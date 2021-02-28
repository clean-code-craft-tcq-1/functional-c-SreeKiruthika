#include "bms.h"

int checkTemp(float temperature)
{
    int retval;
   
	retval = (temperature < MINTEMP)? 1: ((temperature > MAXTEMP)? 2 : 0);
	
    return retval;
}	
		
int checkSoC(float soc)
{
	int retval ;

	retval = (soc < MINSOC)? 1 :((soc > MAXSOC)? 2 : 0);

	return retval;
}

int checkChargeRate(float chargeRate)
{
	int retval;
	retval = (chargeRate <= MAXCHGRATE)? ((chargeRate == 0) ? 2 : 0 ): 1;
	return retval;
}

/****************************************************************************************
*Func desc : This function check if the battery parameters are within the specified range 
*Param     : value - The battery parameter value that was measured -float type
*            param - The battery parameter whos values is passed as first argument
*Return    : Returns the state as int variable in which each bit represents if the parameter is not ok (if bit set , then not ok)
			 Bit 0 : Temperature
			 Bit 1 : State of Charge
			 Bit 2 : Charging rate
			 All bit set indicates invalid parameter passed
*****************************************************************************************/


/****************************************************************************************
*Func desc : This function check if the battery state is ok 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : Returns the state of battery as int, if 1 battery is ok, else battery is not ok
*****************************************************************************************/	  
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  int BatteryStatus = 0;
  int temp_BatteryStatus = 0;
  temp_BatteryStatus = checkTemp(temperature);
  BatteryStatus = temp_BatteryStatus && 0x03;
  temp_BatteryStatus = checkSoC(soc) << 2;
  BatteryStatus =  BatteryStatus | (temp_BatteryStatus && 0xC0);
  temp_BatteryStatus = checkChargeRate (chargeRate) << 4;
  BatteryStatus = BatteryStatus | (temp_BatteryStatus && 0x10); /*Only 1 bit considered as 2 indicates not charging
  
  return (BatteryStatus == 0);
}
