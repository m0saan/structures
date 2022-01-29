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

import (
	"fmt"
)

type Node struct {
	value int   // value property -> holds the value !! generics will be added later on.
	next  *Node // reference to the next Node.
}

type ForwardList struct {
	size       int   // n of elements the linkedlist contains.
	head, tail *Node // head -> first Node
	// tail -> last Node. (Optional)
}

/*
	IForawrdList has the methods that should be
	implemented for the forwardlist
*/
type IForawrdList interface {
	// Element Access
	front() int
	back() int

	// Modifiers
	pushBack(elem int) int
	pushFront(elem int) int
	popBack() int
	popFront() int
	// splice(elem int)
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

// Helper function that takes a value and returns a constructed Node.
func createNode(value int) *Node {
	return &Node{value: value, next: nil}
}

// String -> The fmt package (and many others) look for this interface to print values.
// i.e Implementing this function help printing out the element of the list
// to the console (like toString in Java / operator<< in C++)-.
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

// pushFront takes a value and adds it to the font of the linkedList
// returns the value that was inserted.
// runs in O(1) time complexity
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

// pushBack takes a value and adds it to the back of the linkedList
// returns the value that was inserted.
// runs in O(1) time complexity
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

// popBack erases the value in the back of the linkedList
// returns the value that was erased.
// runs in O(n) time complexity
func (list *ForwardList) popBack() int {
	if list.length() == 0 {
		panic("list empty. can't erase")
	}

	if list.head == list.tail {
		retValue := list.head.value
		list.head = nil
		list.tail = nil
		list.size = 0
		return retValue
	}

	prevNode := list.head

	// When loop is done prevNode will be pointing at
	// the element past the end.
	for prevNode.next != nil {
		if prevNode.next.next == nil {
			break
		}
		prevNode = prevNode.next
	}

	tmpBack := list.tail
	retValue := tmpBack.value

	prevNode.next = nil
	tmpBack = nil
	list.tail = prevNode
	list.size--
	return retValue
}

// popFronmt erases the value in the beggining of the linkedList
// returns the value that was erased.
// runs in O(1) time complexity
func (list *ForwardList) popFront() int {
	if list.length() == 0 {
		panic("list empty. can't erase")
	}

	if list.head == list.tail {
		retValue := list.head.value
		list.head = nil
		list.tail = nil
		list.size = 0
		return retValue
	}

	second := list.head.next
	retValue := second.value

	list.head.next = nil
	list.head = second
	list.size--
	return retValue
}

// clear -> Erases all the elements.
// runs in O(n) time complexity
func (list *ForwardList) clear() {
	for list.head != nil {
		list.popFront()
	}
}

// Front peeks the value in the front of the linkedlist
// runs in O(1) time complexity
func (list *ForwardList) front() int {
	if list.head != nil {
		return list.head.value
	}
	panic("error: list empty. can't get element at font")
}

// Back peeks the value in the back of the linkedlist.
// i.e returns the last value in the linkedlist
// runs in O(1) time complexity
func (list *ForwardList) back() int {
	if list.tail != nil {
		return list.tail.value
	}
	panic("error: list empty. can't get element at back")
}

// contains -> checks whether <elem> is in the linkedlist
// returns a boolean value.
// runs in O(n) time complexity
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

// indexOf -> returns the index of <elem>.
// returns -1 if not found.
// runs in O(n) time complexity
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

// length returns the number of elements the linkedlist have.
// runs in O(1) time complexity
func (list *ForwardList) length() int {
	return list.size
}

// runs in O(1) time complexity
func (list *ForwardList) isEmpty() bool {
	return list.length() == 0
}

func main() {
	list := ForwardList{}
	list.clear()
	fmt.Println(list.head)
	fmt.Println(list.tail)
}
