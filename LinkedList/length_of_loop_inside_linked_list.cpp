int lengthOfLoopWithBigOofNSpaceComplexity(Node *head) {
    Node* temp = head;
    map<Node*, int> mpp;
    int counter = 0;

    while(temp != NULL) {
        counter++;
        
        if(mpp.find(temp) != mpp.end()) {
            int nodeStartingCounter = mpp[temp];

            return counter - nodeStartingCounter;
        }

        mpp[temp] = counter;
        temp = temp->next;
    }

    return 0;
}


int lengthOfLoopOptimisedUsingTortoiseAndHareAlgorithm(Node *head) {
    Node* fast = head;
    Node* slow = head;
    int counter = 1;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            fast = fast->next;
            while (fast != slow) {
                fast = fast->next;
                counter++;
            }

            return counter;
        }

    }

    return 0;
}
