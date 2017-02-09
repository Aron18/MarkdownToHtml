void sp(int n,FILE *fp){
    int i;
    for(i=0;i<n;i++)
        fprintf(fp,"\t");
}   //写入n个制表符，4个空格

void nl(FILE *fp){
    fprintf(fp,"\r\n");
    }	//写入换行

void fwrte(char *a,FILE *fp,int n=1){
	nl(fp);
	sp(n,fp);
	fwrite(a,sizeof(a),1,fp);
}	//a写入字符串 fp写入文件指针 n写入多少个制表符
 
char b1[] = {"body{"};
char b2[] = {"width : 100%;"};
char b3[] = {"display : table;"};
char b4[] = {"}"};

void body(FILE *fp){
	fwrite(b1,sizeof(b1),1,fp);
	fwrte(b2,fp);
	fwrte(b3,fp);
	fwrte(b4,fp);
}

void 