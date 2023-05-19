
class Solution{
  public:
    // vector <int> verticalSum(Node *root) {
    //     // add code here.
    // }
    
    void width(Node* root, int hl, vector<int>&arr)
    {
        if(root == nullptr) return;
    
        arr[0] = min(arr[0],hl);
        arr[1] = max(arr[1],hl);
    
        width(root->left,hl-1,arr);
        width(root->right,hl+1,arr);
    }
    
    class qpair
    {
    public:
        int hl;
        Node* node;
    
        qpair(Node* node, int hl)
        {
            this->node = node;
            this->hl = hl;
        }
    };
    
    vector<int>verticalSum(Node* root)
    {
        if(root ==nullptr) 
        {
            vector<int>t;
            return t;
        }
    
    
        vector<int>arr(2);
        width(root,0,arr);
        int range = arr[1]-arr[0]+1;
    
        vector<int>ans;
        vector<vector<int>>anshelper(range);
        map<int,vector<int>>mp;
    
        queue<qpair>q;
        q.push(qpair(root,abs(arr[0])));
    
        while(q.size()>0)
        {
            int size = q.size();
    
            for(int i=0; i<size; i++)
            {
                qpair tmp = q.front();
                Node *node = tmp.node;
                int hl = tmp.hl;
    
                q.pop();
    
                anshelper[hl].push_back(node->data);
    
                if(node->left)
                {
                    q.push(qpair(node->left,hl-1));
                }
    
                if(node->right)
                {
                    q.push(qpair(node->right,hl+1));
                }
    
    
            }
        }
    
        for(int i=0; i<anshelper.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<anshelper[i].size(); j++)
            {
                sum += anshelper[i][j];
            }
            ans.push_back(sum);
        }
    
        return ans;
    }


};
