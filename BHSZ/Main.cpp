#include <stdio.h>
#include <math.h>

//����
void GetInt(char word[], int *data){
	printf("%s",word);
	scanf("%d",data);
}
void GetDouble(char word[], double *data){
	printf("%s",word);
	scanf("%lf",data);
}

//����պ�ˮ׼
void Count(){
	int sta;//��վ��
	GetInt("�������վ��:",&sta);
	int i;
	double start = 0;//��ʼ��߳�
	double dh[10] = {0};//�߲�
	double dd[10] = {0};//����
	int gz[10] = {0};//������mm
	double ddh[10] = {0};//������߲�
	double gc[11] = {0};//�߳�

	//��������
	GetDouble("��������ʼ��߳�:",&start);
	printf("������%d���߲�:\n",sta);
	for(i=0;i<sta;i++){
		GetDouble("",&dh[i]);
	}
	printf("������%d������:\n",sta);
	for(i=0;i<sta;i++){
		GetDouble("",&dd[i]);
	}

	//����պϲ�
	double Eh = 0;//�պϲ����
	for(i=0;i<sta;i++){
		Eh += dh[i];
	}
	int Ch = (int)Eh*1000;//�պϲ�
	double Ed = 0;//�ܳ���
	for(i=0;i<sta;i++){
		Ed += dd[i];
	}
	printf("�պϲ�Ϊ%dmm������ֵΪ%dmm��", (int)Ch, (int)40*sqrt(Ed));
	if(Ch > 24) {
		printf("����");
		return;//����
	}
	//���������
	gc[0] = start;
	for(i=0;i<sta;i++){
		gz[i] = (int)-Ch * dd[i] / Ed;//���������
		ddh[i] = dh[i] + gz[i]/1000;//���������߲�
		gc[i+1] = gc[i] + ddh[i];//����߳�
	}

	for(i=0;i<sta+1;i++){
		printf("\n\n");
		printf("%.4f,",gc[i]);
	}
}

int main(){
	Count();
	return 0;
}

