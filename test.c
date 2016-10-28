#include <stdio.h>

void main(int argc,char** argv){

double A[4][4];

double *a_add=&A[0][0];
A[0][0]=10;
printf("address a:%lf, value a: %lf\n",a_add,A[0][0]);

}		