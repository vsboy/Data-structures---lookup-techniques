#include"Datatype.h"
enum KindOfItem{Empty,Active,Deleted};
 //�����״̬���Ͷ���
struct HashItem 
//����ṹ�嶨��
{
Datatype data;
KindOfItem info;
HashItem(KindOfItem i=Empty):info(i){}
HashItem(const Datatype&D,KindOfItem i=Empty):data(D),info(i){}
int operator==(HashItem& a)
     {return data==a.data;}
int operator!=(HashItem& a)
     {return data!=a.data;}
};
class HashTable   //��ϣ����
  {
    private:
           HashItem*ht;   //��ϣ������
           int TableSize;   //����ĸ���
           int currentSize;   //���鵱ǰ�ı������
           void AllocateHt()   //�����ϣ������ռ�
		   {ht=new HashItem[TableSize];}
           int FindPos(const Datatype& x)const; //��λ
   public:
   //���캯������������
           HashTable(int m):TableSize(m)
		   {AllocateHt();currentSize=0;}
           ~HashTable(void)
		   {delete []ht;}
           int Find(const Datatype& x);         //����
           int Insert(const Datatype& x);       //����
           int Delete(const Datatype& x);   //ɾ��
           int IsIn(const Datatype& x)        //�Ƿ��Ѵ���
		   {int i=Find(x);return i>=0?1:0;}
           Datatype GetValue(int i)const    //ȡֵ
		   {return ht[i].data;}
           void Clear(void);                       //���
}; 

int HashTable::FindPos(const Datatype& x)const
{int i=x.key%TableSize;
int j=i;
while(ht[j].info==Active && ht[j].data!=x)
{
j=(j+1)%TableSize;
if(j==i)return-TableSize;
}
if(ht[j].info==Active) return j;
else return-j;
}
int HashTable::Find(const Datatype& x)
{
int i=FindPos(x),j=i;
if(j>=0)
{
while(ht[j].info==Active && ht[j].data!=x)
{
j=(j+1)%TableSize;
if(j==i) return -TableSize;
}
if(ht[j].info==Active)return j;
else return-j;
}
else return j;
}
int HashTable::Insert(const Datatype& x)
{
int i=FindPos(x);
if(i>0) return 0;
else if (i!=-TableSize && ht[-i].info!=Active)
{
ht[-i].data=x;
ht[-i].info=Active;
currentSize++;
return 1;
}
else return 0;
}
int HashTable::Delete(const Datatype& x)
{
int i=FindPos(x);
if(i>=0)
{
ht[i].info=Deleted;
currentSize--;
return 1;
}
else return 0;
}
void HashTable::Clear(void)
{
for(int i=0;i<TableSize;i++)
ht[i].info=Empty;
currentSize=0;
} 


