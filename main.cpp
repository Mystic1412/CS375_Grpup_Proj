#include <iostream>
using namespace std;

class Node{
public:
    int data;

    Node* prev;
    Node* next;

    Node(int d){
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};


int main(){

    return 0;
}