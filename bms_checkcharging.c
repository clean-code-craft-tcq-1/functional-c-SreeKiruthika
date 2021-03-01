#include "bms.h"


/****************************************************************************************
*Func desc : This function check if the battery is charging
*Param     : chargeRate - The battery charging rate - float type
*Return    : Returns the status of charging
			 1 - Battery is charging
			 0 - Battery is not charging
*****************************************************************************************/
int checkIfCharging(float chargeRate)
{
	if (chargeRate != 0)
	{
		printf("Battery is charging");
		return 1;
	}
	else
	{
		printf("Battery is not charging");
		return 0;
	}

}


/****************************************************************************************
*Func desc : This function is used to check for the battery charge monitoring 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : No return values, just infers the battry charge / charging status
*****************************************************************************************/	  
void BatteryChargeMonitoring(float temperature, float soc, float chargeRate) 
{
	int tempstatus, retval;
	if (checkIfCharging(chargeRate) == 1)
	{ 
		tempstatus = checkTemp(temperature);
		retval = (tempstatus==1)? printf("Temperature not sufficient"): ((tempstatus == 2) ? printf("Temperature is too high for charging"): printf("Temperature is ok"));
		retval = (checkSoC(soc)) ? printf("Charging is sufficient, UNPLUG CHARGER!") : printf("Battery is Charging");
		
	}
	else
	{
		if (checkSoC(soc)== 1)
		{
			printf("Battery charging is needed");
			tempstatus = checkTemp(float temperature);
			retval = (tempstatus==1)? printf("Temperature not sufficient"): ((tempstatus == 2) ? printf("Temperature is too high for charging"): printf("Temperature is ok"));
		}
	}
		
}
