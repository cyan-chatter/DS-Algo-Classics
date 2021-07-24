#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


node* buildBTPreOrder(){
	int data;
	cin>>data;
	node *root = NULL;
	
	if(data == -1){
		return NULL;	
	}
	
	//preorder tree build
	root = new node(data);
	root->left = buildBTPreOrder();
	root->right = buildBTPreOrder();
	
	return root;
}

//input:  3 4 -1 6 -1 -1 5 1 -1 -1 -1 

void printPreOrder(node* root){
	if(root==NULL){
		return;
	}
	//preorder print
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int heightTree(node* root){
	if(root == NULL){
		return 0;
	}
	int height = 1 + max(heightTree(root->left), heightTree(root->right));
	return height;	
}

void printKthLevel(node* root, int k){
	if(root == NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
	}
	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
	return;
}

void printLevelOrder(node* root){
	if(root == NULL){
		return;
	}
	int height = heightTree(root);
	for(int k=1; k<=height; ++k){
		printKthLevel(root, k);
		cout<<"\n";
	}
} // skew tree - worst case - O(n^2)

//level order traversal using BFS
void bfsPrint(node* root){
	
	if(root == NULL){
		return;
	}
	
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		node* f = q.front();
		
		if(f==NULL){
			cout<<"\n";
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		
		else{
			cout<<f->data<<" ";
			q.pop();
			if(f->left){
				q.push(f->left);
			}
			if(f->right){
				q.push(f->right);
			}	
		}
		
	}
}

int countNodes(node* root){
	if(root == NULL){
		return 0;
	}
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(node* root){
	if(root==NULL){
		return 0;
	}
	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int diameterTree(node* root){ //O(n^2)
	if(root == NULL){
		return 0;
	}
	int h1 = heightTree(root->left); // O(n)
	int h2 = heightTree(root->right); // O(n)
	
	int op1 = h1 + h2;
	int op2 = diameterTree(root->left);
	int op3 = diameterTree(root->right);
	
	return max( op1, max(op2, op3) );
}

 
 class hdPair{
 	public:
 		int height;
 		int diameter;
 };
 
hdPair fastDiameterTree(node* root){
	hdPair p;
	if(root == NULL){
		p.diameter = p.height = 0;
		return p;
	}
	hdPair left = fastDiameterTree(root->left);
	hdPair right = fastDiameterTree(root->right);
	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
	return p;
}//post order, bottom up optimization, finds both height and diameter at a particular level 
//CB Save: 22738

class snPair{
	public:
		int sumChild;
		int nodeValue;
};

snPair preserveSumNodes(node* root){
	snPair s;
	if(root==NULL){
		s.nodeValue = s.sumChild = 0;
		return s;
	}
	snPair left = preserveSumNodes(root->left);
	snPair right = preserveSumNodes(root->right);
	s.sumChild = left.sumChild + right.sumChild + left.nodeValue + right.nodeValue;
	s.nodeValue = root->data;
	return s;
}

int replaceSumNodes(node* &root){
	if(root==NULL){
		return 0;
	}
	int left = replaceSumNodes(root->left);
	int right = replaceSumNodes(root->right);
	int sumChild = left + right;
	int nodeValue = root->data;
	root->data = sumChild;
	return sumChild + nodeValue;
}

int replaceSumPreserveLeafNodes(node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	int left = replaceSumPreserveLeafNodes(root->left);
	int right = replaceSumPreserveLeafNodes(root->right);
	int sumChild = left + right;
	int nodeValue = root->data;
	root->data = sumChild;
	return sumChild + nodeValue;
}

class hbPair{
	public:
		int height;
		bool balance;
};

// O(n)
hbPair isHeightBalanced(node* root){
	hbPair b;
	if(root==NULL){
		b.balance = true;
		b.height = 0;
		return b;
	}
	hbPair left = isHeightBalanced(root->left);
	hbPair right = isHeightBalanced(root->right);
	b.height = 1 + max(left.height, right.height);
	b.balance = ( (abs(left.height - right.height) <= 1) && left.balance && right.balance);
	return b;
}

node* buildTreeFromArray(int *a, int s, int e){
	if(s>e){
		return NULL;
	} //base case
	
	int mid = (s + e)/2;
	
	node* root = new node(a[mid]);
	root->left = buildTreeFromArray(a,s,mid-1);
	root->right = buildTreeFromArray(a,mid+1,e);
	
	return root;
} 

node* buildTreeFromPrePLUSInOrder(int* pre, int* in, int s, int e){
	
	static int preIndex = 0;
 	int mid = -1;
	
	if(s>e){
		return NULL;
	} 
	 
	for(int i=s; i<=e; ++i){
		if(pre[preIndex] == in[i]){
			mid = i;
			break;
		}
	}
	++preIndex;
	
	node *root = new node(in[mid]);	
	root->left = buildTreeFromPrePLUSInOrder(pre, in, s, mid-1);
	root->right = buildTreeFromPrePLUSInOrder(pre, in, mid+1, e);
	return root;	
}//22790
 
int main(){
	
	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);
	int pre[] = {4,3,2,1,5,6,7};
	int in[] = {1,2,3,4,5,6,7};
	int num = sizeof(pre)/sizeof(int);
	node* builtFromComboPre = buildTreeFromPrePLUSInOrder(pre,in,0,num-1);
	node* newnode = buildTreeFromArray(a,0,n-1);
	node* root = buildBTPreOrder();
	printPreOrder(root);	
	cout<<"\n"<<heightTree(root)<<"\n";
	printLevelOrder(root);
	cout<<"\n";
	bfsPrint(root);
	cout<<"\n";
	cout<<countNodes(root);
	cout<<"\n";
	cout<<sumNodes(root);
	cout<<"\n";
	cout<<diameterTree(root);
	cout<<"\n";
	hdPair hdp = fastDiameterTree(root);
	cout<<hdp.diameter;
	cout<<"\nWoo:\n";
	snPair snp = preserveSumNodes(root);
	cout<<snp.sumChild<<" "<<snp.nodeValue<<" "<<(snp.nodeValue + snp.sumChild);
	cout<<"\n";
	//node *replacement1 = root;
	//node *replacement2 = root;
	//replaceSumNodes(replacement1);
	//bfsPrint(replacement1);
	//cout<<"\n";
	//replaceSumPreserveLeafNodes(replacement2);
	//bfsPrint(replacement2);
	//cout<<"\n";
	hbPair hbp = isHeightBalanced(root);
	if(hbp.balance) cout<<"\nBalanced";
	else cout<<"\nNot Balanced";
	cout<<"\n";
	bfsPrint(newnode);
	cout<<"\n";
	bfsPrint(builtFromComboPre);
	
	return 0;
}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 14 13 -1 -1 -1 -1
// CB Save: 22276


//Height Balanced Tree
//Binary Tree
//|h1-h2| <= 1 : at every Node
