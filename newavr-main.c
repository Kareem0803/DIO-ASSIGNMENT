/*
 * File:   newavr-main.c
 * Author: kimom
 *
 * Created on May 24, 2022, 11:25 AM
 */


#define F_CPU 16000000UL
#include <xc.h>
#include <util/delay.h>
#include <avr/io.h>
#define ON 1
#define OFF 0
#define LED0_DIR DDRC2
#define LED0     PORTC2
#define LED1_DIR DDRC7
#define LED1     PORTC7
#define LED2_DIR DDRD3
#define LED2     PORTD3
#define BTN0_DIR DDRB0
#define BTN0     PORTB0
#define BTN1_DIR DDRD6
#define BTN1     PORTD6
#define BTN2_DIR DDRD2
#define BTN2     PORTD2

void LEDs_init(void);
void BTNs_init(void);
unsigned char IsPressed(unsigned char BTN_no);
void setLED(unsigned char LED_no, unsigned char state);
// Looking for a job
int main(void) {
    /* Replace with your application code */
    LEDs_init();
    BTNs_init();
    while (1) {
        if (IsPressed(BTN0)) {
            setLED(LED0, ON);
        } else if (IsPressed(BTN1)) {

            setLED(LED1, ON);

        } else if (IsPressed(BTN2)) {

            setLED(LED2, ON);
        } else {
            setLED(LED0, OFF);
            setLED(LED1, OFF);
            setLED(LED2, OFF);
        }
    }
}

void LEDs_init(void) {
    DDRC |= (1 << LED0_DIR) | (1 << LED1_DIR);
    DDRD |= (1 << LED2_DIR);
}

void BTNs_init(void) {
    DDRB &= ~(1 << BTN0_DIR);
    DDRD &= ~(1 << BTN1_DIR);
    DDRD &= ~(1 << BTN2_DIR);
}

unsigned char IsPressed(unsigned char BTN_no) {
    if (BTN_no == BTN0) {
        if (PINB & (1 << BTN0)) {
            return 1;
        } else {
            return 0;
        }
    } else if (BTN_no == BTN1) {
        if (PIND & (1 << BTN1)) {
            return 1;
        } else {
            return 0;
        }

    } else if (BTN_no == BTN2) {
        if (PIND & (1 << BTN2)) {
            return 1;
        } else {
            return 0;
        }

    } else {
        return 0;
    }
}

void setLED(unsigned char LED_no, unsigned char state) {
    switch (LED_no) {
        case LED0:
            if (state == 1) {
                PORTC |= (1 << LED0);
                break;
            } else if (state == 0) {
                PORTC &= ~(1 << LED0);
                break;
            } else {
                break;
            }
        case LED1:
            if (state == 1) {
                PORTC |= (1 << LED1);
                break;
            } else if (state == 0) {
                PORTC &= ~(1 << LED1);
                break;
            } else {
                break;
            }
        case LED2:
            if (state == 1) {
                PORTD |= (1 << LED2);
                break;
            } else if (state == 0) {
                PORTD &= ~(1 << LED2);
                break;
            } else {
                break;
            }

    }
}