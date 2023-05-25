

//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
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



bool dfs(int src,  vector<int>adj[], vector<bool> &visited, vector<bool>&pathvisited)
{
    visited[src] = true;
    pathvisited[src] = true;
    for(auto nbr:adj[src])
    {
        if(!visited[nbr])
        {
            if(dfs(nbr,adj,visited,pathvisited))
            {
                return true;
            }
            
        }
        else if(visited[nbr] and pathvisited[nbr])
        {
            return true;
        }
        
    }
    pathvisited[src] = false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V,0);
    vector<bool> pathvisited(V,0);
    for(int i=0; i<V ;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,adj,visited,pathvisited))
            {
                return true;
            }
        }
    }

    return false;
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





