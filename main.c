/*
 * File:   main.c
 * Author: Marek
 *
 * Created on 02. Mai 2018, 17:24
 */


#include "xc.h"
#include "init.h"
#include "timer.h"

//lets set the device configuration bits using the pre-processor macros
//_FOSC(PRI & XT_PLL8 & CSW_FSCM_OFF );
//primary oscillator with 8 times pll no clock switching
//_FWDT(WDT_OFF);
//watch dog is disabled
//_FBORPOR( PBOR_OFF & MCLR_EN & PWRT_64 & PWMxL_ACT_HI & PWMxH_ACT_LO &RST_PWMPIN);
//brown out disabled, master-clear enabled, power on reset time = 64ms
//pwm low side is active high, pwm high side is active low,
//reset state controlled with HPOL/LPOL bits
int main(void)
{
    init();/*
    init_out(14);
    unsigned int status = 0;
    int increment = -1;
    unsigned int i;
    P1DC1 = 10;*/
    while(1)
    {/*
        status  = ~status;
        for(i = 0; i < 20000; i++){
            
        }
        if(P1DC1 == 17)
            increment = -1;
        if(P1DC1 == 0)
            increment = 1;
        P1DC1 += increment;
        //P1DC1 = 15;*/
    }
}

