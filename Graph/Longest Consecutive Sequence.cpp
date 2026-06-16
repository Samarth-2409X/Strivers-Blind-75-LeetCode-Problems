class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));

        int ans = 0;

        for(auto num: s){
            if(s.find(num - 1) != s.end()){
                continue;
            }

            int curr = num;
            int count = 0;

            while(s.find(curr) != s.end()){
                curr++;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};



