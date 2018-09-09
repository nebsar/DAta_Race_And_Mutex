/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LogFile.cpp
 * Author: Eagleye
 * 
 * Created on September 9, 2018, 6:16 PM
 */

#include "LogFile.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <mutex>

using namespace std;

LogFile::LogFile() {
    f.open("log.txt");
}

void LogFile::shared_print(string msg, int id) {
    std::lock_guard<std::mutex> locker(m_mutex);
}

