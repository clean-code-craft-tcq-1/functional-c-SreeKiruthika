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
#define MAXCHGRATE 0.8

enum BatteryParam {TEMP, SOC, CHARGERATE, NUMPARAM};

/************************************************************/

/**************Function prototype section**********************/
  
int BatteryStateCheck(float temperature, float soc, float chargeRate);

int checkSoC(float soc);

int checkTemp(float temperature);

int checkChargeRate(float chargeRate);

void BatteryChargeMonitoring(float temperature, float soc, float chargeRate) ;

void checkIfChargingNeeded(float soc);

void checkIfCharged(float soc);
/************************************************************/