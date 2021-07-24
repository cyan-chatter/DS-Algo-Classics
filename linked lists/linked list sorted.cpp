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

class lListS{
	node* start;
	public:	
	lListS(){
		start = NULL;
	}
	
	void insertSorted(){
	node *newnode, *current, *prev;
	int value;
	cout<<"Enter the newnode value\n";
	cin>>value;
	newnode=new node;
	newnode->data=value;
	newnode->next=NULL;
	if(start==NULL)
	{
		cout<<"List is empty. Adding element\n";
		start=newnode;
		return;
	}
	if(start->next == NULL)
	{
		if(value>start->data){
			start->next = newnode;
			return;	
		}
		else{
			newnode->next = start;
			start = newnode;
			return;
		}
	}
	current=start;
	prev = NULL;
	if(value<start->data){
		newnode->next=start;
		start=newnode;
		return;
	}
	while(value>current->data && current->next!=NULL){
			prev = current;
			current=current->next;
	}
	if(value>current->data && current->next==NULL){
		current->next = newnode;
		return;
	}
	else if(value<current->data){
		prev->next=newnode;
		newnode->next=current;
		return;	
	}
}

void insdelete(){
	node *temp;
	if(start==NULL)
	{
		cout<<"Your linked is Empty";
		return;
	}
	temp=start;
	start=start->next;
	free(temp);
}

void enddelete(){
	node *temp,*prev;
	prev=NULL;
	temp=start;
	
	if(start==NULL)
	{
		cout<<"your linked list is empty";
		return;
	}
	
	if(start->next == NULL){
		start = NULL;
		free(temp);
		return;
	}
	
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	free(temp);
	return;
}

void middelete(){
	node *temp,*prev=NULL;
	int key;
	temp=start;
	
	if(start == NULL){
		cout<<"List is empty\n";
		return;
	}
	
	cout<<"Enter the key to be deleted\n";
	cin>>key;
	
	if(start->next == NULL){
		if(key == start->data){
			start = start->next;
			free(temp);	
		}
		else cout<<"Element Not Found";
		return;
	}
	
	if(key == start->data){
		start=start->next;
		free(temp);
		return;
	}
	
	while(temp->data!=key && temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	if(temp->next==NULL && temp->data!=key)
	{
		cout<<"element not found\n";
		return;
	}
	else if(temp->next==NULL && temp->data==key)
	{
		prev->next=NULL;
		free(temp);
		return;
	}
	else
	{
		prev->next=temp->next;
		free(temp);
		return;
	}	
	
}

void search(){
	node* temp;
	int key,c=1;
	cout<<"Enter the Element to Search for\n";
	cin>>key;
	if(start == NULL){
		cout<<"List is empty\n";
		return;
	}
	temp=start;
	while(temp->data!=key && temp->next!=NULL)
	{
		temp=temp->next;
		++c;
	}
	if(temp->next==NULL && temp->data!=key)
	{
		cout<<"Element Not Found\n";
		return;
	}
	else if(temp->data==key)
	{
		cout<<"Element found at Node no. "<<c<<"\n";
	}
}

int count(){
	node* temp;
	int c=1;
	if(start == NULL){
		return 0;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		++c;
	}
	return c;
}

void findMax(){
	node* temp;
	if(start == NULL){
		cout<<"No elements in list\n";
		return;
	}
	if(start->next == NULL){
		cout<<"The maximum element is: "<<start->data<<"\n";
		return;
	}
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	cout<<"The maximum element is: "<<temp->data<<"\n";
}

void findMin(){
	if(start == NULL){
		cout<<"No elements in list\n";
		return;
	}
	cout<<"The minimum element is: "<<start->data<<"\n";
}

void display(){
	node *temp;
	if(start==NULL)
	{
		cout<<"linked list is empty\n";
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

};


int main(){
	int choice;
	lListS lls;
	while(1){
		cout<<"\nenter choice\n";
		cin>>choice;
		switch(choice){
			case 1: lls.insertSorted(); break;
			case 2: lls.insdelete(); break;
			case 3: lls.enddelete(); break;
			case 4: lls.middelete(); break;
			case 5: lls.search(); break;
			case 6: lls.findMax(); break;
			case 7: lls.findMin(); break;
			case 8: cout<<"\nThere are "<<lls.count()<<" nodes in the linked list.\n"; break;
			case 9: cout<<"\n----------------\n";lls.display(); break;
			case 10: exit(1);
			default: "\nSelect options from 1 to 10\n";
		}	
	}
	
	return 0;
}


