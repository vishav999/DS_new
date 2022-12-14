#include <iostream>
using namespace std;
template <class T>
class Myqueue
{
	T*q;//array that holds the queue
	int f,r,n,N;//variables for front,rear,no. of elements,capacity
	public:
	Myqueue(int capacity)
	{
		N=capacity;
		q= new T[N];
		f=r=n=0;
	}
	int size()
	{
		return n;
	}
	bool empty()
	{
		return (n==0);
	}
	void enqueue(int ele)
    {
    	if(n==N)
    	{
    		cout<<"QUEUE IS FULL"<<endl;
		}
		else
		{
			q[r]=ele;
			if(r==N-1)
			{
				r=0;
			}
			else
			{
				r++;
			
			}
			n++;
		}
	}
	void dequeue()
	{
		if(empty())
		{
			cout<<"LIST IS EMPTY"<<endl;
		}
		else
		{
			f=f+1;
			n--;
		}
	}
	void display()
	{
		int c=0;
		int o=f;
		while(c!=n)
		{
			if(o==N-1)
			{

			    cout<<q[o]<<endl;
			    o=0;
			}
			else
			{
               cout<<q[o]<<endl;
			   o++;
			}
		c++;	
		}
		}
};
int main()
{int cont=1,N,o,ele,n;
cout<<"ENTER THE CAPACITY OF QUEUE"<<endl;
cin>>N;
Myqueue<int>d(N);
  do
	{

		cout<<"*******************MENU********************"<<endl;
	    cout<<"ENTER 1 TO ADD A ELEMENT IN THE QUEUE"<<endl;
	    cout<<"ENTER 2 TO REMOVE A ELEMENT IN THE QUEUE"<<endl;
	    cout<<"ENTER 3 TO CHECK THE LENGTH OF THE QUEUE"<<endl;
	    cout<<"ENTER 4 TO CHECK IF THE QUEUE IS EMPTY"<<endl;
	    cout<<"ENTER 5 TO DISPLAY THE QUEUE"<<endl;
	    cout<<"ENTER YOUR CHOICE----->"<<endl;
	    cin>>o;
		switch(o)
		{
			case 1:
				cout<<"ENTER THE ELEMENT"<<endl;
				cin>>ele;
				d.enqueue(ele);
				break;
			case 2:
				d.dequeue();
				break;
			case 3:
                n=d.size();
				cout<<"NO. OF ELEMENTS IN QUEUE------>"<<n<<endl;
				break;
			case 4:
				if(d.empty())
				{
					cout<<"QUEUE IS EMPTY"<<endl;
				}
				else
				{
					cout<<"QUEUE IS NOT EMPTY"<<endl;
				}
				break;
			case 5:
				d.display();
				break;
			default:
				cout<<"WRONG CHOICE"<<endl;
				break;
	    }
		cout<<"DO YOU WANT TO CONTINUE IF YES ENTER 0"<<endl;
		cin>>cont;
	}while(cont!=0);
	return 0;
}
