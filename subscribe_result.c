#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

int main()
{
	char cmd[100]="ipfs pubsub sub result > result.txt";
	system(cmd); 

return 0;
}
