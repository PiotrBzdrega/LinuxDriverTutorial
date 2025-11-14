#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>



int main()
{
    char c;
    int fd = open("/dev/read_write_cdev", O_RDWR);
    if (fd<0)
    {
        perror("open");
        return fd;
    }

    while(read(fd,&c,1))
    {
        putchar(c);
    }
    close(fd);
    
    return 0;
}

