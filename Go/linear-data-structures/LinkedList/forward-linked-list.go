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

import "fmt"

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

func createNode(value int) *Node {
	return &Node{value: value, next: nil}
}

func (list ForwardList) String() string {
	listValues := make([]int, list.length(), list.length())

	current := list.head
	i := 0
	for current != nil {
		listValues[i] = current.value
		i++
		current = current.next
	}
	return fmt.Sprintf("%v", listValues)
}

func (list *ForwardList) pushFront(elem int) int {
	if list.head == nil {
		list.head = createNode(elem)
		list.tail = list.head
		list.size++
		return elem
	}

	newFront := createNode(elem)
	newFront.next = list.head
	list.head = newFront
	list.size++
	return newFront.value
}

func (list *ForwardList) pushBack(elem int) int {
	if list.tail == nil {
		list.head = createNode(elem)
		list.tail = list.head
		list.size++
		return elem
	}

	newBack := createNode(elem)
	list.tail.next = newBack
	list.tail = newBack
	list.size++
	return newBack.value
}

func (list *ForwardList) front() int {
	if list.head != nil {
		return list.head.value
	}
	panic("error: list empty. can't get element at font")
}

func (list *ForwardList) back() int {
	if list.tail != nil {
		return list.tail.value
	}
	panic("error: list empty. can't get element at back")
}

func (list *ForwardList) contains(elem int) bool {
	if list == nil {
		panic("error: list empty")
	}

	current := list.head
	for current != nil {
		if current.value == elem {
			return true
		}
		current = current.next
	}
	return false
}

func (list *ForwardList) indexOf(elem int) int {
	if list == nil {
		panic("error: list empty")
	}

	index := 0
	current := list.head
	for current != nil {
		if current.value == elem {
			return index
		}
		current = current.next
		index++
	}
	return -1
}

func (list *ForwardList) length() int {
	return list.size
}

func (list *ForwardList) isEmpty() bool {
	return list.length() == 0
}

func main() {
	list := ForwardList{}
	list.pushBack(10)
}
