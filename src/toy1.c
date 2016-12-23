//
// Created by ChengZhehao on 2016/12/22.
//
#include <stdio.h>

int fun() {
    static int i;
    for (i=0; i<10; i++)
        return i;
}

int main() {
    int i=0;
    for (i=0; i< 10; i++)
        // 期望每次调用fun()的时候，都能从上次return的地方执行
        printf("%d ", fun());
    return 0;
}