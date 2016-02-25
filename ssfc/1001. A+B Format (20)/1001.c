//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	int a,b,sum=0;
//	scanf("%d %d",&a,&b);
//	sum=a+b;
//	if(abs(sum)<1000) printf("%d\n",sum);
//	else if(1000<=abs(sum) && abs(sum)<1000000){
//		if(sum>0) printf("%d,%03d",sum/1000,sum%1000);
//		else printf("-%d,%03d",-sum/1000,-sum%1000);
//	}else if(abs(sum)>=1000000){
//		if(sum>0) printf("%d,%03d,%03d",sum/1000000,sum/1000%1000,sum%1000);
//		else printf("-%d,%03d,%03d",-sum/1000000,-sum/1000%1000,-sum%1000);
//	}
//	return 0;
//} 
#include<stdio.h>
#include<stdlib.h>
int main(){
	int a,b,asum=0;
	scanf("%d %d",&a,&b);
	asum=abs(a+b);
	if(asum<1000) printf("%d\n",a+b);
	else if(1000<=asum && asum<1000000){
		if(a+b<0) printf("-");
		printf("%d,%03d",asum/1000,asum%1000);
	}else if(asum>=1000000){
		if(a+b<0) printf("-");
		printf("%d,%03d,%03d",asum/1000000,asum/1000%1000,asum%1000);
	}
	return 0;
} 
/*
-1000000 9
*/
