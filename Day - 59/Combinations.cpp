//Backtracking
class Solution {
public:
    void generateSubsets(int start,int end, int k, vector<int>&currCombinations,vector<vector<int>>&subsets)
    { if(currCombinations.size()==k) // if the current vector contains size k then add it to ans & return
        { subsets.push_back(currCombinations);
          return;
        }
        for(int i=start;i<=end;i++) // generating all subsets in range start to end
        {   
            currCombinations.push_back(i); // adding a subset to the currentlist
            generateSubsets(i+1,end,k,currCombinations,subsets); //calling for next range
            currCombinations.pop_back(); //removing the added substring
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>subsets;
        vector<int>currCombination;
        generateSubsets(1,n,k,currCombination,subsets);
        return subsets;
    }
};