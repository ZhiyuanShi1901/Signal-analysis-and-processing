#include <stdio.h>
#include <math.h>
#define M                 //�˴�����x�����ܼ����
#define N                   //�˴�����h����ֵ�ܼ����
#define L M+N-1
#define dt                   //����ʱ����

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
    //ע�� ��hû��ֵ��ʱ������Ϊ0
    return 0;
}


//�˴�����x������h����
float H(float h[])
{

    return h;
}

float X(float x[])
{

    return x;
}

