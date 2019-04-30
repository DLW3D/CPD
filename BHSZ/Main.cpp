#include <stdio.h>
#include <math.h>

//输入
void GetInt(char word[], int *data){
	printf("%s",word);
	scanf("%d",data);
}
void GetDouble(char word[], double *data){
	printf("%s",word);
	scanf("%lf",data);
}

//计算闭合水准
void Count(){
	int i;
	int sta;//测站数
	GetInt("请输入测站数:",&sta);
	double start = 0;//起始点高程
	double dh[10] = {0};//高差
	double dd[10] = {0};//距离
	int gz[10] = {0};//改正数mm
	double ddh[10] = {0};//改正后高差
	double gc[11] = {0};//高程

	//输入数据
	GetDouble("请输入起始点高程:",&start);
	printf("请输入%d个高差:\n",sta);
	for(i=0;i<sta;i++){
		GetDouble("",&dh[i]);
	}
	printf("请输入%d个距离:\n",sta);
	for(i=0;i<sta;i++){
		GetDouble("",&dd[i]);
	}

	//计算闭合差
	double Eh = 0;//闭合差计算
	for(i=0;i<sta;i++){
		Eh += dh[i];
	}
	int Ch = (int)(Eh*1000);//闭合差
	double Ed = 0;//总长度
	for(i=0;i<sta;i++){
		Ed += dd[i];
	}
	printf("闭合差为%dmm，允许值为%.2fmm，", (int)Ch, 40*sqrt(Ed));
	if(Ch > 24) {
		printf("该路线的观测不满足要求。\n");
		return;//超限
	}else{
		printf("该路线的观测满足要求。\n");
	}
	//计算改正数
	gc[0] = start;
	for(i=0;i<sta;i++){
		gz[i] = (int)(-Ch * dd[i] / Ed);//计算改正数
		ddh[i] = dh[i] + (double)gz[i]/1000;//计算改正后高差
		gc[i+1] = gc[i] + ddh[i];//计算高程
	}
	
	//输出
	printf("\n改正数：\n");
	for(i=0;i<sta;i++){
		printf("%d,",gz[i]);
	}
	printf("\n改正后高差：\n");
	for(i=0;i<sta;i++){
		printf("%.3f,",ddh[i]);
	}
	printf("\n高程：\n");
	for(i=0;i<sta+1;i++){
		printf("%.3f,",gc[i]);
	}
	printf("\n");
}

int main(){
	Count();
	return 0;
}

