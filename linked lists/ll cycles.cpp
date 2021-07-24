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
	
	friend ostream& operator <<(ostream&, lList);
	
};

ostream& operator <<(ostream& cout, lList L){
	L.display();
}


int main(){
			
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10, 44};
	int n = sizeof(a)/sizeof(int);
	lList ll1;
	ll1.createLinkedList(a, n);
	cout<<ll1;
	ll1.createPrimitiveCycle(21);
	bool one = ll1.detectCycle();
	cout<<one;	
	bool two = ll1.detectAndRemoveCycle();
	cout<<ll1;
	cout<<two;
	bool three = ll1.detectCycle();
	cout<<"\n"<<three;
	return 0;
}

