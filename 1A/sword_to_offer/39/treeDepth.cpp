#define OK 1
#define ERROR 0

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


// basic data type
typedef char TElemType;

//node
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;	
}BiTNode, *BiTree;
// define a funtion poiter that is used as visit an element
typedef int (*visit)(TElemType e);


int vst(TElemType e)
{
	cout << e << " ";
	return OK;
}


int CreateBiTree(BiTree &T)
{
	char ch;
	cout << "input data: " << endl;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		if (!(T = (BiTNode*) malloc(sizeof(BiTNode))))
			exit(1);
		T->data = ch;
		cout << "input " << ch << "'s left child, ";
		CreateBiTree(T->lchild);
	
		cout << "input " << ch << "'s right child, ";
		CreateBiTree(T->rchild);
		
	}
	return OK;
}

int TreeDepthRecursive(BiTree pRoot)
{
	if (pRoot == NULL)
		return 0;
	int left = TreeDepthRecursive(pRoot->lchild);
	int right = TreeDepthRecursive(pRoot->rchild);

	return left > right? (left+1) : (right+1);
}
bool isBalanced(BiTree pRoot)
{
	if (pRoot == NULL)
		return true;
	int left = TreeDepthRecursive(pRoot->lchild);
	int right = TreeDepthRecursive(pRoot->rchild);
	if (fabs(left - right) > 1)
		return false;

	return isBalanced(pRoot->lchild) && isBalanced(pRoot->rchild);

}
// another isBalanced through post-order 
bool balanceHelper(BiTree pRoot, int *depth)
{
	if (pRoot == NULL)
	{
		*depth = 0;
		return true;
	}
	int left, right;
	if (balanceHelper(pRoot->lchild, &left) && balanceHelper(pRoot->rchild, &right))
	{
		if (fabs(left - right) <= 1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}
bool isBalanced2(BiTree pRoot)
{
	int depth = 0;
	return balanceHelper(pRoot, &depth);
}
int main()
{
	BiTree rootTree;
	CreateBiTree(rootTree);
	cout << TreeDepthRecursive(rootTree) << endl;
    cout << isBalanced2(rootTree) << endl;
	
	return 0;
}