#ifndef _FISHER_YATES_H_
#define _FISHER_YATES_H_

void print_array(int ary[], int len);

int swap(int * first, int * second);

void fisher_yates (int array[], const int length, int (*random_fcn)());
#endif