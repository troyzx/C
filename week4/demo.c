#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double fRand(double fMin, double fMax);
int main(){
    double a = fRand(0,1);
    printf("%lf",a);
    return 0;
}
double fRand(double fMin, double fMax){
    srand(time(NULL));
    double f = (double)rand()/RAND_MAX;
    return fMin + f*(fMax-fMin);
}