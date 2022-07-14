//T.C -: O(N*K*LogK) S.C -: O(N*K) sorting the string and storing as key to a map.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>ump;
        vector<vector<string>>v;
        for(auto &x : strs)
        {
            string temp = x;
            sort(temp.begin(),temp.end());
            ump[temp].push_back(x);
        }
        for(auto &x:ump)
        {
            v.push_back(x.second);
        }
        return v;
    }
};

//T.C -: O(N*K) S.C -: O(N*K) Insead of sorting, use of hashvalue and storing as key to a map.

class Solution {
public:
    
    string hashValue(string s)
    { int charCount[26] = {0};
      for(char &c : s)
      {
          charCount[c - 'a']++;
      }
     string t="";
     for(int i=0;i<26;i++)
     {
         t+=string(charCount[i],i+'a');
     }
        return t;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>ump;
        vector<vector<string>>v;
        for(auto &x : strs)
        {   
            ump[hashValue(x)].push_back(x);
        }
        for(auto &x:ump)
        {
            v.push_back(x.second);
        }
        return v;
    }
};