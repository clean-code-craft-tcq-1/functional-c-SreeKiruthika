/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for BMS*/
/************************************************************************************************************************/
#include <stdio.h>

/***************DEFINES section *****************************/
/* Parameters related to battery maintainence check is defined here*/
#define MINTEMP 0
#define MAXTEMP 45
#define MINSOC  20
#define MAXSOC  80
#define MINCHGRATE 0
#define MAXCHGRATE 0.8

/************************************************************/

/**************Function prototype section**********************/
  
int BatteryStateCheck(float temperature, float soc, float chargeRate);

void printBatteryStatus(int batteryStatus);

int BatteryParamCheck (float param_value, float min_value, float max_value);

void BatteryChargeMonitoring(float soc, float chargeRate) ;

void checkIfChargingNeeded(float soc);

void checkIfCharged(float soc);
/************************************************************/