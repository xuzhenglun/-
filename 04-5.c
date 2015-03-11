#include <stdio.h>
#include <stdlib.h>

void try_to_connect(int *table,int A, int B);
void connect(int *table,int nodeA, int nodeB);
void count(int *table, int NUM);

int main(void)
{
	int MAX;
	scanf("%d\n", &MAX);
	int *p = (int)malloc((MAX+1)*sizeof(int));
	for (int i = 0; i <= MAX; i++)
	{
		p[i] = -1;
	}
	//初始各个节点表
	char command;
	int nodeA, nodeB;
	while (1)
	{
		scanf("%1c", &command);
		if (command == 'C') 
		{
			scanf(" %d %d", &nodeA, &nodeB);
			try_to_connect(p,nodeA,nodeB);
		}
		else if (command == 'I')
		{
			scanf(" %d %d", &nodeA, &nodeB);
			connect(p,nodeA, nodeB);
		}
		else if (command == 'S')
		{
			count(p,MAX+1);
			break;
		}
	}
	return 0;
}

void try_to_connect(int *table,int A, int B)
{
	if (table[A] == -1 && table[B] == -1)
	{
		if (A != B) printf("no\n");
		if (A == B) printf("yes\n");
	}		
	else
	{
		if (table[A] != -1 && table[B] != -1)
		{
			try_to_connect(table, table[A], table[B]);
		}
		else if (table[A] != -1 && table[B] == -1)
		{
			try_to_connect(table, table[A], B);
		}
		else if (table[A] == -1 && table[B] != -1)
		{
			try_to_connect(table, A, table[B]);
		}
	}
}

void connect(int *table, int A, int B)
{
	if (table[A] == -1 && table[B] == -1 && A != B)
	{
		table[A] = B;
	}
	else
	{
		if (table[A] != -1 && table[B] != -1)
		{
			connect(table, table[A], table[B]);
		}
		else if (table[A] != -1 && table[B] == -1)
		{
			connect(table, table[A], B);
		}
		else if (table[A] == -1 && table[B] != -1)
		{
			connect(table, A, table[B]);
		}
	}
}

void count(int *p,int NUM)
{
	int sum=0;
	for (int i = 1; i < NUM; i++){
		if (p[i] == -1)
			sum++;
	}
	if (sum > 1)
		printf("There are %d components.", sum);
	else if (sum == 1)
		printf("The network is connected.");
}