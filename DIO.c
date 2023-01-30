/*
 * DIO.c
 *
 * Created: 9/24/2022 10:14:01 AM
 *  Author: LENOVO
 */ 
#include "DIO.h"

void SetPin_Output (unsigned char Port , unsigned char PinNum) 
{
	switch (Port)
	{
		case 0:
		DDRA=DDRA|1<<PinNum;
		break; 
		case 1:
		DDRB=DDRB|1<<PinNum;
		break;
		case 2:
		DDRC=DDRC|1<<PinNum;
		break;
		case 3:
		DDRD=DDRD|1<<PinNum;
		break;
		default:
	
		break;
	}
	
	

}
void SetPin_Input (unsigned char Port , unsigned char PinNum) 
{
	switch (Port)
	{
		case 0:
		DDRA=DDRA&~(1<<PinNum);
		break;
		case 1:
		DDRB=DDRB&~(1<<PinNum);
		break;
		case 2:
		DDRC=DDRC&~(1<<PinNum);
		break;
		case 3:
		DDRD=DDRD&~(1<<PinNum);
		break;
		default:
		
		break;
	}
}
void Set_Pin (unsigned char Port , unsigned char PinNum) 
{
	switch (Port)
	{
		case 0:
		PORTA=PORTA|1<<PinNum;
		break;
		case 1:
		PORTB=PORTB|1<<PinNum;
		break;
		case 2:
		PORTC=PORTC|1<<PinNum;
		break;
		case 3:
		PORTD=PORTD|1<<PinNum;
		break;
		default:
		
		break;
	}
}
void Clear_Pin (unsigned char Port , unsigned char PinNum) 
{
	switch (Port)
	{
		case 0:
		PORTA=PORTA&~(1<<PinNum);
		break;
		case 1:
		PORTB=PORTB&~(1<<PinNum);
		break;
		case 2:
		PORTC=PORTC&~(1<<PinNum);
		break;
		case 3:
		PORTD=PORTD&~(1<<PinNum);
		break;
		default:
		
		break;
	}
}
void Toggle_Pin (unsigned char Port , unsigned char PinNum) 
{
	switch (Port)
	{
		case 0:
		PORTA=PORTA^1<<PinNum;
		break;
		case 1:
		PORTB=PORTB^1<<PinNum;
		break;
		case 2:
		PORTC=PORTC^1<<PinNum;
		break;
		case 3:
		PORTD=PORTD^1<<PinNum;
		break;
		default:
		
		break;
	}
	
	
} 
unsigned char Get_Pin (unsigned char Port , unsigned char PinNum)
{ unsigned char x;
	switch (Port)
	{
		case 0:
		x=(PINA>>PinNum)&1;
		break;
		case 1:
		x=(PINB>>PinNum)&1;
		break;
		case 2:
		x=(PINC>>PinNum)&1;
		break;
		case 3:
		x=(PIND>>PinNum)&1;
		break;
		default:
		
		break;
	} 
	return x;
}