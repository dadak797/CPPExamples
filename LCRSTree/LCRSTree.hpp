#pragma once

#include <iostream>
#include "Node.hpp"


template<typename T>
class LCRSTree {
public:
    // Constructor
    LCRSTree() : m_RootNode(nullptr) {}

    // Destructor
    ~LCRSTree() {
        if (m_RootNode == nullptr) return;
        delete m_RootNode;
        m_RootNode = nullptr;
    }

    Node<T>* GetRoot() const {
        return m_RootNode;
    }

    // If insertAfter is nullptr, data is set at root node.
    Node<T>* InsertItem(T data, Node<T>* insertAfter = nullptr) {
        if (!insertAfter) {
            return SetRoot(data);
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* childNode = insertAfter->GetChild();
        if (childNode) {
            while (childNode->GetSibling()) {
                childNode = childNode->GetSibling();
            }
            childNode->SetSibling(newNode);
        }
        else {
            insertAfter->SetChild(newNode);
        }

        return newNode;
    }

    void LoopTree(Node<T>* node, void (*pFunc)(Node<T>*, int), int depth = 0)
    {
        if (pFunc) {
            pFunc(node, depth);
        }

        if (node->GetChild()) {
            LoopTree(node->GetChild(), pFunc, depth + 1);
        }

        if (node->GetSibling()) {
            LoopTree(node->GetSibling(), pFunc, depth);
        }
    }

private:
    Node<T>* m_RootNode;

    Node<T>* SetRoot(T data) {
        if (m_RootNode) delete m_RootNode;
        m_RootNode = new Node<T>(data);
        return m_RootNode;
    }
};