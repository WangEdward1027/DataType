//作用域限定符/全局作用域解析运算符 ::

#include <iostream> 
using std::cout;
using std::endl;

int value = 100;

void test()
{
    int value = 200;
    cout << "value = " << value << endl;     //输出的是局部的
    cout << "::value = " << ::value << endl; //输出的是全局的
}

int main()
{
    test();   
    return 0;
}
edward@ed-vm:~/cpp58/CppBoost/test$ cat scope_qualifier.cpp 
//C++的作用域限定符/全局作用域解析运算符 ::

#include <iostream> 
using std::cout;
using std::endl;

int value = 100;

void test()
{
    int value = 200;
    cout << "value = " << value << endl;     //输出的是局部的
    cout << "::value = " << ::value << endl; //输出的是全局的
}

int main()
{
    test();   
    return 0;
}
