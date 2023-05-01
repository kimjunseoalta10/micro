/*
 * 20230501.c
 *
 * Created: 2023-05-01 ¿ÀÀü 9:20:14
 * Author: user
 */

#include <mega128a.h>

void main(void)
{

    unsigned char o_sw, n_sw;
    unsigned char led = 0xFE;
    DDRE = 0x00;
    DDRC = 0xFF;
    
    PORTC = 0x00;    
    
    o_sw = 0b11110000;
    while (1)
    {
        n_sw = PINE&0xf0 ;
        if(n_sw==0b11110000&&o_sw==0b10110000){
            led = (led>>1)|0x80;
            if(led == 0x00) led=0xFE;
        
            PORTC = led;
        }
        o_sw = n_sw;  
    }
}             
