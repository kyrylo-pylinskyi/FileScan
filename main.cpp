#include <iostream>
#include <composite/File.h>
#include <composite/Folder.h>

int main() {
    std::cout << "FileScan!" << std::endl;

    auto root = new Folder;
    auto f1 = new Folder;
    auto f2 = new Folder;
    auto f3 = new Folder;

    root->Add(f1);
    root->Add(f2);
    root->Add(f3);

    auto f1f1 = new Folder;
    f1->Add(f1f1);

    auto f3f1 = new Folder;
    auto f3f2 = new Folder;
    f3->Add(f3f1);
    f3->Add(f3f2);

    auto t1 = new File;
    auto t2 = new File;
    auto t3 = new File;
    auto t4 = new File;
    auto t5 = new File;
    auto t6 = new File;

    root->Add(t1);
    f1->Add(t2);
    f1f1->Add(t3);
    f3->Add(t4);
    f3f1->Add(t5);
    f3f2->Add(t6);

    root->Read();

    return 0;
}
