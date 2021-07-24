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
	
	void insertAtHead(node* &newnode){
		if(head == NULL){
			head = newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
	}
	void insertAtTail(node* &newnode){
		
		if(head == NULL){
			head = newnode;
			return;
		}
		if(head->next == NULL){
			head->next = newnode;
			return;
		}
		node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		
	} 
	
	void createLinkedList(int a[], int n, string insOrder = "h-t"){ 
		
		node* newnode = NULL;
		if(!strcmp(insOrder.c_str(), "h-t")){
			for(int i=0; i<n; ++i){
				newnode = newNode(a[i]);
				insertAtTail(newnode);
			}	
		return;
		}
		if(!strcmp(insOrder.c_str(), "t-h")){
			for(int i=0; i<n; ++i){
				newnode = newNode(a[i]);
				insertAtHead(newnode);
			}	
		return;
		}
		else return;
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
	
	node* midpoint(char ch = '1'){
		if(head == NULL || head->next == NULL){
			return head;
		}
		node* slow = head;
		node* fast;
		if(ch == '2'){
			fast = head;
		}
		else{
			fast = head->next;	
		}
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;	
	}	
	
	friend ostream& operator <<(ostream&, lList);
	friend node* mergeSortedLists(node* &, node* &);
	friend lList mergeTwoSortedLists(lList&, lList&);
	friend node* midPoint(node* head);	
	node* mergeSort(node* &);
	void sort();
	
};

node* midPoint(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    node*slow = head;
    node*fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
    
}

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

node* lList:: mergeSort(node* &h){
	if(h == NULL || h->next == NULL){
		return h;
	}
	node* mid = midPoint(h);
	
	node* a = h;
		
	node* b = mid->next;
		
	mid->next = NULL;
		
	a = mergeSort(a);
	b = mergeSort(b);
	node* c = mergeSortedLists(a,b);
		 
	return c;
}

void lList:: sort(){
	head = mergeSort(head);
}

int main(){
		
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10, 44};
	int n = sizeof(a)/sizeof(int);
	lList ll1;
	ll1.createLinkedList(a,n);
	cout<<ll1;
	ll1.sort();
	cout<<ll1;
	return 0;
}

