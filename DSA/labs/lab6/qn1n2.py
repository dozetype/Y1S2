import time
import random

#A (list): The input array of integers.
#size (int): The size of the array.
#K (int): The target sum.
#dual_index (list): A list to store the indices of the two elements.
def dual_search(A, size, K, dual_index):
    for i in range(size):
        for j in range(i, size):
            if(A[i]+A[j] == K):
                dual_index.append(i)
                dual_index.append(j)
                return

# def dual_sorted_search(A, size, K, dual_index):
#     for i in range(size):
#         low = 0
#         high = size
#         while(low<high):
#             mid = (low+high)//2
#             if(A[mid] + A[i] == K):
#                 dual_index.append(i)
#                 dual_index.append(mid)
#                 return
#             elif(A[mid] + A[i] < K):
#                 low = mid+1
#             else:
#                 high = mid-1

def dual_sorted_search(A, size, K, dual_index):
    left = 0
    right = size-1
    while(left<right):
        if(A[left] + A[right] == K):
            dual_index.append(left)
            dual_index.append(right)
            return
        elif(A[left] + A[right] < K):
            left+=1
        else:
            right-=1

#Question 1
A = [3, 1, 7, 4, 5, 9]
K = 8
dual_index = []
dual_search(A, len(A), K, dual_index)
print(dual_index)



#Question 2
dual_index = []
A.sort()
print("Sorted",A)
dual_sorted_search(A, len(A), K, dual_index)
print(dual_index)



# Question 3
#Unsorted Linear search
# A = random.sample(range(1, 11), 10)
# K = 8
# dual_index = []
# startTime = time.time()
# dual_search(A, len(A), K, dual_index)
# print("Question 3:", "Index:", dual_index, "Value:", A[dual_index[0]], A[dual_index[1]], "Time:", time.time()-startTime)

#Sorted binary seach
A = random.sample(range(1, 101), 100)
K = 8
dual_index = []
A.sort()
startTime = time.time()
dual_sorted_search(A, len(A), K, dual_index)
print("Question 3:", "Index:", dual_index, "Value:", A[dual_index[0]], A[dual_index[1]], "Time:", time.time()-startTime)

