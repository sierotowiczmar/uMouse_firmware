#include "gpio.h"

void init_pwm(int pwm){
    switch(pwm){
        case 1: 
            P1TCONbits.PTEN = 0;
            P1TCONbits.PTCKPS = 1;
            P1TPER = 500;
            PWM1CON1bits.PMOD1 = 0;
            PWM1CON1bits.PEN1H = 1;
            PWM1CON1bits.PEN1L = 1;
            P1TCONbits.PTEN = 1;
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }
}

void set_duty_cycle(uint16_t pwm, float duty_cycle){
    switch(pwm){
        case 1:
            P1DC1 = (uint16_t)duty_cycle*0xFFFF;
            break;
    }
}

void init_out(uint8_t pin){
    TRISB &= ~(1 << pin);
}

void set_out(uint8_t pin, uint8_t value){
    if(value)
        PORTB |= (1 << pin);
    else
        PORTB &= ~(1 << pin);
}

void init_inp(uint8_t pin){
    TRISB |= (1 << pin);
}

uint16_t read_inp(uint8_t pin) //should return 1 or 0
{
    return (LATB & (1 << pin)) >> pin;
}
