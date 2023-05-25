#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;
vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>>&b)
{
    vector<vector<long long>> matrix(2,vector<long long>(2,0));

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            int count = 0;
            for(int k = 0; k<2; k++)
            {
                count  = ( count + a[i][k] * b[k][j])%mod;
            }
            matrix[i][j] = count;
        }
    }
    return matrix;
}

vector<vector<long long>> matrixExponent(vector<vector<long long>> &matrix, long long n)
{
    if(n==1) return matrix;

    vector<vector<long long >> temp = matrixExponent(matrix,n/2);
    vector<vector<long long>> ans = multiply(temp,temp);
    if(n%2 ==1 )
    {
        ans = multiply(ans,matrix);
    }

    return ans;
}


ll countStrings(int N)
{
    vector<vector<long long>> matrix (2,vector<long long>(2,0));
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;

    matrix = matrixExponent(matrix, N);

    return (matrix[0][0] + matrix[0][1]) % mod;

}   

int main()
{

}




ll mod = 1000000007;
class Solution{
public:
    // #define ll long long
    ll countStrings(int n) {
        ll dp0[n+1];
        ll dp1[n+1];
        
        dp0[0] = 0;
        dp1[1] = 1;
        
        dp0[1] = 1;
        dp1[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            dp0[i] = (dp0[i-1]+dp1[i-1])%mod;
            dp1[i] = dp0[i-1];
        }
        
        ll sum = (dp0[n]+dp1[n])%mod;
        
        return sum;
    }
};

