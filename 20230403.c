/*
 * 20230403.c
 *
 * Created: 2023-04-03 ¿ÀÀü 9:29:04
 * Author: user
 */
#include <delay.h>
#include <mega128a.h>

void main(void)
{
    DDRB = 0xF0;  
    DDRD = 0xF0;
    DDRG = 0x0F;
    
    while (1)
    {   
        PORTB=0b00000000;
        PORTD=0b01100000;
        PORTG=0b00001000;
        delay_ms(1);
        
        PORTB=0b00110000;
        PORTD=0b11110000;
        PORTG=0b00000100;
        delay_ms(1);
        
        PORTB=0b01010000;
        PORTD=0b10110000;
        PORTG=0b00000010;
        delay_ms(1);
        
        PORTB=0b01100000;
        PORTD=0b01100000;
        PORTG=0b00000001;
        delay_ms(1);
    }
}

