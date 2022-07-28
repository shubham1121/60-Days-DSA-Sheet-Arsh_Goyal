class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        stack<pair<int, int>> in_stk_p, in_stk_n;
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector<int> left(a.size()), right(a.size());
		
    //initialize
    for(int i = 0; i < a.size(); i++) left[i] =  i + 1;
    for(int i = 0; i < a.size(); i++) right[i] = a.size() - i;
		
    for(int i = 0; i < a.size(); i++){
      // for previous less
      while(!in_stk_p.empty() && in_stk_p.top().first > a[i]) in_stk_p.pop();
      left[i] = in_stk_p.empty()? i + 1: i - in_stk_p.top().second;
      in_stk_p.push({a[i],i});
			
      // for next less
      while(!in_stk_n.empty() && in_stk_n.top().first > a[i]){
        auto x = in_stk_n.top();in_stk_n.pop();
        right[x.second] = i - x.second;
      }
      in_stk_n.push({a[i], i});
    }

    long long int ans = 0, mod = 1e9 +7;
    for(int i = 0; i < a.size(); i++){
      ans = (ans + (a[i]%mod)*((left[i]%mod)*(right[i]%mod))%mod)%mod;
    }
    return ans;
    }
};