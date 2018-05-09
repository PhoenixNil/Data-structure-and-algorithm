// 方式一定时器0  p3^0 1ms 方波
#include <reg52.h>

sbit p3_0 = P3 ^ 0;

void main()
{
    TMOD = 0x01;

    ET1 = 1; //定时器0
    EA = 1;
    TH1 = 0xfe;
    TL1 = 0x0C;
    TR0 = 1;
    while (1);
}

P3_sign() interrupt 3
{
    p3_0 = !p3_0;
    TH1 = 0xfe;
    TL1 = 0x0c;
}