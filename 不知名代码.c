#include<stdio.h>//乱改的
#include<stdlib.h>
#include<string.h>
typedef struct{
	char ID[11];
	char Name[11];
	int score[3];
}student;
int add(student* a, int n);
int delete(student*a, int n);
int update(student *a, int n);
int show(student *a, int n);
int main()
{
	int n;
	scanf("%d", &n);
	student*a = (student*)malloc(n*sizeof(student));
	int i, count = 0, order;
	for(i = 0; i<n; i++)
	{
		scanf("%d", &order);
		getchar();
		if(order==1)
		{
			if(add(a, count)==0)
				printf("Students already exist\n");
			else
			{
				printf("Add success\n");
				count++;
			}
		}
		if(order==2)
		{
			if(delete(a, count)==0)
				printf("Students do not exist\n");
			else
			{
				printf("Delete success\n");
				count--;
			}
		}
		if(order==3)
		{
			if(update(a,count)==0)
				printf("Students do not exist\n");
			else
				printf("Update success\n");
		}
		if(order==4)
		{
			if(show(a,count)==0)
				printf("Students do not exist\n");
			else
			;
		}
	}
	return 0;
}
int add(student* a, int n)
{
	char ID[11], NAME[11];
	scanf("%s %s", ID, NAME);
	for(int i = 0; i<n; i++)
	{
		if(strcmp(ID, a[i].ID)==0)
		return 0;
	}
	strcpy(a[n].ID, ID);
	strcpy(a[n].Name, NAME);
	scanf("%d%d%d", &a[n].score[0], &a[n].score[1],&a[n].score[2]);
	return 1;
}
int delete(student*a, int n)
{
	char ID[11];
	scanf("%s", ID);
	for(int i = 0; i<n; i++)
	{
		if(strcmp(ID, a[i].ID)==0)
		{
			for(; i<n; i++)
			{
				a[i] = a[i+1];
			}
			return 1;
		}
	}
	return 0;
}
int update(student *a, int n)
{
	char ID[11];
	int SCORE[3];
	scanf("%s", ID);
	scanf("%d %d %d", &SCORE[0], &SCORE[1], &SCORE[2]);
	for(int i = 0; i<n; i++)
	{
		if(strcmp(ID, a[i].ID)==0)
		{
			a[i].score[0] = SCORE[0], a[i].score[1] = SCORE[1],a[i].score[2] = SCORE[2];
			return 1;
		}
	}
	return 0;
}
int show(student *a, int n)
{
	char ID[11];
	scanf("%s", ID);
	for(int i = 0; i<n; i++)
	{
		if(strcmp(ID, a[i].ID)==0)
		{
			float ave = (a[i].score[0]+a[i].score[1]+a[i].score[2])/3.0;
			printf("Student ID:%s\nName:%s\nAverage Score:%.1f\n", a[i].ID, a[i].Name,ave);
			return 1;
		}
		return 0;
	}
}
