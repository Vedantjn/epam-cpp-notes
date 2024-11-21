// How Hashing Works
// Hashing is a method to map data (keys) to a fixed-size hash value using a hash function. 
// This hash value is then used to determine the storage location (bucket) in a hash table. 
// The main purpose of hashing is to achieve fast data retrieval, typically in O(1) time in the average case.

// Hash Table
// A hash table is a data structure that stores key-value pairs. It consists of:

// Hash Buckets:
// Each bucket corresponds to a specific index in the hash table.
// A bucket can store one or more elements that hash to the same index (to handle collisions).

// Hash Function:
// Converts a key into a hash value (an integer).
// The hash value is mapped to an index in the hash table using the formula:
// Index = HashValue % TableSize

// Collision Resolution:
// Since different keys may produce the same hash value, collisions are resolved using techniques like separate chaining or open addressing.

// Components of Hashing
// 1. Hash Function
// Converts input data (keys) into a numerical value.
// A good hash function:
// - Distributes keys uniformly across the table.
// - Is deterministic (same input always produces the same hash value).
// - Is efficient to compute.
// Example in C++:
// std::hash<std::string> hashFunction;
// Output the hash of 'apple'
// std::cout << "Hash of 'apple': " << hashFunction("apple") << std::endl;

// 2. Buckets
// A bucket is a storage unit in the hash table.
// The index for each bucket is calculated using the hash function.
// Buckets can store:
// - Single key-value pairs.
// - Multiple key-value pairs (in case of collisions).

// 3. Collision Handling
// Collisions occur when two different keys map to the same bucket.

// a) Separate Chaining
// Each bucket stores a list (or another container) of elements that map to the same bucket.
// Example:
// Hash Table (Bucket Index)
// 0 -> [key1, key2]
// 1 -> [key3]
// 2 -> [key4]
// Separate chaining is the most common collision resolution technique in C++ (std::unordered_map uses it).

// b) Open Addressing
// Instead of storing multiple elements in a bucket, it searches for the next available bucket (probing).
// Types of probing:
// - Linear Probing: Checks the next bucket sequentially.
// - Quadratic Probing: Checks buckets based on a quadratic function.
// - Double Hashing: Uses a second hash function to find the next bucket.

// Hash Table Operations
// Insertion:
// - Compute the hash value of the key.
// - Map the hash value to a bucket index.
// - Insert the key-value pair into the bucket.

// Search:
// - Compute the hash value of the key.
// - Use the hash value to locate the bucket.
// - Search within the bucket for the desired key.

// Deletion:
// - Compute the hash value of the key.
// - Locate the bucket and remove the key-value pair.

// Load Factor and Rehashing
// Load Factor:
// - The ratio of the number of elements to the number of buckets in the hash table.
// Load Factor = Number of Elements / Number of Buckets

// Rehashing:
// - When the load factor exceeds a certain threshold, the hash table grows in size.
// - All existing elements are rehashed and redistributed into the new table.
// Example:
std::unordered_map<int, int> hashMap;
// Set maximum load factor
hashMap.max_load_factor(0.75); 
// Increase the number of buckets to at least 20
hashMap.rehash(20); 

// Hashing with std::unordered_map

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> hashMap;

    // Insert key-value pairs
    hashMap["apple"] = 5;
    hashMap["banana"] = 3;
    hashMap["cherry"] = 7;

    // Access elements
    std::cout << "Value for key 'banana': " << hashMap["banana"] << std::endl;

    // Iterate through elements
    for (const auto& pair : hashMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}

// Output:
// Value for key 'banana': 3
// apple: 5
// banana: 3
// cherry: 7

// Advantages of Hashing
// - Fast Operations: Average case O(1) time complexity for insert, search, and delete.
// - Efficient Storage: Hash tables allow for dynamic resizing and optimal storage.

// Disadvantages of Hashing
// - Collisions: Can degrade performance to O(n) in the worst case.
// - Memory Overhead: Requires extra space for buckets and linked lists (in separate chaining).
// - Order: Hash-based containers like std::unordered_map do not maintain order.

// Visualization of Hashing Process
// Key: "apple"
// Hash Function Output: 175649
// Bucket Index: 175649 % 10 = 9
// "apple" is stored in bucket index 9.
// If "banana" also hashes to 9, it is added to the bucket at index 9 (in case of separate chaining).

// Hashing is a powerful mechanism in C++ to achieve fast and efficient data retrieval, especially in scenarios where quick lookups are essential. 
// The combination of hash functions, buckets, and collision-handling strategies makes it a cornerstone of modern programming.