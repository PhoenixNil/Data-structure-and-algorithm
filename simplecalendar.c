#include <reg52.h>
unsigned char code number[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
unsigned char months, days, years, count;

void init()
{
    months = 1;
    days = 1;
    years = 0;
    TMOD = 0X01;
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}
void delay(unsigned int x)
{
    unsigned int i, j;
    for (i = x; i > 0; i--)
        for (j = 110; j > 0; j--);
}
void display(unsigned int years, unsigned int months, unsigned int days)
{
    P0 = 0xff;
    P2 = number[years / 1000];
    P0 = 0x7f;
    delay(2);

    P0 = 0xff;
    P2 = number[years / 100 % 10];
    P0 = 0xBF;
    delay(2);

    P0 = 0xff;
    P2 = number[years / 10 % 10];
    P0 = 0xdf;
    delay(2);

    P0 = 0xff;
    P2 = number[years / 10];
    P0 = 0xef;
    delay(2);

    P0 = 0xff;
    P2 = number[months / 10];
    P0 = 0xf7;
    delay(2);

    P0 = 0xff;
    P2 = number[months % 10];
    P0 = 0xfb;
    delay(2);

    P0 = 0xff;
    P2 = number[days / 10];
    P0 = 0xfd;
    delay(2);

    P0 = 0xff;
    P2 = number[days % 10];
    P0 = 0xfe;
    delay(2);
}
void main()
{
    init();
    while (1)
    {
        if (count == 20)
        {
            count = 0;
            days++;
            if ((months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12) && (days == 32)) //31???
            {
                days = 1;
                months++;
                if (months == 13)
                {
                    months = 1;
                    years++;
                }
            }
            else if (months == 2 && days == 30)
            {
                days = 1;
                months++;
                if (months == 13)
                {
                    months = 1;
                    years++;
                }
            }
            else
            {
                if ((days == 31) && (months == 4 || months == 6 || months == 9 || months == 11))
                {
                    days = 1;
                    months++;
                    if (months == 13)
                    {
                        months = 1;
                        years++;
                    }
                }
            }
        }
    }
    display(years, months, days);
}
void time() interrupt 1
{
    TH0 = (65536 - 50000) / 256;
    TL0 = (65536 - 50000) % 256;
    count++; //20?????
}