/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/** 
 * @file:   BinaryTreeADT.h
 * @author: cwood
 * @class:  BinaryTreeADT
 *
 * Created on March 21, 2019, 9:23 PM
 */
#ifndef BINARYTREEADT_H
#define BINARYTREEADT_H
#include "BinaryNode.h"

template <class T>
class BinaryTreeADT {
public:
    virtual bool isEmpty() const = 0;
    virtual bool add(const T& newItem) = 0;
    virtual bool remove(T& delItem) = 0;
    virtual BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, T& item, bool& success) = 0; //bool remove(const T& delItem) = 0;
    virtual void clear() = 0;
    virtual bool contains(T& findItem) = 0;
    
//    virtual T getEntry(const T& item) const;
//        throw (NotFoundException) = 0;

    //TODO traversals
    virtual void inorderTraverse(void visit(T& item)) const = 0;
    
private:

};

#endif /* BINARYTREEADT_H */

