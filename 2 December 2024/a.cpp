// Don't run this

#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
 
void createProcess() {
    system("start");  // This will create a new process (open a new command window)
}
 w
int main() {
    std::vector<std::thread> threads;
    // Create 1000 processes (for example)
    for (int i = 0; i < 1000; ++i) {
        threads.push_back(std::thread(createProcess));
    }
 
    for (auto& t : threads) {
        t.join();  // Wait for all threads to finish
    }
 
    std::cout << "Created 1000 processes." << std::endl;
 
    return 0;
}
