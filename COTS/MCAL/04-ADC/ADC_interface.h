/**************************************************************************/
/************** Name    : Mahmoud A Raouf Mahmoud *************************/
/************** Date    : 26/09/2022              *************************/
/************** SWC     : ADC                     *************************/
/************** Version : 0.2                     *************************/
/**************************************************************************/
#ifndef __ADC_INTERFACE_H_
#define __ADC_INTERFACE_H_

/**
 * @defgroup ADC_ADC_Channel_Numbers ADC Channel Numbers
 * @{
 */

/** Single-Ended Channels */
#define ADC_CHANNEL_0    0  /**< ADC Channel 0 */
#define ADC_CHANNEL_1    1  /**< ADC Channel 1 */
#define ADC_CHANNEL_2    2  /**< ADC Channel 2 */
#define ADC_CHANNEL_3    3  /**< ADC Channel 3 */
#define ADC_CHANNEL_4    4  /**< ADC Channel 4 */
#define ADC_CHANNEL_5    5  /**< ADC Channel 5 */
#define ADC_CHANNEL_6    6  /**< ADC Channel 6 */
#define ADC_CHANNEL_7    7  /**< ADC Channel 7 */

/** Differential-Ended Channels */
#define ADC_CHANNEL_8    8  /**< ADC Channel 8 */
#define ADC_CHANNEL_9    9  /**< ADC Channel 9 */
#define ADC_CHANNEL_10   10 /**< ADC Channel 10 */
#define ADC_CHANNEL_11   11 /**< ADC Channel 11 */
#define ADC_CHANNEL_12   12 /**< ADC Channel 12 */
#define ADC_CHANNEL_13   13 /**< ADC Channel 13 */
#define ADC_CHANNEL_14   14 /**< ADC Channel 14 */
#define ADC_CHANNEL_15   15 /**< ADC Channel 15 */
#define ADC_CHANNEL_16   16 /**< ADC Channel 16 */
#define ADC_CHANNEL_17   17 /**< ADC Channel 17 */
#define ADC_CHANNEL_18   18 /**< ADC Channel 18 */
#define ADC_CHANNEL_19   19 /**< ADC Channel 19 */
#define ADC_CHANNEL_20   20 /**< ADC Channel 20 */
#define ADC_CHANNEL_21   21 /**< ADC Channel 21 */
#define ADC_CHANNEL_22   22 /**< ADC Channel 22 */
#define ADC_CHANNEL_23   23 /**< ADC Channel 23 */
#define ADC_CHANNEL_24   24 /**< ADC Channel 24 */
#define ADC_CHANNEL_25   25 /**< ADC Channel 25 */
#define ADC_CHANNEL_26   26 /**< ADC Channel 26 */
#define ADC_CHANNEL_27   27 /**< ADC Channel 27 */
#define ADC_CHANNEL_28   28 /**< ADC Channel 28 */
#define ADC_CHANNEL_29   29 /**< ADC Channel 29 */
#define ADC_CHANNEL_30   30 /**< ADC Channel 30 */
#define ADC_CHANNEL_31   31 /**< ADC Channel 31 */

/** @} */

/**
 * @brief Initialize the ADC module.
 *
 * This function initializes the ADC module, configuring it to its default state.
 * It should be called once at the beginning of your application.
 */
void ADC_Init(void);

/**
 * @brief Get the digital value of an ADC channel.
 *
 * @param[in] Copy_ChannelNo The ADC channel number to read.
 * @param[out] Copy_DigitalValue Pointer to store the digital value read from the channel.
 *
 * @return Std_ReturnType
 *   - E_OK: Digital value read successfully.
 *   - E_NOT_OK: An error occurred during the reading process.
 */
Std_ReturnType ADC_GetDigitalValue(u8 Copy_ChannelNo, u16 *Copy_DigitalValue);

#endif /* __ADC_INTERFACE_H_ */