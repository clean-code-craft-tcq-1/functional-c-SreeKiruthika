#include "bms.h"

int checkTemp(float temperature)
{
	int retval = 0;
    if ((temperature >= MINTEMP) && (temperature <= MAXTEMP))
    {
       printf("Temperature within range!\n");
       retval = 0 ;
    }
    else if (temperature == 255)
	{
		printf("Temperature Sensor is defective!\n");
       retval = 3 ;
	}
	else
	{
	   printf("Temperature is out of range!\n");
       retval =(temperature < MINTEMP) ? 1 : 2;
	}
	return retval;
}	
		
int checkSoC(float soc)
{
	int retval = 0;
	if ((soc >= MINSOC) && (soc <= MAXSOC))
	{
	  printf("State of Charge in range!\n");
	  retval = 0 ;
	}
	else if (soc == 255)
	{
	  printf("State of Charge sensor defective\n");
	  retval = 0 ;
	}
	else
	{
	   printf("SoC is out of range!\n");
       retval = (soc < MINSOC)? 1 : 2;
	}
	return retval;
}

int checkChargeRate(float chargeRate)
{
	int retval = 0;
	if ((chargeRate <= MAXCHGRATE))
	{
	  printf("charge rate in range!\n");
	  retval =  0 ; /*2 indicates it is not charging */
	}
	else if ((chargeRate < 0) || (chargeRate > 1))
	{
	  printf("Charge rate measured is defective\n");
	  retval = 3 ;
	}
	else
	{
	   printf("SoC is out of range!\n");
       retval = 1 ;
	}
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
  float batteryParamValue[NUMPARAM] = {temperature, soc, chargeRate};
  int BatteryStatus = 0;
  BatteryStatus = checkTemp(temperature)&& 0x03;
  temp_BatteryStatus = checkSoC(soc) << 2;
  BatteryStatus =  BatteryStatus | (temp_BatteryStatus && 0xC0);
  temp_BatteryStatus = checkChargeRate (value) << 4;
  BatteryStatus = BatteryStatus | (temp_BatteryStatus && 0x30);
  
  if (BatteryStatus > 0)  
	 return 0;
  else
	 return 1;
}
