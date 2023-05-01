/*
 * 20230501.c
 *
 * Created: 2023-05-01 ¿ÀÀü 9:20:14
 * Author: user
 */

#include <mega128a.h>

void main(void)
{

    unsigned char key;
    
    DDRE = 0x0F;
    DDRC = 0xFF;
    
    PORTC = 0xFF;
    while (1)
    {
        key = PINE&0b11110000;
        
        switch(key)
        {
            case 0b11100000 :
                PORTC = 0x00;
                break;
            case 0b11010000 :
                PORTC = 0xFF;
                break;
            case 0b10110000 :
                PORTC = 0xAA;
                break;
            case 0b01110000 :
                PORTC = 0x55;
                break; 
        }

    }
}
