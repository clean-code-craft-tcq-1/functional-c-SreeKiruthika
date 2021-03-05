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
	if (chargeRate == 0)
	{
		printf("\nBattery is not charging");
		return 0;
	}
	else if(chargeRate < MAXCHGRATE)
	{
	   printf("\nBattery is charging");
	   return 1;
	}
    else
	{
	   printf("\nBattery Charge rate is too high, UNPLUG charger!");
	   return 2;
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
	int  retval;
	printf("\nCharging status info:");
		
	if((checkIfCharging(chargeRate) == 1))
	{
		checkIfCharged(soc); 				
	}
	else
	{
		checkIfChargingNeeded(soc);
	}
	checkTemp(temperature);	
}


/****************************************************************************************
*Func desc : This function is to print the status of battery charging
*Param     : soc         - The current battery state of charge that was measured   -float type	      
*Return    : No return values, just prints battery charging status. This function to be called only if battery charging
*****************************************************************************************/
void checkIfCharged(float soc)
{
	if (soc > MAXSOC)
	{
	   printf("Charging is sufficient, UNPLUG CHARGER!");
	}
	else
	{
	  printf("Batery charge value is %d , continue charging till 80%!", soc);
    }
}
/****************************************************************************************
*Func desc : This function is to print the status if battery charging needed
*Param     : soc         - The current battery state of charge that was measured   -float type	      
*Return    : No return values, just prints battery charging requiements. This function to be called only if battery is not charging
*****************************************************************************************/
void checkIfChargingNeeded(float soc)
{
	if (soc < MINSOC)
	{
	   printf("Battery charge is low, CONNECT CHARGER!");
	}
	else
	{
	  printf("Batery charge value is %d, connect if it goes less than 20% ", soc);
    }

}
