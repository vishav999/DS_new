// Doubly Linked List
//Write a program to implement doubly linked list which supports the following operations: 
// (i) Insert an element x at the beginning of the doubly linked list ~
// (ii) Insert an element x at position in the doubly linked list ~
// (iii)Insert an element x at the end of the doubly linked list ~
// (iv) Remove an element from the beginning of the doubly linked list ~
// (v) Remove an element from position in the doubly linked list. ~
// (vi) Remove an element from the end of the doubly linked list ~
// (vii) Search for an element x in the doubly linked list and return its pointer ~ 
// (viii) Concatenate two doubly linked lists

#include<iostream>

using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;
    Node(){
	next = NULL;
	prev = NULL;
    }
    Node(T x,Node* nPtr,Node* pPtr){
	data = x;
	next = nPtr;
	prev = pPtr;
    }
};

template<typename T>
class list
{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    list(){
	head = new Node<T>();
	tail = new Node<T>();
	head->next = tail;
	tail->prev = head;
    }

    ~list(){
	Node<T> *p;
	while(!isEmpty()){
	    p = head->next;
	    delete head;
	    head = p;
	}
    }

    bool isEmpty(){
	return head->next == tail;
    }

    int size(){
	Node<T> *temp = head->next;
	int s = 0;
	while(temp!=tail){
	    temp = temp->next;
	    s++;
	}
	return s;
    }

    void insertAtHead(T el){
	Node<T> *temp = new Node<T>(el,head->next,head);
	temp->next->prev = temp;
	head->next = temp;
	//cout << "temp = " << temp << "\nhead = " << head << "\ntail = " << tail;
	//cout << "\nhead->next = " << head->next << "\ntail->prev = " << tail->prev << endl;
    }

    void insertAtPosition(T el,int pos){
	Node<T> *temp = head->next;
	int p = 1;
	if(pos == 1){
	    insertAtHead(el);
	}
	else if(pos<1){
	    cout << "Cant add position cant be less than 1.." << endl;
	}
	else if(pos>size()){
	    cout << "Cant add, position cant be greater than size (" << size() << ")." << endl;
	}
	else{
	    while(p<pos){
		temp = temp->next;	
		p++;
	    }
	    
	    temp->prev->next = new Node<T>(el,temp,temp->prev);
	}
    }

    void insertAtTail(T el){
	Node<T> *temp = new Node<T>(el,tail,tail->prev);
	temp->prev->next = temp;
	tail->prev = temp;
	//cout << "temp = " << temp << "\nhead = " << head << "\ntail = " << tail;
	//cout << "\nhead->next = " << head->next << "\ntail->prev = " << tail->prev << endl;
    }

    void removeAtHead(){
	if(isEmpty()){
	    cout << "cant remove. List is empty" << endl;
	}
	else{
	    Node<T> *temp = head->next;
	    head->next = temp->next;
	    temp->next->prev = head;
	    delete temp;
	}
    }

    void removeAtPosition(int pos){
	Node<T> *temp = head->next;
	int p = 1;
	if(isEmpty()){
	    cout << "Cant remove, list empty." << endl;
	}
	else if(pos==1){
	    removeAtHead();
	}
	else if(pos<1){
	    cout << "Cant remove, position cant be less than 1" << endl;
	}
	else if(pos>size()){
	    cout << "Cant remove. Position cant be greater than size (" << size() << ")." <<endl;
	}
	else{
	    Node<T> *temp = head->next;
	    while(p<pos){
		temp = temp->next;
		p++;
	    }
	    temp->prev->next = temp->next;
	    temp->next->prev = temp->prev;
	    delete temp;
	}
    }

    void removeAtTail(){
	if(isEmpty()){
	    cout << "Cant remove, list is empty." << endl;
	}
	else{
	    Node<T> *temp = tail->prev;
	    temp->prev->next = tail;
	    tail->prev = temp->prev;
	    delete temp;
	}
    }

    Node<T> * searchEl(T el){
	Node<T> *temp = head->next;
	if(isEmpty()){
	    cout << "cant search, list empty" << endl;
	}
	else{
	    while(temp != tail){
		if(temp->data==el)
		    return temp;
		temp = temp->next;
	    }
	}
	return NULL;
    }

   // by reference	//bad 
    /*void concatenate(list<T> &l2){
	if(isEmpty())
	    cout << "first list is empty, cant concatenate" << endl;
	else if(l2.isEmpty())
	    cout << "Second list is empty, cant concatenate" << endl;
	else{
	    tail->prev->next = l2.head->next;
	    l2.head->next->prev = tail->prev;
	    tail = l2.tail;
	}

    }*/

    // By value		// good
    void concatenate(list<T> &l2){
	if(isEmpty())
	    cout << "first list is empty, cant concatenate" << endl;
	else if(l2.isEmpty())
	    cout << "Second list is empty, cant concatenate" << endl;
	else{
	    Node<T> *temp = l2.head->next;
	    while(temp!=l2.tail){
		insertAtTail(temp->data);
		temp = temp->next;
	    }
	}

    }

    void display(){
	Node<int> *temp = head->next;
	if(isEmpty())
	    cout << "--Empty--" << endl;
	else{
	    while(temp != tail){
		cout << temp->data << " ";
		temp = temp->next;
	    }
	}
	cout << endl;
    }

    
    
};


int main(){

    list<int> l1,l2;
    int c,num,pos;
    Node<int> *ptr=NULL;

    cout << "---------------------Doubly Linked List---------------------"<< endl;
MENU:
    cout << "\n\t\t------------------MENU------------------" << endl;
    cout << "For List 1";
    cout << "\n\t1. Insert at front\t 2. Insert at back\t 3. Insert at position\t 4. Search element";
    cout << "\n\t5. remove at front\t 6. Remove at back\t 7. Remove at position\t 8. Concatenate";
    cout << "\nFor List 2";
    cout << "\n\t9. Insert at front\t 10. Insert at back\t 11. Insert at position\t 12. Search element";
    cout << "\n\t13. remove at front\t 14. Remove at back\t 15. Remove at position\t 16. Concatenate\n\t0. Exit\n  : ";
    cin >> c;
    if(c==1){
	cout << "Insert num : ";
	cin >> num;
	l1.insertAtHead(num);
    }
    else if(c==2){
	cout << "Insert num : ";
	cin >> num;
	l1.insertAtTail(num);
    }
    else if(c==3){
	cout << "Insert num : ";
	cin >> num;
	cout << "Insert position : ";
	cin >> pos;
    	l1.insertAtPosition(num,pos);
    }
    else if(c==4){
	cout << "Insert num : ";
	cin >> num;
	ptr = l1.searchEl(num);
	if(ptr!=NULL)
	    cout << "Address of element : " << ptr;
    }
    else if(c==5){
	l1.removeAtHead();
    }
    else if(c==6){
	l1.removeAtTail();
    }
    else if(c==7){
	cout << "Enter position : ";
	cin >> pos;
	l1.removeAtPosition(pos);
    }
    else if(c==8){
	l1.concatenate(l2);
    }
    else if(c==9){
	cout << "Insert num : ";
	cin >> num;
	l2.insertAtHead(num);
    }
    else if(c==10){
	cout << "Insert num : ";
	cin >> num;
	l2.insertAtTail(num);
    }
    else if(c==11){
	cout << "Insert num : ";
	cin >> num;
	cout << "Insert position : ";
	cin >> pos;
	l2.insertAtPosition(num,pos);
    }
    else if(c==12){
	cout << "Insert num : ";
	cin >> num;
	ptr = l2.searchEl(num);
	if(ptr!=NULL)
	    cout << "Address of element : " << ptr;
    }
    else if(c==13){
	l2.removeAtHead();
    }
    else if(c==14){
	l2.removeAtTail();
    }
    else if(c==15){
	cout << "Enter position : ";
	cin >> pos;
	l2.removeAtPosition(pos);
    }
    else if(c==16){
	l2.concatenate(l1);
    }
    else{
	cout << "Exiting.." << endl;
	return 0;
    }

    cout << "List 1: ";
    l1.display();
    cout << "List 2: ";
    l2.display();

    goto MENU;

    return 0;
}
