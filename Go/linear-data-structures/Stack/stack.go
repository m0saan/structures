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

type Stack struct {
	vals []interface{}
}

func (s Stack) String() string {
	return fmt.Sprintf("%v", s.vals)
}

func (s *Stack) isEmpty() bool {
	return len(s.vals) == 0
}

func (s *Stack) Push(val interface{}) {
	s.vals = append(s.vals, val)
}

func (s *Stack) Pop() (interface{}, bool) {
	if s.isEmpty() {
		return nil, false
	}
	ret := s.vals[len(s.vals)-1]
	s.vals = s.vals[:len(s.vals)-1]
	return ret, false
}

func (s *Stack) Peek() (interface{}, bool) {
	if s.isEmpty() {
		return nil, false
	}
	return s.vals[len(s.vals)-1], true
}

func main() {
	s := Stack{}
	s.Push(10)
	s.Push(20)
	s.Push(30)
	s.Push(40)

	for s.isEmpty() != true {
		v, _ := s.Pop()
		fmt.Println(v)
	}
}
