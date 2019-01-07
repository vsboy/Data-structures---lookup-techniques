#include"BTreeNode.h"
template<class T>
class BSTree
{
	private:
		T *a;
		int n;
		BTreeNode<T> *build();
	protected:
		BTreeNode<T> *root;
	public:
		BSTree(T a[],int n);//构造函数
		static void insert(T elem,BTreeNode<T> *&p);//将元素elem加入到二叉排序树中
		void insert(T elem);
		static int  dep(BTreeNode<T> *p);//树的深度
		int dep()
		{
			return(dep(root));
		}
		static void calbl(BTreeNode<T> *&p);//修改结点的平衡因子
		static void adjust_LL(BTreeNode<T> *&p);//对结点p为根的树进行LL型平衡调整
		static void adjust_LR(BTreeNode<T> *&p);//对结点p为根的树进行LR型平衡调整
		static void adjust_RR(BTreeNode<T> *&p);//对结点p为根的树进行RR型平衡调整
		static void adjust_RL(BTreeNode<T> *&p);//对结点p为根的树进行RL型平衡调整
		static bool search(BTreeNode<T> *p,T elem,int& count);//在二叉排序树中查找元素elem,count表示查找的次数
		bool search(T elem,int& count);
		static void prnt(BTreeNode<T> *p, int l);
		void prnt(){prnt(root,1);}
		static void layvisit(BTreeNode<T> *p,BTreeNode<T> *a[],int n);//将树层次遍历存放到数组
		void layvisit(BTreeNode<T> *a[],int n);
		static void Vprnt(BTreeNode<T> *p,BTreeNode<T> *a[],int n,int high);// 横向输出树
		void Vprnt(BTreeNode<T> *a[],int n,int high);
};
template<class T>
BSTree<T>::BSTree(T a[],int n)
{
	this->a=a;
	this->n=n;
	root=build();
}
template<class T>
BTreeNode<T> *BSTree<T>::build()
{
	BTreeNode<T> *p=NULL;
	for(int i=0;i<n;i++)
	{
		insert(a[i],p);
	}
	return (p);
}
template<class T>
void BSTree<T>::insert(T elem,BTreeNode<T> *&p)
{
	if(p==NULL)
		p=new BTreeNode<T>(elem,0);
	else if(p->data>=elem)
		{
			insert(elem,p->lchild);
			calbl(p);//修改结点p的平衡因子
			if(p->bl==2 && p->lchild->bl==1)//判断是LL型
				adjust_LL(p);
			if(p->bl==2 && p->lchild->bl==-1)//判断是LR型
				adjust_LR(p);
		}
	else
	{
		insert(elem,p->rchild);
		calbl(p);//修改结点p的平衡因子
		if(p->bl==-2 && p->rchild->bl==-1)//判断是RR型
			adjust_RR(p);
		if(p->bl==-2 && p->rchild->bl==1)//判断是RL型
			adjust_RL(p);
	}
}
template<class T>
void BSTree<T>::insert(T elem)
{
	insert(elem,root);
}
template <class T>
int BSTree<T>::dep(BTreeNode<T> *p)
{ 
  int max;
  if(p==NULL)return(0);
  else {
		max=dep(p->lchild);
        if (dep(p->rchild)>max) max=dep(p->rchild);
        return(max+1);
       }
}
template<class T>
void BSTree<T>::calbl(BTreeNode<T> *&p)
{
	if(p)
	{
		int lefth,righth;
		lefth=dep(p->lchild);
		righth=dep(p->rchild);
		p->bl=lefth-righth;
	}
}
template<class T>
void BSTree<T>::adjust_LL(BTreeNode<T> *&p)
{
	BTreeNode<T> *q;
	q=p;
	p=q->lchild;//新的树根
	q->lchild=p->rchild;
	p->rchild=q;
	p->bl=0;
	q->bl=0;
}
template<class T>
void BSTree<T>::adjust_LR(BTreeNode<T> *&p)
{
	BTreeNode<T> *q,*temp;//q是新树的右孩子，temp是新树的左孩子
	q=p;
	p=q->lchild->rchild;//新的树根
	temp=q->lchild;//原来树的左子树
	q->lchild=p->rchild;
	temp->rchild=p->lchild;//
	p->rchild=q;
	p->lchild=temp;
	//调整平衡因子
	calbl(p);
	calbl(q);
	calbl(temp);
}
template<class T>
void BSTree<T>::adjust_RR(BTreeNode<T> *&p)
{
	BTreeNode<T> *q;//q是新树的左子树
	q=p;
	p=q->rchild;//新的树根
	q->rchild=p->lchild;
	p->lchild=q;
	p->bl=0;
	q->bl=0;
}
template<class T>
void BSTree<T>::adjust_RL(BTreeNode<T> *&p)
{
	BTreeNode<T> *q,*temp;//q是新树的左孩子，temp是新树的右孩子
	q=p;
	p=q->rchild->lchild;//新的树根
	temp=q->rchild;//原来树的左子树
	q->rchild=p->lchild;
	temp->lchild=p->rchild;//
	p->lchild=q;
	p->rchild=temp;
	//调整平衡因子
	calbl(p);
	calbl(q);
	calbl(temp);
}
template<class T>
bool BSTree<T>::search(BTreeNode<T> *p,T elem,int& count)
{
	if(p==NULL)
		return(false);
	else if(p->data==elem)
	{
		count++;
		return(true);
	}
	else if(p->data>elem)
	{	
		count++;
		return(search(p->lchild,elem,count));
	}
	else
	{
		count++;
		return(search(p->rchild,elem,count));
	}
}
template<class T>
bool BSTree<T>::search(T elem,int& count)
{
	return(search(root,elem,count));
}
template <class T>
void BSTree<T>::prnt(BTreeNode<T> *p, int l)
{ if (p!=NULL )
  { prnt(p->rchild,l+1);
    for (int i=0;i<6*(l-1);i++)cout<<" ";
    cout<<"..."<<p->data<<endl;
    prnt(p->lchild,l+1);
  }
}
template<class T>
void BSTree<T>::layvisit(BTreeNode<T> *p,BTreeNode<T> *a[],int n)
{
	int front,rear;
	BTreeNode<T> *q;
	front=rear=0;
	if(p)
	{
		a[rear]=p;
		rear++;
		while(rear<n)
		{
			q=a[front];
			if(q)
			{
				a[rear++]=q->lchild;
				a[rear++]=q->rchild;
				front++;
			}
			else
			{
				a[rear++]=NULL;
				a[rear++]=NULL;
				front++;
			}
		}
	}
}
template<class T>
void BSTree<T>::layvisit(BTreeNode<T> *a[],int n)
{
	layvisit(root,a,n);
}
template<class T>
void BSTree<T>::Vprnt(BTreeNode<T> *p,BTreeNode<T> *a[],int n,int high)
{
	int first,firstleft,linestep;
	//first表示每一行首元素的下标；
	//firstleft表示首元素距离屏幕左边的距离；
	//linestep表示每行元素之间的间隔
	//high表示树的层次数即高度
	for(int i=1;i<=high;i++)
		//打印首元素
	{	
		firstleft=(pow(2,(high-i)*1.0)-1)*2;//计算首元素的起始位置
		for(int j=1;j<=firstleft;j++)
			cout<<" ";
			first=pow(2,(i-1)*1.0)-1;//首元素的下标
			if(a[first])//若结点存在
				cout<<setw(2)<<a[first]->getdata();
			else//不存在
				cout<<setw(2)<<" ";
		//打印同行的其它元素
		for(int k=pow(2,(i-1)*1.0)+1;k<=pow(2,i*1.0)-1;k++)
		{
			linestep=pow(2,(high-i)*1.0)*4;//计算该行元素间隔
			if(a[k-1])//若结点存在
				cout<<setw(linestep)<<a[k-1]->getdata();
			else
				cout<<setw(linestep)<<" ";
		}
		//本行打印完毕，换行
		cout<<endl;
	}
}
template<class T>
void BSTree<T>::Vprnt(BTreeNode<T> *a[],int n,int high)
{
	Vprnt(root,a,n,high);
}
