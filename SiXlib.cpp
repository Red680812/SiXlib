/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <SiXlib.h>

SiX::SiX(void)
{
}

void SiX::SetPID(int MODE,double Aval,double Bval)
{
//設定輸入訊號是否去小數點
	if (MODE > 0)
	 MOD = 1; //是
	else
	 MOD = 0; //否
	MAXval = Aval;
	MINval = Bval;
}

void SiX::LinePID(double intput,double KP,double KI,double KD)
{
	if (MOD == 1)
	  intput = ((int)intput);
    double error = intput;
    interror = (error * KI) + interror;
    double lasterror = (error * KD) - olderror;
    olderror = error;
    double output = (error + interror + lasterror) * KP;

    if (intput > MAXval)
      intput = MAXval;
    if (intput < MINval)
      intput = MINval;
    return output;
}

void SiX::Timer(int start,unsigned long timekey)
{
  static unsigned long time = start;
  time += timekey;
  return time;
}

void SiX::SetMotoPin(int P1A,int P1B,int P2A,int P2B)
{
	Pin1A = P1A;
	Pin1B = P1B;
	Pin2A = P2A;
	Pin2B = P2B;
}

void SiX::Speed(int Left,int Right)
{
  if (Left > 0) {
    analogWrite(Pin1A, Left);
    analogWrite(Pin1B, 0);
  }
  else {
    analogWrite(Pin1A, 0);
    analogWrite(Pin1B, -Left);
  }
  if (B > 0) {
    analogWrite(Pin2A, Right);
    analogWrite(Pin2B, 0);
  }
  else {
    analogWrite(Pin2A, 0);
    analogWrite(Pin2B, -Right);
  }
}

void SiX::TimeTurn(int time,int Left,int Right)
{
	while(1)
	{
		Speed(Left, Right);
	    static unsigned long ENDt = Timer(0,1);
		if ((ENDt/(time*1000)) = 1)
		  break;
	}
}

void SiX::WheelDiffer(double CorrectVal,int Frequency)
{
	if (Frequency <= 0)
	 Frequency = 1;
	if (Frequency >100)
	 Frequency = 100;
	for (int i; i > Frequency; i++)
	{
		if (abs(CorrectVal) < abs(OldCorrectVal))
		  CorrectVal = OldCorrectVal;
	  	OldCorrectVal = CorrectVal;
	}
	return CorrectVal;
}