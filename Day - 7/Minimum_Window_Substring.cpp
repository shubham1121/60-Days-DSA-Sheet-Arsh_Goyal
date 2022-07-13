// T.C -: O(N) S.C -: O(K) k is the size of map Sliding window approach Two pointers approach hashing
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    { 
        unordered_map<char,int> mpp;
       int count=0;
       for(int i=0;i<p.length();i++){
           mpp[p[i]]++;
       }
       count=mpp.size();
       int j=0,i=0,start;
       string ans="";
       int len=INT_MAX;
       while(j<s.length()){
           
           if(mpp.find(s[j])!=mpp.end()){
               mpp[s[j]]--;
               if(mpp[s[j]]==0){
                   count--;
               }
           }
           
           while(count==0){
               if(len>j-i+1){
                   len=j-i+1;
                   ans=s.substr(i,len);
               }
               if(mpp.find(s[i])!=mpp.end()){
                   mpp[s[i]]++;
                   if(mpp[s[i]]==1)count++;
               }
               i++;
           }
           
           j++;
       }
       return len!=INT_MAX ? ans : "-1" ;
    }
};