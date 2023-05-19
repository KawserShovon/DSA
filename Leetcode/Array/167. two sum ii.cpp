

//2 sum target
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

template<typename T>
void display1d(T text)
{
    for(auto x:text)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
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










vector<int> twoSum(vector<int>& arr, int target) {
        
    vector<int>res;
    
    int i =0, j= arr.size()-1;
// sort(arr.begin(),arr.end());


while(i<j)
{
    int sum = arr[i]+arr[j];
    
    

    //to remove duplicates
    if(i != 0 and arr[i]==arr[i-1])
    {
        i++;
        continue;
    }

    

    if(sum == target)
    {
        
        res.push_back(arr[i]);
        res.push_back(arr[j]);
        
        res[0]=99;
      

        i++;j--;
    }
    else if(sum<target)
    {
        i++;
    }
    else 
    {
        j--;
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
   for(int i=0; i<n; i++)
   {
    cin>>arr[i];
   }
    int target;
    cin>>target;
    // targetSumPair2(arr, target);

    vi t = twoSum(arr,target);
    for(auto x:t){cout<<x<<" ";}

}
