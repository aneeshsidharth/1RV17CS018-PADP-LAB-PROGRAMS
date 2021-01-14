#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define SEED 35791246
 
int main()
{
	int n = 0, i, count = 0,t=0;
	double z, pi, x,y;

	printf("Enter the number of threads to be used to estimate pi: ");
	scanf("%d", &t);	
	printf("Enter the number of iterations to be used to estimate pi: ");
	scanf("%d", &n);
	srand(SEED);
	double t1 = omp_get_wtime();
	omp_set_num_threads(t);
	#pragma omp parallel for private(x,y,z) reduction(+:count)
	
	for ( i=0; i<n; i++) 
	{
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x+y*y;
		if (z<=1) count++;
	}
	double t2 = omp_get_wtime();
	printf("%lf\n", t2-t1);
	pi=(double)count/n*4;
	
	printf("# of trials= %d , estimate of pi is %g, # of threads= %d \n",n,pi, t);
}

