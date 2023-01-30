/*
 * LCD.c
 *
 * Created: 9/27/2022 3:49:53 PM
 *  Author: LENOVO
 */ 
#include "LCD.h" 
#include <math.h>
void LCD_init(void)
{
	SetPin_Output(PIN_RS_PORT,PIN_RS_PIN);
	SetPin_Output(PIN_RW_PORT,PIN_RW_PIN);
	SetPin_Output(PIN_E_PORT,PIN_E_PIN); 
	SetPin_Output(LCD_04_PORT,LCD_04_PIN); 
	SetPin_Output(LCD_05_PORT,LCD_05_PIN);
	SetPin_Output(LCD_06_PORT,LCD_06_PIN);
	SetPin_Output(LCD_07_PORT,LCD_07_PIN); 
	Clear_Pin(PIN_RW_PORT,PIN_RW_PIN); 
	LCD_write_command(0x3);
	_delay_ms(4); 
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4); 
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x01);
	LCD_write_command(0x06);
	LCD_write_command(0x0c);
	_delay_ms(20);
	

	
}

void LCD_write_command(unsigned char cmd )
{  
	Clear_Pin(PIN_RS_PORT,PIN_RS_PIN);
	
	if(REDBIT(cmd,7))
	Set_Pin(LCD_07_PORT,LCD_07_PIN); 
	else 
	Clear_Pin(LCD_07_PORT,LCD_07_PIN); 
	
	if(REDBIT(cmd,6))
	Set_Pin(LCD_06_PORT,LCD_06_PIN);
	else
	Clear_Pin(LCD_06_PORT,LCD_06_PIN);
	
	if(REDBIT(cmd,5))
	Set_Pin(LCD_05_PORT,LCD_05_PIN);
	else
	Clear_Pin(LCD_05_PORT,LCD_05_PIN);
	
	if(REDBIT(cmd,4))
	Set_Pin(LCD_04_PORT,LCD_04_PIN);
	else
	Clear_Pin(LCD_04_PORT,LCD_04_PIN); 
	
	Set_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	Clear_Pin(PIN_E_PORT,PIN_E_PIN); 
	_delay_ms(1);  
	
	if(REDBIT(cmd,3))
	Set_Pin(LCD_07_PORT,LCD_07_PIN);
	else
	Clear_Pin(LCD_07_PORT,LCD_07_PIN);
	
	if(REDBIT(cmd,2))
	Set_Pin(LCD_06_PORT,LCD_06_PIN);
	else
	Clear_Pin(LCD_06_PORT,LCD_06_PIN);
	
	if(REDBIT(cmd,1))
	Set_Pin(LCD_05_PORT,LCD_05_PIN);
	else
	Clear_Pin(LCD_05_PORT,LCD_05_PIN);
	
	if(REDBIT(cmd,0))
	Set_Pin(LCD_04_PORT,LCD_04_PIN);
	else
	Clear_Pin(LCD_04_PORT,LCD_04_PIN);
	
	Set_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	Clear_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	
	
	
}

void LCD_write_char (unsigned char data )
{ 
	Set_Pin(PIN_RS_PORT,PIN_RS_PIN);
	
	if(REDBIT(data,7))
	Set_Pin(LCD_07_PORT,LCD_07_PIN);
	else
	Clear_Pin(LCD_07_PORT,LCD_07_PIN);
	
	if(REDBIT(data,6))
	Set_Pin(LCD_06_PORT,LCD_06_PIN);
	else
	Clear_Pin(LCD_06_PORT,LCD_06_PIN);
	
	if(REDBIT(data,5))
	Set_Pin(LCD_05_PORT,LCD_05_PIN);
	else
	Clear_Pin(LCD_05_PORT,LCD_05_PIN);
	
	if(REDBIT(data,4))
	Set_Pin(LCD_04_PORT,LCD_04_PIN);
	else
	Clear_Pin(LCD_04_PORT,LCD_04_PIN);
	
	Set_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	Clear_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	
	if(REDBIT(data,3))
	Set_Pin(LCD_07_PORT,LCD_07_PIN);
	else
	Clear_Pin(LCD_07_PORT,LCD_07_PIN);
	
	if(REDBIT(data,2))
	Set_Pin(LCD_06_PORT,LCD_06_PIN);
	else
	Clear_Pin(LCD_06_PORT,LCD_06_PIN);
	
	if(REDBIT(data,1))
	Set_Pin(LCD_05_PORT,LCD_05_PIN);
	else
	Clear_Pin(LCD_05_PORT,LCD_05_PIN);
	
	if(REDBIT(data,0))
	Set_Pin(LCD_04_PORT,LCD_04_PIN);
	else
	Clear_Pin(LCD_04_PORT,LCD_04_PIN);
	
	Set_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	Clear_Pin(PIN_E_PORT,PIN_E_PIN);
	_delay_ms(1);
	
} 

void LCD_write_string (unsigned char * ptr){
	
	while(*ptr!='\0')
	{
		LCD_write_char(*ptr);
		ptr++;
	}
	
	
	
	
	
} 

void LCD_write_num(uint16_t data)
{ 
	  signed char i;
	unsigned char arr[5];
	if(data==0) 
	LCD_write_char('0');
	
	for (i=0;data!=0;i++)
	{ 
		arr[i]=data%10 +48;
		data=data/10;
	} 
	i--;
	while (i>=0)
	{ 
		LCD_write_char(arr[i]);
		i--;
	}
	
	
}

void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_write_command (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_write_char(msg[i]);
	}
}