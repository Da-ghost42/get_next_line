#include "get_next_line.h"
#include <stdio.h>
int main(int argc, char const *argv[])
{
        char *str;
        int fd = open ("get_next_line.h",  O_RDONLY , 0644);
        str = get_next_line(fd);
        int i = 0;
        while (i++ < 100)
        {
            printf("%s", str);
            str = get_next_line(fd);
        }
        return 0;
}
