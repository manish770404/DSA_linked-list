#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertattail(node* &head, int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void printlinkedlist(node* head)
{
    node* ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}


//reverse using iterative method
node* reverselinkedlist(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;  
    node* nextptr;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }

    head = prevptr;
    return head;
}


//reverse using recursive method
node* reversebyrecursion(node* &head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

      
    node* newhead = reversebyrecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    node* head = NULL;
    insertattail(head, 15);
    insertattail(head, 20);
    insertattail(head, 19);
    insertattail(head, 12);
    insertattail(head, 33);
    insertattail(head, 44);

    cout << "Original Linked List: ";
    printlinkedlist(head);
    cout << endl;

    // head = reverselinkedlist(head);
    head = reversebyrecursion(head);

    cout << "Reversed Linked List: ";
    printlinkedlist(head);

    return 0;
}
