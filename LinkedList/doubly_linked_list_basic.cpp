// Online C++ compiler to run C++ program online
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

    for (int i = 0; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head
}

void print(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        if (head->next == NULL)
            delete head;

        return NULL
    }

    Node* prev = head;
    head= head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

Node* deleteTail(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        if (head->next == NULL)
            delete head;

        return NULL;
    }

    Node* tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;

    delete tail;

    return head;
}

Node* removeKthNode(Node* head, int k)
{
    if (head == NULL)
        return NULL;

    int cnt = 0;
    Node* kNode = head;

    while (kNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if (prev == NULL && front == NULL)
        return NULL;
    else if (prev == NULL)
        return deleteHead(head);
    else if (front == NULL)
        return deleteTail(head)

    prev->next = front;
    front->back = prev;

    kNode->next = nullptr;
    kNode->back = nullptr;

    delete kNode;

    return head;
}

void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->front;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);

        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

Node* insertBeforeHead(Node* head, int val) {
    Node* newHhead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    

    Node* tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node* prev = tail->back;

    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;

    return head;
    
}

Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k==1)
    {
        return insertBeforeHead(head, val);
    }

    int currNode = 1;
    Node* kthNode = head;

    while (currNode != k)
    {
        kthNode = kthNode->next;
        currNode++;
    }

    Node* prevNode = kthNode->back;
    Node* newNode = new Node(val, kthNode, prevNode);

    prevNode->next = newNode;
    kthNode->back = newNode;
    
    return head;
}

void insertBeforeNode(Node* node, int val) {
    Node* prevNode = node->back;
    Node* newNode = new Node(val, node, prevNode);

    prevNode->next = newNode;
    node->back = newNode;
}

int main()
{
    vector<int> arr = {2, 5, 6, 7, 9};
    Node *head = convertArr2DLL(arr);
    print(head);
    return 0;
}