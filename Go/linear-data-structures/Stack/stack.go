/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* DATA STRUCTURES IMPLEMENTATIONS													//
*																					//
*   __                __															//
*  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _								//
*  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)								//
*																					//
*																					//
* Stack -> Using array.																//
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

import (
	"constraints"
	"fmt"
)

/*
	Utility
*/

func max[T constraints.Ordered](args ...T) (maxElem T) {
	for _, arg := range args {
		if arg > maxElem {
			maxElem = arg
		}
	}
	return maxElem
}

func min[T constraints.Ordered](args ...T) (minElem T) {
	for _, arg := range args {
		if arg > minElem {
			minElem = arg
		}
	}
	return minElem
}

/*
	Stack struct
*/
type Stack[T any] struct {
	vals []T // value container
	min  T
	max  T
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

/*
func (s *Stack[T]) Push(val T) {
	s.vals = append(s.vals, val)
	s.max = max(val, s.max)
	s.min = min(val, s.min)
}
*/
//	Pop: remove the element on top of the Stack
//	O(n) time complexity -> because of the min and max to be retrieved in o(1) time complexity.
//	O(1) Space complexity

/*
func (s *Stack[T]) Pop() (ret T, _ bool) {
	if s.isEmpty() {
		return ret, false
	}
	ret = s.vals[len(s.vals)-1]
	s.vals = s.vals[:len(s.vals)-1]

	for _, v := range s.vals {
		s.max = max(v, s.max)
		s.min = min(v, s.min)
	}

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

//	Min: get the min element of the Stack
//	O(1) time complexity
//	O(1) Space complexity

func (s *Stack[T]) Min() T {
	if s.isEmpty() {
		log.Panicln("stack empty. can't get min.")
	}

	return s.min
}

//	Max: get the max element of the Stack
//	O(1) time complexity
//	O(1) Space complexity

func (s *Stack[T]) Max() T {
	if s.isEmpty() {
		log.Panicln("stack empty. can't get max.")
	}

	return s.max
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
		reversed[i] = ch
		i++
	}
	return string(reversed)
}

func isBalancedExpression(str string) bool {
	// Supported Expression [<{(
	openingSymbols := map[byte]bool{
		'[': true,
		'<': true,
		'{': true,
		'(': true,
	}

	symbolsPairs := map[byte]byte{
		']': '[',
		'>': '<',
		'}': '{',
		')': '(',
	}

	s := Stack[byte]{}

	for _, v := range str {
		if _, ok := openingSymbols[byte(v)]; ok {
			s.Push(byte(v))
			continue
		}

		if openingSymbol, ok := symbolsPairs[byte(v)]; ok && openingSymbol == byte(v) {
			if _, okk := s.Peek(); okk == false {
				return false
			}
			s.Pop()
		}
	}
	return s.isEmpty()
}

func main() {

	s := Stack[int]{}

	s.Push(5)
	s.Push(8)
	s.Push(10)
	s.Push(2)
	fmt.Println(s.Max())
	fmt.Println(s.Min())

	// Edge case:
	// ((
	// (()
	// ())
	// )(
	// (>

	// fmt.Println(isBalancedExpression("(1+2>"))
	// fmt.Println(max[int](1, 2, 3, 4, 5))
}
