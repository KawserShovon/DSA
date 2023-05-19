
//4 sum (two pointers approach --2 ) faster approach
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





vector<vector<int>> targetSumQuadruple(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> ans;
    set<vector<int>> filter;
    sort(arr.begin(),arr.end());
    for(int i=0; i<=n-4; i++)
    {
        for(int j=i+1; j<=n-3; j++)
        {
            int left = j+1, right = n-1;
            int temp;
            int k = (arr[i]+arr[j])*-1;
           
            if(__builtin_add_overflow(target,k,&temp))
            {
                
                return ans;
            }
            int newTarget = target-(arr[i]+arr[j]);

            while(left<right)
            {
                int sum = arr[left]+arr[right];
               
                if(sum == newTarget)
                {
                    vector<int> v{arr[i],arr[j],arr[left],arr[right]};
                    ans.push_back(v);
                    left++;right--;

                    //skip duplicates arr[left]
                    while(left<right and arr[left-1]==arr[left])
                    {
                        left++;
                    }
                }
                else if(sum>newTarget)
                {
                    right--;
                }
                else 
                {
                    left++;
                }
            }

            //skip duplicates arr[j]
            while(j+1<n and arr[j]==arr[j+1])
            {
                j++;
            }

            //skip duplicates arr[i]
            while(i+1<n and arr[i]==arr[i+1])
            {
                i++;
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

    vii ans = targetSumQuadruple(arr,target);
    display2d(ans);
  

}


