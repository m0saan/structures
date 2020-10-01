//
// Created by moboustt on 10/1/20.
//

#include "AVLNode.h"


template<typename AVLTREE>
AVLNode<AVLTREE>::AVLNode(T v) : value{ v }, leftChild { nullptr }, rightChild { nullptr } {}