//T.C -: O(N) S.C -: O(N) stack based solution

class Solution {
public:
    int calculate(string s) {
        int currNumber = 0;
        char operation = '+';
        int n = s.length();
        stack<int>st;
        // cout<<n<<endl;
        for(int i=0;i<n;i++)
        { 
          if(isdigit(s[i]))
          {
              currNumber=currNumber*10 + (s[i]-'0');
              // cout<<currNumber<<endl;
          }
          if((!isdigit(s[i]) && !iswspace(s[i])) || i==(n-1))
          {  
              if(operation=='-')
              {
                  st.push(-currNumber);
              }
              else if(operation == '+')
              { 
                  // cout<<currNumber<<endl;
                  st.push(currNumber);
              }
              else if(operation == '*')
              {
                  int sTop = st.top();
                  st.pop();
                  st.push(sTop*currNumber);
              }
              else if(operation=='/')
              {
                  int sTop = st.top();
                  st.pop();
                  // cout<<sTop<<endl;
                  st.push(sTop/currNumber);
              }
              operation = s[i];
              currNumber=0;
          }
            
        }
        int ans = 0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

//T.C -: O(N) S.C -: O(1)

class Solution {
public:
    int calculate(string s) {
        int currNumber = 0;
        char operation = '+';
        int n = s.length();
        int lastNum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        { 
          if(isdigit(s[i]))
          {
              currNumber=currNumber*10 + (s[i]-'0');
          }
          if((!isdigit(s[i]) && !iswspace(s[i])) || i==(n-1))
          {  
              if(operation=='-' || operation == '+')
              {
                  ans+=lastNum;
                  lastNum = (operation == '+')? currNumber : -currNumber;
              }
              else if(operation == '*')
              {
                  lastNum = lastNum*currNumber;
              }
              else if(operation=='/')
              {
                   lastNum = lastNum/currNumber;
              }
              operation = s[i];
              currNumber=0;
          }
            
        }
        ans+=lastNum;
        return ans;
    }
};