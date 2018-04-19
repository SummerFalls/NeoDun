#ifndef MAIN_DEFINE_H
#define MAIN_DEFINE_H

#include <stdint.h>
#include "stm32f4xx_hal.h"


//#define Debug_Print
#define RECV_BIN_FILE_LEN		100*1024
#define Page_Per_Size				50
#define MAX_Page_Index			RECV_BIN_FILE_LEN/Page_Per_Size
#define PACK_INDEX_SIZE			((RECV_BIN_FILE_LEN-1)/50 + 1)
#define MOTOR_TIME  				80


typedef struct
{
		volatile uint8_t Key_Control_Flag;	//防误按的标志位
		volatile uint8_t Key_left_Flag;			//左按键标识
		volatile uint8_t Key_center_Flag;	  //中间按键标识
		volatile uint8_t Key_right_Flag;		//右边按键标识
		volatile uint8_t Key_double_Flag;		//左右双击按键标识
}SIGN_KEY_FLAG;


typedef struct
{
		uint8_t	new_wallet; 			//1表示新钱包，0表示旧钱包
		uint8_t	update;						//1表示需要升级，0表示不需要升级
		uint8_t	language;					//1表示英文，0表示中文
		uint8_t update_flag_failed;
}BOOT_SYS_FLAG;


typedef struct
{
		uint32_t 			size;
		uint32_t 			packIndex;
		uint8_t 			hash_tran[32];
		uint16_t 			reqSerial;
		uint16_t 			notifySerial;
		
		uint8_t 			signature[64];
		uint8_t 			Len_sign;
		uint8_t 			hash_actual[32];
}BIN_FILE_INFO;


enum
{
		PAGE_TOO_BIG_ERROR		 	= 1,
		PAGE_SERIALID_ERROR 		= 2,
		PAGE_HASH_ERROR 				= 3,
		PAGE_SIGNATURE_ERROR 		= 4,
		PAGE_RECV_ERROR 				= 5,
		PAGE_INDEX_ID_ERROR 		= 6
};


#endif





