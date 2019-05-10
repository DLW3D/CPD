#include <stdio.h>
#include <iostream.h>
#include <math.h>

#define PI 3.1415926535

//输入度分秒
void GetDMS(char word[], int angle[]){
	printf("%s",word);
	scanf("%d,%d,%d",&angle[0],&angle[1],&angle[2]);
	//检查输入
	if(angle[0]>=360){
		angle[0] -= 360;
	}else if(angle[0]<0){
		angle[0] += 360;
	}
	if(angle[2]>=60 || angle[2]<0 || angle[1]>=60 || angle[1]<0){
		printf("输入错误，请重新输入\n");
		GetDMS(word, angle);
	}
}
//输入坐标
void GetXY(char word[], double XY[]){
	printf("%s",word);
	scanf("%lf,%lf",&XY[0],&XY[1]);
}
//输入整数
void GetInt(char word[], int &data){
	printf("%s",word);
	scanf("%d",&data);
}
//输入浮点数
void GetDouble(char word[], double &data){
	printf("%s",word);
	scanf("%lf",&data);
}
//度分秒转秒
int GetSec(int deg[]){
	return deg[2] + deg[1]*60 + deg[0]*3600;
}
//秒转度分秒
void GetDeg(int sec, int ret[]){
	//检查范围
	//if(sec >= 360*60*60){
	//	sec -= 360*60*60;
	//}else if(sec < 0){
	//	sec += 360*60*60;
	//}
	//转换
	ret[0] = sec/3600;
	ret[1] = (sec%3600)/60;
	ret[2] = (sec%60);
}
//输出度分秒
void printDEG(char word[], int deg[]){
	printf("%s:(%d,%d,%d)\n",word,deg[0],deg[1],deg[2]);
}

//角度加法
void AngAdd(int res[], int a[], int b[]){
	GetDeg(GetSec(a) + GetSec(b), res);
	/*
	int i;
	for(i=0;i<3;i++){
		res[i] = a[i] + b[i];
	}
	for(i=2;i>0;i--){
		if(res[i]>60){
			res[i] =- 60;
			res[i-1]++;
		}
	}
	*/
}

//角度减法
void AngMin(int res[], int a[], int b[]){
	GetDeg(GetSec(a) - GetSec(b), res);
}
//////////////////////////////////////////////////////////////////

//度分秒转弧度
double DMSToRed(int angle[]){
	return (angle[0] + angle[1]/60 + angle[2]/3600) * PI / 180;
}

//弧度转度分秒
void RedToDMS(double red, int angle[]){
	double sec = red * 180 * 3600 / PI;
	angle[0] = sec/3600;
	angle[1] = (sec%3600)/60;
	angle[2] = (sec%60);
}

//输入度分秒
double ScanDMSToRed(char word[]){
	int angle[3]；
	printf("%s",word);
	scanf("%d,%d,%d",&angle[0],&angle[1],&angle[2]);
	//检查输入
	if(angle[0]>=360){
		angle[0] -= 360;
	}else if(angle[0]<0){
		angle[0] += 360;
	}
	if(angle[2]>=60 || angle[2]<0 || angle[1]>=60 || angle[1]<0){
		printf("输入错误，请重新输入\n");
		GetDMS(word, angle);
	}
	return DMSToRed(word);
}

//计算闭合导线
void Count(){
	int i;
	int sta;//测站数(坐标数)max:10
	int lor;//左角或右角
	double gcj[10];//观测角
	double jdgz[10];//角度改正值
	double gzj[10];//改正后角度
	double fwj[10];//方位角
	double zb[11][2];//坐标
	double zbzl[10][2];//坐标增量
	double zbgz[10][2];//坐标改正
	double gzzl[10][2];//改正后增量
	double bc[10];//边长
	
	double dxcd = 0;//导线长度
	int bhc[3] = {0,0,0};//角度闭合差
	
	//输入数据
	GetInt("测站数(坐标数)：", sta);
	GetInt("左角+1，右角-1：", lor);

	printf("请输入2个已知角:\n");
	ScanDMSToRed("", fwj[0]);
	ScanDMSToRed("", fwj[sta-1]);


	printf("请输入%d个观测角:\n",sta-1);
	for(i=1;i<sta;i++){
		ScanDMSToRed("", gcj[i]);
	}

	printf("请输入4个已知坐标:\n");
	GetXY("B:", zb[0]);
	GetXY("A:", zb[1]);
	GetXY("C:", zb[sta-1]);
	GetXY("D:", zb[sta]);

	printf("请输入%d个边长:\n",sta-2);
	for(i=1;i<sta-1;i++){
		GetDouble("", bc[i]);
		dxcd += bc[i];
	}

	cout << "边长和：" << dxcd << endl;

	//计算闭合差
	GetDeg(GetSec(fwj[0]),bhc);//意思是bhc = fwj[0];
	for (i = 1; i < sta; i++)
	{
		AngAdd(bhc, bhc, gcj[i]);
	}
	int temi[3];
	GetDeg(180*60*60*(sta-1), temi);
	AngMin(bhc, bhc, temi);
	AngMin(bhc, bhc, fwj[sta-1])
	printDEG("闭合差",bhc);


}

int main(){
	Count();
	return 0;
}

