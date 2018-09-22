#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define LEN sizeof(struct train)
#define NULL 0
struct passenger
{
	char name[21];
	int RP;
};
struct train
{
	int num;
	int renshu;
	struct passenger per[101];
	struct train *next;
};
struct train * create(int N)
{
	struct train *head,*p1,*p2;
	p1=p2=(struct train *)malloc(LEN);
	head=NULL;
	for(int i=1;i<=N;i++)
	{
		p1->num=i;
		int x=0;
		getchar();
		scanf("%d",&x);
		p1->renshu=x;
		for(int j=0;j<x;j++)
		{
			getchar();
			scanf("%s%d",&p1->per[j].name,&p1->per[j].RP);
		}
		if(i==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct train *)malloc(LEN);
	}
	p2->next=NULL;
	return(head);
}
void print(struct train *head)
{
	struct train *p;
	p=head;
	do
	{
		printf("num %d     renshu %d\n",p->num,p->renshu);
		for(int i=0;i<p->renshu;i++)
			printf("          %s   %d\n",p->per[i].name,p->per[i].RP);
		p=p->next;
	}while(p!=NULL);
}
void geton(struct train *head,int x,char name[],int RP)
{
	struct train *p;
	p=head;
	while(p!=NULL)
	{
		if(p->num==x)
		{
			strcpy(p->per[p->renshu].name,name);
			p->per[p->renshu].RP=RP;
			p->renshu++;
			break;
		}
		else
			p=p->next;
	}
}
void join(struct train *head,int x,int y)
{
	struct train *p1,*p2,*p;
	int i,j;
	p=head;
	while(p!=NULL)
	{
		if(p->num==x)
			p1=p;
		if(p->num==y)
			p2=p;
		p=p->next;
	}
	j=0;
	for(i=p1->renshu;j<p2->renshu;i++)
	{
		strcpy(p1->per[i].name,p2->per[j].name);
		p1->per[i].RP=p2->per[j].RP;
		j++;
	}
	p1->renshu+=p2->renshu;
}
void getout(struct train *head,int x)
{
	struct train *p;
	int temp,min,rp[101],j=0;
	p=head;
	do
	{
		if(p->num==x)
		{
			min=p->per[0].RP;
			for(int i=0;i<p->renshu;i++)
			{
				if(p->per[i].RP<min)
					min=p->per[i].RP;
			}
			for(int i=0;i<p->renshu;i++)
			{
				if(p->per[i].RP==min)
				{
					rp[j]=i;
					j++;
				}
			}
			for(int i=j-1;i>0;i--)
			{
				if(strcmp(p->per[rp[i]].name,p->per[rp[i-1]].name)>0)
				{
					temp=rp[i];
					rp[i]=rp[i-1];
					rp[i-1]=temp;
				}
			}
			printf("%s\n",p->per[rp[0]].name);
			for(int i=rp[0];i<p->renshu;i++)
			{
				p->per[i]=p->per[i+1];
			}
			p->renshu--;
			break;
		}
		else
			p=p->next;
	}while(p!=NULL);
}
int main()
{
	int N=0,M=0,len=0;
	struct train *head;
	scanf("%d%d",&N,&M);
	head=create(N);
	for(int i=1;i<=M;i++)
	{
		char cmd[7],name[21];
		int x,y,RP;
		getchar();
		scanf("%s",cmd);
		len=strlen(cmd);
		switch(len)
		{
		case 5:scanf("%d%s%d",&x,name,&RP);geton(head,x,name,RP);break;
		case 4:scanf("%d%d",&x,&y);join(head,x,y);break;
		case 6:scanf("%d",&x);getout(head,x);break;
		}
	}
	return 0;
}