/*
 *Write a program to implement Binary Search Tree which supports the following operations: 
 * -(i) Insert an element x 
 * -(ii) Delete an element x 
 * -(iii) Search for an element x in the BST and change its value to y and then place the node with value y at its appropriate position in the BST 
 * -(iv) Display the elements of the BST in preorder, inorder, and postorder traversal  (Both Recursive and iterative implementations )
 * -(v) Display the elements of the BST in level-by-level traversal 
 * -(vi) Display the height of the BST
 */

#include<iostream>
#include"headers/queue.h"
#include"headers/stack.h"

using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(){
	left = NULL;
	right = NULL;
    }
    //Node(T el){
	//data = el;
	//left = NULL;
	//right = NULL;
    //}
    Node(T e,Node<T> *l=NULL,Node<T> *r=NULL){
	data = e;
	left = l;
	right = r;
    }
};

template<typename T>
class bst{
public:
    Node<T>* root;
    bst(){
	root = NULL;
    }
    void insert(T el){
	Node<T> *temp = root,*prev=NULL;
	Node<T> *newNode = new Node<T>(el);
	while(temp!=NULL){
	    prev = temp;
	    if(el<temp->data)
		temp = temp->left;
	    else
		temp = temp->right;
	}
	if(root==NULL){
	    root = newNode;
	}
	else if(el<prev->data)
	    prev->left = newNode;
	else
	    prev->right = newNode;
    }
    Node<T> * search(T el){
	Node<T> * temp = root;
	while(temp!=NULL){
	    if(temp->data==el)
		return temp;
	    else if(temp->data>el)
		temp = temp->left;
	    else
		temp = temp->right;
	}
	return NULL;
    }

    void deleteEl(T el){
				// s = the node to be searched and deleted, prev is previous node to s.
	Node<T> * s = root;
	Node<T> *prev = NULL;
	// Find node and previous node.
	while(s!=NULL){
	    if(s->data==el)
		break;	
	    prev = s;
	    if(s->data>el)
		s = s->left;
	    else
		s = s->right;
	}
	//if not found return
	if(s==NULL)
	    return;
	
	// temp node pointer
	Node<T> * temp = s;

	if(s->right==NULL)	    // if node to be removed has no right child, it has to be replaced with it's left child
	    temp = s->left;
	else if(s->left==NULL)	    // if node to be removed has no left child, it has to be replaced with it's right child
	    temp = s->right;
	else{

	    temp = s->left;		// move to left node of node to be removed
	    while(temp->right != NULL)	// traverse to right-most node
		temp = temp->right;	
	    temp->right = s->right;	// Add left node of node to be removed to right of (right-most node of left child.)
	    temp = s->left;		// assign temp to be node to be connected to it's prev node, that is left of 's'
	}

	// Assign prev's left or right to appropiate node.
	if(s==root){
	    root = temp;
	}
	else if(prev->left==s)
	    prev->left = temp;
	else if(prev->right==s)
	    prev->right = temp;
	else{
	    cout << "\nCode has some problem" << endl;
	}

	delete s;			// delete node
    }

    void searchAndChange(T el,T el2){

	// search node, change its value and remove it from tree (Not delete.)
					// s = the node to be searched and deleted, prev is previous node to s.
	Node<T> * s = root;
	Node<T> *prev = NULL;
	// Find node and previous node.
	while(s!=NULL){
	    if(s->data==el)
		break;	
	    prev = s;
	    if(s->data>el)
		s = s->left;
	    else
		s = s->right;
	}
	//if not found return
	if(s==NULL)
	    return;
	
	// temp node pointer
	Node<T> * temp = s;

	if(s->right==NULL)	    // if node to be removed has no right child, it has to be replaced with it's left child
	    temp = s->left;
	else if(s->left==NULL)	    // if node to be removed has no left child, it has to be replaced with it's right child
	    temp = s->right;
	else{

	    temp = s->left;		// move to left node of node to be removed
	    while(temp->right != NULL)	// traverse to right-most node
		temp = temp->right;	
	    temp->right = s->right;	// Add left node of node to be removed to right of (right-most node of left child.)
	    temp = s->left;		// assign temp to be node to be connected to it's prev node, that is left of 's'
	}

	// Assign prev's left or right to appropiate node.
	if(s==root){
	    root = temp;
	}
	else if(prev->left==s)
	    prev->left = temp;
	else if(prev->right==s)
	    prev->right = temp;
	else{
	    cout << "\nCode has some problem" << endl;
	}

	// change it's value
	s->data = el2;
	s->left = NULL;
	s->right = NULL;
	temp = root;
	prev = NULL;

	// search it's new position and insert
	while(temp!=NULL){
	    prev = temp;
	    if(el2<temp->data)
		temp = temp->left;
	    else
		temp = temp->right;
	}
	if(root==NULL){
	    root = s;
	}
	else if(el2<prev->data)
	    prev->left = s;
	else
	    prev->right = s;




    }

    void breadthFirst(){
	queue<Node<T> *> q;
	Node<T> *temp = root;
	if(root!=NULL){
	   q.enqueue(temp);
	   while(!q.isEmpty()){
	       temp = q.frontEl();
	       q.dequeue();
	       visit(temp);
	       if(temp->left!=NULL)
		   q.enqueue(temp->left);
	       if(temp->right!=NULL)
		   q.enqueue(temp->right);
	   }

	}
    }

    void visit(Node<T>* node){
	cout << node->data << " ";
    }



    int height(Node<T> *temp){
	if(temp==NULL)
	    return -1;
	else{
	    int lHeight = height(temp->left);
	    int rHeight = height(temp->right);

	    return lHeight>rHeight ? lHeight+1 : rHeight+1;
	}
    }

    int height(){		// so that i dont have to use root reference while useage in main
	return height(root);
    }

    void inorder(Node<T> *temp){
	if(root==NULL)
	    cout << "---Empty Tree---" << endl;
	else if(temp==NULL){
	    //Do nothing
	}
	else{
	    if(temp!=NULL){
		inorder(temp->left);
		visit(temp);
		inorder(temp->right);
	    }
	}
    }

    void iterInorder(){		
	Stack<Node<T> *> s;
	Node<T> *temp=root;

	while(temp!=NULL){
	    while(temp!=NULL){
		if(temp->right!=NULL){
		    s.push(temp->right);
		}
		s.push(temp);
		temp = temp->left;
	    }
	    temp = s.topEl();
	    s.pop();
	    while(!s.isEmpty() && temp->right==NULL){
		visit(temp);
		temp = s.topEl();
		s.pop();
	    }
	    visit(temp);
	    if(!s.isEmpty()){
		temp = s.topEl();
		s.pop();
	    }
	    else
		temp = NULL;
	}

    }

    void preorder(Node<T> *temp){
	if(root==NULL)
	    cout << "---Empty Tree---" << endl;
	else if(temp==NULL){
	    //Do nothing
	}
	else{
	    if(temp!=NULL){
		visit(temp);
		preorder(temp->left);
		preorder(temp->right);
	    }
	}

    }
    int countLeftNodes()
	 {
    return countLeftnodes(root);
     }
    int countLeftnodes(Node <T> *temp) {
    int count = 0;
    if (temp->left != NULL) 
        count += 1 + countLeftnodes(temp->left);    

    if (temp->right != NULL)
        count += countLeftnodes(temp->right);


    return count;
 }
    void iterPreorder(){
	Stack<Node<T> *> s;
	Node<T> *temp=root;

	if(temp!=NULL){
	    s.push(temp);
	    while(!s.isEmpty()){
		temp = s.topEl();
		visit(temp);
		s.pop();
		if(temp->right!=NULL)
		    s.push(temp->right);
		if(temp->left!=NULL)
		    s.push(temp->left);
	    }

	}

    }

    void postorder(Node<T> *temp){
	if(root==NULL)
	    cout << "---Empty Tree---" << endl;
	else if(temp==NULL){
	    //Do nothing
	}
	else{
	    if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		visit(temp);
	    }
	}

    }

    void iterPostorder(){
	Stack<Node<T> *> s;
	Node<T> *temp=root;
	while(temp!=NULL || !s.isEmpty()){
	    if(temp!=NULL){
		s.push(temp);
		temp = temp->left;
	    }
	    else{
		Node<T> *next = s.topEl()->right;
		if(next==NULL){
		    next = s.topEl();
		    visit(next);
		    s.pop();
		    while(!s.isEmpty() && next==s.topEl()->right){
			next = s.topEl();
			visit(next);
			s.pop();

		    }
		}
		else
		    temp = next;
	    }
	}
    }

};

int main(){
    bst<int> A;
    Node<int> n;

    int el,el2,c,h;
MENU:
    cout << "---------------------MENU---------------------\n1.Insert\t2.Delete\t3.Change Value\t4.Level-by-level display\t5.Height\t6.PreOrder (recursive)" << endl;
    cout << "7.PreOrder (iterative)\t8.InOrder (recursive)\t9.InOrder (iterative)\t10.PostOrder (recursive)\t11.PostOrder (iterative)" << endl;
    cout << "0. Exit\n\tInput : ";
    cin >> c;
    cout << "---------------------xxxxx---------------------" << endl;
    switch(c){
	case 1:
	    cout << "Enter element: ";
	    cin >> el;
	    A.insert(el);
	    break;
	case 2:
	    cout << "Enter element: ";
	    cin >> el;
	    A.deleteEl(el);
	    break;
	case 3:
	    cout << "Enter element to change: ";
	    cin >> el;
	    cout << "Enter new element : ";
	    cin >> el2;
	    A.searchAndChange(el,el2);
	    break;
	case 4:
	    cout << "Breadth First Search: " << endl;
	    A.breadthFirst();
	    cout << endl;
	    break;
	case 5:
	    cout << "Height " << A.height() << endl;
	    break;
	case 6:
	    cout << "Pre-Order recursive: " << endl;
	    A.preorder(A.root);
	    cout << endl;
	    break;
	case 7:
	    cout << "Pre-Order iterative: " << endl;
	    A.iterPreorder();
	    cout << endl;
	    break;
	case 8:
	    cout << "In-Order recursive: " << endl;
	    A.inorder(A.root);
	    cout << endl;
	    break;
	case 9:
	    cout << "In-Order iterative: " << endl;
	    A.iterInorder();
	    cout << endl;
	    break;
	case 10:
	    cout << "Post-Order recursive: " << endl;
	    A.postorder(A.root);
	    cout << endl;
	    break;
	case 11:
	    cout << "Post-Order iterative: " << endl;
	    A.iterPostorder();
	    cout << endl;
	    break;
	case 12:
	    h=A.countLeftNodes();
	    cout<<h<<endl;
		break;
	default :
	    cout << "\n\tExiting..." << endl;
	    return 0;
    }

    goto MENU;

    return 0;
}
