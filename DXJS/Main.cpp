#include <stdio.h>
#include <math.h>

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
void GetInt(char word[], int *data){
	printf("%s",word);
	scanf("%d",data);
}
//���븡����
void GetDouble(char word[], double *data){
	printf("%s",word);
	scanf("%lf",data);
}
//�ȷ���ת��
int GetSec(int deg[]){
	return deg[2] + deg[1]*60 + deg[0]*3600;
}
//��ת�ȷ���
void GetDeg(int sec, int ret[]){
	//��鷶Χ
	if(sec >= 360*60*60){
		sec -= 360*60*60;
	}else if(sec < 0){
		sec += 360*60*60;
	}
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

//����պϵ���
void Count(){
	int i;
	int sta;//��վ��(������)
	int lor;//��ǻ��ҽ�
	int gcj[10][3];//�۲��
	int jdgz[10][3];//�Ƕȸ���ֵ
	int gzj[10][3];//������Ƕ�
	int fwj[10][3];//��λ��
	double zb[10][2];//����
	double zbzl[10][2];//��������
	double zbgz[10][2];//�������
	double gzzl[10][2];//����������
	double bc[11];//�߳�
	
	double dxcd = 0;//���߳���
	double int[3] = 0;//�Ƕȱպϲ�
	
	//��������
	GetInt("��վ��(������)��", &sta);
	GetInt("���+1���ҽ�-1��", &lor);

	printf("������2����֪��:\n");
	GetDMS("", &fwj[0]);
	GetDMS("", &fwj[sta-1]);


	printf("������%d���۲��:\n",sta-1);
	for(i=0;i<sta-1;i++){
		GetDMS("", &gcj[i]);
	}

	printf("������2����֪����:\n");
	GetXY("", &zb[0]);
	GetXY("", &zb[sta-2]);

	printf("������%d���߳�:\n",sta-2);
	for(i=1;i<sta-1;i++){
		GetDouble("", &bc[i]);
		dxcd += bc[i];
	}


}

int main(){
	Count();
	return 0;
}

