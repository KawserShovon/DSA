class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    class cmp
    {
        public:
            bool operator()(vector<int>&a, vector<int>&b)
            {
                return a[1]<b[1];
            }
    };
    
    int activitySelection(vector<int> &start, vector<int> &finish, int n)
    {
               
        vector<vector<int>>activity(n,vector<int>(2));
        for(int i=0; i<n; i++)
        {
            activity[i][0] = start[i];
            activity[i][1] = finish[i];
        }
    
        cmp sortCol;
        sort(activity.begin(),activity.end(),sortCol);
    
    
    
        int cntjob =1;
        int lastfinish = activity[0][1];
        for(int i=1; i<n; i++)
        {
        
            if(activity[i][0]>lastfinish)
            {
                cntjob++;
                lastfinish = activity[i][1];
            }
        }
    
        return cntjob;
    }
};