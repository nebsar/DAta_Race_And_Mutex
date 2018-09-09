/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.h
 * Author: Eagleye
 *
 * Created on September 9, 2018, 6:16 PM
 */

#ifndef LOGFILE_H
#define LOGFILE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <mutex>

using namespace std;

class LogFile {
    std::mutex m_mutex;
    ofstream f; // Never return f to outside world;

public:
    LogFile();
    ~LogFile();
    void shared_print(string, int);
    // Never return f to outside world
    // For example:

    ofstream& getStream() {
        return f;
    }
    // Never pass f as an argument to user function. For example:

    void processf(void func(ofstream&)) {
        func(f);
    }

};

#endif /* LOGFILE_H */

