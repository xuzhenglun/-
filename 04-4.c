//MLGB的,写了两天终于对了,我是菜B

﻿#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
	int date;
	int num;
	struct Node * left;
	struct Node * right;
	struct Node * father;
} node;


void insert_node(node * root, node * node);
void keep_balance(node * root, node * new_node);
node * creat_node(int item);
int gethigh(node *p);
void ll(node *p);
void rr(node *p);
void lr(node *p);
void rl(node *p);

int main(void)
{
	int MAX_node;
	scanf("%d", &MAX_node);
	int item;
	node *p = creat_node(1 << 17 -1);//将P作为树的头结点，不代表AVL树中任意节点，其中的date取一个极大值，则AVL树将在P的left项中生长。
	for (int i = 0; i<MAX_node; i++)
	{
		scanf("%d", &item);
		node *temp = creat_node(item);
		insert_node(p, temp);
		keep_balance(p,temp );
	}
	printf("%d", p->left->date);
	return 0;
}


void insert_node(node * root, node * node)
{
		if (root->date > node->date)
		{
			if (root->left == NULL)
			{
				root->left = node;
				node->father = root;
			}
			else
				insert_node( root->left, node);
		}
		else if (root->date < node->date)
		{
			if (root->right == NULL)
			{
				root->right = node;
				node->father = root;
			}
			else
				insert_node(root->right, node);
		}

}

node * creat_node(int item)
{
	node * temp;
	temp = (node *)malloc(sizeof(node));
	temp->date = item;
	temp->left = NULL;
	temp->right = NULL;
	temp->father = NULL;
	return temp;
}

void keep_balance(node *head, node *new_node)
{
	gethigh(head->left);
	node *finder=NULL;
	while (new_node != head)
	{
		if (new_node->num == -2 || new_node->num == 2)
		{
			finder = new_node;
			//printf("FUCK,WHY!\n");
			break;
		}
		else
			new_node = new_node->father;
	}
	// printf(("NUM:%d %d\t"),finder->num,finder->left->num);
	if (finder != NULL){
		if (finder->num == 2 && finder->left->num == 1)  ll(finder);
		else if (finder->num == -2 && finder->right->num == 1)  rl(finder);
		else if (finder->num == -2 && finder->right->num == -1)  rr(finder);
		else if (finder->num == 2 && finder->left->num == -1)  lr(finder);
	}
}

int gethigh(node *p)
{
	int left, right;
	if (p == NULL) return 0;
	else
	{
		left = gethigh(p->left);
		right = gethigh(p->right);
	}
	p->num = left - right;
	//printf("~~~%d\t",p->num);
	if (left>right) return left + 1;
	else return right + 1;

}

void  rr(node *finder)
{
	node *old_top = finder;
	node *old_temp = finder->right->left;
	finder = old_top->right;
	finder->left = old_top;
	finder->left->right = old_temp;
	/*以下修复父节点指针*/
	finder->father = old_top->father;
	if (old_top->father->left != NULL && old_top->father->left->num == -2)
	{
		old_top->father->left = finder;
	}
	else if (old_top->father->right != NULL && old_top->father->right->num == -2)
	{
		old_top->father->right = finder;
	}
	finder->left->father = finder;
	finder->right->father = finder;
	if(finder->left->right != NULL )finder->left->right->father = finder->left;

}

void ll(node *finder)
{
	node *old_temp = finder->left->right;
	node *old_top = finder;
	finder = old_top->left;
	finder->right = old_top;
	finder->right->left = old_temp;
	/*以下修复父节点指针*/
	finder->father = old_top->father;
	if (old_top->father->left != NULL && old_top->father->left->num == 2)
	{
		old_top->father->left = finder;
	}
	else if (old_top->father->right != NULL && old_top->father->right->num == 2)
	{
		old_top->father->right = finder;
	}
	finder->left->father = finder;
	finder->right->father = finder;
	if(finder->right->left != NULL) finder->right->left->father = finder->right;

}
void lr(node *finder)
{
	node *old_top = finder;
	node *templ = finder->left->right->left;
	node *tempr = finder->left->right->right;
	finder = finder->left->right;
	finder->left = old_top->left;
	finder->right = old_top;
	finder->left->right = templ;
	finder->right->left = tempr;
	/*以下修复父节点指针*/
	finder->father = old_top->father;
	if (old_top->father->left != NULL && old_top->father->left->num == 2)
	{
		old_top->father->left = finder;
	}
	else if (old_top->father->right != NULL && old_top->father->right->num == 2)
	{
		old_top->father->right = finder;
	}
	finder->left->father = finder;
	finder->right->father = finder;
	if (finder->left->right != NULL)finder->left->right->father = finder->left;
	if (finder->right->left != NULL) finder->right->left->father = finder->right;


}

void rl(node *finder)
{
	node *old_top = finder;
	node *templ = finder->right->left->left;
	node *tempr = finder->right->left->right;
	finder = finder->right->left;
	finder->left = old_top;
	finder->right = old_top->right;
	finder->left->right = templ;
	finder->right->left = tempr;
	/*以下修复父节点指针*/
	finder->father = old_top->father;
	if (old_top->father->left != NULL && old_top->father->left->num == -2)
	{
		old_top->father->left = finder;
	}
	else if (old_top->father->right != NULL && old_top->father->right->num == -2)
	{
		old_top->father->right = finder;
	}
	finder->left->father = finder;
	finder->right->father = finder;
	if (finder->right->left != NULL) finder->right->left->father = finder->right;
	if (finder->left->right != NULL)finder->left->right->father = finder->left;

}
