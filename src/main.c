//
// Created by housecheng on 16-12-20.
//
#include <stdio.h>
#include "coroutine.h"


//#define crBegin static int state=0; switch(state) { case 0:
//#define crReturn(i,x) do { state=i; return x; case i:; } while (0)
//#define crFinish }
//int function(void) {
//    static int i;
//    crBegin;
//            for (i = 0; i < 10; i++)
//                crReturn(1, i);
//    crFinish;
//}

//int ascending(void) {
//    static int i;
//    scrBegin;
//        for (i = 0; i < 10; i++) {
//            scrReturn(i);
//        }
//    scrFinish(-1);
//}

int ascending(ccrContParam) {
    ccrBeginContext;
        int i;
    ccrEndContext(foo);
    ccrBegin(foo);
            for (foo->i = 0; foo->i < 10; foo->i++) {
                ccrReturn(foo->i);
            }
    ccrFinish(-1);
}

int consumer()
{
    return 0;
}
int produce()
{
    return 0;
}

int test() {
    static int i;
    i=1;
    i++;
    return i;
}
int main() {
//    ccrContext z = 0;
//    for(int i=0;i<3;i++)
//        printf("%d \n", ascending(&z));
//    for(int i=0;i<3;i++)
//        printf("%d \n", ascending(&z));
//    ccrAbort(z);
//    for(int i=0;i<3;i++)
//        printf("%d \n", ascending(&z));
    //printf("%d \n", ascending());

    return 0;
}
