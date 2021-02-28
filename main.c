#include <stdio.h>
#include <assert.h>

#ifndef _BMS_H
#include "bms.h"
#endif

int main() 
{
  /*All param within range */
  assert(batteryIsOk(25, 70, 0.7));
  /*Temperature out of range */
  assert(!batteryIsOk(46, 70, 0.3));
  /*SoC out of range */
  assert(!batteryIsOk(50, 85, 0));
  /*SoC out of range */
  assert(!batteryIsOk(25, 70, 0.85));
}
