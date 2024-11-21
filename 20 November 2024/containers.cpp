/*
Containers in C++: 
Containers are a part of the C++ Standard Template Library (STL) and are broadly classified into two main types:

Sequence Containers
Associative Containers
Each container type is designed for specific use cases, offering different trade-offs in terms of time complexity (TC) and space complexity (SC).

1. Sequence Containers
Sequence containers store elements in a linear fashion and are optimized for sequential access.

+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| Container      | Description                                 | Time Complexity (TC) for Key Operations         | Space Complexity (SC)           |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::vector    | Dynamic array with contiguous storage       | Insertion at end: O(1) (amortized),            | O(n) for data.                 |
|                |                                             | O(n) for resizing                              | Extra space for growth         |
|                |                                             | Access: O(1)                                    |                                |
|                |                                             | Insertion/deletion elsewhere: O(n)              |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::deque     | Double-ended queue, allowing efficient      | Access: O(1)                                   | O(n) for data                  |
|                | insertion and deletion at both ends         | Insertion/deletion at ends: O(1)               |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::list      | Doubly linked list, optimized for frequent | Access: O(n)                                   | O(n) + overhead for pointers   |
|                | insertions and deletions                    | Insertion/deletion: O(1) at known positions    |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::forward_  | Singly linked list, lightweight            | Access: O(n)                                   | O(n) + lower pointer overhead  |
| list           | alternative to std::list                    | Insertion/deletion: O(1) at known positions    |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+

2. Associative Containers
a. Ordered Associative Containers
These maintain keys in sorted order (using a binary search tree, typically Red-Black Tree).

+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| Container      | Description                                 | Time Complexity (TC) for Key Operations         | Space Complexity (SC)           |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::map       | Ordered key-value pairs, with unique keys   | Search: O(logn)                                | O(n)                           |
|                |                                             | Insertion/Deletion: O(logn)                     |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::set       | Stores unique elements in sorted order      | Search: O(logn)                                | O(n)                           |
|                |                                             | Insertion/Deletion: O(logn)                     |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::multimap  | Allows duplicate keys but maintains order   | Same as std::map                               | O(n)                           |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::multiset  | Allows duplicate elements but maintains     | Same as std::set                               | O(n)                           |
|                | order                                       |                                                 |                                |
+----------------+---------------------------------------------+------------------------------------------------+--------------------------------+

b. Unordered Associative Containers
These do not maintain order but provide average O(1) time complexity for search, insertion, and deletion (via hash tables).

+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| Container          | Description                                 | Time Complexity (TC) for Key Operations         | Space Complexity (SC)           |
+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::unordered_map | Hash table-based key-value pairs with      | Search/Insertion/Deletion: O(1) average,        | O(n)                           |
|                    | unique keys                                 | O(n) worst-case                                |                                |
+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::unordered_set | Hash table-based collection of unique      | Same as std::unordered_map                     | O(n)                           |
|                    | elements                                    |                                                |                                |
+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::unordered_    | Hash table-based key-value pairs allowing  | Same as std::unordered_map                     | O(n)                           |
| multimap           | duplicate keys                             |                                                |                                |
+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+
| std::unordered_    | Hash table-based collection allowing       | Same as std::unordered_set                     | O(n)                           |
| multiset           | duplicate elements                         |                                                |                                |
+--------------------+---------------------------------------------+------------------------------------------------+--------------------------------+

Container Selection Guide
When to Use Sequence Containers:

std::vector:
- Frequent random access is required
- Append operations dominate (insertions at the end)

std::deque:
- Insertions and deletions occur at both ends

std::list or std::forward_list:
- Frequent insertions and deletions in the middle of the container
- Iteration is sequential, and random access is not needed

When to Use Associative Containers:

Ordered Containers (std::map, std::set):
- Data needs to be stored in sorted order
- Logarithmic access time is acceptable

Unordered Containers (std::unordered_map, std::unordered_set):
- Fast access is needed without regard to order
- Can tolerate occasional hash collisions causing linear performance

Performance Analysis: Ordered vs Unordered

+------------------+--------------------------------+------------------------------------------------+
| Metric           | Ordered Containers             | Unordered Containers                           |
+------------------+--------------------------------+------------------------------------------------+
| Key Lookup       | O(logn)                        | O(1) average, O(n) worst-case                 |
| Memory Usage     | Higher (due to tree structure) | Lower (hash table structure)                  |
| Insertion Time   | O(logn)                        | O(1) average, O(n) worst-case                 |
| Order of Elements| Sorted                         | Unordered                                     |
| Iteration        | In-order traversal             | Arbitrary order                               |
+------------------+--------------------------------+------------------------------------------------+
*/