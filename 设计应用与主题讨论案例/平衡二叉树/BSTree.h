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
		BSTree(T a[],int n);//���캯��
		static void insert(T elem,BTreeNode<T> *&p);//��Ԫ��elem���뵽������������
		void insert(T elem);
		static int  dep(BTreeNode<T> *p);//�������
		int dep()
		{
			return(dep(root));
		}
		static void calbl(BTreeNode<T> *&p);//�޸Ľ���ƽ������
		static void adjust_LL(BTreeNode<T> *&p);//�Խ��pΪ����������LL��ƽ�����
		static void adjust_LR(BTreeNode<T> *&p);//�Խ��pΪ����������LR��ƽ�����
		static void adjust_RR(BTreeNode<T> *&p);//�Խ��pΪ����������RR��ƽ�����
		static void adjust_RL(BTreeNode<T> *&p);//�Խ��pΪ����������RL��ƽ�����
		static bool search(BTreeNode<T> *p,T elem,int& count);//�ڶ����������в���Ԫ��elem,count��ʾ���ҵĴ���
		bool search(T elem,int& count);
		static void prnt(BTreeNode<T> *p, int l);
		void prnt(){prnt(root,1);}
		static void layvisit(BTreeNode<T> *p,BTreeNode<T> *a[],int n);//������α�����ŵ�����
		void layvisit(BTreeNode<T> *a[],int n);
		static void Vprnt(BTreeNode<T> *p,BTreeNode<T> *a[],int n,int high);// ���������
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
			calbl(p);//�޸Ľ��p��ƽ������
			if(p->bl==2 && p->lchild->bl==1)//�ж���LL��
				adjust_LL(p);
			if(p->bl==2 && p->lchild->bl==-1)//�ж���LR��
				adjust_LR(p);
		}
	else
	{
		insert(elem,p->rchild);
		calbl(p);//�޸Ľ��p��ƽ������
		if(p->bl==-2 && p->rchild->bl==-1)//�ж���RR��
			adjust_RR(p);
		if(p->bl==-2 && p->rchild->bl==1)//�ж���RL��
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
	p=q->lchild;//�µ�����
	q->lchild=p->rchild;
	p->rchild=q;
	p->bl=0;
	q->bl=0;
}
template<class T>
void BSTree<T>::adjust_LR(BTreeNode<T> *&p)
{
	BTreeNode<T> *q,*temp;//q���������Һ��ӣ�temp������������
	q=p;
	p=q->lchild->rchild;//�µ�����
	temp=q->lchild;//ԭ������������
	q->lchild=p->rchild;
	temp->rchild=p->lchild;//
	p->rchild=q;
	p->lchild=temp;
	//����ƽ������
	calbl(p);
	calbl(q);
	calbl(temp);
}
template<class T>
void BSTree<T>::adjust_RR(BTreeNode<T> *&p)
{
	BTreeNode<T> *q;//q��������������
	q=p;
	p=q->rchild;//�µ�����
	q->rchild=p->lchild;
	p->lchild=q;
	p->bl=0;
	q->bl=0;
}
template<class T>
void BSTree<T>::adjust_RL(BTreeNode<T> *&p)
{
	BTreeNode<T> *q,*temp;//q�����������ӣ�temp���������Һ���
	q=p;
	p=q->rchild->lchild;//�µ�����
	temp=q->rchild;//ԭ������������
	q->rchild=p->lchild;
	temp->lchild=p->rchild;//
	p->lchild=q;
	p->rchild=temp;
	//����ƽ������
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
	//first��ʾÿһ����Ԫ�ص��±ꣻ
	//firstleft��ʾ��Ԫ�ؾ�����Ļ��ߵľ��룻
	//linestep��ʾÿ��Ԫ��֮��ļ��
	//high��ʾ���Ĳ�������߶�
	for(int i=1;i<=high;i++)
		//��ӡ��Ԫ��
	{	
		firstleft=(pow(2,(high-i)*1.0)-1)*2;//������Ԫ�ص���ʼλ��
		for(int j=1;j<=firstleft;j++)
			cout<<" ";
			first=pow(2,(i-1)*1.0)-1;//��Ԫ�ص��±�
			if(a[first])//��������
				cout<<setw(2)<<a[first]->getdata();
			else//������
				cout<<setw(2)<<" ";
		//��ӡͬ�е�����Ԫ��
		for(int k=pow(2,(i-1)*1.0)+1;k<=pow(2,i*1.0)-1;k++)
		{
			linestep=pow(2,(high-i)*1.0)*4;//�������Ԫ�ؼ��
			if(a[k-1])//��������
				cout<<setw(linestep)<<a[k-1]->getdata();
			else
				cout<<setw(linestep)<<" ";
		}
		//���д�ӡ��ϣ�����
		cout<<endl;
	}
}
template<class T>
void BSTree<T>::Vprnt(BTreeNode<T> *a[],int n,int high)
{
	Vprnt(root,a,n,high);
}
