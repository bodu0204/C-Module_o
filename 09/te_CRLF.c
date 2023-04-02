//version:2.0.0

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
#define FORn(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (long)(i[test_arg])); fflush(stdin);}}
#define FORu(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (unsigned long)(i[test_arg])); fflush(stdin);}}
#define FORx(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (unsigned long)(i[test_arg])); fflush(stdin);}}
#define FORd(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (double)(i[test_arg])); fflush(stdin);}}
#define FORp(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (void *)(i[test_arg])); fflush(stdin);}}
#define FORs(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (char *)(i[test_arg])); fflush(stdin);}}
#define FORc(i,j) {for(size_t test_arg = 0; test_arg j; test_arg++){printf("[(%s/%d) %s ]%s[%zu]:%ld\n", __FILE__, __LINE__, __func__, #i, test_arg, (char)(i[test_arg])); fflush(stdin);}}
#define TAKE(i,j) {static size_t test_arg = 0; if(!(test_arg % j)){i} test_arg++;}
#define STOP {char c; read(STDIN_FILENO, &c, sizeof(char));}

#endif


int main ()
{
    Tc('\n')
    Tn('\n')
    Tc('\r')
    Tn('\r')
    T
    printf("0123456789");fflush(stdout);
    sleep(1);
    printf("\r");fflush(stdout);
    sleep(1);
    printf("a");fflush(stdout);
    printf("\n");fflush(stdout);
    T
    
}