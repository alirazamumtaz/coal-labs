#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int getinput(){
    char buf[10];
    int rv = read(0, buf, sizeof(buf));
    printf("\nNumber of bytes read are %d\n", rv);
    return 0;
}
int main(){
    getinput();
    return 0;
}
