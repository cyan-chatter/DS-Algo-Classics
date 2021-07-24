#include<bits/stdc++.h>
using namespace std;
//Binary Tree
class node{
 public:
 	int data;
 	node*left;
 	node*right;
	
	//Constructor
	node(int d){
		data = d;
		left = NULL;
		right = NULL; 
	}
};

struct myPair{
	int height;
	bool balance;
};

node* insertInBST(node*root, int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}
	
	if(data < root->data){
		root->left = insertInBST(root->left, data);
	}
	else{
		root->right = insertInBST(root->right, data);
	}
	return root;
}

void takeInput(node* &root){
	int data;
	cout<<"\nEnter Tree Data\n";
	while(data!=-1){
		cin>>data;
		if(data!=-1){
			root = insertInBST(root, data);	
		}
	}
}


int countNodes(node*root){
	if(root==NULL){
		return 0;
	}
	int ans = 1 + countNodes(root->left) + countNodes(root->right);
	return ans;
}

int height(node* root){
	if(root==NULL){
		return 0;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	return max(lh,rh) + 1;
} //time is more than O(n)- (best case) Skew Tree takes O(n^2) time- (worst case)


void printPreorder(node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<", ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printLevel(node*root, int level){
	if(root==NULL || level<0){
		return;
	}
	if(level==0){
		cout<<root->data<<" ";
		return;
	}
	printLevel(root->left, level-1);
	printLevel(root->right, level-1);
}

void printLevelOrder(node*root){
	int min_level = 0;
	int max_level = height(root);
	cout<<"\n";
	for(int depth = min_level; depth<=max_level; depth++){
		printLevel(root,depth);
		cout<<"\n";
	}
}
void printInorder(node*root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	cout<<root->data<<", ";
	printInorder(root->right);
}

void printPostorder(node*root){
	if(root==NULL){
		return;
	}
	printInorder(root->left);
	printInorder(root->right);
	cout<<root->data<<", ";
}

ostream& operator<< (ostream &os, node* root){
	printLevelOrder(root);
	return os;
}

istream& operator>> (istream &is, node* &root){
	takeInput(root);
	return is;
}

bool search(node* root, int data){
	if(root == NULL){
		return false;
	}
	if(root->data == data){
		return true;
	}
	if(root->data < data){
		return search(root->right, data);
	}
	return search(root->left, data);
}

myPair isBalanced(node*root){
	myPair p;
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}
	myPair leftTree = isBalanced(root->left);
	myPair rightTree = isBalanced(root->right);
	
	int diff = abs(leftTree.height - rightTree.height);
	
	if(diff<=1 && leftTree.balance && rightTree.balance){
		p.balance = true;
	}else{
		p.balance = false;
	}
	
	p.height = max(leftTree.height,rightTree.height) + 1;
	return p;
}

node* minNode(node* root){
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}

node* deleteNode(node* &root, int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data == key){
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		node* replacement = minNode(root->right);
	 	root->data = replacement->data;
		root->right = deleteNode(root->right, replacement->data);
		return root;
		 
	}
	else if(root->data > key){
		root->left = deleteNode(root->left, key);
		return root;
	}
	else{
		root->right = deleteNode(root->right, key);
		return root;
	}
}

bool isBST(node* root, int minV = INT_MIN, int maxV = INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)){
		return true;		
	}	
	return false;
}

class LinkedList{
    public: 
    node* head;
    node* tail;
};
//flatten - convert to sorted linked list -> CB Save: 23093
LinkedList flatten(node *root){
    LinkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    //leaf node
    if(root->left == NULL && root->right == NULL){
        l.head = l.tail = root;
        return l;
    }
    //left child only
    if(root->left != NULL && root->right == NULL){
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //right child only
    if(root->left == NULL && root->right!=NULL){
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    //both sides, child present
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);
    leftLL.tail->right = root;
    root->right = rightLL.head;
    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main(){
	node* root = NULL; 
	myPair bstParams;
	int key;
	cin>>root;
	cout<<root;
	cout<<"\nEnter Key to Search For: ";
	cin>>key;
	if(search(root,key)) cout<<"\nElement Present"; 
	else cout<<"\nNot Present";
	bstParams = isBalanced(root);
	cout<<"\n";
	if(bstParams.balance) cout<<"\nBalanced Tree"; else cout<<"\nUnbalanced Tree";
	cout<<"\nHeight: "<<bstParams.height<<"\n";
	
		cout<<"\nEnter the node to Delete\n";
		int key1;
		cin>>key1;
		root = deleteNode(root,key1);
		cout<<root<<"\n";
		
	if(isBST(root)){
		cout<<"\nBST\n";
	}
	else cout<<"\nNot a BST\n";

    LinkedList l = flatten(root);
    node *temp = l.head;
    while(temp!=NULL){
        cout<<temp->data<<" --> ";
        temp = temp->right;
    }

    cout<<"\n";
	
    return 0;
}
//5 3 4 2 1 8 9 7 3 -1

