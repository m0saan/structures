/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* DATA STRUCTURES IMPLEMENTATIONS													//
*																					//
*   __                __															//
*  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _								//
*  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)								//
*																					//
*																					//
* Linked List -> Forward Liked List.												//
*																					//
* Features, being n the number of elements in the tree:								//
* 1. Look-ups 		-> O(n)															//
* 2. Insertions:    -> O(n); O(1) at Front/Back										//
* 3. Deletions  	-> O(n); O(1) at Front/Back										//
*																					//
* https://en.wikipedia.org/wiki/Linked_list											//
*																					//
* @author (moboustta6@gmail.com)													//
* @github M0-san																	//
*																					//
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

package main

type Node struct {
	value int
	next  *Node
}

type ForwardList struct {
	size       int
	head, tail *Node
}

type IForawrdList interface {
	// Element Access
	front() int
	back() int

	// Modifiers
	pushBack(elem int) int
	pushFront(elem int) int
	popBack() int
	popFront() int
	splice(elem int)
	clear()

	// Capacity
	isEmpty() bool
	length() int

	// Operations
	contains(elem int) bool
	indexOf(elem int) int
	reverse()
	sort()
}
