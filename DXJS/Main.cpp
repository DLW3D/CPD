#include <stdio.h>
#include <iostream.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944 

//�������뵽����
int Round(float num){
	return (int)(num>0 ? num+0.5: num-0.5);
}

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
int DMSToSec(int deg[]){
	return deg[2] + deg[1]*60 + deg[0]*3600;
}
//��ת�ȷ���
void SecToDMS(int sec, int ret[]){
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

//�Ƕȼӷ�
void AngAdd(int res[], int a[], int b[]){
	SecToDMS(DMSToSec(a) + DMSToSec(b), res);
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
	SecToDMS(DMSToSec(a) - DMSToSec(b), res);
}
//////////////////////////////////////////////////////////////////

//�ȷ���ת����
double DMSToRed(int angle[]){
	return (angle[0]<0?-1:1) * (abs(angle[0]*3600) + angle[1]*60 + angle[2]) * PI / 180 / 3600;
}

//����ת�ȷ���
void RedToDMS(double red, int angle[]){
	double secd = red * 180 * 3600 / PI;
	int sec = Round(secd);
	angle[0] = sec/3600;
	angle[1] = (sec%3600)/60;
	angle[2] = sec%60;

	//double sec = red * 180 * 3600 / PI;
	//angle[0] = sec/3600;
	//angle[1] = (sec-angle[0]*3600)/60;
	//angle[2] = Round(sec-angle[0]*3600-angle[1]*60);
}

//����ȷ���
double GetDMSToRed(char word[]){
	int angle[3];
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
	return DMSToRed(angle);
}

//����ȷ���
void printDMS(char word[], int angle[]){
	printf("%s(%d,%d,%d)\n",word,angle[0],angle[1],angle[2]);
}

//����ȷ���
void printRedToDMS(char word[], double red){
	int angle[3];
	RedToDMS(red, angle);
	printDMS(word, angle);
}

//ˢ��ʹ�ýǶ�ˢ�»���
void refreshDegWithDMS(double &red){
	int angle[3];
	RedToDMS(red, angle);
	red = DMSToRed(angle);
}

//��������
void ZBZS(double zb[2], double bc, double fwj){
	zb[0] = bc * cos(fwj);
	zb[1] = bc * sin(fwj);
}

//�ַ��ָ�
void strSplit(char str[], const char spl[], char **ret){
	char *p; 
	p = strtok(str, spl);
	int i = 0;
	while(p)
	{
		ret[i++] = p;
		p = strtok(NULL, spl);  
	}
}

//�ַ���תdoubles
void StrToDoubles(char str[], const char spl[], double num[10]){
	char *ret[10] = {"","","","","","","","","",""};
	strSplit(str,spl,ret);
	int i = 0;
	for(i=0;ret[i]!="";i++){
		num[i] = atof(ret[i]);//char[]תdouble
	}
}

//�ַ���תReds
void StrToReds(char str[], const char spl[], double num[10]){
	char *ret[10] = {"","","","","","","","","",""};
	char *cang[3] = {"","",""};
	int ang[3];
	strSplit(str,spl,ret);
	for(int i=0;ret[i]!="";i++){
		strSplit(ret[i],",",cang);
		for(int j=0;j<3;j++){
			ang[j] = atof(cang[j]);//char[]תdouble
		}
		num[i] = DMSToRed(ang);
	}
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
	double bhc;//�Ƕȱպϲ�
	double bhcyxz;//�Ƕȱպϲ�����ֵ
	
	/*
	//��������
	GetInt("��վ��(������)��", sta);
	GetInt("���+1���ҽ�-1��", lor);

	printf("������2����֪��:\n");
	fwj[0] = GetDMSToRed("");
	fwj[sta-1] = GetDMSToRed("");
	//�������
	//printRedToDMS("",fwj[0]);
	//printRedToDMS("",fwj[sta-1]);

	printf("������%d���۲��:\n",sta-1);
	for(i=1;i<sta;i++){
		gcj[i] = GetDMSToRed("");
	}
	//�������
	//for(i=1;i<sta;i++){
	//	printRedToDMS("",gcj[i]);
	//}

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
	*/

	FILE *fp = NULL;//�ļ�ָ��
	char buff[255];//������
	double nbuf[10] = {0};//���黺��
	fp = fopen("C:\\Users\\s505\\Desktop\\CPD\\DXJS\\Debug\\test.txt", "r");

	fgets(buff, 255, (FILE*)fp);
	sta = atof(buff);
	cout << "��վ��:" << sta << endl; 

	fgets(buff, 255, (FILE*)fp);
	StrToReds(buff, " ", nbuf);
	fwj[0] = nbuf[0];
	fwj[sta-1] = nbuf[1];
	cout << "��֪��:" << endl;
	printRedToDMS("",fwj[0]);
	printRedToDMS("",fwj[sta-1]);

	fgets(buff, 255, (FILE*)fp);
	StrToReds(buff, " ", nbuf);
	for(i=1;i<sta;i++){
		gcj[i] = nbuf[i-1];
	}
	cout << "�۲��:" << endl;
	for(i=1;i<sta;i++){
		printRedToDMS("", gcj[i]);
	}

	fgets(buff, 255, (FILE*)fp);
	StrToDoubles(buff, " ", nbuf);
	for(i=1;i<sta-1;i++){
		bc[i] = nbuf[i-1];
		dxcd += bc[i];
	}
	cout << "�߳�:" << endl;
	for(i=1;i<sta-1;i++){
		cout << bc[i] << endl;
	}

	fclose(fp);
	//�������

	cout << "�߳��ͣ�" << dxcd << endl;

	//����պϲ�
	bhc = fwj[0] - fwj[sta-1];
	for (i = 1; i < sta; i++)
	{
		printRedToDMS("", bhc);
		refreshDegWithDMS(bhc);
		bhc += gcj[i] - PI;
	}
	printRedToDMS("�պϲ",bhc);
	int baseNum[] = {0,0,40};
	bhcyxz = DMSToRed(baseNum)*sqrt(sta-1);
	printRedToDMS("�պϲ�����ֵ����",bhcyxz);
	if(bhc > bhcyxz){
		cout << "�Ƕȱպϲ�ޣ�" << endl;
		//return 0;
	}
	
	//���нǶȸ���
	jdgz[0] = -bhc / (sta - 1);
	//�����Ǹ���ֵ��ƽ������������
	for(i = 1; i < sta; i++){
		gzj[i] = gcj[i] + jdgz[0];
		fwj[i] = fwj[i-1] + gzj[i] - PI;
	}
	cout << "�����ǣ�" << endl;
	for(i=1;i<sta;i++){
		printRedToDMS("",gzj[i]);
	}
	cout << "���귽λ�ǣ�" << endl;
	for(i=0;i<sta;i++){
		printRedToDMS("",fwj[i]);
	}

	for(i=1;i<sta-1;i++){
		ZBZS(zbzl[i], bc[i], fwj[i]);
		cout << "(" << zbzl[i][0] << "," << zbzl[i][1] << ")" << endl;
	}
	


}

int main(){
	Count();
	/*
	int a1[3] = {50,32,0};
	int a2[3] = {129,27,24};
	double r1 = DMSToRed(a1);
	double r2 = DMSToRed(a2);
	double r3 = r1+r2-PI;
	printRedToDMS("",r3);//should be -36
	*/
	  return 0;
}

