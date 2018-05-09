#include <reg52.h>
unsigned int k, c, flag = 0;
sbit left_r = P1 ^ 0;
sbit left_g = P1 ^ 1;
sbit left_y = P1 ^ 2;

sbit right_r = P3 ^ 5;
sbit right_g = P3 ^ 6;
sbit right_y = P3 ^ 7;

void main()
{
    TH0 = (65536 - 45872) / 256; //装初值，11.0592MHz晶振定时50ms，数为45872  ,前4位
    TL0 = (65536 - 45872) % 256; //后4位
    TMOD = 0X01;                 //方式1
    EA = 1;
    ET0 = 1; //开定时器0中断
    TR0 = 1; //启动定时器0
    while (1)
    {
        if (flag)
        {
            flag = 0;
            if (k > 119)
                k = 0;
            else
                k++;
            if (k <= 57)
            {
                left_g = 0;
                right_r = 0;
                left_r = 1;
                left_y = 1;
                right_y = 1;
                right_g = 1;
            }
            else if (c > 57 && c < 59)
            {
                left_y = 0;
                right_y = 0;
                left_g = 1;
                left_r = 1;
                right_g = 1;
                right_r = 1;
            }
            else if (c > 59 && c < 117)
            {
                left_r = 0;
                right_g = 0;
                left_g = 1;
                left_y = 1;
                right_r = 1;
                right_y = 1;
            }
            else if (c > 117)
            {
                left_y = 0;
                right_y = 0;
                left_g = 1;
                left_r = 1;
                right_g = 1;
                right_r = 1;
            }
        }
    }
}
void T1_time() interrupt 1
{
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    k++;
    if (k > 5)
    {
        k = 0;
        flag = 1;
    }
}