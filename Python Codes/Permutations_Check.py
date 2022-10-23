'''Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.'''

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        permutations = []
        counter = Counter(nums)
        def findAllPermutations(res):
            if len(res) == len(nums):
                permutations.append(res)
                return 
            
            for key in counter:
                if counter[key]:
                    counter[key]-=1 # decrement visited key
                    findAllPermutations(res + [key])    
                    counter[key]+=1 # restore the state of visited key to find the next path
                
        findAllPermutations([])
        return permutations
