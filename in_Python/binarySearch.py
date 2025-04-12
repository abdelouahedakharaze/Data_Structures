# binarySearch.py
# this script implements a binary search algorithm in Python.
# complexity: O(log n)


def binary_search(arr, target):
  left = 0
  right = len(arr) - 1
  iteration = 0
  
  while left <= right:
    mid = (left + right) // 2
    iteration += 1
    # print(f"left: {left}, right: {right}, mid: {mid}")
    # print(f"arr[mid]: {arr[mid]}, target: {target}")
    # print(f"iteration: {iteration}")
    
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      left = mid + 1
    else:
      right = mid - 1
      
  return -1

# detailed exemple , we are not like others 

hey=[1.2, 3.4, 5.6, 7.8, 9.0]
needle=5.6
binary_search(hey, needle)