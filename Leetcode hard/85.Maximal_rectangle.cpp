int largestRectangleArea(vector<int>&heights)
{
    heights.push_back(0);
    int n = heights.size();

    stack<int>st;
    st.push(-1);

    int mx = INT_MIN;


    for(int i=0; i<n; i++)
    {
        while(st.top()>=0 and heights[i]<=heights[st.top()])
        {
            int r = i;
            int h = heights[st.top()];
            st.pop();
            int l = st.top();
            int area = h*(r-l-1);
            mx = max(mx,area);
        }
        st.push(i);
    }

    return mx;
}

int maximalRectangle( vector<vector<char>> &matrix)
{
    int R = matrix.size();
    int C = matrix[0].size();
    int sum = INT_MIN;

    vector<vector<int>> grid(R,vector<int>(C));
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(matrix[i][j]=='1')
            {
                grid[i][j] = 1;
            }
            else 
            {
                grid[i][j] = 0;
            }
        }
    }

    int area = 0;

    vector<int>curr(C);
    for(int r=0; r<R; r++)
    {
        for(int c=0; c<C; c++)
        {
            if(grid[r][c]==1)
            {
            curr[c] += grid[r][c]; 
            }
            else 
            {
                curr[c] = 0;
            }
            
        }

        int t = largestRectangleArea(curr);
        area = max(area,t);
    }


    return area;
}