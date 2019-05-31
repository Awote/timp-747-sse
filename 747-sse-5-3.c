#include <stdio.h>
#include <stdlib.h>

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
typedef struct listBaseNode
{
	BaseNode *ptr_node_tree;
	struct listBaseNode *next;
}ListBaseNode;

typedef struct list
{
	ListBaseNode *first;
	ListBaseNode *last;
}List;
void init(Tree *tree) { 

	tree->root = NULL;
}
void createlist(List *q)
{
	q->first = NULL;
	q->last = NULL;
};

int push(List *q, BaseNode *n)
{
	ListBaseNode *newList = (ListBaseNode*)malloc(sizeof(ListBaseNode));
	newList->ptr_node_tree = n;
	newList->next = NULL;
	if (q->first)
		q->last->next = newList;
	else
		q->first = newList;
	q->last = newList;
	return 0;
}

void clearlist(List  *q)
{
	ListBaseNode *itNeedAble, *nq;
	itNeedAble = q->first;
	do
	{
		nq = itNeedAble;
		itNeedAble = itNeedAble->next;
		free(nq);
	} while (itNeedAble);
	q->first = NULL;
	q->last = NULL;
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
void print(BaseNode* node)
{
	if (node)
	{
		List list1, list2;
		List *ptrlist1 = &list1;
		List *ptrlist2 = &list2;
		createlist(ptrlist1);
		createlist(ptrlist2);
		BaseNode *itNeedAble = NULL;
		ListBaseNode*q = NULL;
		int c = 0, val = node->value, j = 0;
		BaseNode *l = node->left;
		BaseNode *r = node->right;
		push(ptrlist1, node);
		while (1)
		{
			while (ptrlist1->first)
			{
				if (ptrlist1->first)
	{
		ListBaseNode *nodelist_pop;
		itNeedAble = ptrlist1->first->ptr_node_tree;
		nodelist_pop = ptrlist1->first;
		ptrlist1->first = ptrlist1->first->next;
		if (ptrlist1->first == NULL)
			ptrlist1->last = NULL;
		free(nodelist_pop);
	}
	else
		itNeedAble = NULL;
				if (ptrlist1->first == NULL)
				{
					if (itNeedAble->value == val && c == 1)
						printf(" ");
					else
						printf("%d ", itNeedAble->value);
				}
				else if (itNeedAble->value == val && c == 1)
					printf(" ");
				else
					printf("%d ", itNeedAble->value);
				if (itNeedAble->left)
					push(ptrlist2, itNeedAble->left);
				else
					push(ptrlist2, node);
				if (itNeedAble->right)
					push(ptrlist2, itNeedAble->right);
				else
					push(ptrlist2, node);
			}
			node->left = node->right = NULL;
			c = 1;
			q = ptrlist2->first;
			while (ptrlist2->first->ptr_node_tree->value == val)
			{
				ptrlist2->first = ptrlist2->first->next;
				if (ptrlist2->first->next == NULL)
					if (ptrlist2->first->ptr_node_tree->value == val)
					{
						j = 1;
						node->left = l;
						node->right = r;
						clearlist(ptrlist2);
						break;
					}
			}
			ptrlist2->first = q;
			if (j == 1)
				break;
			ptrlist1->first = ptrlist2->first;
			ptrlist1->last = ptrlist2->last;
			ptrlist2->first = NULL;
			ptrlist2->last = NULL;
		}
	}
	else
		printf(" ");
}

void postOrderTravers(BaseNode* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->value);
    }
}
int main()
{
    Tree *tree = (Tree*)malloc(sizeof(BaseNode));
	init(tree);

	int a[7];
	scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3],&a[4],&a[5],&a[6]);
	for (int i = 0; i < 7; i++)
		insert(tree, a[i]);
postOrderTravers(tree->root);

printf("\n");	

    return 0;
}

