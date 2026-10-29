#include<iostream>
using namespace std;
const int MAX=5;
class stack
{
    private:
    int a[MAX];
    int top;    
    public:
    stack()
    {
        top=-1;
    }
    void push(int x)
    {
        top++;
        a[top]=x;
    }
    int pop(void)
    {
        int x=a[top];
        top--;
        return x;
    }
    int peek(void)
    {
        return a[top];
    }
    int full(void)
    {
        if(top==MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int empty(void)
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display(void)
    {
        for(int i=top;i>=0;i--)
        {
            cout<<endl<<a[i];
        }
    }
};
int main()
{
    int x;
    stack s;
    if(!s.full())s.push(12);
    if(!s.full())s.push(23);
    if(!s.full())s.push(34);
    if(!s.full())s.push(41);
    if(!s.full())s.push(56);
    if(!s.full())s.push(87);
    if(!s.full())s.push(91);
    cout<<"stack elements :";
    s.display();
    if(!s.empty())
    {
        x=s.peek();
        cout<<endl<<"top element is:"<<x;
    }
    return 0;
}

/*PS D:\pranav wakchure> cd "d:\pranav wakchure\" ; if ($?) { g++ tempCodeRunnerFile.cpp -o tempCodeRunnerFile } ; if ($?) { .\tempCodeRunnerFile }
stack elements :
56
41
34
23
12
top element is:56
PS D:\pranav wakchure> 