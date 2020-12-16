#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "HotDog_Lista.h"
#include "Pedidos_Fila.h"
#include "Pedidos_Pilha.h"
#include <locale.h>

Lista *AnotarPedido(Lista *Recebida,int *VetorTempoEntrega[], int *VerificaRegiao[], int AuxRandom, int AuxRandom2);

Lista *AnotarPedidoA(Lista *Recebida, int *VetorTempoEntrega[], int AuxControle, int AuxRandom, int AuxRandom2);

Lista *CadastroPonto(Lista *Aux, int *AuxControle[]);

Lista *CadastroPontoA(Lista *Original, int *AuxControle[], int *AuxTempoEntrega[], int AuxRandom, int AuxRandom2);

void ConcluirPedido(Lista *OriginalLista, int *VetorTempo[], int *VerificaRegiao[]);

void CancelaPedidoMain(Lista *OriginalLista);

int Menu(void);

int MenuR(void);

void Relatorio(Lista *Original, int AuxRegioes[]);



///MAIN----------------------------------------------------------------------------------------------------------------------------------------------------
int main(void)
{
    /// variveis cadastro ponto
    int Opcao, QuantidaPontosA, *VerificaRegiao[6] = {0}, *AuxTempoEntrega[6] = {0}, AuxRandom = 100, AuxRandom2 = 3;
    Lista *PontosVenda = inicializa();
    srand(time(NULL));

    setlocale(LC_ALL, "Portuguese");




    while (Opcao != 0)
    {

        do
        {
            Opcao = Menu();
        }
        while (Opcao < 0 || Opcao > 6);

        switch (Opcao)
        {
            case 1:
                PontosVenda = CadastroPonto(PontosVenda, VerificaRegiao);

                break;

            case 2:

                PontosVenda = AnotarPedido(PontosVenda, AuxTempoEntrega, VerificaRegiao, AuxRandom, AuxRandom2);
                AuxRandom2 += + 3;
                AuxRandom += + AuxRandom2;

                break;

            case 3:
                ConcluirPedido(PontosVenda, AuxTempoEntrega, VerificaRegiao);

                break;

            case 4:
                CancelaPedidoMain(PontosVenda);

                system("pause");
                break;


            case 5:

                Relatorio(PontosVenda, VerificaRegiao);
                break;

            case 6:
                QuantidaPontosA = (1 + rand() % 5);

                for (int i = 0; i < QuantidaPontosA; i++)
                {

                    system("cls");

                    PontosVenda = CadastroPontoA(PontosVenda,VerificaRegiao,AuxTempoEntrega,AuxRandom,AuxRandom2);
                    int   PedidosA = (5 + rand() % 10);

                    for (int i = 0; i < PedidosA; i++)
                    {
                        PontosVenda = AnotarPedidoA(PontosVenda, AuxTempoEntrega, PontosVenda->RegiaoPonto, AuxRandom, AuxRandom2);
                        AuxRandom2 += + 3;
                        AuxRandom += + AuxRandom2;

                    }

                }

                break;
        }

    }


}
///MAIN--------------------------------------------------------------------------------------------------------------------------------------------------




///Menu ==========================================================================================================================================================
int Menu(void)
{
    int aux;
    system("cls");

    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                   Cadastrar Ponto de Venda        [1]                        |\n");
    printf("|                                   Anotar Pedido                   [2]                        |\n");
    printf("|                                   Concluir Pedidos                [3]                        |\n");
    printf("|                                   Cancelar Pedidos                [4]                        |\n");
    printf("|                                   Relatório De Vendas             [5]                        |\n");
    printf("|                                   Teste Aleatório                 [6]                        |\n");
    printf("|                                   Sair                            [0]                        |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);

    return aux;

}

///Menu Regioes======================================================================================================================================================================
int MenuR(void)
{
    int aux;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                    Regiao [1]                                                |\n");
    printf("|                                    Regiao [2]                                                |\n");
    printf("|                                    Regiao [3]                                                |\n");
    printf("|                                    Regiao [4]                                                |\n");
    printf("|                                    Regiao [5]                                                |\n");
    printf("|                                Menu anterior [0]                                             |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);
    return aux;
}

int MenuRImpressao(void)
{
    int aux;
    printf("-----------------------------------------------------------------------------------------------\n");
    printf("-----------------------------------HOT DOG PATRICIA'S------------------------------------------\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    printf("|                                    Regiao [1]                                                |\n");
    printf("|                                    Regiao [2]                                                |\n");
    printf("|                                    Regiao [3]                                                |\n");
    printf("|                                    Regiao [4]                                                |\n");
    printf("|                                    Regiao [5]                                                |\n");
    printf("|                      Imprimir relatório de todas regiões [6]                                 |\n");
    printf("|                                Menu anterior [0]                                             |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");

    scanf("%d", &aux);
    return aux;
}


///CADASTRO DOS PONTOS====================================================================================================================================
Lista *CadastroPonto(Lista *Aux, int *AuxControle[])
{
    int  RegiaoCarrinho,Experiencia;


    do
    {
        system("cls");
        RegiaoCarrinho = MenuR();

        if (RegiaoCarrinho == 0)
        {
            return Aux;
        }

        if (AuxControle[RegiaoCarrinho] == 1)
        {
            printf("\nJa existe um ponte de venda nessa regiao\n");
            system("pause");

            RegiaoCarrinho = 10;
        }
        else
        {
            AuxControle[RegiaoCarrinho] = 1;
        }
    }
    while (RegiaoCarrinho < 1 || RegiaoCarrinho > 5);

    do
    {
        system("cls");

        printf("\n Experiencia 1-[baixa] 2-[média] 3-[alta]:");
        scanf("%d", &Experiencia);
    }
    while (Experiencia < 0 || Experiencia > 3);

    Aux = InsereCadastro(Aux, RegiaoCarrinho, Experiencia);

    return Aux;
}


/// Cadastro dos pontos aleatorio=================================================================================================================================================
Lista *CadastroPontoA(Lista *Original, int *AuxControle[], int *AuxTempoEntrega[], int AuxRandom, int AuxRandom2)
{
    srand(time(NULL));

    int  RegiaoCarrinho, Experiencia=(1 + rand() % 3);

    do
    {
        RegiaoCarrinho = (1 + rand() % 5);

        if (AuxControle[RegiaoCarrinho] == 1)
        {

            RegiaoCarrinho = 999;
        }
        else
        {
            AuxControle[RegiaoCarrinho] = 1;
        }
    }
    while (RegiaoCarrinho < 0 || RegiaoCarrinho > 5);


    printf("\n\n=====NOVO PONTO=====");

    printf("\n\n|   Regiao Do Novo Ponto - %d\n\n", RegiaoCarrinho);

    system("pause");

    system("cls");

    Original = InsereCadastro(Original, RegiaoCarrinho, Experiencia);

    return Original;
}




/// Anotar pedido=================================================================================================================================================================
Lista *AnotarPedido(Lista *Recebida, int *VetorTempoEntrega[], int *VerificaRegiao[], int AuxRandom, int AuxRandom2)
{
    int AuxRegiaoPedido, AuxNPedido = 0, AuxQuantidade;

    float AuxValorUnit, AuxValorTotal;

    char AuxObservacoes[50], AuxDescricao[50] = "Cachorro Quente";

    srand(time(NULL));

    ///Informações necessarias------------------------------------------------------------------------------------------------------------------------------------------

    do
    {
        system("cls");

        AuxRegiaoPedido = MenuR();

        if (AuxRegiaoPedido == 0)
        {
            return Recebida;
        }

        srand(time(NULL));

        if (VerificaRegiao[AuxRegiaoPedido] == 0)
        {
            printf("\n\nDesculpe mas ainda não aendemos nessa região\n\n\n");
            system("pause");
        }
    }
    while (VerificaRegiao[AuxRegiaoPedido] != 1);

    AuxNPedido = (AuxRandom + (rand() % AuxRandom2));

    printf("Numero do seu pedido:%d \n", AuxNPedido);

    printf("\nDigite a quantidade de Carrochos Quente o pedido: ");

    scanf("%d", &AuxQuantidade);

    srand(time(NULL));

    AuxValorUnit = ((10 + rand() % 5) + ((rand() % 100) / 100.00));

    printf("\nValor Unitario de cada Cachorro Quente: %.2f", AuxValorUnit);

    AuxValorTotal = (AuxQuantidade * AuxValorUnit);

    printf("\nValor Total do pedido %d : %.2f", AuxNPedido, AuxValorTotal);

    printf("\nObservacoes do Pedido: ");

    fflush(stdin);

    gets(AuxObservacoes);

    ///Busca Lista Correta --------------------------------------------------------------------------------------------------------------

    Lista *Aux = Recebida;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

    ///inserção Fila -----------------------------------------------------------------------------------------------------------------------
    InsereFila(Aux->Pedidos, Recebida->experiencia, AuxRegiaoPedido, AuxDescricao, AuxQuantidade, AuxValorUnit, AuxObservacoes, AuxNPedido, VetorTempoEntrega);

    imprimeNotaFiscal(Aux->Pedidos);

    system("pause");

    return Recebida;
}

/// Anotar pedido Aleatorio=================================================================================================================================================================

Lista *AnotarPedidoA(Lista *Recebida, int *VetorTempoEntrega[], int AuxControle, int AuxRandom, int AuxRandom2)
{
    int AuxRegiaoPedido, AuxNPedido, AuxQuantidade;

    float AuxValorUnit;

    char AuxObservacoes[50] = "NULL", AuxDescricao[50] = "Cachorro Quente";

    AuxRegiaoPedido = AuxControle;

    AuxNPedido = (AuxRandom + (rand() % AuxRandom2));

    AuxQuantidade = (1 + rand() % 5);

    AuxValorUnit = (10 + rand() % 5);



    Lista *Aux = Recebida;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

    InsereFila(Aux->Pedidos,Recebida->experiencia,AuxRegiaoPedido,AuxDescricao,AuxQuantidade,AuxValorUnit,AuxObservacoes,AuxNPedido,VetorTempoEntrega);
    imprimeNotaFiscal(Aux->Pedidos);
    system("pause");
    return Recebida;
}




/// cancelar pedido

void CancelaPedidoMain(Lista *OriginalLista)
{

    int AuxNPedido, AuxRegiao;

    printf("Qual o numero do pedido que deseja Cancelar: ");
    scanf("%d", &AuxNPedido);
    printf("\n\nQual a Região do Pedido:");
    scanf("%d", &AuxRegiao);
    Lista *Aux = OriginalLista;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiao)
        {

            break;
        }
            Aux = Aux->prox;
    }

    system("cls");

    Aux->Pedidos = CancelaPedido(Aux->Pedidos,AuxNPedido);

    printf("\n\n==========Pedidos Restantes ==========\n\n");

    imprimeFila(Aux->Pedidos);


}


///concluir pedido

void ConcluirPedido(Lista *OriginalLista, int *VetorTempo[], int *VerificaRegiao[])
{

    /// Atender Pedido

    /**. Atender pedido: atendimento da fila de pedidos do ponto. Remove um a um os
    itens do pedido e exibe a nota fiscal (a ordem dos itens deve ser a ordem de
    remoção da pilha). Por fim, remove o pedido da fila e atualiza o valor total
    vendido do ponto;**/

    /// variaveis pedido

    int AuxRegiaoPedido,AuxQuantidadePedidos;

    float ValorTotalMain;

    do
    {
        system("cls");

        AuxRegiaoPedido = MenuR();

        if (AuxRegiaoPedido == 0)
        {
            return OriginalLista;
        }

        if (VerificaRegiao[AuxRegiaoPedido] == 0)
        {
            AuxRegiaoPedido = 10;
        }

    }
    while (AuxRegiaoPedido < 0 || AuxRegiaoPedido > 5);

    Lista *Aux = OriginalLista;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == AuxRegiaoPedido)
        {

            break;
        }
        Aux = Aux->prox;

    }

        if (Aux->Pedidos->inicio == NULL)
    {
        printf("\n\nNÃO EXISTE PEDIDOS PARA ESSA REGIÂO\n\n");
        system("pause");
        return OriginalLista;
    }

    AuxQuantidadePedidos = pop_QuantidadeProduto(Aux->Pedidos->inicio->ItensPedido);

    ValorTotalMain = pop_ValorTotal(Aux->Pedidos->inicio->ItensPedido);

    VetorTempo[AuxRegiaoPedido] = VetorTempo[AuxRegiaoPedido] - Aux->Pedidos->inicio->TempoEntrega;

    imprimeNotaFiscalCancela(Aux->Pedidos);

    Aux->Pedidos = liberaFila(Aux->Pedidos);

    Aux->VendasTotal += ValorTotalMain;

    Aux->QuantidadePedidos += AuxQuantidadePedidos;

    system("pause");

    system("cls");

    printf("==========PEDIDOS RESTANTES==========");

    imprimeFila(Aux->Pedidos);
    system("pause");

}

void Relatorio(Lista *OriginalLista, int AuxRegioes[])
{

    int flag, AuxNumPedido;
    do
    {
        system("cls");
        flag = MenuRImpressao();

        if (flag == 0)
        {
            return;
        }

        if (flag == 6)
        {
            imprimeLista(OriginalLista);
            return;
        }

        if (AuxRegioes[flag] == 0)
        {
            flag = 10;
        }

    }
    while (flag < 1 || flag > 6);

    if (flag == 6)
    {
        imprimeLista(OriginalLista);
        return;
    }


    Lista *Aux = OriginalLista;

    while (Aux != NULL)
    {
        if (Aux->RegiaoPonto == flag)
        {

            break;
        }
        Aux = Aux->prox;

    }

    imprimeListaParcial(Aux);



   do
    {
        printf("\n\n Deseja consultar  Todos Pedidos Pendentes - [1] \n Consultar Pedido especifico - [2]\n Voltat-[0]\n:");
        scanf("%d",&flag);

    }
    while (flag < 0 || flag > 2);

    if(flag == 0)
    {
        return;
    }
    else if(flag == 1)
    {
        imprimeFila(Aux->Pedidos);
        system("pause");
    }
    else
    {
        printf("\n\n Digite o numero do pedido que deseja consultar: ");
        scanf("%d",&AuxNumPedido);
        system("cls");



    Fila *AuxF = Aux->Pedidos;




    while (AuxF->inicio != NULL)
    {
        if (AuxF->inicio->NumeroPedido == AuxNumPedido)
        {
            imprimeNotaFiscalRelatorio(AuxF);
            system("pause");
            return;
        }

        AuxF->inicio = AuxF->inicio->prox;

    }
    printf("\n\n\t\tPEDIDO INEXISTENTE VERIFIQUE NUMERO E REGIÃO\n\n");
    system("pause");



    }




}




