
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
        adj[v].push_back(u);
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






bool dfs(int src, int parent, vector<int>adj[], vector<bool> &visited)
{
    visited[src] = true;

 
    for(auto nbr:adj[src])
    {   
        if(!visited[nbr])
        {
            //this has to be checked ****
            if(dfs(nbr,src,adj,visited))
            {
                return true;
            }
        }
        else if(parent != nbr) // it means, visited[nbr] and parent != nbr
        {
            return true;
        }

   
    }
    
    
    return false;
}



bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V,0);
    // bool ans =  dfs_helper(0,-1,adj,visited);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1,adj,visited))
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
    // adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;

    if(isCycle(v,adj))
    {
        cout<<"have cycle"<<endl;
    }
    else 
    {
        cout<<"no cycle"<<endl;
    }
  

}
