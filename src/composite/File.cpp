//
// Created by kpyli on 03.07.2024.
//

#include "composite/File.h"

#include <cstdio>
#include <fstream>
#include <thread>


void File::Read() const {
    std::string content;
    auto filepath = GetPath();

    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filepath.string());
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    printf("File:\t<%s>\n", filepath.string().c_str());
    printf("Content:\n%s", buffer.str().c_str());
}