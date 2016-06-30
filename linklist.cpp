#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* link;
};

node* iatbeg(struct node *ptr, int d)
{
	 node* temp= new node();
	 temp->data=d;
	 temp->link= ptr;
	 ptr=temp;
	 cout <<"Data inserted" <<endl;
	 return ptr;
}

node* iatlast(struct node *ptr,int d)
{
	node* temp=new node();
	temp->data=d;
	temp->link=NULL;
	node* t=ptr;
	if(ptr==NULL)
	{
		ptr=temp;
	}
	else
	{
		while(t->link!=NULL)
		{    
			t=t->link;	
		}
		t->link=temp;
	}
	cout <<"Data inserted" <<endl;
	
	return ptr;
}

void insertafter(struct node* ptr,int m,int d)
{
	int flag=0;
	if(ptr==NULL)
		cout << "Sorry no node here"<<endl;
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==m)
			{
				node* temp=new node();
				temp->data=d;
				temp->link=ptr->link;
				ptr->link=temp;
				flag=1;
				break;
			}
			else
				ptr=ptr->link;
		}
		if(flag==1)
			cout<<"Data inserted successfully" <<endl;
		else
			cout <<"Not inserted bcoz node not founded" <<endl;
	}
	

}

node* delatf(struct node* ptr)
{
	if(ptr==NULL)
		cout << "No nodes present"<<endl;
	else
		{	
			ptr=ptr->link;
			cout << "deleted successfully"<<endl;
		}
	return ptr;
}

node* delatl(struct node* ptr)
{
	node* prev=ptr;
	node* next=ptr->link;
	if(ptr==NULL)
		cout << "No node to delete"<<endl;
	else if(ptr->link==NULL)
		ptr=NULL;
	else
	{
		while(next->link!=NULL)
		{
			prev=next;
			next=next->link;
		}
		prev->link=NULL;

		cout <<"deleted successfully"<<endl;
	}
	return ptr;
}

node* deldata(struct node* ptr, int d)
{
	int flag=0;
	node* prev= ptr;
	node* next=ptr->link;
	if(ptr==NULL)
		cout << "No node to delete"<<endl;
	else if(ptr->data==d)
	{
		ptr=ptr->link;
	}		
	else
	{
		while(next!=NULL)
		{
			if(next->data==d)
			{
				prev->link=next->link;
				flag=1;
				break;
			}
			prev=next;
			next=next->link;
		}
		if(flag==1)
			cout<<"Data deleted successfully" <<endl;
		else
			cout <<"Not deleted bcoz node not founded" <<endl;	
	}
	return ptr;
}

void findlength(struct node* ptr)
{
	int count=0;
	while(ptr!=NULL)
	{
		ptr=ptr->link;
		count++;
	}
	cout <<count <<endl;
}

int flrecur(struct node* ptr)
{
	if(ptr==NULL)
		return 0;
	else return (1+flrecur(ptr=ptr->link));
}

void display(struct node *ptr)
{
	cout<<endl;
	if(ptr==NULL)
		cout <<"link list empty"<<endl;
	else
	{
		while(ptr!=NULL)
		{
			cout << (ptr->data) <<endl;
			ptr=ptr->link;
		}
	}	
}

int main()
{
	
	 node* p =NULL;
	
	while(1)
	{
		cout <<endl<<"press 1 to insert node at begining"<<endl<<"press 2 to insert node at last"<< endl<<"press 3 to insert a node after specific position"<<endl<<
		"press 4 to delete node at first"<<endl<<"press 5 to delete node at last"<<endl<<"press 6 to delete a particular node"<<endl<<"press 7 to find length"<<endl<<
		"press 8 to find length recursively"<<endl<<"press 9 to display"<<endl << "press 10 to exit"<<endl<<endl;	
		int n;
		cin >> n;
		switch(n)
		{
			
			case 1: {
						cout << "insert data" <<endl;
						int d;
						cin>>d;
						p=iatbeg(p,d);
						break;
					}
			case 2: {
						cout << "insert data" <<endl;
						int d;
						cin >>d;                      
						p=iatlast(p,d);
						break;
					}		
			case 3: {
						cout << "after which to be inserted" <<endl;
						int m;
						cin >> m;
						cout <<"data to be inserted" <<endl;
						int d;
						cin >>d;
						insertafter(p,m,d);
						break;
					}		
			case 4: {
						p=delatf(p);
						break;
					}	
			case 5: {
						p=delatl(p);
						break;
					}
			case 6: {
						cout<< "node data to be deleted "<<endl;
						int d;
						cin >>d;
						p=deldata(p,d);
						break;
					}	
			case 7: {
						findlength(p);
						break;
					}
			case 8:	{
						int a=flrecur(p);
						cout << a <<endl;
						break;
					}										
			case 9: {
						display(p);
						break;
					}
							
		}

		if(n==10)
			break;


	}

	delete(p);
	
	
}