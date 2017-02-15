#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include"stack.h"
#include"css.h"
#include"html.h"

int flag[100]={0};
int fflag[100]={0}; //记录有什么tag，再写入不同css

void inite(char *a){
	memset(a,0,sizeof(a));
}	//初始化数组

void check(char a[],FILE *fp){
	int i,j,count=0;
	char tmp;
    int len = strlen(a);	//计算读入字符串的长度方便分析
    Stack steam;	//读取markdown字符串
    for(i=0;i<len+1;i++){
    	if(a[i]=='#'){
    		count++;
    		printf("%d#\n",count);
    		continue;
    	}
    	if(count!=0 && a[i]!='#'){
    		nl(fp);
    		fprintf(fp,"<h%d>",count);
    		flag[0]=1;	//flag[1] 记录是否写入已写入<h>
    		count=0;
    	}	//处理标题
    	if((a[i]>='0' || a[i]<='9') && (a[i+1]=='.' && a[i+2]==' ')){
    		if(flag[1]==0){
                nl(fp);
                fprintf(fp,"<ol>");
                flag[1]=1;	//flag[1] 记录是否写入已写入<ol>
 			}
    		nl(fp);
    		fprintf(fp,"<li>");
    		flag[2]=1;
    	}	//处理有序列表
    }
} //检查读取字符串是否含有markdown语法

int main(){
    replace();
    int i;
	char md1[LEN];
	char html2[LEN];
	char buffer[LEN];
	inite(buffer);
	FILE *fp1;	//指向markdown
	FILE *fp2;	//指向html
	FILE *fp3;	//指向css
	//输入markdown名，输出html名
	printf("plz enter that file route you want to transfer for:\t");
	scanf("%s",md1);
	printf("plz enter the output file name \t");
	scanf("%s",html2);
	if((fp1=fopen(md1,"r"))==NULL){	//打开 markdown 文件
		printf("%s doesn't exist\n",md1);
		exit(0);
	}
	if((fp2=fopen(html2,"a+"))==NULL){	//准备输出 html 文件
		printf("%s doesn't exist\n",html2);
		exit(0);
	}
	fp3=fopen("CSS/test.css","a+");
    for(i=1;i<10;i++){
        if(i==1)
            fprintf(fp2,s[i].tag);
        else{
            ft(s[i].tag,fp2,1);
        }
    }
	do{
       fgets(buffer,100,fp1);
       check(buffer,fp2);
       //printf("%s\n",buffer);
       inite(buffer);
       }while(fgetc(fp1)!= EOF);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
