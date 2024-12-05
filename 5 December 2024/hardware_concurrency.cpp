// Hardware concurrency refers to the number of threads that can run 
// simultaneously on the hardware (CPU cores). It represents the hardware's 
// parallel execution capabilities, which include physical cores and, in the 
// case of hyper-threading, logical cores.

#include <iostream>
#include <thread>

using namespace std;

int main() {
    unsigned int numCores = thread::hardware_concurrency();
    
    if (numCores > 0) {
        cout << "Number of concurrent threads supported: " << numCores << endl;
    } else {
        cout << "Unable to determine hardware concurrency." << endl;
    }

    return 0;
}

// Physical Cores vs Logical Cores:

// Physical cores are the actual hardware units capable of executing instructions.
// Logical cores (threads) arise due to technologies like hyper-threading (common in Intel CPUs), which allow a single physical core to run multiple threads.

// A 4-core CPU with hyper-threading supports 8 logical threads.
// A 6-core CPU without hyper-threading supports 6 logical threads.