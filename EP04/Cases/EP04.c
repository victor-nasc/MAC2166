#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAXM  100
#define MAXK  5
#define MAXP  32000
#define MAXD  100
#define MAXF  100
#define FALSE 0
#define TRUE  1



/*
Abaixo, temos o protótipo de algumas funções que você deve implementar
*/


int BuscaMarcador( int ini, char politech[MAXP], char marcador[MAXM] );
int BuscaMarcadores( int ini, char politech[MAXP],
		     int k, char marcadores[MAXK][MAXM], int *compr);
int Delta( char q[MAXP], char p[MAXP], int delta[MAXD], int desloc, int ini, int fim );
int DiferencaDeConjuntos( int delta_q[MAXD], int delta_s[MAXD], int q_menos_s[MAXD] );  
int HaIncompatibilidade( int n, char F[MAXF][MAXP], int j_p,
			  int G[MAXF], int D[MAXF][MAXD] );

/*
Você deve escrever o protótipo da função abaixo
 */
void DiametroEProbabilidades( /* preencha esse espaco */  );



/*
Você pode escrever outras funções para lhe ajudar.
Por exemplo, uma função para calcular |T(n,k,d)| pode ser útil
*/




int main() {
  char F[MAXF][MAXP];		/* matriz com a família de Politechs, um por linha */
  int np = 0;	                /* número de Politechs armazenados em F */
  int ncp = 0;			/* total de caracteres dos Politechs de F */
  int j_p = 0;			/* indice do patriarca na família */
  int L[MAXF];		        /* length (comprimento) de cada politech */
  int G[MAXF];		        /* gama, primeira ocorrência de marcador de início */
  int continua = TRUE;		/* iteração continua?  */
  char comando;			/* comando selecionado */
  char m[MAXK][MAXM];		/* marcadores de início */
  int nm = 0;	                /* número de marcadores de início */
  char M[MAXK][MAXM];		/* marcadores de fim */
  int nM = 0;	                /* número de marcadores de fim */
  int i, j, k, compr;
  int ini = 0, fim = MAXP-1;	/* extremidades do intervalo de busca de caracteristicas */
  int D[MAXF][MAXD];		/* matriz de caracteristicas com Delta( F[i] ) em cada linha D[i] */
  int diametro;			/* valor devolvido por DiametroEProbabilidade */
  double Prob_eq_diametro, Prob_le_diametro; /* valores devolvidos por DiametroEProbabilidades */
  char comentario[300];			     /* linha de comentario */

  while( continua ) {
    printf( "Digite uma letra para um comando: " );
    comando = 'q';		/* valor default de leitura se houver erro no scanf */
    do {
      scanf( " %c", &comando );
      if ( comando == '#' ) {
	scanf( "%[^\n]",comentario );
	printf("\n#%s",comentario);
      }
    } while (comando=='#');
    switch( comando ) {
    case 'p':
      printf( "\nDigite um Politech: " );
      scanf( " %[!-~]", F[np] );
      L[np] = strlen( F[np] );
      ncp += L[np];
      printf( "\nPolitech %d de comprimento %d inserido na familia, com %d caractere(s).\n",
	      np, L[np], ncp );
      G[np] = D[np][0] = MAXP;	/* calculo posterior */
      np++;
      break;
    case 'P':
      printf( "\nDigite indice do patriarca: " );
      scanf( " %d", &j_p );
      ini = 0, fim = strlen( F[j_p] ) - 1;
      printf( "\nPatriarca da familia [ %d .. %d ] eh o de numero %d e tem comprimento %d .\n",
	      0, np-1, j_p, fim + 1 );
      break;
    case 'e':
      printf( "\nExtremidades atuais do intervalo de posicoes do patriarca a ser comparado: %d %d", ini, fim );
      if ( nm > 0 )
	printf( "\nPrimeira ocorrencia de um marcador de inicio: %d",
		BuscaMarcadores( ini, F[j_p], nm, m, &compr ) );
      printf("\nDigite duas novas extremidades do intervalo de onde serao extraidas as caracteristicas\n(valores invalidos provocam uma busca automatica que use os conjuntos de marcadores): ");
      scanf( "%d %d", &ini, &fim );
      if ( !( 0 <= ini && ini <= fim && fim < L[j_p] ) ) {
	/* valores invalidos provocam uma busca automatica */
	ini = 0; fim = L[j_p];
	printf( "\nAntigo interv. de busca de caracteristicas: [ %d .. %d ].", ini, fim );	
	i = ini; k = -1;
	do {
	  /* busca marcador de início */
	  i = BuscaMarcadores( i, F[j_p], nm, m, &compr );
	  /* printf( "[ marca_ini compr =  %d %d\n", i, compr ); */
	  if ( i <= fim-compr ) {
	    i = i + compr;
	    /* busca marcador de fim */
	    j = BuscaMarcadores( i, F[j_p], nM, M, &compr );
	    /* printf( "marca_fim ] compr =  %d %d\n", j, compr ); */
	    if ( j <= fim-compr ) 
	      k = i = j + compr;
	    else if ( j == MAXP || j + compr > fim ) {
	      i = MAXP;
	      compr = 0;
	    }
	  } /* if i */
	} while ( i <= fim );
	if ( k >= 0) {
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	  fim = k;
	  ini = BuscaMarcadores( 0, F[j_p], nm, m, &compr );
	  /* para incluir mutações biológicas em regiões promotoras */
	  ini = ini < 10 ? 0 : ini-10;
	  /* printf( "ini fim len = %d %d %d\n", ini, fim, L[j_p] ); */
	}
      }
      printf( "\nNovo intervalo de busca de caracteristicas: [ %d .. %d ].\n", ini, fim );
      break;
    case 'm':
      assert( nm < MAXM );
      printf( "\nDigite um marcador de inicio: " );
      scanf( " %[!-~]", m[ nm++ ] );
      printf( "\nInserindo marcador de inicio: %s", m[ nm - 1 ] );
      printf( "  Temos %d marcador(es) de inicio.\n", nm );
      break;
    case 'M':
      assert( nM < MAXM );
      printf( "\nDigite um marcador de fim: " );
      scanf( " %[!-~]", M[ nM++ ] );
      printf( "\nInserindo marcador de fim: %s", M[ nM - 1 ] );
      printf( "  Temos %d marcador(es) de fim.\n", nM );
      break;
    case 'g':
      printf( "\nPrimeira ocorrencia de marcador de inicio (gama) de cada politech:\n%s",
	      "  i   gama" );
      for ( i = 0; i < np; i++ ) {
	G[i] = BuscaMarcadores( 0, F[i], nm, m, &compr );
	printf( "\n%3d %5d", i, G[i] );
      }
      printf("\n");
      break;
    case 'd':
      printf( "\nCaracteristicas no intervalo [ %d .. %d ]:", ini, fim );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  printf( "\nD[ %3d ] = ", i );
	  for ( j = 0; D[i][j] < MAXP; j++ )
	    printf( " %5d", D[i][j] );
	}
	else 
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf("\n");
      break;
    case 'b':
      printf( "\nDiametros e Probabilidades do conjunto de caracteristicas:" );
      printf( "\npol     n   k     d  P(diam=d) P(diam<=d)" );
      for ( i = 0; i < np; i++ )
	if ( i != j_p ) {
	  k = Delta( F[i], F[j_p], D[i], G[i] - G[j_p], ini, fim );
	  DiametroEProbabilidades( D[i], ini, fim, &diametro,
				       &Prob_eq_diametro, &Prob_le_diametro );
	  printf( "\n%3d %5d %3d %5d   %8.2e  %-8.3g",
		  i, fim - ini + 1, k, diametro, Prob_eq_diametro, Prob_le_diametro );
	}
	else
	  D[i][0] = MAXP;	/* conjunto vazio de cararacterísticas */
      printf( "\n" );
      break;
    case 'i':
      if ( HaIncompatibilidade( np, F, j_p, G, D ) )
	printf( "\nHah caracteristicas incompativeis e nao hah arvore filogenetica perfeita.\n" );
      else
	printf( "\nNao hah caracteristicas incompativeis e hah arvore filogenetica perfeita.\n" );
      break;
    default:
      printf( "\nComando invalido: %c\n", (int) comando );
    case 'q':
      continua = FALSE;
      printf( "\nObrigado, ate mais.\n" );
      break;
    }
  }
  return 0;
}







