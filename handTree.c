//使用栈当作辅助数据结构操作二叉树，要利用好s.pop的值
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode
{
	char Data;
	Tree lchild;
	Tree rchild;
};
Tree Create()
{
	Tree T;
	char data;
	scanf("%c", &data);
	if (data == '#')
		T = NULL;
	else
	{
		T = (Tree)malloc(sizeof(struct TreeNode));
		T->Data = data;
		T->lchild = Create();
		T->rchild = Create();
	}
	return T;
}
void PreOrder(Tree T)
{
	Tree S[100];
	int top = 0;
	while (T || top != 0)
	{
		if (T)
			printf("%c ", T->Data);
		if (T)
		{
			top += 1;
			S[top] = T;
			T = T->lchild; //直到左子树为空
		}
		else
		{
			T = S[top];
			top = top - 1;
			T = T->rchild;
		}
	}
}

void InOrder(Tree T)
{
	Tree S[100], P = T;
	int top = 0;
	while (P || top != 0)
	{
		if (P)
		{
			S[top++] = P;
			P = P->lchild; //直到左子树为空
		}
		else
		{
			P = S[--top];
			printf("%c ", P->Data); //print(P->data)
			P = P->rchild;
		}
	}
}

void AfterOrder(Tree T) /*如果该节点访问过了，可以直接输出，或者该节点的左子树和有子树都访问过了，也可以直接输出，
	 				使用标志位flag 来确定左节点是否访问*/
{
	Tree S[100], pre; //K为当前节点，pre为当前节点的前驱节点，或者为NULL
	int flag = 0;
	int top = -1;
	while (T || top != 0)
	{
		if (T)
		{
			S[++top] = T;
			T = T->lchild; //push(p)
			flag = 1;	  //左子树已经访问
		}
		else
		{
			pre = NULL;
			while (flag == 1) //左节点已经访问过了
			{
				T = S[top];
				if (T->rchild == pre || T->rchild == NULL) //如果右节点也访问过了，或者没有右节点
				{
					top--; //s.pop()
					printf("%c", T->Data);
					pre = T; //pre指向当前节点（当前节点成为下一个节点的前驱节点）
				}
				else //，如果当前节点存在右节点，将当前节点的右节点入栈
				{
					T = T->rchild;
					flag = 0; //表明左节点还没处理
				}
			}
		}
	}
}

int main()
{
	char ch, y;
	Tree T;
	printf("please input Tree\n");
	T = Create();
	printf("please  Select operation\n");
	scanf("%c", &y);
	scanf("%c", &ch);
	switch (ch)
	{
	case 'a':
		PreOrder(T);
		break;
	case 'b':
		InOrder(T);
		break;
	case 'c':
		AfterOrder(T);
		break;
	default:
		break;
	}
	return 0;
}
