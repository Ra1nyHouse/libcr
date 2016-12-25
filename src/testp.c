//
// Created by ChengZhehao on 2016/12/25.
//

#include <stdlib.h>
#include <stdio.h>

void fun(void **pp)
{
     int *p =        (int *)*pp;
    if(!p) printf("ok");
}

int main() {
    void *p;
    p=0;
    fun(&p);
    return 0;
}