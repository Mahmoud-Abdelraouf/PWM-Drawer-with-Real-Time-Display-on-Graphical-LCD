/********************************************************/
/********** Name    : Mahmoud a raoof mahmoud ***********/
/********** Date    : 26/09/2022              ***********/
/********** SWC     : KPD                     ***********/
/********** Version : 1.0                     ***********/
/********************************************************/

#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_U8_KEY_NOT_PRESSED        0xFF

Error_State_t KPD_u8GetKeyState(u8 *copy_u8returnedKey);


#endif