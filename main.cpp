#include <iostream>
#include <composite/Folder.h>

int main() {
    std::cout << "FileScan!" << std::endl;

    auto root = std::make_shared<Folder>("D:\\Repos\\FileScan\\data");
    root->LoadContents();
    root->Read();

    return 0;
}
