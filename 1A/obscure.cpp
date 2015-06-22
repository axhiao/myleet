#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

// 2.
int bar(int(x));
// 等价于 int bar(int x);

string foo(string());
// 等价于string foo(string (*)())

string test()
{
	return "test";
}

struct  Test
{
	int data;
	Test(){cout << "constructing Test" << endl;}
	~Test(){cout << "destructing Test" << endl;}	
};


// 6. 
struct Event { virtual ~Event() {} };
struct MouseEvent : Event { int x, y; };
struct KeyboardEvent : Event { int key; };
 
void log(Event *event) {
  if (MouseEvent *mouse = dynamic_cast<MouseEvent *>(event))
    std::cout << "MouseEvent " << mouse->x << " " << mouse->y << std::endl;
 
  else if (KeyboardEvent *keyboard = dynamic_cast<KeyboardEvent *>(event))
    std::cout << "KeyboardEvent " << keyboard->key << std::endl;
 
  else
    std::cout << "Event" << std::endl;
}


//7. 

struct Foo {
  void foo() & { std::cout << "lvalue" << std::endl; }
  void foo() && { std::cout << "rvalue" << std::endl; }
};

int main()
{


	//*  1. 方括号的真正含义   *//
	//  ptr[3]其实是 *(ptr+3) 的缩写，与*(3+ptr)是等价的
	//  所以，3[ptr]也是有效的代码
	int arr[] = {2, 3, 5, 2};	
	cout << 2[arr] << endl;

	//*  2. 最烦人的解析 most vexing parse  *//
	cout << bar(2) << endl;
	cout << foo(test) << endl;

	//*    3. 替代运算标记符     *//
	//标记符               and, and_eq, bitand, bitor, compl, not, not_eq, or, or_eq, xor, xor_eq, <%, %>, <: , :>
	//都可以用来代替我们常用的 &&,  &=,     &,     |,      ~,     !,    !=,   ||,  |=,    ^,   ^=,     {,  },  [ ,  ]
	//在键盘上缺乏必要的符号时你可以使用这些运算标记符来代替。
	cout << 2<:arr:> << endl;
	cout << (5 and 4) << endl;

	//*   4. 重定义关键字    *//
	/*
	*  #define class struct
	*  #define private public
	*  #define protected public
	 
	*  #include "library.h"
	 
	*  #undef class
	*  #undef private
	*  #undef protected
	*/

	//*    5. placement new    *//
	// placement new就是在用户指定的内存位置上构建新的对象，
	// 这个构建过程不需要额外分配内存，只需要调用对象的构造函数即可。
	// placement new实际上是把原本new做的两步工作分开来：第一步自己分配内存，
	// 第二步调用类的构造函数在自己已分配的内存上构建新的对象。
	// placement new的好处：
	// 1）在已分配好的内存上进行对象的构建，构建速度快。
	// 2）已分配好的内存可以反复利用，有效的避免内存碎片问题。

	// must alloclate our own memory
	Test *ptr_test = (Test*)malloc(sizeof(Test));

	// use placement new 
	new(ptr_test)Test;
	// must call the destructor ourselves
	ptr_test->~Test();
	// must release the memory ourselves
	free(ptr_test); // free matches malloc, delete matches new

	//*     6. 声明变量的同时进行分支     *//
	// 见 main函数之上



	//*     7. 成员函数的引用修饰符      *//

	Foo foo;
	foo.foo(); 
	// Prints "lvalue"
	Foo().foo(); 
	// Prints "rvalue"




	return 0;
}


int bar(int(x))
{
	return x;
}

string foo(string (*fun)())
{
	return  (*fun)();
}