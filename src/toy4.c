//
// Created by ChengZhehao on 2016/12/23.
//

#include <stdio.h>

// 用宏封装了switch结构，利用了默认的宏__LINE__来确定执行的位置

#define CR_START static int state=0; switch(state) { case 0:
#define CR_RETURN(var) do { state=__LINE__; return var; case __LINE__:; } while (0)
#define CR_END }

int fun() {
    static int i;
    CR_START;
    for (i = 0; i < 10; i++) {
        CR_RETURN(i);
    }
    CR_END;
    return -1;
}


int main() {
    int i;
    for (i=0; i< 15; i++)
        printf("%d ", fun());
    return 0;
}