//Postfix evaluation with stack

#include<iostream>
#include<string>

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
	    cout << "\n\tStackOverflow...\n";
	}
	else{
	    arr[++top] = e;
	}
    }

    void pop(){
	if(isEmpty()){
	    cout << "\n\tStackUnderflow...\n";
	}
	else{
	    top--;
	}
    }
    T topElement(){
	if(isEmpty()){
	    cout << "\n\tStack empty: no top element\n";
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
    for(int i=0;i<n;i++){
	//cout << " | " << S[i] << " |" << endl;
	temp[i] = S.topElement();
	S.pop();
	cout << " | " << temp[i] << " |" << endl;
    }
    for(int i=n-1;i>=0;i--){
	S.push(temp[i]);
    }
}

int evalPostfix(string str,int n){

    Stack<int> S(n);
 
    for (int i = 0; str[i]; i++)
    {
        if(str[i] == ' ')
	    continue;
         
        else if (str[i] >= '0' && str[i]<='9')
        {
            int num=0;
             
            while(str[i] >= '0' && str[i]<='9')
            {
            num = num * 10 + (int)(str[i] - '0');
                i++;
            }
            i--;
             
	    S.push(num);
        }
         
        else
        {
            int val1 = S.topElement();
	    S.pop();
            int val2 = S.topElement();
	    S.pop();
             
            switch (str[i])
            {
		    case '+': S.push((val2 + val1)); break;
		    case '-': S.push((val2 - val1)); break;
		    case '*': S.push((val2 * val1)); break;
		    case '/': S.push((val2 / val1)); break;
		    case '%': S.push((val2 % val1)); break;
		    case '^': S.push((val2 ^ val1)); break;
		    case '&': S.push((val2 & val1)); break;
             
            }
        }
    }
    return S.topElement();
}

int main(){

    //string str = "4 15 9 + *";
    //int len = str.size();
    //cout << "Result of " << str << " is : " << evalPostfix(str,len) << endl;

    string s;
    cout << "Enter Expression: ";
    getline(cin,s);
    int len=0;
    len = s.size();
    cout << "Result of '" << s << "' is :- " << evalPostfix(s,len) << endl;

}
