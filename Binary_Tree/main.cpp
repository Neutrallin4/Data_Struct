#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *right = nullptr, *left = nullptr, *up = nullptr;
};

template <typename T>
class Binary_Tree
{
private:
    Node<T> *head = nullptr;
    int height = 0;

    // Private function that will be used to delete the tree
    void delete_tree(Node<T>* node) {
        if (node) {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }

    // Private function that is used to add a branch in case of an existing head
    bool add_recursive(T data, Node<T> *node, int current_height)
    {
        if(node->left == nullptr)
        {
            node->left == new Node<T> {data};
            node->left->up = node;
            if(current_height + 1 > height) height = current_height + 1;
            return true;
        }
        else if(node->right == nullptr)
        {
            node->right == new Node<T> {data};
            node->right->up = node;
            if(current_height + 1 > height) height = current_height + 1;
            return true;
        }
        else
        {
            if (add_recursive(data, node->left, current_height + 1)) return true;
            return add_recursive(data, node->right, current_height + 1);
        }
        return false;
    }

public:
    ~Binary_Tree() { delete_tree(head); }

    // Creates the first node in case of an empty head. Otherwise calls the private add function
    bool add(T data)
    {
        if(head == nullptr)
        {
            head = new Node<T> {data};
            height++;
            return true;
        }
        return add_recursive(data, head, 1);
    }
};

int main()
{
    Binary_Tree<int> test;
    test.add(5);
    test.add(10);
    test.add(20);
    test.add(40);
}