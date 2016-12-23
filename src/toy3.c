//
// Created by ChengZhehao on 2016/12/23.
//

#include <stdio.h>

// 利用switch实现了goto的效果，实现了从return的地方开始执行
int fun() {
    // 静态函数第一初始化时赋值，之后改赋值语句不会起作用
    static int i, state = 0;
    switch (state) {
        case 0: ; // START_POS
        for (i = 0; i < 10; i++) {
            state = 1;
            return i;
            case 1: ; // LAST_POS
        }
    }
    return -1;
}

int main() {
    int i;
    for (i=0; i< 10; i++)
        printf("%d ", fun());
    return 0;
}
