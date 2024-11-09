#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertathead(node* &head, int val) {
    node* n = new node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}
void insertattail(node* &head,int val)
{

    if(head==NULL)
    {
        insertathead(head,val);
        return;
    }
    node* n=new node(val);
     node* ptr=head;
     
     while(ptr->next!=NULL)
     {
        ptr=ptr->next;
     }
     ptr->next=n;
     n->prev=ptr;

}
void printlinkedlist(node* head)
{
    node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
}
void deleteathead(node* &head)
{
    node* todelete=head;
    head=head->next;
    if(head!=NULL)
    {
        head->prev=NULL;
    }
    delete todelete;
}
void deletion(node* &head,int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    node* ptr=head;
    int count=1;
    while(ptr!=NULL&&count!=pos)
    {
        ptr=ptr->next;
        count++;
    }
    if(pos>count)
    {
        cout<<"the given position is not valid";
        return;
    }
    ptr->prev->next=ptr->next;
    if(ptr->next!=NULL)
    {
        ptr->next->prev=ptr->prev;
    }
    
    delete ptr;
}
int main() {
    node* head = NULL;
     insertattail(head,1);
     insertattail(head,2);
     insertattail(head,3);
     insertattail(head,4);
     insertattail(head,5);
     insertattail(head,6);
     insertattail(head,7);
     insertattail(head,8);
     insertattail(head,9);
     printlinkedlist(head);
     cout<<endl;
     deletion(head,12);
     
      printlinkedlist(head);
     
   

    return 0;
}
