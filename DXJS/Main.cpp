#include <stdio.h>
#include <iostream.h>
#include <math.h>

#define PI 3.1415926535

//����ȷ���
void GetDMS(char word[], int angle[]){
	printf("%s",word);
	scanf("%d,%d,%d",&angle[0],&angle[1],&angle[2]);
	//�������
	if(angle[0]>=360){
		angle[0] -= 360;
	}else if(angle[0]<0){
		angle[0] += 360;
	}
	if(angle[2]>=60 || angle[2]<0 || angle[1]>=60 || angle[1]<0){
		printf("�����������������\n");
		GetDMS(word, angle);
	}
}
//��������
void GetXY(char word[], double XY[]){
	printf("%s",word);
	scanf("%lf,%lf",&XY[0],&XY[1]);
}
//��������
void GetInt(char word[], int &data){
	printf("%s",word);
	scanf("%d",&data);
}
//���븡����
void GetDouble(char word[], double &data){
	printf("%s",word);
	scanf("%lf",&data);
}
//�ȷ���ת��
int GetSec(int deg[]){
	return deg[2] + deg[1]*60 + deg[0]*3600;
}
//��ת�ȷ���
void GetDeg(int sec, int ret[]){
	//��鷶Χ
	//if(sec >= 360*60*60){
	//	sec -= 360*60*60;
	//}else if(sec < 0){
	//	sec += 360*60*60;
	//}
	//ת��
	ret[0] = sec/3600;
	ret[1] = (sec%3600)/60;
	ret[2] = (sec%60);
}
//����ȷ���
void printDEG(char word[], int deg[]){
	printf("%s:(%d,%d,%d)\n",word,deg[0],deg[1],deg[2]);
}

//�Ƕȼӷ�
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

//�Ƕȼ���
void AngMin(int res[], int a[], int b[]){
	GetDeg(GetSec(a) - GetSec(b), res);
}
//////////////////////////////////////////////////////////////////

//�ȷ���ת����
double DMSToRed(int angle[]){
	return (angle[0] + angle[1]/60 + angle[2]/3600) * PI / 180;
}

//����ת�ȷ���
void RedToDMS(double red, int angle[]){
	double sec = red * 180 * 3600 / PI;
	angle[0] = sec/3600;
	angle[1] = (sec%3600)/60;
	angle[2] = (sec%60);
}

//����ȷ���
double ScanDMSToRed(char word[]){
	int angle[3]��
	printf("%s",word);
	scanf("%d,%d,%d",&angle[0],&angle[1],&angle[2]);
	//�������
	if(angle[0]>=360){
		angle[0] -= 360;
	}else if(angle[0]<0){
		angle[0] += 360;
	}
	if(angle[2]>=60 || angle[2]<0 || angle[1]>=60 || angle[1]<0){
		printf("�����������������\n");
		GetDMS(word, angle);
	}
	return DMSToRed(word);
}

//����պϵ���
void Count(){
	int i;
	int sta;//��վ��(������)max:10
	int lor;//��ǻ��ҽ�
	double gcj[10];//�۲��
	double jdgz[10];//�Ƕȸ���ֵ
	double gzj[10];//������Ƕ�
	double fwj[10];//��λ��
	double zb[11][2];//����
	double zbzl[10][2];//��������
	double zbgz[10][2];//�������
	double gzzl[10][2];//����������
	double bc[10];//�߳�
	
	double dxcd = 0;//���߳���
	int bhc[3] = {0,0,0};//�Ƕȱպϲ�
	
	//��������
	GetInt("��վ��(������)��", sta);
	GetInt("���+1���ҽ�-1��", lor);

	printf("������2����֪��:\n");
	ScanDMSToRed("", fwj[0]);
	ScanDMSToRed("", fwj[sta-1]);


	printf("������%d���۲��:\n",sta-1);
	for(i=1;i<sta;i++){
		ScanDMSToRed("", gcj[i]);
	}

	printf("������4����֪����:\n");
	GetXY("B:", zb[0]);
	GetXY("A:", zb[1]);
	GetXY("C:", zb[sta-1]);
	GetXY("D:", zb[sta]);

	printf("������%d���߳�:\n",sta-2);
	for(i=1;i<sta-1;i++){
		GetDouble("", bc[i]);
		dxcd += bc[i];
	}

	cout << "�߳��ͣ�" << dxcd << endl;

	//����պϲ�
	GetDeg(GetSec(fwj[0]),bhc);//��˼��bhc = fwj[0];
	for (i = 1; i < sta; i++)
	{
		AngAdd(bhc, bhc, gcj[i]);
	}
	int temi[3];
	GetDeg(180*60*60*(sta-1), temi);
	AngMin(bhc, bhc, temi);
	AngMin(bhc, bhc, fwj[sta-1])
	printDEG("�պϲ�",bhc);


}

int main(){
	Count();
	return 0;
}

