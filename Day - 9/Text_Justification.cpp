//T.C -: O(N*K) S.C -: O(K) 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string t=""; //string to store each line
        int cnt=0;
        int nwl = 0; //no of words in a line
        vector<string>v;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            if(i==0)  //if first word then it can be added easily
            {
                t+=words[i];
                nwl++;
            }
            else
            {
                if(t.length()+words[i].length()+1<=maxWidth) //if possible to add word on same line
                {
                    t+=" "+words[i];
                    nwl++;
                }
                else
                { int spaces = 0;
                    cnt = maxWidth-t.length();
                        if(nwl==1)  //if a line contains only one word then to add rest of the place with a space
                           {
                               int j = t.length();
                                int spaces = maxWidth-t.length();
                                while(spaces--)
                                {
                                    t.insert(j," ");
                                }
                           }
                         else
                         {
                             spaces = cnt;
                             while(spaces>0)   //adding spaces evenly through a particular line
                             {
                                 for(int j=0;j<t.length()-1;)
                                 {  if(spaces==0)
                                    {
                                     break;
                                    }
                                     if(t[j]==' '&&t[j+1]!=' ')
                                     {
                                         t.insert(j," ");
                                         j+=2;
                                         spaces-=1;
                                     }
                                     else
                                     {
                                         j++;
                                     }
                                 }
                             }
                         } 
                    v.push_back(t); // a line is completed then stored in a vector
                    t=words[i];    //new line initialised 
                 nwl=1;
                }
            }
        }
        if(t!="")
        {
            int j = t.length();
            int spaces = maxWidth-t.length();
            while(spaces--)
            {
                t.insert(j," ");
            }
            v.push_back(t);
        }
        return v;
        
    }
};