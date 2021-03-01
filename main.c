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
  BatteryChargeMonitoring (30,80,0);
}
