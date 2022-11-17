#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/delay.h>
int main()
{
    DDRB = 0xFF;
    while (true)
    {
        for (int i=0; i<=7; i++)
        {
            PORTB = (1<<i);
            _delay_ms(500);
        }
       for (int i=0; i<=7; i++)
        {
            PORTB = (1<<(7-i));
            _delay_ms(500);
        }
    }
    return 0;
}
