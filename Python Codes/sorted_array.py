# There is an integer array nums sorted in ascending order (with distinct values).

# Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

# Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

# You must write an algorithm with O(log n) runtime complexity.

class Solution:
    def search(self, nums, target)
        l=0
        h=len(nums)-1
        m=(l+h)>>1
        while l<=h:
            if nums[m]==target:
                return m
            elif nums[m]>=nums[l]: #Left Half of Array
                if target<=nums[m] and target>=nums[l]:
                    h=m-1
                else:
                    l=m+1
            else: #Right Half of Array
                if target>=nums[m] and target<=nums[h]:
                    l=m+1
                else:
                    h=m-1
            m=(l+h)>>1
        return -1
