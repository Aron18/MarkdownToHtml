#define LEN 100
#define ERROR -1
#define OK 0
typedef struct Stck{
    char buffer[LEN];
    int top;    //栈顶指针
}Stack;

int Push(Stack *S,char e){
    if(S->top == LEN-1) //栈满
        return ERROR;
    S->top++;
    S->buffer[S->top] = e;
    return OK;
}

int Pop(Stack *S,char *e){
    if(S->top == -1)
        return ERROR;
    *e = S->buffer[S->top];
    S->top--;
    return OK;
}
