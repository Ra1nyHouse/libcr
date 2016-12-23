//
// Created by ChengZhehao on 2016/12/22.
//

#include <stdio.h>

int is_alpha(int c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
    else return 0;
}
void consumer(int c)
{
    static enum {
        START, IN_WORD, END_WORD
    } state = START;

    if (c == '$' || c == EOF) return;
    switch (state) {
        case START:
            if (is_alpha(c)) {
                putchar(c);
                state = IN_WORD;
            }
            break;
        case IN_WORD:
            if (is_alpha(c))
                putchar(c);
            else {
                putchar('\n');
                state = END_WORD;
            }
            break;
        case END_WORD:
            if (is_alpha(c)) {
                putchar(c);
                state = IN_WORD;
            }
            break;
    }
}


int main(){
    int c;
    while (1) {
        c = getchar();

        //putchar(c);
        consumer(c);

        if (c == '$' || c == EOF)
            break;

    }
    return 0;
}