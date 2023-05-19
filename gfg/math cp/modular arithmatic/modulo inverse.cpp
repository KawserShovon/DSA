
 
//modulo inverse

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
        if((a*i)%m == 1%m)
        {
            return i;
        }
    }
    return 0;
}




int main()
{
    file_in_out();

    int a,m;
    cin>>a>>m;
  
    cout<<moduloInverse(a,m)<<endl;

}
