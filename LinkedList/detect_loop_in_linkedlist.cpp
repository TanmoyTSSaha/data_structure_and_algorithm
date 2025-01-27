bool detectCycleWithExtraSpaceComplexity(Node *head)
{
	map<Node*, int> mpp;
    Node* temp = head;

    while(temp != NULL) {
        if(mpp.find(temp) != mpp.end()) {
            return true;
        }

        mpp[temp] = 1;

        temp = temp->next;
    }

    return false;
}


bool detectCycleOptimisedUsingTortoiseAndHareAlgorithm(Node *head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
}