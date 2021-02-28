#include "bms.h"

int checkTemp(float temperature)
{
    if ((value >= MINTEMP) && (value <= MAXTEMP))
    {
       printf("Temperature within range!\n");
       retval = 0 ;
    }
	else if (value == 255)
	{
		printf("Temperature Sensor is defective!\n");
       retval = 3 ;
	}
	else
	{
	   printf("Temperature is out of range!\n");
       retval =(value < MINTEMP) ? 1 : 2;
	}
}	
		
int checkSoC(float value)
{
	if ((value >= MINSOC) && (value <= MAXSOC))
	{
	  printf("State of Charge in range!\n");
	  retval = 0 ;
	}
	else if (value == 255)
	{
	  printf("State of Charge sensor defective\n");
	  retval = 0 ;
	}
	else
	{
	   printf("SoC is out of range!\n");
       retval = (value < MINSOC) 1 : 2;
	}
}
int checkChargeRate(float value)
{
	if ((value <= MAXCHGRATE))
	{
	  printf("charge rate in range!\n");
	  retval = (value == 0)? 2 : 0 ; /*2 indicates it is not charging */
	}
	else if ((value < 0) || (value > 1))
	{
	  printf("Charge rate measured is defective\n");
	  retval = 3 ;
	}
	else
	{
	   printf("SoC is out of range!\n");
       retval = 1 ;
	}
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

int CheckBatteryParam(float value, enum BatteryParam param)
{
	int retval = 0;
	switch (param)
	{
	  case TEMP:
        retval = checkTemp(value);
		break;
	  case SOC:
	    retval = checkSoC(value) << 2 ;
		break;
	  case CHARGERATE:
	    retval = checkChargeRate (value) << 4;
	    break;
	  default:
	   retval = 255; /*To indicate invalid paramater passed*/
	} 
	
	return retval;
}

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
  for (int param =0; param < NUMPARAM; param++)
  {
	  int index = param ;
	  int temp_BatteryStatus =  CheckBatteryParam (batteryParamValue[index] , param) ;
	  BatteryStatus = BatteryStatus | (temp_BatteryStatus << (2*param)) ;
  }
  if (BatteryStatus > 0)  
	 return 0;
  else
	 return 1;
}
