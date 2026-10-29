#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
class LinkedList
{
    private:
    Node*head;
    public:
    LinkedList()
    {
        head=NULL;
    }
    void insert(int val)
    {
        Node*p=new Node(val);
        if(head==NULL)
        {
            head=p;
        }
        else
        {
            Node*q=head;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=p;
        }
    }
    void remove(int val)
    {
        Node*p=NULL;
        Node*q=head;
        if(q!=NULL&&q->data==val)
        {
            p=head;
            head=head->next;
            delete p;
            return;
        }
        while(q->next!=NULL)
        {
            if(q->next->data==val)
            {
                p=q->next;
                q->next=p->next;
                delete p;
                return;
            }
            q=q->next;
        }
        cout<<endl<<"value:"<<val<<" not found in the list.\n";
    }
    void display()
    {
        cout<<endl<<"linked list";
        Node*q=head;
        while(q!=NULL)
        {
            cout<<q->data<<"->";
            q=q->next;
        }cout<<"NULL\n";
    }
};
int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.remove(40);
    list.display();
    list.remove(60);
    list.display();
    list.remove(100);
    list.display();
    return 0;
}

/*PS D:\pranav wakchure> cd "d:\pranav wakchure\" ; if ($?) { g++ tempCodeRunnerFile.cpp -o tempCodeRunnerFile } ; if ($?) { .\tempCodeRunnerFile }

linked list10->20->30->NULL

linked list10->20->30->50->60->NULL

linked list10->20->30->50->NULL

value:100 not found in the list.

linked list10->20->30->50->NULL
PS D:\pranav wakchure> 