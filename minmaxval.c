#include<stdio.h>
#include<omp.h>
int main()
{
double arr[10];
omp_set_num_threads(4);
double min_val,max_val;
int i;
for(i=0;i<10;i++)
{
arr[i]=2.0+1;
printf("%f \n",arr[i]);
}
min_val=arr[0];
#pragma omp parallel for reduction(min:min_val)

for(i=0;i<10;i++)
{
printf("thread id=%d and i=%d\n",omp_get_thread_num(),i);

if(arr[i]>min_val)
{
min_val=arr[i];
}
}
printf("\n min_val=%f",min_val);

#pragma omp parallel for reduction(max:max_val)
for(i=0;i<10;i++)
{
printf("thread id=%d and i=%d\n",omp_get_thread_num(),i);

if(arr[i]>max_val)
{
max_val=arr[i];
}
}
printf("\n max_val=%f",max_val);
}
/*OUTPUT
cpllab00@cpllab:~$ gcc minmaxval.c -fopenmp
cpllab00@cpllab:~$ ./a.out
3.000000/n3.000000/n3.000000/n3.000000/n3.000000/n3.000000/n3.000000/n3.000000/n3.000000/n3.000000/nthread id=0 and i=0
thread id=0 and i=1
thread id=0 and i=2
thread id=2 and i=6
thread id=2 and i=7
thread id=3 and i=8
thread id=3 and i=9
thread id=1 and i=3
thread id=1 and i=4
thread id=1 and i=5
/n min_val=3.000000thread id=1 and i=3
thread id=3 and i=8
thread id=1 and i=4
thread id=2 and i=6
thread id=3 and i=9
thread id=1 and i=5
thread id=0 and i=0
thread id=0 and i=1
thread id=0 and i=2
thread id=2 and i=7
/n max_val=3.000000 
*/
