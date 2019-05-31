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

void init(Tree *tree) { 

	tree->root = NULL;
}

void clear(Tree *tree) { 
	while (tree->root != NULL)
		RemoveMin(tree->root, tree);
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

int RemoveMin(BaseNode *n, Tree *t) {
	t->count--;

	if (t->count != 1) {

		while (n->left != NULL)
			n = n->left;

		if (n->right != NULL) {
			n->right->parent = n->parent;

			if (n == t->root)
				t->root = n->right;
			else
				n->parent->left = n->right;
		}
		else
			n->parent->left = NULL;

		int value = n->value;
		free(n);

		return value;
	}
	else {
		t->root = NULL;
		t->count = 0;
		free(t->root);

		return 0;
	}
}

BaseNode *search(BaseNode *node, int value) { 
	if ((node == NULL) || (node->value == value))
		return node;
	if (value < node->value)
		return search(node->left, value);
	else
		return search(node->right, value);
}

BaseNode *min(BaseNode *root) { 
	BaseNode *l = root;
	while (l->left != NULL)
		l = l->left;
	return l;
}

int findBaseNode(Tree *tree, int value, BaseNode **node) { 
	BaseNode *itNeedAble, *root2;
	root2 = tree->root;
	itNeedAble = search(root2, value);
	if (itNeedAble == NULL) {
		return 1;
	}

	*node = itNeedAble;
	return 0;
}


int rotateLeft(Tree* tree) {
	BaseNode *itNeedAble = tree->root->right;

	if (itNeedAble == NULL)
		return 1;

	tree->root->right = itNeedAble->left;
	itNeedAble->left = tree->root;
	itNeedAble->parent = tree->root->parent;
	tree->root->parent = itNeedAble;
	tree->root = itNeedAble;

	return 0;
}

int rotateRight(Tree *tree) {
	BaseNode *itNeedAble = tree->root->left;

	if (itNeedAble == NULL)
		return 1;

	tree->root->left = itNeedAble->right;
	itNeedAble->right = tree->root;
	itNeedAble->parent = tree->root->parent;
	tree->root->parent = itNeedAble;
	tree->root = itNeedAble;

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
						printf("_\n");
					else
						printf("%d\n", itNeedAble->value);
				}
				else if (itNeedAble->value == val && c == 1)
					printf("_ ");
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
		printf("-\n");
}

void printTree(Tree *tree) {
	print(tree->root);
	
}

BaseNode* _Remove(BaseNode* tree, int value)
{
	BaseNode* temp;
	if (!tree) {
		return tree;
	}
	else if (value < tree->value) {
		tree->left = _Remove(tree->left, value);
	}
	else if (value > tree->value) {
		tree->right = _Remove(tree->right, value);
	}
	else {
		if (tree->left && tree->right) {
			temp = min(tree->right);
			temp->left = tree->left;
			temp = tree->right;
			free(tree);
			return temp;
		}
		else if (tree->left == tree->right) {
			free(tree);
			return NULL;
		}
		else {
			if (!tree->left) temp =tree->right;
			else temp = tree->left;
			free(tree);
			return temp;
		}
	}
	return tree;
}

int Remove(Tree *tree, int value) {
	BaseNode *itNeedAble = _Remove(tree->root, value);
	if (!itNeedAble)
		return 1;
	else {
		tree->count--;
		tree->root = itNeedAble;
		return 0;
	}
}


int main() {
	Tree *tree = (Tree*)malloc(sizeof(BaseNode));
	init(tree);

	int a[4];
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	for (int i = 0; i < 4; i++)
		insert(tree, a[i]);

	print(tree->root);

	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	for (int i = 0; i < 3; i++)
		insert(tree, a[i]);

	print(tree->root);

	int m;

	scanf("%d", &m);

	BaseNode *TreeNode = (BaseNode*)malloc(sizeof(BaseNode));

	if (findBaseNode(tree, m, &TreeNode) == 1)
		printf("-\n");
	else {
		if (TreeNode->parent == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->parent->value);

		if (TreeNode->left == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->left->value);
		if (TreeNode->right == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->right->value);
	}

	printf("\n");

	scanf("%d", &m);

	if (findBaseNode(tree, m, &TreeNode) == 1)
		printf("-\n");
	else {
		if (TreeNode->parent == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->parent->value);

		if (TreeNode->left == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->left->value);
		if (TreeNode->right == NULL)
			printf("_ ");
		else
			printf("%d ", TreeNode->right->value);
	}

	scanf("%d", &m);

	Remove(tree, m);

	print(tree->root);

	while (rotateLeft(tree) == 0);

	print(tree->root);
	while (rotateRight(tree) == 0);

	print(tree->root);

	printf("%d\n", tree->count);

	clear(tree);

	print(tree->root);

	system("pause");
	return 0;
}

