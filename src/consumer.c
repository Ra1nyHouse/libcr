//
// Created by ChengZhehao on 2016/12/22.
//
#include <stdio.h>

int is_alpha(int c)
{
    if((c>='a' && c<='z') || (c>='A' && c<='Z')) return 1;
    else return 0;
}
int main()
{
    int c;
    enum {START, IN_WORD, END_WORD} state;
    state = START;
    while (1) {
        c = getchar();
        if (c=='$' || c==EOF) break;
        switch (state) {
            case START:
                if (is_alpha(c))
                {
                    putchar(c);
                    state=IN_WORD;
                }
                break;
            case IN_WORD:
                if (is_alpha(c))
                    putchar(c);
                else
                    state=END_WORD;
                break;
            case END_WORD:
                if (is_alpha(c))
                {
                    putchar('\n');
                    putchar(c);
                    state=IN_WORD;
                }
                break;
        }
    }
    return 0;
}
