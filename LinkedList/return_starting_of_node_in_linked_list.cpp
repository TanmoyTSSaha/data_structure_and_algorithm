Node* firstNodeWithBigOofNSpaceComplexity(Node *head)
{
    map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL) {
        if (mpp.find(temp) != mpp.end()) {
            return temp;
        }

        mpp[temp] = 1;

        temp = temp->next;
    }

    return NULL;
}

Node* firstNodeOptimisedUsingTurtoiseAndHareAlgorithm(Node *head)
{
    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast-> next;
            }

            return fast;
        }
    }

    return NULL;
}