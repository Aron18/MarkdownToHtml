void sp(int n,FILE *fp){
    int i;
    for(i=0;i<n;i++)
        fprintf(fp,"\t");
}   //写入n个制表符，4个空格

void nl(FILE *fp){
    fprintf(fp,"\n\r");
    }	//写入换行

void ft(char *a,FILE *fp,int n){
	nl(fp);
	sp(n,fp);
	fprintf(fp, a);
}	//a写入字符串 fp写入文件指针 n写入多少个制表符

char b1[] = {"body{"};
char b2[] = {"width : 100%;"};
char b3[] = {"display : table;"};
char b4[] = {"}"};
char b5[] = {"p{"};
char b6[] = {"font-size : 2em;"};
char b7[] = {"color: #484848"};
char b8[] = {"border-bottom: 2px solid #bbb;"};
char b9[] = {"margin : 2em;"};
char b10[] = {"img{"};
char b11[] = {"width : 0.6em;"};
char b12[] = {"height : 0.4em;"};
char b13[] = {".blockquote{"};
char b14[] = {"border-left:3px solid rgb(73, 72, 75);"};
char b15[] = {"margin-left: 1em;"};
char b16[] = {"padding-left: 0.5em;"};
char b17[] = {"background-color:rgb(204,198,198);"};
char b18[] = {"background-color:rgb(238,243,163);"};

void body(FILE *fp){
	fwrite(b1,sizeof(b1),1,fp);
	ft(b2,fp,1);
	ft(b3,fp,1);
	ft(b18,fp,1);
	ft(b4,fp,0);
}

void p(FILE *fp){
	nl(fp);
	ft(b5,fp,0);
	ft(b6,fp,1);
	ft(b7,fp,1);
	ft(b8,fp,1);
	ft(b9,fp,1);
	ft(b4,fp,0);
}

void img(FILE *fp){
	nl(fp);
	ft(b10,fp,0);
	ft(b11,fp,1);
	ft(b12,fp,1);
	ft(b4,fp,0);
}
void blockquote(FILE *fp){
	nl(fp);
	ft(b13,fp,0);
	ft(b14,fp,1);
	ft(b15,fp,1);
	ft(b16,fp,1);
	ft(b17,fp,1);
	ft(b4,fp,0);
}
