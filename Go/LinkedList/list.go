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

package list

type Node[T any] struct {
	value T        // value property -> holds the value.
	next  *Node[T] // reference to the next Node.
}

type List[T any] struct {
	size       int      // n of elements the linkedlist contains.
	head, tail *Node[T] // head -> first Node
	// tail -> last Node. (Optional)
}

// Helper function that takes a value and returns a constructed Node.
func createNode[T any](value T) *Node[T] {
	return &Node[T]{value: value, next: nil}
}

// pushFront takes a value and adds it to the font of the linkedList
// returns the value that was inserted.
// runs in O(1) time complexity
func (list *List[T]) pushFront(elem T) T {
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
