
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # Cyclic Sort by ignoring numbers which are less then 1 or greater than or equalt to length of array.
        # This is done because cyclic sort sorts an array in o(n) iff numbers are in a proper range.
        ix = 0
        while ix < len(nums):
            correct = nums[ix] - 1
            if nums[ix] <= 0 or nums[ix] > len(nums) or nums[ix] == nums[correct]:
                ix += 1
            else:
                nums[ix], nums[correct] = nums[correct], nums[ix]
                
		# Now if at any index ix the number present is not equal to ix+1 then return ix+1
        for ix in range(len(nums)):
            if nums[ix] != ix+1:
                return ix+1
		# If all the numbers in the range are already in the array then just return the next number
        return len(nums) + 1

