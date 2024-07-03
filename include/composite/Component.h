//
// Created by kpyli on 03.07.2024.
//

#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
protected:
    Component* _parrent;
public:
    virtual ~Component() = default;

    void SetParrent(Component* parrent) { _parrent = parrent; }
    Component* GetParrent() const { return _parrent; }

    virtual void Add(Component* component) = 0;
    virtual void Remove(Component* component) = 0;

    virtual bool IsComposite() const { return false; }
    virtual void Read() const = 0;
};

#endif //COMPONENT_H
