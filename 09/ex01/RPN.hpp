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
#define T printf("[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define T_ printf("---------------------------------------------[(%s/%d) %s ]\n", __FILE__, __LINE__, __func__); fflush(stdin);
#define Tn(i) printf("[(%s/%d) %s ]%s:%ld\n", __FILE__, __LINE__, __func__, #i, (long)(i)); fflush(stdin);
#define Tu(i) printf("[(%s/%d) %s ]%s:%lu\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Tx(i) printf("[(%s/%d) %s ]%s:%lx\n", __FILE__, __LINE__, __func__, #i, (unsigned long)(i)); fflush(stdin);
#define Td(i) printf("[(%s/%d) %s ]%s:%lf\n", __FILE__, __LINE__, __func__, #i, (double)(i)); fflush(stdin);
#define Tp(i) printf("[(%s/%d) %s ]%s:%p\n", __FILE__, __LINE__, __func__, #i, (void *)(i)); fflush(stdin);
#define Ts(i) printf("[(%s/%d) %s ]%s:%s\n", __FILE__, __LINE__, __func__, #i, (char *)(i)); fflush(stdin);
#define Tc(i) printf("[(%s/%d) %s ]%s:%c\n", __FILE__, __LINE__, __func__, #i, (char)(i)); fflush(stdin);
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
#include <string>
#include <stack>
#include <sstream>
#include <ostream>

class RPN
{
private:
    std::string answer;
    bool err;
    RPN();
public:
    RPN(std::string);
    RPN(RPN const &);
    RPN const &operator=(RPN const&);
    void calculate(std::string);
    std::string get_answer() const;
    ~RPN();
};