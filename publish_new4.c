#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<time.h>
#include<windows.h>
#include<dos.h>
int num_miners;

struct trust_info
{
char name[100];
char trust[100];
char answer[100];
};

struct ans_node
{
char peerid[100];
char ans;
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

int count_trans=0;

int main()
{

	//Finding number of miners
	FILE* file_miners=fopen("trust.txt","r");
	char demo[100];int count_miners=0;
	while(fgets(demo,sizeof(demo),file_miners))
	{count_miners++;}
	fclose(file_miners);
	int num_miners=count_miners;
	//printf("Number of miners=%d\n",num_miners);
	//Number of miners found

	char command[100] = "type blocks.txt>blocks1.txt";

	system(command);
	FILE *fp  = fopen("blocks1.txt","r");

    int i, size, start, loop=1, counter;
    char buffer[47]="";
    char buffer1[47];
   // char sender[100];
    //char receiver[100];
    //char name[100];
    //int amount=0 ;
    //char line[256];
    fgets(buffer,47,fp);

    if(strlen(buffer) == 0)
     {
        strcat(buffer,"Genesis_BLOCK");
     }
     printf("buffer-->%s\n",buffer);
     fclose(fp);

	//char from[100],to[100],amt[100],comp_from[100],comp_to[100];
	char buyer_name[20],buyer_father_name[20],buyer_address[80],buyer_Id[30],Prop_rec_no[50],Prop_Loc[80],Prop_area[100],
	E_stamp_no[50],E_stamp_Issue_date[30],seller_name[30],seller_father_name[30],seller_address[80],seller_Id[30],owner_name[100],comp_seller[100];
	printf("Enter your choice : \n1-New Land Registration \n2-Land Transaction for change of ownership\n");
	int ch; int sum=0;
	scanf("%d",&ch);
	if(ch==2)
	{

	printf("Enter seller name:\n");
	scanf("%s",seller_name);
	printf("Enter seller Father Name\n");
	scanf("%s",seller_father_name);
	printf("Enter the buyer name:\n");
	scanf("%s",buyer_name);
	printf("Enter buyer father name:\n");
	scanf("%s",buyer_father_name);

	printf("Enter seller Address:\n");
	scanf("%s",seller_address);
	printf("Enter buyer Address:\n");
	scanf("%s",buyer_address);
	printf("Enter buyer id:\n");
	scanf("%s",buyer_Id);
	printf("Enter seller_id:\n");
	scanf("%s",seller_Id);
	printf("Enter the Property Record Number:\n");
	scanf("%s",Prop_rec_no);
	printf("Enter the Property_Location:\n");
	scanf("%s",Prop_Loc);
	printf("Enter the Property_Area:\n");
	scanf("%s",Prop_area);
	printf("Enter the Current E-Stamp-Number:\n");
	scanf("%s",E_stamp_no);
	printf("Enter the Current E_Stamp_Issue_Date ex:dd-mm-yyyy:\n");
	scanf("%s",E_stamp_Issue_date);

	}
	else if(ch==1)
	{
    printf("Enter Buyer name:\n");
	scanf("%s",buyer_name);
	strcpy(seller_name,"govt");

     printf("Enter Buyer Father Name:\n");
	 scanf("%s",buyer_father_name);
	strcpy(seller_father_name,"govt");

    printf("Enter Buyer Address:\n");
	scanf("%s",buyer_address);
	strcpy(seller_address,"govt");

	printf("Enter Buyer_id:\n");
	scanf("%s",buyer_Id);
	strcpy(seller_Id,"govt");

	//printf("Enter the Property Record Number:\n");
	//scanf("%s",Prop_rec_no);

	int m=rand();char str1[100];
	 sprintf(str1, "%d", m);
	strcpy(Prop_rec_no,str1);
	printf("Enter the Property_Location:\n");
	scanf("%s",Prop_Loc);
	printf("Enter the Property_Area:\n");
	scanf("%s",Prop_area);
	//printf("Enter the E-Stamp-Number:\n");
	//scanf("%s",E_stamp_no);
	int y=rand(); char str2[100];
	 sprintf(str2, "%d", y);
	strcpy(E_stamp_no,str2);
	//printf("Enter the E_Stamp_Issue_Date ex:dd-mm-yyyy:\n");
	//scanf("%s",E_stamp_Issue_date);

strcpy(E_stamp_Issue_date,"13-06-2020");

	}


	/*else if(ch==2)
	{
	printf("Enter your name\n");
	scanf("%s",name);
	printf("Enter the amount you want to deposit\n");
	scanf("%s",amt);
	strcpy(from,name);
	strcpy(to,name);
	}*/
	char total[1000]="";
	strcat(total,buyer_name);
	strcat(total,",");
	strcat(total,seller_name);
	strcat(total,",");
	strcat(total,buyer_father_name);
	strcat(total,",");
	strcat(total,seller_father_name);
	strcat(total,",");
	strcat(total,buyer_address);
	strcat(total,",");
	strcat(total,seller_address);
	strcat(total,",");
	strcat(total,buyer_Id);
	strcat(total,",");
	strcat(total,seller_Id);
	strcat(total,",");
	strcat(total,Prop_rec_no);
	strcat(total,",");
	strcat(total,Prop_Loc);
	strcat(total,",");
	strcat(total,Prop_area);
	strcat(total,",");
	strcat(total,E_stamp_no);
	strcat(total,",");
	strcat(total,E_stamp_Issue_date);
	strcat(total,",");

	//char total[100]="";
	//strcat(total,from);
	//strcat(total,",");
	//strcat(total,to);
	//strcat(total,",");
	//strcat(total,amt);

	//strcat(total,",");
	strcat(total,buffer);strcat(total,",");
	char choice[2];
	if(ch==1)choice[0]='1';else if(ch==2)choice[0]='2';
	choice[1]='\0';
	strcat(total,choice);
	char cmd[100]="ipfs pubsub pub block ";
	strcat(cmd,total);
	system(cmd);
	//timer starts


	FILE *fp1=fopen("named_block.txt","w");
	if(ch==2)
    {
    	fprintf(fp1,"previous_hash:%s\n",buffer);      // write the user input's values into this file
    	fprintf(fp1,"Buyer_name:%s\n",buyer_name);
    	fprintf(fp1,"Seller_name:%s\n",seller_name);
    	fprintf(fp1,"Buyer_father_name :%s\n",buyer_father_name);
    	fprintf(fp1,"Seller_father_name:%s\n",seller_father_name);
    	fprintf(fp1,"Buyer_address:%s\n",buyer_address);
    	fprintf(fp1,"Seller_address:%s\n",seller_address);
    	fprintf(fp1,"Buyer_Id:%s\n",buyer_Id);
    	fprintf(fp1,"Seller_Id:%s\n",seller_Id);
    	fprintf(fp1,"Prop_rec_no:%s\n",Prop_rec_no);
    	fprintf(fp1,"Prop_Loc:%s\n",Prop_Loc);
    	fprintf(fp1,"Prop_area:%s\n",Prop_area);
    	int y1=rand(); char str3[100];
	 sprintf(str3, "%d", y1);
	strcpy(E_stamp_no,str3);
    	fprintf(fp1,"E_stamp_no:%s\n",E_stamp_no);
    	strcpy(E_stamp_Issue_date,"4-03-2020");
    	fprintf(fp1,"E_stamp_Issue_date:%s\n",E_stamp_Issue_date);
    }
    else
    {
    fprintf(fp1,"previous_hash:%s\n",buffer);      // write the user input's values into this file
    	fprintf(fp1,"Buyer_name:%s\n",buyer_name);
    	fprintf(fp1,"Seller_name:%s\n",seller_name);
    	fprintf(fp1,"Buyer_father_name :%s\n",buyer_father_name);
    	fprintf(fp1,"Seller_father_name:%s\n",seller_father_name);
    	fprintf(fp1,"Buyer_address:%s\n",buyer_address);
    	fprintf(fp1,"Seller_address:%s\n",seller_address);
    	fprintf(fp1,"Buyer_Id:%s\n",buyer_Id);
    	fprintf(fp1,"Seller_Id:%s\n",seller_Id);
    	fprintf(fp1,"Prop_rec_no:%s\n",Prop_rec_no);
    	fprintf(fp1,"Prop_Loc:%s\n",Prop_Loc);
    	fprintf(fp1,"Prop_area:%s\n",Prop_area);
    	fprintf(fp1,"E_stamp_no:%s\n",E_stamp_no);
    	fprintf(fp1,"E_stamp_Issue_date:%s\n",E_stamp_Issue_date);
    }
    	//fprintf(fp1,"receiver:%s\n",to);
    	//fprintf(fp1,"amount:%s\n",amt);
    	fclose(fp1);
    	printf(" Block is created and published by leader miner ............ ");
    	printf("\n.......... Waiting for response..........");
        clock_t before=clock();
	//FILE *filep=fopen("response.txt","w");fclose(filep);
//h
	FILE *file_res=fopen("response.txt","r");
	//char rep[50*num_miners];
	char rep[1000];
	fgets(rep,sizeof(rep),file_res);
	//while(strcmp(rep,"")==0){sleep(1000);
	//fgets(rep,sizeof(rep),file_res);}
	while(strlen(rep)!=49) {//sleep(1);
            usleep(1);
	FILE *file_res=fopen("response.txt","r");
	fgets(rep,sizeof(rep),file_res);
	printf("\n...............Receiving responses....................\n");
	printf("reponse recieved=%s\n",rep);
	fclose(file_res);
	}
	//printf("%s\n",rep);
	//timer stops
	clock_t after=clock();
	int num_min=num_miners;
	//printf("\n");
	//printf("Time taken to receive all consensus miners response:7.435000ms",((after-before)*1.0)/CLOCKS_PER_SEC);
	//printf("Time taken to receive all consensus miners response:%lfms",((after-before)*1.0)/CLOCKS_PER_SEC);
	struct trust_info brr[100];
	int k=0,t=0,p=0,l=-1,m=-1;
	char samp[100];
//printf("received response=%s\n",rep);

struct ans_node ar[num_miners];
k=0;
int j;
for(i=0;i<strlen(rep);i+=49)
{
char str[100];
for(j=i;j<=i+45;++j)
str[j]=rep[i+j];
str[j]='\n';
strcpy(ar[k].peerid,str);
ar[k].ans=rep[i+47];
k++;
}
k=0;
struct trust_node arr[num_miners];

FILE* file_x=fopen("trust.txt","r");
char lt[100],pt[10];
while(fgets(lt,sizeof(lt),file_x))
{
fgets(pt,sizeof(pt),file_x);
strcpy(arr[k].peerid,lt);
strcpy(arr[k].trust,pt);
k++;
}
printf("\n ..........................consensus starting...............................\n");
for(i=0;i<num_miners;i++)
{
printf(" peer id of consensus miner =%s",ar[i].peerid);
}

for(i=0;i<num_miners;i++)
{
printf("%s\n",arr[i].trust);
}


 sum=ar[0].ans;
/*for(i=0;i<num_miners;i++)
{
for(j=0;j<num_miners;j++)
{
if(strcmp(ar[i].peerid,arr[j].peerid)==0)
{
char x=ar[i].ans;
char buf[10];
int tr;
strcpy(buf,arr[j].trust);
sscanf(buf,"%d",&tr);
int val;
if(x=='0')
val=-1;
else
val=1;
printf("%d %d\n",val,tr);
sum=sum+(val*tr);
printf("sum=%d",sum);
}
}
} */

char final[100];
if(sum<=0)
{
strcpy(final,"No block added.");
printf("\n Final Consensus result :  Block has proved to be invalid");
printf("\n............... No block added...................");
}
else
{
printf("\n Final Consensus result : Block has proved to be valid");
//printf("\n ...............Block is added into the blockchain....................")

strcpy(owner_name,buyer_name);
//int e=strlen(buyer_name);
//buyer_name[e]='\n';buyer_name[e+1]='\0';
strcpy(comp_seller,seller_name);
//int e=strlen(seller_name);
//seller_name[e]='\n';seller_name[e+1]='\0';

printf("\n...............started adding of block into the leader blockchain............... ");
char owner[100],seller[100];
char last_hash[100];
strcpy(last_hash,buffer);
//printf("buffer here--->%s\n",buffer);printf("last hash=%s\n",last_hash);


//	printf("owner_name=%s\n",seller_name);
	//printf("seller_name=%s\n",seller_name);
	//printf("loop=%d\n",loop);

	FILE* fp2=fopen("named_block.txt","a");
	 //Genesis block case
	char s1[100];

	
	strcpy(s1,buyer_name);
	strcat(s1,":");
	strcat(s1,owner);
	fprintf(fp2,"%s\n",s1);
	
	strcpy(s1,seller_name);
	strcat(s1,":");
	strcat(s1,seller);
	fprintf(fp2,"%s\n",s1);


	printf("\n current owner of the propety--->%s",buyer_name);
	fclose(fp2);
	char buf1[100]="ipfs block put named_block.txt > blocks.txt";
	system(buf1);
    // printf("\n%s",buf1);
	char comd[100] = "type blocks.txt>blocks1.txt";

	system(comd);
	FILE *fpb  = fopen("blocks1.txt","r");







	char lhs[100];
	fgets(lhs,sizeof(lhs),fpb);
	char cmd_res[100]="ipfs pubsub pub result ";
	strcat(cmd_res,lhs);
	//system(cmd_res);

	printf("\n last hash after adding the block--->%s",lhs);
	printf("\n Publishing hash to all nodes..........");
	/*char sys1[100]="ipfs pubsub pub result ";
	strcat(sys1,lhs);
	system(sys1);*/

}

printf("\n..........Trust value computation startted............");


clock_t after2=clock();

//printf("\n Time taken by the whole process:................. %lf ms",((after2-before)*1.0)/CLOCKS_PER_SEC);
FILE* time_fp=fopen("time.txt","a");
fprintf(time_fp,"%d %lf\n",count_trans,((after2-before)*1.0)/CLOCKS_PER_SEC);
fclose(time_fp);
char chk;

if(sum<=0)
chk='0';

else
chk='1';
printf("%s %s %s %s", ar[0].peerid,arr[0].peerid,ar[0].ans,arr[0].trust);
//printf("\n sdbhs");
for(i=0;i<num_miners;i++)
{
int val;
if(ar[i].ans==chk)
val=3;
else
val=-12;
for(j=0;j<num_miners;j++)
{
if(strcmp(ar[i].peerid,arr[j].peerid)==0)
{
    //printf("\na1");
int tr;
sscanf(arr[j].trust,"%d",&tr);
printf("\n Previous trust value %s of consensus miner whose peer id is :%s ", arr[i].trust, arr[i].peerid);
if(tr>=0 && tr<=120)
{
tr+=val;
}
if(tr<0)
tr=0;
else if(tr>120)
tr=120;
char fht[10];
sprintf(fht,"%d",tr);
strcpy(arr[i].trust,fht);

break;
}

}


}
//clock_t after2=clock();
FILE* ft=fopen("trust.txt","w");
int d;
for(d=0;d<num_miners;++d)
{
fprintf(ft,"%s",arr[d].peerid);
fprintf(ft,"%s\n",arr[d].trust);
}

//printf("\n updated trust value of the consensus miner=43");
printf("\n Time taken by the whole process:................. %lf",((after2-before)*1.0)/CLOCKS_PER_SEC);
FILE* time_fp=fopen("time.txt","a");
fprintf(time_fp,"%d %lf\n",count_trans,((after2-before)*1.0)/CLOCKS_PER_SEC);
fclose(time_fp);
return 0;
}






































