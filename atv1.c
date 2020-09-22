#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Código feito por Thalyson Luan Menezes Pereira

void bolhas(int v1[], int n) {
     int i, j;
     for(i=1; i<n; i++) {
            for(j=0; j<n-i; j++) {
                if( v1[j]>v1[j+1] ) {
                    int x = v1[j];
                    v1[j] = v1[j+1];
                    v1[j+1] = x;
      }
    }
  }
}

int selmin(int v2[], int i, int n) {
int j, p = i;
    for(j=i+1; j<n; j++){
        if( v2[p]>v2[j] )
        p=j;
    }
    return p;
}

void selecao(int v2[], int n) {
    int i, k, x;
    for(i=0; i<n-1; i++) {
            k = selmin(v2,i,n);
            x = v2[i];
            v2[i] = v2[k];
            v2[k] = x;
       }
    }

int main (){
  clock_t Ticks[2];
  double tempo1, tempo2;

  int n = 1000, k, i;

  int v1[n], v2[n];

  srand(time(NULL));

  printf("\n\n");
  printf(" Adicionando randomicamente valores para o vetor 1 e para o vetor 2...  \n\n");
  for (k = 0; k < n; k ++) {
      v1[k] = rand ();
      v2[k] = rand ();
  }

  Ticks[0] = clock();
  bolhas(v1, n);
  Ticks[1] = clock();
  tempo1 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

  printf("\n\n Digite o indice do vetor que contem o valor minimo a ser ordenado por selecao: ");
  scanf("%d", &i);

  Ticks[0] = clock();
  selmin(v2,i,n);
  selecao(v2,n);
  Ticks[1] = clock();
  tempo2 = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

  printf("\n\n");
  printf("\nValores do vetor 1 ordenados por troca: \n\n");
  for (k=0; k < n; k++) {
    printf ("%d : %d \n", k,v1[k]);
  }

  printf("\nValores do vetor 2 ordenados por selecao: \n\n");
  for (k=0; k < n; k++) {
    printf ("%d : %d \n", k,v2[k]);
  }


  printf("\nTempo de execucao de ordenacao por trocas  : %g ms\n", tempo1);
  printf("\nTempo de execucao de ordenacao por selecao : %g ms\n", tempo2);

 return 0;
}
