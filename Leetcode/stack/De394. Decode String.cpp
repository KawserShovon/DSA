#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <deque>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
#include <map>
#include<limits>
#include <cfloat>
#include<numeric>
#define vi vector<int>
#define vii vector<vi>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)
#define ll long long int 
using namespace std;

void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

//no need of this function
void checkst(stack<char>st)
{
    while(st.size()!=0)
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

string decodeString(string s)
{
    stack<char>st;
    string ans ="";
    for(int i=0; i<s.length(); i++)
    {
       
        if(s[i] != ']')
        {
            st.push(s[i]);
        }
        else if(s[i]==']')
        {
            
            string tans="";
            while(st.top() != '[')
            {
                tans += st.top();
                st.pop();
            }
            
            reverse(tans.begin(),tans.end());
            tans +=ans;
            st.pop();

            string c="";
            while(st.size()>0 and st.top()>='0' and st.top()<='9')
            {
                c += st.top();
                st.pop();
            }
         
            reverse(c.begin(),c.end());
            int cnt = stoi(c);
            

            
            for(int i=0; i<cnt; i++)
            {
                for(int j=0; j<tans.size(); j++)
                {
                   st.push(tans[j]); 
                }
                
            }
            
      
   
        }

        
    }
    while(st.size()>0)
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}



int main()
{
    file_in_out();

    // string  s = "3[a]2[bc]";
    // string s = "3[a2[c]]";
    string s = "100[leetcode]";

    string ans = decodeString(s);
    cout<<ans<<endl;

}
