class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { //不使用额外空间
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }   
        }
    }

  vector<int> twoSum2(vector<int>& nums, int target) { 
        map<int,int> MapIdx;
        for(int i=0;i<nums.size();i++){
            int find = target - nums[i];
            auto it = MapIdx.find(find);
            if(it != MapIdx.end()){
                return {i,it->second};
            }
            
            MapIdx[nums[i]] = i;
        }
        
        return {};
    }

};
