
/* 
 * @file:   main.cpp
 * @author: cwoods
 *
 * Created on March 21, 2019, 9:02 PM
 */
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"

using namespace std;

//template <class T>
void printInOrder(int& num) {
        std::cout << num << std::endl;
}

void startGUITree(string filename) {
    ShellExecute(NULL,"open",filename.c_str(),NULL,NULL,SW_SHOWNORMAL);
    
}

int main() {

    BinarySearchTree<int> testTree;
    testTree.add(654);
    testTree.add(48);
    testTree.add(324);
    testTree.add(4);
    testTree.add(36);
    testTree.add(3554);
    testTree.add(385);
    testTree.add(984);
    testTree.add(398);
    testTree.add(1358);
    testTree.add(894);
    testTree.add(7956);
    testTree.add(7956);
    testTree.add(9826);
    testTree.add(1987);
    testTree.add(45);
    testTree.add(36);
    testTree.add(763);
    testTree.add(555);
    testTree.add(9845);
    int searchVal = 385;
    testTree.inorderTraverse(printInOrder);
    cout << boolalpha << testTree.contains(searchVal) << endl;
    //searchVal = 36;
    testTree.remove(searchVal);
    cout << boolalpha << testTree.contains(searchVal) << endl;
    testTree.inorderTraverse(printInOrder);
    
    system("py -3.6 plugBinaryTree.py");

    return 0;
}
