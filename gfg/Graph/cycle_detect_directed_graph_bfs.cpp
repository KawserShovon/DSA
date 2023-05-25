

//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// cycle detect directed graph bfs

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
#include <map>
#include <bitset>

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vb vector<bool>
using namespace std;

void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

void buildGraph(int v, int e, vector<int>adj[])
{
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        
    }
}

void printGraph(int v, int e, vector<int>adj[])
{
    for(int i=0; i<e; i++)
    {
        cout<<i<<" -> : ";
        for(auto x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


void indegreeCalc(int src, vector<int>adj[], vector<int>&indegree)
{
    for(auto nbr:adj[src])
    {
        indegree[nbr]++;
    }
}

int bfs(int src,  vector<int>adj[], vector<int> &indegree)
{
    queue<int>q;
    int counter = 0;
    for(int i=0; i<indegree.size(); i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(q.size()>0)
    {
        int curr = q.front();
        q.pop();
        counter++;

        for(auto nbr:adj[curr])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }

    return counter;

}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int>indegree(V);
    for(int i=0; i<V; i++)
    {
        indegreeCalc(i,adj,indegree);
    }
    

    int count = bfs(0,adj,indegree);

    //if topo sort exists then no cycle
    if(count == V) return false;

    //since topo sort doesn't exist, so theres cycle
    return true;
}



int main()
{
    file_in_out();

    int v;
    cin>>v;
    int e;
    cin>>e;

    vector<int>adj[v];
    buildGraph(v,e,adj);
    printGraph(v,e,adj);
 

    if(isCyclic(v,adj))
    {
        cout<<"has cycle"<<endl;
    }
    else 
    {
        cout<<"no cycle"<<endl;
    }
  

}










