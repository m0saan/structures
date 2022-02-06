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
	"log"
	"math"
)

type Array[T any] struct {
	_length, _capacity int
	container          []T
}

func (arr Array[T]) String() string {
	return fmt.Sprintf("%v", arr.container[0:arr.size()])
}

func (arr *Array[T]) resize() {
	arr._capacity = arr.capacity() * 2
	tmp := make([]T, arr.capacity())

	for i := 0; i < arr.size(); i++ {
		tmp[i] = arr.container[i]
	}

	arr.container = tmp
}

func (arr *Array[T]) push(elem T) T {
	if arr.capacity() == 0 {
		arr._capacity = int(math.Max(float64(1), float64(arr._capacity)))
		arr.container = make([]T, arr.capacity())
	}

	if arr.size() == arr.capacity() {
		arr.resize()
	}

	arr.container[arr.size()] = elem
	arr._length++
	return elem
}

func (arr *Array[T]) pushAt(elem T, index int) T {

	if index < 0 || index > arr._length {
		log.Panic("Invalid index")
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

func (arr *Array[T]) isEmpty() bool {
	return arr.size() == 0
}

func (arr *Array[T]) capacity() int {
	return arr._capacity
}

func (arr *Array[T]) size() int {
	return arr._length
}

func (arr *Array[T]) at(index int) T {
	if index < 0 || index > arr.size() {
		log.Panicf("error: index out of range: %v", index)
	}
	return arr.container[index]
}

func (arr *Array[T]) contains(elem T, Equal func(elem, arrElem T) bool) bool {
	for i := 0; i < arr.size(); i++ {
		if Equal(elem, arr.at(i)) {
			return true
		}
	}
	return false
}

func (arr *Array[T]) indexOf(elem T, Equal func(elem, arrElem T) bool) int {
	for i := 0; i < arr.size(); i++ {
		if Equal(elem, arr.at(i)) {
			return i
		}
	}
	return -1
}

/*
func (arr *Array[T]) remove(elem T) T {
	elemIndex := arr.indexOf(elem, func(elem, arrElem T) bool {
		return elem == arrElem
	})

	if elemIndex != -1 {
		for i := elemIndex; i < arr.size()-1; i++ {
			arr.container[i] = arr.container[i+1]
		}
		arr._length--
		return elem
	}
	return -1
}
*/
func (arr *Array[T]) max(compare func(i, j T) bool) T {
	if arr.isEmpty() {
		log.Panic("error: Array empty. can't find max element")
	}

	maxElem := arr.at(0)

	for i := 0; i < arr.size()-1; i++ {
		if compare(maxElem, arr.at(i)) {
			maxElem = arr.at(i)
		}
	}

	return maxElem
}

/*
func (arr *Array[T]) min() T {
	if arr.isEmpty() {
		log.Panic("error: Array empty. can't find min element")
	}

	minElem := arr.at(0)

	for i := 0; i < arr.size(); i++ {
		if arr.at(i) < minElem {
			minElem = arr.at(i)
		}
	}

	return minElem
}
*/

func (arr *Array[T]) reverse() []T {
	reversed := make([]T, arr.size(), arr.size())
	for i := arr.size(); i > 0; {
		reversed[arr.size()-i] = arr.at(i)
		i--
	}
	return reversed
}

func (arr *Array[T]) intersect(other *Array[T]) {
	// will be implemented once set is implemented.

}

func main() {
	numbers := Array[int]{}
	for i := 0; i < 1e1; i++ {
		numbers.push(i * 2)
	}

	fmt.Println(numbers.indexOf(400), nil)
}
