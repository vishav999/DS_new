/*
 *Write a program to implement AVL Tree
 *
 *Please ensure to implement the way it is given in 6.7.2 Adam Drozdek (Ref 1)
 */

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

class AVL
{

public:

    int height(Node *N){
	if (N == NULL)
	    return 0;
	return N->height;
    }

    int max(int a, int b){
	if(a>b)
	    return a;
	return b;
    }

    Node *minNode(Node *node){
	Node *current = node;
	while(current->left!=NULL)
	    current=current->left;
	return current;
    }

    Node* newNode(int data){
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
    }

    int getBalance(Node *n){
	if (n == NULL)
	    return 0;
	return height(n->left) - height(n->right);
    }

    Node *rRotate(Node *y){
	Node *x = y->left;
	Node *temp = x->right;

	x->right = y;  
	y->left = temp;

	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
    }

    Node *lRotate(Node *x){
	Node *y = x->right;
	Node *temp = y->left;

	y->left = x;
	x->right = temp;

	x->height = max(height(x->left),  height(x->right)) + 1;
	y->height = max(height(y->left),   height(y->right)) + 1;

	return y;
    }

    void preOrder(Node *root){
	if(root != NULL){
	    cout << root->data << " ";
	    preOrder(root->left);
	    preOrder(root->right);
	}
    }

    void inOrder(Node *root){
	if(root){
	    inOrder(root->left);
	    cout<<root->data<<" ";
	    inOrder(root->right);
	}

    }

    void postorderdisplay(Node *root){
	if(root){
	    postorderdisplay(root->left);
	    postorderdisplay(root->right);
	    cout<<root->data<<" ";
	}
    }

    Node* insert(Node* node, int data){
	if (node == NULL)
	    return(newNode(data));

	if (data < node->data)
	    node->left = insert(node->left, data);
	else if (data > node->data)
	    node->right = insert(node->right, data);
	else 
	    return node;
	node->height = 1 + max(height(node->left),
			    height(node->right));
	int balance = getBalance(node);
	if (balance > 1 && data < node->left->data)
	    return rRotate(node);
	if (balance < -1 && data > node->right->data)
	    return lRotate(node);
	if (balance > 1 && data > node->left->data){
	    node->left = lRotate(node->left);
	    return rRotate(node);
	}
	if (balance < -1 && data < node->right->data){
	    node->right = rRotate(node->right);
	    return lRotate(node);
	}
	return node;
    }

    Node* deleteNode(Node* root,int data){

	if(root==NULL)
	    return root;
	if(data<root->data)
	    root->left=deleteNode(root->left,data);
	else if (data>root->data)
	    root->right=deleteNode(root->right,data);
	else{
	    if((root->left==NULL)||(root->right==NULL)){
		Node *temp=root->left?root->left:root->right;

		if(temp==NULL){
		    temp=root;
		    root=NULL;
		}
		else
		    *root =*temp;

		delete temp;

	    }
	    else{
		Node* temp= minNode(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	    }

	}

	if(root==NULL)
	    return root;
	root->height=1+max(height(root->left),height(root->right));
    }
};

int main()
{
    Node *root = NULL;

    AVL a;
    int c;

    int num;
MENU:
    cout<<"\t------------ MENU ------------ "<<endl;
    cout<<"1. Insert Element\t2. Delete Element\t3. In-Order Traversal\t4. Post-Order Traversal\n5. Pre-Order Traversal\t0. Exit\n : ";
    cin>>c;
    if(c==1){
	cout<<"Enter element : ";
	cin>>num;
	root = a.insert(root, num);
    }
    else if(c==2){
        cout<<"Enter element : ";
        cin>>num;
        root=a.deleteNode(root,num);
    }
     else if(c==3){
        cout<<"in-order : ";
         a.inOrder(root);
	 cout << endl;
    }
     else if(c==4){
        cout<<"post-order : ";
        a.postorderdisplay(root);
	cout << endl;
    }
    else if(c==5){
        cout<<"pre-order : ";
         a.preOrder(root);
	 cout << endl;
    }
    else{
	cout << "Exiting..." << endl;
	return 0;
    }

    goto MENU;
    
    return 0;
}

