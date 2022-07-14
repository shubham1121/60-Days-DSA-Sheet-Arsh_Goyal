//T.C -: O(N) S.C -: O(1) can also be solved by using DFA.
class Solution {
public:
    
    bool isInteger(string s){
        if(s.empty())
            return false;
        if(s[0]=='+' or s[0]=='-')
            s = s.substr(1);
        // check atleast one digit
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' and s[i]<='9')
                continue;
            return false;
        }
        
        return !s.empty();
    }
    
    bool isDecimal(string s){
        if(s.empty())
            return false;
        if(s[0]=='+' or s[0]=='-')
            s = s.substr(1);
        
        int cnt = count(s.begin(),s.end(),'.');
        
        if(cnt==1){
            int ind = 0;
            
            for(int i=0;i<s.length();i++){
                if(s[i]=='.'){
                    ind = i;
                    break;
                }
            }
            for(int i=0;i<ind;i++){
                if(s[i]>='0' and s[i]<='9')
                    continue;
                return false;
            }
            
            for(int i=ind+1;i<s.length();i++){
                if(s[i]>='0' and s[i]<='9')
                    continue;
                return false;
            }
            return s.length()>1;
        }
        
        return false;
        
    }
    
    bool isNumber(string s) {
        int cnt = 0;
        int n = s.length();
        
        // check 'e' or 'E' is present or not?
        for(int i=0;i<n;i++)
            cnt+=(s[i]=='e' or s[i]=='E');
        if(cnt>1)
            return false;
        if(cnt){
            // find the position of 'e' or 'E'
            int ind = 0;
            for(int i=0;i<n;i++){
                if(s[i]=='e' or s[i]=='E'){
                    ind = i;
                    break;
                }
            }
            if(!isInteger(s.substr(ind+1)))
                return false;
            
            // take decimal string now
            s = s.substr(0,ind);
        }
        
        // now we have only decimal or integer string, check?
        return isInteger(s) or isDecimal(s);
    }
};