
#ifndef     GPIO_H
#define     GPIO_H

// cmsis mcu spesific header file.
#include "stm32f1xx.h"
#include "stdint.h"
 
#define PORTA   GPIOA
#define PORTB   GPIOB
#define PORTC   GPIOC


/*   PIN MODES   */
#define OUTPUT_MODE     ((uint32_t)0x01)
#define INPUT_MODE      ((uint32_t)0x02)

/*INPUT MODES TYPES */ 
#define INPUT_ANALOG       ((uint32_t)0x00)
#define INPUT_FLOATING     ((uint32_t)0x01)     // default at reset
#define INPUT_PU_PD        ((uint32_t)0x02)     // input 



/*  OUTPUT MODE TYPES */ 
// what is he meant by atomic
// in the structur you don't have to work in sequence
// and the gpio_init function should be called last
#define OUTPUT_GEN_PURPOSE      ((uint32_t)0x00)
#define OUTPUT_OD               ((uint32_t)0x01)
#define OUTPUT_ALT_FUN          ((uint32_t)0x02)
#define OUTPUT_ALT_FUN_OD       ((uint32_t)0x03)


/* PIN SPEEDS*/
#define SPEED_2MHZ  ((uint32_t)0x02)
#define SPEED_10MHZ  ((uint32_t)0x01)
#define SPEED_50MHZ  ((uint32_t)0x03)


// clock enabling
#define GPIO_CLOCK_ENABLE_ALT_FUNC  ((RCC->APB2ENR |=(1<<0)))
#define GPIO_CLOCK_ENABLE_PORTA     ((RCC->APB2ENR |=(1<<1)))
#define GPIO_CLOCK_ENABLE_PORTB  ((RCC->APB2ENR |=(1<<2)))
#define GPIO_CLOCK_ENABLE_PORTC  ((RCC->APB2ENR |=(1<<3)))


#define CNF_POS_BIT1  (PINPOS[pinNumber] + 2)
#define CNF_POS_BIT2  (PINPOS[pinNumber] + 3)


// configuration struction
typedef struct GPIO
{
    /* data */
    GPIO_TypeDef    *port;
    uint32_t        pin;
    uint32_t        mode;
    uint32_t        mode_type;
    uint32_t        pull;
    uint32_t        speed;
    uint32_t        alt_func;

}GPIO_TYPE;

/** USER FUNCTIONS ***/
static void config_pin (GPIO_TypeDef *port , uint32_t pinNumber, uint32_t mode_type);
static void config_pin_speed (GPIO_TypeDef *port , uint32_t pinNumber, uint32_t pin_speed, uint32_t mode);
void gpio_write(GPIO_TypeDef*  port , uint32_t pinNumber, uint8_t state);

void gpio_toggle(GPIO_TypeDef* port, uint32_t pinNumber);
void gpio_init(GPIO_TYPE gpio_type );


#endif
