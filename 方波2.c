#include <reg52.h>

sbit p3_0 = P3 ^ 0;

void main()
{
    TMOD = 0x02; //方式2
    ET0 = 1;     //定时器0
    EA = 1;
    TH0 = 0x06;
    TL0 = 0x06;
    TR0 = 1;
    while (1);
}

P3_sign() interrupt 1
{
    p3_0 = !p3_0;
}