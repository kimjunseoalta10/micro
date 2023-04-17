/*
 * 20230417.c
 *
 * Created: 2023-04-17 ¿ÀÀü 8:47:22
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

flash unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void Seg4(int);

void main(void)
{

    int num=0;
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;

    PORTB=0x0;
    PORTD=0x0;


while (1)
    {
        Seg4(num);
        num++;
        if(num>9999) num=0 ;
    }
    }                 
void Seg4(int num)
{
    int i, v1, v2, v3, v4, s;
    v1=num/1000;
    s=num%1000;
    v2=s/100;
    s=s%100;
    v3=s/10;
    v4=s%10;
    for(i=1; i<=5; i++)
    {
        PORTG=0b00001000;
        PORTD=(seg[v4]&0x0F)<<4;
        PORTB=(seg[v4]&0xF0) ;
        delay_ms(5); 
        PORTG=0b00000100;
        PORTD=(seg[v3]&0x0F)<<4;
        PORTB=(seg[v3]&0xF0) ;
        delay_ms(5);
        PORTG=0b00000010;
        PORTD=(seg[v2]&0x0F)<<4  ;
        PORTB=(seg[v2]&0xF0);
        delay_ms(5);
        PORTG=0b00000001;
        PORTD=(seg[v1]&0x0F)<<4 ;
        PORTB=(seg[v1]&0xF0);
        delay_ms(5); 
        }
}
