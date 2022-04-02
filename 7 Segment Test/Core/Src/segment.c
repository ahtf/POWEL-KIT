/* Includes ------------------------------------------------------------------*/
#include "segment.h"
#include "gpio.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

#if defined(SEGMENT_SHIFT_REGISTER_DRIVER_USED)
const uint8_t segment_map_sh[]=
{
	0x00,		//Space
	0xE7,		//0
	0x21,   //1
	0xCB,   //2
	0x6B,   //3
	0x2D,   //4
	0x6E,   //5
	0xEE,   //6
	0x23,   //7
	0xEF,   //8
	0x6F,   //9
	0xAF,   //A
	0xEC,   //b
	0xC6,   //C
	0xE9,   //d
	0xCE,   //E
	0x8E,   //F
	0xE6,		//G
	0xAD,   //H
	0x20,   //I
	0xE1,   //J
	0xAE,   //K
	0xC4,   //L
	0xA7,   //M
	0xA8,   //N
	0xE8,   //O
	0x8F,   //P
	0x2F,   //Q
	0x88,   //R
	0x6E,   //S
	0xCC,   //T
	0xE0,   //U
	0xE5,   //V
	0xED,   //W
	0xAD,   //X
	0x6D,   //Y
	0xCB,   //Z
  0x08,   //-
};
#endif

uint8_t char_map[128]=
{
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	37,	0,	0,
	1,	2,	3,	4,	5,	6,	7,	8,	9,	10,	0,	0,	0,	0,	0,	0,
	0,	11,	12,	13,	14,	15,	16,	17,	18,	19,	20,	21,	22,	23,	24,	25,
	26,	27,	28,	29,	30,	31,	32,	33,	34,	35,	36,	0,	0,	0,	0,	0,
	0,	11,	12,	13,	14,	15,	16,	17,	18,	19,	20,	21,	22,	23,	24,	25,
	26,	27,	28,	29,	30,	31,	32,	33,	34,	35,	36,	0,	0,	0,	0,	0,
};


const uint8_t map_blk_sh[NBOF_LED_GROUPS] = 
{
	0x80, 0x40, 0x20, 0x10
};


#if defined(SEGMENT_SHIFT_REGISTER_DRIVER_USED)
volatile uint8_t main_screen_digits_sh[NBOF_DIGITS] = {0,0,0,0};
#endif

volatile uint8_t temp_screen_digits[5] = {0,0,0,0,0};
volatile uint8_t dig_blink = 0x00;
char refined_str[22];	//must get enough size otherwise loss of other variables will happen

/* Private function prototypes -----------------------------------------------*/
/**
  * @brief  Drives serial interface with serial buffers for outputs
  * @note   
  * @param  The buffer  to be sent.
  * @retval None.
  */
static void shiftOut(uint16_t buf)
{
	CLK_RESET();
	for(int j = 0; j < 16; j++)
	{
		(buf&0x01) ? SDI_SET() : SDI_RESET();
		CLK_SET();
		CLK_RESET();
		buf >>= 1;
	}
	LAT_SET();
	LAT_RESET();
}

/* Exported functions --------------------------------------------------------*/
/*
==============================================================================
                            Functions Declarations                                     
==============================================================================
*/

/**
  * @brief  sets and resets segments for each digits based on input string.
  * @note   dot character should be used with a preceeding neighbour character like "SPC".
	*	@note   Error if lenght of string exceeds NbOf digits.
  * @param  str -> the string to be shown on 7segment display.
  * @retval length of input string.
  */
int SEG_procesString(char *str)		//dot sharacter must be used with a valid preceeding char like space
{
	int i = 0;
	while(*str)
	{
		if( (*str) == '.' )
		{
			str++;
			
			main_screen_digits_sh[i-1] |= 1<<4;
		}
		
		main_screen_digits_sh[i] = segment_map_sh[char_map[*str]];
		str++;
		i++;
		if( i >= NBOF_DIGITS )
			break;
	}
		
	return i;
}


/**
  * @brief  Refreshes the segment display.
  * @param  None.
  * @retval None.
  */
void SEG_refreshDigits(void)
{
		shiftOut(0);
	
	static int  i = 2;

	if( i < NBOF_DIGITS  )		
	{
		shiftOut(main_screen_digits_sh[i]<<8	| map_blk_sh[i]);
	}
	if (++i >= NBOF_LED_GROUPS)
		i = 0;
 
}

