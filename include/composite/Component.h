//
// Created by kpyli on 03.07.2024.
//

#ifndef COMPONENT_H
#define COMPONENT_H
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class Component {
protected:
    fs::path _path;
    std::shared_ptr<Component> _parrent;

public:
    Component(const fs::path& path) : _path(path) {}
    virtual ~Component() = default;

    void SetParrent(std::shared_ptr<Component> parrent) {
        _parrent = parrent;
    }
    std::shared_ptr<Component> GetParrent() const { return _parrent; }

    virtual bool IsComposite() const { return false; }

    virtual void Search(std::string &searchString, std::vector<std::string> &results) const = 0;

    virtual fs::path GetPath() const { return _path; }
};

#endif //COMPONENT_H
