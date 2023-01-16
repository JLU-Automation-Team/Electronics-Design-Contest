#define INFRARED_STATE() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN)

#define infrared_PORT GPIOD
#define infrared_PIN GPIO_Pin_1
#define infrared_RCC RCC_APB2Periph_GPIOD

#define INFRARED_STATE() GPIO_ReadInputDataBit(infrared_PORT,infrared_PIN)