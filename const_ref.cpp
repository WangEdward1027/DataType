//探究const 类型 & 作为返回值
//&:避免return时拷贝副本
//const:避免外部的调用者修改引用的内容

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Point{
public:
    //无参构造
    Point()
    :_ix(0)
    ,_iy(0)
    {
        cout << "Point()" << endl;
    }

    //有参构造
    /* explicit //禁止隐式转换 */
    Point(int x, int y = 0) //默认参数
    :_ix(x)
    ,_iy(y)
    {
        cout << "Point(int x, int y)" << " ("<< _ix << "," << _iy << ")" << endl;
    }

    //拷贝构造
    Point(const Point & rhs)
    :_ix(rhs._ix) //只有构造函数才有初始化列表
    ,_iy(rhs._iy) //无参构造、有参构造、拷贝构造
    {
        cout << "Point(const Point & pt)" << endl;
    }

    //赋值运算符函数
    Point& operator=(const Point & rhs)
    {
        cout << "Point& operator=(const Point & pt)" << endl;
        _ix = rhs._ix;
        _iy = rhs._iy;
        return *this;
    }

    //析构函数
    ~Point(){
        cout << "~Point()" << endl;
    }

    void print() const{
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
    
    //const 引用作为返回值
    const int & showX(){
        return _ix;
    }

    //const 引用作为返回值
    const int & showY(){
        return _iy;
    }

    //仅将引用作为返回值,外部的调用者可以凭借返回值引用,修改数据本身
    int & getX(){
        return _ix;
    }

private:
    int _ix;
    int _iy;
};

void test(){
    Point pt(7,8);
    cout << pt.showX() << endl;   
    /* pt.showX = 100; //const & 不可以修改 */

    pt.getX();
    cout << pt.getX() << endl;

    //返回值是引用,修改返回值就会造成数据本身被修改
    pt.getX() = 200;
    cout << pt.getX() << endl;
    pt.print();
}

int main()
{
    test();
    return 0;
}
