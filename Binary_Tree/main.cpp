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
    Node<T> *head;
    int height = 0;

public:
    bool is_full()
    {
        Node<T> *anchor = head;
        for (int i = 1; i < height; i++)
            anchor = anchor->right;
        if (anchor->right == nullptr)
            return false;
        return true;
    }

    bool add(int data, Node<T> *anchor = head, int h = height)
    {
        if (is_full())
        {
            Node<T> *anchor = head, *temp;
            for (int i = 1; i < height; i++)
                anchor = anchor->left;
            temp->data = data;
            temp->up = anchor;
            anchor->left = temp;
            head++;
            return true;
        }

        if (h >= 0)
        {
            if (anchor->left != nullptr)
            {
                if (add(data, h - 1))
                    return true;
            }
            else
            {
                Node<T> temp;
                temp->data = data;
                temp->up = anchor;
                anchor->left = *temp;
                return true;
            }

            if (anchor->right != nullptr)
            {
                if (add(data, h - 1))
                    return true;
            }
            else
            {
                Node<T> temp;
                temp->data = data;
                temp->up = anchor;
                anchor->right = *temp;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}