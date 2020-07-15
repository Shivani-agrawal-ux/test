#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

int main()
{  printf(".................subscribe block published by leader miner............");


	char cmd[100]="ipfs pubsub sub block > output.txt";
	system(cmd);

return 0;
}
