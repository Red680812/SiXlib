/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#ifndef SiXlib_h
#define SiXlib_h

class SiX
{
 void LinePID(double intput,double KP,double KI,double KD);
 void SetPID(int MOD,double MAXval,double MINval);

};

#endif