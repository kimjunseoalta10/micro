/*
 * 20230410.c
 *
 * Created: 2023-04-10 ¿ÀÀü 8:55:01
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

flash unsigned char seg[10]={0x3f, 0x06, 0x5b,0x4f,0x66,0x6d,0x7d,0x27,0x7f,0x6f};
void SEG2(int num);
void main(void)
{
    int num=0;
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;
    PORTB=0b00001111;
    PORTD=0b11110000; 
    
    while (1)
{
    SEG2(num);
    num++;
    if(num>99) num=0;
}
}                    
void SEG2(int num)
{
    int i, N10, N1;
    N10= num/10;
    N1=num%10;
    for(i=0; i<50; i++)
    {   
        PORTG=0b00001000;
        PORTD = ((seg[N1]&0x0F)<<4);
        PORTB=(seg[N1]&0xF0);
        delay_ms(10);
        
        PORTG=0b00000100;
        PORTD = ((seg[N10]&0x0F)<<4);
        PORTB=(seg[N10]&0xF0);
        delay_ms(10);
    }
    
}
