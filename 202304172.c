#include <mega128a.h>
#include <delay.h>

flash unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Seg4(int);

void main(void)
{
    int num=0;
     
    DDRD=0xF0;
    DDRB=0xF0;
    DDRG=0x0F;

    PORTB=0x0;
    PORTD=0x0;


    while(1)
    {                                                                                                   
        Seg4(num);
        num++;
        if(num>9999) num=0;
    }
}
void Seg4(int num)
{
    int i, S1, S10, S100, S1000, b;
    S1000=num/1000;
    b=num%1000;
    S100=b/100;
    b=num%100;
    S10=b/10;
    S1=b%10;
    for(i=1; i<=5; i++)
    {
        PORTG=0b00001000;
        PORTD=(seg[S1]&0x0F)<<4;
        PORTB=seg[S1]&0xF0;
        delay_ms(5); 
        PORTG=0b00000100;
        PORTD=(seg[S10]&0x0F)<<4;
        PORTB=seg[S10]&0xF0;
        delay_ms(5);
        PORTG=0b00000010;
        PORTD=(seg[S100]&0x0F)<<4;
        PORTB=seg[S100]&0xF0;
        delay_ms(5);
        PORTG=0b00000001;
        PORTD=(seg[S1000]&0x0F)<<4;
        PORTB=seg[S1000]&0xF0;
        delay_ms(5);
        }
        }
        