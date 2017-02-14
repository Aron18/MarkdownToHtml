#define LEN 101
#define ERROR -1
#define OK 0
typedef struct Stack{
    char temp[LEN];
    int top;    //栈顶指针
}Stack;

int push(Stack *S,char e){
    if(S->top == LEN-1) //栈满
        return ERROR;
    S->top++;
    S->temp[S->top] = e;
    return OK;
}   //插入

int pop(Stack *S,char *e){
    if(S->top == -1)
        return ERROR;
    *e = S->temp[S->top];
    S->top--;
    return OK;
}   //弹出
