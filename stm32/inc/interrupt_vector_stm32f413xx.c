/* This file is generated automatically. */

#define WEAK __attribute__ ((weak, alias("Default_Handler")))

/* Interrupt handler declarations */
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void MemManage_Handler(void);
WEAK void BusFault_Handler(void);
WEAK void UsageFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void DebugMon_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void WWDG_IRQHandler(void);
WEAK void PVD_IRQHandler(void);
WEAK void TAMP_STAMP_IRQHandler(void);
WEAK void RTC_WKUP_IRQHandler(void);
WEAK void FLASH_IRQHandler(void);
WEAK void RCC_IRQHandler(void);
WEAK void EXTI0_IRQHandler(void);
WEAK void EXTI1_IRQHandler(void);
WEAK void EXTI2_IRQHandler(void);
WEAK void EXTI3_IRQHandler(void);
WEAK void EXTI4_IRQHandler(void);
WEAK void DMA1_Stream0_IRQHandler(void);
WEAK void DMA1_Stream1_IRQHandler(void);
WEAK void DMA1_Stream2_IRQHandler(void);
WEAK void DMA1_Stream3_IRQHandler(void);
WEAK void DMA1_Stream4_IRQHandler(void);
WEAK void DMA1_Stream5_IRQHandler(void);
WEAK void DMA1_Stream6_IRQHandler(void);
WEAK void ADC_IRQHandler(void);
WEAK void CAN1_TX_IRQHandler(void);
WEAK void CAN1_RX0_IRQHandler(void);
WEAK void CAN1_RX1_IRQHandler(void);
WEAK void CAN1_SCE_IRQHandler(void);
WEAK void EXTI9_5_IRQHandler(void);
WEAK void TIM1_BRK_TIM9_IRQHandler(void);
WEAK void TIM1_UP_TIM10_IRQHandler(void);
WEAK void TIM1_TRG_COM_TIM11_IRQHandler(void);
WEAK void TIM1_CC_IRQHandler(void);
WEAK void TIM2_IRQHandler(void);
WEAK void TIM3_IRQHandler(void);
WEAK void TIM4_IRQHandler(void);
WEAK void I2C1_EV_IRQHandler(void);
WEAK void I2C1_ER_IRQHandler(void);
WEAK void I2C2_EV_IRQHandler(void);
WEAK void I2C2_ER_IRQHandler(void);
WEAK void SPI1_IRQHandler(void);
WEAK void SPI2_IRQHandler(void);
WEAK void USART1_IRQHandler(void);
WEAK void USART2_IRQHandler(void);
WEAK void USART3_IRQHandler(void);
WEAK void EXTI15_10_IRQHandler(void);
WEAK void RTC_Alarm_IRQHandler(void);
WEAK void OTG_FS_WKUP_IRQHandler(void);
WEAK void TIM8_BRK_TIM12_IRQHandler(void);
WEAK void TIM8_UP_TIM13_IRQHandler(void);
WEAK void TIM8_TRG_COM_TIM14_IRQHandler(void);
WEAK void TIM8_CC_IRQHandler(void);
WEAK void DMA1_Stream7_IRQHandler(void);
WEAK void FSMC_IRQHandler(void);
WEAK void SDIO_IRQHandler(void);
WEAK void TIM5_IRQHandler(void);
WEAK void SPI3_IRQHandler(void);
WEAK void UART4_IRQHandler(void);
WEAK void UART5_IRQHandler(void);
WEAK void TIM6_DAC_IRQHandler(void);
WEAK void TIM7_IRQHandler(void);
WEAK void DMA2_Stream0_IRQHandler(void);
WEAK void DMA2_Stream1_IRQHandler(void);
WEAK void DMA2_Stream2_IRQHandler(void);
WEAK void DMA2_Stream3_IRQHandler(void);
WEAK void DMA2_Stream4_IRQHandler(void);
WEAK void DFSDM1_FLT0_IRQHandler(void);
WEAK void DFSDM1_FLT1_IRQHandler(void);
WEAK void CAN2_TX_IRQHandler(void);
WEAK void CAN2_RX0_IRQHandler(void);
WEAK void CAN2_RX1_IRQHandler(void);
WEAK void CAN2_SCE_IRQHandler(void);
WEAK void OTG_FS_IRQHandler(void);
WEAK void DMA2_Stream5_IRQHandler(void);
WEAK void DMA2_Stream6_IRQHandler(void);
WEAK void DMA2_Stream7_IRQHandler(void);
WEAK void USART6_IRQHandler(void);
WEAK void I2C3_EV_IRQHandler(void);
WEAK void I2C3_ER_IRQHandler(void);
WEAK void CAN3_TX_IRQHandler(void);
WEAK void CAN3_RX0_IRQHandler(void);
WEAK void CAN3_RX1_IRQHandler(void);
WEAK void CAN3_SCE_IRQHandler(void);
WEAK void RNG_IRQHandler(void);
WEAK void FPU_IRQHandler(void);
WEAK void UART7_IRQHandler(void);
WEAK void UART8_IRQHandler(void);
WEAK void SPI4_IRQHandler(void);
WEAK void SPI5_IRQHandler(void);
WEAK void SAI1_IRQHandler(void);
WEAK void UART9_IRQHandler(void);
WEAK void UART10_IRQHandler(void);
WEAK void QUADSPI_IRQHandler(void);
WEAK void FMPI2C1_EV_IRQHandler(void);
WEAK void FMPI2C1_ER_IRQHandler(void);
WEAK void LPTIM1_IRQHandler(void);
WEAK void DFSDM2_FLT0_IRQHandler(void);
WEAK void DFSDM2_FLT1_IRQHandler(void);
WEAK void DFSDM2_FLT2_IRQHandler(void);
WEAK void DFSDM2_FLT3_IRQHandler(void);

/* Interrupt table */
__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
  (void*)&_estack,
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,
  WWDG_IRQHandler,
  PVD_IRQHandler,
  TAMP_STAMP_IRQHandler,
  RTC_WKUP_IRQHandler,
  FLASH_IRQHandler,
  RCC_IRQHandler,
  EXTI0_IRQHandler,
  EXTI1_IRQHandler,
  EXTI2_IRQHandler,
  EXTI3_IRQHandler,
  EXTI4_IRQHandler,
  DMA1_Stream0_IRQHandler,
  DMA1_Stream1_IRQHandler,
  DMA1_Stream2_IRQHandler,
  DMA1_Stream3_IRQHandler,
  DMA1_Stream4_IRQHandler,
  DMA1_Stream5_IRQHandler,
  DMA1_Stream6_IRQHandler,
  ADC_IRQHandler,
  CAN1_TX_IRQHandler,
  CAN1_RX0_IRQHandler,
  CAN1_RX1_IRQHandler,
  CAN1_SCE_IRQHandler,
  EXTI9_5_IRQHandler,
  TIM1_BRK_TIM9_IRQHandler,
  TIM1_UP_TIM10_IRQHandler,
  TIM1_TRG_COM_TIM11_IRQHandler,
  TIM1_CC_IRQHandler,
  TIM2_IRQHandler,
  TIM3_IRQHandler,
  TIM4_IRQHandler,
  I2C1_EV_IRQHandler,
  I2C1_ER_IRQHandler,
  I2C2_EV_IRQHandler,
  I2C2_ER_IRQHandler,
  SPI1_IRQHandler,
  SPI2_IRQHandler,
  USART1_IRQHandler,
  USART2_IRQHandler,
  USART3_IRQHandler,
  EXTI15_10_IRQHandler,
  RTC_Alarm_IRQHandler,
  OTG_FS_WKUP_IRQHandler,
  TIM8_BRK_TIM12_IRQHandler,
  TIM8_UP_TIM13_IRQHandler,
  TIM8_TRG_COM_TIM14_IRQHandler,
  TIM8_CC_IRQHandler,
  DMA1_Stream7_IRQHandler,
  FSMC_IRQHandler,
  SDIO_IRQHandler,
  TIM5_IRQHandler,
  SPI3_IRQHandler,
  UART4_IRQHandler,
  UART5_IRQHandler,
  TIM6_DAC_IRQHandler,
  TIM7_IRQHandler,
  DMA2_Stream0_IRQHandler,
  DMA2_Stream1_IRQHandler,
  DMA2_Stream2_IRQHandler,
  DMA2_Stream3_IRQHandler,
  DMA2_Stream4_IRQHandler,
  DFSDM1_FLT0_IRQHandler,
  DFSDM1_FLT1_IRQHandler,
  CAN2_TX_IRQHandler,
  CAN2_RX0_IRQHandler,
  CAN2_RX1_IRQHandler,
  CAN2_SCE_IRQHandler,
  OTG_FS_IRQHandler,
  DMA2_Stream5_IRQHandler,
  DMA2_Stream6_IRQHandler,
  DMA2_Stream7_IRQHandler,
  USART6_IRQHandler,
  I2C3_EV_IRQHandler,
  I2C3_ER_IRQHandler,
  CAN3_TX_IRQHandler,
  CAN3_RX0_IRQHandler,
  CAN3_RX1_IRQHandler,
  CAN3_SCE_IRQHandler,
  0,
  0,
  RNG_IRQHandler,
  FPU_IRQHandler,
  UART7_IRQHandler,
  UART8_IRQHandler,
  SPI4_IRQHandler,
  SPI5_IRQHandler,
  0,
  SAI1_IRQHandler,
  UART9_IRQHandler,
  UART10_IRQHandler,
  0,
  0,
  QUADSPI_IRQHandler,
  0,
  0,
  FMPI2C1_EV_IRQHandler,
  FMPI2C1_ER_IRQHandler,
  LPTIM1_IRQHandler,
  DFSDM2_FLT0_IRQHandler,
  DFSDM2_FLT1_IRQHandler,
  DFSDM2_FLT2_IRQHandler,
  DFSDM2_FLT3_IRQHandler
};

