class Solution {
public:
bool dfs_cycle(int src, vector<vector<int>>& graph, vector<bool>&visited, vector<bool>&vispath)
{
    visited[src] = true;
    vispath[src] = true;

    for(auto nbr:graph[src])
    {
        if(!visited[nbr])
        {
            if(dfs_cycle(nbr,graph,visited,vispath))
            {
                return true;
            }
        }
        else if(visited[nbr] and vispath[nbr])
        {
            return true;
        }
    }
    vispath[src] = false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int V = graph.size();

    vector<bool> visited(V,0);
    vector<bool>vispath(V,0);

    vector<int>ans;
    for(int i=0; i<V; i++)
    {
       
            if (!dfs_cycle(i,graph,visited,vispath))
            {
                ans.push_back(i);
            }
       
        
    }

    return ans;
}





};