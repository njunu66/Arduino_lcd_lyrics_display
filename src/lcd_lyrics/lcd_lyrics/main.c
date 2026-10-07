/*
 * main.c
 *
 * Created: 10/15/2025 7:05:51 PM
 *  Author: 97433
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD_functions.h"

/*Function Declarations*/
void LCD_Cmd(unsigned char cmd);
void LCD_Char(unsigned char char_data);
void LCD_Init(void);
void LCD_Clear(void);
void LCD_String(const char *str);
void LCD_String_xy (char row, char pos, const char *str);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);
void chorus();

char i;
unsigned char Heart[8] = {0x0,0xa,0x1f,0x1f,0xe,0x4,0x0};
unsigned char snow_flake[8] = {0x4,0x15,0xe,0x1f,0xe,0x15,0x4};
unsigned char upsidedown_face[8] = {0x0,0xa,0xa,0x0,0xe,0x11,0x0};	
unsigned char spine[8] = {0x3,0x1f,0x1f,0x1f,0x1f,0x1f,0x3};
unsigned char open_Heart[8] = {	0x0,0xa,0x15,0x11,0xa,0x4,0x0};
unsigned char bottom[8] = {0x0,0x0,0x0,0x0,0x0,0x1f,0x1f};
unsigned char middle[8] = {0x0,0x0,0x0,0x1f,0x1f,0x1f,0x1f};
unsigned char top[8] = {0x0,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f};
	
	
	
/*Our main program*/
int main(void)
{
	LCD_Init();
	
	LCD_Custom_Char(0, Heart);
	LCD_Custom_Char(1, upsidedown_face);
	LCD_Custom_Char(2, spine);
	LCD_Custom_Char(3, open_Heart);
	LCD_Custom_Char(4, snow_flake);
	LCD_Custom_Char(5, bottom);
	LCD_Custom_Char(6, middle);
	LCD_Custom_Char(7, top);
	
	
	_delay_ms(5000); 
	
	LCD_String_xy(0, 0, "i love your skin");
	LCD_String_xy(1, 0, "oh-oh sooo"); _delay_ms(7000);
	LCD_Clear();
	
	LCD_String_xy(0, 4, "white");
	LCD_String_xy(1, 4, " "); LCD_Char(0); LCD_Char(0); LCD_Char(0); _delay_ms(4500);
	LCD_Clear();
	
	LCD_String_xy(0, 0, "love your touch");
	LCD_String_xy(1, 0, "co-oh-ld as"); _delay_ms(6000);
	LCD_Clear();
	
	LCD_String_xy(0, 6, "ice");
	LCD_String_xy(1, 5, " "); LCD_Char(4); LCD_Char(4); LCD_Char(4); _delay_ms(4700);
	LCD_Clear();
	
	LCD_String_xy(0, 0, "and love every");
	LCD_String_xy(1, 0, "single tear"); _delay_ms(4500);
	LCD_Clear();
	
	LCD_String_xy(1, 4, "you cry :(");
	LCD_Cmd(0xC0); _delay_ms(5000);
	LCD_Clear();
	
	LCD_String_xy(0, 0, "i just love");
	LCD_String_xy(1, 0, "the way you're"); _delay_ms(3000); LCD_Clear();
	LCD_String_xy(0, 0, "losing your "); _delay_ms(3000); LCD_Clear();
	
	LCD_String_xy(0, 6, "Life!!!");
	LCD_Cmd(0xC0); LCD_Char(0);  LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); _delay_ms(5000); LCD_Clear();
	
	chorus();
	
	LCD_String_xy(0, 0, "i adore"); LCD_String(" ");
	LCD_String_xy(1, 3, "the despair"); _delay_ms(3500); LCD_Clear();
	
	LCD_String_xy(0, 0, "in your");
	LCD_String_xy(1, 12, "eyes :(");  _delay_ms(5500); LCD_Clear();
	
	LCD_String_xy(0, 4, "i worship");
	LCD_String_xy(1, 0, "your lips"); _delay_ms(3000); LCD_Clear();
	
	LCD_String_xy(0, 0, "once red");
	LCD_String_xy(1, 5, "as wine"); _delay_ms(7000); LCD_Clear();
	
	LCD_String_xy(0, 4, "and i crave");
	LCD_String_xy(1, 5, "your scent"); _delay_ms(3000); LCD_Clear();
	
	LCD_String_xy(0, 0, "sending shivers");
	LCD_String_xy(1, 9, "down my"); _delay_ms(4000); LCD_Clear();
	
	LCD_String_xy(0, 5, "spine"); 
	LCD_Cmd(0xC0); LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2);LCD_Char(2); _delay_ms(3500); LCD_Clear();
	
	LCD_String_xy(0, 0, "and i just");
	LCD_String_xy(1, 0, "love the way"); _delay_ms(3000); LCD_Clear();
	
	LCD_String_xy(0, 5, "you're");
	LCD_String_xy(1, 0, "running out of"); _delay_ms(4000); LCD_Clear();
	
	LCD_String_xy(0, 2, "LIFE !!!"); 
	LCD_Cmd(0xC0); LCD_Char(0);  LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); LCD_Char(0); _delay_ms(5000); LCD_Clear();
	
	chorus();
	
	
	
	LCD_String_xy(0, 1, "guitar solo"); LCD_String(" "); LCD_Char(3); _delay_ms(2000);
	LCD_Cmd(0xC0);
	for(int i=5; i<20; i++){
			LCD_Cmd(0x04); LCD_Char(5); 
			LCD_Char(6); 
			LCD_Char(7); 
			LCD_Char(6); 
			LCD_Char(5); LCD_Cmd(0x1C);
		} _delay_ms(36500);
	LCD_Clear();
                                                                                                                         
	
	LCD_String_xy(0, 3, "Your Turn"); _delay_ms(3000); LCD_Clear();
	
	chorus();
	
	LCD_String_xy(0, 0, "made by");
	LCD_String_xy(1, 6, "njunu");
	
	}
	


