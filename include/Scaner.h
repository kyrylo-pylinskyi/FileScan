//
// Created by kpyli on 03.07.2024.
//

#ifndef KEYFINDER_H
#define KEYFINDER_H
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class Scaner {
public:
    static Scaner& GetInstance() {
        static Scaner instance;
        return instance;
    }

    Scaner(const Scaner&) = delete;
    Scaner& operator=(const Scaner&) = delete;

    std::vector<std::string> Scan(const fs::path& path, std::string& searchString);

private:
    Scaner() {}
};

#endif //KEYFINDER_H
