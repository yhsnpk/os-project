#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
int d;
void *primenum(void *a );
void prime(int );
main()
{
 int m,a,flag=0;
 printf("press 0 to continue the programm and 1 for the exit the programm:\n");
 scanf("%d",&m);
 if(m==0)
 {
 printf("PRIME NUMBERS BY USING MULTI THREADS \n");
 printf("ENTER THE ANY NUMBER \n");
 scanf("%d",&a);
 int *k=&a;
 d=a;
 pthread_t tid;
 while(*k>1)
 { pthread_create(&tid,NULL,primenum,(void *)k); 
pthread_join(tid,NULL);
  *k--;  
}
printf("\nTHREAD WAS CREATED ");
int l=a-1;
printf("\nprime numbers less than your number");
while(l>1)
{

	prime(l);
	l--;
}
}
else
{
	printf("You have enter to exit from the programm:\n");
}
getch();
}
void  *primenum(void *j)
{
 	int i,flag=0;
 	int *k;
	k=(int *)j;
	 
 	for(i=2;i<=*k/2;++i)
 	{
 		if(*k%i==0)
 		{
 			flag =1;
 			break;
		}
	 }
    if(flag==0)
    {
 	printf("\n\nIT IS A PRIME NUMBER:%d",*k);
    }  
}
void prime(int k)
{
	int i,flag=0,c;
 	for(i=2;i<=k/2;++i)
 	{
 		if(k%i==0)
 		{
 			flag =1;
 			break;
		}
	 }
    if(flag==0)
    {
 	printf("\nIT IS A PRIME NUMBER:%d",k);
    }
}

