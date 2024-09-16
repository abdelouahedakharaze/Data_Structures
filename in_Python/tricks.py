# Memoization: Store results of expensive function calls and reuse them to avoid recalculations.
def fib_memo(n, memo={}):
    if n in memo: return memo[n]  # Return stored result if available.
    if n <= 2: return 1  # Base case.
    memo[n] = fib_memo(n-1, memo) + fib_memo(n-2, memo)  # Store result.
    return memo[n]

# Dynamic Programming: Break problems into subproblems (bottom-up).
def fib_dp(n):
    dp = [0] * (n+1)
    dp[1] = dp[2] = 1  # Base cases.
    for i in range(3, n+1):
        dp[i] = dp[i-1] + dp[i-2]  # Build solution bottom-up.
    return dp[n]

# Divide and Conquer: Solve subproblems recursively and combine the results.
def merge_sort(arr):
    if len(arr) <= 1:
        return arr  # Base case: single element.
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])  # Recursively sort left half.
    right = merge_sort(arr[mid:])  # Recursively sort right half.
    return merge(left, right)  # Merge sorted halves.

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

# Greedy Algorithm: Choose the best local option at each step.
def coin_change_greedy(coins, amount):
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if amount == 0: break
        count += amount // coin  # Choose the largest coin possible.
        amount %= coin  # Reduce the amount.
    return count if amount == 0 else -1  # Return -1 if exact change is not possible.

# Backtracking: Explore all possibilities and undo steps if they lead to a dead end.
def solve_n_queens(n):
    board = [["."] * n for _ in range(n)]
    result = []
    
    def is_safe(row, col):
        for i in range(row):
            if board[i][col] == "Q" or \
               col-(row-i) >= 0 and board[i][col-(row-i)] == "Q" or \
               col+(row-i) < n and board[i][col+(row-i)] == "Q":
                return False
        return True
    
    def place_queens(row):
        if row == n:
            result.append(["".join(r) for r in board])  # Store solution.
            return
        for col in range(n):
            if is_safe(row, col):
                board[row][col] = "Q"  # Place queen.
                place_queens(row+1)  # Move to next row.
                board[row][col] = "."  # Backtrack (remove queen).
    
    place_queens(0)
    return result

# Binary Search: Efficiently search sorted data by dividing the range.
def binary_search(arr, target):
    left, right = 0, len(arr)-1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid  # Target found.
        elif arr[mid] < target:
            left = mid + 1  # Search right half.
        else:
            right = mid - 1  # Search left half.
    return -1  # Target not found.

# Sliding Window: Maintain a window to optimize subarray problems.
def max_sum_subarray(arr, k):
    max_sum, window_sum = 0, sum(arr[:k])  # Initial window sum.
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i-k]  # Slide window by adding one element and removing one.
        max_sum = max(max_sum, window_sum)
    return max_sum

# Two Pointers: Use two indices to solve array problems efficiently.
def two_sum_sorted(arr, target):
    left, right = 0, len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return [left, right]  # Return indices of two numbers.
        elif current_sum < target:
            left += 1  # Move left pointer right to increase sum.
        else:
            right -= 1  # Move right pointer left to decrease sum.
    return []  # No solution.

# Recursion: Call the function within itself to solve a smaller instance of the problem.
def factorial(n):
    if n == 0: return 1  # Base case.
    return n * factorial(n-1)  # Recursive step.

# Bit Manipulation: Perform operations using binary representations.
def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0  # Power of two has only one bit set.

# Union-Find (Disjoint Set Union): Manage and merge sets efficiently.
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, p):
        if self.parent[p] != p:
            self.parent[p] = self.find(self.parent[p])  # Path compression.
        return self.parent[p]
    
    def union(self, p, q):
        rootP, rootQ = self.find(p), self.find(q)
        if rootP != rootQ:
            self.parent[rootP] = rootQ  # Union by connecting the roots.

# Topological Sorting: Process tasks with dependencies in order.
from collections import deque
def topological_sort(vertices, edges):
    in_degree = {i: 0 for i in range(vertices)}
    graph = {i: [] for i in range(vertices)}
    
    for u, v in edges:
        graph[u].append(v)
        in_degree[v] += 1
    
    queue = deque([i for i in in_degree if in_degree[i] == 0])
    sorted_order = []
    
    while queue:
        vertex = queue.popleft()
        sorted_order.append(vertex)
        
        for neighbor in graph[vertex]:
            in_degree[neighbor] -= 1
            if in_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return sorted_order if len(sorted_order) == vertices else []  # Return topological order.

# Kadane’s Algorithm: Find maximum sum subarray in O(n).
def max_subarray_sum(arr):
    max_ending_here = max_so_far = arr[0]
    for x in arr[1:]:
        max_ending_here = max(x, max_ending_here + x)  # Choose to continue with current subarray or start a new one.
        max_so_far = max(max_so_far, max_ending_here)  # Track the overall maximum.
    return max_so_far

# Trie: Efficient prefix-based search.
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True
    
    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word
