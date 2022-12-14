#include <iostream>
#include<vector>
using namespace std;

class pQueue{
public:
    vector<int> hp;
    pQueue(){
	hp.push_back(0);
    }

    void insert(int ele){
	hp.push_back(ele);
	heapify();
    }

    void delEl(){
	    if(hp.size()==1)
		cout<< "\nHeap is empty"  << endl;
	    else{
		int a=hp[hp.size()-1];
		hp.pop_back();
		hp[1]=a;
		heapify();
	    }
    }

    void heapify(){
	int temp;
	int fg1=1,fg2;
	while(fg1==1){
	    fg2=0;
	    for(int i=1;i<hp.size()-1;i++){

		if(2*i<=hp.size()-1){
		    if(hp[i]>hp[2*i]){
			temp=hp[i];
			hp[i]=hp[2*i];
			hp[2*i]=temp;
			fg2=1;
			break;
		    }
	    
		    else if(hp[i]>hp[2*i+1] && 2*i+1<=hp.size()-1 ){
			temp=hp[i];
			hp[i]=hp[2*i+1];
			hp[2*i+1]=temp;
			fg2=1;
			break;
		    }
		}
	    }
	    if(fg2==0)
		fg1=0;
	}
    }

    void display(){
	if(hp.size()==1)
	    cout<< "\n--Empty--" << endl;
	else{
	    for(int i=1;i<hp.size();i++)
		    cout<<" "<<hp[i];
	    cout<<endl;
	}
    }
};

int main(){
	pQueue pq;
	int ch=0,el;
MENU:
	cout<<"\n\t-------:MENU:--------" << endl;
	cout<< "1. Insert\t2. Delete\t3. Show\t0. Exit\n  :";
	cin >> ch;
	if(ch==1){
	    cout << "Enter Element : ";
	    cin >> el;
	    pq.insert(el);
	}
	else if(ch==2)
		pq.delEl();
	else if(ch==3)
		pq.display();
	else{
	    cout << "Exiting..." << endl;
	    return 0;
	}
	goto MENU;
return 0;
}
