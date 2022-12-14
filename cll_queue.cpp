// implement queue using circular linked list expression
// - removed max size

#include"cll.h"
#include<stdexcept>

using namespace std;

template<typename T>
class queue{
private:
   cll<T> q;
   int s;	    // current size
public:
   queue(){
	s=0;
   }
   int size(){
       return s;
   }
   T frontEl(){
       if(s==0)
	   throw "ERROR: Queue empty. Cant return!" ;
       return q.front();
   }
   bool isEmpty(){
       return s==0;
   }
   
   void enqueue(T el){
	   q.addFront(el);
	   q.advance();
	   s++;
   }

   void dequeue(){
       if(s==0){
       cout << "ERROR: Queue empty. Cant remove!";
       }
       else{
	   q.removeFront();
	   s--;
       }
   }

   void display(){
       if(s==0)
	   cout << "--Empty--" << endl;
       else{
	   cout << endl;
	   for(int i=0;i<s;i++)
	       cout << "-----";
	   cout << endl;
	   for(int i=0;i<s;i++){
	       cout << q.front() << " | " ;
	       q.advance();
	   }
	   cout << endl;
	   for(int i=0;i<s;i++)
	       cout << "-----";
	   cout << endl;
       }
   }

   void clear(){
       q.clear();
       s=0;
   }

};

int main(){

    int c,num;
    cout << "---------------Queue using Circular linked list---------------" << endl;

    queue<int> q;
MENU:
    cout << "\n\t\t\t---------------CHOICE:--------------- " << endl;
    cout << "\t1. Enqueue\t2. Dequeue\t3. FrontEl\t4.isEmpty\t5. Clear\t6. Size\n\t0. any other to exit \n :";
    cin >> c;

    if(c==1){
	cout << "Enter number to input : ";
	cin >> num;
	q.enqueue(num);
    }
    else if(c==2){
	q.dequeue();
    }
    else if(c==3){
	try{
	    cout << "Front element : " << q.frontEl() << endl;
	}
	catch(const char* ch){
	    cout << ch << endl;
	}

    }
    else if(c==4){
	num = q.isEmpty();
	if(num){
	    cout << "Queue is empty.. "<< endl;
	}
	else
	    cout << "Queue is NOT Empty.. " << endl;
    }
    else if(c==5){
	q.clear();
	cout << "Cleared.. " << endl;
    }
    else if(c==6){
	cout << "Size: " << q.size() << endl;
    }
    else{
	cout << "\n\tExiting.." << endl;
	return 0;
    }
    
    q.display();
    goto MENU;

    return 0;
}
