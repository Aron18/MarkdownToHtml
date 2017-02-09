#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include"stack.h"
#include"css.h"

#define rplc(x,y){strcpy(s[x].tag,y);s[x].size=strlen(y);}
#define nmemb 1000	//写入nmemb数目

void check(){
    ;
} //检查读取字符串是否含有markdown语法

int flag[100]={0}; 	//记录有什么tag，再写入不同css

void inite(char *a){
	memset(a,0,sizeof(a));
}	//初始化数组

struct tt{
	char tag[100];
	int size;
}s[nmemb];		//替换的标签

Stack steam;	//读取markdown字符串

void head(FILE *fp){
    char a1[] = {"<!DOCTYPE HTML>"};
    char a2[] = {"<html>"};
    char a3[] = {"<head>"};
    char a4[] = {"<meta charset=\"utf-8\">"};
    char a5[] = {"<meta http-equiv=\"Content-Type\" content=\"text/html\" />"};
    char a6[] = {"<link href=\"CSS/test.css\" rel=\"stylesheet\" type=\"text/css\" />"};
    char a7[] = {"<title>task</title>"};
    char a8[] = {"</head>"};
    char a9[] = {"<body>"};
    fwrite(a1,sizeof(a1),1,fp);
    nl(fp);
    ft(a2,fp,1);
    ft(a3,fp,2);
    ft(a4,fp,2);
    ft(a5,fp,2);
    ft(a6,fp,2);
    ft(a7,fp,1);
    ft(a8,fp,1);
    fwrite(a9,sizeof(a9),1,fp);
}
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
	rplc(12,"<p>"); //text
	rplc(13,"</p>");
	rplc(14,"<ol>"); //有序列表 num. space
	rplc(15,"</ol>");
	rplc(16,"<li>"); //list
	rplc(17,"</li>")
	rplc(18,"<ul>"); //* space && + space && - space
	rplc(19,"</ul>");	//无序列表
	rplc(20,"<em>"); //斜体 *text* && _text_
	rplc(21,"</em>");
	rplc(22,"<strong>"); //粗体 **text** && __text__
	rplc(23,"</strong");
	rplc(24,"<img src=\" "); //img
	rplc(25,"\" />");
}			//	漏写表格，记得补

int main(){
    replace();
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
	fp2=fopen(html2,"wt+");	//准备输出 html 文件
	if(fp2==NULL){
		printf("%s doesn't exist\n",html2);
		exit(0);
	}
	fp3=fopen("CSS/test.css","wt+");
	head(fp2);

	do{
       fgets(buffer,100,fp1);
       check();
       //printf("%s\n",buffer);
       inite(buffer);
       }while(fgetc(fp1)!= EOF);

	/*写入函数*/
	//fwrite(s[24].tag,sizeof(s[24]),1,fp2);
	//nl(fp1);
	//fwrite(s[22].tag,sizeof(s[23]),1,fp2);
	fclose(fp1);
	fclose(fp2);
}
