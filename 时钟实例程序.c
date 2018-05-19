#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
uchar code number[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uchar shi,fen,miao;
uchar time; 
void delay(uint x)
{
 uint y;
 for(;x>0;x--)
  {
   for(y=0;y<124;y++);
  }
}
void display(uchar shi,uchar fen,uchar miao)
{
 P2=0;  //位码
 P0=(tab[shi/10]);  //段码
 delay(2);
 P2=1; 
 P0=(tab[shi%10]);  
 delay(2);
  P2=2;  //位码
 P0=0x40;  //段码
 delay(2);
 P2=3;  //位码
 P0=(tab[fen/10]);  //段码
 delay(2);
 P2=4; 
 P0=(tab[fen%10]);  
 delay(2);
 P2=5;  //位码
 P0=0x40;  //段码
 delay(2);
 P2=6;  //位码
 P0=(tab[miao/10]);  //段码
 delay(2);
 P2=7; 
 P0=(tab[miao%10]);  
 delay(2);
}
void main()
{
 TMOD=0x01;
 TH0=(65536-50000)/256; 
 TL0=(65536-50000)%256;
 EA=1;
 ET0=1;
 TR0=1;
 while(1)
  {
  
   if(time==20)
   {
    time=0;
    miao++;
    if(miao==60)
    {
     miao=0;
     fen++;
     if(fen==60)
     {
      fen=0;
      shi++;
      if(shi==24)
      shi=0;
     }
     
    }
}
   display(shi,fen,miao);
  }
}
void timer0() interrupt 1
{
 TH0=(65536-50000)/256; 
 TL0=(65536-50000)%256;
 time++;
}