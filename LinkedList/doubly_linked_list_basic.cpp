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



int main() {
    vector<int> arr = {2, 5, 6, 7, 9};
    
    return 0;
}