/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* DATA STRUCTURES IMPLEMENTATIONS													//
*																					//
*   __                __															//
*  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _								//
*  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)								//
*																					//
*																					//
* Stack.																			//
*																					//
* Features, being n the number of elements in the tree:								//
* 1. Look-ups 		-> O(1)															//
* 2. Insertions:    -> O(1)															//
* 3. Deletions:		-> O(1)															//
*																					//
* https://en.wikipedia.org/wiki/Stack												//
*																					//
* @author (moboustta6@gmail.com)													//
* @github M0-san																	//
*																					//
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

package main

import "fmt"

/*
	Stack struct
*/
type Stack[T any] struct {
	vals []T // value container
}

// Implement the Stringer interface
// So that it is easier to print out the
// Stack on the console
// String method is required by the fmt package
func (s Stack[T]) String() string {
	return fmt.Sprintf("%v", s.vals)
}

//	isEmpty: checks if the stack has any element
//	O(1) time complexity
//	O(1) Space complexity
func (s *Stack[T]) isEmpty() bool {
	return len(s.vals) == 0
}

//	Push: insert an element on top of the Stack
//	average O(1) time complexity
//	average O(1) Space complexity
func (s *Stack[T]) Push(val T) {
	s.vals = append(s.vals, val)
}

//	Pop: remove the element on top of the Stack
//	O(1) time complexity
//	O(1) Space complexity
func (s *Stack[T]) Pop() (ret T, _ bool) {
	if s.isEmpty() {
		return ret, false
	}
	ret = s.vals[len(s.vals)-1]
	s.vals = s.vals[:len(s.vals)-1]
	return ret, false
}

//	Peek: retrieve the element on top of the Stack
//	O(1) time complexity
//	O(1) Space complexity
func (s *Stack[T]) Peek() (retValue T, _ bool) {
	if s.isEmpty() {
		return retValue, false
	}
	return s.vals[len(s.vals)-1], true
}

/*
	Common Stack problems.
*/

// reverseString: reverse a string using Stack
// 	runs in ->
// 			- O(n) time complexity
// 			- O(n) space complexity
func reverseString(str string) string {
	reversed := make([]byte, len(str))
	stack := Stack[byte]{}

	for i := 0; i < len(str); i++ {
		stack.Push(str[i])
	}

	i := 0
	var ch byte
	for stack.isEmpty() != true {
		ch, _ = stack.Pop()
		reversed[i] = byte(ch)
		i++
	}
	return string(reversed)
}

func main() {
	fmt.Println(reverseString("21"))
}
