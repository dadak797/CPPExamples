template<typename T>
class Node {
public:
    // Constructor
    Node() = delete;
    Node(T data) {
        m_Data = data;
        m_Child = nullptr;
        m_Sibling = nullptr;
    }

    // Destructor
    ~Node() {
        DeleteNode(m_Child);
        DeleteNode(m_Sibling);
    }

    const T& GetData() const {
        return m_Data;
    }

    void SetChild(Node* child) {
        m_Child = child;
    }

    Node* GetChild() const {
        return m_Child;
    }

    void SetSibling(Node* sibling) {
        m_Sibling = sibling;
    }

    Node* GetSibling() const {
        return m_Sibling;
    }

private:
    T m_Data;
    Node* m_Child;
    Node* m_Sibling;

    void DeleteNode(Node* node) {
        if (node == nullptr) return;
        delete node;
        node = nullptr;
    }
};