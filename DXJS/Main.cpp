#include <stdio.h>
#include <iostream.h>
#include <math.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944 

//�������뵽����
int Round(float num){
	return (int)(num+0.5);
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
	int sec = red * 180 * 3600 / PI;
	angle[0] = sec/3600;
	angle[1] = (sec%3600)/60;
	angle[2] = Round(sec%60);
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
	printf("%s:(%d,%d,%d)\n",word,angle[0],angle[1],angle[2]);
}

//����ȷ���
void printRedToDMS(char word[], float red){
	int angle[3];
	RedToDMS(red, angle);
	printDMS(word, angle);
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
	
	//��������
	GetInt("��վ��(������)��", sta);
	GetInt("���+1���ҽ�-1��", lor);

	printf("������2����֪��:\n");
	fwj[0] = GetDMSToRed("");
	fwj[sta-1] = GetDMSToRed("");


	printf("������%d���۲��:\n",sta-1);
	for(i=1;i<sta;i++){
		gcj[i] = GetDMSToRed("");
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
	bhc = fwj[0];
	for (i = 1; i < sta; i++)
	{
		bhc += gcj[i];
		bhc -= PI;
	}
	bhc -= fwj[sta-1];
	printRedToDMS("�պϲ�",bhc);


}

int main(){
	Count();
	return 0;
}

