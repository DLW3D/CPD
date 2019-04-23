#include <stdio.h>
//ÊäÈë¶È·ÖÃë
void GetDMS(char word[], int angle[]){
	printf("%s",word);
	scanf("%d,%d,%d",&angle[0],&angle[1],&angle[2]);
	//¼ì²éÊäÈë
	if(angle[0]>=360){
		angle[0] -= 360;
	}else if(angle[0]<0){
		angle[0] += 360;
	}
	if(angle[2]>=60 || angle[2]<0 || angle[1]>=60 || angle[1]<0){
		printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë\n");
		GetDMS(word, angle);
	}
}
//¶È·ÖÃë×ªÃë
int GetSec(int deg[]){
	return deg[2] + deg[1]*60 + deg[0]*3600;
}
//Ãë×ª¶È·ÖÃë
void GetDeg(int sec, int ret[]){
	//¼ì²é·¶Î§
	if(sec >= 360*60*60){
		sec -= 360*60*60;
	}else if(sec < 0){
		sec += 360*60*60;
	}
	//×ª»»
	ret[0] = sec/3600;
	ret[1] = (sec%3600)/60;
	ret[2] = (sec%60);
}
//Êä³ö¶È·ÖÃë
void printDEG(char word[], int deg[]){
	printf("%s:(%d,%d,%d)\n",word,deg[0],deg[1],deg[2]);
}

//¼ÆËãÒ»²â»Ø½Ç
void Count(){
	int i=0;
	int l1[3], l2[3], r1[3], r2[3];
	int sl1, sl2, sr1, sr2;
	int l[3],r[3],a[3],d[3];
	GetDMS("ÅÌ×óA:",l1);
	GetDMS("ÅÌ×óB:",l2);
	GetDMS("ÅÌÓÒB:",r2);
	GetDMS("ÅÌÓÒA:",r1);
	sl1 = GetSec(l1);
	sl2 = GetSec(l2);
	sr2 = GetSec(r2);
	sr1 = GetSec(r1);
	GetDeg(sl2-sl1, l);
	GetDeg(sr2-sr1, r);
	GetDeg((GetSec(l)+GetSec(r))/2, a);
	GetDeg(GetSec(r)-GetSec(l), d);
	printDEG("ÅÌ×ó",l);
	printDEG("ÅÌÓÒ",r);
	printDEG("²â»Ø",a);
	printDEG("°ë²â»Ø½Ç²î",d);
}

int main(){
	Count();

	return 0;
}

