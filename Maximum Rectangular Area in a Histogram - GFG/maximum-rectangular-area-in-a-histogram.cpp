//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //next smaller to left
     vector <long long> first(long long a[], int n)
    {
      vector<long long> v1;
      stack<pair<long long,int>> s;
      for(int i=0;i<n;i++){
          if(s.size()==0){
              v1.push_back(-1);
          }
          else if(s.top().first<a[i]){
              v1.push_back(s.top().second);
          }
          else{
              while(s.size()!=0&&s.top().first>=a[i]){
                  s.pop();
              }
              if(s.size()==0){
                  v1.push_back(-1);
              }
              else{
                  v1.push_back(s.top().second);
              }
          }
          s.push({a[i],i});
      }
      return v1;
    }
    
    //next smaller to right
    vector <long long> second(long long a[], int n)
    {
      vector<long long> v2;
      stack<pair<long long,int>> s;
      for(int i=n-1;i>=0;i--){
          if(s.size()==0){
              v2.push_back(n);
          }
          else if(s.top().first<a[i]){
              v2.push_back(s.top().second);
          }
          else{
              while(s.size()!=0&&s.top().first>=a[i]){
                  s.pop();
              }
              if(s.size()==0){
                  v2.push_back(n);
              }
              else{
                  v2.push_back(s.top().second);
              }
          }
          s.push({a[i],i});
      }
      reverse(v2.begin(),v2.end());
      return v2;
    }
    
    long long getMaxArea(long long a[], int n)
    {
        vector<long long> v1=first(a,n);        //left
        vector<long long> v2=second(a,n);       //right
    //    vector<long long> v;
        long long res = 0;
        for(int i=0;i<n;i++){
             res=max(res,a[i]*(v2[i]-v1[i]-1));
        }
        return res;
        
    //     for(int i=0;i<n;i++){
    //         v.push_back((v2[i]-v1[i]-1)*a[i]);      //width
            
    //     }
    //   long long x= *max_element(v.begin(), v.end());       //max area
    
    
    //     return x;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends