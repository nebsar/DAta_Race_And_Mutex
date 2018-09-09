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

using namespace std;

class LogFile {
    std::mutex m_mutex;
    ofstream f;

public:
    LogFile();
    void shared_print(string, int);
};

#endif /* LOGFILE_H */

