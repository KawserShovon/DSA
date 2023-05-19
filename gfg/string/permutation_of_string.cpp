// print all permutations of string/array (method I)
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


void helper(string ques, string ans, set<string>&res)
{
    if(ques.length()==0)
    {
      
        if(res.find(ans) != res.end())
        {
            return;
        }

        res.insert(ans);
    }

    for(int i=0; i<ques.length(); i++)
    {
        string qlpart = ques.substr(0,i);
        string qrpart = ques.substr(i+1);
        string roq = qlpart + qrpart;
        helper(roq,ans+ques[i],res);
    }

}

vector<string>find_permutation(string s)
{
    vector<string>ans;
    set<string>res;

    
    helper(s,"",res);

    for(auto x:res){ans.push_back(x);}
    
    return ans;

}



int main()
{
    file_in_out();

    string s;
    cin>>s;

    vector<string> ans = find_permutation(s);
    for(auto x:ans){cout<<x<<" ";}cout<<endl;
  

}
