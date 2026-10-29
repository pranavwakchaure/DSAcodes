#include <iostream>
using namespace std;
int G[20][20], visited[20],n;
void DFS(int i)
{
    int j;
    cout << i << " ";
    visited[i]=1;
    for (j=0;j<n;j++)
    {
        if (!visited[j] && G[i][j]==1)
        {
            DFS(j);
        }
    }
}
int main()
{
    int i,j;
    cout<<"Enter the number of vertices:";
    cin>>n;
    if (n<1||n>20)
    {
        cout<<"Invalid number of vertices!";
        return 1;
    }
    cout <<"Enter the adjacency matrix of the graph:\n";
    for (i=0;i<n;i++)
    {
        for (j = 0; j < n; j++)
        {
            cin>>G[i][j];
        }
    }
    for (i=0;i<n;i++)
    {
        visited[i] = 0;
    }
    cout <<"DFS traversal is:\n";
    for (i=0;i<n;i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
    cout << endl;
    return 0;
}

/*PS D:\pranav wakchure> cd "d:\pranav wakchure\" ; if ($?) { g++ tempCodeRunnerFile.cpp -o tempCodeRunnerFile } ; if ($?) { .\tempCodeRunnerFile }
Enter the number of vertices: 4
Enter the adjacency matrix of the graph:
1 0 1 1
0 1 0 1
1 1 1 0
0 0 1 0
DFS traversal is:
0 2 1 3 
PS D:\pranav wakchure> 