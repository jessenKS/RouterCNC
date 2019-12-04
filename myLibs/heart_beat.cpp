#include "Arduino.h"
#include "heart_beat.h"
//#include "controles.h"

/*
void heart_beating()
{
  static unsigned long long int millis_heartbeat = 0;

  if (digitalRead(ENABLE) == HIGH)
  {
    if (millis() - millis_heartbeat >= DELAY_HEARTBEAT)
    {
      millis_heartbeat = millis();
      digitalWrite(HEART_BEAT, !digitalRead(HEART_BEAT));
    }
  }
  else if (digitalRead(ENABLE) == LOW)
    digitalWrite(HEART_BEAT, HIGH);
}
*/
