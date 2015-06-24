#define OK 1
#define ERROR 0

#include <iostream>
#include <stdlib.h>
#include <stack>

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

// creat a bi-tree through pre-order
int CreateBiTree(BiTree &T);

// pre-order-traverse
int PreOrderTraverseRecursive(BiTree T, visit traverse);
int PreOrderTraverseLoop(BiTree T, visit traverse);

// in-order-traverse
int InOrderTraverseRecursive(BiTree T, visit traverse);
int InOrderTraverseLoop(BiTree T, visit traverse);

// post-order-traverse
int PostOrderTraverseRecursive(BiTree T, visit traverse);
int PostOrderTraverseLoop(BiTree T, visit traverse);

// level-order-traverse
int LevelOrderTraverse(BiTree T, visit traverse);


int main()
{
	BiTree T;
	CreateBiTree(T);
	cout << " pre-order traverse" << endl;
	PreOrderTraverseRecursive(T, vst);
	cout << endl;
	PreOrderTraverseLoop(T, vst);
	cout << endl;
	cout << " in-order traverse" << endl;
	InOrderTraverseRecursive(T, vst);
	cout << endl;
	InOrderTraverseLoop(T, vst);
	cout << endl;
	cout << " post-order traverse" << endl;
	PostOrderTraverseRecursive(T, vst);
	cout << endl;
	PostOrderTraverseLoop(T, vst);
	cout << endl;
	cout << "All done..." << endl;
	return 0;
}



//*************************************************************************//

// implementation to functions

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


// pre-order-traverse
int PreOrderTraverseRecursive(BiTree T, visit traverse)
{
	if (T)
	{
		if (traverse(T->data))
			if (PreOrderTraverseRecursive(T->lchild, traverse))
				if(PreOrderTraverseRecursive(T->rchild, traverse))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int PreOrderTraverseLoop(BiTree T, visit traverse)
{
	stack<BiTree> sak;
	BiTree p = T;
	while (p || !sak.empty())
	{
		if (p)
		{
			sak.push(p);
			traverse(p->data);
			p = p->lchild;
		}
		else
		{
			p = sak.top();
			sak.pop();
			p = p->rchild;
		}
	}///end for while
}

// in-order-traverse
int InOrderTraverseRecursive(BiTree T, visit traverse)
{
	if (T)
	{

		if (InOrderTraverseRecursive(T->lchild, traverse))
			if (traverse(T->data))
				if (InOrderTraverseRecursive(T->rchild, traverse))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int InOrderTraverseLoop(BiTree T, visit traverse)
{
	stack<BiTree> sak;
	BiTree p = T;
	while (p || !sak.empty())
	{
		if (p)
		{
			sak.push(p);
			p = p->lchild;
		}
		else
		{
			p = sak.top();
			if (!traverse(p->data))
				return ERROR;
			sak.pop(); // 
			p = p->rchild;
		}
	}//end while
}

// post-order-traverse
int PostOrderTraverseRecursive(BiTree T, visit traverse)
{
	if (T)
	{
		if (PostOrderTraverseRecursive(T->lchild, traverse))
			if (PostOrderTraverseRecursive(T->rchild, traverse))
				if(traverse(T->data))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
int PostOrderTraverseLoop(BiTree T, visit traverse)
{
	stack<BiTree> sak;
	BiTree p = T;
	char f[1000]; // 标志当前访问节点是从左子树还是右子树返回的
	int i = 0;
	while (p || !sak.empty())
	{
		if (p)
		{
			sak.push(p);
			f[i++] = 0;  //当前根节点入栈  
			p = p->lchild;			
		}
		else
		{
			p = sak.top();			
            if(f[i-1])                //若标志栈栈顶为1，说明从右子树返回  
            {  
                traverse(p->data);    
                i--;   
                sak.pop();
                p = NULL;   
            }  
            else  
            {  
                f[i-1] = 1;           //从左树返回，栈顶标志元素置1  
                p = p->rchild;  
            } 
		}
	}///end for while
}
