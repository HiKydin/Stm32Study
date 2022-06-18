#ifndef _STM32F10X_H
#define _STM32F10X_H

#define PERIPH_BASH          ((unsigned int)0x40000000)
#define APB1_PERIPH_BASH     PERIPH_BASH
#define APB2_PERIPH_BASH     (PERIPH_BASH + 0x10000)
#define AHB_PERIPH_BASH      (PERIPH_BASH + 0x20000)

#define RCC_BASE            (AHB_PERIPH_BASH + 0x1000)
#define GPIOB_BASE           (APB2_PERIPH_BASH + 0x0C00)

#define RCC_APB2ENR         *(unsigned int*)(RCC_BASE+0x18)
    
#define GPIOB_CRL     *(unsigned int*)(GPIOB_BASE + 0x00)
#define GPIOB_CRH     *(unsigned int*)(GPIOB_BASE + 0x04)    
#define GPIOB_IDR     *(unsigned int*)(GPIOB_BASE + 0x08)
#define GPIOB_ODR     *(unsigned int*)(GPIOB_BASE + 0x0C)
#define GPIOB_BSRR    *(unsigned int*)(GPIOB_BASE + 0x10)
#define GPIOB_BRR     *(unsigned int*)(GPIOB_BASE + 0x14)
#define GPIOB_LCKR    *(unsigned int*)(GPIOB_BASE + 0x18)    

#define RCC_CR            *(unsigned int*)(RCC_BASE + 0x00)
#define RCC_CFGR          *(unsigned int*)(RCC_BASE + 0x04)
#define RCC_CIR           *(unsigned int*)(RCC_BASE + 0x08)
#define RCC_APB2RSTR      *(unsigned int*)(RCC_BASE + 0x0C)
#define RCC_APB1RSTR      *(unsigned int*)(RCC_BASE + 0x10)
#define RCC_AHBENR        *(unsigned int*)(RCC_BASE + 0x14)
#define RCC_APB2ENR       *(unsigned int*)(RCC_BASE + 0x18)
#define RCC_APB1ENR       *(unsigned int*)(RCC_BASE + 0x1C)
#define RCC_BDCR          *(unsigned int*)(RCC_BASE + 0x20)
#define RCC_CSR           *(unsigned int*)(RCC_BASE + 0x24)    

typedef unsigned int u32;
typedef unsigned short u16;


typedef struct
{
    u32 CRL;
    u32 CRH;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 BRR;
    u32 LCKR;
    
}GPIO_TypeDef;

typedef struct
{
    u32 CR;
    u32 CFGR;
    u32 CIR;
    u32 APB2RSTR;
    u32 APB1RSTR;
    u32 AHBENR;
    u32 APB2ENR;
    u32 APB1ENR;
    u32 BDCR;
    u32 CSR;
    
}RCC_TypeDef;

#define GPIOB ((GPIO_TypeDef *)(GPIOB_BASE))
#define RCC   ((RCC_TypeDef *)(RCC_BASE))

#endif /* _STM32F10X_H */
