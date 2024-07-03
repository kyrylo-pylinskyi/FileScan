//
// Created by kpyli on 03.07.2024.
//

#include "composite/File.h"
#include <fstream>
#include <iostream>
#include <thread>


File::File(const fs::path &path) : Component(path) {
    if(!is_regular_file(path)) {
        throw std::invalid_argument("Invalid path type: " + _path.string());
    }
}

void File::Search(std::string &searchString, std::vector<std::string> &results) const {
    std::ifstream file(_path);
    if(!file.is_open()) {
        std::cerr << "Failed to open file: " << _path << std::endl;
    }

    std::string line;
    size_t line_number = 0;

    while (std::getline(file, line)) {
        size_t pos = line.find(searchString);
        while(pos != std::string::npos) {
            std::ostringstream result;
            result << _path.string() << "(" << pos << "): ";

            if(pos >= 3) {
                result << line.substr(pos - 3, 3);
            } else {
                result << line.substr(0, 3);
            }

            result << searchString;

            if(pos + searchString.length() + 3 <= line.length()) {
                result << line.substr(pos + searchString.length(), 3);
            } else {
                result << line.substr(pos + searchString.length());
            }

            results.push_back(result.str());
            pos = line.find(searchString, pos + 1);
        }
        ++line_number;
    }
}
