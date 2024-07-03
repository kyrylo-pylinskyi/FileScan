//
// Created by kpyli on 03.07.2024.
//

#include "composite/Folder.h"

#include <thread>
#include <vector>

namespace std {
    class thread;
}

void Folder::Add(Component* component) {
    if (!component) return;

    _children.push_back(component);
    component->SetParrent(this);
}

void Folder::Remove(Component *component) {
    if (!component) return;

    _children.remove(component);
    component->SetParrent(nullptr);
}

void Folder::Read() const {
    std::vector<std::thread> threads;

    for(const Component* c: _children) {
        auto readOperation = [c]() {
            c->Read();
        };
        threads.emplace_back(std::thread(readOperation));
    }

    for(std::thread& t: threads) {
        t.join();
    }
}

