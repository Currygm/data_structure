<font face=STKaiti>

# C++数据结构与算法

本材料为笔者在**数据结构与算法**课上的笔记。

## C++部分特性

### 部分函数和运算符重载

> 以下均以自定义**复数**类为例子。
```c++
class COMPLEX
{
public:
	COMPLEX(double r = 0, double i = 0); 
	COMPLEX(const COMPLEX &other);		 
	void print();						 
										 
	COMPLEX operator+(const COMPLEX &other);
	
	COMPLEX operator-(const COMPLEX &other);
	COMPLEX operator-(); 
	COMPLEX& operator=(const COMPLEX &other);
  
	COMPLEX &operator++();  
	COMPLEX operator++(int); 
	COMPLEX &operator--();   
	COMPLEX operator--(int); 
protected:
	double real, image; 
};
```

1. **拷贝构造函数和赋值运算符**：
   
    ```c++
    COMPLEX::COMPLEX(const COMPLEX &other) {
       real = other.real;
       image = other.image;
    }
    COMPLEX& COMPLEX::operator=(const COMPLEX& other) {
       real = other.real;
       image = other.image;
       return *this;
    }
    ```
    有以下几点需要注意：

    1. 传递的参数必须为**引用**。因为编译器在传递实例参数时是以**拷贝**的形式传递的，这样会导致**无限拷贝**而运行超时。
    2. 赋值运算符重载一定要**改变自身的成员变量**，并返回`*this`，以下为错误示范：
    ```c++
    COMPLEX& operator=(const COMPLEX& other) {
       return COMPLEX(other.real, other.image);
    }
    ```
    这样构建新的对象而非改变自身变量是错误的。

2. 前后置自增运算符

> 此处对实部和虚部都进行自增。

```c++
COMPLEX& COMPLEX::operator++() {
    real++;
    image++;
    return *this;
}       //重载前置++
COMPLEX COMPLEX::operator++(int) {
    double tmp1 = real;
    double tmp2 = image;
    real += 1;
    image += 1;
    return COMPLEX(tmp1, tmp2);
}     //重载后置++
```
区别在于**前置自增**需要是先完成自增再返回结果，因此可以直接返回对`this`的引用；而**后置自增**先返回自身结果再自增，因此需要重新构造一个对象来存储原本的数据，再对`this`指向的对象自增，最后再返回用来存储数据的对象。

### C++中的内置函数和方法

> 以下为笔者在使用C++时使用到的内置函数和方法，为避免遗忘，特此记录。

#### `template`模板函数中常用到的判断数据类型的函数

```c++
template<typename T>
T Plus(T a, T b) {
    cout<<"It's from ";
    if(is_integral<T>::value) {
    // is_integral<T>::value在T为int类型时返回真。
        cout<<"int!"<<endl;
    }
    else if(is_floating_point<T>::value){
    // is_floating_point<T>::value在T为浮点类型时返回真。
        cout<<"double!"<<endl;
    }
    else {
        cout<<"string!"<<endl;
    }
    return a + b;
}
```
以上`is_integral<T>`和`is_floating_point<T>`均为**类型萃取(Type Traits)**。
类型萃取一般都是依靠**特化模板类**来实现的，以下以`is_integral<>`为例子：
```c++
template<typename T>
struct is_integral : std::false_type {};  // 默认不是整型

template<>
struct is_integral<int> : std::true_type {}; // 特化为 true

template<>
struct is_integral<char> : std::true_type {};
// ... 对所有整型类型都做偏特化
```

## C++实现栈(stack)

stack是C++的一种数据结构，遵循`LIFO`(Last-In-First-Out)。C++在STL中提供了stack的部分方法，可通过`#include<stack>`调用，主要有`push`,`top`,`pop`,`empty`。C++提供了一个模板类`stack<TYPENAME>`，可用于存储不同的数据类型，例如`stack<int>`,`stack<double>`。

接下来我们用C++实现一个`Stack`类(vector)：
```c++

```