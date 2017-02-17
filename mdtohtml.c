#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include"stack.h"
#include"css.h"
#include"html.h"

int flag[100]={0};
int fflag[100]={0}; //记录有什么tag，再写入不同css
int i;
int count,temp;
int len;
int i1,i2,i3,i4;    //记录语法符号位置方便跳过

void inite(char *a){
    memset(a,0,sizeof(a));
}   //初始化数组

void check(char a[],FILE *fp,int len){  //计算读入字符串的长度方便分析){
    Stack steam;    //读取markdown字符串
    count=0;
    int j;
    for(;i<len+1;i++){   //i记录语法位置
        if(a[i]=='#'){
            count+=1;
            continue;
        }
        if(count!=0){
            nl(fp);
            fprintf(fp,"<h%d>",count);
            temp=count;
            count=0;
            flag[0]=1;  //flag[1] 记录是否写入已写入<h>
            break;
        }   //处理标题
        if((a[i]>='0' || a[i]<='9') && (a[i+1]=='.' && a[i+2]==' ')){
            if(flag[3]==0){
                nl(fp);
                fprintf(fp,"<ol>");
                flag[3]=1;  //flag[1] 记录是否写入已写入<ol>
            }
            if(flag[3]==1){
                nl(fp);
                fprintf(fp,"<li>");
                flag[1]=1;  //前一行写入了<li>
                flag[2]=1;  //写入了<li>，写css
            }
            i+=3;
            break;
        }   //处理有序列表
        if((a[i]=='*' || a[i]=='+' || a[i]=='-') && a[i+1]==' '){
            if(flag[6]==0){
                nl(fp);
                fprintf(fp,"<ul>");
                flag[6]=1;  //flag[1] 记录是否写入已写入<ol>
            }
            if(flag[6]==1){
                nl(fp);
                fprintf(fp,"<li>");
                flag[4]=1;  //前一行写入了<li>
                flag[5]=1;  //写入了<li>，写css
            }
            i+=3;
            break;
        }
        if(a[i]=='>'){
            if(flag[7]==0){
                nl(fp);
                fprintf(fp,"<div class=\"blockquote\">");
                flag[7]=1;  //写入了引用
                flag[8]=1;  //写css
                i++;
                break;
                }
            }
        if((a[i]=='*' && a[i+1]=='*')||(a[i]=='_' && a[i+1]=='_')){
            flag[9]=1;  //等待匹配，匹配时lag[9]==2
            i1=i;   //记录位置
            for(j=i+1;j<len;++j){
                if((flag[9]==1 )&&((a[j]=='*'&& a[j+1]=='*')||(a[i]=='_' && a[i+1]=='_'))){
                    flag[9]=2;  //flag[9]==2
                    i2=j;   //记录位置
                    break;
                    }
                }
            break;
            }
        if(a[i]=='!' && a[i+1]=='['){
            i1=i+1;
            flag[10]=1; // 等待匹配，img标签
            for(j=i+2;j<len;j++){
                if(flag[10]==1 && a[j]==']' && a[j+1]=='('){
                    i2=j;
                    flag[10]=2;     // 等待匹配
                   }
                if(flag[10]==2 && a[j]==')'){
                    i3=j;
                    flag[10]=3;    //匹配
                    nl(fp);
                    flag[11]=1; //写css
                    fprintf(fp,"<img src=\"");
                    break;
                    }
                }
                break;
            }
        }
} //检查读取字符串是否含有markdown语法

void match(FILE *fp,int a[]){
    if(a[0]==1){
        fprintf(fp,"</h%d>",temp);
        count=0;
        a[0]=0;
    }
    if(a[1]==0 && a[3]==1){
        nl(fp);
        fprintf(fp,"</ol>");
        a[3]=0;
    }
    if(a[1]==1){
        fprintf(fp,"</li>");
        a[1]=0;
    }
    if(a[4]==0 && a[6]==1){
        nl(fp);
        fprintf(fp,"</ul>");
        a[6]=0;
    }
     if(a[4]==1){
        fprintf(fp,"</li>");
        a[4]=0;
    }
    if(a[7]==1){
        fprintf(fp,"</div>");
        a[7]=0;
    }
    if(a[9]==2){
        fprintf(fp,"</strong>");
        a[9]=0;
    }
    if(a[10]==3){
        fprintf(fp,"\">");
        a[10]=0;
    }
}

int main(){
    replace();
    int h,k;
    char md1[LEN];
    char html2[LEN];
    char buffer[LEN];
    inite(buffer);
    FILE *fp1;  //指向markdown
    FILE *fp2;  //指向html
    FILE *fp3;  //指向css
    //输入markdown名，输出html名
    printf("plz enter that file route you want to transfer for:\t");
    scanf("%s",md1);
    printf("plz enter the output file name \t");
    scanf("%s",html2);
    if((fp1=fopen(md1,"r"))==NULL){ //打开 markdown 文件
        printf("%s doesn't exist\n",md1);
        exit(0);
    }
    if((fp2=fopen(html2,"a+"))==NULL){  //准备输出 html 文件
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
    while(fgets(buffer,100,fp1)){
        len=strlen(buffer);
        i=0;
        check(buffer,fp2,len);
        if(flag[9]==2){
            nl(fp2);
            fprintf(fp2,"<p>");
            for(k=0;k<len;k++){
                if(k==i1){
                    fprintf(fp2,"<strong>");
                    k++;
                    continue;
                }
                else if(k==i2){
                    match(fp2,flag);
                    k++;
                    i=k;
                    check(buffer,fp2,len);
                    continue;
                }
                else if(k!=i1 || k!=i1+1 || k!= i2 || k!=i2+2){
                    fprintf(fp2,"%c",buffer[k]);
                }
            }
        fprintf(fp2,"</p>");
        }
        if(flag[10]==3){
            for(k=i2+2;k<len;k++){
                if(k==i3){
                    match(fp2,flag);
                    break;
                }
                fprintf(fp2,"%c",buffer[k]);
            }
        }
        else{
            for(;i<len;i++){
                fprintf(fp2,"%c",buffer[i]);
                }
            //printf("%s\n",buffer);
            match(fp2,flag);
            }
        inite(buffer);
    }
    body(fp3);
    if(flag[8]){
        blockquote(fp3);
    }
    if(flag[11]=1){
        img(fp3);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
