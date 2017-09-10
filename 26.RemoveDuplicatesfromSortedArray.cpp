class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int left=1,right=1;
        int count = 1;
        while(right<nums.size()){
            if(nums[left-1] != nums[right])
                  nums[left++] = nums[right];
            right++;
        }
        
        nums.erase(nums.begin()+left,nums.end());
    
        return left;
    }
};


