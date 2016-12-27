//
// Created by ChengZhehao on 2016/12/23.
//
#include <stdlib.h>
#include <stdio.h>

#define CR_CONTEXT            void *
#define CR_CONTEXT_PARAM      void **crContextParam

#define CR_CONTEXT_START      struct crContextStruct { int crLine
#define CR_CONTEXT_END(crCtx) } *crCtx = (struct crContextStruct *)*crContextParam

#define CR_START(crCtx)       if(!crCtx) {crCtx= *crContextParam=malloc(sizeof(*crCtx)); crCtx->crLine=0;}\
                              if (crCtx) switch(crCtx->crLine) { case 0:;
#define CR_END(z)             } free(*crContextParam); *crContextParam=0; return (z)
#define CR_END_NO_PARAM       } free(*crContextParam); *crContextParam=0; return

#define CR_RETURN(z)            \
        do {\
            ((struct crContextStruct *)*crContextParam)->crLine=__LINE__;\
            return (z); case __LINE__:;\
        } while (0)
#define CR_RETURN_NO_PARAM       \
        do {\
            ((struct crContextStruct *)*crContextParam)->crLine=__LINE__;\
            return; case __LINE__:;\
        } while (0)

// 协程内部终止
#define CR_STOP(z)           do{ free(*crContextParam); *crContextParam=0; return (z); }while(0)
#define CR_STOP_NO_PARAM     do{ free(*crContextParam); *crContextParam=0; return; }while(0)

// 协程外部终止
#define CR_ABORT(crCtx)      do{ if(!crCtx) free(crCtx); crCtx = 0; } while (0)

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


int main() {
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
