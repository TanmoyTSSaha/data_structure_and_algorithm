#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* findMiddleNodeUnoptimized(Node* head) {
    Node* temp = head;
    int cntr = 0;
    
    while(temp->next != NULL) {
        cntr++;
        temp=temp->next;
    }

    if (cntr % 2 != 0) {
        cntr = cntr+1;
    }

    int midNd = (cntr/2)+1;
    temp = head;

    while(temp != NULL) {
        midNd--;
        if(midNd == 0) 
            break;
        temp=temp->next;
    }

    return temp;
}

Node* findMiddleOptimal(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    vector<int> arr = {11, 16, 12, 16, 22, 60, 67, 32, 58, 69, 53, 2, 84, 63, 87, 66, 52, 100, 53, 90, -1};   
    Node* head = convertArr2DLL(arr);
    head = findMiddleNodeUnoptimized(head);
    print(head);
    return 0;
}