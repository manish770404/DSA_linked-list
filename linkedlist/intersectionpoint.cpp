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

int length(node* &head) {
    node* ptr = head;
    int l = 0;
    while (ptr != NULL) {
        l++;
        ptr = ptr->next;
    }
    return l;
}

int intersectionpoint(node* &head1, node* &head2) {
    int l1 = length(head1);
    int l2 = length(head2);

    node* ptr1 = head1;
    node* ptr2 = head2;

    int d = 0;
    if (l1 > l2) {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    } else {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1; // Fix: Should be head1, not head2
    }

    while (d--) {
        ptr1 = ptr1->next;
        if (ptr1 == NULL) {
            return -1;
        }
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

void intersection(node* head1, node* head2, int pos) {
    node* temp1 = head1;
    pos--;
    while (pos--) {
        temp1 = temp1->next;
    }
    node* temp2 = head2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    insertattail(head1, 1);
    insertattail(head1, 2);
    insertattail(head1, 3);
    insertattail(head1, 4);
    insertattail(head1, 5);
    insertattail(head1, 6);
    insertattail(head1, 7);
    insertattail(head2, 10);
    insertattail(head2, 11);
    insertattail(head2, 12);
    insertattail(head2, 13);

    cout << "List 1: ";
    printlinkedlist(head1);
    cout << endl;
    
    cout << "List 2: ";
    printlinkedlist(head2);
    cout << endl;

    intersection(head1, head2, 2);

    cout << "Intersection Point: " << intersectionpoint(head1, head2) << endl;

    return 0;
}
