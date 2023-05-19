


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



vi count_sort_negative(vi &nums)
{
         int mx = nums[0] ;
        int mn = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }

        for(auto x:nums){cout<<x<<" ";}
        cout<<endl;

        //ultimate max 
        mx = max(mx,abs(mn));
        
        int allottedSize = 2*mx; //important for +ve and -ve input
        cout<<"allotedsize: "<<allottedSize<<endl;

    cout<<"mx: "<<mx<<endl;
        for(int i=0; i<nums.size();i++)
        {
            nums[i] = nums[i]+ mx;
        }
       
       for(auto x:nums){cout<<x<<" ";}
        cout<<endl;

        vector<int> count(allottedSize+1);
        for(int i=0; i<nums.size(); i++)
        {
            count[nums[i]]++;
        }

        int idx = 0;

        for(int i=0; i<=allottedSize; i++)
        {
            for(int j=0; j<count[i]; j++,idx++)
            {
                nums[idx] = i-mx;
            }
        }

        return nums;
}


int main()
{
    file_in_out();

    int n;
    cin>>n;
    vi nums(n);
    REP(i,0,n){cin>>nums[i];}



    vi k = count_sort_negative(nums);
    for(auto x:k){cout<<x<<" ";}


}
