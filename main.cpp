#include <iostream>
#include <composite/Folder.h>

#include "Scaner.h"
#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;
using namespace std::chrono;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <path> <search_string>" << std::endl;
        return 1;
    }

    fs::path path(argv[1]);
    std::string searchString(argv[2]);

    // Start measuring time
    auto start = high_resolution_clock::now();

    // Perform the scan operation
    auto result = Scaner::GetInstance().Scan(path, searchString);

    // Stop measuring time
    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<milliseconds>(end - start);

    // Output results
    std::cout << "Search completed in " << duration.count() << " milliseconds." << std::endl;
    for (const auto& res : result) {
        std::cout << res << std::endl;
    }

    return 0;
}
