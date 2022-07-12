//T.C -: O(N*M) S.C -: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        for(int i=0;i<=m-n;i++)
        {
            if(haystack[i]==needle[0])
            { 
              int j;
                for(j=0;j<needle.length();j++)
                { if(haystack[i+j]!=needle[j])
                  { 
                    break;
                  }
                }
             if(j==needle.length())
             {
                 return i;
             }
            }
        }
        return -1;
        
    }
};