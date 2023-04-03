
//version:2.1.0

#ifndef DEBUG_H
#define DEBUG_H
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#define TEST(msg) printf("[(%s/%d) %s ]%s\n", __FILE__, __LINE__, __func__, ((char *)msg)); fflush(stdin);
#define TEST_(msg) printf("---------------------------------------------[(%s/%d) %s ]%s\n", __FILE__, __LINE__, __func__, ((char *)msg)); fflush(stdin);
#define TESTn(msg, i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, ((char *)msg), (long)(i)); fflush(stdin);
#define TESTu(msg, i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, ((char *)msg), (unsigned long)(i)); fflush(stdin);
#define TESTx(msg, i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, ((char *)msg), (unsigned long)(i)); fflush(stdin);
#define TESTd(msg, i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, ((char *)msg), (double)(i)); fflush(stdin);
#define TESTp(msg, i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, ((char *)msg), (void *)(i)); fflush(stdin);
#define TESTs(msg, i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, ((char *)msg), (char *)(i)); fflush(stdin);
#define TESTc(msg, i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, ((char *)msg), (char)(i)); fflush(stdin);
#define Te printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define Te_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define Ten(i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stdin);
#define Teu(i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Tex(i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Ted(i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stdin);
#define Tep(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stdin);
#define Tes(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define Tec(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
#define FORn(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (long)(x[i])); fflush(stdin);}printf("\n");}
#define FORu(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (unsigned long)(x[i])); fflush(stdin);}printf("\n");}
#define FORx(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (unsigned long)(x[i])); fflush(stdin);}printf("\n");}
#define FORd(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (double)(x[i])); fflush(stdin);}printf("\n");}
#define FORp(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (void *)(x[i])); fflush(stdin);}printf("\n");}
#define FORs(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (char *)(x[i])); fflush(stdin);}printf("\n");}
#define FORc(x,j) {printf("[(%s/%d) %s ]%s[]:", __FILE__, __LINE__, __func__, #x);for(size_t i = 0; j; i++){printf("%ld,", (char)(x[i])); fflush(stdin);}printf("\n");}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#endif
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

template <typename T>
void PmergeMe::sort(T &nms)
{
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
        return ;
    }
    T a, b;
    a.assign(nms.begin(), nms.begin() + (nms.size() / 2  + nms.size() % 2 - 1));
    sort(a);
    b.assign(nms.begin() + (nms.size() / 2 + nms.size() % 2), nms.end());
    sort(b);
    size_t i(0), ai(0), bi(0);
    for (; ai < a.size() && bi< b.size(); i++)
        nms[i] = a[ai] < b[bi] ? a[ai++] : b[bi++];
    for (; ai < a.size(); i++)
        nms[i] = a[ai++];
    for (; bi< b.size(); i++)
        nms[i] = b[bi++];
    return ;
}
