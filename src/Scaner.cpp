//
// Created by kpyli on 03.07.2024.
//

#include "Scaner.h"
#include <iostream>
#include <composite/File.h>
#include <composite/Folder.h>

std::vector<std::string> Scaner::Scan(const fs::path &path, std::string &searchString) {
    std::vector<std::string> results;

    if (!exists(path)) {
        std::cerr << "Path does not exist: " << path << std::endl;
        return results;
    }

    try {
        if (is_directory(path)) {
            auto rootFolder = std::make_shared<Folder>(path);
            rootFolder->LoadContents();
            rootFolder->Search(searchString, results);
        } else if (is_regular_file(path)) {
            auto file = std::make_shared<File>(path);
            file->Search(searchString, results);
        } else {
            std::cerr << "Invalid path type: " << path << std::endl;
        }
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }

    return results;
}