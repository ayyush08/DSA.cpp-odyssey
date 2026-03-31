# XOR Linear Basis (Beginner-Friendly Notes)

## 🧠 What is XOR Linear Basis?

XOR Linear Basis is a technique to store a set of numbers in a **compressed form** such that:

* You can generate all possible XOR combinations
* You remove redundant (useless) numbers

---

## 💡 Core Idea

> Keep only those numbers which add new XOR information

If a number can already be formed using existing numbers → ❌ discard it

---

## 🔍 Intuition

Example:

Numbers: `3, 5, 6`

* 6 = 3 ^ 5
* So 6 is not needed

Final basis:

```
{3, 5}
```

---

## ⚙️ How Insert Works

We try to **reduce the number using existing basis**.

### Steps:

1. Go from highest bit → lowest bit
2. If bit is not set → skip
3. If bit is set:

   * If no basis element exists → store it
   * Else → eliminate that bit using XOR

---

## 🧠 Key Insight

> We try to make the number = 0 using existing basis

* If it becomes 0 → already representable → discard
* Else → store it as new basis

---

## 💻 Code Template

```cpp
long long basis[64];

void insert(long long x) {
    for (int i = 63; i >= 0; i--) {
        if (!(x & (1LL << i))) continue;

        if (basis[i] == 0) {
            basis[i] = x;
            return;
        }

        x ^= basis[i];
    }
}
```

---

## ⚡ Find Maximum XOR

```cpp
long long getMax() {
    long long ans = 0;
    for (int i = 63; i >= 0; i--) {
        ans = max(ans, ans ^ basis[i]);
    }
    return ans;
}
```

---

## 📌 Properties

* Basis size ≤ 64
* Time complexity: O(n * 64)
* Stores only independent numbers

---

## 🚀 Common Use Cases

* Maximum XOR subset
* XOR paths in graphs
* Counting distinct XOR values
* Bitmask optimization problems

---

## 🎯 One-Line Summary

> XOR Basis = Keep only numbers that add new XOR possibilities

---

## 🧠 Mental Model

> “Try to kill the number using existing ones.
> If it survives → store it.”
