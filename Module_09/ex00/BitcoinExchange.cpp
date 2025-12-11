#include "BitcoinExchange.hpp"
#include <iomanip>


std::map<std::string, std::string> loadDatabase(const char *filename, char n) {
    std::fstream fs;
    std::map<std::string, std::string> db;

    fs.open (filename);
    if (!fs.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string data;
    try {
        std::getline(fs, data);
        while (std::getline(fs, data)) {
            std::string::iterator it;

            it = std::find(data.begin(), data.end(), n);
           
            if (it != data.end())
                *it = ' ';
            else
                continue;
            std::stringstream ss;
            ss << data;
            std::string key;
            std::string value;
            ss >> key >> value;
            db[key] = value;
        }
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
    fs.close();
    return db;
}

void checkDateParts(std::string date, std::string dateToPrint) {
    std::stringstream ss;
    ss << date;

    int year, month, day;
    ss >> year >> month >> day;
    if (ss.fail() && !ss.eof())
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if (year < 0)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if (month < 1 || month > 12)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if (day < 1 || day > 31)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if (month == 2 && day > 29)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
}

void validateDate(std::string date, std::string dateToPrint) {
    std::string::iterator it;

    it = std::find(date.begin(), date.end(), '-');
    
    if (it != date.end())
        *it = ' ';
    else
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    it = std::find(date.begin(), date.end(), '-');
    
    if (it != date.end())
        *it = ' ';
    else
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    if (date.size() >= 11)
        throw std::runtime_error("Error: bad input => " + dateToPrint);
    try {
            checkDateParts(date, dateToPrint);
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

float calculate(std::map<std::string, std::string> db, std::string date, double value) {
    std::map<std::string, std::string>::iterator it = db.lower_bound(date);

    if (it == db.end()) {
        it = --db.end();
    } else if (it->first != date) {
        if (it != db.begin())
            --it;
    }
    float rate;
    std::stringstream ss;
    ss << it->second;
    ss >> rate;
    return rate * value;
}

std::string formatResult(float f) {
    std::ostringstream oss;

    // with default
    oss << std::fixed << std::setprecision(2) << f;
    std::string s = oss.str();
    
    // Remove trailing zeros
    size_t dot = s.find('.');
    if (dot != std::string::npos) {
        int i = s.length() - 1;
        while (i > (int)dot && s[i] == '0') {
            i--;
        }
        s.erase(i + 1);
        if (s[s.length() - 1] == '.') {
            s.erase(s.length() - 1);
        }
    }
    
    return s;
}

void process(std::map<std::string, std::string> db, const char *filename) {
    std::fstream fs;
    fs.open (filename);
    if (!fs.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string input;
    std::getline(fs, input);
    while (std::getline(fs, input)) {
        std::string::iterator itn;
        itn = std::find(input.begin(), input.end(), '|');
        if (itn != input.end())
            *itn = ' ';
        else {
            std::cerr << "Error: bad input => " << input << std::endl;
            continue;
        }
        std::string date;
        double value;
        std::stringstream ss;
        ss << input;
        ss >> date >> value;

        if (ss.fail() && !ss.eof()) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        else if (value < 0){
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        try {
            validateDate(date, date);
            float result = calculate(db, date, value);
            std::cout << date << " => " << value << " = " << formatResult(result) << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

}