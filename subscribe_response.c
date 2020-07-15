#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

int main()
{printf("Waiting for response sent by consensus miners.................");
	char cmd[100]="ipfs pubsub sub response > response.txt";
	system(cmd);

return 0;
}
