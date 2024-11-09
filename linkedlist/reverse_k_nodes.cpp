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

node* reverseknodes(node* &head, int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;

    // Count the number of nodes in the current group
    node* temp = head;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }

    // If there are at least k nodes, reverse them
    if (count == k)
    {
        count = 0;
        while (count < k && currptr != NULL)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }

        // Recursive call for the next group of k nodes
        if (nextptr != NULL)
        {
            head->next = reverseknodes(nextptr, k);
        }

        return prevptr;  // New head of the reversed group
    }
    else
    {
        // If there are less than k nodes, no reversal needed, return the current head
        return head;
    }
}

int main()
{
    node* head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);

    cout << "Original Linked List: ";
    printlinkedlist(head);
    cout << endl;

    cout << "After reverse: ";
    node* res = reverseknodes(head, 2);
    printlinkedlist(res);

    return 0;
}
