#pragma once	//2重インクルード防止
double dicToRas(double angle);
double getGapLength(double xA,double yA,double xB,double yB);
double getGapAngle(double xA,double yA,double xB,double yB);
double GetGapX(double xA,double gapLength,double gapAngle);
double GetGapY(double yA,double gapLength,double gapAngle);