#include<stdio.h>
#include<math.h>
int main(){
	long double x=4/3;
	long double y;
	for(int i=1;i<=1001;i++){
		y = 4/(3+x);
		x = y;
	}
	printf("%Lf\n",x);
	return 0;
}