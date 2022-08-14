/**
  ******************************************************************************
  * File Name          : ADS1262.c
  * Description        : This ADS1262 provides code for the configuration
  *                      of the ADS1262 instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under UlADS1262ate Liberty license
  * SLA0044, the "License"; You may not use this ADS1262 except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "ADS1262.h"

/* USER CODE BEGIN 0 */
#include "lcd.h"
/* USER CODE END 0 */

/* USER CODE BEGIN 1 */


//get chip ID, 0:1262; 1:1263
uint8_t ADS1262_Get_ID(void)
{
  uint8_t pRxData[3] ;
  uint8_t pTxData[3] ={ CMD_READ|ADS1262_ID,0,0 } ;

  SPI1_CS_ADS_0;
  HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 3 , 20);
  SPI1_CS_ADS_1;

  return pRxData[2];
}


//ADS1262 init,
//Set channel
uint8_t ADS1262_Init(void)
{

  uint8_t pTxData[3] ={
		  CMD_WRITE|ADS1262_MODE2,
		  0,
		  0x54 //ADS1262_MODE2:used PGA ,Gain=32; 20SPS;
//		  0x04 //ADS1262_MODE2: no used PGA; 20SPS;
  };

  //1. open 5V 3.3V power of ADC chip
  ADS_POWER_CTL_1;

  //2. set CH444G EN, low is active;
  ADC_SWITCH_EN_0;

  //3. pull up the reset pin, wait for stable
  ADS_RESET_0;
  HAL_Delay(100);
  ADS_RESET_1;
  HAL_Delay(100);

  //4. check chip's ID, if not ADS1262, stop
  if( 0xE0 & ADS1262_Get_ID() )
	  return 1;

#if Debug_Version
  /*----Used for Debug Mode ,set test DAC-----*/
//  ADS1262_Set_Test_DAC();
  /*----Used for Debug Mode ,set sample channel which is connnet to test DAC-----*/
//  ADS1262_Set_Channel(0x45);

#endif

  //5. set register for configure chip mode
  SPI1_CS_ADS_0;
  HAL_SPI_Transmit( &hspi1 ,  pTxData,  3 , 20);
  SPI1_CS_ADS_1;

  //6. start adc translation
  ADS_START_1;
  HAL_Delay(1);

  return 0;
}


//write data to ads1262,set different channel
//Num : 0x01 0x23 0x45
void ADS1262_Set_Channel( uint8_t num )
{

	uint8_t pTxData[3] ={ CMD_WRITE|ADS1262_INPMUX, 0, 0 } ;

	switch (num) {
		case 0x01:
			pTxData[2] = ADS1262_INPUT_01;
			break;
		case 0x23:
			pTxData[2] = ADS1262_INPUT_23;
			break;
		case 0x45:
			pTxData[2] = ADS1262_INPUT_45;
			break;
		default:
			break;
	}

	SPI1_CS_ADS_0;
	HAL_SPI_Transmit( &hspi1 ,  pTxData,  3 , 20);
	SPI1_CS_ADS_1;
}

//control CH44G GPIO ,set different channel
//control all of three CH444
//Num : 1、2、3、4
void CH444G_Set_Channel( uint8_t num )
{
	switch (num) {
		case 1:
			ADC_SWITCH_IN0_0;
			ADC_SWITCH_IN1_0;
			break;
		case 2:
			ADC_SWITCH_IN0_0;
			ADC_SWITCH_IN1_1;
			break;
		case 3:
			ADC_SWITCH_IN0_1;
			ADC_SWITCH_IN1_0;
			break;
		case 4:
			ADC_SWITCH_IN0_1;
			ADC_SWITCH_IN1_1;
			break;
		default:
			ADC_SWITCH_IN0_0;
			ADC_SWITCH_IN1_0;
			break;
	}
}


uint32_t ADS1262_Get_ADC(void)
{
  uint8_t pRxData[7] ;
  uint8_t pTxData[7] ={ ADS1262_ADC1_DATA, 0, 0, 0, 0, 0, 0 } ;
//  float val=0;

  //start adc translation
  ADS_START_1;
  HAL_Delay(1);

  //wait adc translation finish
  while(ADS_DRDY);

  //read register for data
  SPI1_CS_ADS_0;
  HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 7 , 20);
  SPI1_CS_ADS_1;

  //stop adc translation
  ADS_START_0;

#if Debug_Version
//  val = (((uint32_t)pRxData[2]<<24)|((uint32_t)pRxData[3]<<16)|((uint32_t)pRxData[4]<<8)|(uint32_t)pRxData[5])*2.5/0x7FFFFFFF;
//  LCD_ShowNum(10,100,(((uint32_t)pRxData[2]<<24)|((uint32_t)pRxData[3]<<16)|((uint32_t)pRxData[4]<<8)|(uint32_t)pRxData[5]),10,12,0,BLACK,WHITE);
#endif

  return (((uint32_t)pRxData[2]<<24)|((uint32_t)pRxData[3]<<16)|((uint32_t)pRxData[4]<<8)|(uint32_t)pRxData[5]) ;
}


/*----Used for Debug Mode ,set test DAC-----*/
//write data to ads1262,set diff channel
void ADS1262_Set_Test_DAC(void)
{

  uint8_t pTxData[4] ={ CMD_WRITE|ADS1262_TDACP, 1, 0x81 , 0x80 } ;

  SPI1_CS_ADS_0;
  HAL_SPI_Transmit( &hspi1 ,  pTxData,  4 , 20);
  SPI1_CS_ADS_1;

}





//
//float ADS1262_Temperature_sensor_DATA_GET(void)
//{
//  uint8_t pRxData[4];
//  uint8_t pTxData[4] ={ ADC_CFGH_AIN0_1_CH,ADC_CFGL_TEMP_SENSOR,ADC_CFGH_AIN0_1_CH,ADC_CFGL_TEMP_SENSOR } ;
//
//  SPI1_CS_ADS_0;
//  HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 20);
//  HAL_Delay(ADC_COVEN_TIME);
//  HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 20);
//  SPI1_CS_ADS_1;
//
//  return (((((uint16_t)pRxData[0])<<8)|pRxData[1])>>2)*0.03125;
//}
//
//
////USE_ANALOG_SWITCH
///*
//uint8_t CH_x :支持8通道，从0到7
//uint16_t 返回值：返回实际使能的通道值
//*/
//uint16_t _ADS1262_GET_ADC_DATA(uint8_t CH_x)
//{
//
//  uint8_t pTxData[4] ={ ADC_CFGH_AIN0_1_CH,ADC_CFGL_TEMP_SENSOR,ADC_CFGH_AIN0_1_CH,ADC_CFGL_TEMP_SENSOR } ;
//  uint8_t pRxData[4];
//
//  switch( CH_x )
//  {
//    case 0 :
//      ADC_SWITCH1_0;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN0_1_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_SET );
//    break;
//
//    case 1 :
//      ADC_SWITCH1_1;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN0_1_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_SET );
//    break;
//
//    case 2 :
//      ADC_SWITCH2_0;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN2_3_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_SET );
//    break;
//
//    case 3 :
//      ADC_SWITCH2_1;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN2_3_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_SET );
//    break;
//
//    case 4 :
//      ADC_SWITCH3_0;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN0_1_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_SET );
//    break;
//
//    case 5 :
//      ADC_SWITCH3_1;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN0_1_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_SET );
//    break;
//
//    case 6 :
//      ADC_SWITCH4_0;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN2_3_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_SET );
//    break;
//
//    case 7 :
//      ADC_SWITCH4_1;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN2_3_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC3_GPIO_Port, SPI1_CS_ADC3_Pin, GPIO_PIN_SET );
//    break;
//
//    default:
//      ADC_SWITCH1_0;
//      pTxData[0] = pTxData[2] = ADC_CFGH_AIN0_1_CH;
//      pTxData[1] = pTxData[3] = ADC_CFGL_ANALOG_IN;
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_RESET );
//      HAL_SPI_TransmitReceive( &hspi1 ,  pTxData,  pRxData, 4 , 100);
//      HAL_GPIO_WritePin(SPI1_CS_ADC1_GPIO_Port, SPI1_CS_ADC1_Pin, GPIO_PIN_SET );
//      break;
//  }
//  return (((uint16_t)pRxData[0])<<8)|pRxData[1];
//}
//
//
//uint16_t ADS1262_GET_ADC_DATA(uint8_t CH_x)
//{
//  _ADS1262_GET_ADC_DATA(CH_x);
//  HAL_Delay(ADC_COVEN_TIME);
//  return _ADS1262_GET_ADC_DATA(CH_x);
//}
//
//
////FSR范围±0.256,转换电压，以mV显示
//float ADC1262_Change_ADC_to_VAL(uint16_t ADC_DATA)
//{
//  float FSR=2.048;
//  switch( ADC_CFGH_AIN0_1_CH )
//  {
//    case ADC_CFGH_AIN0_1_CH_FSRL : FSR=0.256;    break;
//    case ADC_CFGH_AIN0_1_CH_FSRM : FSR=2.048;    break;
//    case ADC_CFGH_AIN0_1_CH_FSRH : FSR=6.144;    break;
//  }
//
//  //负数变成正数
//  if( ADC_DATA >= 0x8000 ){
//    ADC_DATA = (uint16_t)(0x00010000-ADC_DATA) ;
//    return -ADC_DATA*FSR/32.768;
//  } else {
//    return ADC_DATA*FSR/32.768;
//  }
//}
//
//
////******************
//// function:ADC1262_Change_VAL_to_Temperature
//// return:float
//// DESCRIPTION:将通道电压值转换为温度值，带有冷端补偿的转换
//// float ADC1262_Change_VAL_to_Temperature ( float Temperature  , float ADC_VAL );
////******************
//float ADC1262_Change_VAL_to_Temperature ( float Temperature  , float ADC_VAL )
//{
//  float CH_Temperature = 0;
//
//  //CH_Temperature = Temperature + 0.000001*pow(ADC_VAL,6)+0.0001*pow(ADC_VAL,5)-0.0059*pow(ADC_VAL,4)+0.0888*pow(ADC_VAL,3)+0.483*pow(ADC_VAL,2)+25.268*ADC_VAL+0.0801;
//  CH_Temperature = Temperature + (0.0002*pow(ADC_VAL,5) - 0.0067*pow(ADC_VAL,4) + 0.0932*pow(ADC_VAL,3) - 0.4893*pow(ADC_VAL,2) + 25.253*ADC_VAL + 0.0981) ;
//  //CH_Temperature = Temperature - 0.0269*pow(ADC_VAL,2) + 24.949*ADC_VAL - 1.1065;
//  //CH_Temperature = Temperature + 24.574*ADC_VAL - 0.578;
//  if(CH_Temperature>=999)CH_Temperature=999;
//  if(CH_Temperature<=-100)CH_Temperature=-100;
//  return CH_Temperature;
//}
//


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
