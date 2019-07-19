/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: nrcar
 *
 * Created on March 27, 2019, 11:34 AM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BinaryTreeADT.h"
#include "BinaryNode.h"

template <class T>
class BinarySearchTree : BinaryTreeADT<T> {
public:
    /**
     * Default constructor
     * 
     * Root is sent to null ptr.
     */
    BinarySearchTree();
    /**
     * Blank copy constructor.  not in use.
     * @param orig Item to be copied
     */
    //BinarySearchTree(const BinarySearchTree& orig) const;
    /**
     * Blank destructor.  Not in use
     */
    //virtual ~BinarySearchTree();

    /**
     * Tells whether or not the tree is empty
     * @return true if root is nullptr, false if otherwise
     */
    bool isEmpty()const;

    /**
     * Adds a node to the binary tree.
     * @param newItem item to be added
     * @return if it was added or not
     */
    bool add(const T& newItem);

    /**
     * Removes an item from the tree. 
     * @param delItem
     * @return If the node was successfully removed
     */
    bool remove(T& delItem);
    
    BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, T& item, bool& success);
    
    /**
     * Deletes the binary tree.
     */
    void clear();
    /**
     * check to see if the binary tree contains an item DOES NOT WORK
     * @param findItem The item it is checking for
     * @return true of false if the item is found or not.
     */
    bool contains(T& findItem);
    /**
     * The public calling method for the inorder traversal.
     * @param visit
     */
    void inorderTraverse(void visit(T&)) const;
    void postorderTraverse(void visit(T& item));


private:
    BinaryNode<T>* root;

    //recursive functions
    /**
     * Destroys the tree with a postorder traversal
     * @param currRoot root of the tree.
     * @return if the tree is empty afterwards.
     */
    bool destroyTree(BinaryNode<T>* currRoot);
    /**
     * Puts an item in its proper place when added to the tree.
     * @param currRoot The node that is being analyzed
     * @param newNode the node that is going down the tree to be put in its proper place
     * @return the currRoot.
     */
    BinaryNode<T>* placeNode
    (BinaryNode<T>* currRoot, BinaryNode<T>* newNode);

    BinaryNode<T>* findNode(BinaryNode<T>* currRoot, T& findItem);
    BinaryNode<T>* removeNode(BinaryNode<T>* nodePtr);
    BinaryNode<T>* removeLeftmostNode(BinaryNode<T>* nodePtr, T& item);

    /**
     * Uses a Left Node Right order of visitation to visit the nodes in order.
     * @param currRoot The node being analyzed.
     * @param visit method that is defined by the data service.  Performs specified
     * actions on current node.
     */
    void inorder(BinaryNode<T>* currRoot, void visit(T&)) const;
    /**
     * Uses a Left Right Node order of visitation to visit the nodes post order.
     * @param currRoot The node being analyzed.
     * @param visit method that is defined by the data service.  Performs specified
     * actions on current node.
     */
    void postorder(BinaryNode<T>* currRoot, void visit(T& item));
};

#include "BinarySearchTree.cpp"

#endif /* BINARYSEARCHTREE_H */

