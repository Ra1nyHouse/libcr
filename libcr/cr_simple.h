/*
 * 协程简单实现
 */

#ifndef CR_SIMPLE_H
#define CR_SIMPLE_H

#define CR_START static int state=0; switch(state) { case 0:
#define CR_RETURN(var) do { state=__LINE__; return var; case __LINE__:; } while (0)
#define CR_END }

#endif