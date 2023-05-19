// Add your code here
// }


vector<int>diagonalSum(Node* root)
{
    vector<int> ans;
    vector<vector<int>>anshelper;

    if(root == nullptr) return ans;

    queue<Node*>q;
    q.push(root);

    while(q.size()>0)
    {
        int size = q.size();
        vector<int>tmp;
        for(int i=0; i<size; i++)
        {
            Node* node = q.front();
            q.pop();
            

            while(node != nullptr)
            {
                tmp.push_back(node->data);

                //don't check if(node->left)
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }

                node = node->right;
            }
        }
        anshelper.push_back(tmp);
    }

    for(int i=0; i<anshelper.size(); i++)
    {
        int sum = 0;
        //always use anshelper[i]// don't forget the i
        for(int j=0; j<anshelper[i].size(); j++)
        {
            sum += anshelper[i][j];
        }
        ans.push_back(sum);
    }

    return ans;
}