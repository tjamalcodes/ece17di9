//
// Created by Tasnia Jamal on 11/27/23.
//
#include "BinaryTree.h"
BinaryTree::BinaryTree() {
    root = nullptr;
}
void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if(aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else{ // if value is found
        makeDeletion(aNodePtr);
    }
}
void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node* tempPtr = nullptr;
    if (aNodePtr == nullptr){
        std::cout <<"Can't read empty node!"<<std::endl;
    }
    else if (aNodePtr->right == nullptr){
        tempPtr = aNodePtr;
        aNodePtr = aNodePtr-> left;
        delete tempPtr;
    }
    else if(aNodePtr->left == nullptr){
        tempPtr = aNodePtr;
        aNodePtr = aNodePtr-> right;
        delete tempPtr;
    }
    else{
        tempPtr = aNodePtr->right;
        while(tempPtr->left){
            tempPtr=tempPtr->left;
        }
        tempPtr->left = aNodePtr->left;
        tempPtr = aNodePtr;
        aNodePtr = tempPtr->right;
        delete tempPtr;
    }
}
bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;
    while(currentNode){
        if(currentNode ->val == aVal){
            return true;
        }
        else if(aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else{
            currentNode = currentNode->right;
        }
    }
    return false;
}
void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}
void BinaryTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root,newNode);

}
void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    //if null, set ptr to new node
    if(aNodePtr == nullptr){
        aNodePtr = aNewNodePtr;
    }
        //if new node is less than current node, insert as left child
    else if(aNewNodePtr -> val < aNodePtr ->val){
        insert(aNodePtr->left, aNewNodePtr);
    }
        //if greater, insert as right child
    else{
        insert(aNodePtr->right, aNewNodePtr);
    }
}
void BinaryTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        std::cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinaryTree::printTree(){
    displayInOrder(root);
    std::cout << std::endl;
};