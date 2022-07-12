//T.C -: O(N) && S.C -: O(K) where k is no. of unique elements in string.
void PrintDuplicates(string s)
{ unordered_map<char,int>mp;
  for(int i=0;i<s.length();i++)
  {
    mp[s[i]]++;
  }
  for(auto x:mp)
  {
    if(x.second>1)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
  }

}