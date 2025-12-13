#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {

        int i = 0;
        int j = nums.size() - 1;
        std::vector<int> ans;

        int first = -1, last = -1;

        while (i <= j) {
            if(nums[i] == target && nums[j] == target){
                first = i;
                last = j;
                break;
            }
            else if(nums[i] == target) {
                j--;
            }
            else if(nums[j] == target) {
                i++;
            }
            else {
                i++;
                j--;
            }
        }
        ans.push_back(first);
        ans.push_back(last);

        return ans;
    }
};