#include <delay.h>
#include <mega128a.h>

flash unsigned char seg[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27,0x7F, 0x6F}; 

void main(void)
{
    int i;
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;
    
    PORTG=0b00001000;
    PORTB=0b00001111;
    PORTD=0b11110000;
    
    while(1){
        for(i=0; i<10; i++){
            PORTD=((seg[i]&0x0F)<<4);
            PORTB=seg[i]&0xF0;
            delay_ms(500);
        }
    }
}    