/*
********************************************************************************************
*
*        Copyright (c):  Fuzhou Rockchip Electronics Co., Ltd
*                             All rights reserved.
*
* FileName: Bsp\EVK_V2.0\Scatter\ScatterLoader.c
* Owner: aaron.sun
* Date: 2015.6.10
* Time: 16:01:48
* Version: 1.0
* Desc:
* History:
*    <author>    <date>       <time>     <version>     <Desc>
*    aaron.sun     2015.6.10     16:01:48   1.0
********************************************************************************************
*/

#define _IN_STARTLOAD_

#include "BspConfig.h"
#include "RKOS.h"
#include "BSP.h"

extern uint32 Load$$MODULE_INFO$$Base;

//SYS MODULE
extern uint32 Load$$AP_SYS_CODE$$Base;
extern uint32 Image$$AP_SYS_CODE$$Base;
extern uint32 Image$$AP_SYS_CODE$$Length;
extern uint32 Load$$AP_SYS_DATA$$Base;
extern uint32 Image$$AP_SYS_DATA$$RW$$Base;
extern uint32 Image$$AP_SYS_DATA$$RW$$Length;
extern uint32 Image$$AP_SYS_DATA$$ZI$$Base;
extern uint32 Image$$AP_SYS_DATA$$ZI$$Length;

//INIT MODULE
extern uint32 Load$$INIT_CODE$$Base;
extern uint32 Image$$INIT_CODE$$Base;
extern uint32 Image$$INIT_CODE$$Length;
extern uint32 Load$$INIT_DATA$$Base;
extern uint32 Image$$INIT_DATA$$RW$$Base;
extern uint32 Image$$INIT_DATA$$RW$$Length;
extern uint32 Image$$INIT_DATA$$ZI$$Base;
extern uint32 Image$$INIT_DATA$$ZI$$Length;

//PMU MODULE
extern uint32 Load$$PMU_CODE$$Base;
extern uint32 Image$$PMU_CODE$$Base;
extern uint32 Image$$PMU_CODE$$Length;
extern uint32 Load$$PMU_DATA$$Base;
extern uint32 Image$$PMU_DATA$$RW$$Base;
extern uint32 Image$$PMU_DATA$$RW$$Length;
extern uint32 Image$$PMU_DATA$$ZI$$Base;
extern uint32 Image$$PMU_DATA$$ZI$$Length;

//SYS SUSPEND MODULE
extern uint32 Load$$SYS_SUSPEND_CODE$$Base;
extern uint32 Image$$SYS_SUSPEND_CODE$$Base;
extern uint32 Image$$SYS_SUSPEND_CODE$$Length;
extern uint32 Load$$SYS_SUSPEND_DATA$$Base;
extern uint32 Image$$SYS_SUSPEND_DATA$$RW$$Base;
extern uint32 Image$$SYS_SUSPEND_DATA$$RW$$Length;
extern uint32 Image$$SYS_SUSPEND_DATA$$ZI$$Base;
extern uint32 Image$$SYS_SUSPEND_DATA$$ZI$$Length;


//SYS RESUME MODULE
extern uint32 Load$$SYS_RESUME_CODE$$Base;
extern uint32 Image$$SYS_RESUME_CODE$$Base;
extern uint32 Image$$SYS_RESUME_CODE$$Length;
extern uint32 Load$$SYS_RESUME_DATA$$Base;
extern uint32 Image$$SYS_RESUME_DATA$$RW$$Base;
extern uint32 Image$$SYS_RESUME_DATA$$RW$$Length;
extern uint32 Image$$SYS_RESUME_DATA$$ZI$$Base;
extern uint32 Image$$SYS_RESUME_DATA$$ZI$$Length;

//LINEIN SEG MODULE
extern uint32 Load$$LINEIN_TASK_CODE$$Base;
extern uint32 Image$$LINEIN_TASK_CODE$$Base;
extern uint32 Image$$LINEIN_TASK_CODE$$Length;
extern uint32 Image$$LINEIN_TASK_CODE$$ZI$$Base;
extern uint32 Image$$LINEIN_TASK_CODE$$ZI$$Length;

extern uint32 Load$$LINEIN_INIT_CODE$$Base;
extern uint32 Image$$LINEIN_INIT_CODE$$Base;
extern uint32 Image$$LINEIN_INIT_CODE$$Length;
extern uint32 Image$$LINEIN_INIT_CODE$$ZI$$Base;
extern uint32 Image$$LINEIN_INIT_CODE$$ZI$$Length;

//LINEINCONTROL SEG MODULE
extern uint32 Load$$LINEINCONTROL_TASK_CODE$$Base;
extern uint32 Image$$LINEINCONTROL_TASK_CODE$$Base;
extern uint32 Image$$LINEINCONTROL_TASK_CODE$$Length;
extern uint32 Image$$LINEINCONTROL_TASK_CODE$$ZI$$Base;
extern uint32 Image$$LINEINCONTROL_TASK_CODE$$ZI$$Length;


extern uint32 Load$$LINEINCONTROL_INIT_CODE$$Base;
extern uint32 Image$$LINEINCONTROL_INIT_CODE$$Base;
extern uint32 Image$$LINEINCONTROL_INIT_CODE$$Length;
extern uint32 Image$$LINEINCONTROL_INIT_CODE$$ZI$$Base;
extern uint32 Image$$LINEINCONTROL_INIT_CODE$$ZI$$Length;

//FMUI SEG MODULE
extern uint32 Load$$FMUI_TASK_CODE$$Base;
extern uint32 Image$$FMUI_TASK_CODE$$Base;
extern uint32 Image$$FMUI_TASK_CODE$$Length;
extern uint32 Image$$FMUI_TASK_CODE$$ZI$$Base;
extern uint32 Image$$FMUI_TASK_CODE$$ZI$$Length;

extern uint32 Load$$FMUI_INIT_CODE$$Base;
extern uint32 Image$$FMUI_INIT_CODE$$Base;
extern uint32 Image$$FMUI_INIT_CODE$$Length;
extern uint32 Image$$FMUI_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FMUI_INIT_CODE$$ZI$$Length;

//FMCONTROL SEG MODULE
extern uint32 Load$$FMCONTROL_TASK_CODE$$Base;
extern uint32 Image$$FMCONTROL_TASK_CODE$$Base;
extern uint32 Image$$FMCONTROL_TASK_CODE$$Length;
extern uint32 Image$$FMCONTROL_TASK_CODE$$ZI$$Base;
extern uint32 Image$$FMCONTROL_TASK_CODE$$ZI$$Length;

extern uint32 Load$$FMCONTROL_INIT_CODE$$Base;
extern uint32 Image$$FMCONTROL_INIT_CODE$$Base;
extern uint32 Image$$FMCONTROL_INIT_CODE$$Length;
extern uint32 Image$$FMCONTROL_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FMCONTROL_INIT_CODE$$ZI$$Length;


//FM SEG MODULE
extern uint32 Load$$FM_DEV_CODE$$Base;
extern uint32 Image$$FM_DEV_CODE$$Base;
extern uint32 Image$$FM_DEV_CODE$$Length;
extern uint32 Image$$FM_DEV_CODE$$ZI$$Base;
extern uint32 Image$$FM_DEV_CODE$$ZI$$Length;

extern uint32 Load$$FM_INIT_CODE$$Base;
extern uint32 Image$$FM_INIT_CODE$$Base;
extern uint32 Image$$FM_INIT_CODE$$Length;
extern uint32 Image$$FM_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FM_INIT_CODE$$ZI$$Length;

extern uint32 Load$$FM_SHELL_CODE$$Base;
extern uint32 Image$$FM_SHELL_CODE$$Base;
extern uint32 Image$$FM_SHELL_CODE$$Length;
extern uint32 Image$$FM_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$FM_SHELL_CODE$$ZI$$Length;

//BROWSERUI SEG MODULE
extern uint32 Load$$BROWSERUI_TASK_CODE$$Base;
extern uint32 Image$$BROWSERUI_TASK_CODE$$Base;
extern uint32 Image$$BROWSERUI_TASK_CODE$$Length;
extern uint32 Image$$BROWSERUI_TASK_CODE$$ZI$$Base;
extern uint32 Image$$BROWSERUI_TASK_CODE$$ZI$$Length;

extern uint32 Load$$BROWSERUI_INIT_CODE$$Base;
extern uint32 Image$$BROWSERUI_INIT_CODE$$Base;
extern uint32 Image$$BROWSERUI_INIT_CODE$$Length;
extern uint32 Image$$BROWSERUI_INIT_CODE$$ZI$$Base;
extern uint32 Image$$BROWSERUI_INIT_CODE$$ZI$$Length;

//SYSTEMSETWIFISECLECT SEG MODULE
extern uint32 Load$$SYSTEMSETWIFISELECT_TASK_CODE$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_TASK_CODE$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_TASK_CODE$$Length;
extern uint32 Image$$SYSTEMSETWIFISELECT_TASK_CODE$$ZI$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_TASK_CODE$$ZI$$Length;

extern uint32 Load$$SYSTEMSETWIFISELECT_INIT_CODE$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_INIT_CODE$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_INIT_CODE$$Length;
extern uint32 Image$$SYSTEMSETWIFISELECT_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SYSTEMSETWIFISELECT_INIT_CODE$$ZI$$Length;

//SYSTEMSET SEG MODULE
extern uint32 Load$$SYSTEMSET_TASK_CODE$$Base;
extern uint32 Image$$SYSTEMSET_TASK_CODE$$Base;
extern uint32 Image$$SYSTEMSET_TASK_CODE$$Length;
extern uint32 Image$$SYSTEMSET_TASK_CODE$$ZI$$Base;
extern uint32 Image$$SYSTEMSET_TASK_CODE$$ZI$$Length;

extern uint32 Load$$SYSTEMSET_INIT_CODE$$Base;
extern uint32 Image$$SYSTEMSET_INIT_CODE$$Base;
extern uint32 Image$$SYSTEMSET_INIT_CODE$$Length;
extern uint32 Image$$SYSTEMSET_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SYSTEMSET_INIT_CODE$$ZI$$Length;

//CHARGE SEG MODULE
extern uint32 Load$$CHARGE_TASK_CODE$$Base;
extern uint32 Image$$CHARGE_TASK_CODE$$Base;
extern uint32 Image$$CHARGE_TASK_CODE$$Length;
extern uint32 Image$$CHARGE_TASK_CODE$$ZI$$Base;
extern uint32 Image$$CHARGE_TASK_CODE$$ZI$$Length;

extern uint32 Load$$CHARGE_INIT_CODE$$Base;
extern uint32 Image$$CHARGE_INIT_CODE$$Base;
extern uint32 Image$$CHARGE_INIT_CODE$$Length;
extern uint32 Image$$CHARGE_INIT_CODE$$ZI$$Base;
extern uint32 Image$$CHARGE_INIT_CODE$$ZI$$Length;

//MUSIC PLAY MENU SEG MODULE

extern uint32 Load$$MUSIC_PLAY_MENU_TASK_CODE$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_TASK_CODE$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_TASK_CODE$$Length;
extern uint32 Image$$MUSIC_PLAY_MENU_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_TASK_CODE$$ZI$$Length;

extern uint32 Load$$MUSIC_PLAY_MENU_INIT_CODE$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_INIT_CODE$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_INIT_CODE$$Length;
extern uint32 Image$$MUSIC_PLAY_MENU_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MUSIC_PLAY_MENU_INIT_CODE$$ZI$$Length;

//RECOD SEG MODULE

extern uint32 Load$$RECOD_TASK_CODE$$Base;
extern uint32 Image$$RECOD_TASK_CODE$$Base;
extern uint32 Image$$RECOD_TASK_CODE$$Length;
extern uint32 Image$$RECOD_TASK_CODE$$ZI$$Base;
extern uint32 Image$$RECOD_TASK_CODE$$ZI$$Length;

extern uint32 Load$$RECOD_INIT_CODE$$Base;
extern uint32 Image$$RECOD_INIT_CODE$$Base;
extern uint32 Image$$RECOD_INIT_CODE$$Length;
extern uint32 Image$$RECOD_INIT_CODE$$ZI$$Base;
extern uint32 Image$$RECOD_INIT_CODE$$ZI$$Length;

//Media Update
extern uint32 Load$$MEDIA_UPDATE_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_UPDATE_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_UPDATE_TASK_CODE$$Length;
extern uint32 Image$$MEDIA_UPDATE_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_UPDATE_TASK_CODE$$ZI$$Length;

//file info save
extern uint32 Load$$FILE_INFO_SAVE_CODE$$Base;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$Base;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$Length;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$ZI$$Base;
extern uint32 Image$$FILE_INFO_SAVE_CODE$$ZI$$Length;

//ID3
extern uint32 Load$$ID3_DEV_CODE$$Base;
extern uint32 Image$$ID3_DEV_CODE$$Base;
extern uint32 Image$$ID3_DEV_CODE$$Length;
extern uint32 Image$$ID3_DEV_CODE$$ZI$$Base;
extern uint32 Image$$ID3_DEV_CODE$$ZI$$Length;

//file info sort
extern uint32 Load$$FILE_INFO_SORT_CODE$$Base;
extern uint32 Image$$FILE_INFO_SORT_CODE$$Base;
extern uint32 Image$$FILE_INFO_SORT_CODE$$Length;
extern uint32 Image$$FILE_INFO_SORT_CODE$$ZI$$Base;
extern uint32 Image$$FILE_INFO_SORT_CODE$$ZI$$Length;

//MEDIA LIBRARY SEG MODULE
extern uint32 Load$$MEDIA_LIBRARY_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_LIBRARY_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_LIBRARY_TASK_CODE$$Length;
extern uint32 Image$$MEDIA_LIBRARY_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_LIBRARY_TASK_CODE$$ZI$$Length;

extern uint32 Load$$MEDIA_LIBRARY_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_LIBRARY_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_LIBRARY_INIT_CODE$$Length;
extern uint32 Image$$MEDIA_LIBRARY_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_LIBRARY_INIT_CODE$$ZI$$Length;

//MEDIA BROWSER SEG MODULE
extern uint32 Load$$MEDIA_BROWSER_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_BROWSER_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_BROWSER_TASK_CODE$$Length;
extern uint32 Image$$MEDIA_BROWSER_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_BROWSER_TASK_CODE$$ZI$$Length;

extern uint32 Load$$MEDIA_BROWSER_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_BROWSER_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_BROWSER_INIT_CODE$$Length;
extern uint32 Image$$MEDIA_BROWSER_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_BROWSER_INIT_CODE$$ZI$$Length;

//USBSERVICE SEG MODULE

extern uint32 Load$$USBSERVICE_TASK_CODE$$Base;
extern uint32 Image$$USBSERVICE_TASK_CODE$$Base;
extern uint32 Image$$USBSERVICE_TASK_CODE$$Length;
extern uint32 Image$$USBSERVICE_TASK_CODE$$ZI$$Base;
extern uint32 Image$$USBSERVICE_TASK_CODE$$ZI$$Length;


extern uint32 Load$$USBSERVICE_INIT_CODE$$Base;
extern uint32 Image$$USBSERVICE_INIT_CODE$$Base;
extern uint32 Image$$USBSERVICE_INIT_CODE$$Length;
extern uint32 Image$$USBSERVICE_INIT_CODE$$ZI$$Base;
extern uint32 Image$$USBSERVICE_INIT_CODE$$ZI$$Length;

//MAIN SEG MODULE

extern uint32 Load$$MAIN_TASK_CODE$$Base;
extern uint32 Image$$MAIN_TASK_CODE$$Base;
extern uint32 Image$$MAIN_TASK_CODE$$Length;
extern uint32 Image$$MAIN_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MAIN_TASK_CODE$$ZI$$Length;

extern uint32 Load$$MAIN_MENU_CODE$$Base;
extern uint32 Image$$MAIN_MENU_CODE$$Base;
extern uint32 Image$$MAIN_MENU_CODE$$Length;
extern uint32 Image$$MAIN_MENU_CODE$$ZI$$Base;
extern uint32 Image$$MAIN_MENU_CODE$$ZI$$Length;

extern uint32 Load$$MAIN_INIT_CODE$$Base;
extern uint32 Image$$MAIN_INIT_CODE$$Base;
extern uint32 Image$$MAIN_INIT_CODE$$Length;
extern uint32 Image$$MAIN_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MAIN_INIT_CODE$$ZI$$Length;

//RECORD SEG MODULE
//chad.ma add
extern uint32 Load$$RECORD_SHELL_CODE$$Base;
extern uint32 Image$$RECORD_SHELL_CODE$$Base;
extern uint32 Image$$RECORD_SHELL_CODE$$Length;
extern uint32 Image$$RECORD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$RECORD_SHELL_CODE$$ZI$$Length;

//MUSIC SEG MODULE

extern uint32 Load$$MUSIC_SHELL_CODE$$Base;
extern uint32 Image$$MUSIC_SHELL_CODE$$Base;
extern uint32 Image$$MUSIC_SHELL_CODE$$Length;
extern uint32 Image$$MUSIC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$MUSIC_SHELL_CODE$$ZI$$Length;

//EFFECT SEG MODULE
extern uint32 Load$$EFFECT_MODULE_CODE$$Base;
extern uint32 Image$$EFFECT_MODULE_CODE$$Base;
extern uint32 Image$$EFFECT_MODULE_CODE$$Length;
extern uint32 Image$$EFFECT_MODULE_CODE$$ZI$$Base;
extern uint32 Image$$EFFECT_MODULE_CODE$$ZI$$Length;

//TIMER SEG MODULE
extern uint32 Load$$TIMER_DEV_CODE$$Base;
extern uint32 Image$$TIMER_DEV_CODE$$Base;
extern uint32 Image$$TIMER_DEV_CODE$$Length;
extern uint32 Image$$TIMER_DEV_CODE$$ZI$$Base;
extern uint32 Image$$TIMER_DEV_CODE$$ZI$$Length;

extern uint32 Load$$TIMER_INIT_CODE$$Base;
extern uint32 Image$$TIMER_INIT_CODE$$Base;
extern uint32 Image$$TIMER_INIT_CODE$$Length;
extern uint32 Image$$TIMER_INIT_CODE$$ZI$$Base;
extern uint32 Image$$TIMER_INIT_CODE$$ZI$$Length;


extern uint32 Load$$TIMER_SHELL_CODE$$Base;
extern uint32 Image$$TIMER_SHELL_CODE$$Base;
extern uint32 Image$$TIMER_SHELL_CODE$$Length;
extern uint32 Image$$TIMER_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$TIMER_SHELL_CODE$$ZI$$Length;

//ADC SEG MODULE
extern uint32 Load$$ADC_DEV_CODE$$Base;
extern uint32 Image$$ADC_DEV_CODE$$Base;
extern uint32 Image$$ADC_DEV_CODE$$Length;
extern uint32 Image$$ADC_DEV_CODE$$ZI$$Base;
extern uint32 Image$$ADC_DEV_CODE$$ZI$$Length;

extern uint32 Load$$ADC_INIT_CODE$$Base;
extern uint32 Image$$ADC_INIT_CODE$$Base;
extern uint32 Image$$ADC_INIT_CODE$$Length;
extern uint32 Image$$ADC_INIT_CODE$$ZI$$Base;
extern uint32 Image$$ADC_INIT_CODE$$ZI$$Length;

extern uint32 Load$$ADC_SHELL_CODE$$Base;
extern uint32 Image$$ADC_SHELL_CODE$$Base;
extern uint32 Image$$ADC_SHELL_CODE$$Length;
extern uint32 Image$$ADC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$ADC_SHELL_CODE$$ZI$$Length;

//KEY SEG MODULE
extern uint32 Load$$KEY_DEV_CODE$$Base;
extern uint32 Image$$KEY_DEV_CODE$$Base;
extern uint32 Image$$KEY_DEV_CODE$$Length;
extern uint32 Image$$KEY_DEV_CODE$$ZI$$Base;
extern uint32 Image$$KEY_DEV_CODE$$ZI$$Length;

extern uint32 Load$$KEY_INIT_CODE$$Base;
extern uint32 Image$$KEY_INIT_CODE$$Base;
extern uint32 Image$$KEY_INIT_CODE$$Length;
extern uint32 Image$$KEY_INIT_CODE$$ZI$$Base;
extern uint32 Image$$KEY_INIT_CODE$$ZI$$Length;

extern uint32 Load$$KEY_SHELL_CODE$$Base;
extern uint32 Image$$KEY_SHELL_CODE$$Base;
extern uint32 Image$$KEY_SHELL_CODE$$Length;
extern uint32 Image$$KEY_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$KEY_SHELL_CODE$$ZI$$Length;

//PWM SEG MODULE
extern uint32 Load$$PWM_DEV_CODE$$Base;
extern uint32 Image$$PWM_DEV_CODE$$Base;
extern uint32 Image$$PWM_DEV_CODE$$Length;
extern uint32 Image$$PWM_DEV_CODE$$ZI$$Base;
extern uint32 Image$$PWM_DEV_CODE$$ZI$$Length;

extern uint32 Load$$PWM_INIT_CODE$$Base;
extern uint32 Image$$PWM_INIT_CODE$$Base;
extern uint32 Image$$PWM_INIT_CODE$$Length;
extern uint32 Image$$PWM_INIT_CODE$$ZI$$Base;
extern uint32 Image$$PWM_INIT_CODE$$ZI$$Length;

extern uint32 Load$$PWM_SHELL_CODE$$Base;
extern uint32 Image$$PWM_SHELL_CODE$$Base;
extern uint32 Image$$PWM_SHELL_CODE$$Length;
extern uint32 Image$$PWM_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$PWM_SHELL_CODE$$ZI$$Length;

//VOP SEG MODULE
extern uint32 Load$$VOP_DEV_CODE$$Base;
extern uint32 Image$$VOP_DEV_CODE$$Base;
extern uint32 Image$$VOP_DEV_CODE$$Length;
extern uint32 Image$$VOP_DEV_CODE$$ZI$$Base;
extern uint32 Image$$VOP_DEV_CODE$$ZI$$Length;

extern uint32 Load$$VOP_INIT_CODE$$Base;
extern uint32 Image$$VOP_INIT_CODE$$Base;
extern uint32 Image$$VOP_INIT_CODE$$Length;
extern uint32 Image$$VOP_INIT_CODE$$ZI$$Base;
extern uint32 Image$$VOP_INIT_CODE$$ZI$$Length;

extern uint32 Load$$VOP_SHELL_CODE$$Base;
extern uint32 Image$$VOP_SHELL_CODE$$Base;
extern uint32 Image$$VOP_SHELL_CODE$$Length;
extern uint32 Image$$VOP_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$VOP_SHELL_CODE$$ZI$$Length;

//LCD SEG MODULE
extern uint32 Load$$LCD_DEV_CODE$$Base;
extern uint32 Image$$LCD_DEV_CODE$$Base;
extern uint32 Image$$LCD_DEV_CODE$$Length;
extern uint32 Image$$LCD_DEV_CODE$$ZI$$Base;
extern uint32 Image$$LCD_DEV_CODE$$ZI$$Length;

extern uint32 Load$$LCD_INIT_CODE$$Base;
extern uint32 Image$$LCD_INIT_CODE$$Base;
extern uint32 Image$$LCD_INIT_CODE$$Length;
extern uint32 Image$$LCD_INIT_CODE$$ZI$$Base;
extern uint32 Image$$LCD_INIT_CODE$$ZI$$Length;

extern uint32 Load$$LCD_SHELL_CODE$$Base;
extern uint32 Image$$LCD_SHELL_CODE$$Base;
extern uint32 Image$$LCD_SHELL_CODE$$Length;
extern uint32 Image$$LCD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$LCD_SHELL_CODE$$ZI$$Length;

//DISPLAY SEG MODULE
extern uint32 Load$$DISPLAY_DEV_CODE$$Base;
extern uint32 Image$$DISPLAY_DEV_CODE$$Base;
extern uint32 Image$$DISPLAY_DEV_CODE$$Length;
extern uint32 Image$$DISPLAY_DEV_CODE$$ZI$$Base;
extern uint32 Image$$DISPLAY_DEV_CODE$$ZI$$Length;

extern uint32 Load$$DISPLAY_INIT_CODE$$Base;
extern uint32 Image$$DISPLAY_INIT_CODE$$Base;
extern uint32 Image$$DISPLAY_INIT_CODE$$Length;
extern uint32 Image$$DISPLAY_INIT_CODE$$ZI$$Base;
extern uint32 Image$$DISPLAY_INIT_CODE$$ZI$$Length;

extern uint32 Load$$DISPLAY_SHELL_CODE$$Base;
extern uint32 Image$$DISPLAY_SHELL_CODE$$Base;
extern uint32 Image$$DISPLAY_SHELL_CODE$$Length;
extern uint32 Image$$DISPLAY_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$DISPLAY_SHELL_CODE$$ZI$$Length;

//GUI SEG MODULE
extern uint32 Load$$GUI_TASK_CODE$$Base;
extern uint32 Image$$GUI_TASK_CODE$$Base;
extern uint32 Image$$GUI_TASK_CODE$$Length;
extern uint32 Image$$GUI_TASK_CODE$$ZI$$Base;
extern uint32 Image$$GUI_TASK_CODE$$ZI$$Length;

extern uint32 Load$$GUI_INIT_CODE$$Base;
extern uint32 Image$$GUI_INIT_CODE$$Base;
extern uint32 Image$$GUI_INIT_CODE$$Length;
extern uint32 Image$$GUI_INIT_CODE$$ZI$$Base;
extern uint32 Image$$GUI_INIT_CODE$$ZI$$Length;

extern uint32 Load$$GUI_SHELL_CODE$$Base;
extern uint32 Image$$GUI_SHELL_CODE$$Base;
extern uint32 Image$$GUI_SHELL_CODE$$Length;
extern uint32 Image$$GUI_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$GUI_SHELL_CODE$$ZI$$Length;

//BCORE SEG MODULE
extern uint32 Load$$BCORE_DEV_CODE$$Base;
extern uint32 Image$$BCORE_DEV_CODE$$Base;
extern uint32 Image$$BCORE_DEV_CODE$$Length;
extern uint32 Image$$BCORE_DEV_CODE$$ZI$$Base;
extern uint32 Image$$BCORE_DEV_CODE$$ZI$$Length;

extern uint32 Load$$BCORE_INIT_CODE$$Base;
extern uint32 Image$$BCORE_INIT_CODE$$Base;
extern uint32 Image$$BCORE_INIT_CODE$$Length;
extern uint32 Image$$BCORE_INIT_CODE$$ZI$$Base;
extern uint32 Image$$BCORE_INIT_CODE$$ZI$$Length;

extern uint32 Load$$BCORE_SHELL_CODE$$Base;
extern uint32 Image$$BCORE_SHELL_CODE$$Base;
extern uint32 Image$$BCORE_SHELL_CODE$$Length;
extern uint32 Image$$BCORE_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$BCORE_SHELL_CODE$$ZI$$Length;

//MSG SEG MODULE
extern uint32 Load$$MSG_DEV_CODE$$Base;
extern uint32 Image$$MSG_DEV_CODE$$Base;
extern uint32 Image$$MSG_DEV_CODE$$Length;
extern uint32 Image$$MSG_DEV_CODE$$ZI$$Base;
extern uint32 Image$$MSG_DEV_CODE$$ZI$$Length;

extern uint32 Load$$MSG_INIT_CODE$$Base;
extern uint32 Image$$MSG_INIT_CODE$$Base;
extern uint32 Image$$MSG_INIT_CODE$$Length;
extern uint32 Image$$MSG_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MSG_INIT_CODE$$ZI$$Length;

extern uint32 Load$$MSG_SHELL_CODE$$Base;
extern uint32 Image$$MSG_SHELL_CODE$$Base;
extern uint32 Image$$MSG_SHELL_CODE$$Length;
extern uint32 Image$$MSG_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$MSG_SHELL_CODE$$ZI$$Length;

//FILESTREAM SEG MODULE
extern uint32 Load$$FILESTREAM_TASK_CODE$$Base;
extern uint32 Image$$FILESTREAM_TASK_CODE$$Base;
extern uint32 Image$$FILESTREAM_TASK_CODE$$Length;
extern uint32 Image$$FILESTREAM_TASK_CODE$$ZI$$Base;
extern uint32 Image$$FILESTREAM_TASK_CODE$$ZI$$Length;

extern uint32 Load$$FILESTREAM_INIT_CODE$$Base;
extern uint32 Image$$FILESTREAM_INIT_CODE$$Base;
extern uint32 Image$$FILESTREAM_INIT_CODE$$Length;
extern uint32 Image$$FILESTREAM_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FILESTREAM_INIT_CODE$$ZI$$Length;

// HTTP SEG MODULE
extern uint32 Load$$HTTP_TASK_CODE$$Base;
extern uint32 Image$$HTTP_TASK_CODE$$Base;
extern uint32 Image$$HTTP_TASK_CODE$$Length;
extern uint32 Image$$HTTP_TASK_CODE$$ZI$$Base;
extern uint32 Image$$HTTP_TASK_CODE$$ZI$$Length;

extern uint32 Load$$HTTP_INIT_CODE$$Base;
extern uint32 Image$$HTTP_INIT_CODE$$Base;
extern uint32 Image$$HTTP_INIT_CODE$$Length;
extern uint32 Image$$HTTP_INIT_CODE$$ZI$$Base;
extern uint32 Image$$HTTP_INIT_CODE$$ZI$$Length;


//MEDIA SEG MODULE
extern uint32 Load$$MEDIA_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_TASK_CODE$$Base;
extern uint32 Image$$MEDIA_TASK_CODE$$Length;
extern uint32 Image$$MEDIA_TASK_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_TASK_CODE$$ZI$$Length;

extern uint32 Load$$MEDIA_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_INIT_CODE$$Base;
extern uint32 Image$$MEDIA_INIT_CODE$$Length;
extern uint32 Image$$MEDIA_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MEDIA_INIT_CODE$$ZI$$Length;



//DIR SEG MODULE
extern uint32 Load$$DIR_DEV_CODE$$Base;
extern uint32 Image$$DIR_DEV_CODE$$Base;
extern uint32 Image$$DIR_DEV_CODE$$Length;
extern uint32 Image$$DIR_DEV_CODE$$ZI$$Base;
extern uint32 Image$$DIR_DEV_CODE$$ZI$$Length;

extern uint32 Load$$DIR_INIT_CODE$$Base;
extern uint32 Image$$DIR_INIT_CODE$$Base;
extern uint32 Image$$DIR_INIT_CODE$$Length;
extern uint32 Image$$DIR_INIT_CODE$$ZI$$Base;
extern uint32 Image$$DIR_INIT_CODE$$ZI$$Length;

extern uint32 Load$$DIR_SHELL_CODE$$Base;
extern uint32 Image$$DIR_SHELL_CODE$$Base;
extern uint32 Image$$DIR_SHELL_CODE$$Length;
extern uint32 Image$$DIR_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$DIR_SHELL_CODE$$ZI$$Length;


//STREAMCONTROL SEG MODULE
extern uint32 Load$$STREAMCONTROL_TASK_CODE$$Base;
extern uint32 Image$$STREAMCONTROL_TASK_CODE$$Base;
extern uint32 Image$$STREAMCONTROL_TASK_CODE$$Length;
extern uint32 Image$$STREAMCONTROL_TASK_CODE$$ZI$$Base;
extern uint32 Image$$STREAMCONTROL_TASK_CODE$$ZI$$Length;

extern uint32 Load$$STREAMCONTROL_INIT_CODE$$Base;
extern uint32 Image$$STREAMCONTROL_INIT_CODE$$Base;
extern uint32 Image$$STREAMCONTROL_INIT_CODE$$Length;
extern uint32 Image$$STREAMCONTROL_INIT_CODE$$ZI$$Base;
extern uint32 Image$$STREAMCONTROL_INIT_CODE$$ZI$$Length;


//AUDIOCONTROL SEG MODULE
extern uint32 Load$$AUDIOCONTROL_TASK_CODE$$Base;
extern uint32 Image$$AUDIOCONTROL_TASK_CODE$$Base;
extern uint32 Image$$AUDIOCONTROL_TASK_CODE$$Length;
extern uint32 Image$$AUDIOCONTROL_TASK_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOCONTROL_TASK_CODE$$ZI$$Length;

extern uint32 Load$$AUDIOCONTROL_INIT_CODE$$Base;
extern uint32 Image$$AUDIOCONTROL_INIT_CODE$$Base;
extern uint32 Image$$AUDIOCONTROL_INIT_CODE$$Length;
extern uint32 Image$$AUDIOCONTROL_INIT_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOCONTROL_INIT_CODE$$ZI$$Length;

//RECORDCONTROL SEG MODULE
//chad.ma add
extern uint32 Load$$RECORDCONTROL_TASK_CODE$$Base;
extern uint32 Image$$RECORDCONTROL_TASK_CODE$$Base;
extern uint32 Image$$RECORDCONTROL_TASK_CODE$$Length;
extern uint32 Image$$RECORDCONTROL_TASK_CODE$$ZI$$Base;
extern uint32 Image$$RECORDCONTROL_TASK_CODE$$ZI$$Length;

extern uint32 Load$$RECORDCONTROL_INIT_CODE$$Base;
extern uint32 Image$$RECORDCONTROL_INIT_CODE$$Base;
extern uint32 Image$$RECORDCONTROL_INIT_CODE$$Length;
extern uint32 Image$$RECORDCONTROL_INIT_CODE$$ZI$$Base;
extern uint32 Image$$RECORDCONTROL_INIT_CODE$$ZI$$Length;

//Encode WAV
extern uint32  Load$$WAV_ENCODE_CODE$$Base;
extern uint32 Image$$WAV_ENCODE_CODE$$Base;
extern uint32 Image$$WAV_ENCODE_CODE$$Length;
extern uint32 Image$$WAV_ENCODE_CODE$$ZI$$Base;
extern uint32 Image$$WAV_ENCODE_CODE$$ZI$$Length;

//Encode AMR
extern uint32  Load$$AMR_ENCODE_CODE$$Base;
extern uint32 Image$$AMR_ENCODE_CODE$$Base;
extern uint32 Image$$AMR_ENCODE_CODE$$Length;
extern uint32 Image$$AMR_ENCODE_CODE$$ZI$$Base;
extern uint32 Image$$AMR_ENCODE_CODE$$ZI$$Length;

//Encode XXX
extern uint32  Load$$XXX_ENCODE_CODE$$Base;
extern uint32 Image$$XXX_ENCODE_CODE$$Base;
extern uint32 Image$$XXX_ENCODE_CODE$$Length;
extern uint32 Image$$XXX_ENCODE_CODE$$ZI$$Base;
extern uint32 Image$$XXX_ENCODE_CODE$$ZI$$Length;

//MP3
extern uint32  Load$$MP3_DECODE_CODE$$Base;
extern uint32 Image$$MP3_DECODE_CODE$$Base;
extern uint32 Image$$MP3_DECODE_CODE$$Length;
extern uint32 Image$$MP3_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$MP3_DECODE_CODE$$ZI$$Length;

//XXX
extern uint32  Load$$XXX_DECODE_CODE$$Base;
extern uint32 Image$$XXX_DECODE_CODE$$Base;
extern uint32 Image$$XXX_DECODE_CODE$$Length;
extern uint32 Image$$XXX_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$XXX_DECODE_CODE$$ZI$$Length;

//WAV
extern uint32  Load$$WAV_DECODE_CODE$$Base;
extern uint32 Image$$WAV_DECODE_CODE$$Base;
extern uint32 Image$$WAV_DECODE_CODE$$Length;
extern uint32 Image$$WAV_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$WAV_DECODE_CODE$$ZI$$Length;

//AMR
extern uint32 Load$$AMR_DECODE_CODE$$Base;
extern uint32 Image$$AMR_DECODE_CODE$$Base;
extern uint32 Image$$AMR_DECODE_CODE$$Length;
extern uint32 Image$$AMR_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$AMR_DECODE_CODE$$ZI$$Length;

//FLAC
extern uint32  Load$$FLAC_DECODE_CODE$$Base;
extern uint32 Image$$FLAC_DECODE_CODE$$Base;
extern uint32 Image$$FLAC_DECODE_CODE$$Length;
extern uint32 Image$$FLAC_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$FLAC_DECODE_CODE$$ZI$$Length;

//AAC
extern uint32  Load$$AAC_DECODE_CODE$$Base;
extern uint32 Image$$AAC_DECODE_CODE$$Base;
extern uint32 Image$$AAC_DECODE_CODE$$Length;
extern uint32 Image$$AAC_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$AAC_DECODE_CODE$$ZI$$Length;

//APE
extern uint32  Load$$APE_DECODE_CODE$$Base;
extern uint32 Image$$APE_DECODE_CODE$$Base;
extern uint32 Image$$APE_DECODE_CODE$$Length;
extern uint32 Image$$APE_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$APE_DECODE_CODE$$ZI$$Length;

//OGG

extern uint32  Load$$OGG_DECODE_CODE$$Base;
extern uint32 Image$$OGG_DECODE_CODE$$Base;
extern uint32 Image$$OGG_DECODE_CODE$$Length;
extern uint32 Image$$OGG_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$OGG_DECODE_CODE$$ZI$$Length;

//HFLAC
extern uint32  Load$$FLAC_HDECODE_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_CODE$$Length;
extern uint32 Image$$FLAC_HDECODE_CODE$$ZI$$Base;
extern uint32 Image$$FLAC_HDECODE_CODE$$ZI$$Length;

//HALAC
extern uint32  Load$$ALAC_HDECODE_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_CODE$$Length;
extern uint32 Image$$ALAC_HDECODE_CODE$$ZI$$Base;
extern uint32 Image$$ALAC_HDECODE_CODE$$ZI$$Length;


//HAPE
extern uint32  Load$$APE_HDECODE_CODE$$Base;
extern uint32 Image$$APE_HDECODE_CODE$$Base;
extern uint32 Image$$APE_HDECODE_CODE$$Length;
extern uint32 Image$$APE_HDECODE_CODE$$ZI$$Base;
extern uint32 Image$$APE_HDECODE_CODE$$ZI$$Length;

//SBC
extern uint32  Load$$SBC_DECODE_CODE$$Base;
extern uint32 Image$$SBC_DECODE_CODE$$Base;
extern uint32 Image$$SBC_DECODE_CODE$$Length;
extern uint32 Image$$SBC_DECODE_CODE$$ZI$$Base;
extern uint32 Image$$SBC_DECODE_CODE$$ZI$$Length;

//aec
extern uint32  Load$$AEC_CODE$$Base;
extern uint32 Image$$AEC_CODE$$Base;
extern uint32 Image$$AEC_CODE$$Length;
extern uint32 Load$$AEC_CODE$$RW$$Base;
extern uint32 Image$$AEC_CODE$$RW$$Base;
extern uint32 Image$$AEC_CODE$$RW$$Length;
extern uint32 Image$$AEC_CODE$$ZI$$Base;
extern uint32 Image$$AEC_CODE$$ZI$$Length;

//I2S SEG MODULE
extern uint32 Load$$I2S_DEV_CODE$$Base;
extern uint32 Image$$I2S_DEV_CODE$$Base;
extern uint32 Image$$I2S_DEV_CODE$$Length;
extern uint32 Image$$I2S_DEV_CODE$$ZI$$Base;
extern uint32 Image$$I2S_DEV_CODE$$ZI$$Length;

extern uint32 Load$$I2S_INIT_CODE$$Base;
extern uint32 Image$$I2S_INIT_CODE$$Base;
extern uint32 Image$$I2S_INIT_CODE$$Length;
extern uint32 Image$$I2S_INIT_CODE$$ZI$$Base;
extern uint32 Image$$I2S_INIT_CODE$$ZI$$Length;


extern uint32 Load$$I2S_SHELL_CODE$$Base;
extern uint32 Image$$I2S_SHELL_CODE$$Base;
extern uint32 Image$$I2S_SHELL_CODE$$Length;
extern uint32 Image$$I2S_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$I2S_SHELL_CODE$$ZI$$Length;

//ROCKCODEC SEG MODULE
extern uint32 Load$$ROCKCODEC_DEV_CODE$$Base;
extern uint32 Image$$ROCKCODEC_DEV_CODE$$Base;
extern uint32 Image$$ROCKCODEC_DEV_CODE$$Length;
extern uint32 Image$$ROCKCODEC_DEV_CODE$$ZI$$Base;
extern uint32 Image$$ROCKCODEC_DEV_CODE$$ZI$$Length;

extern uint32 Load$$ROCKCODEC_INIT_CODE$$Base;
extern uint32 Image$$ROCKCODEC_INIT_CODE$$Base;
extern uint32 Image$$ROCKCODEC_INIT_CODE$$Length;
extern uint32 Image$$ROCKCODEC_INIT_CODE$$ZI$$Base;
extern uint32 Image$$ROCKCODEC_INIT_CODE$$ZI$$Length;

extern uint32 Load$$ROCKCODEC_SHELL_CODE$$Base;
extern uint32 Image$$ROCKCODEC_SHELL_CODE$$Base;
extern uint32 Image$$ROCKCODEC_SHELL_CODE$$Length;
extern uint32 Image$$ROCKCODEC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$ROCKCODEC_SHELL_CODE$$ZI$$Length;

//AUDIO SEG MODULE
extern uint32 Load$$AUDIO_DEV_CODE$$Base;
extern uint32 Image$$AUDIO_DEV_CODE$$Base;
extern uint32 Image$$AUDIO_DEV_CODE$$Length;
extern uint32 Image$$AUDIO_DEV_CODE$$ZI$$Base;
extern uint32 Image$$AUDIO_DEV_CODE$$ZI$$Length;

extern uint32 Load$$AUDIO_INIT_CODE$$Base;
extern uint32 Image$$AUDIO_INIT_CODE$$Base;
extern uint32 Image$$AUDIO_INIT_CODE$$Length;
extern uint32 Image$$AUDIO_INIT_CODE$$ZI$$Base;
extern uint32 Image$$AUDIO_INIT_CODE$$ZI$$Length;

extern uint32 Load$$AUDIO_SHELL_CODE$$Base;
extern uint32 Image$$AUDIO_SHELL_CODE$$Base;
extern uint32 Image$$AUDIO_SHELL_CODE$$Length;
extern uint32 Image$$AUDIO_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$AUDIO_SHELL_CODE$$ZI$$Length;

//AUDIOSUB SEG MODULE
extern uint32 Load$$AUDIOSUB_TASK_CODE$$Base;
extern uint32 Image$$AUDIOSUB_TASK_CODE$$Base;
extern uint32 Image$$AUDIOSUB_TASK_CODE$$Length;
extern uint32 Image$$AUDIOSUB_TASK_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOSUB_TASK_CODE$$ZI$$Length;

extern uint32 Load$$AUDIOSUB_INIT_CODE$$Base;
extern uint32 Image$$AUDIOSUB_INIT_CODE$$Base;
extern uint32 Image$$AUDIOSUB_INIT_CODE$$Length;
extern uint32 Image$$AUDIOSUB_INIT_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOSUB_INIT_CODE$$ZI$$Length;

//AUDIOMAIN SEG MODULE
extern uint32 Load$$AUDIOMAIN_TASK_CODE$$Base;
extern uint32 Image$$AUDIOMAIN_TASK_CODE$$Base;
extern uint32 Image$$AUDIOMAIN_TASK_CODE$$Length;
extern uint32 Image$$AUDIOMAIN_TASK_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOMAIN_TASK_CODE$$ZI$$Length;

extern uint32 Load$$AUDIOMAIN_INIT_CODE$$Base;
extern uint32 Image$$AUDIOMAIN_INIT_CODE$$Base;
extern uint32 Image$$AUDIOMAIN_INIT_CODE$$Length;
extern uint32 Image$$AUDIOMAIN_INIT_CODE$$ZI$$Base;
extern uint32 Image$$AUDIOMAIN_INIT_CODE$$ZI$$Length;

//USBMSC SEG MODULE
extern uint32 Load$$USBMSC_DEV_CODE$$Base;
extern uint32 Image$$USBMSC_DEV_CODE$$Base;
extern uint32 Image$$USBMSC_DEV_CODE$$Length;
extern uint32 Image$$USBMSC_DEV_CODE$$ZI$$Base;
extern uint32 Image$$USBMSC_DEV_CODE$$ZI$$Length;

extern uint32 Load$$USBMSC_INIT_CODE$$Base;
extern uint32 Image$$USBMSC_INIT_CODE$$Base;
extern uint32 Image$$USBMSC_INIT_CODE$$Length;
extern uint32 Image$$USBMSC_INIT_CODE$$ZI$$Base;
extern uint32 Image$$USBMSC_INIT_CODE$$ZI$$Length;

extern uint32 Load$$USBMSC_SHELL_CODE$$Base;
extern uint32 Image$$USBMSC_SHELL_CODE$$Base;
extern uint32 Image$$USBMSC_SHELL_CODE$$Length;
extern uint32 Image$$USBMSC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$USBMSC_SHELL_CODE$$ZI$$Length;

//MAILBOX SEG MODULE
extern uint32 Load$$MAILBOX_DEV_CODE$$Base;
extern uint32 Image$$MAILBOX_DEV_CODE$$Base;
extern uint32 Image$$MAILBOX_DEV_CODE$$Length;
extern uint32 Image$$MAILBOX_DEV_CODE$$ZI$$Base;
extern uint32 Image$$MAILBOX_DEV_CODE$$ZI$$Length;

extern uint32 Load$$MAILBOX_INIT_CODE$$Base;
extern uint32 Image$$MAILBOX_INIT_CODE$$Base;
extern uint32 Image$$MAILBOX_INIT_CODE$$Length;
extern uint32 Image$$MAILBOX_INIT_CODE$$ZI$$Base;
extern uint32 Image$$MAILBOX_INIT_CODE$$ZI$$Length;

extern uint32 Load$$MAILBOX_SHELL_CODE$$Base;
extern uint32 Image$$MAILBOX_SHELL_CODE$$Base;
extern uint32 Image$$MAILBOX_SHELL_CODE$$Length;
extern uint32 Image$$MAILBOX_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$MAILBOX_SHELL_CODE$$ZI$$Length;

//RK618 SEG MODULE
extern uint32 Load$$RK618_DEV_CODE$$Base;
extern uint32 Image$$RK618_DEV_CODE$$Base;
extern uint32 Image$$RK618_DEV_CODE$$Length;
extern uint32 Image$$RK618_DEV_CODE$$ZI$$Base;
extern uint32 Image$$RK618_DEV_CODE$$ZI$$Length;

extern uint32 Load$$RK618_INIT_CODE$$Base;
extern uint32 Image$$RK618_INIT_CODE$$Base;
extern uint32 Image$$RK618_INIT_CODE$$Length;
extern uint32 Image$$RK618_INIT_CODE$$ZI$$Base;
extern uint32 Image$$RK618_INIT_CODE$$ZI$$Length;

extern uint32 Load$$RK618_SHELL_CODE$$Base;
extern uint32 Image$$RK618_SHELL_CODE$$Base;
extern uint32 Image$$RK618_SHELL_CODE$$Length;
extern uint32 Image$$RK618_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$RK618_SHELL_CODE$$ZI$$Length;

//SD SEG MODULE
extern uint32 Load$$SD_DEV_CODE$$Base;
extern uint32 Image$$SD_DEV_CODE$$Base;
extern uint32 Image$$SD_DEV_CODE$$Length;
extern uint32 Image$$SD_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SD_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SD_INIT_CODE$$Base;
extern uint32 Image$$SD_INIT_CODE$$Base;
extern uint32 Image$$SD_INIT_CODE$$Length;
extern uint32 Image$$SD_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SD_INIT_CODE$$ZI$$Length;

extern uint32 Load$$SD_SHELL_CODE$$Base;
extern uint32 Image$$SD_SHELL_CODE$$Base;
extern uint32 Image$$SD_SHELL_CODE$$Length;
extern uint32 Image$$SD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SD_SHELL_CODE$$ZI$$Length;

//SD SEG MODULE
extern uint32 Load$$FIFO_DEV_CODE$$Base;
extern uint32 Image$$FIFO_DEV_CODE$$Base;
extern uint32 Image$$FIFO_DEV_CODE$$Length;
extern uint32 Image$$FIFO_DEV_CODE$$ZI$$Base;
extern uint32 Image$$FIFO_DEV_CODE$$ZI$$Length;

extern uint32 Load$$FIFO_INIT_CODE$$Base;
extern uint32 Image$$FIFO_INIT_CODE$$Base;
extern uint32 Image$$FIFO_INIT_CODE$$Length;
extern uint32 Image$$FIFO_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FIFO_INIT_CODE$$ZI$$Length;

extern uint32 Load$$FIFO_SHELL_CODE$$Base;
extern uint32 Image$$FIFO_SHELL_CODE$$Base;
extern uint32 Image$$FIFO_SHELL_CODE$$Length;
extern uint32 Image$$FIFO_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$FIFO_SHELL_CODE$$ZI$$Length;

//I2C SEG MODULE
extern uint32 Load$$I2C_DEV_CODE$$Base;
extern uint32 Image$$I2C_DEV_CODE$$Base;
extern uint32 Image$$I2C_DEV_CODE$$Length;
extern uint32 Image$$I2C_DEV_CODE$$ZI$$Base;
extern uint32 Image$$I2C_DEV_CODE$$ZI$$Length;

extern uint32 Load$$I2C_INIT_CODE$$Base;
extern uint32 Image$$I2C_INIT_CODE$$Base;
extern uint32 Image$$I2C_INIT_CODE$$Length;
extern uint32 Image$$I2C_INIT_CODE$$ZI$$Base;
extern uint32 Image$$I2C_INIT_CODE$$ZI$$Length;

extern uint32 Load$$I2C_SHELL_CODE$$Base;
extern uint32 Image$$I2C_SHELL_CODE$$Base;
extern uint32 Image$$I2C_SHELL_CODE$$Length;
extern uint32 Image$$I2C_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$I2C_SHELL_CODE$$ZI$$Length;

//USBOTG SEG MODULE
extern uint32 Load$$USBOTG_DEV_CODE$$Base;
extern uint32 Image$$USBOTG_DEV_CODE$$Base;
extern uint32 Image$$USBOTG_DEV_CODE$$Length;
extern uint32 Image$$USBOTG_DEV_CODE$$ZI$$Base;
extern uint32 Image$$USBOTG_DEV_CODE$$ZI$$Length;

extern uint32 Load$$USBOTG_INIT_CODE$$Base;
extern uint32 Image$$USBOTG_INIT_CODE$$Base;
extern uint32 Image$$USBOTG_INIT_CODE$$Length;
extern uint32 Image$$USBOTG_INIT_CODE$$ZI$$Base;
extern uint32 Image$$USBOTG_INIT_CODE$$ZI$$Length;

extern uint32 Load$$USBOTG_SHELL_CODE$$Base;
extern uint32 Image$$USBOTG_SHELL_CODE$$Base;
extern uint32 Image$$USBOTG_SHELL_CODE$$Length;
extern uint32 Image$$USBOTG_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$USBOTG_SHELL_CODE$$ZI$$Length;

//SDC SEG MODULE
extern uint32 Load$$SDC_DEV_CODE$$Base;
extern uint32 Image$$SDC_DEV_CODE$$Base;
extern uint32 Image$$SDC_DEV_CODE$$Length;
extern uint32 Image$$SDC_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SDC_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SDC_SHELL_CODE$$Base;
extern uint32 Image$$SDC_SHELL_CODE$$Base;
extern uint32 Image$$SDC_SHELL_CODE$$Length;
extern uint32 Image$$SDC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SDC_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$SDC_INIT_CODE$$Base;
extern uint32 Image$$SDC_INIT_CODE$$Base;
extern uint32 Image$$SDC_INIT_CODE$$Length;
extern uint32 Image$$SDC_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SDC_INIT_CODE$$ZI$$Length;

//DMA SEG MODULE
extern uint32 Load$$DMA_SHELL_CODE$$Base;
extern uint32 Image$$DMA_SHELL_CODE$$Base;
extern uint32 Image$$DMA_SHELL_CODE$$Length;
extern uint32 Image$$DMA_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$DMA_SHELL_CODE$$ZI$$Length;

//EMMC SEG MODULE
extern uint32 Load$$EMMC_DEV_CODE$$Base;
extern uint32 Image$$EMMC_DEV_CODE$$Base;
extern uint32 Image$$EMMC_DEV_CODE$$Length;
extern uint32 Image$$EMMC_DEV_CODE$$ZI$$Base;
extern uint32 Image$$EMMC_DEV_CODE$$ZI$$Length;

extern uint32 Load$$EMMC_SHELL_CODE$$Base;
extern uint32 Image$$EMMC_SHELL_CODE$$Base;
extern uint32 Image$$EMMC_SHELL_CODE$$Length;
extern uint32 Image$$EMMC_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$EMMC_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$EMMC_INIT_CODE$$Base;
extern uint32 Image$$EMMC_INIT_CODE$$Base;
extern uint32 Image$$EMMC_INIT_CODE$$Length;
extern uint32 Image$$EMMC_INIT_CODE$$ZI$$Base;
extern uint32 Image$$EMMC_INIT_CODE$$ZI$$Length;

//LUN SEG MODULE
extern uint32 Load$$LUN_DEV_CODE$$Base;
extern uint32 Image$$LUN_DEV_CODE$$Base;
extern uint32 Image$$LUN_DEV_CODE$$Length;
extern uint32 Image$$LUN_DEV_CODE$$ZI$$Base;
extern uint32 Image$$LUN_DEV_CODE$$ZI$$Length;

extern uint32 Load$$LUN_SHELL_CODE$$Base;
extern uint32 Image$$LUN_SHELL_CODE$$Base;
extern uint32 Image$$LUN_SHELL_CODE$$Length;
extern uint32 Image$$LUN_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$LUN_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$LUN_INIT_CODE$$Base;
extern uint32 Image$$LUN_INIT_CODE$$Base;
extern uint32 Image$$LUN_INIT_CODE$$Length;
extern uint32 Image$$LUN_INIT_CODE$$ZI$$Base;
extern uint32 Image$$LUN_INIT_CODE$$ZI$$Length;

//PAR SEG MODULE
extern uint32 Load$$PAR_DEV_CODE$$Base;
extern uint32 Image$$PAR_DEV_CODE$$Base;
extern uint32 Image$$PAR_DEV_CODE$$Length;
extern uint32 Image$$PAR_DEV_CODE$$ZI$$Base;
extern uint32 Image$$PAR_DEV_CODE$$ZI$$Length;

extern uint32 Load$$PAR_SHELL_CODE$$Base;
extern uint32 Image$$PAR_SHELL_CODE$$Base;
extern uint32 Image$$PAR_SHELL_CODE$$Length;
extern uint32 Image$$PAR_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$PAR_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$PAR_INIT_CODE$$Base;
extern uint32 Image$$PAR_INIT_CODE$$Base;
extern uint32 Image$$PAR_INIT_CODE$$Length;
extern uint32 Image$$PAR_INIT_CODE$$ZI$$Base;
extern uint32 Image$$PAR_INIT_CODE$$ZI$$Length;

//FAT SEG MODULE
extern uint32 Load$$FAT_DEV_CODE$$Base;
extern uint32 Image$$FAT_DEV_CODE$$Base;
extern uint32 Image$$FAT_DEV_CODE$$Length;
extern uint32 Image$$FAT_DEV_CODE$$ZI$$Base;
extern uint32 Image$$FAT_DEV_CODE$$ZI$$Length;

extern uint32 Load$$FAT_SHELL_CODE$$Base;
extern uint32 Image$$FAT_SHELL_CODE$$Base;
extern uint32 Image$$FAT_SHELL_CODE$$Length;
extern uint32 Image$$FAT_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$FAT_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$FAT_INIT_CODE$$Base;
extern uint32 Image$$FAT_INIT_CODE$$Base;
extern uint32 Image$$FAT_INIT_CODE$$Length;
extern uint32 Image$$FAT_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FAT_INIT_CODE$$ZI$$Length;

//FILE SEG MODULE
extern uint32 Load$$FILE_DEV_CODE$$Base;
extern uint32 Image$$FILE_DEV_CODE$$Base;
extern uint32 Image$$FILE_DEV_CODE$$Length;
extern uint32 Image$$FILE_DEV_CODE$$ZI$$Base;
extern uint32 Image$$FILE_DEV_CODE$$ZI$$Length;

extern uint32 Load$$FILE_SHELL_CODE$$Base;
extern uint32 Image$$FILE_SHELL_CODE$$Base;
extern uint32 Image$$FILE_SHELL_CODE$$Length;
extern uint32 Image$$FILE_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$FILE_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$FILE_INIT_CODE$$Base;
extern uint32 Image$$FILE_INIT_CODE$$Base;
extern uint32 Image$$FILE_INIT_CODE$$Length;
extern uint32 Image$$FILE_INIT_CODE$$ZI$$Base;
extern uint32 Image$$FILE_INIT_CODE$$ZI$$Length;

//SDIO SEG MODULE
extern uint32 Load$$SDIO_DEV_CODE$$Base;
extern uint32 Image$$SDIO_DEV_CODE$$Base;
extern uint32 Image$$SDIO_DEV_CODE$$Length;
extern uint32 Image$$SDIO_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SDIO_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SDIO_SHELL_CODE$$Base;
extern uint32 Image$$SDIO_SHELL_CODE$$Base;
extern uint32 Image$$SDIO_SHELL_CODE$$Length;
extern uint32 Image$$SDIO_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SDIO_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$SDIO_INIT_CODE$$Base;
extern uint32 Image$$SDIO_INIT_CODE$$Base;
extern uint32 Image$$SDIO_INIT_CODE$$Length;
extern uint32 Image$$SDIO_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SDIO_INIT_CODE$$ZI$$Length;

//UART SEG MODULE
extern uint32 Load$$UART_DEV_CODE$$Base;
extern uint32 Image$$UART_DEV_CODE$$Base;
extern uint32 Image$$UART_DEV_CODE$$Length;
extern uint32 Image$$UART_DEV_CODE$$ZI$$Base;
extern uint32 Image$$UART_DEV_CODE$$ZI$$Length;

extern uint32 Load$$UART_SHELL_CODE$$Base;
extern uint32 Image$$UART_SHELL_CODE$$Base;
extern uint32 Image$$UART_SHELL_CODE$$Length;
extern uint32 Image$$UART_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$UART_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$UART_INIT_CODE$$Base;
extern uint32 Image$$UART_INIT_CODE$$Base;
extern uint32 Image$$UART_INIT_CODE$$Length;
extern uint32 Image$$UART_INIT_CODE$$ZI$$Base;
extern uint32 Image$$UART_INIT_CODE$$ZI$$Length;

//WDOG SEG MODULE
extern uint32 Load$$WDOG_DEV_CODE$$Base;
extern uint32 Image$$WDOG_DEV_CODE$$Base;
extern uint32 Image$$WDOG_DEV_CODE$$Length;
extern uint32 Image$$WDOG_DEV_CODE$$ZI$$Base;
extern uint32 Image$$WDOG_DEV_CODE$$ZI$$Length;

extern uint32 Load$$WDOG_SHELL_CODE$$Base;
extern uint32 Image$$WDOG_SHELL_CODE$$Base;
extern uint32 Image$$WDOG_SHELL_CODE$$Length;
extern uint32 Image$$WDOG_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$WDOG_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$WDOG_INIT_CODE$$Base;
extern uint32 Image$$WDOG_INIT_CODE$$Base;
extern uint32 Image$$WDOG_INIT_CODE$$Length;
extern uint32 Image$$WDOG_INIT_CODE$$ZI$$Base;
extern uint32 Image$$WDOG_INIT_CODE$$ZI$$Length;

// innowifi
extern uint32 Load$$I6000_DEV_CODE$$Base;
extern uint32 Image$$I6000_DEV_CODE$$Base;
extern uint32 Image$$I6000_DEV_CODE$$Length;
extern uint32 Image$$I6000_DEV_CODE$$ZI$$Base;
extern uint32 Image$$I6000_DEV_CODE$$ZI$$Length;

extern uint32 Load$$I6000_DEV_CODE2$$Base;
extern uint32 Image$$I6000_DEV_CODE2$$Base;
extern uint32 Image$$I6000_DEV_CODE2$$Length;
extern uint32 Image$$I6000_DEV_CODE2$$ZI$$Base;
extern uint32 Image$$I6000_DEV_CODE2$$ZI$$Length;

extern uint32 Load$$I6000_SHELL_CODE$$Base;
extern uint32 Image$$I6000_SHELL_CODE$$Base;
extern uint32 Image$$I6000_SHELL_CODE$$Length;
extern uint32 Image$$I6000_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$I6000_SHELL_CODE$$ZI$$Length;

//ap6181
extern uint32 Load$$WIFI_APPLICATIONTASK_INIT_CODE$$Base;
extern uint32 Image$$WIFI_APPLICATIONTASK_INIT_CODE$$Base;
extern uint32 Image$$WIFI_APPLICATIONTASK_INIT_CODE$$Length;
extern uint32 Image$$WIFI_APPLICATIONTASK_INIT_CODE$$ZI$$Base;
extern uint32 Image$$WIFI_APPLICATIONTASK_INIT_CODE$$ZI$$Length;

extern uint32 Load$$WIFIAPP_TASK_CODE$$Base;
extern uint32 Image$$WIFIAPP_TASK_CODE$$Base;
extern uint32 Image$$WIFIAPP_TASK_CODE$$Length;
extern uint32 Image$$WIFIAPP_TASK_CODE$$ZI$$Base;
extern uint32 Image$$WIFIAPP_TASK_CODE$$ZI$$Length;

extern uint32 Load$$AP6181WIFI_INIT_CODE$$Base;
extern uint32 Image$$AP6181WIFI_INIT_CODE$$Base;
extern uint32 Image$$AP6181WIFI_INIT_CODE$$Length;
extern uint32 Image$$AP6181WIFI_INIT_CODE$$ZI$$Base;
extern uint32 Image$$AP6181WIFI_INIT_CODE$$ZI$$Length;

extern uint32 Load$$AP6181WIFI_DEV_CODE$$Base;
extern uint32 Image$$AP6181WIFI_DEV_CODE$$Base;
extern uint32 Image$$AP6181WIFI_DEV_CODE$$Length;
extern uint32 Image$$AP6181WIFI_DEV_CODE$$ZI$$Base;
extern uint32 Image$$AP6181WIFI_DEV_CODE$$ZI$$Length;

extern uint32 Load$$AP6181WIFI_SHELL_CODE$$Base;
extern uint32 Image$$AP6181WIFI_SHELL_CODE$$Base;
extern uint32 Image$$AP6181WIFI_SHELL_CODE$$Length;
extern uint32 Image$$AP6181WIFI_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$AP6181WIFI_SHELL_CODE$$ZI$$Length;

//dlna
extern uint32 Load$$DLNA_TASK_INIT_CODE$$Base;
extern uint32 Image$$DLNA_TASK_INIT_CODE$$Base;
extern uint32 Image$$DLNA_TASK_INIT_CODE$$Length;
extern uint32 Image$$DLNA_TASK_INIT_CODE$$ZI$$Base;
extern uint32 Image$$DLNA_TASK_INIT_CODE$$ZI$$Length;

extern uint32 Load$$DLNA_TASK_CODE$$Base;
extern uint32 Image$$DLNA_TASK_CODE$$Base;
extern uint32 Image$$DLNA_TASK_CODE$$Length;
extern uint32 Image$$DLNA_TASK_CODE$$ZI$$Base;
extern uint32 Image$$DLNA_TASK_CODE$$ZI$$Length;

extern uint32 Load$$DLNA_SHELL_CODE$$Base;
extern uint32 Image$$DLNA_SHELL_CODE$$Base;
extern uint32 Image$$DLNA_SHELL_CODE$$Length;
extern uint32 Image$$DLNA_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$DLNA_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$DLNA_DEV_CODE$$Base;
extern uint32 Image$$DLNA_DEV_CODE$$Base;
extern uint32 Image$$DLNA_DEV_CODE$$Length;
extern uint32 Image$$DLNA_DEV_CODE$$ZI$$Base;
extern uint32 Image$$DLNA_DEV_CODE$$ZI$$Length;

//upnp
extern uint32 Load$$UPNP_DEV_CODE$$Base;
extern uint32 Image$$UPNP_DEV_CODE$$Base;
extern uint32 Image$$UPNP_DEV_CODE$$Length;
extern uint32 Image$$UPNP_DEV_CODE$$ZI$$Base;
extern uint32 Image$$UPNP_DEV_CODE$$ZI$$Length;

extern uint32 Load$$XMLPARSE_DEV_CODE$$Base;
extern uint32 Image$$XMLPARSE_DEV_CODE$$Base;
extern uint32 Image$$XMLPARSE_DEV_CODE$$Length;
extern uint32 Image$$XMLPARSE_DEV_CODE$$ZI$$Base;
extern uint32 Image$$XMLPARSE_DEV_CODE$$ZI$$Length;

//XXX
extern uint32 Load$$XXX_TASK_INIT_CODE$$Base;
extern uint32 Image$$XXX_TASK_INIT_CODE$$Base;
extern uint32 Image$$XXX_TASK_INIT_CODE$$Length;
extern uint32 Image$$XXX_TASK_INIT_CODE$$ZI$$Base;
extern uint32 Image$$XXX_TASK_INIT_CODE$$ZI$$Length;

extern uint32 Load$$XXX_SHELL_CODE$$Base;
extern uint32 Image$$XXX_SHELL_CODE$$Base;
extern uint32 Image$$XXX_SHELL_CODE$$Length;
extern uint32 Image$$XXX_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$XXX_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$XXX_DEV_CODE$$Base;
extern uint32 Image$$XXX_DEV_CODE$$Base;
extern uint32 Image$$XXX_DEV_CODE$$Length;
extern uint32 Image$$XXX_DEV_CODE$$ZI$$Base;
extern uint32 Image$$XXX_DEV_CODE$$ZI$$Length;

//CHANNELS speaker
extern uint32 Load$$CHANNELS_SPEAKER_CODE$$Base;
extern uint32 Image$$CHANNELS_SPEAKER_CODE$$Base;
extern uint32 Image$$CHANNELS_SPEAKER_CODE$$Length;
extern uint32 Image$$CHANNELS_SPEAKER_CODE$$ZI$$Base;
extern uint32 Image$$CHANNELS_SPEAKER_CODE$$ZI$$Length;

//SSL
extern uint32 Load$$SSL_DEV_CODE$$Base;
extern uint32 Image$$SSL_DEV_CODE$$Base;
extern uint32 Image$$SSL_DEV_CODE$$Length;
extern uint32 Image$$SSL_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SSL_DEV_CODE$$ZI$$Length;

//SWITCH_PLAYER JJJHHH
/*extern uint32 Load$$SHELL_SWITCH_PLAYER_CODE$$Base;
extern uint32 Image$$SHELL_SWITCH_PLAYER_CODE$$Base;
extern uint32 Image$$SHELL_SWITCH_PLAYER_CODE$$Length;
extern uint32 Image$$SHELL_SWITCH_PLAYER_CODE$$ZI$$Base;
extern uint32 Image$$SHELL_SWITCH_PLAYER_CODE$$ZI$$Length;*/


//lwip
extern uint32 Load$$LWIP_DEV_CODE$$Base;
extern uint32 Image$$LWIP_DEV_CODE$$Base;
extern uint32 Image$$LWIP_DEV_CODE$$Length;
extern uint32 Image$$LWIP_DEV_CODE$$ZI$$Base;
extern uint32 Image$$LWIP_DEV_CODE$$ZI$$Length;

//ping
extern uint32 Load$$PING_SHELL_CODE$$Base;
extern uint32 Image$$PING_SHELL_CODE$$Base;
extern uint32 Image$$PING_SHELL_CODE$$Length;
extern uint32 Image$$PING_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$PING_SHELL_CODE$$ZI$$Length;

//ip config
extern uint32 Load$$IPCONFIG_SHELL_CODE$$Base;
extern uint32 Image$$IPCONFIG_SHELL_CODE$$Base;
extern uint32 Image$$IPCONFIG_SHELL_CODE$$Length;
extern uint32 Image$$IPCONFIG_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$IPCONFIG_SHELL_CODE$$ZI$$Length;

//api
extern uint32 Load$$LWIP_DEV_API_CODE$$Base;
extern uint32 Image$$LWIP_DEV_API_CODE$$Base;
extern uint32 Image$$LWIP_DEV_API_CODE$$Length;
extern uint32 Image$$LWIP_DEV_API_CODE$$ZI$$Base;
extern uint32 Image$$LWIP_DEV_API_CODE$$ZI$$Length;

//HTTP
extern uint32 Load$$LWIP_DEV_HTTP_CODE$$Base;
extern uint32 Image$$LWIP_DEV_HTTP_CODE$$Base;
extern uint32 Image$$LWIP_DEV_HTTP_CODE$$Length;

extern uint32 Load$$LWIP_DEV_HTTP_CODE$$RW$$Base;
extern uint32 Image$$LWIP_DEV_HTTP_CODE$$RW$$Base;
extern uint32 Image$$LWIP_DEV_HTTP_CODE$$RW$$Length;

extern uint32 Image$$LWIP_DEV_HTTP_CODE$$ZI$$Base;
extern uint32 Image$$LWIP_DEV_HTTP_CODE$$ZI$$Length;

//HTTPD
extern uint32 Load$$LWIP_DEV_HTTPD_CODE$$Base;
extern uint32 Image$$LWIP_DEV_HTTPD_CODE$$Base;
extern uint32 Image$$LWIP_DEV_HTTPD_CODE$$Length;
extern uint32 Image$$LWIP_DEV_HTTPD_CODE$$ZI$$Base;
extern uint32 Image$$LWIP_DEV_HTTPD_CODE$$ZI$$Length;


//mbedtls
extern uint32 Load$$MBEDTLS_DEV_CODE$$Base;
extern uint32 Image$$MBEDTLS_DEV_CODE$$Base;
extern uint32 Image$$MBEDTLS_DEV_CODE$$Length;
extern uint32 Image$$MBEDTLS_DEV_CODE$$ZI$$Base;
extern uint32 Image$$MBEDTLS_DEV_CODE$$ZI$$Length;

//bluetooth
extern uint32 Load$$BLUETOOTH_CODE$$Base;
extern uint32 Image$$BLUETOOTH_CODE$$Base;
extern uint32 Image$$BLUETOOTH_CODE$$Length;
extern uint32 Image$$BLUETOOTH_CODE$$ZI$$Base;
extern uint32 Image$$BLUETOOTH_CODE$$ZI$$Length;

extern uint32 Load$$BLUETOOTH_SHELL_CODE$$Base;
extern uint32 Image$$BLUETOOTH_SHELL_CODE$$Base;
extern uint32 Image$$BLUETOOTH_SHELL_CODE$$Length;
extern uint32 Image$$BLUETOOTH_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$BLUETOOTH_SHELL_CODE$$ZI$$Length;

//bluetooth lwbt
extern uint32 Load$$BLUETOOTH_LWBT_CODE$$Base;
extern uint32 Image$$BLUETOOTH_LWBT_CODE$$Base;
extern uint32 Image$$BLUETOOTH_LWBT_CODE$$Length;
extern uint32 Image$$BLUETOOTH_LWBT_CODE$$ZI$$Base;
extern uint32 Image$$BLUETOOTH_LWBT_CODE$$ZI$$Length;


//SPIFLASH SEG MODULE
extern uint32 Load$$SPIFLASH_DEV_CODE$$Base;
extern uint32 Image$$SPIFLASH_DEV_CODE$$Base;
extern uint32 Image$$SPIFLASH_DEV_CODE$$Length;
extern uint32 Image$$SPIFLASH_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SPIFLASH_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SPIFLASH_SHELL_CODE$$Base;
extern uint32 Image$$SPIFLASH_SHELL_CODE$$Base;
extern uint32 Image$$SPIFLASH_SHELL_CODE$$Length;
extern uint32 Image$$SPIFLASH_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SPIFLASH_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$SPIFLASH_INIT_CODE$$Base;
extern uint32 Image$$SPIFLASH_INIT_CODE$$Base;
extern uint32 Image$$SPIFLASH_INIT_CODE$$Length;
extern uint32 Image$$SPIFLASH_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SPIFLASH_INIT_CODE$$ZI$$Length;

//SPI SEG MODULE
extern uint32 Load$$SPI_DEV_CODE$$Base;
extern uint32 Image$$SPI_DEV_CODE$$Base;
extern uint32 Image$$SPI_DEV_CODE$$Length;
extern uint32 Image$$SPI_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SPI_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SPI_SHELL_CODE$$Base;
extern uint32 Image$$SPI_SHELL_CODE$$Base;
extern uint32 Image$$SPI_SHELL_CODE$$Length;
extern uint32 Image$$SPI_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SPI_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$SPI_INIT_CODE$$Base;
extern uint32 Image$$SPI_INIT_CODE$$Base;
extern uint32 Image$$SPI_INIT_CODE$$Length;
extern uint32 Image$$SPI_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SPI_INIT_CODE$$ZI$$Length;


//SPINOR SEG MODULE
extern uint32 Load$$SPINOR_DEV_CODE$$Base;
extern uint32 Image$$SPINOR_DEV_CODE$$Base;
extern uint32 Image$$SPINOR_DEV_CODE$$Length;
extern uint32 Image$$SPINOR_DEV_CODE$$ZI$$Base;
extern uint32 Image$$SPINOR_DEV_CODE$$ZI$$Length;

extern uint32 Load$$SPINOR_SHELL_CODE$$Base;
extern uint32 Image$$SPINOR_SHELL_CODE$$Base;
extern uint32 Image$$SPINOR_SHELL_CODE$$Length;
extern uint32 Image$$SPINOR_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SPINOR_SHELL_CODE$$ZI$$Length;

extern uint32 Load$$SPINOR_INIT_CODE$$Base;
extern uint32 Image$$SPINOR_INIT_CODE$$Base;
extern uint32 Image$$SPINOR_INIT_CODE$$Length;
extern uint32 Image$$SPINOR_INIT_CODE$$ZI$$Base;
extern uint32 Image$$SPINOR_INIT_CODE$$ZI$$Length;


//WIFI FIRMWARE MODULE
extern uint32 Load$$WIFI_FIRMWARE_ONE$$Base;
extern uint32 Image$$WIFI_FIRMWARE_ONE$$Base;
extern uint32 Image$$WIFI_FIRMWARE_ONE$$Length;
extern uint32 Load$$WIFI_FIRMWARE_TWO$$Base;
extern uint32 Image$$WIFI_FIRMWARE_TWO$$Base;
extern uint32 Image$$WIFI_FIRMWARE_TWO$$Length;
extern uint32 Load$$WIFI_FIRMWARE_RKI6000$$Base;
extern uint32 Image$$WIFI_FIRMWARE_RKI6000$$Base;
extern uint32 Image$$WIFI_FIRMWARE_RKI6000$$Length;
//BT FIRMWARE MODULE
extern uint32 Load$$BT_FIRMWARE$$Base;
extern uint32 Image$$BT_FIRMWARE$$Base;
extern uint32 Image$$BT_FIRMWARE$$Length;

//AUDIO EQTABLE
extern uint32 Load$$AUDIO_EQ_DATA$$Base;
extern uint32 Image$$AUDIO_EQ_DATA$$Base;
extern uint32 Image$$AUDIO_EQ_DATA$$Length;
//xml DMR
extern uint32 Load$$DMR_DEVICE_DATA$$Base;
extern uint32 Image$$DMR_DEVICE_DATA$$Base;
extern uint32 Image$$DMR_DEVICE_DATA$$Length;

extern uint32 Load$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Length;

extern uint32 Load$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Length;

#if 1//#ifdef _QPLAY_ENABLE
extern uint32 Load$$DMR_QPLAY_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_QPLAY_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_QPLAY_SERVICE_DATA$$Length;
#endif

extern uint32 Load$$DMR_AVTRANSPORT_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_AVTRANSPORT_SERVICE_DATA$$Base;
extern uint32 Image$$DMR_AVTRANSPORT_SERVICE_DATA$$Length;

//nametab

extern uint32 Load$$DMR_NAMINGBITMAP_DATA$$Base;
extern uint32 Image$$DMR_NAMINGBITMAP_DATA$$Base;
extern uint32 Image$$DMR_NAMINGBITMAP_DATA$$Length;

extern uint32 Load$$DMR_NMSTRTPAGES_DATA$$Base;
extern uint32 Image$$DMR_NMSTRTPAGES_DATA$$Base;
extern uint32 Image$$DMR_NMSTRTPAGES_DATA$$Length;

extern uint32 Load$$DMR_NAMEPAGES_DATA$$Base;
extern uint32 Image$$DMR_NAMEPAGES_DATA$$Base;
extern uint32 Image$$DMR_NAMEPAGES_DATA$$Length;

//SYS_CMD
extern uint32 Load$$SYSCMD_SHELL_CODE$$Base;
extern uint32 Image$$SYSCMD_SHELL_CODE$$Base;
extern uint32 Image$$SYSCMD_SHELL_CODE$$Length;
extern uint32 Image$$SYSCMD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$SYSCMD_SHELL_CODE$$ZI$$Length;

//DEV_CMD
extern uint32 Load$$DEVCMD_SHELL_CODE$$Base;
extern uint32 Image$$DEVCMD_SHELL_CODE$$Base;
extern uint32 Image$$DEVCMD_SHELL_CODE$$Length;
extern uint32 Image$$DEVCMD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$DEVCMD_SHELL_CODE$$ZI$$Length;


//TASK_CMD
extern uint32 Load$$TASKCMD_SHELL_CODE$$Base;
extern uint32 Image$$TASKCMD_SHELL_CODE$$Base;
extern uint32 Image$$TASKCMD_SHELL_CODE$$Length;
extern uint32 Image$$TASKCMD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$TASKCMD_SHELL_CODE$$ZI$$Length;


//CUSTOM_CMD
extern uint32 Load$$CUSTOMCMD_SHELL_CODE$$Base;
extern uint32 Image$$CUSTOMCMD_SHELL_CODE$$Base;
extern uint32 Image$$CUSTOMCMD_SHELL_CODE$$Length;
extern uint32 Image$$CUSTOMCMD_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$CUSTOMCMD_SHELL_CODE$$ZI$$Length;


/****************BB 核*************************/
extern uint32  Load$$BB_SYS_CODE$$Base;
extern uint32 Image$$BB_SYS_CODE$$Base;
extern uint32 Image$$BB_SYS_CODE$$Length;
extern uint32  Load$$BB_SYS_DATA$$Base;
extern uint32 Image$$BB_SYS_DATA$$RW$$Base;
extern uint32 Image$$BB_SYS_DATA$$RW$$Length;
extern uint32 Image$$BB_SYS_DATA$$ZI$$Base;
extern uint32 Image$$BB_SYS_DATA$$ZI$$Length;

//SBC
extern uint32  Load$$SBC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$SBC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$SBC_DECODE_BIN_CODE$$Length;
extern uint32  Load$$SBC_DECODE_BIN_DATA$$Base;
extern uint32 Image$$SBC_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$SBC_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$SBC_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$SBC_DECODE_BIN_DATA$$ZI$$Length;


//MP3
extern uint32  Load$$MP3_DECODE_BIN_CODE$$Base;
extern uint32 Image$$MP3_DECODE_BIN_CODE$$Base;
extern uint32 Image$$MP3_DECODE_BIN_CODE$$Length;
extern uint32  Load$$MP3_DECODE_BIN_DATA$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$MP3_DECODE_BIN_DATA$$ZI$$Length;

//XXX
extern uint32  Load$$XXX_DECODE_BIN_CODE$$Base;
extern uint32 Image$$XXX_DECODE_BIN_CODE$$Base;
extern uint32 Image$$XXX_DECODE_BIN_CODE$$Length;
extern uint32  Load$$XXX_DECODE_BIN_DATA$$Base;
extern uint32 Image$$XXX_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$XXX_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$XXX_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$XXX_DECODE_BIN_DATA$$ZI$$Length;


//WAV
extern uint32  Load$$WAV_DECODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_DECODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_DECODE_BIN_CODE$$Length;
extern uint32  Load$$WAV_DECODE_BIN_DATA$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$WAV_DECODE_BIN_DATA$$ZI$$Length;

//AMR
extern uint32  Load$$AMR_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AMR_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AMR_DECODE_BIN_CODE$$Length;
extern uint32  Load$$AMR_DECODE_BIN_DATA$$Base;
extern uint32 Image$$AMR_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$AMR_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$AMR_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$AMR_DECODE_BIN_DATA$$ZI$$Length;

//FLAC
extern uint32  Load$$FLAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_DECODE_BIN_CODE$$Length;
extern uint32  Load$$FLAC_DECODE_BIN_DATA$$Base;
extern uint32 Image$$FLAC_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$FLAC_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$FLAC_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$FLAC_DECODE_BIN_DATA$$ZI$$Length;

//AAC
extern uint32  Load$$AAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AAC_DECODE_BIN_CODE$$Base;
extern uint32 Image$$AAC_DECODE_BIN_CODE$$Length;
extern uint32  Load$$AAC_DECODE_BIN_DATA$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$AAC_DECODE_BIN_DATA$$ZI$$Length;

//APE
extern uint32 Load$$APE_DECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_DECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_DECODE_BIN_CODE$$Length;
extern uint32 Load$$APE_DECODE_BIN_DATA$$Base;
extern uint32 Image$$APE_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$APE_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$APE_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$APE_DECODE_BIN_DATA$$ZI$$Length;


//OGG
extern uint32  Load$$OGG_DECODE_BIN_CODE$$Base;
extern uint32 Image$$OGG_DECODE_BIN_CODE$$Base;
extern uint32 Image$$OGG_DECODE_BIN_CODE$$Length;
extern uint32  Load$$OGG_DECODE_BIN_DATA$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$OGG_DECODE_BIN_DATA$$ZI$$Length;


//HFLAC
extern uint32  Load$$FLAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$FLAC_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Length;

//HALAC
extern uint32  Load$$ALAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$ALAC_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Length;

//HAPE
extern uint32  Load$$APE_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_HDECODE_BIN_CODE$$Base;
extern uint32 Image$$APE_HDECODE_BIN_CODE$$Length;
extern uint32  Load$$APE_HDECODE_BIN_DATA$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$APE_HDECODE_BIN_DATA$$ZI$$Length;


//XXX ENC
extern uint32  Load$$XXX_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$XXX_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$XXX_ENCODE_BIN_CODE$$Length;
extern uint32  Load$$XXX_ENCODE_BIN_DATA$$Base;
extern uint32 Image$$XXX_ENCODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$XXX_ENCODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$XXX_ENCODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$XXX_ENCODE_BIN_DATA$$ZI$$Length;

//WAV ENC
extern uint32  Load$$WAV_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$WAV_ENCODE_BIN_CODE$$Length;
extern uint32  Load$$WAV_ENCODE_BIN_DATA$$Base;
extern uint32 Image$$WAV_ENCODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$WAV_ENCODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$WAV_ENCODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$WAV_ENCODE_BIN_DATA$$ZI$$Length;

//AMR ENC
extern uint32 Load$$AMR_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$AMR_ENCODE_BIN_CODE$$Base;
extern uint32 Image$$AMR_ENCODE_BIN_CODE$$Length;
extern uint32 Load$$AMR_ENCODE_BIN_DATA$$Base;
extern uint32 Image$$AMR_ENCODE_BIN_DATA$$RW$$Base;
extern uint32 Image$$AMR_ENCODE_BIN_DATA$$RW$$Length;
extern uint32 Image$$AMR_ENCODE_BIN_DATA$$ZI$$Base;
extern uint32 Image$$AMR_ENCODE_BIN_DATA$$ZI$$Length;

//FADE SEG
extern uint32 Load$$FADE_MODULE_CODE$$Base;
extern uint32 Image$$FADE_MODULE_CODE$$Base;
extern uint32 Image$$FADE_MODULE_CODE$$Length;
extern uint32 Image$$FADE_MODULE_CODE$$ZI$$Base;
extern uint32 Image$$FADE_MODULE_CODE$$ZI$$Length;

//SHELL CMD NAME
extern uint32 Load$$SHELL_CMD_NAME_DATA$$Base;
extern uint32 Image$$SHELL_CMD_NAME_DATA$$Base;
extern uint32 Image$$SHELL_CMD_NAME_DATA$$Length;
extern uint32 Image$$SHELL_CMD_NAME_DATA$$ZI$$Base;
extern uint32 Image$$SHELL_CMD_NAME_DATA$$ZI$$Length;

//SHELL CMD NAME
extern uint32 Load$$TASK_INF_DATA$$Base;
extern uint32 Image$$TASK_INF_DATA$$Base;
extern uint32 Image$$TASK_INF_DATA$$Length;
extern uint32 Image$$TASK_INF_DATA$$ZI$$Base;
extern uint32 Image$$TASK_INF_DATA$$ZI$$Length;

//FW SHELL
extern uint32 Load$$FW_SHELL_CODE$$Base;
extern uint32 Image$$FW_SHELL_CODE$$Base;
extern uint32 Image$$FW_SHELL_CODE$$Length;
extern uint32 Image$$FW_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$FW_SHELL_CODE$$ZI$$Length;

//GPIO SHELL
extern uint32 Load$$GPIO_SHELL_CODE$$Base;
extern uint32 Image$$GPIO_SHELL_CODE$$Base;
extern uint32 Image$$GPIO_SHELL_CODE$$Length;
extern uint32 Image$$GPIO_SHELL_CODE$$ZI$$Base;
extern uint32 Image$$GPIO_SHELL_CODE$$ZI$$Length;

//IDLE STACK
extern uint32 Image$$IDLE_STACK$$ZI$$Base;
extern uint32 Image$$IDLE_STACK$$ZI$$Length;
extern uint32 Image$$IDLE_STACK$$RW$$Base;
extern uint32 Image$$IDLE_STACK$$RW$$Length;

//AP_MAIN_STACK
extern uint32 Image$$AP_MAIN_STACK$$ZI$$Base;
extern uint32 Image$$AP_MAIN_STACK$$ZI$$Length;
extern uint32 Image$$AP_MAIN_STACK$$RW$$Base;
extern uint32 Image$$AP_MAIN_STACK$$RW$$Length;

//APP HEAP_STACK
extern uint32 Image$$APP_HEAP_STACK$$RW$$Base;
extern uint32 Image$$APP_HEAP_STACK$$RW$$Length;
extern uint32 Image$$APP_HEAP_STACK$$ZI$$Base;
extern uint32 Image$$APP_HEAP_STACK$$ZI$$Length;

// HEAP STACK
extern uint32 Image$$HEAP_STACK$$RW$$Base;
extern uint32 Image$$HEAP_STACK$$RW$$Length;
extern uint32 Image$$HEAP_STACK$$ZI$$Base;
extern uint32 Image$$HEAP_STACK$$ZI$$Length;




/*
--------------------------------------------------------------------------------
  Function name :
  Author        : ZHengYongzhi
  Description   : 模块信息表，生成固件模块头信息，用于代码调度

  History:     <author>         <time>         <version>
             ZhengYongzhi     2008/07/21         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
__attribute__((section("_ModuleInfo_")))
FIRMWARE_INFO_T const ModuleInfo  =
{

    (uint32)(&Load$$MODULE_INFO$$Base),

#ifndef _NOT_USE_SEGMENT_OVERLAY_
    //MODUE_INFO_TABLE
    {
        (uint32)(MAX_SEGMENT_NUM),
        {
            //SYS SEG
            {
                (uint32)(&Load$$AP_SYS_CODE$$Base),
                (uint32)(&Image$$AP_SYS_CODE$$Base),
                (uint32)(&Image$$AP_SYS_CODE$$Length),

                (uint32)(&Load$$AP_SYS_DATA$$Base),
                (uint32)(&Image$$AP_SYS_DATA$$RW$$Base),
                (uint32)(&Image$$AP_SYS_DATA$$RW$$Length),

                (uint32)(&Image$$AP_SYS_DATA$$ZI$$Base),
                (uint32)(&Image$$AP_SYS_DATA$$ZI$$Length),
                "system",
            },

            //INIT SEG
            {
                (uint32)(&Load$$INIT_CODE$$Base),
                (uint32)(&Image$$INIT_CODE$$Base),
                (uint32)(&Image$$INIT_CODE$$Length),

                (uint32)(&Load$$INIT_DATA$$Base),
                (uint32)(&Image$$INIT_DATA$$RW$$Base),
                (uint32)(&Image$$INIT_DATA$$RW$$Length),

                (uint32)(&Image$$INIT_DATA$$ZI$$Base),
                (uint32)(&Image$$INIT_DATA$$ZI$$Length),
                "initial",
            },

            //PMU
            {
                (uint32)(&Load$$PMU_CODE$$Base),
                (uint32)(&Image$$PMU_CODE$$Base) + 0x03090000,
                (uint32)(&Image$$PMU_CODE$$Length),

                (uint32)(&Load$$PMU_DATA$$Base),
                (uint32)(&Image$$PMU_DATA$$RW$$Base) + 0x03090000,
                (uint32)(&Image$$PMU_DATA$$RW$$Length),

                (uint32)(&Image$$PMU_DATA$$ZI$$Base) + 0x03090000,
                (uint32)(&Image$$PMU_DATA$$ZI$$Length),
                "pmu",
            },



            //SYS SUSPEND SEG
            {
                (uint32)(&Load$$SYS_SUSPEND_CODE$$Base),
                (uint32)(&Image$$SYS_SUSPEND_CODE$$Base),
                (uint32)(&Image$$SYS_SUSPEND_CODE$$Length),

                (uint32)(&Load$$SYS_SUSPEND_DATA$$Base),
                (uint32)(&Image$$SYS_SUSPEND_DATA$$RW$$Base),
                (uint32)(&Image$$SYS_SUSPEND_DATA$$RW$$Length),

                (uint32)(&Image$$SYS_SUSPEND_DATA$$ZI$$Base),
                (uint32)(&Image$$SYS_SUSPEND_DATA$$ZI$$Length),
                "sys suspend",
            },


            //SYS RESUME SEG
            {
                (uint32)(&Load$$SYS_RESUME_CODE$$Base),
                (uint32)(&Image$$SYS_RESUME_CODE$$Base),
                (uint32)(&Image$$SYS_RESUME_CODE$$Length),

                (uint32)(&Load$$SYS_RESUME_DATA$$Base),
                (uint32)(&Image$$SYS_RESUME_DATA$$RW$$Base),
                (uint32)(&Image$$SYS_RESUME_DATA$$RW$$Length),

                (uint32)(&Image$$SYS_RESUME_DATA$$ZI$$Base),
                (uint32)(&Image$$SYS_RESUME_DATA$$ZI$$Length),
                "sys resume",
            },

            //LINEIN TASK SEG
            {
                (uint32)(&Load$$LINEIN_TASK_CODE$$Base),
                (uint32)(&Image$$LINEIN_TASK_CODE$$Base),
                (uint32)(&Image$$LINEIN_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LINEIN_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$LINEIN_TASK_CODE$$ZI$$Length),
                "linein task",
            },

            //LINEIN INIT SEG
            {
                (uint32)(&Load$$LINEIN_INIT_CODE$$Base),
                (uint32)(&Image$$LINEIN_INIT_CODE$$Base),
                (uint32)(&Image$$LINEIN_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LINEIN_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$LINEIN_INIT_CODE$$ZI$$Length),
                "linein init",
            },

            //LINEINCONTROL TASK SEG
            {
                (uint32)(&Load$$LINEINCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$LINEINCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$LINEINCONTROL_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LINEINCONTROL_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$LINEINCONTROL_TASK_CODE$$ZI$$Length),
                "linein ctrl",
            },

            //LINEINCONTROL INIT SEG
            {
                (uint32)(&Load$$LINEINCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$LINEINCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$LINEINCONTROL_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LINEINCONTROL_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$LINEINCONTROL_INIT_CODE$$ZI$$Length),
                "linein ctrl init",
            },

            //FMUI TASK SEG
            {
                (uint32)(&Load$$FMUI_TASK_CODE$$Base),
                (uint32)(&Image$$FMUI_TASK_CODE$$Base),
                (uint32)(&Image$$FMUI_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FMUI_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$FMUI_TASK_CODE$$ZI$$Length),
                "fmui task",
            },

            //FMUI INIT SEG
            {
                (uint32)(&Load$$FMUI_INIT_CODE$$Base),
                (uint32)(&Image$$FMUI_INIT_CODE$$Base),
                (uint32)(&Image$$FMUI_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FMUI_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FMUI_INIT_CODE$$ZI$$Length),
                "fmui init",
            },

            //FMCONTROL TASK SEG
            {
                (uint32)(&Load$$FMCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$FMCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$FMCONTROL_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FMCONTROL_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$FMCONTROL_TASK_CODE$$ZI$$Length),
                "fm ctrl",
            },

            //FMCONTROL INIT SEG
            {
                (uint32)(&Load$$FMCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$FMCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$FMCONTROL_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FMCONTROL_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FMCONTROL_INIT_CODE$$ZI$$Length),
                "fm ctrl init",
            },

            //FM DEV SEG
            {
                (uint32)(&Load$$FM_DEV_CODE$$Base),
                (uint32)(&Image$$FM_DEV_CODE$$Base),
                (uint32)(&Image$$FM_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FM_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$FM_DEV_CODE$$ZI$$Length),
                "fm dev",
            },

            //FM INIT SEG
            {
                (uint32)(&Load$$FM_INIT_CODE$$Base),
                (uint32)(&Image$$FM_INIT_CODE$$Base),
                (uint32)(&Image$$FM_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FM_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FM_INIT_CODE$$ZI$$Length),
                "fm init",
            },

            //FM SHELL SEG
            {
                (uint32)(&Load$$FM_SHELL_CODE$$Base),
                (uint32)(&Image$$FM_SHELL_CODE$$Base),
                (uint32)(&Image$$FM_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FM_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$FM_SHELL_CODE$$ZI$$Length),
                "fm shell",
            },
            //BROWSERUI TASK SEG
            {
                (uint32)(&Load$$BROWSERUI_TASK_CODE$$Base),
                (uint32)(&Image$$BROWSERUI_TASK_CODE$$Base),
                (uint32)(&Image$$BROWSERUI_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BROWSERUI_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$BROWSERUI_TASK_CODE$$ZI$$Length),
                "browser task",
            },

            //BROWSERUI INIT SEG
            {
                (uint32)(&Load$$BROWSERUI_INIT_CODE$$Base),
                (uint32)(&Image$$BROWSERUI_INIT_CODE$$Base),
                (uint32)(&Image$$BROWSERUI_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BROWSERUI_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$BROWSERUI_INIT_CODE$$ZI$$Length),
                "browser init",
            },


            //SYSTEMSETWIFISECLECT TASK SEG
            {
                (uint32)(&Load$$SYSTEMSETWIFISELECT_TASK_CODE$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_TASK_CODE$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SYSTEMSETWIFISELECT_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_TASK_CODE$$ZI$$Length),
                "system wifi",
            },

            //SYSTEMSETWIFISECLECT INIT SEG
            {
                (uint32)(&Load$$SYSTEMSETWIFISELECT_INIT_CODE$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_INIT_CODE$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SYSTEMSETWIFISELECT_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SYSTEMSETWIFISELECT_INIT_CODE$$ZI$$Length),
                "system wifi init",

            },

            //SYSTEMSET TASK SEG
            {
                (uint32)(&Load$$SYSTEMSET_TASK_CODE$$Base),
                (uint32)(&Image$$SYSTEMSET_TASK_CODE$$Base),
                (uint32)(&Image$$SYSTEMSET_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SYSTEMSET_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$SYSTEMSET_TASK_CODE$$ZI$$Length),
                "system task",
            },

            //SYSTEMSET INIT SEG
            {
                (uint32)(&Load$$SYSTEMSET_INIT_CODE$$Base),
                (uint32)(&Image$$SYSTEMSET_INIT_CODE$$Base),
                (uint32)(&Image$$SYSTEMSET_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SYSTEMSET_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SYSTEMSET_INIT_CODE$$ZI$$Length),
                "system init",
            },

            //CHARGE TASK SEG
            {
                (uint32)(&Load$$CHARGE_TASK_CODE$$Base),
                (uint32)(&Image$$CHARGE_TASK_CODE$$Base),
                (uint32)(&Image$$CHARGE_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$CHARGE_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$CHARGE_TASK_CODE$$ZI$$Length),
                "charge task",
            },

            //CHARGE INIT SEG
            {
                (uint32)(&Load$$CHARGE_INIT_CODE$$Base),
                (uint32)(&Image$$CHARGE_INIT_CODE$$Base),
                (uint32)(&Image$$CHARGE_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$CHARGE_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$CHARGE_INIT_CODE$$ZI$$Length),
                "charge init",

            },

            //MUSIC PLAY MENU TASK SEG
            {
                (uint32)(&Load$$MUSIC_PLAY_MENU_TASK_CODE$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_TASK_CODE$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MUSIC_PLAY_MENU_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_TASK_CODE$$ZI$$Length),
                "playmenu task",
            },

            //MUSIC PLAY MENU INIT SEG
            {
                (uint32)(&Load$$MUSIC_PLAY_MENU_INIT_CODE$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_INIT_CODE$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MUSIC_PLAY_MENU_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MUSIC_PLAY_MENU_INIT_CODE$$ZI$$Length),
                "playmenu init",
            },

            //RECOD TASK SEG
            {
                (uint32)(&Load$$RECOD_TASK_CODE$$Base),
                (uint32)(&Image$$RECOD_TASK_CODE$$Base),
                (uint32)(&Image$$RECOD_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RECOD_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$RECOD_TASK_CODE$$ZI$$Length),
                "record task",

            },

            //RECOD INIT SEG
            {
                (uint32)(&Load$$RECOD_INIT_CODE$$Base),
                (uint32)(&Image$$RECOD_INIT_CODE$$Base),
                (uint32)(&Image$$RECOD_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RECOD_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$RECOD_INIT_CODE$$ZI$$Length),
                "record init",
            },

            //media update
            {
                (uint32)(&Load$$MEDIA_UPDATE_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_UPDATE_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_UPDATE_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_UPDATE_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_UPDATE_TASK_CODE$$ZI$$Length),
                "media update",
            },

            //file info save
            {
                (uint32)(&Load$$FILE_INFO_SAVE_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$ZI$$Base),
                (uint32)(&Image$$FILE_INFO_SAVE_CODE$$ZI$$Length),
                "fileinfo save",
            },

            //ID3
            {
                (uint32)(&Load$$ID3_DEV_CODE$$Base),
                (uint32)(&Image$$ID3_DEV_CODE$$Base),
                (uint32)(&Image$$ID3_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ID3_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$ID3_DEV_CODE$$ZI$$Length),
                "ide3",
            },

            //file info sort
            {
                (uint32)(&Load$$FILE_INFO_SORT_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_CODE$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILE_INFO_SORT_CODE$$ZI$$Base),
                (uint32)(&Image$$FILE_INFO_SORT_CODE$$ZI$$Length),
                "fileinfo sort",
            },

            //MEDIA LIBRARY CODE SEG
            {
                (uint32)(&Load$$MEDIA_LIBRARY_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_LIBRARY_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_TASK_CODE$$ZI$$Length),
                "media library",
            },

            //MEDIA LIBRARY INIT SEG
            {
                (uint32)(&Load$$MEDIA_LIBRARY_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_LIBRARY_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_LIBRARY_INIT_CODE$$ZI$$Length),
                "mdlibrary init",
            },

            //MEDIA BROWSER CODE SEG
            {
                (uint32)(&Load$$MEDIA_BROWSER_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_BROWSER_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_TASK_CODE$$ZI$$Length),
                "media browser",
            },

            //MEDIA BROWSER INIT SEG
            {
                (uint32)(&Load$$MEDIA_BROWSER_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_BROWSER_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_BROWSER_INIT_CODE$$ZI$$Length),
                "mdbrowser init",
            },

            //USBSERVICE TASK SEG
            {
                (uint32)(&Load$$USBSERVICE_TASK_CODE$$Base),
                (uint32)(&Image$$USBSERVICE_TASK_CODE$$Base),
                (uint32)(&Image$$USBSERVICE_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBSERVICE_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$USBSERVICE_TASK_CODE$$ZI$$Length),
                "usb service",

            },

            //USBSERVICE INIT SEG
            {
                (uint32)(&Load$$USBSERVICE_INIT_CODE$$Base),
                (uint32)(&Image$$USBSERVICE_INIT_CODE$$Base),
                (uint32)(&Image$$USBSERVICE_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBSERVICE_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$USBSERVICE_INIT_CODE$$ZI$$Length),
                "usb service init",

            },

            //MAIN TASK SEG
            {
                (uint32)(&Load$$MAIN_TASK_CODE$$Base),
                (uint32)(&Image$$MAIN_TASK_CODE$$Base),
                (uint32)(&Image$$MAIN_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAIN_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MAIN_TASK_CODE$$ZI$$Length),
                "main task",

            },


            //MAIN MENU SEG
            {
                (uint32)(&Load$$MAIN_MENU_CODE$$Base),
                (uint32)(&Image$$MAIN_MENU_CODE$$Base),
                (uint32)(&Image$$MAIN_MENU_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAIN_MENU_CODE$$ZI$$Base),
                (uint32)(&Image$$MAIN_MENU_CODE$$ZI$$Length),
                "main menu",
            },

            //MAIN INIT SEG
            {
                (uint32)(&Load$$MAIN_INIT_CODE$$Base),
                (uint32)(&Image$$MAIN_INIT_CODE$$Base),
                (uint32)(&Image$$MAIN_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAIN_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MAIN_INIT_CODE$$ZI$$Length),
                "main task init"
            },

            //RECORD SHELL SEG
            {//chad.ma add
                (uint32)(&Load$$RECORD_SHELL_CODE$$Base),
                (uint32)(&Image$$RECORD_SHELL_CODE$$Base),
                (uint32)(&Image$$RECORD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RECORD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$RECORD_SHELL_CODE$$ZI$$Length),
                "record shell",
            },

            //MUSIC SHELL SEG
            {
                (uint32)(&Load$$MUSIC_SHELL_CODE$$Base),
                (uint32)(&Image$$MUSIC_SHELL_CODE$$Base),
                (uint32)(&Image$$MUSIC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MUSIC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$MUSIC_SHELL_CODE$$ZI$$Length),
                "music shell",

            },

            //EFFECT MODULE SEG
            {
                (uint32)(&Load$$EFFECT_MODULE_CODE$$Base),
                (uint32)(&Image$$EFFECT_MODULE_CODE$$Base),
                (uint32)(&Image$$EFFECT_MODULE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$EFFECT_MODULE_CODE$$ZI$$Base),
                (uint32)(&Image$$EFFECT_MODULE_CODE$$ZI$$Length),
                "effect",

            },

            //TIMER DEV SEG
            {
                (uint32)(&Load$$TIMER_DEV_CODE$$Base),
                (uint32)(&Image$$TIMER_DEV_CODE$$Base),
                (uint32)(&Image$$TIMER_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$TIMER_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$TIMER_DEV_CODE$$ZI$$Length),
                "timer dev",

            },

            //TIMER INIT SEG
            {
                (uint32)(&Load$$TIMER_INIT_CODE$$Base),
                (uint32)(&Image$$TIMER_INIT_CODE$$Base),
                (uint32)(&Image$$TIMER_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$TIMER_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$TIMER_INIT_CODE$$ZI$$Length),
                "timer init",
            },

            //TIMER SHELL SEG
            {
                (uint32)(&Load$$TIMER_SHELL_CODE$$Base),
                (uint32)(&Image$$TIMER_SHELL_CODE$$Base),
                (uint32)(&Image$$TIMER_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$TIMER_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$TIMER_SHELL_CODE$$ZI$$Length),
                "timer shell",

            },

            //ADC DEV SEG
            {
                (uint32)(&Load$$ADC_DEV_CODE$$Base),
                (uint32)(&Image$$ADC_DEV_CODE$$Base),
                (uint32)(&Image$$ADC_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ADC_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$ADC_DEV_CODE$$ZI$$Length),
                "adc dev",

            },

            //ADC INIT SEG
            {
                (uint32)(&Load$$ADC_INIT_CODE$$Base),
                (uint32)(&Image$$ADC_INIT_CODE$$Base),
                (uint32)(&Image$$ADC_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ADC_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$ADC_INIT_CODE$$ZI$$Length),
                "adc init",
            },

            //ADC SHELL SEG
            {
                (uint32)(&Load$$ADC_SHELL_CODE$$Base),
                (uint32)(&Image$$ADC_SHELL_CODE$$Base),
                (uint32)(&Image$$ADC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ADC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$ADC_SHELL_CODE$$ZI$$Length),
                "adc shell",
            },

            //KEY DEV SEG
            {
                (uint32)(&Load$$KEY_DEV_CODE$$Base),
                (uint32)(&Image$$KEY_DEV_CODE$$Base),
                (uint32)(&Image$$KEY_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$KEY_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$KEY_DEV_CODE$$ZI$$Length),
                "key dev",
            },

            //KEY INIT SEG
            {
                (uint32)(&Load$$KEY_INIT_CODE$$Base),
                (uint32)(&Image$$KEY_INIT_CODE$$Base),
                (uint32)(&Image$$KEY_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$KEY_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$KEY_INIT_CODE$$ZI$$Length),
                "key init",
            },

            //KEY SHELL SEG
            {
                (uint32)(&Load$$KEY_SHELL_CODE$$Base),
                (uint32)(&Image$$KEY_SHELL_CODE$$Base),
                (uint32)(&Image$$KEY_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$KEY_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$KEY_SHELL_CODE$$ZI$$Length),
                "key shell",
            },

            //PWM DEV SEG
            {
                (uint32)(&Load$$PWM_DEV_CODE$$Base),
                (uint32)(&Image$$PWM_DEV_CODE$$Base),
                (uint32)(&Image$$PWM_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PWM_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$PWM_DEV_CODE$$ZI$$Length),
                "pwm dev",
            },

            //PWM INIT SEG
            {
                (uint32)(&Load$$PWM_INIT_CODE$$Base),
                (uint32)(&Image$$PWM_INIT_CODE$$Base),
                (uint32)(&Image$$PWM_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PWM_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$PWM_INIT_CODE$$ZI$$Length),
                "pwm init",
            },

            //PWM SHELL SEG
            {
                (uint32)(&Load$$PWM_SHELL_CODE$$Base),
                (uint32)(&Image$$PWM_SHELL_CODE$$Base),
                (uint32)(&Image$$PWM_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PWM_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$PWM_SHELL_CODE$$ZI$$Length),
                "pwm shell",
            },

            //VOP DEV SEG
            {
                (uint32)(&Load$$VOP_DEV_CODE$$Base),
                (uint32)(&Image$$VOP_DEV_CODE$$Base),
                (uint32)(&Image$$VOP_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$VOP_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$VOP_DEV_CODE$$ZI$$Length),
                "vop dev",

            },

            //VOP INIT SEG
            {
                (uint32)(&Load$$VOP_INIT_CODE$$Base),
                (uint32)(&Image$$VOP_INIT_CODE$$Base),
                (uint32)(&Image$$VOP_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$VOP_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$VOP_INIT_CODE$$ZI$$Length),
                "vop init",

            },

            //VOP SHELL SEG
            {
                (uint32)(&Load$$VOP_SHELL_CODE$$Base),
                (uint32)(&Image$$VOP_SHELL_CODE$$Base),
                (uint32)(&Image$$VOP_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$VOP_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$VOP_SHELL_CODE$$ZI$$Length),
                "vop shell",

            },

            //LCD DEV SEG
            {
                (uint32)(&Load$$LCD_DEV_CODE$$Base),
                (uint32)(&Image$$LCD_DEV_CODE$$Base),
                (uint32)(&Image$$LCD_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LCD_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$LCD_DEV_CODE$$ZI$$Length),
                "lcd dev",

            },

            //LCD INIT SEG
            {
                (uint32)(&Load$$LCD_INIT_CODE$$Base),
                (uint32)(&Image$$LCD_INIT_CODE$$Base),
                (uint32)(&Image$$LCD_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LCD_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$LCD_INIT_CODE$$ZI$$Length),
                "lcd init",
            },

            //LCD SHELL SEG
            {
                (uint32)(&Load$$LCD_SHELL_CODE$$Base),
                (uint32)(&Image$$LCD_SHELL_CODE$$Base),
                (uint32)(&Image$$LCD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LCD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$LCD_SHELL_CODE$$ZI$$Length),
                "lcd shell",
            },

            //DISPLAY DEV SEG
            {
                (uint32)(&Load$$DISPLAY_DEV_CODE$$Base),
                (uint32)(&Image$$DISPLAY_DEV_CODE$$Base),
                (uint32)(&Image$$DISPLAY_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DISPLAY_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$DISPLAY_DEV_CODE$$ZI$$Length),
                "display dev",

            },

            //DISPLAY INIT SEG
            {
                (uint32)(&Load$$DISPLAY_INIT_CODE$$Base),
                (uint32)(&Image$$DISPLAY_INIT_CODE$$Base),
                (uint32)(&Image$$DISPLAY_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DISPLAY_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$DISPLAY_INIT_CODE$$ZI$$Length),
                "display init",

            },

            //DISPLAY SHELL SEG
            {
                (uint32)(&Load$$DISPLAY_SHELL_CODE$$Base),
                (uint32)(&Image$$DISPLAY_SHELL_CODE$$Base),
                (uint32)(&Image$$DISPLAY_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DISPLAY_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$DISPLAY_SHELL_CODE$$ZI$$Length),
                "display shell",

            },

            //GUI TASK SEG
            {
                (uint32)(&Load$$GUI_TASK_CODE$$Base),
                (uint32)(&Image$$GUI_TASK_CODE$$Base),
                (uint32)(&Image$$GUI_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$GUI_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$GUI_TASK_CODE$$ZI$$Length),
                "gui task",
            },

            //GUI INIT SEG
            {
                (uint32)(&Load$$GUI_INIT_CODE$$Base),
                (uint32)(&Image$$GUI_INIT_CODE$$Base),
                (uint32)(&Image$$GUI_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$GUI_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$GUI_INIT_CODE$$ZI$$Length),
                "gui init",
            },

            //GUI Shell SEG
            {
                (uint32)(&Load$$GUI_SHELL_CODE$$Base),
                (uint32)(&Image$$GUI_SHELL_CODE$$Base),
                (uint32)(&Image$$GUI_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$GUI_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$GUI_SHELL_CODE$$ZI$$Length),
                "gui shell"
            },

            //BCORE DEV SEG
            {
                (uint32)(&Load$$BCORE_DEV_CODE$$Base),
                (uint32)(&Image$$BCORE_DEV_CODE$$Base),
                (uint32)(&Image$$BCORE_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BCORE_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$BCORE_DEV_CODE$$ZI$$Length),
                "bcore dev",
            },

            //BCORE INIT SEG
            {
                (uint32)(&Load$$BCORE_INIT_CODE$$Base),
                (uint32)(&Image$$BCORE_INIT_CODE$$Base),
                (uint32)(&Image$$BCORE_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BCORE_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$BCORE_INIT_CODE$$ZI$$Length),
                "bcore init",
            },

            //BCORE SHELL SEG
            {
                (uint32)(&Load$$BCORE_SHELL_CODE$$Base),
                (uint32)(&Image$$BCORE_SHELL_CODE$$Base),
                (uint32)(&Image$$BCORE_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BCORE_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$BCORE_SHELL_CODE$$ZI$$Length),
                "bcore shell",
            },

            //MSG DEV SEG
            {
                (uint32)(&Load$$MSG_DEV_CODE$$Base),
                (uint32)(&Image$$MSG_DEV_CODE$$Base),
                (uint32)(&Image$$MSG_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MSG_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$MSG_DEV_CODE$$ZI$$Length),
                "msg dev",
            },

            //MSG INIT SEG
            {
                (uint32)(&Load$$MSG_INIT_CODE$$Base),
                (uint32)(&Image$$MSG_INIT_CODE$$Base),
                (uint32)(&Image$$MSG_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MSG_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MSG_INIT_CODE$$ZI$$Length),
                "msg init",
            },

            //MSG SHELL SEG
            {
                (uint32)(&Load$$MSG_SHELL_CODE$$Base),
                (uint32)(&Image$$MSG_SHELL_CODE$$Base),
                (uint32)(&Image$$MSG_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MSG_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$MSG_SHELL_CODE$$ZI$$Length),
                "msg shell",
            },

            //DIR DEV SEG
            {
                (uint32)(&Load$$DIR_DEV_CODE$$Base),
                (uint32)(&Image$$DIR_DEV_CODE$$Base),
                (uint32)(&Image$$DIR_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DIR_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$DIR_DEV_CODE$$ZI$$Length),
                "dir dev",
            },

            //DIR INIT SEG
            {
                (uint32)(&Load$$DIR_INIT_CODE$$Base),
                (uint32)(&Image$$DIR_INIT_CODE$$Base),
                (uint32)(&Image$$DIR_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DIR_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$DIR_INIT_CODE$$ZI$$Length),
                "dir init",

            },

            //DIR SHELL SEG
            {
                (uint32)(&Load$$DIR_SHELL_CODE$$Base),
                (uint32)(&Image$$DIR_SHELL_CODE$$Base),
                (uint32)(&Image$$DIR_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DIR_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$DIR_SHELL_CODE$$ZI$$Length),
                "dir shell"
            },

            //FILESTREAM TASK SEG
            {
                (uint32)(&Load$$FILESTREAM_TASK_CODE$$Base),
                (uint32)(&Image$$FILESTREAM_TASK_CODE$$Base),
                (uint32)(&Image$$FILESTREAM_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILESTREAM_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$FILESTREAM_TASK_CODE$$ZI$$Length),
                "file stream",
            },

            //FILESTREAM INIT SEG
            {
                (uint32)(&Load$$FILESTREAM_INIT_CODE$$Base),
                (uint32)(&Image$$FILESTREAM_INIT_CODE$$Base),
                (uint32)(&Image$$FILESTREAM_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILESTREAM_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FILESTREAM_INIT_CODE$$ZI$$Length),
                "file stream init",

            },

            //HTTP TASK SEG
            {
                (uint32)(&Load$$HTTP_TASK_CODE$$Base),
                (uint32)(&Image$$HTTP_TASK_CODE$$Base),
                (uint32)(&Image$$HTTP_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$HTTP_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$HTTP_TASK_CODE$$ZI$$Length),
                "http task",
            },

            //HTTP INIT SEG
            {
                (uint32)(&Load$$HTTP_INIT_CODE$$Base),
                (uint32)(&Image$$HTTP_INIT_CODE$$Base),
                (uint32)(&Image$$HTTP_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$HTTP_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$HTTP_INIT_CODE$$ZI$$Length),
                "http init",

            },


            //MEDIA TASK SEG
            {
                (uint32)(&Load$$MEDIA_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_TASK_CODE$$Base),
                (uint32)(&Image$$MEDIA_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_TASK_CODE$$ZI$$Length),
                "media task",
            },

            //MEDIA INIT SEG
            {
                (uint32)(&Load$$MEDIA_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_INIT_CODE$$Base),
                (uint32)(&Image$$MEDIA_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MEDIA_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MEDIA_INIT_CODE$$ZI$$Length),
                "media init",

            },

            //STREAMCONTROL TASK SEG
            {
                (uint32)(&Load$$STREAMCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$STREAMCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$STREAMCONTROL_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$STREAMCONTROL_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$STREAMCONTROL_TASK_CODE$$ZI$$Length),
                "stream task",

            },

            //STREAMCONTROL INIT SEG
            {
                (uint32)(&Load$$STREAMCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$STREAMCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$STREAMCONTROL_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$STREAMCONTROL_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$STREAMCONTROL_INIT_CODE$$ZI$$Length),
                "stream init",

            },


            //AUDIOCONTROL TASK SEG
            {
                (uint32)(&Load$$AUDIOCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOCONTROL_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOCONTROL_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOCONTROL_TASK_CODE$$ZI$$Length),
                "audio control",
            },

            //AUDIOCONTROL INIT SEG
            {
                (uint32)(&Load$$AUDIOCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOCONTROL_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOCONTROL_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOCONTROL_INIT_CODE$$ZI$$Length),
                "audio ctrl init",
            },

            //RECORDCONTROL TASK SEG
            {//chad.ma add
                (uint32)(&Load$$RECORDCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$RECORDCONTROL_TASK_CODE$$Base),
                (uint32)(&Image$$RECORDCONTROL_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RECORDCONTROL_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$RECORDCONTROL_TASK_CODE$$ZI$$Length),
                "record ctrl",
            },

            //RECORDCONTROL INIT SEG
            {
                (uint32)(&Load$$RECORDCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$RECORDCONTROL_INIT_CODE$$Base),
                (uint32)(&Image$$RECORDCONTROL_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RECORDCONTROL_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$RECORDCONTROL_INIT_CODE$$ZI$$Length),
                "record ctrl init",
            },

             //chad.ma add
            //ENC ADPCM
            {
                (uint32)(&Load$$WAV_ENCODE_CODE$$Base),
                (uint32)(&Image$$WAV_ENCODE_CODE$$Base),
                (uint32)(&Image$$WAV_ENCODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WAV_ENCODE_CODE$$ZI$$Base),
                (uint32)(&Image$$WAV_ENCODE_CODE$$ZI$$Length),
                "wav encode",
            },

            //ENC AMR
            {
                (uint32)(&Load$$AMR_ENCODE_CODE$$Base),
                (uint32)(&Image$$AMR_ENCODE_CODE$$Base),
                (uint32)(&Image$$AMR_ENCODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AMR_ENCODE_CODE$$ZI$$Base),
                (uint32)(&Image$$AMR_ENCODE_CODE$$ZI$$Length),
                "amr encode",
            },

            //ENC XXX
            {
                (uint32)(&Load$$XXX_ENCODE_CODE$$Base),
                (uint32)(&Image$$XXX_ENCODE_CODE$$Base),
                (uint32)(&Image$$XXX_ENCODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$XXX_ENCODE_CODE$$ZI$$Base),
                (uint32)(&Image$$XXX_ENCODE_CODE$$ZI$$Length),
                "xxx encode",
            },



            //MP3
            {
                (uint32)(&Load$$MP3_DECODE_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MP3_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$MP3_DECODE_CODE$$ZI$$Length),
                "mp3 decode",
            },

            //XXX
            {
                (uint32)(& Load$$XXX_DECODE_CODE$$Base),
                (uint32)(&Image$$XXX_DECODE_CODE$$Base),
                (uint32)(&Image$$XXX_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$XXX_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$XXX_DECODE_CODE$$ZI$$Length),
                "xxx decode",
            },

            //WAV
            {
                (uint32)(&Load$$WAV_DECODE_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WAV_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$WAV_DECODE_CODE$$ZI$$Length),
                "wav decode",
            },

            //AMR
            {
                (uint32)(&Load$$AMR_DECODE_CODE$$Base),
                (uint32)(&Image$$AMR_DECODE_CODE$$Base),
                (uint32)(&Image$$AMR_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AMR_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$AMR_DECODE_CODE$$ZI$$Length),
                "amr decode",
            },

            //FALC
            {
                (uint32)(&Load$$FLAC_DECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_DECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FLAC_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$FLAC_DECODE_CODE$$ZI$$Length),
                "flac decode",

            },

            //AAC
            {
                (uint32)(&Load$$AAC_DECODE_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AAC_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$AAC_DECODE_CODE$$ZI$$Length),
                "aac decode",
            },

            //APE
            {
                (uint32)(&Load$$APE_DECODE_CODE$$Base),
                (uint32)(&Image$$APE_DECODE_CODE$$Base),
                (uint32)(&Image$$APE_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$APE_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$APE_DECODE_CODE$$ZI$$Length),
                "ape decode",
            },

            //OGG
            {
                (uint32)(&Load$$OGG_DECODE_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$OGG_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$OGG_DECODE_CODE$$ZI$$Length),
                "ogg decode",
            },

            //HIFI FLAC
            {
                (uint32)(&Load$$FLAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FLAC_HDECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$FLAC_HDECODE_CODE$$ZI$$Length),
                "hifi flac decode",
            },

            //HIFI ALAC
            {
                (uint32)(&Load$$ALAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ALAC_HDECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$ALAC_HDECODE_CODE$$ZI$$Length),
                "hifi alac decode",
            },

            //HIFI APE
            {
                (uint32)(&Load$$APE_HDECODE_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$APE_HDECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$APE_HDECODE_CODE$$ZI$$Length),
                "hifi ape decode",
            },

            //SBC
            {
                (uint32)(&Load$$SBC_DECODE_CODE$$Base),
                (uint32)(&Image$$SBC_DECODE_CODE$$Base),
                (uint32)(&Image$$SBC_DECODE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SBC_DECODE_CODE$$ZI$$Base),
                (uint32)(&Image$$SBC_DECODE_CODE$$ZI$$Length),
                "sbc decode"

            },

            //aec
            {
                (uint32)(&Load$$AEC_CODE$$Base),
                (uint32)(&Image$$AEC_CODE$$Base),
                (uint32)(&Image$$AEC_CODE$$Length),

                (uint32)(&Load$$AEC_CODE$$RW$$Base),
                (uint32)(&Image$$AEC_CODE$$RW$$Base),
                (uint32)(&Image$$AEC_CODE$$RW$$Length),

                (uint32)(&Image$$AEC_CODE$$ZI$$Base),
                (uint32)(&Image$$AEC_CODE$$ZI$$Length),
                "aec",
            },

            //I2S DEV SEG
            {
                (uint32)(&Load$$I2S_DEV_CODE$$Base),
                (uint32)(&Image$$I2S_DEV_CODE$$Base),
                (uint32)(&Image$$I2S_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2S_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$I2S_DEV_CODE$$ZI$$Length),
                "i2s dev",
            },

            //I2S INIT SEG
            {
                (uint32)(&Load$$I2S_INIT_CODE$$Base),
                (uint32)(&Image$$I2S_INIT_CODE$$Base),
                (uint32)(&Image$$I2S_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2S_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$I2S_INIT_CODE$$ZI$$Length),
                "i2s init",
            },

            //I2S SHELL SEG
            {
                (uint32)(&Load$$I2S_SHELL_CODE$$Base),
                (uint32)(&Image$$I2S_SHELL_CODE$$Base),
                (uint32)(&Image$$I2S_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2S_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$I2S_SHELL_CODE$$ZI$$Length),
                "i2s shell",

            },

            //ROCKCODEC DEV SEG
            {
                (uint32)(&Load$$ROCKCODEC_DEV_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_DEV_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ROCKCODEC_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$ROCKCODEC_DEV_CODE$$ZI$$Length),
                "rockcodec dev",

            },

            //ROCKCODEC INIT SEG
            {
                (uint32)(&Load$$ROCKCODEC_INIT_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_INIT_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ROCKCODEC_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$ROCKCODEC_INIT_CODE$$ZI$$Length),
                "rockcodec init",
            },

            //ROCKCODEC SHELL SEG
            {
                (uint32)(&Load$$ROCKCODEC_SHELL_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_SHELL_CODE$$Base),
                (uint32)(&Image$$ROCKCODEC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$ROCKCODEC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$ROCKCODEC_SHELL_CODE$$ZI$$Length),
                "rockcodec shell",
            },

            //AUDIO DEV SEG
            {
                (uint32)(&Load$$AUDIO_DEV_CODE$$Base),
                (uint32)(&Image$$AUDIO_DEV_CODE$$Base),
                (uint32)(&Image$$AUDIO_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIO_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIO_DEV_CODE$$ZI$$Length),
                "audio dev",
            },

            //AUDIO INIT SEG
            {
                (uint32)(&Load$$AUDIO_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIO_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIO_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIO_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIO_INIT_CODE$$ZI$$Length),
                "audio init"
            },

            //AUDIO SHELL SEG
            {
                (uint32)(&Load$$AUDIO_SHELL_CODE$$Base),
                (uint32)(&Image$$AUDIO_SHELL_CODE$$Base),
                (uint32)(&Image$$AUDIO_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIO_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIO_SHELL_CODE$$ZI$$Length),
                "audio shell",

            },

            //AUDIOSUB TASK SEG
            {
                (uint32)(&Load$$AUDIOSUB_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOSUB_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOSUB_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOSUB_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOSUB_TASK_CODE$$ZI$$Length),
                "audio sub task",
            },

            //AUDIOSUB INIT SEG
            {
                (uint32)(&Load$$AUDIOSUB_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOSUB_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOSUB_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOSUB_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOSUB_INIT_CODE$$ZI$$Length),
                "audio sub init",
            },


            //AUDIOMAIN TASK SEG
            {
                (uint32)(&Load$$AUDIOMAIN_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOMAIN_TASK_CODE$$Base),
                (uint32)(&Image$$AUDIOMAIN_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOMAIN_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOMAIN_TASK_CODE$$ZI$$Length),
                "audio main task",
            },

            //AUDIOMAIN INIT SEG
            {
                (uint32)(&Load$$AUDIOMAIN_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOMAIN_INIT_CODE$$Base),
                (uint32)(&Image$$AUDIOMAIN_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AUDIOMAIN_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$AUDIOMAIN_INIT_CODE$$ZI$$Length),
                "audio main init",
            },

            //USBMSC DEV SEG
            {
                (uint32)(&Load$$USBMSC_DEV_CODE$$Base),
                (uint32)(&Image$$USBMSC_DEV_CODE$$Base),
                (uint32)(&Image$$USBMSC_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBMSC_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$USBMSC_DEV_CODE$$ZI$$Length),
                "usbmsc dev",
            },

            //USBMSC INIT SEG
            {
                (uint32)(&Load$$USBMSC_INIT_CODE$$Base),
                (uint32)(&Image$$USBMSC_INIT_CODE$$Base),
                (uint32)(&Image$$USBMSC_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBMSC_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$USBMSC_INIT_CODE$$ZI$$Length),
                "usbmsc init",
            },

            //USBMSC SHELL SEG
            {
                (uint32)(&Load$$USBMSC_SHELL_CODE$$Base),
                (uint32)(&Image$$USBMSC_SHELL_CODE$$Base),
                (uint32)(&Image$$USBMSC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBMSC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$USBMSC_SHELL_CODE$$ZI$$Length),
                "usbmsc shell",
            },

            //MAILBOX DEV SEG
            {
                (uint32)(&Load$$MAILBOX_DEV_CODE$$Base),
                (uint32)(&Image$$MAILBOX_DEV_CODE$$Base),
                (uint32)(&Image$$MAILBOX_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAILBOX_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$MAILBOX_DEV_CODE$$ZI$$Length),
                "mailbox dev",
            },

            //MAILBOX INIT SEG
            {
                (uint32)(&Load$$MAILBOX_INIT_CODE$$Base),
                (uint32)(&Image$$MAILBOX_INIT_CODE$$Base),
                (uint32)(&Image$$MAILBOX_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAILBOX_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$MAILBOX_INIT_CODE$$ZI$$Length),
                "mailbox init",
            },

            //MAILBOX SHELL SEG
            {
                (uint32)(&Load$$MAILBOX_SHELL_CODE$$Base),
                (uint32)(&Image$$MAILBOX_SHELL_CODE$$Base),
                (uint32)(&Image$$MAILBOX_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MAILBOX_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$MAILBOX_SHELL_CODE$$ZI$$Length),
                "mailbox shell",
            },

            //RK618 DEV SEG
            {
                (uint32)(&Load$$RK618_DEV_CODE$$Base),
                (uint32)(&Image$$RK618_DEV_CODE$$Base),
                (uint32)(&Image$$RK618_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RK618_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$RK618_DEV_CODE$$ZI$$Length),
                "RK618 dev",
            },

            //RK618 INIT SEG
            {
                (uint32)(&Load$$RK618_INIT_CODE$$Base),
                (uint32)(&Image$$RK618_INIT_CODE$$Base),
                (uint32)(&Image$$RK618_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RK618_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$RK618_INIT_CODE$$ZI$$Length),
                "rk618 init",

            },

            //RK618 SHELL SEG
            {
                (uint32)(&Load$$RK618_SHELL_CODE$$Base),
                (uint32)(&Image$$RK618_SHELL_CODE$$Base),
                (uint32)(&Image$$RK618_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$RK618_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$RK618_SHELL_CODE$$ZI$$Length),
                "rk618 shell",
            },


            //FIFO DEV SEG
            {
                (uint32)(&Load$$FIFO_DEV_CODE$$Base),
                (uint32)(&Image$$FIFO_DEV_CODE$$Base),
                (uint32)(&Image$$FIFO_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FIFO_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$FIFO_DEV_CODE$$ZI$$Length),
                "fifo dev",
            },

            //FIFO INIT SEG
            {
                (uint32)(&Load$$FIFO_INIT_CODE$$Base),
                (uint32)(&Image$$FIFO_INIT_CODE$$Base),
                (uint32)(&Image$$FIFO_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FIFO_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FIFO_INIT_CODE$$ZI$$Length),
                "fifo init",
            },

            //FIFO SHELL SEG
            {
                (uint32)(&Load$$FIFO_SHELL_CODE$$Base),
                (uint32)(&Image$$FIFO_SHELL_CODE$$Base),
                (uint32)(&Image$$FIFO_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FIFO_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$FIFO_SHELL_CODE$$ZI$$Length),
                "fifo shell",
            },

            //SD DEV SEG
            {
                (uint32)(&Load$$SD_DEV_CODE$$Base),
                (uint32)(&Image$$SD_DEV_CODE$$Base),
                (uint32)(&Image$$SD_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SD_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SD_DEV_CODE$$ZI$$Length),
                "sd dev",
            },

            //SD INIT SEG
            {
                (uint32)(&Load$$SD_INIT_CODE$$Base),
                (uint32)(&Image$$SD_INIT_CODE$$Base),
                (uint32)(&Image$$SD_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SD_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SD_INIT_CODE$$ZI$$Length),
                "sd init",
            },

            //SD SHELL SEG
            {
                (uint32)(&Load$$SD_SHELL_CODE$$Base),
                (uint32)(&Image$$SD_SHELL_CODE$$Base),
                (uint32)(&Image$$SD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SD_SHELL_CODE$$ZI$$Length),
                "sd shell",
            },

            //I2C DEV SEG
            {
                (uint32)(&Load$$I2C_DEV_CODE$$Base),
                (uint32)(&Image$$I2C_DEV_CODE$$Base),
                (uint32)(&Image$$I2C_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2C_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$I2C_DEV_CODE$$ZI$$Length),
                "i2c dev",
            },

            //I2C INIT SEG
            {
                (uint32)(&Load$$I2C_INIT_CODE$$Base),
                (uint32)(&Image$$I2C_INIT_CODE$$Base),
                (uint32)(&Image$$I2C_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2C_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$I2C_INIT_CODE$$ZI$$Length),
                "i2c init",
            },

            //I2C SHELL SEG
            {
                (uint32)(&Load$$I2C_SHELL_CODE$$Base),
                (uint32)(&Image$$I2C_SHELL_CODE$$Base),
                (uint32)(&Image$$I2C_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I2C_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$I2C_SHELL_CODE$$ZI$$Length),
                "i2c shell",
            },

            //USBOTG DEV SEG
            {
                (uint32)(&Load$$USBOTG_DEV_CODE$$Base),
                (uint32)(&Image$$USBOTG_DEV_CODE$$Base),
                (uint32)(&Image$$USBOTG_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBOTG_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$USBOTG_DEV_CODE$$ZI$$Length),
                "usbotg dev",
            },

            //USBOTG INIT SEG
            {
                (uint32)(&Load$$USBOTG_INIT_CODE$$Base),
                (uint32)(&Image$$USBOTG_INIT_CODE$$Base),
                (uint32)(&Image$$USBOTG_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBOTG_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$USBOTG_INIT_CODE$$ZI$$Length),
                "usbotg init",
            },

            //USBOTG SHELL SEG
            {
                (uint32)(&Load$$USBOTG_SHELL_CODE$$Base),
                (uint32)(&Image$$USBOTG_SHELL_CODE$$Base),
                (uint32)(&Image$$USBOTG_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$USBOTG_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$USBOTG_SHELL_CODE$$ZI$$Length),
                "usbotg shell",
            },

            //SDC DEV SEG
            {
                (uint32)(&Load$$SDC_DEV_CODE$$Base),
                (uint32)(&Image$$SDC_DEV_CODE$$Base),
                (uint32)(&Image$$SDC_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDC_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SDC_DEV_CODE$$ZI$$Length),
                "sdc dev",
            },


            //SDC INIT SEG
            {
                (uint32)(&Load$$SDC_INIT_CODE$$Base),
                (uint32)(&Image$$SDC_INIT_CODE$$Base),
                (uint32)(&Image$$SDC_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDC_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SDC_INIT_CODE$$ZI$$Length),
                "sdc init",

            },


            //SDC SHELL SEG
            {
                (uint32)(&Load$$SDC_SHELL_CODE$$Base),
                (uint32)(&Image$$SDC_SHELL_CODE$$Base),
                (uint32)(&Image$$SDC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SDC_SHELL_CODE$$ZI$$Length),
                "sdc shell",
            },

            //DMA SHELL SEG
            {
                (uint32)(&Load$$DMA_SHELL_CODE$$Base),
                (uint32)(&Image$$DMA_SHELL_CODE$$Base),
                (uint32)(&Image$$DMA_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DMA_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$DMA_SHELL_CODE$$ZI$$Length),
                "dma shell",
            },


            //EMMC DEV SEG
            {
                (uint32)(&Load$$EMMC_DEV_CODE$$Base),
                (uint32)(&Image$$EMMC_DEV_CODE$$Base),
                (uint32)(&Image$$EMMC_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$EMMC_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$EMMC_DEV_CODE$$ZI$$Length),
                "emmc dev",
            },


            //EMMC INIT SEG
            {
                (uint32)(&Load$$EMMC_INIT_CODE$$Base),
                (uint32)(&Image$$EMMC_INIT_CODE$$Base),
                (uint32)(&Image$$EMMC_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$EMMC_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$EMMC_INIT_CODE$$ZI$$Length),
                "emmc init",
            },


            //EMMC SHELL SEG
            {
                (uint32)(&Load$$EMMC_SHELL_CODE$$Base),
                (uint32)(&Image$$EMMC_SHELL_CODE$$Base),
                (uint32)(&Image$$EMMC_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$EMMC_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$EMMC_SHELL_CODE$$ZI$$Length),
                "emmc shell",
            },


            //LUN DEV SEG
            {
                (uint32)(&Load$$LUN_DEV_CODE$$Base),
                (uint32)(&Image$$LUN_DEV_CODE$$Base),
                (uint32)(&Image$$LUN_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LUN_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$LUN_DEV_CODE$$ZI$$Length),
                "lun dev",
            },

            //LUN INIT SEG
            {
                (uint32)(&Load$$LUN_INIT_CODE$$Base),
                (uint32)(&Image$$LUN_INIT_CODE$$Base),
                (uint32)(&Image$$LUN_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LUN_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$LUN_INIT_CODE$$ZI$$Length),
                "lun init",
            },


            //LUN SHELL SEG
            {
                (uint32)(&Load$$LUN_SHELL_CODE$$Base),
                (uint32)(&Image$$LUN_SHELL_CODE$$Base),
                (uint32)(&Image$$LUN_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$LUN_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$LUN_SHELL_CODE$$ZI$$Length),
                "lun shell",
            },


            //PAR DEV SEG
            {
                (uint32)(&Load$$PAR_DEV_CODE$$Base),
                (uint32)(&Image$$PAR_DEV_CODE$$Base),
                (uint32)(&Image$$PAR_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PAR_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$PAR_DEV_CODE$$ZI$$Length),
                "par dev",
            },


            //PAR INIT SEG
            {
                (uint32)(&Load$$PAR_INIT_CODE$$Base),
                (uint32)(&Image$$PAR_INIT_CODE$$Base),
                (uint32)(&Image$$PAR_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PAR_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$PAR_INIT_CODE$$ZI$$Length),
                "par init",
            },


            //PAR SHELL SEG
            {
                (uint32)(&Load$$PAR_SHELL_CODE$$Base),
                (uint32)(&Image$$PAR_SHELL_CODE$$Base),
                (uint32)(&Image$$PAR_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PAR_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$PAR_SHELL_CODE$$ZI$$Length),
                "par shell",
            },


            //FAT DEV SEG
            {
                (uint32)(&Load$$FAT_DEV_CODE$$Base),
                (uint32)(&Image$$FAT_DEV_CODE$$Base),
                (uint32)(&Image$$FAT_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FAT_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$FAT_DEV_CODE$$ZI$$Length),
                "fat dev",
            },


            //FAT INIT SEG
            {
                (uint32)(&Load$$FAT_INIT_CODE$$Base),
                (uint32)(&Image$$FAT_INIT_CODE$$Base),
                (uint32)(&Image$$FAT_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FAT_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FAT_INIT_CODE$$ZI$$Length),
                "fat init",

            },


            //FAT SHELL SEG
            {
                (uint32)(&Load$$FAT_SHELL_CODE$$Base),
                (uint32)(&Image$$FAT_SHELL_CODE$$Base),
                (uint32)(&Image$$FAT_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FAT_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$FAT_SHELL_CODE$$ZI$$Length),
                "fat shell",
            },

            //FILE DEV SEG
            {
                (uint32)(&Load$$FILE_DEV_CODE$$Base),
                (uint32)(&Image$$FILE_DEV_CODE$$Base),
                (uint32)(&Image$$FILE_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILE_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$FILE_DEV_CODE$$ZI$$Length),
                "file dev",
            },


            //FILE INIT SEG
            {
                (uint32)(&Load$$FILE_INIT_CODE$$Base),
                (uint32)(&Image$$FILE_INIT_CODE$$Base),
                (uint32)(&Image$$FILE_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILE_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$FILE_INIT_CODE$$ZI$$Length),
                "file init",
            },


            //FILE SHELL SEG
            {
                (uint32)(&Load$$FILE_SHELL_CODE$$Base),
                (uint32)(&Image$$FILE_SHELL_CODE$$Base),
                (uint32)(&Image$$FILE_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FILE_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$FILE_SHELL_CODE$$ZI$$Length),
                "file shell",

            },

            //SDIO DEV SEG
            {
                (uint32)(&Load$$SDIO_DEV_CODE$$Base),
                (uint32)(&Image$$SDIO_DEV_CODE$$Base),
                (uint32)(&Image$$SDIO_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDIO_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SDIO_DEV_CODE$$ZI$$Length),
                "sdio dev",
            },


            //SDIO INIT SEG
            {
                (uint32)(&Load$$SDIO_INIT_CODE$$Base),
                (uint32)(&Image$$SDIO_INIT_CODE$$Base),
                (uint32)(&Image$$SDIO_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDIO_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SDIO_INIT_CODE$$ZI$$Length),
                "sdio init",
            },


            //SDIO SHELL SEG
            {
                (uint32)(&Load$$SDIO_SHELL_CODE$$Base),
                (uint32)(&Image$$SDIO_SHELL_CODE$$Base),
                (uint32)(&Image$$SDIO_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SDIO_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SDIO_SHELL_CODE$$ZI$$Length),
                "sdio shell",
            },

            //UART DEV SEG
            {
                (uint32)(&Load$$UART_DEV_CODE$$Base),
                (uint32)(&Image$$UART_DEV_CODE$$Base),
                (uint32)(&Image$$UART_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$UART_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$UART_DEV_CODE$$ZI$$Length),
                "uart dev",
            },


            //UART INIT SEG
            {
                (uint32)(&Load$$UART_INIT_CODE$$Base),
                (uint32)(&Image$$UART_INIT_CODE$$Base),
                (uint32)(&Image$$UART_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$UART_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$UART_INIT_CODE$$ZI$$Length),
                "uart init",
            },


            //UART SHELL SEG
            {
                (uint32)(&Load$$UART_SHELL_CODE$$Base),
                (uint32)(&Image$$UART_SHELL_CODE$$Base),
                (uint32)(&Image$$UART_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$UART_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$UART_SHELL_CODE$$ZI$$Length),
                "uart shell",

            },


             //WDOG DEV SEG
            {
                (uint32)(&Load$$WDOG_DEV_CODE$$Base),
                (uint32)(&Image$$WDOG_DEV_CODE$$Base),
                (uint32)(&Image$$WDOG_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WDOG_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$WDOG_DEV_CODE$$ZI$$Length),
                "wdog dev",
            },


            //WDOG INIT SEG
            {
                (uint32)(&Load$$WDOG_INIT_CODE$$Base),
                (uint32)(&Image$$WDOG_INIT_CODE$$Base),
                (uint32)(&Image$$WDOG_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WDOG_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$WDOG_INIT_CODE$$ZI$$Length),
                "wdog init",
            },


            //WDOG SHELL SEG
            {
                (uint32)(&Load$$WDOG_SHELL_CODE$$Base),
                (uint32)(&Image$$WDOG_SHELL_CODE$$Base),
                (uint32)(&Image$$WDOG_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WDOG_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$WDOG_SHELL_CODE$$ZI$$Length),
                "wdog shell",

            },


            // INNO wifi dev seg
            {
                (uint32)(&Load$$I6000_DEV_CODE$$Base),
                (uint32)(&Image$$I6000_DEV_CODE$$Base),
                (uint32)(&Image$$I6000_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I6000_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$I6000_DEV_CODE$$ZI$$Length),
                "inno wifi1",
            },

            // INNO wifi dev seg
            {
                (uint32)(&Load$$I6000_DEV_CODE2$$Base),
                (uint32)(&Image$$I6000_DEV_CODE2$$Base),
                (uint32)(&Image$$I6000_DEV_CODE2$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I6000_DEV_CODE2$$ZI$$Base),
                (uint32)(&Image$$I6000_DEV_CODE2$$ZI$$Length),
                "inno wifi2",
            },

            {
                (uint32)(&Load$$I6000_SHELL_CODE$$Base),
                (uint32)(&Image$$I6000_SHELL_CODE$$Base),
                (uint32)(&Image$$I6000_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$I6000_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$I6000_SHELL_CODE$$ZI$$Length),
                "inno wifi shell",
            },
                //ap6181
             {
                (uint32)(&Load$$WIFI_APPLICATIONTASK_INIT_CODE$$Base),
                (uint32)(&Image$$WIFI_APPLICATIONTASK_INIT_CODE$$Base),
                (uint32)(&Image$$WIFI_APPLICATIONTASK_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WIFI_APPLICATIONTASK_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$WIFI_APPLICATIONTASK_INIT_CODE$$ZI$$Length),
                "wifi task init",
            },
            {
                (uint32)(&Load$$WIFIAPP_TASK_CODE$$Base),
                (uint32)(&Image$$WIFIAPP_TASK_CODE$$Base),
                (uint32)(&Image$$WIFIAPP_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$WIFIAPP_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$WIFIAPP_TASK_CODE$$ZI$$Length),
                "wifi task",
            },

            {
                (uint32)(&Load$$AP6181WIFI_INIT_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_INIT_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AP6181WIFI_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$AP6181WIFI_INIT_CODE$$ZI$$Length),
                "wifi init",
            },

            {
                (uint32)(&Load$$AP6181WIFI_DEV_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_DEV_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AP6181WIFI_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$AP6181WIFI_DEV_CODE$$ZI$$Length),
                "wifi dev",
            },

           {
                (uint32)(&Load$$AP6181WIFI_SHELL_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_SHELL_CODE$$Base),
                (uint32)(&Image$$AP6181WIFI_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$AP6181WIFI_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$AP6181WIFI_SHELL_CODE$$ZI$$Length),
                "wifi shell",
            },

            //dlna

             {
                (uint32)(&Load$$DLNA_TASK_INIT_CODE$$Base),
                (uint32)(&Image$$DLNA_TASK_INIT_CODE$$Base),
                (uint32)(&Image$$DLNA_TASK_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DLNA_TASK_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$DLNA_TASK_INIT_CODE$$ZI$$Length),
                "dlna task init",
            },

            {
                (uint32)(&Load$$DLNA_TASK_CODE$$Base),
                (uint32)(&Image$$DLNA_TASK_CODE$$Base),
                (uint32)(&Image$$DLNA_TASK_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DLNA_TASK_CODE$$ZI$$Base),
                (uint32)(&Image$$DLNA_TASK_CODE$$ZI$$Length),
                "dlna task",
            },

            {
                (uint32)(&Load$$DLNA_SHELL_CODE$$Base),
                (uint32)(&Image$$DLNA_SHELL_CODE$$Base),
                (uint32)(&Image$$DLNA_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DLNA_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$DLNA_SHELL_CODE$$ZI$$Length),
                "dlna shell",

            },


            {
                (uint32)(&Load$$DLNA_DEV_CODE$$Base),
                (uint32)(&Image$$DLNA_DEV_CODE$$Base),
                (uint32)(&Image$$DLNA_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DLNA_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$DLNA_DEV_CODE$$ZI$$Length),
                "dlna dev",
            },
            //upnp
            {
                (uint32)(&Load$$UPNP_DEV_CODE$$Base),
                (uint32)(&Image$$UPNP_DEV_CODE$$Base),
                (uint32)(&Image$$UPNP_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$UPNP_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$UPNP_DEV_CODE$$ZI$$Length),
                "upnp",

            },
            {
                (uint32)(&Load$$XMLPARSE_DEV_CODE$$Base),
                (uint32)(&Image$$XMLPARSE_DEV_CODE$$Base),
                (uint32)(&Image$$XMLPARSE_DEV_CODE$$Length),

                 NULL,
                 NULL,
                 NULL,

                (uint32)(&Image$$XMLPARSE_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$XMLPARSE_DEV_CODE$$ZI$$Length),
                "xml parse",

            },
            //XXX
            {
                (uint32)(&Load$$XXX_TASK_INIT_CODE$$Base),
                (uint32)(&Image$$XXX_TASK_INIT_CODE$$Base),
                (uint32)(&Image$$XXX_TASK_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$XXX_TASK_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$XXX_TASK_INIT_CODE$$ZI$$Length),
                "xxx task",
            },

            {
                (uint32)(&Load$$XXX_SHELL_CODE$$Base),
                (uint32)(&Image$$XXX_SHELL_CODE$$Base),
                (uint32)(&Image$$XXX_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$XXX_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$XXX_SHELL_CODE$$ZI$$Length),
                "xxx shell",
            },

            {
                (uint32)(&Load$$XXX_DEV_CODE$$Base),
                (uint32)(&Image$$XXX_DEV_CODE$$Base),
                (uint32)(&Image$$XXX_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$XXX_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$XXX_DEV_CODE$$ZI$$Length),
                "xxx dev",
            },

            {
                (uint32)(&Load$$CHANNELS_SPEAKER_CODE$$Base),
                (uint32)(&Image$$CHANNELS_SPEAKER_CODE$$Base),
                (uint32)(&Image$$CHANNELS_SPEAKER_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$CHANNELS_SPEAKER_CODE$$ZI$$Base),
                (uint32)(&Image$$CHANNELS_SPEAKER_CODE$$ZI$$Length),
                "channel speaker",
            },

            //SSL
            {
                (uint32)(&Load$$SSL_DEV_CODE$$Base),
                (uint32)(&Image$$SSL_DEV_CODE$$Base),
                (uint32)(&Image$$SSL_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SSL_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SSL_DEV_CODE$$ZI$$Length),
                "ssl",
            },

			//SHELL_SWITCH_PLAYER jjjhhh
			/*{
				(uint32)(&Load$$SHELL_SWITCH_PLAYER_CODE$$Base),
				(uint32)(&Image$$SHELL_SWITCH_PLAYER_CODE$$Base),
				(uint32)(&Image$$SHELL_SWITCH_PLAYER_CODE$$Length),
				
				NULL,
				NULL,
				NULL,
				
				(uint32)(&Image$$SHELL_SWITCH_PLAYER_CODE$$ZI$$Base),
				(uint32)(&Image$$SHELL_SWITCH_PLAYER_CODE$$ZI$$Length),
			},*/


            // lwip seg
            {
                (uint32)(&Load$$LWIP_DEV_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)  (&Image$$LWIP_DEV_CODE$$ZI$$Base),
                (uint32) (&Image$$LWIP_DEV_CODE$$ZI$$Length),
                "lwip",
            },
            // lwip api seg
            {
                (uint32)(&Load$$LWIP_DEV_API_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_API_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_API_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)  (&Image$$LWIP_DEV_API_CODE$$ZI$$Base),
                (uint32) (&Image$$LWIP_DEV_API_CODE$$ZI$$Length),
                "lwip api",
            },
            // ping shell seg
            {
                (uint32)(&Load$$PING_SHELL_CODE$$Base),
                (uint32)(&Image$$PING_SHELL_CODE$$Base),
                (uint32)(&Image$$PING_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$PING_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$PING_SHELL_CODE$$ZI$$Length),
                "ping shell",
            },
            // ipconfig shell seg
            {
                (uint32)(&Load$$IPCONFIG_SHELL_CODE$$Base),
                (uint32)(&Image$$IPCONFIG_SHELL_CODE$$Base),
                (uint32)(&Image$$IPCONFIG_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$IPCONFIG_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$IPCONFIG_SHELL_CODE$$ZI$$Length),
                "lwip shell",
            },
            // http seg
            {
                (uint32)(&Load$$LWIP_DEV_HTTP_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$Length),

                (uint32)(&Load$$LWIP_DEV_HTTP_CODE$$RW$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$RW$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$RW$$Length),

                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$ZI$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTP_CODE$$ZI$$Length),
                "http",
            },

            // httpd seg
            {
                (uint32)(&Load$$LWIP_DEV_HTTPD_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTPD_CODE$$Base),
                (uint32)(&Image$$LWIP_DEV_HTTPD_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)  (&Image$$LWIP_DEV_HTTPD_CODE$$ZI$$Base),
                (uint32) (&Image$$LWIP_DEV_HTTPD_CODE$$ZI$$Length),
                "httpd",
            },
            // mbedtls seg
            {
                (uint32)(&Load$$MBEDTLS_DEV_CODE$$Base),
                (uint32)(&Image$$MBEDTLS_DEV_CODE$$Base),
                (uint32)(&Image$$MBEDTLS_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$MBEDTLS_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$MBEDTLS_DEV_CODE$$ZI$$Length),
                "mbedtls",
            },
            {
                (uint32)(&Load$$BLUETOOTH_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BLUETOOTH_CODE$$ZI$$Base),
                (uint32)(&Image$$BLUETOOTH_CODE$$ZI$$Length),
                "bt ctrl",
            },

            {
                (uint32)(&Load$$BLUETOOTH_SHELL_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_SHELL_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BLUETOOTH_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$BLUETOOTH_SHELL_CODE$$ZI$$Length),
                "bt shell",
            },

            {
                (uint32)(&Load$$BLUETOOTH_LWBT_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_LWBT_CODE$$Base),
                (uint32)(&Image$$BLUETOOTH_LWBT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$BLUETOOTH_LWBT_CODE$$ZI$$Base),
                (uint32)(&Image$$BLUETOOTH_LWBT_CODE$$ZI$$Length),
                "lwbt",
            },

            //SPIFLASH SEG MODULE

            {
                (uint32)(&Load$$SPIFLASH_INIT_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_INIT_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPIFLASH_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SPIFLASH_INIT_CODE$$ZI$$Length),
                "spiflash init",
            },

            {
                (uint32)(&Load$$SPIFLASH_DEV_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_DEV_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPIFLASH_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SPIFLASH_DEV_CODE$$ZI$$Length),
                "spiflash dev",
            },

            {
                (uint32)(&Load$$SPIFLASH_SHELL_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$Base),
                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$ZI$$Length),
                "spiflash shell",
            },


            //SPI SEG MODULE
            {
                (uint32)(&Load$$SPI_INIT_CODE$$Base),
                (uint32)(&Image$$SPI_INIT_CODE$$Base),
                (uint32)(&Image$$SPI_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPI_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SPI_INIT_CODE$$ZI$$Length),
                "spi init",
            },

            {
                (uint32)(&Load$$SPI_DEV_CODE$$Base),
                (uint32)(&Image$$SPI_DEV_CODE$$Base),
                (uint32)(&Image$$SPI_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPI_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SPI_DEV_CODE$$ZI$$Length),
                "spi dev",
            },

            {
                (uint32)(&Load$$SPI_SHELL_CODE$$Base),
                (uint32)(&Image$$SPI_SHELL_CODE$$Base),
                (uint32)(&Image$$SPI_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPI_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SPI_SHELL_CODE$$ZI$$Length),
                "spi shell",

            },


            //SPINOR SEG MODULE

            {
                (uint32)(&Load$$SPINOR_INIT_CODE$$Base),
                (uint32)(&Image$$SPINOR_INIT_CODE$$Base),
                (uint32)(&Image$$SPINOR_INIT_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPINOR_INIT_CODE$$ZI$$Base),
                (uint32)(&Image$$SPINOR_INIT_CODE$$ZI$$Length),
                "spinor init",
            },

            {
                (uint32)(&Load$$SPINOR_DEV_CODE$$Base),
                (uint32)(&Image$$SPINOR_DEV_CODE$$Base),
                (uint32)(&Image$$SPINOR_DEV_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPINOR_DEV_CODE$$ZI$$Base),
                (uint32)(&Image$$SPINOR_DEV_CODE$$ZI$$Length),
                "spinor dev",
            },

            {
                (uint32)(&Load$$SPINOR_SHELL_CODE$$Base),
                (uint32)(&Image$$SPINOR_SHELL_CODE$$Base),
                (uint32)(&Image$$SPINOR_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SPIFLASH_SHELL_CODE$$ZI$$Length),
                "spinor shell",
            },

            //WIFI FIRMWAVE ONE
            {
                (uint32)(&Load$$WIFI_FIRMWARE_ONE$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_ONE$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_ONE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "wififirmware one",

            },

            //WIFI FIRMWAVE TWO
            {
                (uint32)(&Load$$WIFI_FIRMWARE_TWO$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_TWO$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_TWO$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "wififirmware two",

            },
            //WIFI FIRMWAVE RKi6000
            {
                (uint32)(&Load$$WIFI_FIRMWARE_RKI6000$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_RKI6000$$Base),
                (uint32)(&Image$$WIFI_FIRMWARE_RKI6000$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "rki600 firmwave",

            },
            //BT FIRMWAVE
            {
                (uint32)(&Load$$BT_FIRMWARE$$Base),
                (uint32)(&Image$$BT_FIRMWARE$$Base),
                (uint32)(&Image$$BT_FIRMWARE$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "bt firmwave",

            },

            //AUDIO EQTABLE
            {
                (uint32)(&Load$$AUDIO_EQ_DATA$$Base),
                (uint32)(&Image$$AUDIO_EQ_DATA$$Base),
                (uint32)(&Image$$AUDIO_EQ_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "audio eqtable",

            },

            //xml
            {
                (uint32)(&Load$$DMR_DEVICE_DATA$$Base),
                (uint32)(&Image$$DMR_DEVICE_DATA$$Base),
                (uint32)(&Image$$DMR_DEVICE_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr device",

            },

            {
                (uint32)(&Load$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_CONNECTIONMANAGER_SERVICE_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr connection",

            },

            {
                (uint32)(&Load$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_RENDERINGCONTROL_SERVICE_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr render",

            },
		#if 1//#ifdef _QPLAY_ENABLE
            {
                (uint32)(&Load$$DMR_QPLAY_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_QPLAY_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_QPLAY_SERVICE_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
				"dmr qplay",
           },
		#endif
           {
                (uint32)(&Load$$DMR_AVTRANSPORT_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_AVTRANSPORT_SERVICE_DATA$$Base),
                (uint32)(&Image$$DMR_AVTRANSPORT_SERVICE_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr avtransport",

            },

            //nametab
            {
                (uint32)(&Load$$DMR_NAMINGBITMAP_DATA$$Base),
                (uint32)(&Image$$DMR_NAMINGBITMAP_DATA$$Base),
                (uint32)(&Image$$DMR_NAMINGBITMAP_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr naming",
            },

            {
                (uint32)(&Load$$DMR_NMSTRTPAGES_DATA$$Base),
                (uint32)(&Image$$DMR_NMSTRTPAGES_DATA$$Base),
                (uint32)(&Image$$DMR_NMSTRTPAGES_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr nmstrtpages",
            },

            {
                (uint32)(&Load$$DMR_NAMEPAGES_DATA$$Base),
                (uint32)(&Image$$DMR_NAMEPAGES_DATA$$Base),
                (uint32)(&Image$$DMR_NAMEPAGES_DATA$$Length),

                NULL,
                NULL,
                NULL,

                NULL,
                NULL,
                "dmr namepages",
            },

            {
                (uint32)(&Load$$SYSCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$SYSCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$SYSCMD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SYSCMD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$SYSCMD_SHELL_CODE$$ZI$$Length),
                "sys cmd",
            },


            {
                (uint32)(&Load$$DEVCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$DEVCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$DEVCMD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$DEVCMD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$DEVCMD_SHELL_CODE$$ZI$$Length),
                "dev cmd",
            },

            {
                (uint32)(&Load$$TASKCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$TASKCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$TASKCMD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$TASKCMD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$TASKCMD_SHELL_CODE$$ZI$$Length),
                "task cmd",
            },

            {
                (uint32)(&Load$$CUSTOMCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$CUSTOMCMD_SHELL_CODE$$Base),
                (uint32)(&Image$$CUSTOMCMD_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$CUSTOMCMD_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$CUSTOMCMD_SHELL_CODE$$ZI$$Length),
                "custom shell",
            },

            //BB Module
            {
                (uint32)(&Load$$BB_SYS_CODE$$Base),
                (uint32)(&Image$$BB_SYS_CODE$$Base),
                (uint32)(&Image$$BB_SYS_CODE$$Length),
                (uint32)(&Load$$BB_SYS_DATA$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$RW$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$RW$$Length),
                (uint32)(&Image$$BB_SYS_DATA$$ZI$$Base),
                (uint32)(&Image$$BB_SYS_DATA$$ZI$$Length),
                "bb system",
            },

            //MP3
            {
                (uint32)(&Load$$MP3_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$MP3_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$MP3_DECODE_BIN_DATA$$ZI$$Length),
                "mp3 decode bin",
            },

            //XXX
            {
                (uint32)(&Load$$XXX_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$XXX_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$XXX_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$XXX_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$XXX_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$XXX_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$XXX_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$XXX_DECODE_BIN_DATA$$ZI$$Length),
                "xxx decode bin",
            },

            //WAV
            {
                (uint32)(&Load$$WAV_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$WAV_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$WAV_DECODE_BIN_DATA$$ZI$$Length),
                "wav decode bin",
            },

            //AMR
            {
                (uint32)(&Load$$AMR_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AMR_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AMR_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$AMR_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$AMR_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$AMR_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$AMR_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$AMR_DECODE_BIN_DATA$$ZI$$Length),
                "amr decode bin",
            },

            //FLAC
            {
                (uint32)(&Load$$FLAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$FLAC_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$FLAC_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$FLAC_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$FLAC_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$FLAC_DECODE_BIN_DATA$$ZI$$Length),
                "flac decode bin",
            },


            //AAC
            {
                (uint32)(&Load$$AAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$AAC_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$AAC_DECODE_BIN_DATA$$ZI$$Length),
                "aac decode bin",
            },

            //APE
            {
                (uint32)(&Load$$APE_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$APE_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$APE_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$APE_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$APE_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$APE_DECODE_BIN_DATA$$ZI$$Length),
                "ape decode bin",
            },

            //OGG
            {
                (uint32)(&Load$$OGG_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$OGG_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$OGG_DECODE_BIN_DATA$$ZI$$Length),
                "ogg decode bin",
            },



            //HIFI FLAC
            {
                (uint32)(&Load$$FLAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_CODE$$Length),
                (uint32)(&Load$$FLAC_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$FLAC_HDECODE_BIN_DATA$$ZI$$Length),
                "hifi flac bin",
            },

            //HIFI ALAC
            {
                (uint32)(&Load$$ALAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_CODE$$Length),
                (uint32)(&Load$$ALAC_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$ALAC_HDECODE_BIN_DATA$$ZI$$Length),
                "hifi alac bin",
            },

            //HIFI APE
            {
                (uint32)(&Load$$APE_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_CODE$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_CODE$$Length),
                (uint32)(&Load$$APE_HDECODE_BIN_DATA$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$APE_HDECODE_BIN_DATA$$ZI$$Length),
                "hifi ape bin",
            },

            //SBC
            {
                (uint32)(&Load$$SBC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$SBC_DECODE_BIN_CODE$$Base),
                (uint32)(&Image$$SBC_DECODE_BIN_CODE$$Length),
                (uint32)(&Load$$SBC_DECODE_BIN_DATA$$Base),
                (uint32)(&Image$$SBC_DECODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$SBC_DECODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$SBC_DECODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$SBC_DECODE_BIN_DATA$$ZI$$Length),
                "sbc decode bin",
            },

            //WAV_ENC
            {//chad.ma add
                (uint32)(&Load$$WAV_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$WAV_ENCODE_BIN_CODE$$Length),
                (uint32)(&Load$$WAV_ENCODE_BIN_DATA$$Base),
                (uint32)(&Image$$WAV_ENCODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$WAV_ENCODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$WAV_ENCODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$WAV_ENCODE_BIN_DATA$$ZI$$Length),
                "wav encode bin",
            },

            //AMR_ENC
            {//cjh add
                (uint32)(&Load$$AMR_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$AMR_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$AMR_ENCODE_BIN_CODE$$Length),
                (uint32)(&Load$$AMR_ENCODE_BIN_DATA$$Base),
                (uint32)(&Image$$AMR_ENCODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$AMR_ENCODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$AMR_ENCODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$AMR_ENCODE_BIN_DATA$$ZI$$Length),
                "amr encode bin",
            },

            //XXX_ENC
            {//chad.ma add
                (uint32)(&Load$$XXX_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$XXX_ENCODE_BIN_CODE$$Base),
                (uint32)(&Image$$XXX_ENCODE_BIN_CODE$$Length),
                (uint32)(&Load$$XXX_ENCODE_BIN_DATA$$Base),
                (uint32)(&Image$$XXX_ENCODE_BIN_DATA$$RW$$Base),
                (uint32)(&Image$$XXX_ENCODE_BIN_DATA$$RW$$Length),
                (uint32)(&Image$$XXX_ENCODE_BIN_DATA$$ZI$$Base),
                (uint32)(&Image$$XXX_ENCODE_BIN_DATA$$ZI$$Length),
                "xxx encode bin",
            },

            //FADE MODULE SEG
            {
                (uint32)(&Load$$FADE_MODULE_CODE$$Base),
                (uint32)(&Image$$FADE_MODULE_CODE$$Base),
                (uint32)(&Image$$FADE_MODULE_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FADE_MODULE_CODE$$ZI$$Base),
                (uint32)(&Image$$FADE_MODULE_CODE$$ZI$$Length),
                "fade module",
            },

            //SHELL CMD NAME SEG
            {
                (uint32)(&Load$$SHELL_CMD_NAME_DATA$$Base),
                (uint32)(&Image$$SHELL_CMD_NAME_DATA$$Base),
                (uint32)(&Image$$SHELL_CMD_NAME_DATA$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$SHELL_CMD_NAME_DATA$$ZI$$Base),
                (uint32)(&Image$$SHELL_CMD_NAME_DATA$$ZI$$Length),
                "cmd help",
            },

            //TASK INF SEG
            {
                (uint32)(&Load$$TASK_INF_DATA$$Base),
                (uint32)(&Image$$TASK_INF_DATA$$Base),
                (uint32)(&Image$$TASK_INF_DATA$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$TASK_INF_DATA$$ZI$$Base),
                (uint32)(&Image$$TASK_INF_DATA$$ZI$$Length),
                "task inf",
            },

            //FW SHELL SEG
            {
                (uint32)(&Load$$FW_SHELL_CODE$$Base),
                (uint32)(&Image$$FW_SHELL_CODE$$Base),
                (uint32)(&Image$$FW_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$FW_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$FW_SHELL_CODE$$ZI$$Length),
                "fw shell",
            },

            //GPIO SHELL SEG
            {
                (uint32)(&Load$$GPIO_SHELL_CODE$$Base),
                (uint32)(&Image$$GPIO_SHELL_CODE$$Base),
                (uint32)(&Image$$GPIO_SHELL_CODE$$Length),

                NULL,
                NULL,
                NULL,

                (uint32)(&Image$$GPIO_SHELL_CODE$$ZI$$Base),
                (uint32)(&Image$$GPIO_SHELL_CODE$$ZI$$Length),
                "gpio shell",
            },


            //STACK1
            {
                NULL,
                (uint32)(&Image$$APP_HEAP_STACK$$RW$$Base),
                (uint32)(&Image$$APP_HEAP_STACK$$RW$$Length),

                NULL,
                (uint32)(&Image$$APP_HEAP_STACK$$ZI$$Base),
                (uint32)(&Image$$APP_HEAP_STACK$$ZI$$Length),

                (uint32)(&Image$$HEAP_STACK$$ZI$$Base),
                (uint32)(&Image$$HEAP_STACK$$ZI$$Length),
                "stack1",
            },


            //STACK2
            {
                NULL,
                (uint32)(&Image$$AP_MAIN_STACK$$RW$$Base),
                (uint32)(&Image$$AP_MAIN_STACK$$RW$$Length),

                NULL,
                (uint32)(&Image$$AP_MAIN_STACK$$ZI$$Base),
                (uint32)(&Image$$AP_MAIN_STACK$$ZI$$Length),

                (uint32)(&Image$$HEAP_STACK$$RW$$Base),
                (uint32)(&Image$$HEAP_STACK$$RW$$Length),
                "stack2",
            },

            //STACK3
            {
                NULL,
                (uint32)(&Image$$IDLE_STACK$$RW$$Base),
                (uint32)(&Image$$IDLE_STACK$$RW$$Length),

                NULL,
                (uint32)(&Image$$IDLE_STACK$$ZI$$Base),
                (uint32)(&Image$$IDLE_STACK$$ZI$$Length),

                NULL,
                NULL,
                "stack3",
            },
        },
    },
#endif
      //系统默认参数
    {
        //系统参数
#ifdef _SDCARD_
        (uint32)1,      //UINT32 SDEnable;
#else
        (uint32)0,
#endif

#ifdef _RADIO_
        (uint32)1,      //UINT32 FMEnable;
#else
        (uint32)1,
#endif

        (uint32)KEY_NUM,//UINT32 KeyNum


        (uint32)2,      //UINT32 Langule;
        (uint32)25,     //UINT32 Volume;

        (uint32)1,      //UINT32 BLMode;
        (uint32)4,      //UINT32 BLevel;
        (uint32)1,      //UINT32 BLtime;

        (uint32)0,      //UINT32 SetPowerOffTime;
        (uint32)0,      //UINT32 IdlePowerOffTime;

        (uint32)0,      //UINT32 AvlsEnabled;
        (uint32)33,      //UINT32 BeepEnabled;
        (uint32)1,      //UINT32 FactoryVolLimit;

        //Music参数
        (uint32)0,      //UINT32 MusicRepMode;
        (uint32)0,      //UINT32 MusicPlayOrder;
        (uint32)0,      //UINT32 MusicBassBoost;
        (uint32)7,      //UINT32 MusicEqSel;
        (uint32)0,      //UINT32 MusicPlayFxSel;

        //Video参数

        //Radio参数
        (uint32)2,      //UINT32 FMArea;
        (uint32)0,      //UINT32 FMStereo;
        (uint32)0,      //UINT32 FMScanSensitivity;

        //Record参数

        //Picture参数
        (uint32)2,      //UINT32 PicAutoPlayTime;

        //Text参数
        (uint32)2,      //UINT32 TextAutoPlayTime;

        //Image ID
        (uint32)0,

        //#ifdef _Vol_Tab_General
        //(uint32)1,      //UINT32 VolumeTableIndex;
        //#else
        //(uint32)0,
        //#endif            //VolumeTableIndex will not be reset when reset default setting - weslly

        //多国语言选择
		#ifdef _USE_GUI_
        (uint32)TOTAL_MENU_ITEM,    //最大菜单项
        (uint32)TOTAL_LANAUAGE_NUM, //uint32 LanguageTotle, 实际最大多国语言个数
		#else
		(uint32)0,
		(uint32)0,
		#endif

        {
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //8
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //16
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //24
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //32
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //40
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //48
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //56
            (uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1,(uint32)1, //64
        },
    }
};
/*
--------------------------------------------------------------------------------
  Function name :
  Author        : ZHengYongzhi
  Description   : 模块信息表

  History:     <author>         <time>         <version>
             ZhengYongzhi     2008/07/21         Ver1.0
  desc:         ORG
--------------------------------------------------------------------------------
*/
__attribute__((section("AP_START_CODE")))
void ScatterLoader(void)
{
    uint32 i,len;
    uint8  *pDest;

    //clear sys bss data
    pDest = (uint8*)((uint32)(&Image$$AP_SYS_DATA$$ZI$$Base));
    len = (uint32)((uint32)(&Image$$AP_SYS_DATA$$ZI$$Length));
    for (i = 0; i < len; i++)
    {
        *pDest++ = 0;
    }
}

__attribute__((section("AP_START_CODE")))
void StartCASystem(void)
{
    uint32 *core2reset;
    uint32 i;
    core2reset = (uint*)0x401808F8;
    *core2reset = 0;

    while (i < 0xffff)
        i++;

    *core2reset |= 0x80;

#if 0
    while (1)
    {
        MailBoxWriteA2BCmd(0,0,0);
        MailBoxWriteA2BData(0,0,0);
        //__WFI();
    }
#endif

}
/*
********************************************************************************
*
*                         End of StartLoadTab.c
*
********************************************************************************
*/
