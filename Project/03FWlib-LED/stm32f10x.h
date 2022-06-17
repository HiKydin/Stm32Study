
#define PERIPH_BASH          ((unsigned int)0x40000000)
#define APB1_PERIPH_BASH     PERIPH_BASH
#define APB2_PERIPH_BASH     (PERIPH_BASH + 0x10000)
#define AHB_PERIPH_BASH      (PERIPH_BASH + 0x20000)

#define RCC_BASE            (AHB_PERIPH_BASH + 0x1000)
#define GPIOB_BASE           (APB2_PERIPH_BASH + 0x0C00)

#define RCC_APB2ENR         *(unsigned int*)(RCC_BASE+0x18)
    
#define GPIOB_CRL    *(unsigned int*)(GPIOB_BASE + 0x00)
#define GPIOB_CRH    *(unsigned int*)(GPIOB_BASE + 0x04)    
#define GPIOB_IDR    *(unsigned int*)(GPIOB_BASE + 0x08)
#define GPIOB_ODR    *(unsigned int*)(GPIOB_BASE + 0x0C)
#define GPIOB_BSRR    *(unsigned int*)(GPIOB_BASE + 0x10)
#define GPIOB_BRR    *(unsigned int*)(GPIOB_BASE + 0x14)
#define GPIOB_LCKR    *(unsigned int*)(GPIOB_BASE + 0x18)    

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


#define GPIOB ((GPIO_TypeDef *)(GPIOB_BASE))