//
// Created by ChengZhehao on 2016/12/27.
//

#include "eventloop.h"
#include "cr_context.h"
#include <stdio.h>

int shared_var = 0;

void producer(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int i;
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            for (ctx->i = 0; ctx->i < 10; ) {
                if (shared_var==0)
                {
                    printf("This is \033[1;31mproducer\033[0m: produce a product \n");
                    shared_var = 1;
                    (ctx->i)++;
                }
                else
                {
                    printf("This is \033[1;31mproducer\033[0m: wait consuming a product \n");
                }
                CR_RETURN_NO_PARAM;
            }
    printf("This is \033[1;31mproducer\033[0m: finish producing  \n");
    shared_var=-1;
    CR_END_NO_PARAM;
}

void consumer(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int i;
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            while (1)
            {
                if (shared_var==1)
                {
                    printf("This is \033[1;32mconsumer\033[0m: consume a product \n");
                    shared_var = 0;
                }
                else if(shared_var==0)
                {
                    printf("This is \033[1;32mconsumer\033[0m: wait producing a product \n");
                }
                else if(shared_var==-1)
                {
                    printf("This is \033[1;32mconsumer\033[0m: finish consuming \n");
                    break;
                }
                CR_RETURN_NO_PARAM;
            }
    CR_END_NO_PARAM;
}


int main() {
    // 创建事件
    event_t producer_event;
    producer_event.context=NULL;
    producer_event.callback_fun=&producer;
    producer_event.status=INIT;

    event_t consumer_event;
    consumer_event.context=NULL;
    consumer_event.callback_fun=&consumer;
    consumer_event.status=INIT;

    // 创建循环
    loop_t *loop = init_loop();
    add_event(loop, &producer_event);
    add_event(loop, &consumer_event);

    // 运行循环
    run_loop(loop);

    return 0;
}
