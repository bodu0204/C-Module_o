#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
    if (argc < 2 || argc > 4)
    {
        std::cerr << "Error: could not open file."<< std::endl;
        return (1);
    }
    std::fstream f(argv[1], std::ios_base::in);
    if (!f.is_open())
    {
        std::cerr << "Error: could not open file."<< std::endl;
        return (1);
    }
    BitcoinExchange BE(argc == 3 ? argv[2] : RATE_DATABASE_FILE);
    std::string line;
    getline(f, line);
    if (!(f.fail() || f.eof()) && line == "date | value")
    {
        getline(f, line);
        std::cout << BE.exchange_record(line) << std::endl;
    }
    while (!(f.fail() || f.eof()))
    {
        getline(f, line);
        std::cout << BE.exchange_record(line) << std::endl;
    }
    f.close();
    return (0);
}