#include <stdio.h>
#include <math.h>
#define M                 //此处设置x函数总间隔数
#define N                   //此处设置h函数值总间隔数
#define L M+N-1
#define dt                   //设置时间间隔

int main(void)
{
    int m, p;
    float x[M], h[N], y[L];
    for(p=0; p<L; p++)
    {
        y[k] = 0.0;
        for(m=0; m<M;M++)
        {
            if(k-m>=0 && k-m < N)
                y[k] += x[m*dt]*h[(k-m)*dt]*dt;
        }
    }
    //注意 当h没有值的时候，设置为0
    return 0;
}


//此处设置x函数和h函数
float H(float h[])
{

    return h;
}

float X(float x[])
{

    return x;
}

