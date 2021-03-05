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
		printf("\nBattery is charging");
		return 1;
	}
	else
	{
		printf("\nBattery is not charging");
		return 0;
	}

}


/****************************************************************************************
*Func desc : This function is used to check for the battery charge monitoring 
*Param     : temperature - The current battery temperature value that was measured -float type
*			 soc         - The current battery state of charge that was measured   -float type	
*            chargerate  - The charging rate that is measured - float type
*Return    : No return values, just infers the battery charge / charging status
*****************************************************************************************/	  
void BatteryChargeMonitoring(float temperature, float soc, float chargeRate) 
{
	int tempstatus, retval;
	printf("\nCharging status info:");
	int tempstatus = checkTemp(temperature);
	int chargestatus = (checkSoC(soc));
	if (checkIfCharging(chargeRate) == 1)
	{ 
	     retval = (chargestatus==2) ? printf("\nCharging is sufficient, UNPLUG CHARGER!") : printf("\n Continue charging till 80%");
	}
	else
	{
		if(chargestatus==2)
		{
			printf("\nCharging is needed, CONNECT CHARGER!");
		}	
	 }
		
}
