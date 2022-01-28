/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * DATA STRUCTURES IMPLEMENTATIONS													//
 *																					//
 *   __                __															//
 *  |  \  _  |_  _    (_  |_  _      _ |_      _  _  _								//
 *  |__/ (_| |_ (_|   __) |_ |  |_| (_ |_ |_| |  (- _)								//
 *																					//
 *																					//
 * Dynamic Array -> Array.															//
 *																					//
 * Features, being n the number of elements in the tree:							//
 * 1. Look-ups 		-> O(1)															//
 * 2. Insertions 	-> O(n); O(1) on average										//
 * 3. Deletions  	-> O(n)															//
 *																					//
 * http://en.wikipedia.org/wiki/(should be updated)									//
 *																					//
 * @author (moboustta6@gmail.com)													//
 * @github M0-san																	//
 *																					//
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

package main

import (
	"fmt"
	"math"
)

type Array struct {
	_length, _capacity int
	container          []int
}

type IArray interface {
	push(elem int) int
	pushAt(elem int, index int) int
	remove(elem int) int
	at(index int) int
	indexOf(elem int) int
	contains(elem int) bool
	isEmpty() bool
	size() int
	capacity() int
	max() int
	min() int
	reverse() []int
	intersect() []int
}

func (arr Array) String() string {
	return fmt.Sprintf("%v", arr.container[0:arr.size()])
}

func (arr *Array) resize() {
	arr._capacity = arr.capacity() * 2
	tmp := make([]int, arr.capacity())

	for i := 0; i < arr.size(); i++ {
		tmp[i] = arr.container[i]
	}

	arr.container = tmp
}

func (arr *Array) push(elem int) int {
	if arr.capacity() == 0 {
		arr._capacity = int(math.Max(float64(1), float64(arr._capacity)))
		arr.container = make([]int, arr.capacity())
	}

	if arr.size() == arr.capacity() {
		arr.resize()
	}

	arr.container[arr.size()] = elem
	arr._length++
	return elem
}

func (arr *Array) pushAt(elem int, index int) int {

	if index < 0 || index > arr._length {
		panic("error: index out of range")
	}

	if index == arr._length {
		arr.push(elem)
		return elem
	}

	if arr.capacity() == arr.size() {
		arr.resize()
	}

	for i := arr.size(); i >= index; i-- {
		arr.container[i+1] = arr.container[i]
	}

	arr._length++
	arr.container[index] = elem
	return elem
}

func (arr *Array) isEmpty() bool {
	return arr.size() == 0
}

func (arr *Array) capacity() int {
	return arr._capacity
}

func (arr *Array) size() int {
	return arr._length
}

func (arr *Array) at(index int) int {
	if index < 0 || index > arr.size() {
		panic(fmt.Sprintf("error: index out of range: %v", index))
	}
	return arr.container[index]
}

func (arr *Array) contains(elem int) bool {
	for i := 0; i < arr.size(); i++ {
		if elem == arr.at(i) {
			return true
		}
	}
	return false
}

func (arr *Array) indexOf(elem int) int {
	for i := 0; i < arr.size(); i++ {
		if elem == arr.at(i) {
			return i
		}
	}
	return -1
}

func (arr *Array) remove(elem int) int {
	elemIndex := arr.indexOf(elem)

	if elemIndex != -1 {
		for i := elemIndex; i < arr.size()-1; i++ {
			arr.container[i] = arr.container[i+1]
		}
		arr._length--
		return elem
	}
	return -1
}

func (arr *Array) max() int {
	if arr.isEmpty() {
		panic("error: Array empty. can't find max element")
	}

	maxElem := arr.at(0)

	for i := 0; i < arr.size(); i++ {
		maxElem = int(math.Max(float64(maxElem), float64(arr.at(i))))
	}

	return maxElem
}

func (arr *Array) min() int {
	if arr.isEmpty() {
		panic("error: Array empty. can't find min element")
	}

	minElem := arr.at(0)

	for i := 0; i < arr.size(); i++ {
		minElem = int(math.Min(float64(minElem), float64(arr.at(i))))
	}

	return minElem
}

func (arr *Array) reverse() []int {
	reversed := make([]int, arr.size(), arr.size())
	for i := arr.size(); i > 0; {
		reversed[arr.size()-i] = arr.at(i)
		i--
	}
	return reversed
}

func (arr *Array) intersect(other *Array) Array {
	// will be implemented once set is implemented.
	return Array{}
}

func main() {
	numbers := Array{}
	for i := 0; i < 10; i++ {
		numbers.push(i * 2)
	}

	fmt.Println(numbers)
	// numbers.pushAt(99, numbers._length)
	fmt.Println(numbers.reverse())
}
