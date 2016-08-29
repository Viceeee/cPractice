#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char buf1[] = "benxintuzi";
char buf2[] = "BENXINTUZI";

int main(void)
{
        int fd;

        if ((fd = open("file", O_RDWR | O_CREAT)) == -1)
                printf("create error\n");

        if (write(fd, buf1, 10) != 10)
                printf("buf1 write error\n");
        /* offset now = 10 */

        if (lseek(fd, 16384, SEEK_SET) == -1)
                printf("lseek error\n");
        /* offset now = 16384 */

        if (write(fd, buf2, 10) != 10)
                printf("buf2 write error\n");
        /* offset now = 16394 */

        return 0;
}

