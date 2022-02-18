#include <stdio.h>
#include <stdlib.h>

int main() {
	int *pai, *resultado, *aux;
    int num_casos, N, M, x, y, i, j = 0, max;
    scanf("%d", &num_casos);
    resultado = (int*) malloc( num_casos * sizeof(int) );
    while (num_casos--) {
        scanf("%d %d", &N, &M);
        pai = (int*) malloc( N * sizeof(int) );

        //inicializando vetor
        for (i = 0; i < N; i++)
            pai[i] = i;
        

        for (i = 0; i < M; i++) {
            scanf("%d %d", &x, &y);
            x--;
            y--;
            while (pai[x] != x)
		        x = pai[x];
	        while (pai[y] != y)
		        y = pai[y];

            pai[x] = y;
        }

        max = 0;
        aux = (int*) malloc( N * sizeof(int) );
        for (i = 0; i < N; i++){
        	x = i;
        	while (pai[x] != x)
		        x = pai[x];
		    y = ++aux[x];
            if(max < y){
                max = y;
            }
        }
        resultado[j++] = max;
        free(pai);
        free(aux);
    }

    //Imprimindo resultado
    for (i = 0; i < j; i++)
        printf("%d\n", resultado[i]);

    free(resultado);
    return 0;
}
