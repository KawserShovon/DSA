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


//build graph for coding ninjas

void buildGraph(int v, int e, vector<vector<int>> &graph)
{
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
}


void printGraph(int v, int e, vector<vector<int>> graph)
{
    for(int i=0; i<e; i++)
    {
        cout<<i<<" -> : ";
        for(auto x:graph[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


bool checkCycle_usingDFS(int src, int parent, vector<vector<int>> &edges, vector<bool>&visited)
{
    visited[src] = true;

    for(auto nbr:edges[src])
    {
        if(!visited[nbr])
        {
            if(checkCycle_usingDFS(nbr,src,edges,visited))
            {
                return true;
            }
        }
        else if(nbr != parent)
        {
            return true;
        }

    }
    return false;
}


void connectedComponents(int src,vector<vector<int>> edges, vector<bool> &visited)
{
    visited[src] = true;
    for(auto nbr:edges[src])
    {
        if(!visited[nbr])
        {
            connectedComponents(nbr,edges,visited);
        }
    }
}

bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<bool> visited(n,0);

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            connectedComponents(i,edges,visited);
            cnt++;
        }
    }
    // cout<<"cnt; "<<cnt<<endl;
    if(cnt>1) 
    {
        
        return false;
    }


    vector<bool> visit(n,0);
    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            //if it doesn't have  a cycle then its a tree
            if(!checkCycle_usingDFS(i,-1,edges,visit))
            {
                return true;
            }
        }
    }

    return false;
}

bool checkCycle_usingDFS(int src, int parent, vector<vector<int>> &edges, vector<bool>&visited)
{
    visited[src] = true;

    for(auto nbr:edges[src])
    {
        if(!visited[nbr])
        {
            if(checkCycle_usingDFS(nbr,src,edges,visited))
            {
                return true;
            }
        }
        else if(nbr != parent)
        {
            return true;
        }

    }
    return false;
}


void connectedComponents(int src,vector<vector<int>> &edges, vector<bool> &visited)
{
    visited[src] = true;
    
    for(auto nbr:edges[src])
    {
        if(!visited[nbr])
        {
            connectedComponents(nbr,edges,visited);
        }
    }
}

void buildGraph(int v, int e, vector<vector<int>> &input, vector<vector<int>>&edges)
{
    for(int i=0; i<e; i++)
    {
        int u,v;
        u = input[i][0];
        v = input[i][1];
        edges[u].push_back(v);
        edges[v].push_back(u);
        
    }
}

void printGraph(int v, int e, vector<vector<int>> graph)
{
    for(int i=0; i<e; i++)
    {
        cout<<i<<" -> : ";
        for(auto x:graph[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

bool checkgraph(vector<vector<int>> input, int n, int m)
{ 


    vector<vector<int>>edges(n);
    buildGraph(n,m,input,edges);
    // printGraph(n,m,edges);
    
    vector<bool> visited(n,0);

    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            connectedComponents(i,edges,visited);
            cnt++;
        }
    }
  
    if(cnt>1) 
    {
        
        return false;
    }


    vector<bool> visit(n,0);
    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            //if it doesn't have  a cycle then its a tree
            if(!checkCycle_usingDFS(i,-1,edges,visit))
            {
                return true;
            }
        }
    }

    return false;
}

