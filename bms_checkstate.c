#include "bms.h"

/****************************************************************************************
*Func desc : This function check if the battery temperature is within the specified range 
*Param     : temperature - The battery temperature - float type
*Return    : Returns the status of charge
			 0 - SoC rate is within range (OK)
			 1 - SoC is less than required charge (NOT_OK)
			 2 - SoC is more than desired charge value (NOT_OK)
*****************************************************************************************/	
int checkTemp(float temperature)
{
    int retval;
   
	retval = (temperature < MINTEMP)? 1: ((temperature > MAXTEMP)? 2 : 0);
	
    return retval;
}	

/****************************************************************************************
*Func desc : This function check if the battery state of charge is within the specified range 
*Param     : soc - The battery SoC - float type
*Return    : Returns the status of charge
			 0 - SoC rate is within range (OK)
			 1 - SoC is less than required charge (NOT_OK)
			 2 - SoC is more than desired charge value (NOT_OK)
*****************************************************************************************/		
int checkSoC(float soc)
{
	int retval ;

	retval = (soc < MINSOC)? 1 :((soc > MAXSOC)? 2 : 0);

	return retval;
}

/****************************************************************************************
*Func desc : This function check if the battery charge rate is within the specified range 
*Param     : chargeRate - The battery charging rate - float type
*Return    : Returns the status of charging rate
			 1 - Charge rate is not in range (NOT_OK)
			 0 - Charging rate is within range (OK)
*****************************************************************************************/
int checkChargeRate(float chargeRate)
{
	int retval;
	retval = (chargeRate < MAXCHGRATE)? 0 : 1;
	return retval;
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
    return !(checkTemp(temperature)||checkSoC(soc)||checkChargeRate(chargeRate));
}
