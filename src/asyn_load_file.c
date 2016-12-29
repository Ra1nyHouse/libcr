//
// Created by ChengZhehao on 2016/12/17.
//

#include "eventloop.h"
#include "cr_context.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 其他耗时操作 回调函数
void do_other(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int i;
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            for (ctx->i = 0; ctx->i < 10; ctx->i++) {
                printf("\033[1;31mdo_other():\033[0m doing something...\n");
                CR_RETURN_NO_PARAM;
            }
            printf("\033[1;31mdo_other():\033[0m stop!\n");
    CR_END_NO_PARAM;
}

// 读文件 回调函数
void load_file(CR_CONTEXT_PARAM) {
    CR_CONTEXT_START;
        int fd;
        int ret;
        unsigned char key_val[15];
    CR_CONTEXT_END(ctx);

    CR_START(ctx);
            ctx->fd = open("../README.md", O_RDONLY );
                if(ctx->fd<0)
                {
                    printf("fail to open file.\n");
                }
                else {
                    while (1)
                    {
                        ctx->ret = read(ctx->fd, &(ctx->key_val), 15);
                        // 文件结束
                        if (ctx->ret==0) break;
                        // 出错
                        if (ctx->ret<0) printf("\033[1;31mload_file(): \033[0msome errors.\n");
                        // 显示读到字节数
                        printf("\033[1;31mload_file(): \033[0mread data %d bytes.\n", ctx->ret);
                        CR_RETURN_NO_PARAM;
                    }
                }
            printf("\033[1;31mload_file(): \033[0mstop!\n");
    CR_END_NO_PARAM;
}


int main() {
    // 创建事件
    event_t do_other_event;
    do_other_event.context=NULL;
    do_other_event.callback_fun=&do_other;
    do_other_event.status=INIT;

    event_t load_file_event;
    load_file_event.context=NULL;
    load_file_event.callback_fun=&load_file;
    load_file_event.status=INIT;

    // 创建循环
    loop_t *loop = init_loop();
    add_event(loop, &do_other_event);
    add_event(loop, &load_file_event);

    // 运行循环
    run_loop(loop);

    return 0;
}
