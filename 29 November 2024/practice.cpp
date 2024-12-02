#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex mtx;

void problematicFunction() {
    mtx.lock();  // Lock acquired
    std::cout << "Mutex locked\n";
    throw std::runtime_error("Something went wrong!");  // Exception thrown
    mtx.unlock();  // Unlock skipped because of the exception
}

int main() {
    try {
        problematicFunction();
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }

    // Another thread trying to lock mtx may deadlock
    if (mtx.try_lock()) {
        std::cout << "Mutex successfully re-locked\n";
        mtx.unlock();
    } else {
        std::cout << "Mutex is still locked!\n";
    }
    return 0;
}
