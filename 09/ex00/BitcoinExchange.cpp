#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename){
    std::fstream f(filename, std::ios_base::in);

    if (!f.is_open())
    {
        std::cerr << "Warning: can not open " << '\"' << filename << '\"' << std::endl;
        return ;
    }
    while (!(f.fail() || f.eof()))
    {
        std::string line;
        getline(f, line);
        bool is_record = true;
        for (size_t i = 0; is_record && i < 4; i++)
        {
            if (!isdigit(line[i]))
                is_record = false;
        }
        if (is_record && line[4] != '-')
            is_record = false;
        for (size_t i = 5; is_record &&  i < 7; i++)
        {
            if (!isdigit(line[i]))
                is_record = false;
        }
        if (is_record && memcmp(line.substr(5, 2).c_str(),"12", 2) > 0)
            is_record = false;
        if (is_record && line[7] != '-')
            is_record = false;
       for (size_t i = 8; is_record &&  i < 10; i++)
        {
            if (!isdigit(line[i]))
                is_record = false;
        }
        if (is_record \
        && (!memcmp(line.substr(5, 2).c_str(),"01", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"03", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"05", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"07", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"08", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"10", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"12", 2))\
        && memcmp(line.substr(8, 2).c_str(),"31", 2) > 0)
                is_record = false;
        else if (is_record \
        && (!memcmp(line.substr(5, 2).c_str(),"04", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"06", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"09", 2)\
            ||!memcmp(line.substr(5, 2).c_str(),"11", 2))
        && memcmp(line.substr(8, 2).c_str(),"30", 2) > 0)
                is_record = false;
        else if (is_record \
        && atoi(line.substr(2, 2).c_str()) % 4
        && !memcmp(line.substr(5, 2).c_str(),"02", 2)
        && memcmp(line.substr(8, 2).c_str(),"28", 2) > 0)
                is_record = false;
        else if (is_record \
        && !memcmp(line.substr(2, 2).c_str(),"00", 2)
        && !memcmp(line.substr(5, 2).c_str(),"02", 2)
        && memcmp(line.substr(8, 2).c_str(),"28", 2) > 0)
                is_record = false;
        else if (is_record \
        && !memcmp(line.substr(5, 2).c_str(),"02", 2)
        && memcmp(line.substr(8, 2).c_str(),"29", 2) > 0)
            is_record = false;
        if (is_record && line[10] != ',')
                is_record = false;
        size_t i = 11;
        for (; is_record && line[i]; i++)
        {
            if (line[i] == '.')
                break;
            if (!isdigit(line[i]))
                is_record = false;
        }
        if (is_record && i <= 11)
            is_record = false;
        for (size_t ii = i + 1; is_record && line[i] == '.' && line[ii]; ii++)
        {
            if (!isdigit(line[ii]))
                is_record = false;
        }
        double value;
        if (is_record)
            value =  atof(line.substr(11, line.size() - 11).c_str());
        if (is_record && value < 0)
            is_record = false;   
        if (is_record)
            this->database[line.substr(0,10)] = value;
        else if (line != "date,exchange_rate" && line.size())
            std::cerr << "Warning: bad data \"" << line << "\"" << std::endl;
    }
    f.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &dest){
    *this = dest;
}


BitcoinExchange const & BitcoinExchange::operator=(const BitcoinExchange & dest){
    this->database = dest.database;
    return (*this);
}


float BitcoinExchange::exchange(std::string date, float value){
    return(this->database[date] * value);
}

std::string BitcoinExchange::exchange_record(std::string line){
    bool is_record = true;
    for (size_t i = 0; is_record && i < 4; i++)
    {
        if (!isdigit(line[i]))
            is_record = false;
    }
    if (is_record && line[4] != '-')
        is_record = false;
    for (size_t i = 5; is_record &&  i < 7; i++)
    {
        if (!isdigit(line[i]))
            is_record = false;
    }
    if (is_record && memcmp(line.substr(5, 2).c_str(),"12", 2) > 0)
        is_record = false;
    if (is_record && line[7] != '-')
        is_record = false;
   for (size_t i = 8; is_record &&  i < 10; i++)
    {
        if (!isdigit(line[i]))
            is_record = false;
    }
    if (is_record \
    && (!memcmp(line.substr(5, 2).c_str(),"01", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"03", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"05", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"07", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"08", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"10", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"12", 2))\
    && memcmp(line.substr(8, 2).c_str(),"31", 2) > 0)
        is_record = false;
    else if (is_record \
    && (!memcmp(line.substr(5, 2).c_str(),"04", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"06", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"09", 2)\
        ||!memcmp(line.substr(5, 2).c_str(),"11", 2))
    && memcmp(line.substr(8, 2).c_str(),"30", 2) > 0)
        is_record = false;
    else if (is_record \
    && atoi(line.substr(2, 2).c_str()) % 4
    && !memcmp(line.substr(5, 2).c_str(),"02", 2)
    && memcmp(line.substr(8, 2).c_str(),"28", 2) > 0)
        is_record = false;
    else if (is_record \
    && !memcmp(line.substr(2, 2).c_str(),"00", 2)
    && !memcmp(line.substr(5, 2).c_str(),"02", 2)
    && memcmp(line.substr(8, 2).c_str(),"28", 2) > 0)
        is_record = false;
    else if (is_record \
    && !memcmp(line.substr(5, 2).c_str(),"02", 2)
    && memcmp(line.substr(8, 2).c_str(),"29", 2) > 0)
        is_record = false;
    if (is_record && memcmp(line.substr(10, 3).c_str(), " | ", 3))
        is_record = false;
    size_t i = 13;
    if (line[13] == '-')
        i++;
    for (; is_record && line[i]; i++)
    {
        if (line[i] == '.')
            break;
        if (!isdigit(line[i]))
            is_record = false;
    }
    if (is_record && (i <= 13 || (i <= 14 && line[13] == '-')))
        is_record = false;
    size_t ii = i + 1;
    for (; is_record && line[i] == '.' && line[ii]; ii++)
    {
        if (!isdigit(line[ii]))
            is_record = false;
    }
    if (!is_record)
        return (std::string("Error: bad input => ") + line);
    double value = atof(line.substr(13, line.size() - 13).c_str());
    if (value < 0)
        return(std::string("Error: not a positive number."));
    if (value > 1000 + 0L)
        return(std::string("Error: too large a number."));
    if (this->database.find(line.substr(0, 10)) == this->database.end())
        return (std::string("Error: no data => ") + line.substr(0, 10));
    ii -= 13;
    std::stringstream rtn;
    rtn << line.substr(0, 10) << " => " << line.substr(13, ii) << " = " << this->exchange(line.substr(0, 10), value);
    return (rtn.str());
}


BitcoinExchange::~BitcoinExchange(){}
