# How to identify Digit DP Problems

Digit DP (Dynamic Programming on Digits) is a specialized technique used to solve problems related to counting or optimizing numbers based on their digit properties. Here are some key indicators that a problem may be suitable for Digit DP:

- Given a range, find count/sum of numbers satisfying certain digit properties. and constraingts are large (up to 10^18 or more).
- Problems that involve counting numbers with specific digit constraints (e.g., no consecutive digits, sum of digits, etc.).
- Problems that require finding the k-th number with certain digit properties.
- Problems that involve leading zeros or specific digit placements.
- Problems that require checking properties of numbers based on their digits (e.g., palindromic numbers, numbers with specific digit patterns).
- Problems that involve digit transformations or modifications (e.g., changing digits to achieve a certain property).
- Problems that require optimization based on digit properties (e.g., maximizing or minimizing a number with certain digit constraints).
- Problems that involve counting numbers with specific digit restrictions (e.g., no repeated digits, specific
    digit frequencies).

# States
In Digit DP, the states typically represent the following components:

- **idx**: The current position in the digit array (from most significant to least significant)(left to right).
- **tight**: A boolean flag indicating whether the current prefix of the number being formed is still bounded by the corresponding prefix of the upper limit number. If `tight` is true, the next digit can only go up to the digit in the upper limit at that position; otherwise, it can go up to 9.
- **prev**: The previous digit chosen (useful for problems with constraints on consecutive digits).