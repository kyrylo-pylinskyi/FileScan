//
// Created by kpyli on 03.07.2024.
//

#include "composite/Folder.h"

#include <thread>
#include <composite/File.h>

Folder::Folder(const fs::path& path) : Component(path) {
    if(!is_directory(_path)) {
        throw std::invalid_argument("Invalid path type: " + _path.string());
    }
}

void Folder::LoadContents() {
    for(const auto& entry: fs::directory_iterator(_path)) {
        if(entry.is_directory()) {
            auto folder = std::make_shared<Folder>(entry.path());
            this->AddChild(folder);
            folder->LoadContents();
        }
        else
            this->AddChild(std::make_shared<File>(entry.path()));
    }
}

void Folder::AddChild(std::shared_ptr<Component> component) {
    if (!component) return;

    std::lock_guard lock(_mutex);

    component->SetParrent(shared_from_this());
    _children.push_back(component);
}

void Folder::Search(std::string &searchString, std::vector<std::string> &results) const {
    std::vector<std::thread> threads;
    std::vector<std::vector<std::string>> partialResults(_children.size());

    {
        std::lock_guard lock(_mutex);
        int index = 0;

        for(const auto& child: _children) {
            threads.emplace_back([&, index] {
                child->Search(searchString, partialResults[index]);
            });
            ++index;
        }

        for(auto& thread: threads) {
            thread.join();
        }

        for(const auto& partialResult: partialResults) {
            results.insert(results.end(), partialResult.begin(), partialResult.end());
        }
    }
}