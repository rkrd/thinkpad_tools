#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    
    if (argc != 2)
        return 1;

    fd = open("/proc/acpi/ibm/kbdlight", O_WRONLY);
    if (fd < 0)
        return 2;

    switch(argv[1][0]) {
    case '0':
    case '1':
    case '2':
        write(fd, argv[1], 1);
        return 0;
    default:
        return 3;
    }
}

