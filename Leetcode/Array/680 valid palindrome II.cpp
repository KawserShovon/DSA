
//valid palindrome 2
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





void validPalindrome2(string s)
{
    int count = 0;
    int res =99999 ;
    for(int i=0, j=s.length()-1; i<=j; i++,j--)
    {
        
        // cout<<"chekcing "<<s[i]<<" " <<s[j]<<endl;
        if(s[i] != s[j] and count == 0)
        {
            
            if(s[i] == s[j-1])
            {
                i--;
            }
            else if(s[i+1]==s[j])
            {
                j++;
            }
            else 
            {
                // cout<<"false"<<endl;
                res = 0;
                // return;
            }


            count++;
        }
        else if(s[i] !=s[j] and count > 0)
        {
            // cout<<"false";
            res = 0;
            break;
            // return;
        }

        
    }

    if(res !=0)
    {
       res = 1; 
    }
    
    // cout<<"true"<<endl;


    // cout<<endl;

    int tres = 99999;
    count =0;
    for(int i=0, j=s.length()-1; i<=j; i++,j--)
    {
        
        // cout<<"checking "<<s[i]<<" " <<s[j]<<endl;
        if(s[i] != s[j] and count == 0)
        {
            
          
            if(s[i+1]==s[j])
            {
                j++;
            }
            else if(s[i] == s[j-1])
            {
                i--;
            }
            else 
            {
                // cout<<"false"<<endl;
                tres = 0;
                // return;
            }


            count++;
        }
        else if(s[i] !=s[j] and count > 0)
        {
            // cout<<"false";
            tres = 0;
            // return;
        }

    }

    if(tres != 0)
    {
        tres = 1;
    }

    int ures  = res | tres;
    
    // if(ures)
    // {
    //     cout<<"true"<<endl;
    // }
    // else 
    // {
    //     cout<<"false"<<endl;
    // }

    return ures;

    
}




int main()
{
    file_in_out();

    string s;
    cin>>s;

    validPalindrome2(s);

}



