//
// Created by ChengZhehao on 2016/12/22.
//
#include <stdio.h>

int fun() {
    // 静态函数第一初始化时赋值，之后改赋值语句不会起作用
    static int i, state = 0;
    switch (state) {
        case 0: goto START_POS;
        case 1: goto LAST_POS;
    }
    START_POS:
    for (i = 0; i < 10; i++) {
        state = 1;
        return i;
        LAST_POS:;
    }
}

int main() {
    int i;
    for (i=0; i< 10; i++)
        printf("%d ", fun());
    return 0;
}