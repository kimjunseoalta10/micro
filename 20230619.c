/*
 * 20230619.c
 *
 * Created: 2023-06-19 ¿ÀÀü 9:16:56
 * Author: user
 */

#include <mega128a.h>

unsigned char led = 0xFE;

void main(void)
{
    DDRC = 0XFF;
    PORTC = led;
    TCCR0 = 0X0F;
    TIMSK = 0X02;
    OCR0 = 0XFF;
    SREG = 0X80;
while (1);
}
interrupt [TIM0_COMP] void timer_comp0(void)
{
    led = led << 1 | 0x01;
    if(led == 0xFF) led = 0xFE;
    PORTC = led;

}

