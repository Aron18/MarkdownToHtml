#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define rplc(x,y){strcpy(s[x].tag,y);s[x].size=strlen(y);}
#define nl(*fp){fputc("\n",fp);}	//往文件写入换行
#define nmemb 1000	//写入nmemb数目

struct tt{
	char tag[100];
	int size;
}s[nmemb];

void replace(){
	rplc(0,"<h1>");	//#
	rplc(1,"</h1>");
	rplc(2,"<h2>");	//##
	rplc(3,"</h2>"); 
	rplc(4,"<h3>");	//###
	rplc(5,"</h3>"); 
	rplc(6,"<h4>");	//####
	rplc(7,"</h4");
	rplc(8,"<h5>"); //#####
	rplc(9,"</h5>");
	rplc(10,"<h6>"); //######
	rplc(11,"</h6>");
	rplc(12,"") 
}
int main(){
    replace();
	char md1[100];
	char html2[100];
	FILE *fp1;
	FILE *fp2;
	//输入markdown名，输出html名
	scanf("%s",md1);
	//printf("%s\n",md1);
	scanf("%s",html2);
	//printf("%s\n",html2);
	fp1=fopen(md1,"a+");	//打开 markdown 文件
	fp2=fopen(html2,"a+");	//准备输出 html 文件
	if(fp1==NULL){
		printf("%s doesn't exist\n",md1);
		exit(0);
	}
	if(fp2==NULL){
		printf("%s doesn't exist\n",html2);
		exit(0);
	}
	/*写入函数*/
	//fwrite(s[0].tag,sizeof(s[0]),1,fp1);
	fclose(fp1);
	fclose(fp2);
}
