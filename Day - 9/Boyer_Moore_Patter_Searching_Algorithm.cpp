// T.C -: O(N*M)  S.C -: O(1)
#include<bits/stdc++.h>
using namespace std;
int badMatchTable[257];
void printAllOccurance(string &text,int n,string &pat,int m){
    int start=0,end=m-1;
    while(end<n)
    {
        int j = m-1;
        while(j>=0 && text[start+j]==pat[j])
        {j--;}
        if(j<0)
        {
            cout<<"Pattern found at idx "<<start<<endl;
            end += 1;
            start+=1;
        }
        else
        { 
            end = badMatchTable[(int) text[start+j]]==-1 ? start+j + badMatchTable[256] : end + badMatchTable[(int) text[start+j]] ;
            start = end-m+1;
        }

    }
}
int main()
{ string text = "AABAACAADAABAABA";
  string pat = "AABA";
  int n=text.length(), m = pat.length();
  for(int i=0;i<257;i++)
  {badMatchTable[i]=-1;}
  for(int i=0;i<m;i++)
  {
    badMatchTable[(int)pat[i]] = max(1,m-i-1);
  }
  badMatchTable[256]=m;
  printAllOccurance(text,n,pat,m);
    return 0;
}