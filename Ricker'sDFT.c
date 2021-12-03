#include <stdio.h>
#include<math.h>
# define dt 0.0001
# define NP 2001
# define tmin -0.1   //������Сʱ��
# define fm 30
# define PI 2*asin(1.0)
#define N 2000
void dft(xreal, ximag);
void Ricker(float R[N],float t[N]);
int main()
{
    float t[2000], R[2000];
    float xreal[N], ximag[N];
    Ricker(R, t);
    printf("�׿��Ӳ��������");  //��������
    for(int i=0; i<N; i++)
    {
        xreal[i]=R[i]; ximag[i]=0;  //���׿��Ӳ�����ʵ��Ϊԭֵ���鲿Ϊ0
        printf("%f\t%d\n", xreal[i], i);
    }
    dft(xreal, ximag);

    FILE *DFT;  //������������ļ�
    DFT = fopen("Ricker_DFT.xls", "w");

    for(int i=0; i<N; i++)
    {
         fprintf(DFT, "%10.6f\t %d\n", sqrt(pow(xreal[i],2)+pow(ximag[i], 2)), i);
    }
    fclose(DFT);

    return 0;
}


void dft(xreal, ximag)  //DFT ��ɢ����Ҷ���任
float xreal[N],ximag[N];
{
    float Xreal[N],Ximag[N];
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

void Ricker(float R[N],float t[N])
{
     for(int i=0; i<NP; i++)
    {
        float time;
        time = tmin + i*dt;
        R[i] = (1-2*pow(PI*fm*time, 2.0))*exp(-pow(PI*fm*time, 2.0));
        t[i] = time;
    }
}
