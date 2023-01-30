/*
 * Diploma_proj.cpp
 *
 * Created: 1/27/2023 7:02:02 PM
 * Author : LENOVO
 */ 

#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"

char alef[] = {
	0b00110,
	0B01100,
	0B00100,
	0B00100,
	0B00100,
	0B00100,
	0B00100,
	0B00100
};

char haah[] = {
	0B00000,
	0B00100,
	0B00010,
	0B11111,
	0B00000,
	0B00000,
	0B00000,
	0B00000
};
char beeh[] = {
	0B00000,
	0B00000,
	0B00001,
	0B11111,
	0B00100,
	0B00000,
	0B00000,
	0B00000
};
char kaaf[] = {
	0B00001,
	0B01101,
	0B01101,
	0B11111,
	0B00000,
	0B00000,
	0B00000,
	0B00000
};

char noon[] = {
0B00000,
0B00000,
0B10101,
0B10001,
0B01110,
0B00000,
0B00000,
0B00000
}; 

char teeh[] = {
	0B00000,
	0B01110,
	0B10001,
	0B11111,
	0B00000,
	0B00000,
	0B00000,
	0B00000
};



char raah[] = {
	0B00000,
	0B00000,
	0B00001,
	0B00001,
	0B00010,
	0B00100,
	0B01000,
	0B10000
};

char qaaf[] = {
	0B00011,
	0B00000,
	0B00111,
	0B00101,
	0B11111,
	0B00000,
	0B00000,
	0B00000
};




int main(void)
{ 
	LCD_init();
	LCD_Custom_Char(0, alef);
	LCD_Custom_Char(1, haah);
	LCD_Custom_Char(2,beeh);
	LCD_Custom_Char(3,kaaf);
	LCD_Custom_Char(4,noon);
	LCD_Custom_Char(5,teeh);
	LCD_Custom_Char(6,qaaf);
	LCD_Custom_Char(7,raah);
	
	//SetPin_Input(2,1);
	//LCD_write_command(0x8f);
	//LCD_write_char(0);
	
    while (1) 
    { 
		while (REDBIT(PINC,1)==1 && REDBIT(PINC,3)==1 && REDBIT(PINC,4)==1 && REDBIT(PINC,5)==1 && REDBIT(PINC,2)==0)
		{
			LCD_write_command(0x8f);
			LCD_write_char(0);
			LCD_write_command(0x8e);
			LCD_write_char(4);
			LCD_write_command(0x8d);
			LCD_write_char(5);
		
		}
		LCD_write_command(0x01);
		while (REDBIT(PINC,1)==1 && REDBIT(PINC,4)==1 && REDBIT(PINC,5)==1 && REDBIT(PINC,2)==0 && REDBIT(PINC,3)==0)
		{ 
			
			LCD_write_command(0x8f);
			LCD_write_char(0);
			LCD_write_command(0x8e);
			LCD_write_char(4);
			LCD_write_command(0x8d);
			LCD_write_char(0);
			LCD_write_command(0x8c);
			LCD_write_char(0);
			LCD_write_command(0x8b);
			LCD_write_char(7);
			LCD_write_command(0x8a);
			LCD_write_char(0);
			LCD_write_command(0x89);
			LCD_write_char(6);
			LCD_write_command(0x88);
			LCD_write_char(2);
			LCD_write_command(0x87);
			LCD_write_char(3);
			
		}
		LCD_write_command(0x01);
		while(REDBIT(PINC,4)==1 && REDBIT(PINC,1)==0 && REDBIT(PINC,2)==0 && REDBIT(PINC,3)==0 && REDBIT(PINC,5)==0)
		{
			
			LCD_write_command(0x8f);
			LCD_write_char(1);
			LCD_write_command(0x8e);
			LCD_write_char(6);
			LCD_write_command(0x8d);
			LCD_write_char(0);
			LCD_write_command(0x8c);
			LCD_write_char(0);
			LCD_write_command(0x8b);
			LCD_write_char(1);
			LCD_write_command(0x8a);
			LCD_write_char(2);
			LCD_write_command(0x89);
			LCD_write_char(3);
			
		}
		LCD_write_command(0x01);
		while(REDBIT(PINC,4)==1 && REDBIT(PINC,1)==0 && REDBIT(PINC,2)==0 && REDBIT(PINC,3)==1 && REDBIT(PINC,5)==0)
		{
			
			LCD_write_command(0x8f);
			LCD_write_char(0);
			LCD_write_command(0x8e);
			LCD_write_char(1);
			LCD_write_command(0x8d);
			LCD_write_char(2);
			LCD_write_command(0x8c);
			LCD_write_char(3);
			
		}
		LCD_write_command(0x01);
		while(REDBIT(PINC,4)==1 && REDBIT(PINC,1)==1 && REDBIT(PINC,2)==0 && REDBIT(PINC,3)==1 && REDBIT(PINC,5)==0)
		{
			
			LCD_write_command(0x80);
			char arr[]={"thats terrible"};
			LCD_write_string(arr);
			
		}
		LCD_write_command(0x01);
		while(REDBIT(PINC,4)==0 && REDBIT(PINC,1)==0 && REDBIT(PINC,2)==0 && REDBIT(PINC,3)==0 && REDBIT(PINC,5)==0)
		{
			
			LCD_write_command(0x80);
			char arr[]={"wish you a happy"};
			LCD_write_string(arr);
			LCD_write_command(0xc0);
			LCD_write_char('l');
			LCD_write_char('i');
			LCD_write_char('f');
			LCD_write_char('e');
			
		}
		LCD_write_command(0x01);
		while(REDBIT(PINC,4)==1 && REDBIT(PINC,1)==0 && REDBIT(PINC,2)==1 && REDBIT(PINC,3)==1 && REDBIT(PINC,5)==1)
		{
			
			LCD_write_command(0x80);
			char arr[]={"good job"};
			LCD_write_string(arr);
			
			
		}
		LCD_write_command(0x01);
    
	}

}