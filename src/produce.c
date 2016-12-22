//
// Created by ChengZhehao on 2016/12/22.
//
#include <stdio.h>

int main(){
    int c;
    while (1) {
        c = getchar();
//        putchar('c');
        if (c == '$' || c == EOF)
            break;
    }
    return 0;
}