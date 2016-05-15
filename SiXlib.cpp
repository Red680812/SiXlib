/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#include "SiXlib.h"

SiXlib::SiX(void)
{
}

double MOD,MAXval,MINval;
void SiXlib::SetPID(int MOD,double Aval,double Bval)
{
//設定輸入訊號是否去小數點
	if (MOD > 0)
	 MOD = 1; //是
	else
	 MOD = 0; //否
	MAXval = Aval;
	MINval = Bval;
}

double interror,olderror;
void SiXlib::LinePID(double intput,double KP,double KI,double KD)
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

void SiXlib::Timer(int start,unsigned long timekey)
{
  static unsigned long time = start;
  time += timekey;
  return time;
}

int Pin1A, Pin1B, Pin2A, Pin2B;
void SiXlib::SetMotoPin(int P1A,int P1B,int P2A,int P2B)
{
	Pin1A = P1A;
	Pin1B = P1B;
	Pin2A = P2A;
	Pin2B = P2B;
}

void SiXlib::Speed(int Left,int Right)
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

void SiXlib::TimeTurn(int time,int Left,int Right)
{
	while(1)
	{
		Speed(Left, Right);
	    static unsigned long ENDt = Timer(0,1);
		if ((ENDt/(time*1000)) = 1)
		  break;
	}
}

double OldCorrectVal;
void SiXlib::WheelDiffer(double CorrectVal,int Frequency)
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