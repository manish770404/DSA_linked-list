#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};


void insertathead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertatgivenposition(node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertathead(head, val);
        return;
    }

    node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        if (temp == NULL)
        {
            // Insert at the tail if the position is at the end of the list
            insertattail(head, val);
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        // Insert at the tail if the position is at the end of the list
        insertattail(head, val);
        return;
    }

    node *n = new node(val);
    n->next = temp->next;
    temp->next = n;
}

void printlinkedlist(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
}

void deleteathead(node *&head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(node *&head, int val)
{
    node *temp = head;

    if (head->next == NULL)
    {
        deleteathead(head);
        return;
    }
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main()
{
    node *head = NULL;
    insertattail(head, 15);
    insertattail(head, 20);
    insertattail(head, 19);
    insertattail(head, 12);
    insertattail(head, 33);
    insertattail(head, 44);
    printlinkedlist(head);
    cout << endl;
    insertatgivenposition(head, 50, 2);
    printlinkedlist(head);
    cout << endl;
    insertatgivenposition(head, 50, 25);
    printlinkedlist(head);

    return 0;
}
