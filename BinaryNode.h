/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryNode.h
 * Author: cwood
 *
 * Created on October 26, 2018, 6:16 PM
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

template <class T>
class BinaryNode {
public:
    /**
     * Default constructor.  Sets left and right child to nullptr.
     */
    BinaryNode();
    /**
     * Overloaded constructor: Initialized a node with everything it needs
     * @param newItem the item the node points to
     * @param left the left child
     * @param right the right child
     */
    BinaryNode(const T& newItem,
            BinaryNode<T>* left = nullptr,
            BinaryNode<T>* right = nullptr);
    /**
     * Copy constructor makes an identical node.
     * @param orig the node to be copied
     */
    BinaryNode(const BinaryNode& orig);
    /**
     * Deletes a binary node.  Not in use.
     */
    virtual ~BinaryNode();

    /**
     * Returns the item the node points to.
     * @return The item the node points to
     */
    T getItem() const;
    /**
     * Sets the item the node points to.
     * @param newItem the item the node will point to.
     */
    void setItem(const T& newItem);
    /**
     * Returns the left child
     * @return left child
     */
    BinaryNode<T>* getLeftChild() const;
    /**
     * Returns the right child
     * @return right child
     */
    BinaryNode<T>* getRightChild() const;
    /**
     * Sets the left child of a node
     * @param left The node to be set as the left child.
     */
    void setLeftChild(BinaryNode<T>* left);
    /**
     * Sets the right child of a node
     * @param right The node to be set as the right child.
     */
    void setRightChild(BinaryNode<T>* right);

    /**
     * Tells whether or not the node is the at the last level of the tree.
     * @return Whether or not the node is the at the last level of the tree.
     */
    bool isLeaf() const;

    //  void inorderTraverse(void visit(T&));

private:
    T item;
    BinaryNode<T>* leftChild;
    BinaryNode<T>* rightChild;
};

#include "BinaryNode.cpp"
#endif /* BINARYNODE_H */

