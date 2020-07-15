#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

struct node
{
	char name[100];
	char amt[100];
};
struct brick{
	char name[100];
	char trust[100];
};
struct trust_node
{
char peerid[100];
char trust[10];
};
int fun(char s[],char sub[],int n1,int n2)
{
int i;
if(n2!=n1+1)
    return 0;
for( i=0;i<n1;i++)
{
if(s[i]!=sub[i])
    return 0;
}
return 1;
}
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

	char peerid[100],id[100];
	//FILE *g=fopen("output.txt","w");fclose(g);
	char command[100]="ipfs config show | grep \"PeerID\" > abc.txt";
	system(command);
	FILE *file_peer=fopen("abc.txt","r");
	fgets(peerid,sizeof(peerid),file_peer);printf("Peer id:%s\n",peerid);
	fclose(file_peer);
	int p;//position of : in peer id
	for(p=0;p<strlen(peerid);++p)
	{if(peerid[p]==':')break;}//printf("%d\n",p);
	subst(peerid,id,p+3,strlen(peerid)-2);id[46]='\0';
           printf("Peer id:%s.............\n",id);
	//printf("Peer id:%s\n",id);
	struct node arr[100];
	int g=0;


		char info[1000],last_hash[100],choice[100],buyer_name[20],buyer_father_name[20],buyer_address[80],buyer_Id[30],Prop_rec_no[50],Prop_Loc[80],Prop_area[100],
	     E_stamp_no[50],E_stamp_Issue_date[30],seller_name[30],seller_father_name[30],seller_address[80],seller_Id[30],seller[50],owner[50];
	     int fraud;
		printf("................Opening the Output.txt file to subtract the transaction details..................\n.");//printf("opening output.txt\n");
		FILE *fp=fopen("output.txt","r");
		printf("opened output.txt\n");
		fgets(info,sizeof(info),fp);
		//fscanf(fp,"%s",info);
    printf("Transaction received from leader miner= %s\n",info);

		fclose(fp);
		while(strcmp(info,"")==0){//sleep(1);
		FILE *fp=fopen("output.txt","r");
		printf("%s",info);
		printf("Stuck Here2!!!\n");
		fscanf(fp,"%s",info);
		fgets(info,sizeof(info),fp);
		fclose(fp);
		}

		int len=strlen(info);
		system(">output.txt");
		info[len]='\0';
		int i,c2=0,answer=0;
		//int ar[4];
		int ar[14];
		for(i=0;i<len;++i)
		{
			if(info[i]==',')
			ar[c2++]=i;
		}

		subst(info,buyer_name,0,ar[0]-1); //int b=strlen(buyer_name);buyer_name[b]='\n';buyer_name[b+1]='\0';
		subst(info,seller_name,ar[0]+1,ar[1]-1);//b=strlen(seller_name);seller_name[b]='\n';seller_name[b+1]='\0';
		subst(info,buyer_father_name,ar[1]+1,ar[2]-1);
		subst(info,seller_father_name,ar[2]+1,ar[3]-1);//b=strlen(seller_father_name);seller_father_name[b]='\n';seller_father_name[b+1]='\0';
		subst(info,buyer_address,ar[3]+1,ar[4]-1);//b=strlen(buyer_address);buyer_address[b]='\n';buyer_address[b+1]='\0';
		subst(info,seller_address,ar[4]+1,ar[5]-1);//b=strlen(seller_address);seller_address[b]='\n';seller_address[b+1]='\0';
		subst(info,buyer_Id,ar[5]+1,ar[6]-1);//b=strlen(buyer_Id);to[buyer_Id]='\n';buyer_Id[b+1]='\0';
        subst(info,seller_Id,ar[6]+1,ar[7]-1); //b=strlen(seller_Id);seller_Id[b]='\n';seller_Id[b+1]='\0';
		subst(info,Prop_rec_no,ar[7]+1,ar[8]-1); //b=strlen(Prop_rec_no);Prop_rec_no[b]='\n';Prop_rec_no[b+1]='\0';
		subst(info,Prop_Loc,ar[8]+1,ar[9]-1); //b=strlen(Prop_Loc);Prop_Loc[b]='\n';Prop_Loc[b+1]='\0';
		subst(info,Prop_area,ar[9]+1,ar[10]-1); //b=strlen(Prop_area);Prop_area[b]='\n';Prop_area[b+1]='\0';
		subst(info,E_stamp_no,ar[10]+1,ar[11]-1); //b=strlen(E_stamp_no);E_stamp_no[b]='\n';E_stamp_no[b+1]='\0';
		subst(info,E_stamp_Issue_date,ar[11]+1,ar[12]-1); //b=strlen(E_stamp_Issue_date);E_stamp_Issue_date[b]='\n';E_stamp_Issue_date[b+1]='\0';
		subst(info,last_hash,ar[12]+1,ar[13]-1);
		subst(info,choice,ar[13]+1,len-1);
		choice[1]='\0';
  printf("transaction details received from leader\n");
  struct trust_node arr[num_miners];
// for checking that the miner is consensus or not
/*FILE* file_x=fopen("trust.txt","r");
char lt[100],pt[10];
while(fgets(lt,sizeof(lt),file_x))
{
fgets(pt,sizeof(pt),file_x);
strcpy(arr[k].peerid,lt);
strcpy(arr[k].trust,pt);
k++;
}
int i;
for(i=0;i<=k;i++)
{
    if(strcmp(peerid,arr[k].peerid)==0)
        break;
}*/


//if(arr[i].trust>20) then do the below process

		printf("\nbuyer_name=%s,",buyer_name);
		printf("buyer_father_name=%s,",buyer_father_name);
		printf("buyer_address=%s,",buyer_address);
		printf("buyer_Id=%s,",buyer_Id);
		printf("seller_name=%s,",seller_name);
		printf("seller_father_name=%s,",seller_father_name);
		printf("seller_address=%s,",seller_address);
		printf("seller_Id=%s,",seller_Id);
		printf("Prop_rec_no=%s,",Prop_rec_no);
		printf("Prop_Loc=%s,",Prop_Loc);
		printf("Prop_area=%s,",Prop_area);
		printf("E_stamp_no=%s,",E_stamp_no);
      //  printf("E_stamp_no=%s\n",E_stamp_no);
        printf("E_stamp_Issue_date=%s,",E_stamp_Issue_date);
        printf("last_hash=%s,",last_hash);
        printf("choice=%s\n",choice);
		int loop=1;
		printf("\n...................Verification started.................\n");
		if(strcmp(last_hash,"Genesis_BLOCK")==0)
		loop=0;
int x=0;
		int flag1=-1,flag2=-1;
		char str[100];
		while(1 && loop){//start of while loop
                fraud=0;
		if(strcmp(last_hash,"Genesis_BLOCK\n")==0 ||  strcmp(last_hash,"Genesis_BLOCK")==0)
		break;
		strcpy(str,"ipfs block get ");
		strcat(str,last_hash);
		strcat(str," > last_hash.txt");
		printf("string in system-->%s\n",str);
		system(str);
		usleep(10);
		//char rflh[6][100];//rflh=read from last hash
		char rflh[16][100];
		FILE *file1=fopen("last_hash.txt","r");
		int count=0,pos,w;
		char line[1200];
		strcpy(line,"");
		while(fgets(line,sizeof(line),file1)){
		//printf("********************reading from last hash.txt 1************************\n");
			//printf("%s",line);
			int len=strlen(line);
			int k;

			for(k=0;k<len;++k){
			//printf("********************reading from last hash.txt 2 ************************\n");
			if(line[k]==':')
			{pos=k;
			printf("breaking now\n");
			break;}
			}
			printf("reached here 1\n");
			subst(line,rflh[count],pos+1,len-1);//printf("%s\n",rflh[count]);
			count++;
			//sleep(2);
		}
		fclose(file1);
             /*		printf("started----\n");

	                     	for(w=0;w<16;w++)
	                	printf("%s ",rflh[w]);
		            printf("printed-------\n");*/
		strcpy(last_hash,rflh[0]);
		int l = strlen(last_hash);
		last_hash[l-1]='\0';
		printf("last hash-->%s \n",last_hash);
		  if(fun(seller_name,rflh[1],strlen(seller_name),strlen(rflh[1])) && fun(seller_father_name,rflh[3],strlen(seller_father_name),strlen(rflh[3])) && fun(seller_address,rflh[5],strlen(seller_address),strlen(rflh[5])) && fun(seller_Id,rflh[7],strlen(seller_Id),strlen(rflh[7])) && flag1==-1 )
              flag1=0;
          if(fun(Prop_rec_no,rflh[9],strlen(Prop_rec_no),strlen(rflh[9])) &&  fun(Prop_Loc,rflh[10],strlen(Prop_Loc),strlen(rflh[10])) && fun(Prop_area,rflh[11],strlen(Prop_area),strlen(rflh[11])) && flag2==-1)
              flag2=0;

	++x;
		int h;
		for(h=0;h<16;++h) strcpy(rflh[h],"");

		for(h=0;h<16;++h) strcpy(rflh[h],"");
	if(flag1==0 && flag2==0)
            break;

	if(flag2==0 && flag1==-1)
        fraud=1;
    if(fraud==1)
        break;
     if((flag1==0 && flag2==-1) || (flag1==-1 && flag2==-1))
     {
            flag1 =-1 ;flag2=-1;
     }

		}//end of while loop
		if(flag1==-1)
             strcpy(owner,"owner");

		if(flag2==-1)
		strcpy(seller,"seller");

		if(strcmp(choice,"1")==0){//property registration

			if(strcmp(last_hash,"Genesis_BLOCK\n")==0 || strcmp(last_hash,"Genesis_BLOCK")==0 )//first block
              {
                  printf("Owner name=%s",buyer_name);
               answer=1;}
               else if(fraud==0)//property registered that is not of others
                 {

                 printf("Owner name=%s",buyer_name);
                    answer=1;
                 }
		}
		else if(strcmp(choice,"2")==0){//property transaction
			if(flag1==0 && flag2==0)
            {
        printf("Owner name=%s",buyer_name);
			answer=1;}

		}

           printf("\n................verification completed............... ");

         printf("\n ..................Publishing response.............\n");
		char res[100]="ipfs pubsub pub response ";
		strcat(res,id);char a[100];
		if(answer==0)
		a[0]='0';
		else
		a[0]='1';
		a[1]='\0';
		strcat(res,",");strcat(res,a);strcat(res,".");
		system(res);
		printf("executed-->%s\n",res);
		/*FILE *fres = fopen("pid_res.txt","r");
		char t[10];
		fscanf(fres,"%s",t);
		char strTemp[100] = "kill -9 ";
		strcat(strTemp,t);
		system(strTemp);
		printf(" %d kill command-->%s\n",++g,strTemp);
		sleep(20);
		system("gnome-terminal -x sh -c \"./sub_block; bash\"");
		strcpy(info,"");*/
	//}
/*	FILE* fr=fopen("result.txt","r");
		char result[100];
		strcpy(result,"");
		fgets(result,sizeof(result),fr);
		fclose(fr);

		while(strcmp(result,"")==0)
		{
			FILE* fr=fopen("result.txt","r");
			fgets(result,sizeof(result),fr);
			if(strcmp(result,"")!=0){
			break;usleep(100);}
			printf("Stuck for result!!\n");
			fclose(fr);
		}*/


printf("\n Waiting for final consensus result.................");
/*FILE* fr=fopen("result.txt","r");
		char result[100];
		strcpy(result,"");
		fgets(result,sizeof(result),fr);
		fclose(fr);

		while(strcmp(result,"")==0)
		{
			FILE* fr=fopen("result.txt","r");
			fgets(result,sizeof(result),fr);
			if(strcmp(result,"")!=0){
			break;usleep(100);}
			printf("Stuck for result!!\n");
			fclose(fr);
		}



		result[46]='\0';
		printf("Result received=%s\n",result);

		char str_new[100];
		strcpy(str_new,"ipfs block get ");
		strcat(str_new,result);
		strcat(str_new," > miner_block.txt");
		system(str_new);

		char final_cmd[100];
		strcpy(final_cmd,"ipfs block put miner_block.txt > hash_miner.txt");
		system(final_cmd);*/


return 0;
}


