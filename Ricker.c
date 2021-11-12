#include<stdio.h>
#include<math.h>

# define dt 0.001
# define NP 2001
# define tmin -1.0   //设置最小时间
# define fm 30
# define PI 2*asin(1.0)

int main(void)
{
    double fx[NP],t;
    int i;
    FILE *fp2;
    fp2 = fopen("Ricker.xls","w");

    for(i=0; i<NP; i++)
    {
        t = tmin + i*dt;
        fx[i] = (1-2*pow(PI*fm*t, 2))*exp(-pow(PI*fm*t, 2));
        fprintf(fp2, "%10.6f\t%10.6f\n", t*1000, fx[i]);  //使用ms为单位
    }
    fclose(fp2);
    return 0;
}
