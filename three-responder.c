#include <reg52.h>
#define uchar unsigned char
unsigned char num, i, shi, ge, j, m, n, player = 0, flag = 0;
void delay();

uchar code table[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
sbit wela = P2 ^ 7;
sbit dula = P2 ^ 6;
sbit key1 = P3 ^ 4;
sbit key2 = P3 ^ 5;
sbit key3 = P3 ^ 6;
sbit key4 = P3 ^ 7;
void display(uchar player, uchar shi, uchar ge)
{
    wela = 1;
    P0 = 0xfe;
    wela = 0;
    P0 = 0xff;
    dula = 1;
    P0 = table[player];
    dula = 0;
    delay();

    wela = 1;
    P0 = 0xdf;
    wela = 0;
    P0 = 0xff;
    dula = 1;
    P0 = table[ge];
    dula = 0;
    delay();

    wela = 1;
    P0 = 0xef;
    wela = 0;
    P0 = 0xff;
    dula = 1;
    P0 = table[shi];
    dula = 0;
    delay();
}
void main()
{
    TMOD = 0x01;
    TH0 = (65536 - 46082) / 256;
    TL0 = (65536 - 46082) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
    while (1)
    {
        if (key1 == 0)
        {
            delay();
            if (key1 == 0)      //再次按下0重新计时
            {
                flag = 1;
                player = 1;
                while (!key1);
                TR0 = ~TR0;
            }
        }
        if (key2 == 0)
        {
            delay();
            if (key2 == 0)
            {
                player = 2;
                while (!key2);
                TR0 = 0;
            }
        }

        else if (key3 == 0)
        {
            delay();
            if (key3 == 0)
            {
                player = 3;
                while (!key3);
                TR0 = 0;
            }
        }

        else if (key4 == 0)
        {
            delay();

            if (key4 == 0)
            {
                player = 4;
                while (!key4);
                TR0 = 0;
            }
        }
        if (flag)
        {
            display(player, shi, ge);
        }
    }
}

void Timer_1() interrupt 1
{
    TH0 = (65536 - 45872) / 256;
    TL0 = (65536 - 45872) % 256;
    i++;
    if (i == 1)
    {
        i = 0;
        num++;
        if (num == 100)
            num = 0;
        shi = num / 10;
        ge = num % 10;
    }
}

void delay()
{
    for (m = 20; m > 0; m--)
        for (n = 110; n > 0; n--);
}