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

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int>indegree(V);
    for(int i=0; i<V;i++)
    {
        for(auto x:adj[i])
        {
            indegree[x]++;
        }
    }


    vector<int>ans;

    queue<int>q;
    for(int i=0; i<V; i++)
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

        ans.push_back(curr);

        for(auto nbr:adj[curr])
        {
            indegree[nbr]--;
            if(indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}

int main()
{
    file_in_out();

    int n;
    cin>>n;
  

}
