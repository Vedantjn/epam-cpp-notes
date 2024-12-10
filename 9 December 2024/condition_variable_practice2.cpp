//Condition Variable in c++ threading
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m1;
long balance = 0;

void addMoney(int money){
  lock_guard<mutex> lg(m1);
  balance+=money;
  cout << "Amount added and the current balance is " << balance << endl;
  cv.notify_one();
}

void withDrawMoney(int money){
  unique_lock<mutex> ul(m1);
  cv.wait(ul,[] { return balance != 0 ? true:false; });
  if(balance >= money){
    balance -= money;
    cout << "Amount dedeuted: " << money << endl;
  }else{
    cout << "Low in balance and this amount can't be dedeucted: " << money << endl;
  }
  cout << "Current balance is: " << balance << endl;
}

int main(){
  thread t1(withDrawMoney,600);
  thread t2(addMoney,500);

  t1.join();
  t2.join();

  return 0;
}

// Amount added and the current balance is 500
// Low in balance and this amount can't be dedeucted: 600
// Current balance is: 500