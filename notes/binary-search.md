# Binary Search

*Source File (C++):* leet-code/binary_search.cpp

### Description

Binary search is a type of _search_ algorithm that finds the position of a target
element within a _sorted_ list/array. It uses a _divide & conquer_ approach to
search for its target. The search is designed explicitily to operate on array data
structures.

The algorithm assumes that its input is sorted, it is a pre-condition.

The algorithm seeks the middle point of the list and compares its target to the value at
that position, if the value is less than the target, then it can be assumed that all values
lower than the middle point will also be less, therefore, that half of the list can be
disregarded for the rest of the search, the same logic applies for the case that the value
is greater than the target, but, instead, the upper half is then discarded. The algorithm
repeatedly applies this logic - find middle point, compare to target, return if same/find
middle of left if greater/find middle of right if less. If a target is not found when
the list can no longer be split in half, then the target does not exist in the array.

Binary search is faster than [linear search](https://en.wikipedia.org/wiki/Linear_search) on large arrays simply because linear search
simply because linear search must travers all of its elements to find its target.
For small arrays binary search is generally slower, because its target might be the array's
first or last element, which, because of repeatedly finding the middle point, will be the last
values it compares.

### Time Complexity

The algorithm runs in logarithmic time in its worst case, and constant time, _O_(1),
in its best case. This makes it extremely effecient as the input size grows larger.

- Best case: _O_(0)
- Worst case: _O_(log _n_)
- Average case: _O_(log _n_)

### Space Complexity

The space complexity is always constant time, since the algorithm only needs three
values perform the search, regardless of the size of the input array. In the case of
_binary_search.cpp_: 3 unsigned_longs.

Worst case: _O_(1)

### Mathematical Proof

Given _A_ of _n_ sorted elements with values _A[0], A[1], ..., A[n-1]_, such that
_A[0] <= A[1] <= A[n-1]_, and target value _T_, _binary search_ finds the
first index _I_, where _I_ = _T_.

The procedure is as follows:

1. Set _L_ = 0
2. Set _R_ = _n_ - 1
3. if _L_ > _R_, return unsuccessful
4. Set _m_ to floor(_L_ + _R_) / 2
5. if _A[m]_ < _T_, set _L_ = _m_ + 1, repeat from _Step 2_.
6. if _A[m]_ > _T_, set _R_ = _m_ - 1, repeat from _Step 2_.
7. if _A[m]_ == _T_, return _m_

### Implementation

```python
binary_search(A, n, T):
    L = 0
    R = n - 1
    
    while L <= R:
        m = floor((L + R) / 2)
        if A[m] < T:
            L = m + 1
        elif:
            R = m - 1
        else:
            return m
            
    return -1
```

### Other Names

- Half-Interval Search
- Logarithmic Search
- Binary Chop

### References

- [Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm)

___
