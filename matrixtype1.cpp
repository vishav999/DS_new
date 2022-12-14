#include <iostream>
using namespace std;
class diagonal
{
	int*arr;
	int r;
 	public:
	diagonal(int r)
	{
		this->r=r;
  		arr = new int[r];
  		for(int i=0;i<r;i++)
  		{
  			arr[i]=0;	
		}
	}
	
	int get(int i, int j)
	{
		if(i>=0 && j>=0 && i<r && j<r)
		{
			if(i==j)
			  {
			  	return arr[i];
			  }
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
	}
	
	int set(int i, int j,int x)
	{
		if(i>=0 && j>=0 && i<r && j<r)
		{
			if(i==j)
			  {
			  	arr[i]=x;
			  }
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
	}
	void display()
	{cout<<"ARRAY IS ";
	for(int i=0;i<r;i++)
	{cout<<arr[i]<<" ";
	}
	cout<<endl;
	   for(int i=0;i<r;i++)
	   { 
	      for(int j=0;j<r;j++)
	          { 
	             if(i==j)
	               {
	               	cout<<arr[i];
				   }
				else
				   {
				   	cout<<"0";
				   }
				   cout<<" ";
			  }
		 cout<<endl;
	   }
	}
};
class tridiagonal
{
	int*arr;
	int r;
	int size;
 	public:
	tridiagonal(int r)
	{
		this->r=r;
		size= r+2*(r-1);
  		arr = new int[size];
  		for(int i=0;i<size;i++)
  		{
  			arr[i]=0;	
		}
	}
	
	int get(int i, int j)
	{
		if(i>=1 && j>=1 && i<=r && j<=r)
		{
			if(i==j)
			  {
			  	return arr[r+i-2];
			  }
			else if(i==j+1)
			{ 
			  return arr[i-2];
			}
			else if(i==j-1)
			{
				return arr[2*r+i-2];
			}
			else
			{
				return -1;
			}
		}
		else
		{
	        cout<<"enter the correct values of i and j"<<endl;
	        exit(0);
		}
	}
	
	int set(int i, int j,int x)
	{
		if(i>=1 && j>=1 && i<=r && j<=r)
		 {
		   if(i==j)
			  { 
			  	arr[r+i-2]=x;
			  	
			  }
		  if(i==j+1)
			   {
			      arr[i-2]=x;
			     
			   }
		  
		  if(i==j-1)
			   {
		        arr[2*r+i-2]=x;
		
			   }
	    	}
		else
		{
	        cout<<"enter correct values of i and j"<<endl;
	        exit(0);
		}

	}
	void display()
	{
	cout<<"ARRAY IS ";
	for(int i=0;i<size;i++)
	{cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=r;i++)
	   {
	    for(int j=1;j<=r;j++)
	    { 
	        int m= get(i,j);
	       // cout<<m<<endl<<endl;
	        if(m!= -1)
	        {
	        	cout<<m;
			}
	        /*if(i==j)
			  {
			  	cout<<arr[r+i-2];
			  }
			else if(i==j+1)
			  {
			   cout<<arr[i-2];
			  }
			else if(i==j-1)
			{
			  cout<<arr[2*r+i-2];
			}
			*/
			else
			 {
			   cout<<"0";
			 }
		    cout<<" ";
	       }
		 cout<<endl;
	   }
	}
};
class lowertri
{
	int*arr;
	int r;
	int size;
 	public:
	lowertri(int r)
	{
		this->r=r;
		size= (r*(r+1))/2;
  		arr = new int[size];
  		for(int i=0;i<size;i++)
  		{
  			arr[i]=0;	
		}
	}
	
	int get(int i, int j)
	{
		if(i>=1 && j>=1 && i<=size && j<=size)
		{
			if(i>=j)
			  {
			  	return arr[((i-1)*i/2)+ (j-1)];
			  }
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
	}
	
	int set(int i, int j,int x)
	{
		if(i>=1 && j>=1 && i<=size && j<=size)
		{
			if(i>=j)
			  {
			  	arr[((i-1)*i/2)+j-1]=x;
			  }
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
	}
	void display()
	{for(int p=0;p<size;p++)
  		{
  			cout<<arr[p]<<" ";	
		}
	cout<<endl;
	for(int i=1;i<=r;i++)
	   { 
	      for(int j=1;j<=r;j++)
	          { 
	             if(i>=j)
	               {
	               	cout<<arr[((i-1)*i/2)+ (j-1)];
				   }
				else
				   {
				   	cout<<"0";
				   }
				   cout<<" ";
			  }
		 cout<<endl;
	   }
	}
};
class uppertri
{
	int*arr;
	int r;
	int size;
 	public:
	uppertri(int r)
	{
		this->r=r;
		size= (r*(r+1))/2;
  		arr = new int[size];
  		for(int i=0;i<size;i++)
  		{
  			arr[i]=0;	
		}
	}
	
	int get(int i, int j)
	{
		if(i>=1 && j>=1 && i<=r && j<=r)
		{
			if(i<=j)
			  {
			  	return arr[((i - 1) * r - (i - 2) * (i - 1) / 2) + (j - i)];
			  }
			else
			{
				return -1;
			}
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
	}
	
	int set(int i, int j,int x)
	{
		if(i>=1 && j>=1 && i<=r && j<=r)
		{
			if(i<=j)
			  {
			  	arr[((i - 1) * r - (i - 2) * (i - 1) / 2) + (j - i)]=x;
			  }
		}
		else
		{
			cout<<"enter the correct values of i and j: "<<endl;
			exit(0);
		}
   }
	void display()
	{	for(int p=0;p<size;p++)
  		{
  			cout<<arr[p]<<" ";	
		}
		cout<<endl;
	   for(int i=1;i<=r;i++)
	   { 
	      for(int j=1;j<=r;j++)
	          { 
	             int m= get(i,j);
				if(m==-1)
				   {
				   	cout<<"0";
				   }
				else
				{
					cout<<m;
				}
				   cout<<" ";
			  }
		 cout<<endl;
	   }
	}
};
int main()
{int a;
cout<<"Enter the row/column"<<endl;
int r;
cin>>r;
cout<<"****ENTER*****"<<endl;
cout<<"1. to make a diagonal matrix"<<endl;
cout<<"2. to make a tridiagonal matrix"<<endl;
cout<<"3. to make a upper triangular matrix"<<endl;	
cout<<"4. to make a lower triangular matrix"<<endl;
cout<<"Enter the value---->";
cin>>a;
switch(a)
{
	case 1:
		{int x;
		diagonal u(r);
		cout<<"enter the value"<<endl;
			for(int i=0;i<r;i++)
            {
	        for(int j=0;j<r;j++)
	         {
	         	cin>>x;
	         	u.set(i,j,x);
	          }
            }
	        u.display();
			break;	
		}
	case 2:
		{int x;
		tridiagonal u(r);
		cout<<"enter the value"<<endl;
			for(int i=1;i<=r;i++)
            {
	        for(int j=1;j<=r;j++)
	         {
	         	cin>>x;
	         	u.set(i,j,x);
	          }
            }
	        u.display();
			break;	
		}
	case 3:
		{int x;
		uppertri u(r);
		cout<<"enter the value"<<endl;
			for(int i=1;i<=r;i++)
            {
	        for(int j=1;j<=r;j++)
	         {
	         	cin>>x;
	         	u.set(i,j,x);
	          }
            }
	        u.display();
			break;	
		}
	case 4:
		{int x;
		lowertri u(r);
		cout<<"enter the value"<<endl;
			for(int i=1;i<=r;i++)
            {
	        for(int j=1;j<=r;j++)
	         {
	         	cin>>x;
	         	u.set(i,j,x);
	          }
            }
	        u.display();
			break;	
		}
	default:
		{cout<<"wrong choice"<<endl;
		}
}
return 0;
}
