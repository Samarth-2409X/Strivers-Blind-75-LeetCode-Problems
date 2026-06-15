class Solution {
public:
    int n;
    vector<vector<int>> result;
    set<vector<int>> s;

    void solve(vector<int>& candidates, int idx, vector<int>& temp, int target){
        if(idx == n || target < 0){
            return;
        }

        if(target == 0){
            if(s.find(temp) == s.end()){
                result.push_back(temp);
                s.insert(temp);
            }

            return;
        }

        temp.push_back(candidates[idx]);
        solve(candidates, idx+1, temp, target - candidates[idx]);
        solve(candidates, idx, temp, target - candidates[idx]);
        temp.pop_back();

        solve(candidates, idx+1, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();

        vector<int> temp;

        solve(candidates,0 , temp, target);

        return result;
    }
};