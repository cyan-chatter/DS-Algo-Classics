#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    
		node(int d){
      data = d;
      next = NULL;
    }
};

/*
class LinkedList{
    node*head;
    node*tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert(){
        
    }
    
};
*/

void insertAtHead(node*&head,int data){
    node*n = new node(data);
    n->next = head;
    head = n;
}

int length(node*head){
    
    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}

void insertAtTail(node*&head,int data){
    
    if(head==NULL){
        head = new node(data);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node*&head,int data,int p){
    
    if(head==NULL||p==0){
        insertAtHead(head,data);
    }   
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        //Insert in the middle 
        //Take p-1 jumps
        int jump=1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump += 1;
        }
        
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
        
    }
}

bool searchRecursive(node*head,int key){
    if(head==NULL){
        return false;
    }
    //Rec Case 
    if(head->data ==key){
        return true;
    }
    else{
        return searchRecursive(head->next,key);
    }
}
bool searchIterative(node*head,int key){
    
    while(head!=NULL){
        if(head->data==key){
            return true;
        }
        head = head->next;
    }
    return false;
}

void print(node*head){
    //node*temp = head;
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
        if(head == NULL){
        	cout<<"|:";
				}
    }
    cout<<endl;
}

void buildList(node*&head){
    
    int data;
    cin>>data;
    
    while(data!=-1){
        insertAtTail(head,data);
        cin>>data;
    }
}

istream& operator >> (istream &is, node*&head){
	buildList(head);
	return is;
}
ostream& operator << (ostream &os, node*head){
	print(head);
	return os;
}

void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteInTheMiddle(node*head,int p){
    //Homework 
}

void reverse(node*&head){
    
    node*C = head;
    node*P = NULL;
    node*N;
    
    while(C!=NULL){
        //Save the next node 
        N = C->next;
        //Make the current node point to prev 
        C->next = P;
        //Just update prev and current
        P = C;
        C= N;
    }
    head = P;
}

node* reverseRec(node*head){
    //Base Case 
    if(head->next==NULL||head==NULL){
        return head;
    }
    //Rec Case
    node*smallHead = reverseRec(head->next);
    node*C = head;
    C->next->next = C;
    C->next = NULL;
    return smallHead;
    
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

node* midPoint2(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*slow = head;
    node*fast = head;
    
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* kthFromLast(node*head, int k){
	if(head==NULL || head->next==NULL){
		return head;
	}
	node*slow = head;
	node*fast = head;
	while(k--){
		if(fast==NULL){
			cout<<"\nERROR CONDITION\n";
			return head;
		}
		fast = fast->next;
	}
	while(fast!=NULL){
		slow=slow->next;
		fast=fast->next;
	}
	return slow; 
}

node* merge(node*a, node*b){
	if(a==NULL) return b;
	else if(b==NULL) return a;
	node *c;
	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

node* mergeSort(node* head){
	if(head==NULL || head->next == NULL){
		return head;
	}
	
	node* mid = midPoint(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;
	
	a = mergeSort(a);
	b = mergeSort(b);
	
	node *c = merge(a,b);
	return c;
}

bool detectCycle(node *head){
	node *slow = head;
	node *fast = head;
	
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			return true;
		}
	}
	return false;
}

bool removeCycle(node *head){
	node *slow = head;
	node *fast = head;
	
	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow){
			slow = head;
			while(slow->next == fast->next){
				slow=slow->next;
				fast=fast->next;
			}
			fast->next = NULL;
			return true;
		}
	}
	return false;
}

int main(){
    node*head = NULL;
    node*head1 = NULL;
    node*head2 = NULL;
    node*head3 = NULL;
		node*head4 = NULL;
		//buildList(head);
    //print(head);
    //cin>>head>>head2;
    //cout<<head<<head2;
    cin>>head;
    cout<<head;
//    cin>>head1;
//    cout<<head1;
		head2 = midPoint2(head);
    cout<<"\nMid 2: "<<head2->data;
    head2 = midPoint(head);
    cout<<"\nMid 1: "<<head2->data;
    head3 = kthFromLast(head,3);
		cout<<"\n3rd Last Element: "<<head3->data<<"\n";
//		head4 = merge(head,head1);
//		cout<<"\nMerged List:  "<<head4<<"\n";
		head4 = mergeSort(head);
		cout<<"\nSorted List:  "<<head4<<"\n";
		return 0;
}
