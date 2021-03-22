#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int arr[] = {4,7,1,2,9,0,6,8,3,5};
// int arr[] = {0,1,2,3,4,5,6,7,8,9};

int main(int argc, char *argv[]){
    if(argc != 2){
        printf(2,"Usage: copylseek <filename>\n");
        exit();
    }
    int fd = open(argv[1],O_RDONLY);
    int copy = open("copy", O_CREATE | O_WRONLY);
    int len = lseek(fd,0,SEEK_END);
    printf(1,"Length: %d\n",len); 
    int partSize = (len/10 + (len % 10 != 0));
    int offset,count;
    char buf[partSize];

    for(int i = 0; i < len; i++){
        write(copy,"a",1);
    }
    for(int i = 0 ; i < 10; i++){
        offset = arr[i] * partSize;
        lseek(fd,offset,SEEK_SET);
        count = read(fd,buf,partSize);
        lseek(copy,offset,SEEK_SET);
        write(copy,buf,count);
    }
    exit();
}