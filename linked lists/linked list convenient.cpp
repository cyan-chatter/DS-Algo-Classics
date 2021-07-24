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
		}// brings temp to last node
		temp->next = newnode;
		
	} 
	void insertAfter(node* &newnode, int prevnodeData){
		
		if(head == NULL){
			return;	
		}	
		node* temp = head;
		while(temp != NULL){
			if(temp->data == prevnodeData){
				newnode->next = temp->next;
				temp->next = newnode;
				return;
			}
			temp = temp->next;
		}
		if(temp == NULL){
			return;
		}
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
	
	void createLinkedList(int a[], int n, string insOrder = "h-t"){ //string: t-h : insertion at head, h-t: insertion at tail (default) 
		
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
		
		// custom insertions from array can be made this way
	
		else return;
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
	
	void deleteAtHead(){
		if(head == NULL){
			return;
		}
		node* deleteThis = head;
		head = head->next;
		delete deleteThis;
	}
	
	void deleteAtTail(){
		if(head == NULL){
			return;
		}
		if(head->next == NULL){
			node *deleteThis = head;
			head = NULL;
			delete deleteThis;
			return;
		}
		if(head->next->next == NULL){
			node *deleteThis = head->next;
			head->next = NULL;	
			delete deleteThis;
			return;
		}
		node* temp = head;
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		node *deleteThis = temp->next;
		temp->next = NULL;
		delete deleteThis;
	}
	
	void deleteKey(int key){
		if(head == NULL){
			return;
		}
		if(head->data == key){
			node* deleteThis = head;
			
			if(head->next == NULL){
				head = NULL;
				delete deleteThis;
				return;
			}
			
			head = head->next;
			delete deleteThis;
			return;	
		}
		node* temp = head;
		while(temp->next != NULL){
			if(temp->next->data == key){
				if(temp->next->next == NULL){
					temp->next = NULL;
					return;
				}
				temp->next = temp->next->next;
				return;
			}
			temp=temp->next;
		}
	}
	
	void createPrimitiveCycle(int jointKey){
		
		if(head == NULL || head->next == NULL){
			return;
		}
		node* temp = head;
		node* joint = NULL;
		while(temp->next != NULL){
			if(temp->data == jointKey){
				joint = temp;	
			}
			temp = temp->next;
		}
		if(joint == NULL){
			return;
		}
		temp->next = joint;
	}
	
	bool detectCycle(){

		node* slow = head;
		node* fast = head;
		
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				return true;	
			} 
		}
		return false;
	}
	
	bool detectAndRemoveCycle(){
		node *slow = head;
		node *fast = head;
		
		while(fast!=NULL && fast->next!=NULL){
			fast = fast->next->next;
			slow = slow->next;
			if(fast == slow){
				slow = head;
				while(slow->next != fast->next){
					slow=slow->next;
					fast=fast->next;
				}
				fast->next = NULL;
				return true;
			}
		}
		return false;
	}
	
	friend node* mergeSortedLists(node* &, node* &);
	friend lList mergeTwoSortedLists(lList&, lList&);
	friend node* midPoint(node* head);	
	node* mergeSort(node* &);
	void sort();
	
};

ostream& operator <<(ostream& cout, lList L){
	L.display();
}

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
		
	lList ll;
	node* newnode = NULL;
	
	newnode = newNode(10);
	ll.insertAtHead(newnode);
	
	newnode = newNode(50);
	ll.insertAtHead(newnode);
	
	newnode = newNode(30);
	ll.insertAtHead(newnode);
	
	newnode = newNode(20);
	ll.insertAtTail(newnode);
	
	newnode = newNode(70);
	ll.insertAtTail(newnode);
	
	newnode = newNode(60);
	ll.insertAfter(newnode, 10);
	
	cout<<ll;
		
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10, 44};
	int n = sizeof(a)/sizeof(int);
	lList ll1;
	ll1.createSortedLinkedList(a, n); //array is of the form tail-head, ie, insertion in ll occurs from the head
	cout<<ll1;
	
	ll.deleteAtHead();
	ll.deleteAtTail();
	cout<<ll;
	
	ll1.deleteKey(10);
	
	cout<<ll1;	
		
	return 0;
}

