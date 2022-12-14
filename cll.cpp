// Circular linked list using 1 cursor
/*
 *Write a program to implement circularly linked list which supports the following operations: 
 * (i) Insert an element x at the front of the circularly linked list ~
 * (ii) Insert an element x after an element y in the circularly linked list ~
 * (iii)Insert an element x at the back of the circularly linked list ~
 * (iv) Remove an element from the back of the circularly linked list ~
 * (v) Remove an element from the front of the circularly linked list ~
 * (vi) remove the element x from the circularly linked list ~
 * (vii)Search for an element x in the circularly linked list and return its pointer ~
 * (viii) Concatenate two circularly linked lists ~
 */

#include<iostream>
#include<stdexcept>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;
};

template<typename T>
class cll{
private:
    Node<T>* cursor;
public:
    cll(){
	cursor = NULL;
    }
    ~cll(){
	while(!isEmpty()){
	    Node<T>* temp=cursor->next;
	    if(temp==cursor)
		cursor=NULL;
	    else{
		cursor->next = temp->next;
	    }
	    delete temp;
	}
    }

    bool isEmpty(){
	return cursor==NULL;
    }

    void advance(){
	if(!isEmpty())
	    cursor = cursor->next;
    }

    Node<T> * searchEl(T el){
	Node<T> *temp = cursor->next;
	if(isEmpty()){
	    cout << "cant search, list empty" << endl;
	}
	else{
	    if(cursor->data == el)
		return cursor;
	    while(temp!=cursor){
		if(temp->data == el)
		    return temp;
		temp = temp->next;
	    }
	}
	return NULL;
    }

    T front(){		    // Front element, i.e after cursor
	//try{
	    //if(isEmpty())
		//throw "Queue is empty no front element";
	//}
	//catch(const char* ch){
	    //cout << ch << endl;
	//}
	return cursor->next->data;
    }

    T back(){			    // Back element that is cursor's data
	try{
	    if(isEmpty())
		throw "Queue is empty no front element";
	}
	catch(const char* ch){
	    cout << ch << endl;
	}
	return cursor->data;

    }

    void insertAtFront(T el){		    // Add to front (after cursor)
	Node<T> *temp = new Node<T>;
	temp->data= el;
	if(cursor==NULL){
	    temp->next = temp;
	    cursor = temp;
	}
	else{
	    temp->next = cursor->next;
	    cursor->next = temp;
	}
    }

    void removeAtFront(){		    // remove front el
	if(isEmpty()){
	    cout << "list already empty." << endl;
	}
	else{
	    Node<T> *temp = cursor->next;
	    if(temp==cursor)
		cursor = NULL;
	    else
		cursor->next = temp->next;
	    delete temp;
	}

    }

    void insertAtBack(T el){
	Node<T> *temp = new Node<T>;
	temp->data= el;
	if(cursor==NULL){
	    temp->next = temp;
	    cursor = temp;
	}
	else{
	    Node<T> *temp2 = cursor->next;
	    //while(temp2!=cursor){
		//temp2 = temp2->next;
	    //}
	    cursor->next = temp;
	    temp->next = temp2;
	    //cursor = temp;
	    advance();
	}

    }

    void removeAtBack(){
	Node<T> *temp = cursor->next;
	if(isEmpty())
	    cout << "list empty, cant remove" << endl;
	else if(cursor->next == cursor){
	    temp = cursor;
	    cursor = NULL;
	    delete temp;
	}
	else{
	    while(temp->next != cursor){
		temp = temp->next;
	    }
	    temp->next = cursor->next;
	    Node<T> *temp2 = cursor;
	    delete temp2;
	    cursor = temp;

	}
    }

    void insertAfterY(T x,T y){
	if(isEmpty()){
	    cout << "Can't insert after given element, list is empty, no element." << endl;
	}
	else{
	    Node<T> *yAdd = searchEl(y);
	    if(yAdd == NULL)
		cout << "Element not found, couldnt add" << endl;
	    else{
		Node<T> *temp = new Node<T>;
		temp->next = yAdd->next;
		temp->data = x;
		yAdd->next = temp;
	    }
	}
    }

    void removeEl(T x){
	Node<T> *temp = cursor->next;
	if(isEmpty())
	    cout << "Cant remove, list is empty" << endl;
	else if(cursor->data==x){
	    removeAtBack();
	    
	}
	else{
	    bool found = false;
	    Node<T> *temp2;
	    while(temp->next != cursor){
		if(temp->next->data==x){
		    temp2 = temp->next;
		    temp->next = temp2->next;
		    delete temp2;
		    found = true;
		    break;
		}
		temp = temp->next;
	    }
	    if(!found)
		cout << "Element not found, cant remove" << endl;
	}
    }
    void removeElAtindex(int index){
	Node<T> *temp = cursor->next;
	if(isEmpty())
	    cout << "Cant remove, list is empty" << endl;
	else if( index== 1){
	    removeAtFront();
	    
	}
	else{
	    Node<T> *temp2=temp;
	    int j=1;
	    bool found= false;
	    while(temp2->next != cursor->next && j!= index)
		{
		    temp2 = temp;
		    temp = temp->next;
		    j++;
		    cout<<j<<endl;
	    }
	    if(j==index)
		{
			cout<<temp->data;
			temp2->next=temp->next;
			if(temp!=cursor)
			delete temp;
			else
			{
				cursor= temp2;
				delete temp;
			}
		}
		else
		{
			cout<<"position not found"<<endl;
		}
	}
    }

    void clear(){
	while(!isEmpty()){
	    Node<T>* temp=cursor->next;
	    if(temp==cursor)
		cursor=NULL;
	    else{
		cursor->next = temp->next;
	    }
	    delete temp;
	}

    }

    void display(){
	if(isEmpty())
	    cout << "--empty--" << endl;
	else{
	    Node<T> *temp = cursor->next;
	    while(temp!=cursor){
		cout << temp->data << " ";
		temp = temp->next;
	    }
	    cout << temp->data << endl;
	}
    }

    /*// by reference	//bad
    void concatenate(cll<T> &l2){
	if(isEmpty())
	    cout << "first list is empty, cant concatenate" << endl;
	else if(l2.isEmpty())
	    cout << "Second list is empty, cant concatenate" << endl;
	else{
	    Node<T> *temp = cursor->next;
	    cursor->next = l2.cursor->next;
	    l2.cursor->next = temp;
	    cursor = l2.cursor;
	}

    }*/

    void concatenate(cll<T> &l2){
	if(isEmpty())
	    cout << "first list is empty, cant concatenate" << endl;
	else if(l2.isEmpty())
	    cout << "Second list is empty, cant concatenate" << endl;
	else{
	    Node<T> *temp = l2.cursor->next;
	    while(temp!=l2.cursor){
		insertAtBack(temp->data);
		temp = temp->next;
	    }
	    insertAtBack(temp->data);
	    
	}

    }

};

int main(){

    cll<int> c1,c2;
    int ch=0,num,y;
    Node<int> *ptr = NULL;
    cout << "---------------------Linked List using Cursor---------------------"<< endl;
MENU:
    cout << "\n\t\t------------------MENU------------------" << endl;
    cout << "For List 1";
    cout << "\n\t1. Insert At front\t 2. Insert At back\t 3. Insert after Y\t 4. Remove from front" << endl;
    cout << "\t5. Remove from Back\t 6. Remove X\t 7.Search for X\t 8. Concatenate" << endl;
    cout << "For List 2";
    cout << "\n\t9. Insert At front\t 10. Insert At back\t 11. Insert after Y\t 12. Remove from front" << endl;
    cout << "\t13. Remove from Back\t 14. Remove X\t 15.Search for X\t 16. Concatenate\n0. Exit\n  : ";
    cin >> ch;

    if(ch==1){
	cout << "Insert num : ";
	cin >> num;
	c1.insertAtFront(num);
    }
    else if(ch==2){
	cout << "Insert num : ";
	cin >> num;
	c1.insertAtBack(num);	
    }
    else if(ch==3){
	cout << "Insert num : ";
	cin >> num;
	cout << "Element after which we have to add : ";
	cin >> y;
	c1.insertAfterY(num,y);
    }
    else if(ch==4){
	c1.removeAtFront();
    }
    else if(ch==5){
	c1.removeAtBack();
    }
    else if(ch==6){
	cout << "Insert element to remove : ";
	cin >> num;
	c1.removeEl(num);
    }
    else if(ch==7){
	cout << "Insert num to search : ";
	cin >> num;
	ptr = c1.searchEl(num);
	if(ptr!=NULL)
	    cout << "Address : " << ptr;
    }
    else if(ch==8){
	c1.concatenate(c2);
    }
    else if(ch==9){
	cout << "Insert num : ";
	cin >> num;
	c2.insertAtFront(num);
    }
    else if(ch==10){
	cout << "Insert num : ";
	cin >> num;
	c2.insertAtBack(num);	
    }
    else if(ch==11){
	cout << "Insert num : ";
	cin >> num;
	cout << "Element after which we have to add : ";
	cin >> y;
	c2.insertAfterY(num,y);
    }
    else if(ch==12){
	c2.removeAtFront();
    }
    else if(ch==13){
	c2.removeAtBack();
    }
    else if(ch==14){
	cout << "Insert element to remove : ";
	cin >> num;
	c2.removeEl(num);
    }
    else if(ch==15){
	cout << "Insert num to search : ";
	cin >> num;
	ptr = c2.searchEl(num);
	if(ptr!=NULL)
	    cout << "Address : " << ptr;

    }
    else if(ch==16){
	c2.concatenate(c1);
    }
    else if(ch==17)
    {cout << "Insert element to remove : ";
	cin >> num;
	c1.removeElAtindex(num);	
	}
    else{
	cout << "Exiting.." << endl;
	return 0;
    }
    
    cout << "C1: ";
    c1.display();
    cout << "C2: ";
    c2.display();

    goto MENU;


    return 0;
}
