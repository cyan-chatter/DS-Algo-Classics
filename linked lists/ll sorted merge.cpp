#include<iostream>
#include<string.h>
using namespace std;
#define node struct NODE

struct NODE{
	int data;
	node* next;
};

node* newNode(int val){
	node* newnode = new node;
	newnode->data = val;
	newnode->next = NULL;
	return newnode;
}

class lList{
	node* head;
	public:	
	lList(){
		head = NULL;
	}
	
	void insertSorted(node* &newnode){
		
		node *current, *prev;
		
		if(head==NULL)
		{
			head=newnode;
			return;
		}
		
		if(head->next == NULL)
		{
			if(newnode->data>head->data){
				head->next = newnode;
				return;	
			}
			else{
				newnode->next = head;
				head = newnode;
				return;
			}
		}
		
		current=head;
		prev = NULL;
		
		if(newnode->data<head->data){
			newnode->next=head;
			head=newnode;
			return;
		}
		
		while(newnode->data>current->data && current->next!=NULL){
				prev = current;
				current=current->next;
		}
		
		if(newnode->data>current->data && current->next==NULL){
			current->next = newnode;
			return;
		}
		
		else if(newnode->data<current->data){
			prev->next=newnode;
			newnode->next=current;
			return;	
		}
		
	}
	
	void createSortedLinkedList(int a[], int n){
		node* newnode = NULL;
			for(int i=0; i<n; ++i){
				newnode = newNode(a[i]);
				insertSorted(newnode);
			}	
	}
	
	void display(){
		if(head == NULL){
			return;
		}
		cout<<"\n";
		node* temp = head;
		if(temp->next == NULL){
			cout<<temp->data<<"\n";
			return;
		}
		
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
	
	friend ostream& operator <<(ostream&, lList);
	friend node* mergeSortedLists(node* &, node* &);
	friend lList mergeTwoSortedLists(lList&, lList&);	
};

node* mergeSortedLists(node* &l1, node* &l2){
	if(l1 == NULL){
		return l2;
	}
	else if(l2 == NULL){
		return l1;
	}
	
	node* c;
	
	if(l1->data < l2->data){
		c = l1;
		c->next = mergeSortedLists(l1->next, l2);		
	}
	else{
		c = l2;
		c->next = mergeSortedLists(l1, l2->next);
	}
	
	return c;
}

lList mergeTwoSortedLists(lList& l1, lList& l2){
	node* lhead1 = l1.head;
	node* lhead2 = l2.head;
	lList lm;
	lm.head = mergeSortedLists(lhead1, lhead2);
	return lm;
}

ostream& operator <<(ostream& cout, lList L){
	L.display();
}


int main(){
		
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10, 44};
	int n = sizeof(a)/sizeof(int);
	lList ll1;
	ll1.createSortedLinkedList(a,n);
	cout<<ll1;
	int b[] = {8,16,34,25,43,88};
	int m = sizeof(b)/sizeof(int);
	lList ll2;
	ll2.createSortedLinkedList(b,m);
	cout<<ll2;
	lList llm = mergeTwoSortedLists(ll1,ll2);
	cout<<llm;
		
	return 0;
}

