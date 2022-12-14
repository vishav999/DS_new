#include<iostream>
using namespace std;
template<typename T>
class Stack{
private:
	
    T *arr;
    int n;
    int top;
    
public:
    
    Stack(){
	n = 10;
	arr = new T[n];
	top = -1;
    }
    Stack(int x){
	n = x;
	arr = new T[n];
	top = -1;
    }
    ~Stack(){
	delete[] arr;
    }

    bool isEmpty(){
	if (top <= -1){
	    return true;
	}
	else
	    return false;
    }

    void push(T e){
	if(top == (n-1)){
	    cout << "\nStackOverflow... mamximum limit reached..\n";
	}
	else{
	    arr[++top] = e;
	}
    }

    void pop(){
	if(isEmpty()){
	    cout << "\nStackUnderflow... no element to pop\n";
	}
	else{
	    top--;
	}
    }
    T topElement(){
	if(isEmpty()){
	    cout << "\nStack is empty... no top element\n";
	    return -1;
	}
	else{
	    return arr[top];
	}
	return arr[top];
    }

    void clear(){
	top = -1;
    }

    int size(){
	return top+1;
    }

};

template<typename T>
void displayStack(Stack<T>& S,int n){
    T *temp;
    temp = new T[n];
    for(int i=0;i<n-1;i++){
	//cout << " | " << S[i] << " |" << endl;
	if(!S.isEmpty())
	{
		temp[i] = S.topElement();
	    S.pop();
	    cout << " | " << temp[i] << " |" << endl;
	}
	
    }
    for(int i=n-1;i>=0;i--){
	S.push(temp[i]);
    }
}

int main(){

    int size,c1,c2;

    cout << "Enter size: ";
    cin >> size;

    Stack<int> S(size);
    int ele;
MENU:
    cout << "\n\t CHOOSE: \n";
    cout << "1.Push   2.Pop   3.See top element   4.See if it's empty   5.Size   6.clear   7.display   8.Exit\n:";
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
	cout << "Top element is : " << S.topElement() << endl;
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
    else if (c1==7)
    {
    	displayStack(S,size);
	}
    else{
	cout << "\nExiting..";
	return 0;
    }
	goto MENU;
    
}
