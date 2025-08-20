# Bit Manipulation Tricks and Techniques

## 1. Swapping Two Numbers Without a Third Variable
**Description**: Efficiently swap two numbers using XOR operator without a temporary variable.

**Example**:
- Given: A = 5, B = 6
- Steps:
    1. A = A ^ B (A becomes 3)
    2. B = A ^ B (B becomes 5) 
    3. A = A ^ B (A becomes 6)

**Code**:
```cpp
// Swap using XOR
A = A ^ B
B = A ^ B
A = A ^ B
```

**Complexity**:
- Time: O(1)
- Space: O(1)

## 2. Checking if the i-th Bit is Set
**Description**: Check if i-th bit is set using shift operators.

**Example**:
- Given: N = 13 (1101), i = 2
- Left Shift: (1 << 2) & 13 = 4 (bit is set)
- Right Shift: (13 >> 2) & 1 = 1 (bit is set)

**Code**:
```cpp
bool isBitSet(int n, int i) {
        return (n & (1 << i)) != 0;
        //OR
        return (n >> i) & 1;
}
```

**Complexity**:
- Time: O(1)
- Space: O(1)

## 3. Setting the i-th Bit
**Description**: Set i-th bit to 1 using OR operator.

**Example**:
- Given: N = 9 (1001), i = 2
- Result: 9 | (1 << 2) = 13 (1101)

**Code**:
```cpp
int setBit(int n, int i) {
        return n | (1 << i);
}
```

## 4. Clearing the i-th Bit
**Description**: Clear i-th bit using AND operator.

**Example**:
- Given: N = 13 (1101), i = 2
- Result: 13 & ~(1 << 2) = 9 (1001)

**Code**:
```cpp
int clearBit(int n, int i) {
        return n & ~(1 << i);
}
```

## 5. Toggling the i-th Bit
**Description**: Toggle i-th bit using XOR operator.

**Example**:
- Given: N = 13 (1101), i = 1
- Result: 13 ^ (1 << 1) = 15 (1111)

**Code**:
```cpp
int toggleBit(int n, int i) {
        return n ^ (1 << i);
}
```

## 6. Removing the Last Set Bit
**Description**: Remove rightmost set bit using AND operator.

**Example**:
- Given: N = 13 (1101)
- Result: 13 & (13-1) = 12 (1100)

**Code**:
```cpp
int removeLastSetBit(int n) {
        return n & (n - 1);
}
```

## 7. Checking if a Number is Power of 2
**Description**: Check if number is power of 2 using AND operator.

**Example**:
- Given: N = 16
- Result: 16 & 15 = 0 (is power of 2)

**Code**:
```cpp
bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
}
```

## 8. Counting Set Bits
### Basic Approach
**Description**: Count set bits using loop and AND operator.

**Code**:
```cpp
int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
                count += (n & 1);
                n >>= 1;
        }
        return count;
}
```

**Complexity**:
- Time: O(logN)
- Space: O(1)

### Optimized Approach
**Description**: Count set bits by turning off rightmost set bit.

**Code**:
```cpp
int countSetBits(int n) {
        int count = 0;
        while (n) {
                n &= (n - 1);
                count++;
        }
        return count;
}
```

**Complexity**:
- Time: O(K) where K is number of set bits (O(31) at max for 32-bit integers)
- Space: O(1)
