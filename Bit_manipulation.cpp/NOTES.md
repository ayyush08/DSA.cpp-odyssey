# 🧮 Bit Manipulation Cheat Sheet

## 1️⃣ Odd / Even Check
- **Check if n is odd:**

    ```
    n & 1
    ```
- `1` if odd
- `0` if even

---

## 2️⃣ Check if i-th Bit is Set
- **Is the i-th bit set?**
  ```
  (n >> i) & 1
  ```

- Returns `1` if i-th bit is set
- Returns `0` otherwise
- *Alternative:*
  ```
  n & (1 << i)
  ```

---

## 3️⃣ Unset (Clear) the i-th Bit
- **Clear i-th bit to 0:**
```
n & ~(1 << i)
```

---

## 4️⃣ Toggle the i-th Bit
- **Flip i-th bit (0→1 or 1→0):**
```
n ^ (1 << i)
```

---

## 5️⃣ Check if n is a Power of Two
- **True if n is power of 2:**
```
n > 0 and (n & (n - 1)) == 0
```

---

## 6️⃣ Unset Rightmost Set Bit
- **Remove the lowest 1-bit in n:**
```
n & (n - 1)
```

## 7️⃣ Keep only the rightmost set bit:
```
n & -n OR n= n & ~(n - 1)
```

## 8️⃣ Number of Set Bits in N (Hamming Weight)
- **Count set bits in n:**
```
count = 0
while n:
    count += n & 1
    n >>= 1
```
Or using STL:
```
__builtin_popcount(n)
```

## 9️⃣ For any integer appearning n times (a^a^a^...^a till n times)
- **Result is a if n is odd, 0 if n is even:**
```