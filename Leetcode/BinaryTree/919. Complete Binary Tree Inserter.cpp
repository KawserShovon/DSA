class CBTInserter {
public:
TreeNode* head = nullptr;
TreeNode* nextInptr = nullptr;
queue<TreeNode*>q;

    CBTInserter(TreeNode* root) {
        
        head = root;
        q.push(root);

        while(true)
        {
            TreeNode *top = q.front();

            if(top->left != nullptr)
            {
                q.push(top->left);
            }
            else 
            {
                nextInptr = top;
                break;
            }

            if(top->right != nullptr)
            {
                q.push(top->right);

            }
            else 
            {
                nextInptr = top;
                break;
            }

            q.pop();
             
        }
    }
    
    int insert(int val) {
        
        int tr = nextInptr->val;
        if(nextInptr->left == nullptr)
        {
            TreeNode *node = new TreeNode(val);
            nextInptr->left = node;
            q.push(node);
        }
        else 
        {
            TreeNode *node = new TreeNode(val);
            nextInptr->right = node;
            q.push(node);
           
            nextInptr = q.front();
             q.pop();

            
        }

        return tr;
    }
    
    TreeNode* get_root() {
        return head;
    }
};