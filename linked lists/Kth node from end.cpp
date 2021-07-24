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
	
	node* KthFromEnd(int K){
		
		if(head == NULL || K<=0){
			return NULL;
		}
		
		if(head->next == NULL && K==1){
			return head;
		}
		
		node* slow = head;
		node* fast = head;
		
		for(int i=0; i<K; ++i){
			if(fast == NULL){
				return NULL;
			}
			fast = fast->next;
		}
			 
		while(fast != NULL){
			slow = slow->next;
			fast = fast->next;
		}
		
		return slow;
		
	}

};


int main(){
		
	lList ll;
	node* newnode = NULL;	
	int a[] = {4, 14, 6, 21, 9, 11, 17, 7, 66, 10};
	int n = sizeof(a)/sizeof(int);
	ll.createLinkedList(a, n); 
	ll.display();
	int K = 3;
	node* Kth = ll.KthFromEnd(K);
	if(Kth != NULL){
		cout<<Kth->data;	
	}
	else cout<<"\nNULL";
	return 0;
}

