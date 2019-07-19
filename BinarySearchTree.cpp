/* 
 * File:   BinaryTree.cpp
 * Author: nrcar
 *
 * Created on March 27, 2019, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "BinaryNode.h"

using namespace std;

ofstream guiInfoFile("plugBST.txt");

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr) {

};

/*
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& orig) {

};


template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    //clear();
};
 */
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
    return (root == nullptr);
};

template <class T>
bool BinarySearchTree<T>::add(const T& newItem) {
    //guiInfoFile.open("plugBST.txt", std::ios_base::app);
    BinaryNode<T>* newNode = new BinaryNode<T>(newItem);
    if (guiInfoFile.is_open()) {
        guiInfoFile << endl << "Add " << newItem;
    } else {
        cout << "Could not open file." << endl;
    }
    root = placeNode(root, newNode);
    //guiInfoFile.close();
    return true;
};

template <class T>
bool BinarySearchTree<T>::remove(T& delItem) {
    bool isSuccessful = false;
    guiInfoFile << endl << "Delete " << delItem;
    root = removeValue(root, delItem, isSuccessful);
    //guiInfoFile.close();
    return isSuccessful;
};

template <class T>
BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* subTreePtr, T& item, bool& success) {

    // Not found.
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    // Item is in the root of the subtree.
    if (subTreePtr->getItem() == item) {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    } else {
        if (subTreePtr->getItem() > item) {
            subTreePtr->setLeftChild(removeValue(subTreePtr->getLeftChild(), item, success));

        } else {
            subTreePtr->setRightChild(removeValue(subTreePtr->getRightChild(), item, success));

            return subTreePtr;
        }
    }
}

template <class T>
void BinarySearchTree<T>::clear() {

    destroyTree(root);
    root = nullptr;
};

template <class T>
bool BinarySearchTree<T>::contains(T& findItem) {

    return findNode(root, findItem);
};

template <class T>
bool BinarySearchTree<T>::destroyTree(BinaryNode<T>* currRoot) {

    if (currRoot != nullptr) {

        destroyTree(currRoot->getLeftChild());
        destroyTree(currRoot->getRightChild());
        delete currRoot;
        currRoot = nullptr;
    }
    return (isEmpty());
};



// private methods

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findNode(BinaryNode<T>* currRoot, T& findItem) {
    if (currRoot == nullptr) {
        return nullptr;
    } else if (currRoot->getItem() == findItem) {
        return currRoot;
    } else if (currRoot->getItem() < findItem) {
        return findNode(currRoot->getRightChild(), findItem);
    } else {

        return findNode(currRoot->getLeftChild(), findItem);
    }
};

template <class T>
BinaryNode<T>* BinarySearchTree<T>::removeNode(BinaryNode<T>* nodePtr) {
    if (nodePtr->isLeaf()) {
        delete nodePtr;
        return (nodePtr = nullptr);
    } else if (nodePtr->getRightChild() == nullptr) {
        BinaryNode<T>* nodeToConnectPtr = nodePtr->getLeftChild();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    } else if (nodePtr->getLeftChild() == nullptr) {
        BinaryNode<T>* nodeToConnectPtr = nodePtr->getRightChild();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    } else {
        T newNodeValue;
        nodePtr->setRightChild(removeLeftmostNode(nodePtr->getRightChild(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::removeLeftmostNode(BinaryNode<T>* nodePtr, T& item) {

    if (nodePtr->isLeaf() && nodePtr->getItem() != item) {
        std::cout << "Roots it haha";
    } else if (nodePtr->isLeaf()) {
        item = nodePtr->getItem();
        BinaryNode<T>* nodeToConnectPtr = nodePtr;
        delete nodePtr;
        nodePtr = nullptr;
        //removeNode(nodePtr);
        return nodeToConnectPtr;
    } else if (nodePtr->getLeftChild() == nullptr) {
        item = nodePtr->getItem();
        BinaryNode<T>* nodeToConnectPtr = nodePtr->getRightChild();
        delete nodePtr;
        nodePtr = nullptr;
        //removeNode(nodePtr);
        return nodeToConnectPtr;
    } else {
        removeLeftmostNode(nodePtr->getLeftChild(), item);
    }
}

template <class T >
BinaryNode<T>* BinarySearchTree<T>::placeNode
(BinaryNode<T>* currRoot, BinaryNode<T>* newNode) {

    if (currRoot == nullptr) {
        return newNode;
    } else {
        if (newNode->getItem() < currRoot->getItem()) {
            //std::cout << "Going left" << std::endl;
            BinaryNode<T>* temp =
                    placeNode(currRoot->getLeftChild(), newNode);
            currRoot->setLeftChild(temp);
        } else {
            //std::cout << "Going right" << std::endl;

            currRoot->setRightChild(placeNode(currRoot->getRightChild(), newNode));
        }
        return currRoot;
    }

    //return currRoot;
};

template <class T>
void BinarySearchTree<T>::inorderTraverse(void visit(T & item)) const {

    inorder(root, visit);
};

template <class T>
void BinarySearchTree<T>::postorderTraverse(void visit(T & item)) {

    postorder(root, visit);
};

template <class T>
void BinarySearchTree<T>::inorder(BinaryNode<T>* currRoot, void visit(T & item)) const {
    if (currRoot != nullptr) {
        //cout << "Going left" << endl;

        inorder(currRoot->getLeftChild(), visit);
        // do something with current root
        T item = currRoot->getItem();
        visit(item);
        //cout << "Going right" << endl;
        inorder(currRoot->getRightChild(), visit);
    }

};

template <class T>
void BinarySearchTree<T>::postorder(BinaryNode<T>* currRoot, void visit(T & item)) {
    if (currRoot != nullptr) {
        //cout << "Going left" << endl;
        postorder(currRoot->getLeftChild(), visit);
        //cout << "Going right" << endl;
        postorder(currRoot->getRightChild(), visit);
        // do something with current root
        T item = currRoot->getItem();
        visit(item);

    }
};