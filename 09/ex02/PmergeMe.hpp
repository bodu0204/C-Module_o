
#pragma once
#include <sys/time.h>
#include <string>
#include <sstream>
#include <vector>
#include <list>

class PmergeMe
{
private:
    std::string result;
    double time_diff();
    PmergeMe();
public:
    PmergeMe(int, char *[]);
    PmergeMe(PmergeMe const &);
    PmergeMe const &operator=(PmergeMe const &);
    template <typename T> void sort(T &);
    std::string get_result();
    ~PmergeMe();
};

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(PmergeMe const &src){*this = src;}
PmergeMe const &PmergeMe::operator=(PmergeMe const &src){this->result = src.result; return *this;}
PmergeMe::PmergeMe(int argc, char *argv[])
{
    std::stringstream output;
    std::vector<int>v;
    std::list<int>l;
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
        l.push_back(n);       
    }
    double tv, tl;
    this->time_diff();
    this->sort(v);
    tv = this->time_diff();
    this->sort(l);
    tl = this->time_diff();
    output << "\nAfter:\t";
    for (size_t i = 0; i < v.size(); i++)
    {
        output << v[i] << " ";
    }
    output << "\n";
    output << "Time to process a range of " << v.size() << "elements with std::vector<int>\t:\t" << tv / 1000 << " us\n";
    output << "Time to process a range of " << l.size() << "elements with std::list<int>\t:\t" << tl / 1000 << " us";
    this->result = output.str();
    return ;
}

template <typename T>
void PmergeMe::sort(T &nms)
{
    if (nms.size() <= 16)
    {
        for (size_t i = 1; i < nms.size(); i++)
        {
            T::iterator it = nms.bigin();
            for (size_t j = i; j && it[j] < it[j - 1]; j--)
            {
                int tmp = it[j];
                it[j] = it[j - 1];
                it[j - 1] = tmp;
            }
        }
    }
    T a, b;
    a.assign(nms.begin(), nms.begin() + (nms.size() / 2  + nms.size() % 2 - 1));
    sort(a);
    b.assign(nms.begin() + (nms.size() / 2 + nms.size() % 2), nms.end());
    sort(b);
    size_t i(0), ai(0), bi(0);
    T::iterator it = nms.bigin();
    T::iterator ita = a.bigin();
    T::iterator itb = b.bigin();
    for (; ai < a.size() && bi< b.size(); i++)
        it[i] = ita[ai] < itb[bi] ? ita[ai++] : itb[bi++];
    for (; ai < a.size(); i++)
        it[i] = ita[ai++];
    for (; ai < bi< b.size(); i++)
        it[i] = itb[bi++];
    return ;
}

double	PmergeMe::time_diff(void)
{
	static struct timespec	p = {0};
	struct timespec			n;
	unsigned int			sec;
	int						nsec;

	clock_gettime(CLOCK_REALTIME, &n);
	sec = n.tv_sec - p.tv_sec;
	nsec = n.tv_nsec - p.tv_nsec;
	p = n;
	return ((double)sec + (double)nsec / (1000 * 1000 * 1000));
}

std::string PmergeMe::get_result(){return (this->result);}


PmergeMe::~PmergeMe(){}
