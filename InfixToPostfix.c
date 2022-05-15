#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int prior(char c) {
    switch(c) {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}


char *toPostfix(char* infix) {
    #define pop() stack[stackTop--]
    #define push(e) stack[++stackTop]=e

    int stacklen=strlen(infix), stackTop=-1, postTop=0;
    char stack[stacklen], *postfix=malloc(stacklen);

    push('#');
    
    for(int i=0; i<strlen(infix); i++) {
        char cur=infix[i];
        
        if(cur=='\\') {
            postfix[postTop++]=cur;
            i++;
            continue;
        }
        
        if(cur=='(')
            push(cur);
        else
            if(isalnum(cur))
                postfix[postTop++]=cur;
            else
                if(cur==')') {
                    while(stack[stackTop]!='(')
                        postfix[postTop++]=pop();
                    stackTop--;
                }else{
                    while(prior(stack[stackTop])>=prior(cur))
                        postfix[postTop++]=pop();
                    push(cur);
                }
    }
    
    while(stack[stackTop]!='#')
        postfix[postTop++]=pop();
        
    postfix[postTop]='\0';

    #undef pop
    #undef push
    return postfix;
}



int main() {
    char *expr="A*(B+C)-D";
    char *res=toPostfix(expr);
    

    printf("%s -> %s\n", expr, res);
}

