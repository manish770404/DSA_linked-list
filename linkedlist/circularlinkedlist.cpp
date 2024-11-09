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

void insertathead(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertattail(node* &head, int val)
{
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

/*void printlinkedlist(node* head)
{
    node* temp = head;

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << endl; 
}*/

void printlinkedlist(node* head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }

    node* temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
void deleteathead(node* head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete =head;
    temp->next=head->next;
    head=head->next;

    delete todelete;
}
void deletion(node* head,int pos)
{

    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    node* todelete;
    node* temp=head;
    int count=1;
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
     todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main()
{
    node* head = NULL;
    insertathead(head, 10);
    insertathead(head, 20);
    insertathead(head, 30);
    insertathead(head, 40);
    insertathead(head, 50);
    insertathead(head, 60);
    insertathead(head, 70);
    insertathead(head, 80);

    printlinkedlist(head);
cout<<endl;
//insertathead(head,15);
deletion(head, 3);
printlinkedlist(head);
    return 0;
}
