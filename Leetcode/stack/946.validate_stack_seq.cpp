bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
    int n = pushed.size();
    stack<int>st;
    int i=0,k=0;
    for(i=0; i<n; i++)
    {
        if(k<n)
        {
            st.push(pushed[i]);
        }

        while(st.size()>0 and st.top() == popped[k])
        {
            st.pop();
            k++;
        }
    }
    if(i==k)
    {
        return true;
    }

    return false;
}