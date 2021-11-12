#include<stdio.h>
#include<math.h>

# define dt 0.02
# define NP 2001
# define tmin -20   //设置最小时间


int main(void)
{
    float fx[NP],t;
    int i;
    FILE *fp1;
    fp1 =  fopen("sinc_function.xls","w");
    for(i=0; i<NP; i++)
    {
        t = tmin + i*dt;
        if(t == 0)
        {
            fx[i] = 1;
        }
        else
        {
            fx[i] = sin(t)/t;  //计算
        }
        fprintf(fp1, "%10.3f\t%10.3f\n", t, fx[i]);  //写入文件
    }
    fclose(fp1);  //关闭文件



    return 0;
}
