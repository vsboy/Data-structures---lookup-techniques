//定义类BiSortTree中的成员函数，文件名为bisorttree.cpp
#include<iostream>
#include"bisorttree.h"
using namespace std;

/*
 *前置条件：二叉排序树不存在
 *输    入：数组a[n]
 *功    能：构造一棵数据值为a[n]的二叉排序树
 *输    出：无
 *后置条件：产生一棵二叉排序树
 */
BiSortTree::BiSortTree(int a[ ], int n)//构造函数
{	
	root = NULL;
    for (int i = 0; i < n; i++)
	{
        BiNode* s = new BiNode;
		s->data = a[i];
		s->lchild = NULL;
		s->rchild = NULL;
        root = InsertBST(root, s);
	}	
}
/*
 *前置条件：二叉排序树已经存在
 *输    入：无
 *功    能：释放二叉排序树中所有结点
 *输    出：无
 *后置条件：二叉排序树不存在
 */
BiSortTree::~BiSortTree(void)
{ 
    Release(root);	
}

/*
 *前置条件：二叉排序树已经存在
 *输    入：无
 *功    能：获取指向根结点的指针
 *输    出：指向根结点的指针
 *后置条件：二叉排序树不变
 */
BiNode* BiSortTree::Getroot( )
{
	return root;
}
/*
 *前置条件：空的二叉排序树
 *输    入：指向根结点的指针和指向新建结点的指针
 *功    能：将新建结点插入到二叉排序树中
 *输    出：指向根结点的指针
 *后置条件：产生一棵新的二叉排序树
 */

BiNode* BiSortTree::InsertBST(BiNode *root, BiNode *s)
{
   if(root==NULL) return s;
   else{	
	    if(s->data<root->data) root->lchild = InsertBST(root->lchild, s);//插入到左子树中
        else  root->rchild = InsertBST(root->rchild, s);                 //插入到右子树中
		return root;
   }	
}

/*
 *前置条件：二叉排序树已经存在
 *输    入：指向结点f的指针和空指针p
 *功    能：将结点f的左孩子结点p删除
 *输    出：无
 *后置条件：产生一棵新的二叉排序树
 */
void BiSortTree::DeleteBST(BiNode *p, BiNode *f ) 
{
	p = f->lchild;
	BiNode *par;
	BiNode *s;
    if(!p->lchild && !p->rchild){ //p为叶子	  
        f->lchild = NULL;  
        delete p;
	}
    else{ 
		if (!p->rchild){         //p只有左子树		    
            f->lchild = p->lchild;
            delete p;
		}
        else{ 
			if (!p->lchild){     //p只有右子树			  
                f->lchild = p->rchild;
                delete p;
			}
            else{                //左右子树均不空			   
                 par = p;  
				 s = p->rchild;  
                 while (s->lchild!=NULL)   //查找最左下结点
				 {
                     par = s;
                     s = s->lchild;
				 }
                 p->data = s->data;
                 if (par==p)  par->rchild = s->rchild;  //处理特殊情况
                 else par->lchild = s->rchild;          //一般情况
                 delete s;
			}       //左右子树均不空的情况处理完毕
		}
	}
}
/*
 *前置条件：二叉排序树已经存在
 *输    入：指向根结点的指针和查询的数据k
 *功    能：查找数据值为k的结点
 *输    出：指向数据值为k的结点
 *后置条件：二叉排序树不变
 */
BiNode* BiSortTree::SearchBST(BiNode *root, int k, int count)
{
    if(root==NULL){   	
		cout<<"此结点不存在!"<<endl; 
		cout<<"比较次数为"<<count<<endl;
		return NULL;
	}
    else{ 
		if (root->data==k){ //查找成功，返回		
			count++;
			cout<<"查找"<<root->data<<"成功!"<<endl;
            cout<<"比较次数为"<<count<<endl;
			return root;
		}
        else{ 
			if (k < root->data){ 			
				count++;
				return SearchBST(root->lchild, k,count);  //查找左子树
			}
            else{
				count++;
				return SearchBST(root->rchild, k,count);  //查找右子树
			}
		}
	}
}
/*
 *前置条件：二叉排序树已经存在
 *输    入：无
 *功    能：释放二叉排序树的存储空间，析构函数调用
 *输    出：无
 *后置条件：二叉排序树不存在
 */
void BiSortTree::Release(BiNode* root)
{
  if (root != NULL){                  
	  Release(root->lchild);   //释放左子树
      Release(root->rchild);   //释放右子树
      delete root;
  }  
}