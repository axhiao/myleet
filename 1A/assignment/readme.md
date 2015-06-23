


#### 注意点

+ 返回值的类型声明为该类型的引用，并在函数结束前返回实例自身的引用（即*this).只有这样才可以实现连续赋值 str1 = str2 = str3.

+ 传入的参数的类型声明为常量引用。提高效率，不改变传入实例的状态。

+ 释放实例自身已有内存。防止出现内存泄漏。

+ 判断传入的实参与当前实例(*this)是否是同一个实例。如果是，则不进行赋值，否则会因为过早释放内存而出现引用错误的异常。


确保对象自我赋值时operator=有良好的行为。其中技术包括“来源对像”和“目标对象”的地址、精心周到的语句顺序、以及copy-and-swap。

+ “来源对像”和“目标对象”的地址：即证同测试
+ 精心周到的语句顺序：包含异常安全的考虑

```C++

CMyString& CMyString::operator=(const CMyString& rhs)
{
    char* pOrig = m_pData;
    m_pData = new char[strlen(rhs.m_pData) + 1];
    strcpy(m_pData, rhs.m_pData);
    delete[] pOrig;
    return *this;
}
```
+ copy-and-swap

创建临时实例strTemp，接着把strTemp.m\_pData与实例自身的m\_pData交换，由于strTemp是局部变量，当超出变量的作用域以后该变量会被析构，相应其指向的内存也会释放掉。（strTemp.m\_pData指向的内存就是实例之前m\_pData指向的内存）

```
CMyString& CMyString::operator=(const CMyString& rhs)
{
    CMyString strTemp(rhs);
    
    char* pTemp = strTemp.m_pData;
    strTemp.m_pData = m_pData;
    m_pData = pTemp;

    return *this;
}
```

#### 测试用例

+ 把一个CMyString的实例赋值给另外一个实例
+ 把一个CMyString的实例赋值给它自己
+ 连续赋值

#### 考点

+ C++的基础语法的理解， 如运算符函数、常量引用
+ 内存泄漏
+ 对代码异常安全性的理解


