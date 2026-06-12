class Solution {
public:
    int findPivote(vector<int>& nums){
        int l = 0; 
        int r = nums.size() - 1;

        while(l < r){
            int mid = l + (r - l)/2;

            if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }

        return r;
    }

    int binarySearch(int l, int r, vector<int>& nums, int target){

        int idx = -1;

        while(l <= r){
            int mid = l + (r - l)/2;

            if(nums[mid] == target){
                idx = mid;
                break;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return idx;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivote_index = findPivote(nums);

        int idx = binarySearch(0, pivote_index - 1, nums, target);

        if(idx != -1){
            return idx;
        }

        idx = binarySearch(pivote_index, n-1, nums, target);

        return idx;
    }
};