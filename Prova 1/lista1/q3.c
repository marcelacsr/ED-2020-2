//Q3) Problema 1103 URI

#include <stdio.h>

int calcula_minutos(int h1, int m1, int h2, int m2){
     if (h2 > h1) return ((h2*60)+m2)-((h1*60)+m1);
     if ((h2 == h1) && (m1 < m2)) return ((h2*60)+m2)-((h1*60)+m1);
     if (h2 < h1) return (((h2*60)+m2)-((h1*60)+m1)+(24*60));
     if ((h2 == h1) && (m1 > m2)) return ((h2*60)+m2)-((h1*60)+m1)+(24*60);
}

int main (){
    int h1, m1, h2, m2;

    while(1){
        printf("h1 m1 h2 m2\n");
        scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
        if (h1<=0 && m1<=0 && h2<=0 && m2<=0) return 0;
        int retorno = calcula_minutos(h1, m1, h2, m2);
        printf("%d minutos de descanso - horas: %d e minutos: %d \n", retorno, retorno/60, retorno % 60);
    }    
}