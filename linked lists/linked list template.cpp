#include <iostream>
#include <stdlib.h>
#include <time.h>
#define null nullptr
#define ttt template <typename T>
using namespace std;

ttt class node{
public:
    T data;
    node<T>* next;
    explicit node(T d){
        data = d;
        next = null;
    }
    T getData(){
        return data;
    }
};

ttt class linked_list;
ttt ostream& operator << (ostream& os, linked_list<T>& x);

ttt class linked_list{
protected:
    node<T>* head;
    node<T>* tail;
public:
    linked_list(){
        head = null;
        tail = null;
    }
    void insertAtHead(T data);
    void insertAtTail(T data);
    void insertAfterNode(node<T>* Node, T data);
    void insertBeforeNode(node<T>* Node, T data);
    void output();
    friend ostream& operator << <> (ostream& os, linked_list<T>& x);
    node<T>* pointAtPos(int);
    bool isPresent(T value);
    void deleteAtHead();
    void deleteLastNode();
    void deleteNodeWithData(T key);
    void reverse();
    void revRec(node<T> *head, node<T> *&newHead);
    void sortedInsert(T value);
    void genRandList(int n=5);
    void genSortedRandList(int n=5);
    void sortedMerge(linked_list<T> &ll);
    node<T>* midNode(node<T>*head);
    node<T>* mergeSort(node<T>*);
    void sortList();
    void createPrimitiveCycle(T jointKey);

    bool detectCycle();

    bool detectAndRemoveCycle();
};



ttt bool searchRecursive(node<T>* head, T &key){
    if(head == null){
        return false;
    }
    if(head->data == key || searchRecursive(head->next, key)){
        return true;
    }
    return false;
}

ttt bool linked_list<T> :: isPresent(T value){
    return searchRecursive(head,value);
}

ttt node<T>* linked_list<T> :: pointAtPos(int pos){
    if(head == null || pos < 0){
        return null;
    }
    if(pos == 0){
        return head;
    }
    node<T>* t = head;
    while(t != null && pos--){
        t = t->next;
    }
    if(pos > 0){
        return null;
    }
    return t;
}


ttt ostream& operator << (ostream& os, linked_list<T>& ll){
    ll.output();
}


ttt void linked_list<T> :: output(){
    if(head == null){
        return;
    }
    if(head->next == null){
        cout<<head->data<<" -> :]\n";
        return;
    }
    node<T> * t = head;
    while(t != null){
        cout<<t->data<<" -> ";
        t = t->next;
    }
    cout<<":]\n";
}

ttt void linked_list<T> :: insertAtHead(T data) {
    auto* newnode = new node<T>(data);
    newnode->next = head;
    head = newnode;
}

ttt void linked_list<T> ::insertAtTail(T data) {
    auto* newnode = new node<T>(data);
    if(head == null){
        head = newnode;
    }
    node<T>* t = head;
    while(t->next != null){
        t = t->next;
    }
    t->next = newnode;
}


ttt void linked_list<T> :: insertAfterNode(node<T>* Node, T data){
    auto* newnode = new node<T>(data);
    newnode->next = Node->next;
    Node->next = newnode;
}

ttt void linked_list<T> :: insertBeforeNode(node<T> *Node, T data) {
    auto* newnode = new node<T>(data);
    if(head == null){
        return;
    }
    if(Node == head){
        insertAtHead(data);
        return;
    }
    node<T>* t = head;
    while(t->next != null && t->next != Node){
        t = t->next;
    }
    if(t->next == null){
        return;
    }
    newnode->next = t->next;
    t->next = newnode;
}

ttt void linked_list<T> :: deleteAtHead(){
    if(head == null){
        return;
    }
    node<T>* t = head;
    head = head->next;
    delete t;
}

ttt void linked_list<T> :: deleteLastNode(){
    if(head == null){
        return;
    }
    node<T>* t = head;
    node<T>* temp;
    if(head->next == null){
        head = null;
    }else{
        while(t->next->next != null){
            t = t->next;
        }
        temp = t;
        t = t->next;
        temp->next = null;
    }
    delete t;
}

ttt void linked_list<T> :: deleteNodeWithData(T key){
    if(head == null){
        return;
    }

    if(head->data == key){
        deleteAtHead();
        return;
    }

    if(head->next == null){
        return;
    }

    node<T>* p = head;
    node<T>* t = head->next;

    if(head->next->data == key){
        head->next = t->next;
        delete t;
        return;
    }

    while(t != null){
        if(t->data == key){
            p->next = t->next;
            delete t;
            return;
        }
        p = t;
        t = t->next;
    }

}

ttt void linked_list<T> :: revRec(node<T>* head, node<T>* &newHead){
    if(head == null){
        return;
    }
    if(head->next == null){
        newHead = head;
        return;
    }
    revRec(head->next,newHead);
    head->next->next = head;
    head->next = null;
}

ttt void linked_list<T> :: reverse(){
    node<T>* newHead = null;
    revRec(head,newHead);
    head = newHead;
}

ttt void linked_list<T> :: genRandList(int n){
    srand(time(0));
    while(n--){
        insertAtHead(rand());
    }
}

ttt void linked_list<T> :: genSortedRandList(int n){
    srand(time(0));
    while(n--){
        sortedInsert(rand());
    }
}


ttt void linked_list<T> :: sortedInsert(T value){
    node<T>* newnode = new node<T>(value);
    if(head == null){
        head = newnode;
        return;
    }
    if(head->next == null){
        if(value <= head->data) insertAtHead(value);
        else insertAtTail(value);
        return;
    }
    node<T>* prev = head;
    node<T>* curr = head->next;
    if(value <= head->data) insertAtHead(value);
    else{
        while(curr != null && curr->data < value){
            prev = curr;
            curr = curr->next;
        }
        newnode->next = curr;
        prev->next = newnode;
    }
}


ttt node<T>* mergeLists(node<T>* &lh1, node<T>* &lh2){
    if(lh1 == null){
        return lh2;
    }
    if(lh2 == null){
        return lh1;
    }
    node<T>*curr;
    if(lh1->data <= lh2->data){
        curr = lh1;
        lh1->next = mergeLists(lh1->next,lh2);
    }else{
        curr = lh2;
        lh2->next = mergeLists(lh1,lh2->next);
    }
    return curr;
}


ttt void linked_list<T> :: sortedMerge(linked_list<T> &ll){
    node<T>*lh1 = head;
    node<T>*lh2 = ll.head;
    head = mergeLists(lh1,lh2);
}


ttt node<T>* linked_list<T> :: midNode(node<T>*head) {
    if(head == null || head->next == null){
        return head;
    }
    node<T>* slow=head;
    node<T>* fast=head->next;
    while(fast!=null && fast->next!=null){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ttt node<T>* linked_list<T> :: mergeSort(node<T>*head){
    if(head == null || head->next == null){
        return head;
    }
    node<T>* mid = midNode(head);
    node<T>* left = head;
    node<T>* right = mid->next;
    mid->next = null;
    left = mergeSort(left);
    right = mergeSort(right);
    return mergeLists(left,right);
}

ttt void linked_list<T> :: sortList(){
    head = mergeSort(head);
}

ttt void linked_list<T> :: createPrimitiveCycle(T jointKey){

    if(head == null || head->next == null){
        return;
    }
    node<T>* temp = head;
    node<T>* joint = null;
    while(temp->next != null){
        if(temp->data == jointKey){
            joint = temp;
        }
        temp = temp->next;
    }
    if(joint == null){
        return;
    }
    temp->next = joint;
}

ttt bool linked_list<T> :: detectCycle(){
    if(head == null || head->next == null){
        return false;
    }
    if(head->next == head){
        return true;
    }
    node<T> *slow = head, *fast = head;
    while(fast != null && fast->next != null){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

ttt bool linked_list<T> :: detectAndRemoveCycle(){
    if(head == null || head->next == null){
        return false;
    }
    if(head->next == head){
        head->next = null;
        return true;
    }
    node<T> *slow = head, *fast = head;
    while(fast != null && fast->next != null){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            fast = head;
            while(fast->next != slow->next){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = null;
            return true;
        }
    }
    return false;
}


int main() {
    cout << "Hello Linked Lists!\n";
    linked_list<int> ll;
    ll.insertAtHead(7);
    ll.insertAtHead(17);
    ll.insertAtTail(4);
    node<int>* t = ll.pointAtPos(0);
    if(t!=null){
        cout<<(*t).getData()<<"\n";
    }
    ll.insertBeforeNode(t,20);
    ll.insertAfterNode(t,15);
    cout<<ll.isPresent(4)<<"\n";
    cout<<ll;
//    ll.deleteNodeWithData(17);
//    ll.deleteAtHead();
//    ll.deleteLastNode();
//    cout<<ll;
    ll.reverse();
    cout<<ll;
    linked_list<int> ll2;
    ll2.genRandList();
    cout<<ll2;
    ll.sortedInsert(12002);
    ll.sortedInsert(5000);
    ll.sortedInsert(6044);
    ll.sortedInsert(59383);
    ll.sortedInsert(704);
    ll.sortedInsert(8851);
    cout<<ll;
    linked_list<int> ll3;
    ll3.genSortedRandList();
    cout<<ll3;
    ll.sortedMerge(ll3);
    cout<<ll;
    ll2.sortList();
    cout<<ll2;
    ll.createPrimitiveCycle(5000);
    cout<<ll.detectCycle()<<" ";
    cout<<ll.detectAndRemoveCycle()<<"\n";
    cout<<ll;
    return 0;
}
