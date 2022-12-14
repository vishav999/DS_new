// Make stack using linked list
// push pop topEl clear isEmpty size;
#include"sll.h"
#include<stdexcept>

using namespace std;

template<typename T>
class Stack{
private:
    list<T> l;
    int s;			// current size
    int n;			// max size
public:
    Stack(){
	s=0;
	n=10;
    }
    Stack(int max_size){
	s=0;
	n = max_size;
    }

    void push(T el){
	if(s==n)
	    cout << "\n\tStackOverFlow..." << endl;
	else{
	    l.insertAtHead(el);
	    s++;
	}
    }
    void pop(){
	if(s==0)
	    cout << "\n\tStackUnderFlow..." << endl;
	else{
	    l.removeAtHead();
	    s--;
	}
    }

    T topEl(){
	if(s==0){
	    throw "\n\tStack is empty. No top element available" ;
	}
	T el = l.removeAtHead();
	l.insertAtHead(el);
	return el;
    }

    void clear(){
	s=0;
	while(s>0){ 
	    l.removeAtHead();
	}
	//Node<T> *temp, *temp2;
	//for(temp = l.head;temp->next!=0;){
	    //temp2 = temp;
	    //temp = temp->next;
	    //delete temp2;
	//}
	//delete temp;
    }

    bool isEmpty(){
	return s==0;
    }

    int size(){
	return s;
    }

    void displayStack(){
	if(s==0)
	    cout << "Stack Empty.." << endl;
	else
	    l.display();
	//Node<T> *temp;
	//for(temp=l.head;temp!=0;temp=temp->next)
	    //cout << " " << temp->data << " |" ;
	//cout << endl;
    }
    
};

int main(){

    int ele,c1=0,m_size;
    cout << "Enter Size: ";
    cin >> m_size;
    Stack<int> S(m_size);

MENU:
    cout << "\t\t\t----------------CHOOSE:---------------- \n";
    cout << "\t\t1.Push   2.Pop   3.See top element   4.See if it's empty   5.Size   6.clear   7.Exit\nINPUT: ";
    cin >> c1;

    if(c1 == 1){
	cout << "Enter element: ";
	cin >> ele;
	S.push(ele);
    }
    else if(c1 == 2){
	S.pop();
	cout << "POPed";
    }
    else if(c1 == 3){
	try{
	    cout << "Top element is : " << S.topEl() << endl;
	}
	catch(const char* ch){
	    cout << ch << endl;
	}
    }
    else if(c1 == 4){
	if(S.isEmpty())
	    cout << "Stack is empty.." << endl;

	else
	    cout << "Stack is not empty.." << endl;
    }
    else if(c1==5)
	cout << "Current Size: " << S.size() << endl ;
    else if(c1==6){
	S.clear();
	cout << "Cleared.." << endl;
    }
    else{
	cout << "\nExiting.." << endl;
	return 0;
    }

    cout << "STACK: " ;
    S.displayStack();
    goto MENU;
    

    return 0;
}
