// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        /*
        int result=(n*(n+1)/2);
        int sum=0;
        for(int num:array){
            sum=sum+num;
        }
        return result-sum;
    }
    */
    /*
     sort(array.begin(), array.end());
      for(int i=1; i<n; i++) {
          if(array[i-1]!=i) {
              return i;
          }
      }
    */
    
    /*
      int sum=0;
     int total=(n*(n+1)/2);
     for(int i=0;i<n-1;i++){
         sum=sum+array[i];
     }
      return total-sum;
     */
     
      sort(array.begin(),array.end());
       for(int i=0;i<n;i++){
           if(array[i]!=i+1){
               return i+1;
           }
       }
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends