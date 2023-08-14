#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append_back(Node* tail, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    tail->next = newNode;
}
