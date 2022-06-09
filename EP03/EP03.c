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
#define TAM_MAX 2021

int criaNumerao (int n, int num[]);
void imprimeNumerao(int num[], int tamNum);
int soma(int a[], int tamA, int b[], int tamB);
int soma(int a[], int tamA, int b[], int tamB);

int main() {
    int n1,
        n2,
        tamNum,
        a[TAM_MAX],
        b[TAM_MAX],
        tamA,
        tamB,
        i,
        opcao;
        
    printf ("Digite 0 (soma) ou 1 (soma naturais): ");
    scanf ("%d", &opcao);
    if (opcao == 0){   /* executa a opcao 0 */
        printf ("Digite o primeiro numero: ");
        scanf ("%d", &n1);
        printf ("Digite o segundo numero: ");
        scanf ("%d", &n2);

        tamA = criaNumerao (n1, a);    /* cria numerao e salva no vetor a[], devolvendo seu tamanho */
        tamB = criaNumerao (n2, b);     /* cria numerao e salva no vetor b[], devolvendo seu tamanho */
        tamNum = soma(a, tamA, b, tamB); /* soma os vetores a[] e b[] e retorna o tamanho da soma */
            
        imprimeNumerao (a, tamNum); /* imprime a soma dos numeroes */
        printf ("\n");
    }
    if (opcao == 1){   /* executa a opcao 1 */
        int k, 
            j,
            l;
        printf ("Entre com valor de n para soma dos n primeiros naturais: ");
        scanf ("%d", &n1); 
        tamA = criaNumerao (n1, b);
        i = 0;
        if (tamA == 2)    /* se numerao tiver apenas 1 casa fazer a soma de 1-10 apenas 1 vez */
            k = b[1];
        else{              
            if (b[1] == 0){  /* se a ultima casa do numerao for 0 fazer soma de 1-10 10vezes */
                k = 10;
            }
            else{           /* se a ultima casa do numerao for != 0 fazer a soma 10vezes o valor dessa casa */
                k = 10 * b[1];
            }
        }
        j = 1;
        l = 1;   /* casa em que a soma sera armazenada de acordo com a casa deciamal */
        while (tamA - 1 > 0){
            while (k > 0){
                i = i + 1;
                /* soma da dos n <= 10 primeiros numeros e armazena*/
                if (i <= 10 * k)            
                    a[l] = a[l] + i * j;  /* soma de acordo com a casa decimal do numerao */
                k = k - 1;
            }
            tamA = tamA - 1;
            j = j * 10; /* troca a casa decimal a ser somada */
            /* aumenta a quantidade de vezes que a soma da "PA" sera feita de acordo com a proxima casa decinal */
            if (b[l+1] == 0){
                k = 10 * j;
            }
            else{
                k = 10 * (b[l+1] - 1);
            }
            l = l + 1;    
        }
        /* proximo passo seria somar os vetores formados (ex.: a[1] + a[2]+...+a[tamA]) com a funçao soma */
        /* assim obtendo a soma dos numeros naturais */
        printf ("Soma dos %d primeiros naturais = ", n1);
        printf ("%d", a[1]);
    }
    return 0;
}



int criaNumerao(int n, int num[]){
    int resto,
        x,      /* usado para dividir as casas decimais do numerao */
        i;      /* tamanho do numerao */

    i = 1;
    /* define se o numerao é positivo ou negativo e armazena */
    if (n > 0) 
        num[0] = 0;
    if (n < 0) {
        n = -n;
        num[0] = 1;
    }
    /* define tamanho 1 caso numerao seja igual a 0*/
    if (n == 0)
        i = i + 1;
    resto = n;
    /* divide as casas do numerao e as armazena individualmente */
    while (resto > 0) {
        x = resto % 10;
        num [i] = x;
        resto = resto / 10;
        i = i + 1;
        }
    return (i);
}

void imprimeNumerao(int num[], int tamNum){
    int i;
    printf ("Soma: ");
    i = tamNum;
    /* imprime "-" caso o numerao seja negativo */
    if (num[0] == 1 || num[0] == 2)
        printf ("-");
    /* imprime numerao na ordem correta */
    while (i > 0){
        if (num[i] < 0)         /* troca o sinal do vetor que armazena a casa do numerao caso ele seja negativo */
            num[i] = -num[i];
        printf ("%d", num[i]);
        i = i - 1;
    }
    printf ("\n");
}

int soma(int a[], int tamA, int b[], int tamB){
    int i, 
        x,     
        j,      /* tamanho da soma */
        p;      /* armazena se a soma é positiva ou negativa */
    if (a[0] + b[0] == 0 || a[0] + b[0] == 2){ /* soma de positivo com positivo ou negativo com negativo */
        if (tamB > tamA){   /* se o vetor b  for maior (tiver mais casas) que o a */
            i = -1;
            x = 0;
            while (i < tamB){       /* soma os vetores individualmente */
                i = i + 1;
                a[i] = a[i] + b[i];
                if (x > 0){         
                    a[i] = a[i] + x;
                    x = 0;
                }
                x = a[i] / 10;      
                if (a[i] >= 10)
                    a[i] = a[i] % 10;   
            }
            if (a[tamB] == 0)        /* diminui o tamanho do vetor de acordo com os zeros a esquerda */
                j = tamB - 1;
            else
                j = tamB;
    }
        else {          /* o mesmo raciocinio do laço acima, porem tendo vetor b[] menor ou igual a a[] */
            i = 0;
            x = 0;
            while (i < tamA){
                i = i + 1;
                if (a[i] >= 10)
                    a[i] = 0;
                a[i] = a[i] + b[i];
                if (x > 0){
                    a[i] = a[i] + x;
                    x = 0;
                }
                x = a[i] / 10;
                if (a[i] >= 10)
                    a[i] = a[i] % 10;
            }
            if (a[tamA] == 0){
                j = tamA - 1;
            }
            else{
                j = tamA;
            }
        }
    }
    if (a[0] + b[0] == 1){    /* subtracao de vetores caso seja um positivo e outro negativo */
        if (a[0] < b[0] || a[0] > b[0]){    /* se a for positivo e b negativo ou vice-versa*/
            i = 1;
            if (tamB < tamA){   /* se o vetor b  for maior (tiver mais casas) que o a */
                p = 0;   
                if (a[0] > b[0])    /* a positivo e b negativo */
                    p = 1;
                while (i < tamB + 1){       /* transforma as casas do vetor b individualmente para negativo */
                    b[i] = -b[i];
                    i = i + 1;
                }
                if (b[1] == 0)       /* define tamanho igual a 1 caso o b for igual a 0 */
                    p = 1;
                if (b[tamA] == 0)       /* diminui o tamanho do vetor de acordo com os zeros a esquerda */
                    j = tamA - 1;
                else
                    j = tamA;  
            }
            if (tamB == tamA) {        /* tamanho de b igual ao de a */
                if (b[tamB - 1] > a[tamA - 1]){     /* caso o numerao b for maior que o a */
                    p = 1;
                    while (i < tamA){       
                        a[i] = -a[i];
                        i = i + 1;
                    }
                    if (a[1] == 0)      /* define tamanho igual a 1 caso o numerao a for igual a 0 */
                        p = 1;
                    if (a[tamB] == 0)       /* diminui o tamanho do vetor de acordo com os zeros a esquerda */
                        j = tamB - 1;
                    else                        
                        j = tamB;
                }
                if (b[tamB - 1] < a[tamA - 1]){         /* caso o numerao a for maior que o b */
                    /* o mesmo raciocinio do laço acima */
                    p = 0;
                    while (i < tamB + 1){
                        b[i] = -b[i];
                        i = i + 1;
                    }
                    if (b[1] == 0)
                        p = 1;
                    if (b[tamA] == 0)
                        j = tamA - 1;
                    else
                        j = tamA;
                }
            }
        }
        /* subtrai os vetores individualmente ( tendo em vista que um deles foi "negativado") */
            x = 0;
            i = 0;
            while (i < j){
                i = i + 1;     
                a[i] = a[i] + b[i];
                if (a[i] < 0){
                    x = 1;
                    a[i] = a[i] + 10;
                    a[i+1] = a[i+1] - 1;
                }
            }
            while (a[j] == 0){      /* diminui o tamanho do vetor de acordo com os zeros a esquerda */
                j = j - 1;
            }
            a[0] = p;   /* devolve positivo ou negativo para a soma do numerao e armazena em a[] */
    }
    return (j);     /* devolve o tamanho da soma dos numeroes */
}