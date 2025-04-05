#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função f(x) = 2x - cos(x)
float f1_x(float x) {
    return 2 * x - cosf(x);
}

// Derivada f'(x) = 2 + sen(x)
float derivada_f1_x(float x) {
    return 2 + sinf(x);
}

// Função f(x) = e^x + (1/2)x
float f2_x(float x) {
    return expf(x) + (x / 2.0);
}

// Derivada f'(x) = e^x + 1/2
float derivada_f2_x(float x) {
    return expf(x) + 0.5;
}

// Função f(x) = 5x^4 - sen(x)
float f3_x(float x) {
    return 5 * powf(x, 4) - sinf(x);
}

// Derivada f'(x) = 20x^3 - cos(x)
float derivada_f3_x(float x) {
    return 20 * powf(x, 3) - cosf(x);
}

// Método de Newton-Raphson / Aplicação com escrita em arquivo comentada
float newtonraphson(float (*f)(float), float (*df)(float), float x0, float precisao, int max_iter/*,FILE *arquivo*/) {
    float x1, x1_anterior;
    int iteracoes = 0;
    x1_anterior = 2 * precisao;

    printf("i, xi, xi+1, precisao\n");
    //fprintf(arquivo, "i, xi, xi+1, precisao\n");
    while (fabs(x0 - x1_anterior) > precisao && iteracoes < max_iter) 
    {
        x1_anterior = x0;
        x1 = x0 - (f(x0) / df(x0));
        x0 = x1;
        iteracoes++;

        //fprintf(arquivo, "%d, %f, %f, %f\n", iteracoes, x1_anterior, x1, precisao);
        printf("%d, %f, %f, %f\n", iteracoes, x1_anterior, x1, precisao);
    }
    return x1;
}

int main()
{
    int escolha;

    
    //FILE *arquivo = fopen("newtonraphson.csv", "wt"); // posso até retirar esse trecho já
    float raiz;
    float precisao = 0.0001;
    int max_iter = 10;
    /*
    if (arquivo == NULL) 
    {
        exit(0);
        //printf("Erro ao abrir o arquivo.\n");
    }*/
    
    do
    {
        printf("\nEscolha um exercicio (6-8) ou 0 para sair:\n");
        printf("6: f(x) = 2x-cos(x)\n");
        printf("7: f(x) = e^x + (1/2)x\n");
        printf("8: f(x) = 5x⁴-sen(x)\n");
        printf("0: Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 6:
                    /*arquivo = fopen("newtonraphson.csv", "wt"); // Reabre para sobrescrever
                    if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo.\n");
                        exit(1);
                    }*/
                    raiz = newtonraphson(f1_x, derivada_f1_x, 0.3927, precisao, max_iter/*, arquivo*/);
                    printf("Raiz = %g\n", raiz);
                    //fprintf(arquivo, "Raiz,%g\n", raiz);
                    fflush(stdout);
                    //fclose(arquivo);
                break;
            case 7:                    
                    /*arquivo = fopen("newtonraphson.csv", "wt"); // Reabre para sobrescrever
                    if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo.\n");
                        exit(1);
                    }*/
                    raiz = newtonraphson(f2_x, derivada_f2_x, -0.85, precisao, max_iter/*, arquivo*/);
                    printf("Raiz = %g\n", raiz);
                    //fprintf(arquivo, "Raiz,%g\n", raiz);
                    fflush(stdout);
                    //fclose(arquivo);
                break;
            case 8:
                    /*arquivo = fopen("newtonraphson.csv", "wt"); // Reabre para sobrescrever
                    if (arquivo == NULL) {
                        printf("Erro ao abrir o arquivo.\n");
                        exit(1);
                    }*/
                    raiz = newtonraphson(f3_x, derivada_f3_x, 0.5, precisao, max_iter/*, arquivo*/);
                    printf("Raiz = %g\n", raiz);
                    //fprintf(arquivo, "Raiz,%g\n", raiz);
                    fflush(stdout);
                    //fclose(arquivo);
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }

    } while (escolha !=0);

    
    return 0;
}
