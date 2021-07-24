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
	void reverse1(){
		
		//three pointers method
		if(head == NULL){
			return;
		}
		if(head->next == NULL){
			return;
		}
		node* pre = head;
		node* temp = head->next;
		node* post = temp->next;
		if(post == NULL){
			temp->next = head;
			head->next = NULL;
			head = temp;
			return;
		}
		while(post != NULL){
			temp->next = pre;
			pre = temp;
			temp = post;
			post = post->next;
			
		}
		temp->next = pre;
		head->next = NULL;
		head = temp;
	}
	void reverse2(){
		//three pointer method but very neat
		if(head == NULL){
			return;
		}
		node* C = head;
		node* P = NULL;
		node* N;
		while(C!=NULL){
			N = C->next;
			C->next = P;
			P = C;
			C = N;
		}
		head = P;
	}	

	node* reverseRec(node* head){
		//reverse Recursively
	if(head == NULL || head->next == NULL){
		return head;
	}		
	node* smallhead = reverseRec(head->next);
	node* current = head;
	current->next->next = current;
	current->next = NULL;
	return smallhead;	
	}
	
	void reverse3(){
		//reverse Recursively Wrapper
		head = reverseRec(head);
	}
};


int main(){
		
	lList ll;
	node* newnode = NULL;	
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10};
	int n = sizeof(a)/sizeof(int);
	ll.createLinkedList(a, n); 
	ll.display();
	ll.reverse3();
	ll.display();	
	return 0;
}

