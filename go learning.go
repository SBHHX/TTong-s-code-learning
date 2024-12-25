package main

import "fmt"

func test() (int, int) {
	return 100, 200
}

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

	fmt.Println("num:%d\n", num)

	/*
			代码解释:
			fmt.Printf 是 fmt包中用于格式化输出的函数，它允许你使用格式化字符串和参数列表。
			在格式化字符串"The number is:%d\n”中，%d 是一个占位符，它告诉 fmt.Printf 函数，
			这里将被
			一个整数替换。
			第一个参数 num 是要替换 %d 的整数，\n 是一个转义字符，表示输出后换行。
			在 fmt.Printf("The sum of %d and %d is %d\n"，num1,num2,num1+num2)中，第一个 %d 会被
			num1 的值替换，第二个 %d会被 num2 的值替换，第三个 %d 会被 num1 + num2 的结果替换。
			除了 %d ，还有其他常用的格式化占位符:
			%s:用于格式化输出字符串。
			%f:用于格式化输出浮点数。
			%t :用于格式化输出布尔值。
		    %p:地址
			可以输出变量的默认格式，对于不同类型的变量，它会根据变量的类型使用不同的格式化规则。
			%v :
	*/

	//go中交换更方便一点
	var c, d int = 1, 2
	c, d = d, c
	fmt.Println(c, d)

	e, f := test() //这样写是直接初始化了两个变量
	//赋值是 =  怎么还搞忘了呢
	fmt.Println(e, f)

	_, g := test()
	fmt.Println(g)

	/*
		や 匿名变量
		匿名变量的待点是一个下画线”"，""本身就是一个特殊的标识符，被称为空白标识符。它可以像其他标识符那样用于变量的声明或赋值(任何
		类型都可以赋值给它)，
		但任何赋给这个标识符的值都将被抛弃，因此这些值不能在后续的代码中使用，也不可以使用这个标识符作为变量对其
		它变量进行赋值或运算。使用匿名变量时，只需要在变量声明的地方使用下画线替换即可。例如:
		func test()(int,int){
		return 100，200
		13 func main(){
		a，-:= test()
		-，b := test()
		fmt.Print1n(a，b)//输出的结果为 100,200
		//在第一行代码中，我们只需要获取第一个返回值，所以第二个返回值定义为匿名变量
		// 在第二行代码中，我们只需要获取第二个返回值，所以第一个返回值定义为匿名变量
		在编码过程中，可能会遇到没有名称的变量、类型或方法。虽然这不是必须的，但有时候这样做可以极大地增强代码的臭活性，这些变量被统称
		为匿名变量。
		匿名变量不占用内存空间，不会分配内存。匿名变量与匿名变量之间也不会因为多次声明而无法使用。
	*/
}
