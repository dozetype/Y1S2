# # def find_median_sorted_arrays(num1, num2):
# import math
# list1 = [0]
# list2 = [1,5,7,9]
# size1 = len(list1)
# size2 = len(list2)
# side = (size1+size2)//2
# left1, left2 = 0, 0
# ans = 0
# right1, right2 = size1, size2
# for i in range(int(math.log(size2+size1))):
#     middle1 = left1 + (right1-left1)//2
#     middle2 = left2 + (right2-left2)//2
#     if(list1[middle1] < list2[middle2]):
#         left1 +=1
#         ans = list1[middle1]
#     else:
#         right2 -= 1
#         ans = list2[middle2]
#     print(list1[middle1], list2[middle2])
# print(ans)
    
    
# # print(middle)
def findMedianSortedArrays(nums1, nums2):
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1
    
    x, y = len(nums1), len(nums2)
    low, high = 0, x
    
    while low <= high:
        partitionX = (low + high) // 2
        partitionY = (x + y + 1) // 2 - partitionX
        
        maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX - 1]
        minRightX = float('inf') if partitionX == x else nums1[partitionX]
        
        maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY - 1]
        minRightY = float('inf') if partitionY == y else nums2[partitionY]
        

        #checking if biggest element in left partition of A is smaller than smallest element in right partition of B
        #checking if biggest element in left partition of B is smaller than smallest element in right partition of A
        if maxLeftX <= minRightY and maxLeftY <= minRightX:
            if (x + y) % 2 == 0:
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2
            else:
                return max(maxLeftX, maxLeftY)
        elif maxLeftX > minRightY:
            high = partitionX - 1
        else:
            low = partitionX + 1

arr1 = [1,3,5,7,9]
arr2 = [2,4,6,8,10]
print(findMedianSortedArrays(arr1, arr2))