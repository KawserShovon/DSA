

//Modulo inverse of 1 to N

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
#include<numeric>


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




int moduloInverse(int a, int m)
{
    for(int i=1; i<m; i++)
    {
        //if(a*i)%m == 1
        if((a*i)%m == 1%m)
        {
            return i;
        }
    }
    return 0;
}

struct Triplet
{
    int gcd;
    int x,y;
};

Triplet extended_gcd(int a, int b)
{
    if(b==0)
    {
        Triplet ans ;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }   


    Triplet tempans = extended_gcd(b,a%b);
    Triplet ans;
    ans.gcd = tempans.gcd;
    ans.x = tempans.y;
    ans.y = tempans.x - (a/b)*tempans.y;

    return ans;

}
int efficientModuloInverse(int a, int m)
{
    Triplet ans = extended_gcd(a,m);

    if(ans.gcd != 1)
    {
        cout<<"Inverse doesn't exists"<<endl;
        exit(0);
        // return 0;
    }

    return (ans.x%m + m)%m; //for -ve output we have to take the mod
    // return ans.x;
    
}

int main()
{
    file_in_out();

    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
    {
        cout<<efficientModuloInverse(i,m)<<endl;
        cout<<moduloInverse(i,m)<<endl;
    }





}
    

