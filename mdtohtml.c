#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include"stack.h"
#include"css.h"

#define rplc(x,y){strcpy(s[x].tag,y);s[x].size=strlen(y);}
#define nmemb 1000	//写入nmemb数目

void check(char *a){
    ;
} //检查读取字符串是否含有markdown语法

int flag[100]={0};
int fflag[100]={0}; //记录有什么tag，再写入不同css

void inite(char *a){
	memset(a,0,sizeof(a));
}	//初始化数组

struct tt{
	char tag[100];
	int size;
}s[nmemb];		//替换的标签

Stack steam;	//读取markdown字符串

void replace(){
    rplc(1,"<!DOCTYPE HTML>");
    rplc(2,"<html>");
    rplc(3,"<head>");
    rplc(4,"<meta charset=\"utf-8\">");
    rplc(5,"<meta http-equiv=\"Content-Type\" content=\"text/html\" />");
    rplc(6,"<link href=\"CSS/test.css\" rel=\"stylesheet\" type=\"text/css\" />");
    rplc(7,"<title>task</title>");
    rplc(8,"</head>");
    rplc(9,"<body>");
	rplc(10,"<h1>");	//#
	rplc(11,"</h1>");
	rplc(12,"<h2>");	//##
	rplc(13,"</h2>");
	rplc(14,"<h3>");	//###
	rplc(15,"</h3>");
	rplc(16,"<h4>");	//####
	rplc(17,"</h4");
	rplc(18,"<h5>"); //#####
	rplc(19,"</h5>");
	rplc(20,"<h6>"); //######
	rplc(21,"</h6>");
	rplc(22,"<p>"); //text
	rplc(23,"</p>");
	rplc(24,"<ol>"); //有序列表 num. space
	rplc(25,"</ol>");
	rplc(26,"<li>"); //list
	rplc(27,"</li>")
	rplc(28,"<ul>"); //* space && + space && - space
	rplc(29,"</ul>");	//无序列表
	rplc(30,"<em>"); //斜体 *text* && _text_
	rplc(31,"</em>");
	rplc(32,"<strong>"); //粗体 **text** && __text__
	rplc(33,"</strong");
	rplc(34,"<img src=\" "); //img
	rplc(35,"\" />");
	rplc(36,"</body>");
	rplc(37,"</html>");
}			//	漏写表格，记得补

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
	fp2=fopen(html2,"a+");	//准备输出 html 文件
	if(fp2==NULL){
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
	/*do{
       fgets(buffer,100,fp1);
       check(buffer);
       //printf("%s\n",buffer);
       inite(buffer);
       }while(fgetc(fp1)!= EOF);*/
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

}
