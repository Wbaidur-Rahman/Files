#include<bits/stdc++.h>
using namespace std;

int top=-1,stk[201],mxstk=200;
string p="12,56,5,3,-,/,+";

void push(int item)
{
    if(top==mxstk) {printf("Stack Overflow\n"); return;}
    top++;
    stk[top]=item;
}

void pop()
{
    if(top==0) {printf("Stack Underflow\n"); return;}
    top--;
}

int isdgt(char c)
{
    string s="0123456789";
    for(int i=0;s[i];i++)
        if(c==s[i]) return 1;
    return 0;
}

int operate(char c,int x,int y){
    if(c=='+') return x+y;
    else if(c=='-') return x-y;
    else if(c=='/') return x/y;
    else if(c=='*') return x*y;
    else if(c=='^') return pow(x,y);
}

void postfix(){
    for(int i=0;p[i];i++){
        if(p[i]==',') continue;
        string s="";
        if(isdgt(p[i])){
            while(p[i]!=',') {s+=p[i]; i++;}
            int x=stoi(s);
            push(x);
        }

        else{
               stk[top-1]=operate(p[i],stk[top-1],stk[top]);
                pop();
            }
    }
}

int main(){
   while(1){
    printf("Please Enter the Postfix Expression\n");
    cin>>p;
    postfix();
    cout<<"Result is "<<stk[top]<<"\n";}
}
