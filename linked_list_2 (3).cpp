#include<iostream>
using namespace std;
class llnode
{int element;
llnode *next;
friend class linkedlist;
llnode(int n=0)
	{
		element= n;
		next=NULL;	
	}
};
class linkedlist
{public:
llnode *head;
linkedlist()
	{
		head= NULL;
	}
void insertatbegin(int element)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p;
				p = new llnode(element);
				p->next= head;
				head= p;
			}
	}
void insertatend(int element)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p,*q;
				p = new llnode(element);
				q = head;
				while(q->next!=	NULL)
				{
					q=q->next;
				}
				q->next= p;
			}
	}
void insertatpos(int element,int i)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p,*q,*r;
				p = new llnode(element);
				q = head;
				int j = 1;
				if(i==1)
				{
					insertatbegin(element);
				}
				else
				{
					while(j<i && q->next != NULL)
					{
						r=q;
						q=q->next;
						j++;
					
					}
					if(i>j)
					{
						cout<<"POSITION DOES NOT EXIST"<<endl;
						insertatend(element);
					}
					else
					{    
						r->next=p;
						p->next=q;
					}
				}
			 
			}
	}
void insertbeforepos(int element,int i)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p,*q,*r;
				p = new llnode(element);
				q = head;
				int j=1;
				if(i==1||i==2)
				{
					insertatbegin(element);
				}
				else
				{
					while(j<i-1 && q->next!=NULL)
					{   
				    	r=q;
						q=q->next;
						j++;
						
					}
					if(i-1>j)
					{
						cout<<"POSITION DOES NOT EXIST"<<endl;
						insertatend(element);
					}
					else
					{
						r->next=p;
						p->next=q;	
					}
				}
			}
	}
void insertbeforele(int element,int ele)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p,*q,*r;
				p = new llnode(element);
				q = head;
				if(head->element==ele)
				{
					insertatbegin(element);
				}
				else
				{
					int j=0;
					while(q->next!=NULL && q->element!=ele)
					{  
				    	r=q;
						q=q->next;
						if(q->element==ele)
						j=1;
					}
					if(j==0)
					{
						cout<<"ELEMENT DOES NOT EXIST"<<endl;
						insertatend(element);
					}
					else
					{
						r->next=p;
						p->next=q;	
					}
				}
			 
			}
	}
void insertafterele(int element,int ele)
	{
		if(head== NULL)
			{
				head = new llnode(element);
			}
		else
			{
				llnode *p,*q;
				p = new llnode(element);
				q = head;
				int j=0;
				while(q->element!=ele && q->next!=NULL)
				{   
					q=q->next;
					if(q->element==ele)
					{
						j=1;
					}
				}
				if(j==0)
				{
					cout<<"ELEMENT DOES NOT EXIST"<<endl;
					insertatend(element);
				}
				else
				{
					p->next=q->next;
					q->next=p;	
				}
			 
			}
	}
void deleteatbegin()
	{
		if(head== NULL)
			{
				cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *p;
				p=head;
				head= head->next;
				delete p;
			}
	}
void deleteatend()
	{
		if(head== NULL)
			{
				cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *q,*r;
				q = head;
				while(q->next->next !=NULL)
				{
					q=q->next;
				}
				r=q->next ;
				q->next=NULL;
				delete r;
				
			}
	}
void deleteatpos(int i)
	{
		if(head== NULL)
			{
				cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *q,*r;
				q = head;
				int j = 1;
				if(i==1)
				{
					deleteatbegin();
				}
				else
				{
					while(j<i && q->next != NULL)
					{
						r=q;
						q=q->next;
						j++;
					
					}
					if(i>j)
					{
						cout<<"POSITION DOES NOT EXIST"<<endl;
					}
					else
					{    
						r->next=q->next;
						delete q;
					}
				}
			 
			}
	}
void deletebeforepos(int i)
	{
		if(head== NULL)
			{
				cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *q,*r;
				q = head;
				int j=1;
				if(i==1)
				{
					cout<<"NO ELEMENT BEFORE TO DELETE"<<endl;
				}
				else if(i==2)
				{
					deleteatbegin();
				}
				else
				{
					while(j<i-1 && q->next!=NULL)
					{   
				    	r=q;
						q=q->next;
						j++;
						
					}
					if(i-1>j)
					{
						cout<<"POSITION DOES NOT EXIST"<<endl;
					}
					else
					{
						r->next=q->next;
						delete q;	
					}
				}
			}
	}
void deletebeforele(int ele)
	{
		if(head== NULL)
			{
				cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *q,*r;
				q = head;
				if(head->element==ele)
				{
					cout<<"NO ELEMENT BEFORE TO DELETE"<<endl;
				}
				else if(head->next->element==ele)
				{
					deleteatbegin();		
				}
				else
				{   
				    int j=0;
					while(q->next!=NULL)
					{  
						if(q->next->element!=ele)
				    	{
							r=q;
							q=q->next;
						}
					    else
					    {
					    	j=1;
					    	break;
						}
					}
					if(j==0 && head->next->element!= ele)
					{
						cout<<"ELEMENT DOES NOT EXIST"<<endl;
					}
					else
					{
						r->next=q->next; 
						delete q;	
					}
				}
			 
			}
	}
void deleteafterele(int ele)
	{
		if(head== NULL)
			{
			    cout<<"LIST IS ALREADY EMPTY"<<endl;
			}
		else
			{
				llnode *q,*r;
				q = head;
				int j=0;
				while(r->element!=ele && q->next!=NULL)
				{   r=q;
					q=q->next;
					if(r->element==ele)
					{
						j=1;
					}
				}
				if(j==0)
				{
					cout<<"ELEMENT DOES NOT EXIST"<<endl;
				}
				else
				{
					r->next=q->next;	
					delete q;
				}
			 
			}
	}
void selectionsort()
{
	llnode*p,*q;
	p= head;
	if(head==NULL||head->next==NULL)
	{
		cout<<"EMPTY LIST"<<endl;
	}
	else
	{
		while(p->next != NULL)
		{
			q=p->next;
			while(q->next!=NULL)
			{
				if(p->element>q->element)
				{
					int temp = p->element;
					p->element=q->element;
					q->element=temp;
				}
				q=q->next;
			}
			p=p->next;
		}
	}
	
}
void reverse()
{
	if(head==NULL||head->next==NULL)
	{
		cout<<"EMPTY LINKED LIST OR LINKED LIST WITH 1 ELEMENT"<<endl;
	}
	else
	{
	llnode*p,*q,*r;
	p= head;
	q= p->next;
	p->next=NULL;
	r= q->next;
	while(q->next!=NULL)
	{
		q->next=p;
		p=q;	
		q=r;
		if(r!=NULL)
		{
		   r=r->next;
		  
		}	
	}
	q->next=p;
	head=q;
   }	
}
void merge(linkedlist l1)
{
	selectionsort();
	l1.selectionsort();
	cout<<"ENTERED LINKED LIST----->"<<endl;
	l1.display();
	cout<<"PREVIOUS LINKED LIST----->"<<endl;
	display();
	llnode *p,*q,*r;
	p=head;
	q=l1.head;
	linkedlist f;
	while(p!=NULL && q!=NULL)
	{
		if(p->element<q->element)
		{
			f.insertatend(p->element);
			p=p->next;
		}
		else
		{
		   f.insertatend(q->element);
			q=q->next;
		}
	}
	if(p==NULL)
    {
    	while(q!=NULL)
    	{
    		f.insertatend(q->element);
	   		q=q->next;
		}
    	
	}
	if(q==NULL)
    {
    	while(p!=NULL)
    	{
    		f.insertatend(p->element);
	   		p=p->next;
		}
    	
	}
	cout<<"MERGEDED LINKED LIST----->"<<endl;
	f.display();
}
void concat(linkedlist l1)
{
	llnode*p,*q;
	p= head;
	q= l1.head;
	while(p->next!= NULL)
	{
		p=p->next;
	}
	p->next=q;
	
}
void display()
    {llnode *p;
     p = head;
     while(p!=NULL)
	    {
    		cout<<p->element<<" ";
    		p = p->next;
		}
	cout<<endl;
	}
};
int main()
{int y=1;
int element,i,ele;
linkedlist m;
	do
	{   int o;
	    cout<<"*******************MENU********************"<<endl;
	    cout<<"ENTER 1 TO ADD A ELEMENT IN THE BEGINING"<<endl;
	    cout<<"ENTER 2 TO ADD A ELEMENT IN THE END"<<endl;
	    cout<<"ENTER 3 TO ADD A ELEMENT AT ANY POSITION"<<endl;
	    cout<<"ENTER 4 TO ADD A ELEMENT BEFORE ANY POSITION"<<endl;
		cout<<"ENTER 5 TO ADD A ELEMENT BEFORE ANY ELEMENT"<<endl;
		cout<<"ENTER 6 TO ADD A ELEMENT AFTER ANY ELEMENT"<<endl;
	    cout<<"ENTER 7 TO DELETE A ELEMENT IN THE BEGINING"<<endl;
		cout<<"ENTER 8 TO DELETE A ELEMENT IN THE END"<<endl;
		cout<<"ENTER 9 TO DELETE A ELEMENT AT A POSITION"<<endl;
		cout<<"ENTER 10 TO DELETE A ELEMENT BEFORE A POSITION"<<endl;
		cout<<"ENTER 11 TO DELETE A ELEMENT BEFORE ANY ELEMENT"<<endl;
		cout<<"ENTER 12 TO DELETE A ELEMENT AFTER ANY ELEMENT "<<endl;
		cout<<"ENTER 13 TO SORT THE LINKED LIST "<<endl;
		cout<<"ENTER 14 TO REVERSE THE LINKED LIST "<<endl;
		cout<<"ENTER 15 TO CONCATENATE THE LINKED LIST "<<endl;
		cout<<"ENTER 16 TO MERGE THE LINKED LIST "<<endl;
		cout<<"ENTER YOUR CHOICE ------>";
		cin>>o;
		switch(o)
		{
			case 1:
				cout<<"ENTER THE ELEMENT "<<endl;
				cin>>element;
				m.insertatbegin(element);
				m.display();
				break;
			case 2:
				cout<<"ENTER THE ELEMENT"<<endl;
				cin>>element;
				m.insertatend(element);
				m.display();
				break;
			case 3:
				cout<<"ENTER THE ELEMENT AND POSITION"<<endl;
				cin>>element;
				cin>>i;
				m.insertatpos(element,i);
				m.display();
				break;
            case 4:
				cout<<"ENTER THE ELEMENT AND POSITION"<<endl;
				cin>>element;
				cin>>i;
				m.insertbeforepos(element,i);
				m.display();
				break;  
			case 5:
				cout<<"ENTER THE ELEMENT AND ELEMENT BEFORE WHICH THE ELEMENT HAS TO BE ADDED"<<endl;
				cin>>element;
				cin>>ele;
				m.insertbeforele(element,ele);
				m.display();
				break;   
			case 6:
				cout<<"ENTER THE ELEMENT AND ELEMENT AFTER WHICH THE ELEMENT HAS TO BE ADDED"<<endl;
				cin>>element;
				cin>>ele;
				m.insertafterele(element,ele);
				m.display();
				break; 
			case 7:
				m.deleteatbegin();
				m.display();
				break; 
			case 8:
				m.deleteatend();
				m.display();
				break;  
			case 9:
				cout<<"ENTER THE POSITION AT WHICH YOU WANT TO DELETE THE ELEMENT"<<endl;
				cin>>i;
				m.deleteatpos(i);
				m.display();
				break; 
			case 10:
				cout<<"ENTER THE POSITION BEFORE WHICH YOU WANT TO DELETE THE ELEMENT"<<endl;
				cin>>i;
				m.deletebeforepos(i);
				m.display();
				break; 
			case 11:
				cout<<"ENTER THE ELEMENT BEFORE WHICH THE ELEMENT HAS TO BE DELETED"<<endl;
				cin>>ele;
				m.deletebeforele(ele);
				m.display();
				break; 
			case 12:
				cout<<"ENTER THE ELEMENT AFTER WHICH THE ELEMENT HAS TO BE DELETED"<<endl;
				cin>>ele;
				m.deleteafterele(ele);
				m.display();
				break;
			case 13:
				cout<<"SORTED LINKED LIST----->"<<endl;
				m.selectionsort();
				m.display();
				break;
			case 14:
				cout<<"REVERSED LINKED LIST----->"<<endl;
				m.reverse();
				m.display();
				break; 	
			case 15:
				{
					if(m.head!=NULL)
					{

				cout<<"ENTER ELEMENTS IN ANOTHER LINKED LIST(press 0 to stop)----->"<<endl;
				int ele;
				linkedlist l1;
				cin>>ele;
				while(ele!=0)
				{
					l1.insertatend(ele);
					cin>>ele;
				}
				cout<<"ENTERED LINKED LIST----->"<<endl;
				l1.display();
				cout<<"PREVIOUS LINKED LIST----->"<<endl;
				m.display();
				cout<<"CONCATENATED LINKED LIST----->"<<endl;
				m.concat(l1);
				m.display();
			}
				 else
				   {
				   	   cout<<"first enter elements in 1 list"<<endl;
				   }
				}
			case 16:
				{	if(m.head!=NULL)
				   {
					cout<<"ENTER ELEMENTS IN ANOTHER LINKED LIST(press 0 to stop)----->"<<endl;
					int ele;
					linkedlist l1;
					cin>>ele;
					while(ele!=0)
					{
						l1.insertatend(ele);
						cin>>ele;
					}
					m.merge(l1);
				   }
				   else
				   {
				   	   cout<<"first enter elements in 1 list"<<endl;
				   }
				   break;
				}
				
		    default:
				cout<<"WRONG CHOICE"<<endl;
		}
		cout<<"DO YOU WANT TO CONTINUE ??if yes enter 1"<<endl;
		cin>>y;
	}while(y==1);
}
