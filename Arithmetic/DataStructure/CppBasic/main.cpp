//
//  main.cpp
//  CppBasic
//
//  Created by PLUTO on 2019/5/7.
//  Copyright © 2019 PLUTO. All rights reserved.
//

/*
#include <stdio.h>

#include <iostream>

using namespace std;

double Test(double a,double b){
    return a+b;
}

bool test(bool x){
    return x;
}

bool test(double x){
    return x>0;
}

*/

//int main(){
  //  double a=1.223;
    //double b=4.323;
    
  //  cout<<"a+b="<<Test(a,b)<<endl;
    
    //函数的重载
    /*
     C++重载函数为什么不能用返回值来区别呢？
     
     因为C++调用一个函数是可以忽略其返回值的，这种情况下编译器就无法根据返回值类型来确定调用哪一个函数。
     
     所以，重载不能用返回值类型来区别
     
     C++重载，即 同作用域下，同函数名，参数不同（包括类型、个数、顺序）
     */
/*
if (test(true)){
        cout<<"pass"<<endl;
    }
    
    if(test(3.3)){
        cout<<"pass2"<<endl;
    }
    
    
    
    
    return 0;
    }

     */
/*
#include <iostream>

using namespace std;

// 基类
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;
};

// 派生类
class Rectangle: public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

int main(void)
{
    Rectangle Rect;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    
    return 0;
}
*/

int main(){
    int a=1;
    const int b=2;
    const int *prt1=&a;
    int* const prt2=&a;
}
