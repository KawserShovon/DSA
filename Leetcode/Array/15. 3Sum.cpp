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





vector<vector<int>> targetSumUniqueTriplet(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());

    for(int i=0; i<arr.size()-2; i++)
    {
        if((i>0) and (arr[i]==arr[i-1]))
        {
            continue;
        }

        int left = i+1, right = arr.size()-1;

        while(left<right)
        {
            int sum = arr[i] + arr[left]+ arr[right];
            vector<int>ret;
            if(sum == target)
            {
                ans.push_back({arr[i],arr[left],arr[right]});
                left++;
                while(left<right and arr[left] == arr[left-1])
                {
                    left++;
                }

                right--;
                while(left<right and arr[right] == arr[right+1])
                {
                    right--;
                }
            }
            else if(sum>target)
            {
                right--;
            }
            else 
            {
                left++;
            }
        }
    }

    return ans;
}



int main()
{
    file_in_out();

    int n;cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++){cin>>arr[i];}
    int target;
    cin>>target;

    vii ans = targetSumUniqueTriplet(arr,target);
    display2d(ans);
  

}
