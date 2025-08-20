# Binary Number System and Bitwise Operations

## 1. Number System Conversions

### 1.1 Decimal to Binary Conversion
- Method: Divide number by 2 repeatedly and collect remainders
- Example (13 to binary):
    ```
    13 ÷ 2 = 6 (rem 1)
     6 ÷ 2 = 3 (rem 0)
     3 ÷ 2 = 1 (rem 1)
     1 ÷ 2 = 0 (rem 1)
    Result (bottom-up): 1101
    ```

```cpp
string decimalToBinary(int n) {
        result = ""
        while(n != 1) {
                if(n % 2 == 1) result += '1'
                else result += '0'
                n = n / 2
        }
        reverse(result)
        return result
}
```
**Complexity:** Time O(logN), Space O(logN)

### 1.2 Binary to Decimal Conversion
- Method: Multiply each bit by power of 2 based on position
- Example (1101 to decimal):
    ```
    1*2³ + 1*2² + 0*2¹ + 1*2⁰
    = 8 + 4 + 0 + 1 = 13
    ```

```cpp
string binaryToDecimal(string str) {
        len = str.length
        val = 1, num = 0
        for(i from len-1 to 0) {
                if(str[i] == '1') num = num + val
                val = val * 2
        }
        return num
}
```
**Complexity:** Time O(n), Space O(1)

## 2. Complement Systems

### 2.1 One's Complement
- Method: Flip all bits
- Example (13):
    ```
    Original:   0000 1101
    One's:      1111 0010
    ```

### 2.2 Two's Complement
- Method: One's complement + 1
- Example (13):
    ```
    Original:   0000 1101
    One's:      1111 0010
    Two's:      1111 0011
    ```

## 3. Bitwise Operators

### 3.1 Basic Operators
| Operator | Symbol | Description |
|----------|--------|-------------|
| AND | & | Both 1 → 1 |
| OR | \| | Any 1 → 1 |
| XOR | ^ | Odd 1s → 1 |
| NOT | ~ | Flips bits | checks -ve after flipping, if yes then stores it's 2's complement otherwise stop

### 3.2 Shift Operators
- Right Shift (>>): 13 >> 1 = 1101 → 0110 (6)
- Left Shift (<<): 13 << 1 = 1101 → 11010 (26)


### 3.3 Examples
```
AND: 13 & 7
        1101
        0111
        ----
        0101 (5)

OR: 13 | 7
        1101
        0111
        ----
        1111 (15)

XOR: 13 ^ 7
        1101
        0111
        ----
        1010 (10)
```

## Key Points:

1.
```cpp
x >> k = x / 2^k
x << k = x * 2^k
```


2. How are negative numbers represented in binary?
The 31st bit is the sign bit. If it's 1, the number is negative.