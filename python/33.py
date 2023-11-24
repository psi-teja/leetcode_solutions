class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0 
        right = len(nums)-1

        while left <= right:

            mid = left + (right-left)//2

            print (left, right, mid)

            if nums[mid] > target:
                if nums[mid] < nums[left]:    # right sorted array
                    right = mid - 1
                else:                         # left sorted array                     
                    if nums[left] > target:
                        left = mid + 1
                    else:
                        right = mid - 1
                        
            elif nums[mid] < target:
                if nums[mid] > nums[left]:    # left sorted array
                    left = mid + 1
                else:                         # right sorted array
                    if nums[right] < target:
                        right = mid - 1
                    else:
                        left = mid + 1
                                  
            else:
                return mid
            
        return -1
    

print(Solution().search([4,5,6,7,8,1,2,3],8))