#include "LCRSTree.hpp"

void PrintNode(Node<int>* node, int depth)
{
    for (int i = 0; i < depth; i++) {
        std::cout << "-";
    }
    std::cout << node->GetData() << std::endl;
    
}

int main() {
    using INT_NODE = Node<int>*;
    using INT_TREE = LCRSTree<int>;
    
    INT_TREE tree;

    tree.InsertItem(0);
    tree.InsertItem(1, tree.GetRoot());
    tree.InsertItem(2, tree.GetRoot());
    INT_NODE tempNode = tree.InsertItem(3, tree.GetRoot());
    tree.InsertItem(4, tree.GetRoot());

    tree.InsertItem(31, tempNode);
    INT_NODE tempNode2 = tree.InsertItem(32, tempNode);
    tree.InsertItem(33, tempNode);

    tree.InsertItem(321, tempNode2);
    INT_NODE tempNode3 = tree.InsertItem(322, tempNode2);
    tree.InsertItem(323, tempNode2);

    tree.InsertItem(3221, tempNode3);
    tree.InsertItem(3222, tempNode3);
    tree.InsertItem(3223, tempNode3);

    tree.LoopTree(tree.GetRoot(), PrintNode);

    return 0;
}