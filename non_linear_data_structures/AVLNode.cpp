/*******************************************************************************
 * DATA STRUCTURES IMPLEMENTATIONS
 *
 *   __                __
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)
 *
 *
 * Adelson-Velskii and Landis' (AVL) tree
 *
 * Features, being N the number of elements in the tree:
 * 1. Guaranteed search time is O(log(N)).
 * 2. Dynamically updated/balanced tree structure O(N) storage.
 *
 * http://en.wikipedia.org/wiki/AVL_tree
 *
 * @author (moboustta6@gmail.com)
 * @github MoBoustta
 *
 ******************************************************************************/


#include "AVLNode.h"


template<typename AVLTREE>
AVLNode<AVLTREE>::AVLNode(T v) : value{v}, height{}, leftChild{nullptr}, rightChild{nullptr} {}