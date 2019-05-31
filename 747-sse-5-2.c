#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
typedef struct BaseNode
{
	int value;
	struct BaseNode *left;
	struct BaseNode *right;
	struct BaseNode *parent;
} BaseNode;

typedef struct tree
{
	struct BaseNode *root;
	int count;
} Tree;
void init(Tree *tree) { 

	tree->root = NULL;
}
int insert(Tree *tree, int value) { 
	BaseNode *itNeedAble = (BaseNode*)malloc(sizeof(BaseNode));

	itNeedAble->value = value;


	if (tree->root == NULL) {
		itNeedAble->left = itNeedAble->right = NULL;
		itNeedAble->parent = NULL;
		tree->root = itNeedAble;
		tree->count = 1;
		return 0;
	}

	if (itNeedAble->value == tree->root->value)
		return -1;

	BaseNode *root2 = (BaseNode*)malloc(sizeof(BaseNode)), *root3 = NULL;

	root2 = tree->root;

	while (root2 != NULL)
	{
		root3 = root2;
		if (value < root2->value)
			root2 = root2->left;
		else
			root2 = root2->right;
	}

	if (itNeedAble->value == root3->value) {
		return -1;
	}

	itNeedAble->parent = root3;
	itNeedAble->left = NULL;
	itNeedAble->right = NULL;

	if (value < root3->value)
		root3->left = itNeedAble;
	else
		root3->right = itNeedAble;
	tree->count++;
	return 0;
}
void TwoTask( Tree* Root)
{
	BaseNode *f[15];
	int tmp =0;
	BaseNode *temp[15];
	int tmp_2 =0;
	BaseNode * node = Root -> root;
	while(tmp_2 <Root ->count)
	{
		while (node!= NULL)
		{
			tmp_2++;
			if(node -> right != NULL)
			{tmp++;
				f[tmp] = node->right;
			}
			temp[tmp_2] = node;
			node = node->left;
			
		}
		node = f[tmp];
		tmp = tmp -1 ;
	}
	for (int i = 1 ;i <= tmp_2;i++)
	{
		printf("%d ",temp[i]->value);
}
printf("\n");
}
int main()
{
    Tree *tree =malloc(sizeof tree);
	init(tree);

	int a[7];
	scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3],&a[4],&a[5],&a[6]);
	for (int i = 0; i < 7; i++){
		insert(tree, a[i]);}
	TwoTask(tree);
printf("\n");
	

    return 0;
}
