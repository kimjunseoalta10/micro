/*
 * 20230515.c
 *
 * Created: 2023-05-15 ¿ÀÀü 9:48:03
 * Author: user
 */

#include <mega128a.h>
unsigned char led = 0xFE;
void main(void)
{
    DDRC = 0xFF;
    PORTC = led;
    EIMSK = 0b10000000;
    EICRB = 0b11000000;
    SREG = 0x80;
while (1) ;
}
interrupt[EXT_INT7] void LED_TEST(void)
{                           
    led = led << 1;
    led = led | 0b00000001;
    if(led == 0xFF) led = 0xFE;
    PORTC = led;
}

