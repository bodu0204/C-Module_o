
#pragma once
#include <sys/time.h>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <iomanip>

class PmergeMe
{
private:
    std::string result;
    long time_diff();
    PmergeMe();
    typedef struct s_time
    {
        long ti;
        long tm;
        s_time();
    }time;
    
public:
    PmergeMe(int, char *[]);
    PmergeMe(PmergeMe const &);
    PmergeMe const &operator=(PmergeMe const &);
    template <typename T> void sort(T &, time&);
    std::string get_result();
    ~PmergeMe();
};

template <typename T>
void PmergeMe::sort(T &nms, time& t)
{
    this->time_diff();
    if (nms.size() <= 16)
    {
        for (size_t i = 1; i < nms.size(); i++)
        {
            for (size_t j = i; j && nms[j] < nms[j - 1]; j--)
            {
                int tmp = nms[j];
                nms[j] = nms[j - 1];
                nms[j - 1] = tmp;
            }
        }
        t.ti += this->time_diff();
        return ;
    }
    T a, b;
    a.assign(nms.begin(), nms.begin() + (nms.size() / 2  + nms.size() % 2));
    b.assign(nms.begin() + (nms.size() / 2 + nms.size() % 2), nms.end());
    t.tm += this->time_diff();
    sort(a, t);
    sort(b, t);
    this->time_diff();
    size_t i(0), ai(0), bi(0);
    for (; ai < a.size() && bi< b.size(); i++)
        nms[i] = a[ai] < b[bi] ? a[ai++] : b[bi++];
    for (; ai < a.size(); i++)
        nms[i] = a[ai++];
    for (; bi< b.size(); i++)
        nms[i] = b[bi++];
    t.tm += this->time_diff();
    return ;
}
