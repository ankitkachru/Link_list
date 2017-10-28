#include<iostream.h>

class cll
{
private:
 int data;
 cll *next;
public:
 cll* insert_one(int,cll*);
 cll* delete_one(int,cll*);
 void ftraverse(cll*);
 void rtraverse(cll*);
 void search(int,cll*);
 void function();
};

cll*hd;

void cll::function()
{
 cout<<“******************************************\n”;
 cout<<“program to implement a circular linked list \n”;
 cout<<“******************************************\n”;

 cll * head;
 head=NULL;

 cout<<“\n\nMENU :\n”;
 cout<<“1)insertion\n”
  <<“2forward traversal\n”
  <<“3)reverse traversal\n”
  <<“4)search\n”
  <<“5)exit\n\n”;
 cout<<“Enter your option :”;
 int opt;
 cin>>opt;
 int d;

 while(opt!=5)
 {
  switch(opt)
  {
   case 1:
   cout<<“Enter data to the node :”;
   cin>>d;
   head=insert_one(d,head);
   cout<<“inserted\n”;
   break;
   case 2:
   cout<<“The forward traversal is :\n”;
   ftraverse(head);
   break;
   case 3:
   cout<<“The reverse traversal is :\n”;
   hd=head;
   rtraverse(head);
   cout<<“NULL\n”;
   break;
   case 4:
   cout<<“Enter the element to be searched :”;
   int d;
   cin>>d;
   search(d,head);
   break;
   case 5:
   break;
   default:
   cout<<“invalid option”;
   break;
  }
  cout<<“\n\nMENU :\n”;
  cout<<“1)insertion\n”
  <<“2)forward traversal\n”
  <<“3)reverse traversal\n”
  <<“4)search\n”
  <<“5)exit\n\n”;
  cout<<“Enter your option :”;
  cin>>opt;
 }
}
cll* cll::insert_one(int d,cll* c)
{
 cll*NEW;
 NEW=new cll;
 NEW->data=d;
 NEW->next=NULL;

 if(c==NULL)
 {
  c=NEW;
  c->next=c;
 }
 else
 {
  cll*c1=c;
  while(c1->next!=c)
  c1=c1->next;
  c1->next=NEW;
  NEW->next=c;
 }
 return c;
}

void cll::ftraverse(cll* c)
{
 if(c==NULL)
 {
  cout<<“\nlist empty\n”;
  return;
 }
 else
 {
  cll *c1=c;
  cout<<c1->data<<“->”;
  c1=c1->next;
  while(c1!=c)
  {
   cout<<c1->data<<“->”;
   c1=c1->next;
  }
  cout<<“NULL\n”;
 }
}

void cll::rtraverse(cll* c)
{
 if(c->next==hd)
 {
  cout<<c->data<<“->”;
  return;
 }
 else
  rtraverse(c->next);
 cout<<c->data<<“->”;
}

void cll::search(int d,cll* c)
{
 cll*c1=c;
 if(c==NULL)
 {
  cout<<“\nlist empty\n”;
  return;
 }
 else
 {
  if(c->data == d)
  {
   cout<<“found\n”;
   return ;
  }
  while(c->next !=c1)
  {
   if(c->data==d)
   {
    cout<<“found\n”;
    return ;
   }
   c=c->next;
  }
  if(c->data ==d)
  {
   cout<<“found\n”;
   return ;
  }
  cout<<” search unsuccess ful \n”;
 }
}

void main()
{
 cll list;
 list.function();
}
