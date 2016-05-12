/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#include "SiXlib.h"

SiXlib::SiX(void)
{
}

void SiXlib::SetPID(int MOD,double MAXval,double MINval)
{
//設定輸入訊號是否去小數點
	if (MOD > 0)
	 MOD = 1; //是
	else
	 MOD = 0; //否
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
    intput = (error + interror + lasterror) * KP;

    if (intput > MAXval)
      intput = MAXval;
    if (intput < MINval)
      intput = MINval;
}