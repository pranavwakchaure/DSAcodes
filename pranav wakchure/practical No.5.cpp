#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    void insert(int val)
    {
        Node* p = new Node(val);
        if (head == nullptr)
        {
            head = p;
            return;
        }
        Node* q = head;
        while (q->next != nullptr)
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
    void remove(int val)
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node* q = head;
        if (q->data == val)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete q;
            return;
        }
        while (q != nullptr)
        {
            if (q->data == val)
            {
                q->prev->next = q->next;
                if (q->next != nullptr)
                {
                    q->next->prev = q->prev;
                }
                delete q;
                return;
            }
            q = q->next;
        }
        cout << "Value " << val << " not found in the list.\n";
    }
    void displayForward()
    {
        Node* q = head;
        cout << "Forward: ";
        while (q != nullptr)
        {
            cout << q->data << " <-> ";
            q = q->next;
        }
        cout << "NULL\n";
    }
    void displayBackward()
    {
        Node* q = head;
        if (q == nullptr)
        {
            cout << "Backward: NULL\n";
            return;
        }
        while (q->next != nullptr)
        {
            q = q->next;
        }
        cout << "Backward: ";
        while (q != nullptr)
        {
            cout << q->data << " <-> ";
            q = q->prev;
        }
        cout << "NULL\n";
    }
};
int main()
{
    DoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.displayForward();
    list.displayBackward();
    list.remove(20);
    list.displayForward();
    list.displayBackward();
    return 0;
}
/*PS D:\pranav wakchure> cd "d:\pranav wakchure\" ; if ($?) { g++ tempCodeRunnerFile.cpp -o tempCodeRunnerFile } ; if ($?) { .\tempCodeRunnerFile }
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL
PS D:\pranav wakchure> 