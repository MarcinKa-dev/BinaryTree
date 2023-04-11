#pragma once


template <typename T>
class Node
{
private:
    bool is_value_set;
	T value;
    Node* left_child;
    Node* right_child;
public:
    inline T getValue() const
    {
        return value;
    }

    inline void setValue(T value)
    {
        is_value_set = true;
        this->value = value;
    }

    bool isValueSet() const
    {
        return is_value_set;
    }

    inline Node* getLeftChild()
    {
        // create a new node if it doesn't exist
        if (left_child == nullptr)
        {
            left_child = new Node();
        }
        return left_child;
    }

    bool hasLeftChild() const
    {
        if (left_child == nullptr)
            return false;
        return true;
    }

    void setLeftChild(Node* child)
    {
        left_child = child;
    }

    inline Node* getRightChild()
    {
        // create a new node if it doesn't exist
        if (right_child == nullptr)
        {
            right_child = new Node();
        }
        return right_child;
    }

    bool hasRightChild() const
    {
        if (right_child == nullptr)
            return false;
        return true;
    }

    void setRightChild(Node* child)
    {
        right_child = child;
    }

    Node() : is_value_set(false), value(0), left_child(nullptr), right_child(nullptr) {}
    ~Node()
    {
        delete left_child;
        delete right_child;
        left_child = nullptr;
        right_child = nullptr;
    }
};

