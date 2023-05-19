#include <iostream>
#include <deque>
#include <vector> 
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


vector<int> res;
void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int>dq;
    int curmx = -999999;
    int secmx = -99999;
    for(int i=0; i<k; i++)
    {
       if(dq.size() == 0)
       {
          dq.push_back(arr[i]); 
           
       }
       else 
       {
            while (dq.size()> 0 and arr[i]>dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
       }
  
    }
    res.push_back(dq.front());
    // cout<<"first front: "<<dq.front()<<endl;
    // cout<<"size; "<<dq.size()<<endl;
    for(int i=k; i<n; i++)
    {
        // cout<<"dq front: "<<dq.front()<<endl;
        // cout<<"arr[i]: "<<arr[i]<<endl;
       
        // cout<<i<<"-"<<k<<"-"<<1<<endl;
        // cout<<"arr[i-k]: "<<arr[i-k]<<endl;
        if(dq.front()>= arr[i] and dq.front()==arr[i-k])
        {
            // cout<<"******"<<endl;
            dq.pop_front();
            
            
            
            while(dq.size()>0 and arr[i]>dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);
            res.push_back(dq.front());
        }
        else if(dq.front()>=arr[i])
        {
            res.push_back(dq.front());
            while(dq.size()>0 and arr[i]>dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);           
        }
        else 
        {
            
            res.push_back(arr[i]);
            while(dq.size()>0 and arr[i]>dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(arr[i]);            
        }
    }


    for(auto x:res){cout<<x<<" ";}
    cout<<endl;

    dq.clear();
    res.clear();
 
}

int main(){
  
	file_in_out();
    int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}