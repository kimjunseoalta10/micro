/*
 * 20230619.c
 *
 * Created: 2023-06-19 ¿ÀÀü 9:16:56
 * Author: user
 */

#include <mega128a.h>

unsigned char led = 0x0;
unsigned char cnt = 0;

void main(void)
{
    DDRC = 0XFF;
    PORTC = led;
    TCCR0 = 0X06;
    TIMSK = 0X01;
    TCNT0 = 6;
    SREG = 0X80;
while (1);
}
interrupt [TIM0_OVF] void timer_comp0(void)
{
    TCNT0 = 0X06;
    cnt++;
    if(cnt == 250){
        led = led ^ 0xFF;
        PORTC = led;
        cnt=0;
        }

}

