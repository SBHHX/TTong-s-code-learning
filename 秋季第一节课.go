package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

// LV1--加法函数
func add(a, b int) int {
	return a + b
}

// LV2--计算圆的面积
func Circle(R float64) float64 {
	return math.Pi * R * R
}

// LV3--判断素数
func PrimeTell(num int) bool {
	if num < 2 {
		return false
	}
	for i := 2; i*i <= num; i++ {
		if num%i == 0 {
			return false
		}
	}
	return true
}

// LVX--用二分法确定随机数
func binarySearch(target int) int {
	low, high := 1, 100
	for low <= high {
		mid := low + (high-low)/2
		if target == mid {
			fmt.Println("二分法找到目标")
			return target
		} else if target > mid {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	fmt.Println("未找到目标")
	return -1
}

func LVX() {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	secretNumber := r.Intn(100) + 1
	fmt.Println("生成的随机数：", secretNumber)
	binarySearch(secretNumber)
}

func main() {

	fmt.Println(add(1, 2))

	fmt.Println(Circle(3.14))

	fmt.Println(PrimeTell(9))

	LVX()

}
