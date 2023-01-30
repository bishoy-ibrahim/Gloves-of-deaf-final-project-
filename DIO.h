/*
 * DIO.h
 *
 * Created: 9/24/2022 10:03:30 AM
 *  Author: LENOVO
 */ 


#ifndef DIO_H_
#define DIO_H_
#define F_CPU 16000000UL
#include <util/delay.h> 
#include <avr/io.h> 

void SetPin_Output (unsigned char Port , unsigned char PinNum);
void SetPin_Input (unsigned char Port , unsigned char PinNum); 
void Set_Pin (unsigned char Port , unsigned char PinNum);
void Clear_Pin (unsigned char Port , unsigned char PinNum);
void Toggle_Pin (unsigned char Port , unsigned char PinNum); 
unsigned char Get_Pin (unsigned char Port , unsigned char PinNum);  

#define SETBIT(REG,BIT) (REG|=1<<BIT)
#define CLRBIT(REG,BIT) (REG &=~(1<<BIT))
#define TOGBIT(REG,BIT) (REG^=1<<BIT)
#define REDBIT(REG,BIT) ((REG>>BIT)&1)



#endif /* DIO_H_ */