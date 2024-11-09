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

node* merge(node* head1,node* head2)
{
    node* p1=head1;
    node* p2=head2;

    node* dummynode=new node(-1);

    node* p3=dummynode;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
           p3->next=p2;
           p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
         p3->next=p1;
            p1=p1->next;
             p3=p3->next;

    }
    while(p2!=NULL)
    {
         p3->next=p2;
           p2=p2->next;
            p3=p3->next;
    }
    return dummynode->next;
}
int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    insertattail(head1, 1);
    insertattail(head1, 4);
    insertattail(head1, 5);
    insertattail(head1, 7);
    insertattail(head2, 2);
    insertattail(head2, 3);
    insertattail(head2, 6);
    

    cout << "List 1: ";
    printlinkedlist(head1);
    cout << endl;
    
    cout << "List 2: ";
    printlinkedlist(head2);
    cout << endl;
    node* newhead= merge( head1, head2);
    cout<<"merged list is:";
    printlinkedlist(newhead);
    return 0;
}