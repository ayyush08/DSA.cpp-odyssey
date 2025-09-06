## Approaches

1. **Memoization:** Known as “top-down” dynamic programming, it usually solves the problem from the main problem to the base cases.

2. **Tabulation:** Known as “bottom-up” dynamic programming, it solves the problem from the base cases to the main problem.


## Example - Fibonacci Numbers using Memoization

```cpp
int f(int n, vector<int>& dp) {
    // Base case: return n if n is 0 or 1
    if (n <= 1) return n;
    
    // If the value is already calculated, return it
    if (dp[n] != -1) return dp[n];
    
    // Calculate the value and store it in dp array
    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}
```

Time Complexity: O(N) Overlapping subproblems return answers in constant time O(1). Therefore, only 'n' new subproblems are solved, resulting in O(N) complexity.

Space Complexity: O(N) Using recursion stack space and an array, the total space complexity is O(N) + O(N) ≈ O(N).

## Example - Fibonacci Numbers using Tabulation

```cpp
int main() {
    int n = 5; // Fibonacci number to find

    // Initialize dp array with size n + 1
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array using the tabulation method
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Output the nth Fibonacci number
    cout << dp[n] << endl;

    return 0;
}
```

Time Complexity: O(N): Running a simple iterative loop results in O(N) complexity.

Space Complexity: O(N): Using an external array of size n+1, the space complexity is O(N).


## Example -  Fibonacci Numbers using Space Optimization

```cpp
int main() {
    int n = 5; // Fibonacci number to find

    // Edge case: if n is 0, the result is 0
    if (n == 0) {
        cout << 0;
        return 0;
    }

    // Edge case: if n is 1, the result is 1
    if (n == 1) {
        cout << 1;
        return 0;
    }

    int prev2 = 0; // Fibonacci number for n-2
    int prev = 1;  // Fibonacci number for n-1

    // Iterate from 2 to n to find the nth Fibonacci number
    for (int i = 2; i <= n; i++) {
        int cur_i = prev2 + prev; // Current Fibonacci number
        prev2 = prev;             // Update prev2 to the previous Fibonacci number
        prev = cur_i;             // Update prev to the current Fibonacci number
    }

    // Print the nth Fibonacci number
    cout << prev;
    return 0;
}
```

Time Complexity: O(N): Running a simple iterative loop results in O(N) complexity
Space Complexity: O(1): Using only a constant amount of space for variables, the space complexity is O(1).


## Note
Dynamic programming problems can often be identified by the presence of overlapping subproblems and optimal substructure properties. Overlapping subproblems mean that the same subproblems are solved multiple times, and optimal substructure means that the solution to a problem can be composed of solutions to its subproblems. Common applications of dynamic programming include problems related to sequences, such as the longest common subsequence, and optimization problems, such as the knapsack problem.