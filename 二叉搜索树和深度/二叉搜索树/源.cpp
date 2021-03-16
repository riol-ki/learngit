#include<iostream>

using namespace std;

#define MAX_TREE_SIZE 5								//定义最大结点个数
typedef int ElemType;								//整形为该二叉树的元素类型
typedef struct Cnode* BinTree;						//typedef结构体指针

typedef struct Cnode {
	ElemType data;
	BinTree lchild;	
	BinTree rchild;									//左右子结点
}CNode;												//二叉树的链式存储


BinTree BST_Insert(BinTree T, ElemType i)		//传入根结点和要插入的结点元素
{
	if (T == NULL)								//发现无该节点且找到了他的位置
	{
		T = (BinTree)malloc(sizeof(CNode));		//分配内存
		T->data = i;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	if (i < T->data)							//小于该结点的元素
	{
		T->lchild = BST_Insert(T->lchild, i);	//找左子树
	}
	if (i > T->data)							//大于该结点的元素
	{
		T->rchild = BST_Insert(T->rchild, i);	//找右子树
	}
	return T;
}

void MidOrderTraverse(CNode* root)				//中序遍历
{
	if (root)
	{
		MidOrderTraverse(root->lchild);
		cout << root->data << " ";
		MidOrderTraverse(root->rchild);
	}
}

int GetDepth(BinTree T)							//求深度
{
	if (T == NULL)
		return 0;
	else {
		int a = GetDepth(T->lchild);
		int b = GetDepth(T->rchild);			//递归
		return (a > b) ? (a + 1) : (b + 1);
	}
}

int main()
{
	int a[MAX_TREE_SIZE];						//储存元素的数组
	BinTree Root = NULL;						//根结点
	cout << "输入要插入的数据" << endl;
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		cin >> a[i];							//数组赋值
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		Root=BST_Insert(Root, a[i]);			//多次调用插入函数
	}
	cout << "中序遍历的结果为：";
	MidOrderTraverse(Root);						//中序遍历
	cout << endl;
	cout<<"该二叉树的最大深度为："<< GetDepth(Root)<<endl;
}
