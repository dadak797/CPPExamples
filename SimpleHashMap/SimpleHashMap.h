#pragma once

#include <memory>
#include <iostream>
#include "Node.h"


class SimpleHashMap
{
public:
    SimpleHashMap() = default;
    ~SimpleHashMap() = default;

    void Add(const char* key, unsigned long hash, int value);
    int Get(const char* key, unsigned long hash) const;
    void Print() const;

private:
    static constexpr int MAX_SIZE = 10;
    std::shared_ptr<Node> mArray[MAX_SIZE];
};

void SimpleHashMap::Add(const char* key, unsigned long hash, int value)
{
    std::shared_ptr<Node> newNode = std::make_shared<Node>(key, value);

    int index = hash % MAX_SIZE;

    if (mArray[index] == nullptr)
    {
        mArray[index] = newNode;
        return;
    }

    std::shared_ptr<Node> current = mArray[index];
    if (current->GetKey() == key)
    {
        newNode->SetNext(current->GetNext());
        mArray[index] = newNode;
        return;
    }

    while (current->GetNext() != nullptr)
    {
        if (current->GetNext()->GetKey() == key)
        {
            newNode->SetNext(current->GetNext()->GetNext());
            current->SetNext(newNode);
            return;
        }

        current = current->GetNext();
    }

    current->SetNext(newNode);
}

int SimpleHashMap::Get(const char* key, unsigned long hash) const
{
    int index = hash % MAX_SIZE;

    if (mArray[index] == nullptr)
    {
        return -1;
    }

    std::shared_ptr<Node> current = mArray[index];

    while (current != nullptr)
    {
        if (current->GetKey() == key)
        {
            return current->GetData();
        }

        current = current->GetNext();
    }

    return -1;
}

void SimpleHashMap::Print() const
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (mArray[i] != nullptr)
        {
            std::shared_ptr<Node> current = mArray[i];

            while (current != nullptr)
            {
                std::cout << "Key: " << current->GetKey() << ", Value: " << current->GetData() << std::endl;
                current = current->GetNext();
            }
        }
    }
}