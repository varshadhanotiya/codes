// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    
    int findPlatform(int arr[], int dep[], int n)
    {
        
    int i = 1, j = 0,max=1,count = 1;   //i = for arrival and j = for departure
    
    sort(arr, arr + n);
    sort(dep, dep + n);

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            i++;
            count++;
            
            if(count > max)
                max = count;
        }
        else
        {
            j++;
            count--;
        }
    }
    return max;
    }
    
    
    
    /*
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int c = 1;
        vector <pair<int,int>> v;
        for(int i=0; i<n; i++)
            v.push_back({arr[i], dep[i]});
        sort(v.begin(), v.end());
        priority_queue <int, vector<int>, greater<int>> pq;
        pq.push(v[0].second);
        for(int i=1; i<n; i++){
            if(pq.top() < v[i].first)
                pq.pop();
            else
                c += 1;
            pq.push(v[i].second);
        }
        return c;
    }
    */
    
    
    /*
    int findPlatform(int arr[], int dep[], int n){
        int d[2400]={0};
        for(int i=0;i<n;i++)
        {
            d[arr[i]]++;
            d[dep[i]+1]--;
        }
        int ans=INT_MIN;
        for(int i=1;i<2400;i++)
        {
            d[i]+=d[i-1];
            ans=max(d[i],ans);
        }
        return ans;
    }
    */
    
    
    /*
    int findPlatform(int a[], int d[], int n)
    {
    sort(a, a + n);
    sort(d, d + n);

    int i = 1, j = 0;

    int pl_cnt = 1;
    while (i < n)
    {
        if (a[i] <= d[j])
        {
            pl_cnt++;
            i++;
        }
        else if (a[i] > d[j])
        {
            i++;
            j++;
        }
    }
    return pl_cnt;
    }
    */
    
    
    /*
    static bool customsort(const pair<int,char> &a,const pair<int,char> &b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
    
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector< pair<int,char> > order;
        
        //inserting all the values of time(arrival and departure)
        //in the vector of pairs.
        for (int i = 0; i < n; i++) {
    
            //if the time is of arrival then we keep second value
            //of pair as 'a' else 'd'.
            order.push_back(make_pair(arr[i], 'a'));
            order.push_back(make_pair(dep[i], 'd'));
        }
    
        //using custom sort vector, first according to time and if time is
        //same for two events, then arrival comes first followed by departure.
        sort(order.begin(),order.end(),customsort);
    
        int result = 1;
        int plat_needed = 0;
        
        //using an iterator on vector of pairs.
        vector< pair<int,char> >::iterator it = order.begin();
    
        for (; it != order.end(); it++) {
            //if the second value of vector element is 'a' which stands
            //for arrival then we add 1 to platform needed else we 
            //subtract 1 from platform needed.
            if ((*it).second == 'a')
                plat_needed++;
            else
                plat_needed--;
            
            //we keep updating the value of result.
            if (plat_needed>result)
                result = plat_needed;
        }
        //returning the minimum number of platforms required.
        return result;
    }
    */
    
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends