#include <stdio.h>
#include <math.h>

float anterior;
float fxanterior;
float posterior;
float fxposterior;

float f1(float x) {
    return (x * x * x) - (x * x) - 1;
}

float f2(float x) {
    return (expf(-x)) * ((x - 1) / 2);
}

float f3(float x) {
    return (x * x) - x + sinf(5 * x);
}

float f4(float x) {
    return (x * x) + 1.95 * x - 2.09;
}

float f5(float x) {
    return x - 3 - powf(x, -x);
}

int buscainversao(float inicio, float fim, float (*f)(float))
{
    float x = inicio;
    float fx = 0.0;

    printf("----------------------------------\n");
    printf("|  x        | f(x)                |\n");
    printf("----------------------------------\n");
    while(x <= fim)
    {
        fx = f(x);

        if(fx < 10.0)
        {	    
            printf("| %+f | %+f          |\n", x, fx);
        }

        if((fx >= 10.0) && (fx < 100.0))
        {
            printf("| %+f | %+f         |\n", x, fx);     
        }	

        if(fx >= 100.0)
        {
            printf("| %+f | %+f        |\n", x, fx);     
        }	    

        if(x == inicio)
        {
            anterior = x;
            fxanterior = fx;
        }

        if(x != inicio) 
        {
            posterior = x;
            fxposterior = fx;
            if((fxanterior < 0.0) && (fxposterior >= 0.0))
            {
                printf("----------------------------------\n"); 
                return(0);
            }
            if(fxanterior != fxposterior)
            {
            anterior = x;
            fxanterior = fx;
            }
        }
        x += 0.1;
    }
  printf("----------------------------------\n"); 
  return(0);
}

float dicotomia(float xa, float xb, float precisao, float (*f)(float))
{
    float xc, anterior, f_xa, f_xb, f_xc;
    int iteracoes = 0;

    anterior = xb;
    xc = xa;

    printf("\n");  
    printf("-----------------------------------------------------------------------------\n");  
    printf("| n  | xa        | xb        | xc        | f(xa)     | f(xb)     | f(xc)     |\n");  
    printf("-----------------------------------------------------------------------------\n"); 

    while(fabs(xc - anterior) > precisao)
    {
        iteracoes++;

        anterior = xc;
        xc = (xa + xb) / 2.0;

        f_xa = f(xa);  // Usar a função passada como parâmetro
        f_xb = f(xb);  // Usar a função passada como parâmetro
        f_xc = f(xc);  // Usar a função passada como parâmetro
    
        printf("| %d  | %+f | %+f | %+f | %+f | %+f | %+f |\n", iteracoes, xa, xb, xc, f_xa, f_xb, f_xc);

        if( f_xa * f_xc < 0.0)
        {
            xb = xc;
        }

        else
        {
            if( f_xb * f_xc < 0.0)
            {
                xa = xc;
            }
        }
    }
    printf("--------------------------------------------------\n");

    printf("Numero de iteracoes = %d\n", iteracoes);
    return (xc);
}

void busca_intervalo(float *inicio, float *fim)
{
    printf("Escolha um valor de inicio do intervalo:");
    scanf("%f", inicio);
    printf("Escolha um valor de fim do intervalo:");
    scanf("%f", fim);
}

void busca_precisao(float *precisao)
{
    printf("Escolha o valor da precisao:");
    scanf("%f", precisao);
}

int main()
{
    int escolha;
    float raiz = 0.0, inicio = 0.0, fim = 0.0;
    float precisao = 0.00000;

    do 
    {
        printf("\nObservação: Exercícios que já constam precisão ou intevalos não serão solicitados valores para o usuário\n");
        printf("\nEscolha um exercicio (1-5) ou 0 para sair:\n");
        printf("1: f(x) = x³ - x² - 1\n"); // precisão de 4 casas decimais 0,0001
        printf("2: f(x) = (e ^ -x) * ((x - 1) / 2)\n"); // intervalo [0;2] precisão 4 casas decimais 0,0001
        printf("3: f(x) = x² - x + sen(5x)\n"); //apenas raiz, vou pedir precisão pelo usuário
        printf("4: f(x) = x² + 1,95x - 2,09\n"); // apenas raiz também, vou pedir precisão pelo usuário
        printf("5: f(x) = x - 3 - (x ^ -x)\n"); // intervalo [1.0;3.0] e precisão de 4 casas decimais também 0,0001
        printf("0: Sair\n");
        printf("Opcao: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                //inicio = 1.4; fim = 1.5;
                busca_intervalo(&inicio,&fim);
                buscainversao(inicio, fim, f1);
                raiz = dicotomia(anterior, posterior, 0.0001, f1);
                break;
            case 2:
                inicio = 0.0; fim = 2.0;
                buscainversao(inicio, fim, f2);
                raiz = dicotomia(anterior, posterior, 0.0001, f2);
                break;
            case 3:
                //inicio = -1.0; fim = 1.5;
                busca_intervalo(&inicio,&fim);
                busca_precisao(&precisao);
                buscainversao(inicio, fim, f3);
                raiz = dicotomia(anterior, posterior, precisao, f3);
                break;
            case 4:
                //inicio = -3.0; fim = 1.0;
                busca_intervalo(&inicio,&fim);
                busca_precisao(&precisao);
                buscainversao(inicio, fim, f4);
                raiz = dicotomia(anterior, posterior, precisao, f4);
                break;
            case 5:
                inicio = 1.0; fim = 3.0;
                buscainversao(inicio, fim, f5);
                raiz = dicotomia(anterior, posterior, 0.0001, f5);
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
        printf("Raiz: %.4f\n", raiz);
    } while (escolha != 0);
    return 0;
}
