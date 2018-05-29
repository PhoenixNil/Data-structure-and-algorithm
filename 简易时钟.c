// 简易时钟
#include <reg52.h>
sbit wei = P2 ^ 6;                                                                          //申明段选
sbit duan = P2 ^ 7;                                                                         //位选
unsigned char code number[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f}; //0-9段码显示
unsigned char second, minute, hour, count;
void delayms(unsigned int x)
{
    unsigned int i, j;
    for (i = x; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}

void init() //状态初始化 时分秒，中断计数，开启中断
{
    second = 0;
    minute = 0;
    hour = 0;
    TMOD = 0X01;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void display(unsigned int hour, unsigned int minute, unsigned second)
{
    duan = 1;
    P0 = number[hour / 10];
    duan = 0;
    P0 = 0xff; //消影，下面的0xff都是这个作用
    wei = 1;
    P0 = 0xdf; //位选数码管  最左边的数码管
    wei = 0;
    delayms(5);

    duan = 1;
    P0 = number[hou % 10];
    duan = 0;
    P0 = 0xff;
    wei = 1;
    P0 = 0xef; //位选数码管   第二个
    wei = 0;
    delayms(5);

    duan = 1;
    P0 = number[minute / 10];
    duan = 0;
    P0 = 0xff;
    wei = 1;
    P0 = 0xf7; //位选数码管   第三个
    wei = 0;
    delayms(5);

    duan = 1;
    P0 = number[minute % 10];
    duan = 0;
    P0 = 0xff;
    wei = 1;
    P0 = 0xfb; //位选数码管   第四个
    wei = 0;
    delayms(5);

    duan = 1;
    P0 = number[second / 10];
    duan = 0;
    P0 = 0xff;
    wei = 1;
    P0 = 0xfd; //位选数码管  第五个
    wei = 0;
    delayms(5);

    duan = 1;
    P0 = number[second % 10];
    duan = 0;
    P0 = 0xff;
    wei = 1;
    P0 = 0xfe; //位选数码管  第六个
    wei = 0;
    delayms(5);
}

void main()
{
    init();
    while (1)
    {
        if (count == 20)
        {
            count = 0;
            second++;
            if (second == 60)
            {
                second = 0;
                minute++;
                if (minute == 60)
                {
                    minute = 0;
                    hour++;
                    if (hour == 24)
                        hour = 0;
                }
            }
        }
        display(hour, minute, second);
    }
}
void timer0() interrupt 1
{
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    count++; //20次50ms为一秒
}