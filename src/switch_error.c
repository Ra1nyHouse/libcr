//
// Created by ChengZhehao on 2016/12/23.
//

#include <stdio.h>

int main() {
    int out_state=0, in_state=1;
    switch (out_state)
    {
        switch (in_state)
        {
            case 0:
                printf("ok ...\n");
        }
        default:
            printf("end ...\n");
    }
    return 0;
}