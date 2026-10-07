

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#ifndef _LCD_functions_H
#define _LCD_functions_H



/*Useful pin and port definitions*/
#define LCD_Dir DDRD
#define LCD_Port PORTD
/* RS=0, command reg. */
/* Enable pulse ON */
/* Enable pulse OFF */
/* Enable pulse ON */
#define RS PD2
#define EN PD3
/*LCD command write function*/
void LCD_Cmd(unsigned char cmd){
	/*Sending the first nibble of data (Higher 4 bits)*/
	LCD_Port = (LCD_Port & 0x0F) | (cmd & 0xF0);/* Sending upper nibble */
	LCD_Port &= ~ (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	/*Sending the second nibble of data (Lower 4 bits)*/
	LCD_Port = (LCD_Port & 0x0F) | (cmd << 4);/* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}
/*LCD data write function */
void LCD_Char (unsigned char char_data){
	/*Sending the first nibble of data (Higher 4 bits)*/
	LCD_Port = (LCD_Port & 0x0F) | (char_data & 0xF0);/* Sending upper nibble */
	LCD_Port |= (1<<RS);
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_us(200);
	/*Sending the second nibble of data (Lower 4 bits)*/
	LCD_Port = (LCD_Port & 0x0F) | (char_data << 4);  /* Sending lower nibble */
	LCD_Port |= (1<<EN);
	_delay_us(1);
	LCD_Port &= ~ (1<<EN);
	_delay_ms(2);
}
/*LCD Initialize function */
void LCD_Init (void){
	LCD_Dir = 0xFF; /* Make LCD command port direction as output pins*/
	_delay_ms(20); /* LCD Power ON delay always > 15ms */
	/* Enable pulse OFF */
	/* RS=1, data reg. */
	/* Enable pulse ON */
	/* Enable pulse OFF */
	/* Enable pulse ON */
	/* Enable pulse OFF */
	LCD_Cmd(0x02); /* Return display to its home position */
	LCD_Cmd(0x28); /* 2 line 4bit mode */
	LCD_Cmd(0x0C); /* Display ON Cursor OFF */
	LCD_Cmd(0x06); /* Auto Increment cursor */
	LCD_Cmd(0x01); /* Clear display */
}

/*Clear LCD Function*/
void LCD_Clear(void){
	LCD_Cmd(0x01); /* clear display */
	LCD_Cmd(0x02); /* Return display to its home position */
}

/*Send string to LCD function */
void LCD_String (const char *str){
	int i;
	/* Send each char of string till the NULL */
	for(i=0;str[i]!=0;i++){
		LCD_Char(str[i]);
	}
}

/*Send string to LCD with xy position */
void LCD_String_xy (char row, char pos, const char *str){
	if (row == 0 && pos<16){
		LCD_Cmd((pos & 0x0F)|0x80);/* Command of first row and required
		position<16 */
	}
	else if (row == 1 && pos<16){
		LCD_Cmd((pos & 0x0F)|0xC0);/* Command of second row and required
		position<16 */
	}
	LCD_String(str);
	/* Call LCD string function */
} 

/*loading custom chars*/

void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
{
    unsigned char i;
    if(loc<8)
    {
     LCD_Cmd (0x40 + (loc*8));  /* Command 0x40 and onwards forces 
                                       the device to point CGRAM address */
       for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */
           LCD_Char(msg[i]);      
    }   
}

void chorus(){
	
		/*CHORUS*/
		LCD_String_xy(0, 3, "woah - oh");
		LCD_String_xy(1, 8, "my baby"); _delay_ms(5000);
		LCD_Clear();
		
		LCD_String_xy(0, 0, "how beautiful");
		LCD_String_xy(1, 6, "you are"); LCD_String(" "); LCD_Char(3); _delay_ms(5000);
		LCD_Clear();
		
		LCD_String_xy(0, 6, "and");
		LCD_String_xy(1, 7, "woah-ah"); _delay_ms(3000); LCD_Clear();
		
		LCD_String_xy(0, 0, "my darling");
		LCD_String_xy(1, 1, "completely torn"); _delay_ms(4500); LCD_Clear();
		
		LCD_String_xy(1, 0, "apart"); _delay_ms(3000); LCD_Clear();
		
		LCD_String_xy(0, 0, "and gone");
		LCD_String_xy(1, 3, "with the sin"); _delay_ms(3000); LCD_Clear();
		
		LCD_String_xy(0, 5, "my baby");
		LCD_String_xy(1, 3, "and beautiful"); _delay_ms(3500); LCD_Clear();
		
		LCD_String_xy(0, 2, "YOU ARE !!!"); _delay_ms(3000); LCD_Clear();
		
		LCD_String_xy(0, 5, "so gone");
		LCD_String_xy(1, 2, "with the sin"); _delay_ms(3000); LCD_Clear();
		
		LCD_String_xy(0, 3, "my darling"); LCD_String(" "); LCD_Char(3); _delay_ms(8500); LCD_Clear();
		
		/* END OF CHORUS */
}




#endif