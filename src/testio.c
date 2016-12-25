//
// Created by housecheng on 16-12-25.
//
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    unsigned char key_val[100];
    int ret;
    int Oflags;
    int fd;
    fd = open("/home/housecheng/data/caipiao.txt", O_RDONLY );
    //fd = open("/dev/buttons", O_RDWR | O_NONBLOCK);
    if (fd < 0)
    {
        printf("can't open!\n");
        return -1;
    }

    while (1)
    {
        ret = read(fd, &key_val, 100);
        //printf("key_val: 0x%x, ret = %d\n", key_val, ret);
        printf("%d \n", ret);
        sleep(1);
    }

    return 0;
}