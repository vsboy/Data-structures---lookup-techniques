#include<iostream>
#include"HashTable.h"
using namespace std;
void main(void)
{
HashTable myHashTable(13);
Datatype a[]={188,256,300,448,555,201,214};
int j,n=7;
Datatype item;
for(int i=0;i<n;i++)
myHashTable.Insert(a[i]);
for(int i=0;i<n;i++)
{
j=myHashTable.Find(a[i]);
item=myHashTable.GetValue(j);
cout<<"j= " <<j<<" ht[]="<<item.key<<endl;
}
int k=myHashTable.IsIn(555);
if(k>0) cout<<"数据555在哈希表中"<<endl;
else cout<<"数据555不在哈希表中"<<endl;
}
