class Solution {
public:
    



    int countPrimes(int n) {
         vector<bool> sieveArr(n+1,1);
          sieveArr[0] = 0;
    sieveArr[1] = 0;
    int count = 0;
    for(int i=2; i<n; i++)
    {
        if(sieveArr[i] == true)
        {
           
            for(int j=2*i; j<n; j+=i)
            {
                sieveArr[j] = false;

            }
            count++;
        }
    }

    return count;

    }
};