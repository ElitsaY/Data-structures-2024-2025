#include <iostream>

template<typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template<typename T>
void freeTree(Node<T>* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

template<typename T>
unsigned getTreeHeight(Node<T>* root) {
    if (!root) {
        return -1;
    }

    return (1 + std::max(getTreeHeight(root->left), getTreeHeight(root->right)));
}

template<typename T>
bool contains(Node<T>* root, T value) {
    if (!root) {
        return false;
    }

    if (root->data == value) {
        return true;
    }

    return (contains(root->left, value) || contains(root->right, value));
}