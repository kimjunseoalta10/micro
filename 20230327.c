/*
 * 20230327.c
 *
 * Created: 2023-03-27 ¿ÀÀü 8:54:20
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>
void main(void)
{
    int i;
    unsigned char led;
    DDRC=0xFF;
    while (1)
    {
        led = 0b01111111;
        for(i=1; i<=8; i++)
        {
            PORTC=led;
            delay_ms(500);
            led>>=1;   
            led=led |0x80;
        }
    }
}
