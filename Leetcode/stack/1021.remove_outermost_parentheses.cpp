
// //1021. Remove Outermost Parentheses

// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <cstring>
// #include <unordered_map>
// #include <queue>
// #include <deque>
// #include <unordered_set>
// #include <stack>
// #include <set>
// #include <utility>
// #include <iomanip>
// #include <climits>
// #include <map>
// #include<limits>
// #include <cfloat>
// #include<numeric>
// #define vi vector<int>
// #define vii vector<vi>
// #define REP(i,a,b) for(int i=a; i<b; i++)
// #define REPeq(i,a,b) for(int i=a; i<=b; i++)
// #define ll long long int 
// using namespace std;

// void file_in_out()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif
// }


// string removeOuterParentheses(string s)
// {
//     set<int>track;

//     int n = s.length();
//     int b = 0; 
//     track.insert(0);
//     for(int i=0; i<n; i++)
//     {
//         if(s[i]=='(')
//         {
//             b++;
//         }
//         else 
//         {
//             b--;
//         }
//         if(b==0)
//         {
//             track.insert(i);
//             track.insert(i+1);
//         }
        
//     }

//     string ans = "";
//     for(int i=0; i<n; i++)
//     {
//         if(track.find(i) == track.end())
//         {
//             ans+=s[i];
//         }
//     }

//     return ans;
// }

// int main()
// {
//     file_in_out();

//      string s;
//      cin>>s;

//      cout<<removeOuterParentheses(s)<<endl;

// }
