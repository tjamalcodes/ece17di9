//
// Created by Tasnia Jamal on 11/27/23.
//
#include <iostream>
#ifndef ECE17DI9_BINARYTREE_H
#define ECE17DI9_BINARYTREE_H
class BinaryTree{
private:
    struct Node{
        int val;
        Node* left;
        Node* right;
        Node(int aVal, Node*left = nullptr, Node*right = nullptr){
            val =aVal;
        };
    };
    Node* root;
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();

};
#endif //ECE17DI9_BINARYTREE_H
