#include "timer.h"
#include "gpio.h"
#include "adc.h"


void init_timer(int timer, uint16_t period, uint16_t prescaler){
    switch(timer){
        case 1:
            T1CONbits.TON = 0;
            TMR1 = 0;
            T1CONbits.TCKPS = prescaler;
            PR1 = period;
            T1CONbits.TCS = 0;
            T1CONbits.TSIDL = 1;
            T1CONbits.TGATE = 0;
            IFS0bits.T1IF = 0; ///reset the timer 1 interrupt flag
            IPC0bits.T1IP = 4;
            IEC0bits.T1IE = 1;
            T1CONbits.TON = 1;
            break;
        case 2:
            T2CONbits.TON = 0;
            TMR2 = 0;
            T2CONbits.TCKPS = prescaler;
            PR2 = period;
            T2CONbits.TCS = 0;
            T2CONbits.TSIDL = 1;
            T2CONbits.TGATE = 0;
            IFS0bits.T2IF=0; ///reset the timer 1 interrupt flag
            IPC1bits.T2IP = 3;
            IEC0bits.T2IE = 1;
            T2CONbits.TON = 1;
            break;
        default:
            break;
    }
}


//So, the idea would be to have one interrupt for the period in IR sensor 
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
IFS0bits.T1IF=0; ///reset the timer 1 interrupt flag

static unsigned int super_period = 0;

//ed_state = ~led_state;
super_period =  (super_period + 1)%8;

    switch(super_period){
        case 0:
            set_out(13, 1);
            set_measurement();
            AD1CON1bits.ASAM=1; //we start the autosampling in the timer ISR
            break;
        case 1:
            set_out(13, 0);
            break;
        default:
            break;
    }
}

void __attribute__((interrupt, auto_psv)) _T2Interrupt(void)
{
IFS0bits.T2IF=0; ///reset the timer 1 interrupt flag

static unsigned int super_period = 0;

super_period =  (super_period + 1)%8;

    switch(super_period){
        case 0:
            set_out(15, 1);
            break;
        case 1:
            set_out(15, 0);
            break;
        default:
            break;
    }
}

