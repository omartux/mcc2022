package main

import (
	//"fmt"
	"log"
	"time"
)

func main() {
	defer timeTrack(time.Now(), "Funcion Principal")
	var lista = []int{-608, 449, 333, 861, -627, -398, -714, 977, 562, -684, 490, -945, 460, -773, -448, -344, -706, 272, -842, -832, -359, -96, -943, 328, -498, 790, -737, 896, 843, -887, 844, 282, 152, -235, 663, 585, 610, 752, -285, 686, -784, 604, 709, 559, 803, -674, -245, -29, 101, 964, 315, -280, 213, 909, -16, -598, 207, -276, -858, 522, -605, 878, -764, 903, -88, -540, -768, -473, -715, 572, -650, -707, -262, -23, -166, 425, 121, -409, -415, -441, -256, 22, 688, 720, 697, -400, -627, 755, 596, 229, -186, -744, 236, 132, -445, 181, 555, 11, 701, 165}
	//fmt.Println(lista)
	quicksort(lista)

	//fmt.Println(lista)

}

func quicksort(a []int) []int {

	if len(a) < 2 {
		return a
	}

	left, right := 0, len(a)-1

	//pivot := rand.Int() % len(a)
	pivot := len(a) / 2

	a[pivot], a[right] = a[right], a[pivot]

	for i := range a {
		if a[i] < a[right] {
			a[left], a[i] = a[i], a[left]
			left++
		}
	}

	a[left], a[right] = a[right], a[left]

	quicksort(a[:left])
	quicksort(a[left+1:])

	return a
}

func timeTrack(start time.Time, name string) {

	elapsed := time.Since(start)
	log.Printf("%s toma %s", name, elapsed)
}
