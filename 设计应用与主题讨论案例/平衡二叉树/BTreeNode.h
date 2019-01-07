template <class T> class BTree;//二叉树类
template <class T> class BSTree;//二叉排序树类
template <class T>
class BTreeNode
{  friend  class BTree <T>;
   friend  class BSTree <T>;
   T  data;
   int bl;
   BTreeNode<T> *lchild,*rchild;
 public:
   BTreeNode():lchild(NULL),rchild(NULL){}
   BTreeNode(T d, int b,BTreeNode<T> *l=NULL, BTreeNode<T> *r=NULL)
     :data(d),bl(b),lchild(l),rchild(r){}
   T getdata(){return data;}
   int getbl(){return bl;}
   BTreeNode<T> *getleft(){return lchild}//获取左孩子
   BTreeNode<T> *getright(){return rchild}//获取右孩子
};
