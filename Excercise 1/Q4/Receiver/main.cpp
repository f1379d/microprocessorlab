#define F_CPU 8000000UL /* Define CPU Frequency e.g. here 8MHz */

#include <avr/io.h>
#include <string.h>
#include <avr/delay.h>

#define LCD_Data_Dir DDRB      /* Define LCD data port direction */
#define LCD_Command_Dir DDRA   /* Define LCD command port direction register */
#define LCD_Data_Port PORTB    /* Define LCD data port */
#define LCD_Command_Port PORTA /* Define LCD data port */
#define RS PC0                 /* Define Register Select (data/command reg.)pin */
#define RW PC1                 /* Define Read/Write signal pin */
#define EN PC2                 /* Define Enable signal pin */

void LCD_Command(unsigned char cmnd)
{
    LCD_Data_Port = cmnd;
    LCD_Command_Port &= ~(1 << RS); /* RS=0 command reg. */
    LCD_Command_Port &= ~(1 << RW); /* RW=0 Write operation */
    LCD_Command_Port |= (1 << EN);  /* Enable pulse */
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(3);
}

void LCD_Init(void) /* LCD Initialize function */
{
    LCD_Command_Dir = 0xFF; /* Make LCD command port direction as o/p */
    LCD_Data_Dir = 0xFF;    /* Make LCD data port direction as o/p */

    _delay_ms(20);     /* LCD Power ON delay always >15ms */
    LCD_Command(0x38); /* Initialization of 16X2 LCD in 8bit mode */
    LCD_Command(0x0C); /* Display ON Cursor OFF */
    LCD_Command(0x06); /* Auto Increment cursor */
    LCD_Command(0x01); /* clear display */
    LCD_Command(0x80); /* cursor at home position */
}

void LCD_Char(unsigned char char_data)
{
    LCD_Data_Port = char_data;
    LCD_Command_Port |= (1 << RS);  /* RS=1 Data reg. */
    LCD_Command_Port &= ~(1 << RW); /* RW=0 write operation */
    LCD_Command_Port |= (1 << EN);  /* Enable Pulse */
    _delay_us(1);
    LCD_Command_Port &= ~(1 << EN);
    _delay_ms(1);
}

void LCD_String(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        LCD_Char(str[i]); /* call LCD data write */
}

int main()
{
    DDRC = 0;

    while (PINC == 0)
    {
    }

    char text[200];

    for (int j = 0; j != 200; j++)
    {
        text[j] = PINC;
        _delay_ms(1);
    }

    LCD_Init(); /* Initialize LCD */

    int buffer_size = 14;

    for (int i = 0; i != 200 / buffer_size; i++)
    {
        char buffer[buffer_size];
        strncpy(buffer, text + i * buffer_size, buffer_size);

        LCD_Command(0x01);
        LCD_Command(0x80);

        LCD_String(buffer);

        _delay_ms(100);
    }

    return 0;
}
