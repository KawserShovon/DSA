
//Rearrange characters (the code is correct but judge shows incorrect)
// leetcode version has been accepted
//https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1
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
int gcnt = 0;
void file_in_out()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}


// bool cmp(pair<char,int>&a, pair<char,int>&b)
// {
//     if(a.second==b.second)
//     {
//         return a.first>b.first;
//     }

//     return a.second>b.second;
// }

class Compare
{
    public:
    bool operator()(pair<char,int>&a, pair<char,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }

        return a.second<b.second; 
    }
};

string rearrangeString(string str)
{
    unordered_map<char,int>umap;
    for(int i=0; i<str.length(); i++)
    {
        umap[str[i]]++;
    }

    priority_queue<pair<char,int>, vector<pair<char,int>>, Compare>pq;

    for(auto x:umap)
    {
        pq.push({x.first,x.second});
        
    }

    string ans="";
    pair<char,int>block = pq.top();
    pq.pop();
    ans +=block.first;
    block.second--;

    while(pq.size()>0)
    {
    
        pair<char,int> temp = pq.top();
        pq.pop();
        ans += temp.first;
        temp.second--;

        if(block.second>0)
        {
            pq.push(block);
        }
        block = temp;   

    }

    if(block.second>0)
    {
        return to_string(-1);
    }
  
    return to_string(1);
}


int main()
{
    file_in_out();

    string s;
    cin>>s;
    cout<<rearrangeString(s)<<endl;

}
