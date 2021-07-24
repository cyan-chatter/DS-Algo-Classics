#include<iostream>
#include<string.h>
#include<unordered_map>
#include<map>
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
	
	int detectAndRemoveCycle();
	void unionThis(lList&);
	void intersectionThis(lList&);
};

int lList::detectAndRemoveCycle(){
	unordered_map<node*,int> m;
	node* temp = head;
	node* prev = head;
	while(temp!= NULL){
		if(m.count(temp)){
			prev->next = NULL;
			return temp->data;
		}
		m[temp] = temp->data;
		prev = temp;
		temp = temp->next;
	}		
	return -1;	
}

void lList::unionThis(lList& ll){
	map<int,node*> hm;
	node* temp = head;
	node* temp2 = ll.head;
		while(temp!=NULL){
			if(!hm.count(temp->data)){
				hm[temp->data] = temp;
			}
			temp=temp->next;
		}
		while(temp2!=NULL){
			if(!hm.count(temp2->data)){
				hm[temp2->data] = temp2;
			}
			temp2=temp2->next;
		}
		node* t = NULL;
	for(auto itr : hm){
		if(itr.first != (hm.begin())->first){
			t->next = itr.second;
			t = t->next;
			if(t->next != NULL){
				t->next = NULL;		
			}	
		}else{
			head = itr.second;
			head->next = NULL;
			t = head;	
		}
	}
}

int main(){
	
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10, 44};
	int b[] = {24, 54, 6, 40, 19, 24, 17, 44};
	//4 6 7 9 10 11 14 17 19 21 24 40 44 54 66
	//4 14 6 21 9 11 17 7 66 10 44
	//54 40 17 44 21 66--	==1
	//21--	<=1
	int n = sizeof(a)/sizeof(int);
	int m = sizeof(a)/sizeof(int);
	lList ll;
	lList ll1;
	ll.createLinkedList(a, n);
	ll1.createLinkedList(b, m); 
//	ll.createPrimitiveCycle(11);
//	cout<<ll.detectAndRemoveCycle()<<"\n";
	ll.unionThis(ll1);
	ll.display();
	return 0;
}

