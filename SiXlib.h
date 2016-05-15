/******************************************/
/************    Library by   *************/
/************     Shiichi     *************/
/************    2016/05/13   *************/
/******************************************/

#ifndef SiXlib_h
#define SiXlib_h

class SiX
{

public:
  //功能一: PID
	void SetPID(int, double, double);
	void LinePID(double, double, double, double);
 				 
  //功能二: 計時器
	void Timer(int, unsigned long);
 				 
  //功能三: 正負值馬達控制
	void SetMotoPin(int, int, int, int);
	void Speed(int, int);
 				 
  //功能四: 限時轉彎
	void TimeTurn(int, int, int);
 				 
  //功能五: 曲率判斷
	void Curvature(double, double);
 				 
  //功能六: 輪差修正
	void WheelDiffer(double, int);
 				 
private:
	int Pin1A;
	int Pin1B;
	int Pin2A;
	int Pin2B;
 				 
	double MOD;
 				 
	double MAXval;
	double MINval;
  				 
	double interror;
	double olderror;
			  
	double OldCorrectVal;
};
#endif