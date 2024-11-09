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

int length(node* &head)
{
    node* ptr=head;
    int l=0;
    while(ptr!=NULL)
    {
        l++;
        ptr=ptr->next;
    }
    return l;
}
node* appendfromgivenposition(node* &head,int k)
{
    node* newhead;
    node* newtail;
    node* tail=head;
    int len=length(head);
    k=k%len;

    if(k>=len)
    {
        cout<<"cannot append";
        return 0;
    }

    int count=1;
    while(tail->next!=NULL)
    {
        if(count==k)
        {
           newtail=tail;
        }
        if(count==k+1)
        {
            newhead=tail;
        }
        tail=tail->next;
        count++;
     }
     newtail->next=NULL;
     tail->next=head;
     return newhead;
    
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
    cout<<endl;
    node* ans=appendfromgivenposition(head,1);
     printlinkedlist(ans);
     return 0;


}