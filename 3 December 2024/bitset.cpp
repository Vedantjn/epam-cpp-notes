// std::bitset is a container that represents a fixed-size sequence of bits. 
// It provides operations for bit manipulation such as setting, flipping, and 
// testing bits. It's part of the <bitset> header.

#include <bitset>
#include <iostream>

using namespace std;

int main() {
    bitset<8> b1; // Default: All bits are 0
    bitset<8> b2(5); // From an integer: 00000101
    bitset<8> b3(string("10101")); // From a binary string: 00010101

    cout << "b1: " << b1 << endl;
    cout << "b2: " << b2 << endl;
    cout << "b3: " << b3 << endl;

    return 0;
}

// b1: 00000000
// b2: 00000101
// b3: 00010101

// ================================

#include <bitset>
#include <iostream>

using namespace std;

int main() {
    bitset<8> b("00001111"); // Initialize with binary string

    cout << "Original: " << b << endl;

    b.set(2); // Set the 2nd bit (0-based index)
    cout << "After set(2): " << b << endl;

    b.reset(3); // Reset (clear) the 3rd bit
    cout << "After reset(3): " << b << endl;

    b.flip(0); // Flip the 0th bit
    cout << "After flip(0): " << b << endl;

    cout << "Bit at index 4: " << b[4] << endl; // Access bit at index 4

    return 0;
}

// Original: 00001111
// After set(2): 00001111
// After reset(3): 00000111
// After flip(0): 00000110
// Bit at index 4: 0

// ================================

#include <bitset>
#include <iostream>

using namespace std;

int main() {
    bitset<8> b("11001010");

    cout << "Bitset: " << b << endl;

    cout << "Number of 1s: " << b.count() << endl; // Count of set bits
    cout << "Total size: " << b.size() << endl; // Size of the bitset

    cout << "Is bit 3 set? " << (b.test(3) ? "Yes" : "No") << endl;

    return 0;
}

// Bitset: 11001010
// Number of 1s: 4
// Total size: 8
// Is bit 3 set? Yes