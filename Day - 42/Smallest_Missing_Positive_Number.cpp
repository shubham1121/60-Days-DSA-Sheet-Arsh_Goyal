// T.C -: O(N) & S.C -: O(1) just place value at its correct index and ignore 
// greater than n values or -ve values
class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        for(int i=0;i<n;i++){
       if(arr[i]<=0 || arr[i]>n) continue;
       else if(arr[i]==i+1) continue;
       else{
           if(arr[i]==arr[arr[i]-1]) continue;
           swap(arr[i],arr[arr[i]-1]);
           i--;
       }
   }
   for(int i=0;i<n;i++){
       if(arr[i]!=(i+1)) return (i+1);
   }
   return n+1;
    } 
};