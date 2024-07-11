#include <iostream> 
using std::cout;
using std::endl;

int main()
{
    //double转int是向0取整,截断小数部分
    double a = 1.9;
    double b = 2.9;
    int a1 = a;
    int b1 = b;
    cout << a1 << endl;
    cout << b1 << endl;
    
    double c = -1.1;
    double d = -1.9;
    int c1 = c;
    int d1 = d;
    cout << c1 << endl;
    cout << d1 << endl;
    
    return 0;
}
