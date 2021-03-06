#include "bms.h"

/****************************************************************************************
*Func desc : This function check if the passed battery parameter value is within the specified range 
*Param     : param_value - The measured battery parameter value, whole limits are to be verified - float type
*Return    : Returns the status of param limit check
			 0 - Param is within range (OK)
			 1 - Param is less than required charge (NOT_OK)
			 2 - Param is more than desired charge value (NOT_OK)
*****************************************************************************************/	
int BatteryParamCheck (float param_value, struct ParamLimits param_limit)
{
    if(param_value < param_limit.min_value)
	{
		return 1;
	}
	else if (param_value > param_limit.max_value) 
	{
		return 2;
	}
	else
	{
		return 0;
	}
}	

/****************************************************************************************
*Func desc : This function check if the battery state is ok. In this function all the desired battery
			 parameters are checked to validate the current battery status. Further 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : Returns the state of battery as int, 
			 1 - battery is ok
			 0 - battery is not ok
*****************************************************************************************/	  
int BatteryStateCheck(float temperature, float soc, float chargeRate) 
{
	/*All check param functions must return 0 if the param check is OK*/
    int batteryStatus;
	
	batteryStatus = !((BatteryParamCheck(temperature, tempLimits)) || (BatteryParamCheck(soc, SoCLimits)) || (BatteryParamCheck(chargeRate, ChargeRateLimits)));
	
	printBatteryStatus(batteryStatus);
	
    return batteryStatus;
}

/****************************************************************************************
*Func desc : This function check if the battery state is ok. In this function all the desired battery
			 parameters are checked to validate the current battery status. Further 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : Returns the state of battery as int, 
			 1 - battery is ok
			 0 - battery is not ok
*****************************************************************************************/	
void printBatteryStatus(int batteryStatus)
{
	if(batteryStatus)
	{
		printf("\nBattery status is OK");
	}
	else
	{
		printf("\nBattery status is NOT OK");
	}
}