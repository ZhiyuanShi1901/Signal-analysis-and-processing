#include <stdio.h>
#include <math.h>
# define dt 0.002
# define fm1 10
# define fm2 35
# define fm3 70
# define PI 2*asin(1.0)
#define tmin 0
#define N 3000
#define N1 30
#define N2 300
#define TS1 0.1
#define TS2 0.01
void dft(float xreal[N], float ximag[N] , int P);  //DFT 离散傅里叶正变换
int main()
{
    FILE *fp1;
    fp1 = fopen("STtest_in_P98.xls", "w");
    float S1[N], S2[N];  //定义两个数组，f1为0.1s抽样，f2为0.01s抽样
    float fss1[N1], fss2[N2];
    float fs1[N], fs2[N];//存储抽样后的fs时域函数值
    float fw1[N1], fw2[N2];//存储抽样后的fw频域函数值
    float t;  t=tmin;
    for(int i = 0; i < N; i++) //创建抽样函数
    {
        t += dt;
        if (i%(int)(TS1/dt) == 0)
            {S1[i] = 1.0;
            //printf("%d\n",S1[i]);
            }
        else
            S1[i] = 0.0;
        if(i%(int)(TS2/dt) == 0)
            S2[i] = 1.0;
        else
            S2[i] = 0.0;
    }


    t=tmin;
    for(int i = 0; i < N; i++) //计算时域数据
    {
        t += dt;
        float f;
        f = sin(2*PI*fm1*t)+sin(2*PI*fm2*t)+sin(2*PI*fm3*t);
        fprintf(fp1, "%10.6f\t %10.6f\n",  t, f); //t输出单位为s
        //printf("%f\n", f);
        fs1[i] = f * S1[i];
        fs2[i] = f * S2[i];
    }

        fprintf(fp1, "\n\nt\t  fs1\t  f1\t fw1\n");
printf("\n\n\n\n\n");
    int j, k; j=0;k=0;
    for(int i = 0; i < N; i++) //抽样后的函数值
    {
       if (i%(int)(TS1/dt) == 0)
       {
           fss1[j] = fs1[i];
           j++;
       }
        if(i%(int)(TS2/dt) == 0)
        {
            fss2[k] = fs2[i];
            k++;
        }
    }
    float fs1R[N], fs2R[N], fs1I[N], fs2I[N];//存储抽样后的fw频域函数值
    for(int i = 0; i < N1; i++) //时域数据分为实部和虚部
    {
        fs1R[i] = fss1[i];
        fs1I[i] = 0.0;
    }
     for(int i = 0; i < N2; i++) //时域数据分为实部和虚部
    {
        fs2R[i] = fss2[i];
        fs2I[i] = 0.0;
    }
    dft(fs1R, fs1I, N1);  //离散傅里叶变换
    dft(fs2R, fs2I, N2);  //离散傅里叶变换
    t=tmin;
     for(int i = 0; i < N1; i++) //输出fs1序列
    {
        t+=TS1;
        fprintf(fp1, "%10.6f\t %10.6f\t %10.6f\t %10.6f\n",  t, fss1[i], i*(1/TS1/N1),sqrt(pow(fs1R[i],2)+pow(fs1I[i], 2))); //t输出单位为s
    }

    t=tmin;
     fprintf(fp1, "\n\n t\t  fs2\t f2\t fw2\n");
    for(int i = 0; i < N2; i++) //输出fs2序列
    {
        t+= TS2;
        fprintf(fp1, "%10.6f\t %10.6f\t %10.6f\t %10.6f\n",  t, fss2[i], i*(1/TS2/N2), sqrt(pow(fs2R[i],2)+pow(fs2I[i], 2))); //t输出单位为s
    }

    fclose(fp1);
    return 0;
}


void dft(float xreal[N], float ximag[N], int P)  //DFT 离散傅里叶正变换
//float xreal[N],ximag[N];
{
    printf("P%d\n",P);
    float Xreal[N], Ximag[N];
    float sumreal, sumimag, rad;  //定义实部计算加和、虚部计算加和、角度
    for(int k = 0; k < P; k++)
    {
        sumreal = 0.0; sumimag = 0.0;
        for(int n=0; n<P; n++)
        {
            rad = 2*PI/P*n*k;

           //  printf("rad:%f\n", rad/PI);
            sumreal += xreal[n]*cos(rad) + ximag[n]*sin(rad);
            sumimag+= -xreal[n]*sin(rad) + ximag[n]*cos(rad);
        }

        Xreal[k] = sumreal;
        Ximag[k] = sumimag;
    }
    for(int k = 0; k < P; k++)
    {
        xreal[k] = Xreal[k];
        ximag[k] = Ximag[k];
    }
}
