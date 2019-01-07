//������BiSortTree������ṹBiNode���ļ���Ϊbisorttree.h
#ifndef BISORTTREE_H
#define BISORTTREE_H

struct BiNode
{
  int data;
  BiNode *lchild, *rchild;
};

class BiSortTree    //�ٶ���¼��ֻ��һ������������
{
public:
	BiSortTree(int a[ ], int n);    //�������Ҽ���a[n]�Ķ���������
	~BiSortTree(void);        //�����������ͷŶ��������������н�㣬ͬ�����������������
	BiNode* Getroot( );       //��ȡָ�������ָ��
	BiNode* InsertBST(BiNode *root, BiNode *s);          //�ڶ����������в���һ�����s
	void DeleteBST(BiNode *p, BiNode *f );               //ɾ�����f�����ӽ��p
	BiNode* SearchBST(BiNode *root, int k, int count);   //����ֵΪk�Ľ��
private:
    BiNode *root;    //�����������������������ĸ�ָ��
    void Release(BiNode *root);   //������������
};
#endif