#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void f1(char* data){
	char buff[10];
	strcpy(buff, data);
	printf("%s\n", buff);
	return;
}
int foo(){
	printf("Learning is fun with Arif Butt.\n");
	exit(0);
}
int main(int argc, char*argv[]){
	f1(argv[1]);
	exit(0);
}