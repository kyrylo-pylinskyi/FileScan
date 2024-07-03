//
// Created by kpyli on 03.07.2024.
//

#ifndef FOLDER_H
#define FOLDER_H
#include <list>
#include <mutex>
#include "Component.h"


class Folder : public Component, public std::enable_shared_from_this<Folder> {
private:
    mutable std::mutex _mutex;

    void AddChild(std::shared_ptr<Component> component);

protected:
    std::list<std::shared_ptr<Component>> _children;

public:
    explicit Folder(const fs::path& path);

    bool IsComposite() const override { return true; }

    void Search(std::string &searchString, std::vector<std::string> &results) const override;

    void LoadContents();
};


#endif //FOLDER_H
