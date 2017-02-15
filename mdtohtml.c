#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include"stack.h"
#include"css.h"
#include"html.h"

int flag[100]={0};
int fflag[100]={0}; //记录有什么tag，再写入不同css
int i,j;
int count,temp;
int len;

void inite(char *a){
	memset(a,0,sizeof(a));
}	//初始化数组

void check(char a[],FILE *fp,int len){	//计算读入字符串的长度方便分析){
    Stack steam;	//读取markdown字符串
    count=0;
    for(i=0;i<len+1;i++){   //记录语法位置
    	if(a[i]=='#'){
    		count++;
    		printf("%d#\n",count);
    		continue;
    	}
    	if(count!=0 && a[i]!='#'){
    		nl(fp);
    		fprintf(fp,"<h%d>",count);
    		temp=count;
    		count=0;
    		flag[0]=1;	//flag[1] 记录是否写入已写入<h>
    		break;
    	}	//处理标题
    	if((a[i]>='0' || a[i]<='9') && (a[i+1]=='.' && a[i+2]==' ')){
    		if(flag[3]==0){
                nl(fp);
                fprintf(fp,"<ol>");
                flag[3]=1;	//flag[1] 记录是否写入已写入<ol>
 			}
 			if(flag[3]==1){
                nl(fp);
                fprintf(fp,"<li>");
                flag[1]=1;  //前一行写入了<li>
                flag[2]=1;  //写入了<li>
 			}
 			continue;
    	}	//处理有序列表
    }
} //检查读取字符串是否含有markdown语法

void match(FILE *fp,int a[]){
    if(a[0]==1){
        fprintf(fp,"<h%d>",temp);
        count=0;
        a[0]=0;
    }
    if(a[1]==1){
        fprintf(fp,"</li>");
        a[1]=0;
    }
    if(a[1]==0 && a[3]==1){
        nl(fp);
        fprintf(fp,"</ol>");
        a[3]=0;
    }
}

int main(){
    replace();
    int h,k;
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
    for(h=1;h<10;h++){
        if(h==1)
            fprintf(fp2,s[h].tag);
        else{
            ft(s[h].tag,fp2,1);
        }
    }
	do{
       fgets(buffer,100,fp1);
       len=strlen(buffer);
       check(buffer,fp2,len);
       //printf("%s\n",buffer);
       match(fp2,flag);
       inite(buffer);
            }while(fgetc(fp1)!= EOF);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
