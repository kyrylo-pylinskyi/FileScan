//
// Created by kpyli on 03.07.2024.
//

#include "composite/File.h"

#include <cstdio>
#include <thread>


void File::Read() const {
    printf("File Read thread_id: %zu\n", std::hash<std::thread::id>{}(std::this_thread::get_id()));
}