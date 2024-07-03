//
// Created by kpyli on 03.07.2024.
//

#ifndef FOLDER_H
#define FOLDER_H
#include <list>
#include "Component.h"

class Folder : Component {
protected:
    std::list<Component*> _children;

public:
    void Add(Component* component) override;
    void Remove(Component *component) override;

    void Read() const override;
};


#endif //FOLDER_H
