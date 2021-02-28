/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for BMS*/
/************************************************************************************************************************/


/***************DEFINES section *****************************/
/* Parameters related to battery maintainence check is defined here*/
#define MINTEMP 0
#define MAXTEMP 45
#define MINSOC  20
#define MAXSOC  80
#define MAXCHGRATE 0.8

enum BatteryParam {TEMP, SOC, CHARGERATE, NUMPARAM};

/************************************************************/

/**************Function prototype section**********************/
int CheckBatteryParam(float value, BatteryParam param);
	  
int batteryIsOk(float temperature, float soc, float chargeRate);
/************************************************************/