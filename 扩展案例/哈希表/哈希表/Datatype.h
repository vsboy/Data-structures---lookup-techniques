typedef int Keytype;
struct Datatype
{
        Keytype key;//���캯��
        Datatype(){}
        Datatype(Keytype item):key(item){}
        //�߼��Ƚ������
       int operator<=(const Datatype& item)
	   {return key<=item.key;}
       int operator<(const Datatype& item)
	   {return key<item.key;}
       int operator==(const Datatype& item)
	   {return key==item.key;}
       int operator>=(const Datatype& item)
	   {return key>=item.key;}
      int operator>(const Datatype& item)
	  {return key>item.key;}
      int operator!=(const Datatype& item)
	  {return key!=item.key;}
};
