#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    ///Node Struct Represents binary tree has right child left child and contains type <T> Data.

    ///Template of Binary Tree Build from Nodes///

    template <class T>
    class BinaryTree
    {
        class Node
        {
        public:
            T node_data;
            Node *right_child;
            Node *left_child;
            Node *parent;

            Node(const T data)
                : node_data(data), left_child(nullptr), right_child(nullptr) {}
        };

        class BinaryTreeIterator
        {
        private:
            Node *current;
            Node *end;

        public:
            BinaryTreeIterator() {}

            BinaryTreeIterator &operator++() { return *this; };
            T &operator*() const
            {
                return current->node_data;
            }

            T *operator->() const
            {
                return &(current->node_data);
            }

            bool operator==(const BinaryTreeIterator &bti)
            {
                return false;
            }

            bool operator!=(const BinaryTreeIterator &bti)
            {
                return false;
            }
        };

        Node *TreeRoot;

    public:
        BinaryTree<T>() : TreeRoot(nullptr){};

        BinaryTree<T> add_root(T root)
        {
            if (TreeRoot == nullptr)
            {
                this->TreeRoot = new Node(root);
            }
            else
            {
                TreeRoot->node_data = root;
            }

            return *this;
        };

        BinaryTree<T> add_left(const T &father, const T &left)
        {
            Node *temp = find_node(TreeRoot,father);
            if (temp == nullptr)
            {
                throw invalid_argument("Father Node Couldnt be found.");
            }

            if (temp->left_child == nullptr)
            {
                temp->left_child = new Node(left);
            }
            else
            {
                temp->left_child->node_data = left;
                return *this;

            }

            return *this;
        };

        BinaryTree<T> add_right(const T &father, const T &right)
       {
            Node *temp = find_node(TreeRoot,father);
            if (temp == nullptr)
            {
                throw invalid_argument("Father Node Couldnt be found.");
            }

            if (temp->right_child == nullptr)
            {
                temp->right_child = new Node(right);
            }
            else
            {
                temp->right_child->node_data = right;
                return *this;

            }

            return *this;
        };

        BinaryTreeIterator begin_inorder() { return BinaryTreeIterator{}; };

        BinaryTreeIterator end_inorder() { return BinaryTreeIterator{}; };

        BinaryTreeIterator begin() { return BinaryTreeIterator{}; };

        BinaryTreeIterator end() { return BinaryTreeIterator{}; };

        BinaryTreeIterator begin_preorder() { return BinaryTreeIterator{}; };

        BinaryTreeIterator end_preorder() { return BinaryTreeIterator{}; };

        BinaryTreeIterator begin_postorder()
        {
            return BinaryTreeIterator{};
        };

        BinaryTreeIterator end_postorder() { return BinaryTreeIterator{}; };

        friend ostream &operator<<(ostream &out, const BinaryTree<T> &btree) { return out; };

        const Node *get_root()
        {
            return TreeRoot;
        };

        Node *find_node(Node *current, T data)
        {
            if(current==nullptr){return nullptr;}

            if(current->node_data==data){return current;}

            Node *sub_left = find_node(current->left_child,data);
            if(sub_left){return sub_left;}

            Node *sub_right = find_node(current->right_child,data);
            return sub_right; 
        };
    };

    }
