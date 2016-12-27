//
// Created by ChengZhehao on 2016/12/27.
//

#include <stdio.h>
#include "cr_context.h"

int shared_var = 0;

int fun(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int i;
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            for (ctx->i = 0; ctx->i < 10; ctx->i++) {
                CR_RETURN(ctx->i);
            }
    CR_END(-1);
}
void producer(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int i;
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            for (ctx->i = 0; ctx->i < 10; ) {
                if (shared_var==0)
                {
                    printf("This is producer: produce a product \n");
                    shared_var = 1;
                    (ctx->i)++;
                }
                else
                {
                    printf("This is producer: wait consume a product \n");
                }
                CR_RETURN_NO_PARAM;
            }
            printf("This is producer: finish producing  \n");
            shared_var=-1;
    CR_END_NO_PARAM;
}

int main()
{
    int i;
    CR_CONTEXT ctx=0;
    for (i=0; i< 5; i++)
    {
        printf("%d ", fun(&ctx));
    }
    printf("\n");
    CR_ABORT(ctx);
    for (i=0; i< 10; i++)
    {
        printf("%d ", fun(&ctx));
    }
    return 0;
}