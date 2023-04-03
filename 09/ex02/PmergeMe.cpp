#include "PmergeMe.hpp"


PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &src){*this = src;}
PmergeMe const &PmergeMe::operator=(PmergeMe const &src){this->result = src.result; return *this;}
PmergeMe::PmergeMe(int argc, char *argv[])
{
    std::stringstream output;
    std::vector<int>v;
    std::deque<int>d;
    output << "Before:\t";
    for (size_t i = 1; i < static_cast<size_t>(argc); i++)
    {
        std::string str(argv[i]);
        int n = 0;
        for (size_t i = 0; str[i]; i++)
        {
            if (n > INT32_MAX / 10)
            {
                this->result = "Error";
                return ;
            }
            n *= 10;
            if (isdigit(str[i]) && !(n == (INT32_MAX / 10) * 10 && str[i] - '0' > INT32_MAX % 10))
            {
                n += str[i] - '0';
            }
            else
            {
                this->result = "Error";
                return ;
            }
        }
        output << n << " ";
        v.push_back(n);
        d.push_back(n);       
    }
    time tv, td;
    this->sort(v, tv);
    this->sort(d, td);
    output << "\nAfter:\t";
    for (size_t i = 0; i < v.size(); i++)
    {
        output << v[i] << " ";
    }
    output << "\n";
    output << "Time to process a range of " << v.size() << " elements with std::vector<int>\t:\t" << std::setprecision(4) \
    << static_cast<double>(tv.ti + tv.tm) / 1000 / 1000 << " us " \
    << " (i:" << static_cast<double>(tv.ti) / 1000 / 1000 << "," \
    << "m:" << static_cast<double>(tv.tm) / 1000 / 1000 << ")\n";
    output << "Time to process a range of " << d.size() << " elements with std::deque<int>\t:\t" << std::setprecision(4) \
    << static_cast<double>(td.ti + td.tm) / 1000 / 1000 << " us " \
    << " (i:" << static_cast<double>(td.ti) / 1000 / 1000 << "," \
    << "m:" << static_cast<double>(td.tm) / 1000 / 1000 << ")";
    this->result = output.str();
    return ;
}


long	PmergeMe::time_diff(void)
{
	static struct timespec	p;
	struct timespec			n;
	long			        sec;

	clock_gettime(CLOCK_REALTIME, &n);
	sec = static_cast<double>(n.tv_sec - p.tv_sec) * (1000 * 1000 * 1000);
	sec += static_cast<double>(n.tv_nsec - p.tv_nsec);
	p = n;
	return (sec);
}

std::string PmergeMe::get_result(){return (this->result);}


PmergeMe::~PmergeMe(){}
PmergeMe::time::s_time():ti(0), tm(0){}
