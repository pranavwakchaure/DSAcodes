#include<iostream>
#include<string>
using namespace std;
class student
{
    private:
    string name;
    int rollno;
    char division;
    public:
    void getData()
    {
        cout<<"enter student name";
        cin.ignore();
        getline(cin,name);
        cout<<"enter roll no:";
        cin>>rollno;
        cout<<"enter div:";
        cin>>division;
    }
    void displayData()
    {
        cout<<"\nstudent details"<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"roll no:"<<rollno<<endl;
        cout<<"division:"<<division<<endl;
    }
};
    int main()
    {
    student s;
    s.getData();
    s.displayData();
    return 0;
    }
