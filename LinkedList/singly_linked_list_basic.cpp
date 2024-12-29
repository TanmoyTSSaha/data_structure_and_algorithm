// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1, Node* next1, Node* back1) {
        data=data1;
        next=next1;
        back=back1;
    }
    
    public:
    Node(int data1) {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertAllToDoublyLinkedList(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* removeHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        if(head->next == NULL) delete head;
        
        return NULL;
    }
    
    Node* prev = head;
    
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    
    delete prev;
    
    return head;
}

Node* removeTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        if(head->next == NULL) delete head;
        
        return NULL;
    }
    
    Node* temp = head;
    
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    
    Node* next = temp->next;
    
    next->back = nullptr;
    temp->next = nullptr;
    
    delete next;
    
    
    return head;
}

Node* removeElementsFromLinkedListByPosition(Node* head, int k) {
    if (head == NULL) return NULL;
    
    int cntr = 0;
    Node* KNode = head;
    
    while()
    
    return head;
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