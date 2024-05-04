#include<iostream>
using namespace std;

int counter = 1;

void function() {
    if (counter > 5) return;
    cout << "Name" << endl;
    counter++;
    function();
}

int main() {
    function();
    return 0;
}