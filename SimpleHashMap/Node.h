#pragma once

#include <string>
#include <memory>


class Node final
{
public:
    Node() = delete;
    Node(const char* key, int data);
    ~Node() = default;

    void SetNext(std::shared_ptr<Node> const next);
    std::shared_ptr<Node> GetNext() const;
    int GetData() const;
    const std::string& GetKey() const;

private:
    std::string mKey;
    int mData;
    std::shared_ptr<Node> mNext;
};

Node::Node(const char* key, int data)
    : mKey(std::string(key))
    , mData(data)
{
}

void Node::SetNext(std::shared_ptr<Node> const next)
{
    mNext = next;
}

std::shared_ptr<Node> Node::GetNext() const
{
    return mNext;
}

int Node::GetData() const
{
    return mData;
}

const std::string& Node::GetKey() const
{
    return mKey;
}