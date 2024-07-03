//
// Created by kpyli on 03.07.2024.
//

#ifndef FILE_H
#define FILE_H
#include "Component.h"

class File : public Component {
public:
    explicit File(const fs::path& path);

    void Search(std::string &searchString, std::vector<std::string> &results) const override;
};

#endif //FILE_H
