package main

import "fmt"

// main函数，go语言启动的入口
func main() {
	//fmt.Println  打印一句话 执行完毕后换行
	fmt.Println("Hello Golang")

	//定义变量
	var name string = "陈英豪" //go中定义的变量必须使用
	fmt.Println(name)
	//string默认值为空
	//int的默认值为0

	//简单定义
	num := 18 //编译器自动推导数据类型
	fmt.Println(num)

	//一次定义多个
	var (
		a int
		b string
	)
	fmt.Println(a, b)
}
