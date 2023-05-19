int largestRectangleArea(vector<int>&heights)
{
    heights.push_back(0);
    int n = heights.size();

//next smaller element to the left at the start is -1
    stack<int>st;
    st.push(-1);

    int mx = INT_MIN;
 
    for(int i=0; i<n;i++)
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
