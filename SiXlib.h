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
	SiX(void);

  //功能一: PID
	void SetPID(int, double, double);
	void LinePID(double, double, double, double);
	double rePID();
 				 
  //功能二: 計時器
	void Timer(int, unsigned long);
	unsigned long reTime();
 				 
  //功能三: 正負值馬達控制
	void SetMotoPin(int, int, int, int);
	void Speed(int, int);
 				 
  //功能四: 限時轉彎
	void TimeTurn(int, int, int);
 				 
  //功能五: 曲率判斷
	void Curvature(double, double);
 				 
  //功能六: 輪差修正
	void WheelDiffer(double, int);
	double reCorval();
 				 
private:
	int Pin1A;
	int Pin1B;
	int Pin2A;
	int Pin2B;
 				 
	double MOD;

	unsigned long time;
 				 
	double MAXval;
	double MINval;
  				 
	double interror;
	double olderror;
	double output;

	double OldCorrectVal;
	double CorrectVal;
};
#endif