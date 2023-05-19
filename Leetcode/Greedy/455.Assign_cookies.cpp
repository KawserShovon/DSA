class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        vector<bool>b(s.size(),0);
        vector<bool>bb(g.size(),0);
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

     int newi = 0, newj=0;
        for(int j=newj; j<s.size(); j++)
        {
            for(int i=newi; i<g.size(); i++)
            {
                if(s[j]>=g[i] and b[j]==false and  bb[i]==false)
                {
                    cnt++;
                   
                    bb[i] = true;
                    b[j] = true;
                    newj = j+1;
                    newi = i+1;
                }
            }
        } 

        int ssize= s.size();
        cnt = min(cnt,ssize);     

    

        return cnt;
    }
};