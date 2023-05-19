class Solution
{
    public:
        int closing (string s, int pos)
        {
            int cnt = 0;
            for(int i=0; i<s.length(); i++)
            {
                if(i>=pos)
                {
                    if(s[i]=='[')
                    {
                        cnt++;
                    }
                    else if(s[i]==']')
                    {
                        cnt--;
                    }
                    if(cnt==0)
                    {
                        return i;
                    }
                }
            }
            return 0;
        }
};