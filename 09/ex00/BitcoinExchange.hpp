#pragma once

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#define RATE_DATABASE_FILE "./data.csv"

class BitcoinExchange
{
private:
    std::map<std::string, float> database;
    BitcoinExchange();
public:
    BitcoinExchange(std::string);
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange const & operator=(const BitcoinExchange &);
    float exchange(std::string, float);
    std::string exchange_record(std::string);
    ~BitcoinExchange();
};
