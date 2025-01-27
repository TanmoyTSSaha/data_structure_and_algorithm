Node* reverseLinkedList(Node *head)
{
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp != NULL) {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

Node* recursiveReverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}