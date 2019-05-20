//
//  main.cpp
//  CppBasic
//
//  Created by PLUTO on 2019/5/7.
//  Copyright © 2019 PLUTO. All rights reserved.
//

#include <stdio.h>

#include <iostream>

using namespace std;

double Test(double a,double b){
    return a+b;
}

int main(){
    double a=1.223;
    double b=4.323;
    
    cout<<"a+b="<<Test(a,b)<<endl;
    return 0;
    }
