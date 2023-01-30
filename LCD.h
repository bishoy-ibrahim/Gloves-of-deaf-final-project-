/*
 * LCD.h
 *
 * Created: 9/27/2022 3:49:41 PM
 *  Author: LENOVO
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"  

#define PIN_RS_PORT 1
#define PIN_RS_PIN 1 

#define PIN_RW_PORT 1
#define PIN_RW_PIN 2

#define PIN_E_PORT 1
#define PIN_E_PIN 3  

#define LCD_04_PORT 0
#define LCD_04_PIN 4 

#define LCD_05_PORT 0
#define LCD_05_PIN 5

#define LCD_06_PORT 0
#define LCD_06_PIN 6 

#define LCD_07_PORT 0
#define LCD_07_PIN 7






void LCD_init(void);

void LCD_write_command(unsigned char cmd);

void LCD_write_char (unsigned char data );

void LCD_write_string (unsigned char *);

void LCD_write_num(uint16_t data);

void LCD_Custom_Char (unsigned char loc, unsigned char *);

#endif /* LCD_H_ */