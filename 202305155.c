#include <mega128a.h>
#include <delay.h>

flash char seg[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
unsigned char N1=0;
void SEG2(int);
void main(void)
{
    int num = 0;
    DDRD = 0xF0;
    DDRB = 0xF0;
    DDRG = 0x0F;
    PORTB=0x0;
    PORTD=0x0;
    EIMSK = 0b00010000;
    EICRB = 0b00000010;
    SREG = 0x80; 
    SEG2(N1); 
while (1);
}
interrupt[EXT_INT4] void LED_TEST(void)
{                          
    N1++;
    if(N1==10) N1=0;  
    SEG2(N1);

}
void SEG2(int num)
{
    PORTG=0x08;
    PORTD = (seg[N1]&0x0F)<<4; 
    PORTB = (seg[N1]&0xF0) ;
    delay_ms(10);
    }