//
//  LinearList.cpp
//  OpenGL
//
//  Created by PLUTO on 2019/5/23.
//  Copyright © 2019 PLUTO. All rights reserved.
//

#include <stdio.h>

//线性表合并算法（不讨论存储结构）
void union(linear_list:&la,linear_list:&lb){
    n=ListLength(la);   //la长度
    for(int i=0;i<ListLength(lb);i++){
        x=GetElem(lb,i);
        k=LeocateElem(la,x);
        if(k==-1)
            ListInsert(la,++n,x;)
    }
}

//有序线性表合并

