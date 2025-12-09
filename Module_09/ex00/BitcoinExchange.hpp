#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <fstream>
#include <algorithm>
#include <sstream>

std::map<std::string, std::string> loadDatabase(const char *filename, char n);
void process(std::map<std::string, std::string> db, const char *filename);