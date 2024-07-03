//
// Created by kpyli on 03.07.2024.
//

#include "composite/Folder.h"

#include <thread>
#include <vector>
#include <filesystem>
#include <composite/File.h>

Folder::Folder(const fs::path& path) : Component(path) {
    if(!is_directory(_path)) {
        throw std::invalid_argument("Path is not a directory: " + _path.string());
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
    auto p = shared_from_this();

    component->SetParrent(p);
    _children.push_back(component);
}

void Folder::Read() const {
    std::vector<std::thread> threads;

    {
        std::lock_guard lock(_mutex);
        for (const auto& child : _children) {
            auto readOperation = [child] () {
                child->Read();
            };
            threads.emplace_back(readOperation);
        }
    }

    for (std::thread& t : threads) {
        t.join();
    }
}
