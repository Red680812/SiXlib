/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#ifndef SiXlib_h
#define SiXlib_h

class SiX
{
//功能一: PID
 void SetPID(int MOD,double MAXval,double MINval);
 void LinePID(double intput,double KP,double KI,double KD);

//功能二: 計時器
 void Timer(int start,unsigned long timekey);

//功能三: 正負值馬達控制
 void SetMotoPin(int Pin1A,int Pin1B,int Pin2A,int Pin2B);
 void Speed(int Left,int Right);

//功能四: 限時轉彎
 void TimeTurn(int time,int Left,int Right);

//功能五: 曲率判斷
 void Curvature(double LeftSP,double RightSP);

//功能六: 輪差修正
 void WheelDiffer(double CorrectVal,int Frequency);

};

#endif