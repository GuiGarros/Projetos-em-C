#ifndef PEDIDOS_FILA_H_INCLUDED
#define PEDIDOS_FILA_H_INCLUDED
#include "Pedidos_Pilha.h"






typedef struct NoFila
{

    int   NumeroPedido;
    int   RegiaoPedido; /// Valor numerico que representa uma RegiaoPedido de entrega
    int   TempoEntrega; /// Tempo de entrega para cada pedido
    Pilha *ItensPedido; /// Itens do pedido de cada cliente/

    struct NoFila *prox;

} NoFila;

typedef struct fila
{
    NoFila *inicio;
    NoFila *fim;
} Fila;

int VaziaFila(Fila *Aux)
{
    if (Aux->inicio == NULL)
    {
        return 1;
    }
    return 0;

}

Fila *CriaFila(void)
{
    Fila *Aux = (Fila *) malloc(sizeof(Fila));
    Aux->inicio = Aux->fim = NULL;
    return Aux;

}

NoFila *Insere_NoFila(NoFila *fim, int AuxRegiaoPedido, char AuxDescricao[], int AuxQuantidadeProduto, float AuxValorUnitario,
                      char AuxObservacoes[], int AuxNumeroPedido)
{


    NoFila *Aux = (NoFila *) malloc(sizeof(NoFila));
    Aux->ItensPedido = (Pilha *)malloc(sizeof(Pilha));

    if (Aux->prox == NULL)
    {
        Aux->ItensPedido = CriaPilha();
    }

    Aux->RegiaoPedido = AuxRegiaoPedido;

    Aux->TempoEntrega = 20;

    Aux->NumeroPedido = AuxNumeroPedido;

    push(Aux->ItensPedido, AuxDescricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes);

    Aux->prox = NULL;


    if (fim != NULL)
    {
        fim->prox = Aux;/* verifica se lista não estava vazia */
    }


    return Aux;
};



void InsereFila(Fila *Aux, int AuxExperiencia, int AuxRegiaoPedido, char AuxDecricao[], int AuxQuantidadeProduto,
                float AuxValorUnitario, char AuxObservacoes[], int AuxNumeroPedido, int *VetorTempoEntrega[])
{

    Aux->fim = Insere_NoFila(Aux->fim, AuxRegiaoPedido, AuxDecricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes,
                             AuxNumeroPedido);


    if (Aux->inicio == NULL) /* fila antes vazia? */
    {
        Aux->inicio = Aux->fim;
    }
    CalculoTempEntrega(Aux, VetorTempoEntrega, AuxExperiencia, AuxQuantidadeProduto);



};


NoFila *Insere_NoFilaCancela(NoFila *fim, int AuxRegiaoPedido, char AuxDescricao[], int AuxQuantidadeProduto,
                             float AuxValorUnitario, char AuxObservacoes[], int AuxNumeroPedido, int AuxTempoEntrega)
{


    NoFila *Aux = (NoFila *) malloc(sizeof(NoFila));
    Aux->ItensPedido = (Pilha *)malloc(sizeof(Pilha));
    Aux->RegiaoPedido = AuxRegiaoPedido;
    Aux->TempoEntrega = AuxTempoEntrega;

    Aux->NumeroPedido = AuxNumeroPedido;

    push(Aux->ItensPedido, AuxDescricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes);

    Aux->prox = NULL;

    if (fim != NULL)
    {
        fim->prox = Aux;/* verifica se lista não estava vazia */
    }
    return Aux;
};




void InsereFilaCancela(Fila *Aux, int AuxRegiaoPedido, char AuxDecricao[], int AuxQuantidadeProduto, float AuxValorUnitario,
                       char AuxObservacoes[], int AuxNumeroPedido, int AuxTempoEntrega)
{

    Aux->fim = Insere_NoFilaCancela(Aux->fim, AuxRegiaoPedido, AuxDecricao, AuxQuantidadeProduto, AuxValorUnitario, AuxObservacoes,
                                    AuxNumeroPedido, AuxTempoEntrega);


    if (Aux->inicio == NULL) /* fila antes vazia? */
    {
        Aux->inicio = Aux->fim;
    }

}








NoFila *Retira_Inicio(NoFila *Inicio)
{
    NoFila *Aux = Inicio->prox;
    free(Inicio);
    return Aux;
}



Pilha *RetiraItensPedido(Fila *Aux, int AuxNumeroPedido)
{
    Pilha *AuxItensPedido;
    if (VaziaFila(Aux))
    {
        printf("Pedido não encontrado.\n");
        return 0;
    }

    AuxItensPedido = Aux->inicio->ItensPedido;
    //Aux->inicio = Retira_Inicio(Aux->inicio);
    if (Aux->inicio == NULL)
    {
        Aux->fim = NULL;
    }
    return AuxItensPedido;
}

int RetiraFilaRegiaoPedido(Fila *Aux)
{
    int AuxRegiaoPedido;
    if (VaziaFila(Aux))
    {
        printf("Pedido não encontrado.\n");
        return 0;
    }
    AuxRegiaoPedido = Aux->inicio->RegiaoPedido;

    if (Aux->inicio == NULL)
    {
        Aux->fim = NULL;
    }
    return AuxRegiaoPedido;
}

int RetiraFilaTempoEntrega(Fila *Aux)
{
    int AuxTempoEntrega;
    if (VaziaFila(Aux))
    {
        printf("Pedido não encontrado.\n");
        return 0;
    }
    AuxTempoEntrega = Aux->inicio->TempoEntrega;

    if (Aux->inicio == NULL)
    {
        Aux->fim = NULL;
    }
    return AuxTempoEntrega;
}

void imprimeFila(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\n Não Há Pedidos \n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio ; N != NULL ; N = N->prox)
        {


            printf("\n");
            printf("numero do pedido - %d \n", N->NumeroPedido);
            printf("Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("Tempo de entrega - %d \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
        }
    }


}

void imprimeNotaFiscal(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\nNão Há Pedidos\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->fim ; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - %d -Min \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
            printf("\n====================================\n\n\n\n");
            break;
        }
    }


}

void imprimeNotaFiscalRelatorio(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("\n\nNão Há Pedidos\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio ; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - %d -Min \n", N->TempoEntrega);
            ImprimePilha(N->ItensPedido);
            printf("\n====================================\n\n\n\n");
            break;
        }
    }


}

void imprimeNotaFiscalCancela(Fila *Aux)
{
    if (VaziaFila(Aux) == 1)
    {
        printf("Fila Vazia\n\n");
    }
    else
    {

        NoFila *N;
        for (N = Aux->inicio; N != NULL; N = N->prox)
        {
            system("cls");
            printf("\n\n\n============NOTA FISCAL============");
            printf("\n");
            printf("|   numero do pedido - %d \n", N->NumeroPedido);
            printf("|   Regiao do pedido - %d \n", N->RegiaoPedido);
            printf("|   Tempo de entrega - PRONTO PARA ENTREGA \n");
            ImprimePilha(N->ItensPedido);
            printf("\n\n\n===================================");

            printf("\n\n\n\tPATRICIA´s AGRADECE A PREFERENCIA\n\n\n");
            break;
        }
    }


}

Fila *liberaFila(Fila *Aux)
{
    Fila *Flag = Aux;
    NoFila *Flag2 = Aux->inicio->prox;

    while (Flag2 != NULL)
    {
        Flag2->TempoEntrega = Flag2->TempoEntrega - Flag->inicio->TempoEntrega;
        Flag2 = Flag2->prox;
    }
    Aux->inicio = Aux->inicio->prox;

    return Aux;
}


Fila *CancelaPedido(Fila *Original, int AuxNumeroPedido)
{

    Fila *Nova = CriaFila();

    int AuxRetiraTempo = 0, AuxCalculoTempo;


    if (AuxNumeroPedido == Original->inicio->NumeroPedido)
    {

        Original->inicio = Original->inicio->prox;
        return Original;
    }

    while (Original->inicio != NULL)
    {


        if (Original->inicio->NumeroPedido != AuxNumeroPedido)
        {


            AuxCalculoTempo = Original->inicio->TempoEntrega;

            InsereFilaCancela(Nova, Original->inicio->RegiaoPedido, Original->inicio->ItensPedido->Primeiro->Descricao,
                              Original->inicio->ItensPedido->Primeiro->QuantidadeProduto, Original->inicio->ItensPedido->Primeiro->ValorUnitario,
                              Original->inicio->ItensPedido->Primeiro->Observacoes, Original->inicio->NumeroPedido,
                              Original->inicio->TempoEntrega - AuxRetiraTempo);


        }
        else
        {
            printf("========= PEDIDO CANCELADO ==========\n");
            imprimeNotaFiscalCancela(Original);
            AuxRetiraTempo = Original->inicio->TempoEntrega - AuxCalculoTempo;
        }

        Original->inicio = Original->inicio->prox;

    }

    if (Original->inicio == NULL)
    {
        printf("\n\n\n PEDIDO NÂO EXISTE\n\n\n");
    }

    return Nova;


}

void CalculoTempEntrega(Fila *Original, int *VetorTempoEntrega[], int AuxExperiencia, int AuxQauntidadePedido)
{

    Fila *FAux = Original;


    if (AuxExperiencia == 1)
    {
        FAux->fim->TempoEntrega = FAux->fim->TempoEntrega + (5 * AuxQauntidadePedido);
    }
    else
    {
        FAux->fim->TempoEntrega = FAux->fim->TempoEntrega + ((5 - (AuxExperiencia * 3 / 3)) * AuxQauntidadePedido);
    }

    VetorTempoEntrega[FAux->fim->RegiaoPedido] += FAux->fim->TempoEntrega ;
    FAux->fim->TempoEntrega =  VetorTempoEntrega[FAux->fim->RegiaoPedido];
    FAux->fim->TempoEntrega = FAux->fim->TempoEntrega / 4;
};


#endif // PEDIDOS_FILA_H_INCLUDED
