#include<iostream>

using namespace std;

#define MAX_TREE_SIZE 5								//������������
typedef int ElemType;								//����Ϊ�ö�������Ԫ������
typedef struct Cnode* BinTree;						//typedef�ṹ��ָ��

typedef struct Cnode {
	ElemType data;
	BinTree lchild;	
	BinTree rchild;									//�����ӽ��
}CNode;												//����������ʽ�洢


BinTree BST_Insert(BinTree T, ElemType i)		//���������Ҫ����Ľ��Ԫ��
{
	if (T == NULL)								//�����޸ýڵ����ҵ�������λ��
	{
		T = (BinTree)malloc(sizeof(CNode));		//�����ڴ�
		T->data = i;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	if (i < T->data)							//С�ڸý���Ԫ��
	{
		T->lchild = BST_Insert(T->lchild, i);	//��������
	}
	if (i > T->data)							//���ڸý���Ԫ��
	{
		T->rchild = BST_Insert(T->rchild, i);	//��������
	}
	return T;
}

void MidOrderTraverse(CNode* root)				//�������
{
	if (root)
	{
		MidOrderTraverse(root->lchild);
		cout << root->data << " ";
		MidOrderTraverse(root->rchild);
	}
}

int GetDepth(BinTree T)							//�����
{
	if (T == NULL)
		return 0;
	else {
		int a = GetDepth(T->lchild);
		int b = GetDepth(T->rchild);			//�ݹ�
		return (a > b) ? (a + 1) : (b + 1);
	}
}

int main()
{
	int a[MAX_TREE_SIZE];						//����Ԫ�ص�����
	BinTree Root = NULL;						//�����
	cout << "����Ҫ���������" << endl;
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		cin >> a[i];							//���鸳ֵ
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		Root=BST_Insert(Root, a[i]);			//��ε��ò��뺯��
	}
	cout << "��������Ľ��Ϊ��";
	MidOrderTraverse(Root);						//�������
	cout << endl;
	cout<<"�ö�������������Ϊ��"<< GetDepth(Root)<<endl;
}
