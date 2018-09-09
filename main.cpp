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

#include "LogFile.h"

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

void function(LogFile& log) {
    for (int i = 0; i>-100; i--)
        log.shared_print("t1 : ", i);
}

int main(int argc, char** argv) {

    LogFile log;

    thread t1(function, std::ref(log));

    for (int i = 0; i < 100; i++) {
        log.shared_print("Main Thread : ", i);
    }

    t1.join();

    return 0;
}

