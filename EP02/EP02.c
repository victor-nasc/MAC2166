/*
  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES
  DESSE EP E QUE PORTANTO NÃO CONSTITUEM DESONESTIDADE ACADÊMICA
  OU PLÁGIO.  
  DECLARO TAMBÉM QUE SOU RESPONSÁVEL POR TODAS AS CÓPIAS
  DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO E
  DESONESTIDADE ACADÊMICA SERÃO TRATADOS SEGUNDO OS CRITÉRIOS
  DIVULGADOS NA PÁGINA DA DISCIPLINA.
  ENTENDO QUE EPS SEM ASSINATURA NÃO SERÃO CORRIGIDOS E,
  AINDA ASSIM, PODERÃO SER PUNIDOS POR DESONESTIDADE ACADÊMICA.

  Nome : Victor Nascimento Ribeiro
  NUSP : 12513849
  Turma: 01
  Prof.: Alair Pereira do Lago

  Referências: Com exceção das rotinas fornecidas no enunciado
  e em sala de aula, caso você tenha utilizado alguma refência,
  liste-as abaixo para que o seu programa não seja considerado
  plágio ou irregular.
  
  Exemplo:
  - O algoritmo Quicksort foi baseado em
  http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html
*/

#include <stdio.h>
#define TRUE 1 
#define FALSE 2 

void PrimeiraParte ( int m, int a, int c, int r_0, int n, int r , int f, int i, int N, int k, int fmax, int fmin, int j, int d, int fmax_linha, int fmin_linha ) {;
    printf ("Digite parametros n, k, N, m, a, c, r_0:");
    printf ("\n");
    scanf ("%d %d %d %d %d %d %d", &n, &k, &N, &m, &a, &c, &r_0 );
    printf ("Recorrencia   r <-- ( r x %d + %d ) mod %d   a partir da semente %d.", a, c, m, r_0);
    printf ("\n");
    printf ("As %d sequencias de %d sorteios (com repeticao) em [ 1 .. %d ] e seus diametros:", N, k, n);  
    printf ("\n");
    i = 0;
    j = 0;
    fmax = 0;
    fmin = 99999;  /* maior numero possivel com 5 digitos */
    fmin_linha = 99999;
    fmax_linha = 0;
    while (i < N){  /* contagem para no maximo N linhas */
        while (j < k){ /* contagem para no maximo k colunas */
            r = (a * r_0 + c) % m;
            f = (r*n)/m + 1;
            printf ("%5d ", f);
            j = j+1;
                if (f > fmax)
                    fmax = f;
                if (f < fmin)
                    fmin = f;
                if (f > fmax_linha)
                    fmax_linha = f;
                if (f < fmin_linha)
                    fmin_linha = f;
            r_0 = r;
            d = (fmax_linha - fmin_linha) + 1;
        }
        printf ("  -> ");
        printf ("%5d", d);
        d = 0;
        printf ("\n");
        fmin_linha = 99999;
        fmax_linha = 0;
        j = 0;
        i = i + 1;
    }


}


int main (){

    printf ("Digite a parte desejada: 1 para primeira; 2 para segunda.");
    printf ("\n");
    int parte_desejada, primeira, segunda, h;
    primeira = 1;
    segunda = 2;
    scanf ( "%d", &parte_desejada );
    if (parte_desejada == primeira)
        primeira = TRUE;
    else
        primeira = FALSE;

    int m, a, c, r_0, n, r ,f, i, N, k, fmax, fmin, j, d, fmax_linha, fmin_linha;
    if (primeira == TRUE )
        PrimeiraParte (  m, a, c, r_0, n, r , f, i, N, k, fmax, fmin, j, d, fmax_linha, fmin_linha );
    if (primeira == FALSE )
        printf ("Digite parametros n, d:");


}



