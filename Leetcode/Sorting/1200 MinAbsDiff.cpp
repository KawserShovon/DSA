

//HW2 problem-1 Minimum absolute difference (leetcode 1200)

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <list>
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

#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vd vector<double>
#define vdll vector<long double>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPeq(i,a,b) for(int i=a; i<=b; i++)



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


template<typename T>
void display2d(std::vector<std::vector<T>> vec)
{
    for(auto x:vec)
    {
        for(auto y:x)
        {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}



vector<vector<int>> minimumAbsDifference(vector<int>& arr)
{
    sort(arr.begin(),arr.end());
    for(auto x:arr){cout<<x<<" ";}
    int curdiff = INT_MAX;
    // vector<vector<int>> res(arr[arr.size()-1]+1);
    vector<vector<int>> res;
    for(int i=0,j=1; j<arr.size(); i++,j++)
    {
        if(arr[j]-arr[i]<curdiff)
        {
            res.clear();
            curdiff = arr[j]-arr[i];
            vector<int>tmp;
            tmp.push_back(arr[i]);
            tmp.push_back(arr[j]);

            res.push_back(tmp);
        }
        else if(arr[j]-arr[i] == curdiff)
        {
            vector<int>tmp;
            tmp.push_back(arr[i]);
            tmp.push_back(arr[j]);
            res.push_back(tmp);
        }

    }
    return res;
}



int main()
{
    file_in_out();

    int n; 
    cin>>n;

    vi arr(n);
    REP(i,0,n){cin>>arr[i];}
  
    vii res = minimumAbsDifference(arr);
    cout<<endl;
    display2d(res);
}
