// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node{
    Public:
    int data;
    Node* next;
    Public:

    Node (int data1, Node* next1){
        data=data1; 
        next=next1; 
    }
    Node (int data1){
        data=data1; 
        next=nullptr; 

    }
};

Node* constructLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int lengthOfLinkedList(Node *head)
{
	int cnt=0;
    Node* temp = head;
    
    while(temp) {
        temp = temp->next;
        cnt++;
    }
    
    return cnt;
}

int searchInLinkedList(Node<int> *head, int k) {
    Node<int>* temp = head;
    
    while(temp) {
        if(k == temp->data) return 1;
        
        temp = temp->next;
    }
    
    return 0;
}

int main() {
    vector<int> arr = {2, 5, 6, 7, 9};
    
    Node* head = convertAllToDoublyLinkedList(arr);
    
    cout << "Doubly Linked List before operation: " << endl;
    print(head);
    
    head = removeTail(head);
    
    cout << "\n\nDoubly Linked List after operation: " << endl;
    print(head);
    
    return 0;
}