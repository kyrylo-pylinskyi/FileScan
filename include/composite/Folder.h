//
// Created by kpyli on 03.07.2024.
//

#ifndef FOLDER_H
#define FOLDER_H
#include <list>
#include <mutex>
#include <string>

#include "Component.h"

namespace fs = std::filesystem;

class Folder : public Component, public std::enable_shared_from_this<Folder> {
private:
    mutable std::mutex _mutex;

    void AddChild(std::shared_ptr<Component> component);

protected:
    std::list<std::shared_ptr<Component>> _children;

public:
    Folder(const fs::path& path);

    bool IsComposite() const override { return true; }

    void Read() const override;

    void LoadContents();
};


#endif //FOLDER_H
