#include <stdio.h>
#include <math.h>
# define dt 0.001
# define fm1 10
# define fm2 35
# define fm3 70
# define PI 2*asin(1.0)
#define N 3000
#define N1 30
#define N2 300
#define TS1 0.1
#define TS2 0.01
void dft(float xreal[N], float ximag[N]);  //DFT ��ɢ����Ҷ���任
int main()
{
    FILE *fp1;
    fp1 = fopen("STtest_in_P98.xls", "w");
    float S1[N], S2[N];  //�����������飬f1Ϊ0.1s������f2Ϊ0.01s����
    float fss1[N1], fss2[N2];
    float fs1[N], fs2[N];//�洢�������fsʱ����ֵ
    float fw1[N1], fw2[N2];//�洢�������fwƵ����ֵ
    float t;  t=0.0;
    for(int i = 0; i < N; i++) //������������
    {
        t += dt;
        if (i%100 == 0)
            {S1[i] = 1.0;
            //printf("%d\n",S1[i]);
            }
        else
            S1[i] = 0.0;
        if(i%10 == 0)
            S2[i] = 1.0;
        else
            S2[i] = 0.0;
    }

    fprintf(fp1, "t\t  fs1\t  fw1\n");

    t=0.0;
    for(int i = 0; i < N; i++) //����ʱ������
    {
        t += dt;
        float f;
        f = sin(2*PI*fm1*t)+sin(2*PI*fm2*t)+sin(2*PI*fm3*t);
        printf("%f\n", f);
        fs1[i] = f * S1[i];
        fs2[i] = f * S2[i];
    }
    int j, k; j=0;k=0;
    for(int i = 0; i < N; i++) //������ĺ���ֵ
    {
       if (i%100 == 0)
       {
           fss1[j] = fs1[i];
           j++;
       }
        if(i%10 == 0)
        {
            fss2[k] = fs2[i];
            k++;
        }
    }
    float fs1R[N], fs2R[N], fs1I[N], fs2I[N];//�洢�������fwƵ����ֵ
    for(int i = 0; i < N1; i++) //ʱ�����ݷ�Ϊʵ�����鲿
    {
        fs1R[i] = fss1[i];
        fs1I[i] = 0.0;
    }
     for(int i = 0; i < N2; i++) //ʱ�����ݷ�Ϊʵ�����鲿
    {
        fs2R[i] = fss2[i];
        fs2I[i] = 0.0;
    }
    dft(fs1R, fs1I);  //��ɢ����Ҷ�任
    dft(fs2R, fs2I);  //��ɢ����Ҷ�任
    t=0.0;
     for(int i = 0; i < N1; i++) //���fs1����
    {
        t+=TS1;
        fprintf(fp1, "%10.6f\t %10.6f\t %10.6f\n",  t, fss1[i], sqrt(pow(fs1R[i],2)+pow(fs1I[i], 2))); //t�����λΪms
    }

    t=0.0;
     fprintf(fp1, "\n\nt\t  fs2\t  fw2\n");
    for(int i = 0; i < N2; i++) //���fs2����
    {
        t+= TS2;
        fprintf(fp1, "%10.6f\t %10.6f\t %10.6f\n",  t, fss2[i], sqrt(pow(fs2R[i],2)+pow(fs2I[i], 2))); //t�����λΪms
    }

    fclose(fp1);
    return 0;
}


void dft(float xreal[N], float ximag[N])  //DFT ��ɢ����Ҷ���任
//float xreal[N],ximag[N];
{
    float Xreal[N], Ximag[N];
    float sumreal, sumimag, rad;  //����ʵ������Ӻ͡��鲿����Ӻ͡��Ƕ�
    for(int k = 0; k < N; k++)
    {
        sumreal = 0.0; sumimag = 0.0;
        for(int n=0; n<N; n++)
        {
            rad = 2*PI/N*n*k;
            sumreal += xreal[n]*cos(rad) + ximag[n]*sin(rad);
            sumimag+= -xreal[n]*sin(rad) + ximag[n]*cos(rad);
        }

        Xreal[k] = sumreal;
        Ximag[k] = sumimag;
    }
    for(int k = 0; k < N; k++)
    {
        xreal[k] = Xreal[k];
        ximag[k] = Ximag[k];
    }
}
