#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]){
    if(argc < 5){
        printf(2,"Usage: prog <filename> <offset> <length> <string>\n");
        exit();
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd == -1){
        printf(2,"Error: File not found\n");
        exit();
    }
    char buf[atoi(argv[3])];
    lseek(fd,atoi(argv[2]),SEEK_SET);
    read(fd,buf,atoi(argv[3]));
    // printf(1,"Read %d bytes\n%s\n",count,buf);
    if(strcmp(buf,argv[4]) == 0){
        printf(1,"Data read is same\nData is %s\n",buf);
    }
    else{
        printf(2,"Data read does not match\nData read is %s\n",buf);
        exit();
    }
    exit();
}