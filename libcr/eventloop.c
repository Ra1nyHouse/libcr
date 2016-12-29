//
// Created by ChengZhehao on 2016/12/16.
//

#include "eventloop.h"
#include <stdlib.h>
#include <stdio.h>

int run_event(event_t *event);

loop_t *init_loop()
{
    loop_t* loop = (loop_t*)malloc(sizeof(loop_t));
    if (loop==NULL)
    {
        printf("malloc fail!\n");
        exit(-1);
        return NULL;
    }
    loop->event = NULL;
    loop->next = NULL;
    return loop;
}

int add_event(loop_t *loop, event_t *event)
{
    if (event->status!=INIT)
    {
        printf("this event should be initialized.");
        CR_ABORT(event->context);
        event->status = INIT;
    }
    while (loop->next!=NULL)
        loop = loop->next;
    loop_t *new_loop = init_loop();
    loop->next = new_loop;
    new_loop->event = event;
    return 1;
}

void run_loop(loop_t *loop)
{
    loop_t *head = loop;
    while (1)
    {
        // 统计执行协程数量
        int cnt_exec=0;
        loop_t *current_loop = loop;
        loop_t *next_loop = current_loop->next;
        while (1)
        {
            if (next_loop==NULL)
                break;
            if (run_event(next_loop->event))
            {
                cnt_exec ++;
                // 协程结束，释放资源
                if (next_loop->event->status==FINISH)
                {
                    current_loop->next = next_loop->next;
                    free(next_loop);
                    next_loop = current_loop->next;
                }
                else
                {
                    current_loop = next_loop;
                    next_loop = current_loop->next;
                }
            }
        }

        if(cnt_exec==0)
            break;
    }
}

int run_event(event_t *event)
{
    if(event->status==INIT || event->status==WAIT)
    {
        event->status=ACTIVE;
        (*(event->callback_fun))(&(event->context));
        if (event->context)
            event->status=WAIT;
        else
            event->status=FINISH;
        return 1;
    }
    return 0;
}