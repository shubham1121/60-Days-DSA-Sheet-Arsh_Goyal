// Wherever it is asked to minimise the lenght or dist just use bfs
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans=0;
        unordered_set<string>uset;
        queue<string>q;
        int wordSize = beginWord.length();
        for(string &s : wordList)
        {
            uset.insert(s);
        }
        q.push(beginWord);
        if(uset.find(endWord)==uset.end()) return 0;
        while(!q.empty())
        { ans++;
          int qsize = q.size();
          for(int i=0;i<qsize;i++)
          { string temp = q.front();
            q.pop();
            for(int j=0;j<wordSize;j++)
            { char org = temp[j];
              for(char ch = 'a';ch<='z';ch++)
                { temp[j]=ch;
                  if(temp==endWord) return ans+1;
                  if(uset.find(temp)==uset.end())continue;
                  uset.erase(temp);
                  q.push(temp);
                }
             temp[j]=org;
            } 
          }
        }
        return 0;
    }
};