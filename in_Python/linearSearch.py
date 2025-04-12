# linearSearch.py
# This script implements a linear search algorithm in Python.
# complexity: O(n)
def linear_search(arr, target):
 
  for index, element in enumerate(arr):
    if element == target:
      return index
  return -1
