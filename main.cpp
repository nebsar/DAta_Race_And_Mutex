/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 9, 2018, 5:05 PM
 */

#include <cstdlib>
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;

/*
 * 
 */

mutex mu;

void shared_print(const char* msg, int i) {
    std::lock_guard<std::mutex> guard(mu);
    // mu.lock();
    cout << msg << "  " << i << endl;
    // mu.unlock();
}

void function() {
    for (int i = 0; i>-100; i--)
        shared_print("From t1 : ", i);
}

int main(int argc, char** argv) {

    thread t1(function);

    for (int i = 0; i < 100; i++) {
        shared_print("From Main Thread : ", i);
    }

    t1.join();

    return 0;
}

