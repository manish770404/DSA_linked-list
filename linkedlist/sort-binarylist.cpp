#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};
void insertattail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void printlinkedlist(node* head) {
    node* ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}
void sortBinaryLinkedList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Initialize two dummy nodes for 0s and 1s
    Node* zeroDummy = new Node(0);
    Node* oneDummy = new Node(0);

    Node* zeroCurr = zeroDummy;
    Node* oneCurr = oneDummy;

    // Traverse the original list
    Node* curr = head;
    while (curr != nullptr) {
        // If current node's data is 0, append it to the zero list
        if (curr->data == 0) {
            zeroCurr->next = curr;
            zeroCurr = zeroCurr->next;
        } else { // Otherwise, append it to the one list
            oneCurr->next = curr;
            oneCurr = oneCurr->next;
        }
        curr = curr->next;
    }

    // Connect the zero list to the one list
    zeroCurr->next = oneDummy->next;

    // Connect the end of the one list to nullptr
    oneCurr->next = nullptr;

    // Update the head pointer to the start of the sorted list
    head = zeroDummy->next;

    // Free the dummy nodes
    delete zeroDummy;
    delete oneDummy;
}

int main() {
 node* head = NULL;
    insertattail(head, 1);
    insertattail(head, 0);
    insertattail(head, 1);
    insertattail(head, 0);
    insertattail(head, 0);
    insertattail(head, 1);

    cout << "Original Linked List: ";
    printlinkedlist(head);
    cout << endl;

    
}