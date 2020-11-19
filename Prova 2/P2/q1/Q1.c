#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP.c"

int aval(char *str){
  int i = 0, ind_ops = 0, ind_vals = 0;
  char ops[strlen(str)];
  int vals[strlen(str)];
  
  while (str[i]){
    if ((str[i] == ' ') || (str[i] == '(')) i++;
    else if (str[i] == '+') ops[ind_ops++] = str[i++];
    else if ((str[i] == '-') && (str[i + 1] == ' ')) ops[ind_ops++] = str[i++];
    else if (str[i] == '*') ops[ind_ops++] = str[i++];
    else if (str[i] == '/') ops[ind_ops++] = str[i++];
    else if (str[i] == '%') ops[ind_ops++] = str[i++];
    else if (str[i] == ')'){
      i++;
      char op = ops[--ind_ops];
      int v = vals[--ind_vals];
      if (op == '+') v = vals[--ind_vals] + v;
      else if (op == '-') v = vals[--ind_vals] - v;
      else if (op == '*') v = vals[--ind_vals] * v;
      else if (op == '/') v = vals[--ind_vals] / v;
      else if (op == '%') v = vals[--ind_vals] % v;
      vals[ind_vals++] = v;
    }
    else{
      int j = 0;
      char num[strlen(str)];
      while(str[i] != ' ') num[j++] = str[i++];
      num[j] = '\0';
      vals[ind_vals++] = atoi(num);
    } 
  }
  int resp = vals[--ind_vals];
  return resp;
}

int main(void){
  while(1){
    char str[1001];
    scanf(" %1000[^\n]", str);
    if(!strcmp(str, "FIM")) return 0;
    //int resp = aval(str);    
    //printf("%s = %d\n", str, resp);
  }
}
