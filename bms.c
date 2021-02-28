#include "bms.h"

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
        if ((value < MINTEMP)|| (value > MAXTEMP))
	    {
		  printf("Temperature out of range!\n");
		  retval = 1 ;
	    }
		break;
	  case SOC:
	    if ((value < MINSOC)|| (value > MAXSOC))
	    {
		  printf("State of Charge out of range!\n");
		  retval = 2 ;
	    }
		break;
	  case CHARGERATE:
	    if (value > MAXCHGRATE)
	    {
		  printf("Charge Rate out of range!\n");
		  retval = 4 ;
	    }
	  break;
	  default:
	   retval=255; /*To indicate invalid paramater passed*/
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
	  BatteryStatus = BatteryStatus | temp_BatteryStatus ;
  }
  if (BatteryStatus > 0)  
	 return 0;
  else
	 return 1;
}
