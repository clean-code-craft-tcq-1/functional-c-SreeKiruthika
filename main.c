#include <stdio.h>
#include <assert.h>

#ifndef _BMS_H
#include "bms.h"
#endif

int main() 
{
  /*All param within range */
  assert(BatteryStateCheck(25, 70, 0.7));
  /*Temperature out of range */
  assert(!BatteryStateCheck(46, 70, 0.3));
  /*SoC out of range */
  assert(!BatteryStateCheck(50, 85, 0));
  /*SoC out of range */
  assert(!BatteryStateCheck(25, 70, 0.85));
  
  /*This function to be called every frequently based on the monitoring frequency needed*/
  /*Not charging and battery is normal */
  printf("\nThe passed values for battery charging status check are as follows \nTemperature : 30 \nSoC : 80 \nCharge rate:0");
  BatteryChargeMonitoring (30,80,0);

  /*Not charging and charge is low with optimum temperature */
  printf("\nThe passed values for battery charging status check are as follows \nTemperature : 30 \nSoC : 19 \nCharge rate:0");
  BatteryChargeMonitoring (30,19,0);

  /*Charging and charge is above threshold with optimum temperature */
  printf("\nThe passed values for battery charging status check are as follows \nTemperature : 25 \nSoC : 81 \nCharge rate:0.3");
  BatteryChargeMonitoring (25,81,0.3);

  /*Charging and charge is in limit with more temperature */
  printf("\nThe passed values for battery charging status check are as follows \nTemperature : 60 \nSoC : 75 \nCharge rate:0.5");
  BatteryChargeMonitoring (60,75,0.5);
}


