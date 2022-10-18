class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        int pp_ans=nums[0];
        int p_ans=max(nums[0],nums[1]);
        int res=p_ans;
        for(int i=2; i<nums.size(); i++){
            res=max(p_ans, pp_ans+nums[i]);
            pp_ans=p_ans;
            p_ans=res;
        }
        return res;
    }
};
//TC : O(n)
//SC : O(1)
