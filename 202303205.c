#include <mega128a.h>
#include <delay.h>
void main(void)
{
    DDRC = 0xFF;
    PORTC = 0x55;
    while (1)
    {
        PORTC = 0x55;
        delay_ms(1000);
        PORTC = 0xAA;
        delay_ms(1000);
    }
}