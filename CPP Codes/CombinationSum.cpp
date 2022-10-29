//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.



class Solution {
public:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        // base case
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        // recursive case
        // pickup the element
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findCombination(ind, target-arr[ind], arr, ans, ds);
            ds.pop_back();
        }
        
        // not pickup
        findCombination(ind+1, target, arr, ans, ds);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};