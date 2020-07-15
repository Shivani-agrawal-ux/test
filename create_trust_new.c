#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

#define num_miners 2

void subst(char s[],char sub[],int p,int l)
{
	int i,c=0;
	for(i=p;i<=l;++i)
	{
		sub[c++]=s[i];
	}
	sub[c]='\0';
}

int main()
{

//char peer_cmd[100]="ipfs swarm peers > peer.txt";
//	system(peer_cmd);
	FILE *file_peer=fopen("peer.txt","r");
	char ip_plus_peer[1000];

	//copying content of trust.txt in another file so as to copy the trust value of previous miners later
	FILE* fp=fopen("trust.txt","r");
	FILE* file_copy=fopen("copy.txt","w");
	char s[100];strcpy(s,"");
	while(fgets(s,sizeof(s),fp))
	fprintf(file_copy,"%s",s);
	fclose(file_copy);
	fclose(fp);
	//copying complete

	FILE *trust_file=fopen("trust.txt","w");
	int check;
	while(fgets(ip_plus_peer,sizeof(ip_plus_peer),file_peer))
	{
	check=0;
	printf("%s\n",ip_plus_peer);
	char peer_id[1000];
	subst(ip_plus_peer,peer_id,strlen(ip_plus_peer)-46,strlen(ip_plus_peer)-1);
	printf("here\n");
	printf("%s\n",peer_id);
	char pid[100];strcpy(pid,peer_id);pid[46]='\0';

	//if the hash is available in the copy file then we need to take trust from that file
	//else we need to give the default value of hash=50

	file_copy=fopen("copy.txt","r");
	char str[100];char val[100];
	while(fgets(str,sizeof(str),file_copy))
	{
		printf("executed..\n");
		fgets(val,sizeof(val),file_copy);
		str[46]='\0';
		printf("str=%s\n",str);
		printf("pid=%s\n",pid);
		if(strcmp(pid,str)==0)
		{
		printf("hello..\n");
		check=1;
		fprintf(trust_file,"%s\n%s",pid,val);
		break;
		}

	}

	if(check==0)
	fprintf(trust_file,"%s40\n",peer_id);

	fclose(file_copy);
	}
	fclose(trust_file);

return 0;

}
