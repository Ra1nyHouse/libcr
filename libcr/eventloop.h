#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "cr_context.h"

typedef void (*callback_t)(CR_CONTEXT_PARAM);
enum event_status{
    // 初始状态，上下文未被初始化， 上下文指向空
    INIT,
    // 等待执行
    WAIT,
    // 正在执行
    ACTIVE,
    // 结束，上下指向空
    FINISH};

typedef struct cr_event {
    CR_CONTEXT context;
    callback_t callback_fun;
    enum event_status status;
} event_t;

typedef struct cr_loop {
    event_t *event;
    struct cr_loop *next;
} loop_t;

loop_t *init_loop();
int add_event(loop_t *loop, event_t *event);
void run_loop(loop_t *loop);

#endif