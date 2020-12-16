#include <stdio.h>
#include <stdlib.h>
#define tam 3
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>



typedef struct
{
    char aluno_nome [50];
    char aluno_ra[50];
    bool a_verifica;
    char aluno_materias[20][30];


    char dis_nome[30];
    char dis_codigo[30];
    bool d_verifica;


    char prof_nome[50];
    char prof_codigo[50];
    bool p_verifica;
    char prof_materias[20][30];

} cadastro;

void clear (cadastro cad[])
{
    int i,j;
    for( i=0; i<tam; i++)
    {
        for ( j=0; j<tam; j++)
        {
            strcpy(cad[i].aluno_materias[j],"NULL");
            strcpy(cad[i].prof_materias[j],"NULL");
            strcpy(cad[i].aluno_nome,"NULL");
            strcpy(cad[i].dis_nome,"NULL");
            strcpy(cad[i].prof_nome,"NULL");
        }
    }
}

int verificacao (cadastro cad[],int a,int tipo)
{
    int j;
    for (j=0; j<tam; j++)
    {
        if(tipo==1)
        {
            if (strcmp(cad[a].aluno_ra,cad[j].aluno_ra)==0 && j!=a)
            {

                return 1;
            }
        }
        if (tipo==2)
        {

            if (strcmp(cad[a].dis_codigo,cad[j].dis_codigo)==0 && j!=a)
            {
                return 1;
            }
        }
        if(tipo==3)
        {
            if ( strcmp(cad[a].prof_codigo,cad[j].prof_codigo)==0 && j!=a)
            {

                return 1;
            }
        }

    }
    return 0;
}

void imprimirDisciplinaDeAluno(cadastro cad[])
{
    char busca[50];
    printf("Digite o Ra:");
    fflush(stdin);
    gets(busca);

    for (int i=0; i<tam; i++)
    {
        if(strcmp(cad[i].aluno_ra,busca)==0)
        {
            for( int j=0; j<tam; j++)
            {
                if(strcmp(cad[i].aluno_materias[j],"NULL")!=0)
                    puts(cad[i].aluno_materias[j]);
            }
        }
    }

}
void imprimirA(cadastro cad[])
{
    int i;
    printf("\n Lista de alunos ");
    for ( i=0; i<tam ; i++)
    {
        if(strcmp(cad[i].aluno_nome,"NULL")==1)
        {
            printf("\n %s - Ra:%s",cad[i].aluno_nome,cad[i].aluno_ra);
        }
    }
}
void imprimirD(cadastro cad[])
{
    printf("\n Lista de disciplinas ");
    for (int i=0; i<tam ; i++)
    {
        if(strcmp(cad[i].dis_nome,"NULL")==1)
        {
            printf("\n %s - Codigo:%s",cad[i].dis_nome,cad[i].dis_codigo);
        }
    }
}
void imprimirP(cadastro cad[])
{
    printf("\n Lista de Professores");
    for (int i=0; i<tam ; i++)
    {
        if(strcmp(cad[i].prof_nome,"NULL")==1)
        {
            printf("\n %s - numero de identificação:%s",cad[i].prof_nome,cad[i].prof_codigo);
        }
    }
}

void imprimirDisciplinaMinistradaProf(cadastro cad[])
{
    char busca[50];
    printf("Digite o Codigo:");
    fflush(stdin);
    gets(busca);

    for (int i=0; i<tam; i++)
    {
        if(strcmp(cad[i].prof_codigo,busca)==0)
        {
            for(int j=0; j<tam; j++)
            {
                if(strcmp(cad[i].prof_materias[j],"NULL")!=0)
                    puts(cad[i].prof_materias[j]);
            }
        }
    }

}

void imprimirAlunosEmDisciplina(cadastro cad[])
{
    int i,j;
    char busca[50];
    char auxbusca[50];
    printf("Digite o codigo da disciplina: ");
    fflush(stdin);
    gets(busca);

    for(i=0; i<tam; i++)
    {
        if(strcmp(cad[i].dis_codigo,busca)==0)
        {
            strcpy(auxbusca,cad[i].dis_nome);
            for(j=0; j<tam; j++)
            {
                if(strcmp(auxbusca,cad[j].aluno_materias)==0)
                {
                    puts(cad[j].aluno_nome);
                }
            }
        }
    }
}
void imprimirProfessorEmDisciplina(cadastro cad[])
{
    int i,j;
    char busca[50];
    char auxbusca[50];
    printf("Digite o codigo da disciplina: ");
    fflush(stdin);
    gets(busca);

    for(i=0; i<tam; i++)
    {
        if(strcmp(cad[i].dis_codigo,busca)==0)
        {
            strcpy(auxbusca,cad[i].dis_nome);
            for(j=0; j<tam; j++)
            {
                if(strcmp(auxbusca,cad[j].prof_materias)==0)
                {
                    puts(cad[j].prof_nome);
                }
            }
        }
    }
}

int menu (int k)
{
    do
    {

        k=0;
        char numero[]= {0};
        printf("\t\t\t\tCadastro universitário! Oque deseja cadastrar?\n");
        printf("\t\t\t\t _______________________________________________________");
        printf("\n\t\t\t\t|                                                       |");
        printf("\n\t\t\t\t|[1] Aluno                                              |");
        printf("\n\t\t\t\t|[2] Disciplina                                         |");
        printf("\n\t\t\t\t|[3] Professor                                          |");
        printf("\n\t\t\t\t|[4] Matricular na Disciplina aluno                     |");
        printf("\n\t\t\t\t|[5] Matricular Professor na Disciplina                 |");
        printf("\n\t\t\t\t|[6] Desmatricular um Aluno de uma Disciplina           |");
        printf("\n\t\t\t\t|[7] Desmatricular um Professor de uma Disciplina       |");
        printf("\n\t\t\t\t|[8] Desmatricular Aluno da faculdade                   |");
        printf("\n\t\t\t\t|[9] Imprimir lista                                     |");
        printf("\n\t\t\t\t|[0] Sair                                               |");
        printf("\n\t\t\t\t|                                                       |");
        printf("\n\t\t\t\t _______________________________________________________\n:");
        gets(numero);
        fflush(stdin);
        k=strtol(numero, NULL, 10);
        Sleep(100);
        system("cls");

    }
    while(k>9 || k<0);
    return k;
}

int SegundoMenu(int n)
{
    n=0;
    do
    {
        char aux[]= {0};
        system("cls");
        printf("\t\t\t\t\tQual lista deseja imprimir?\n");
        printf("\t\t\t\t ______________________________________________________________________");
        printf("\n\t\t\t\t|                                                                      |");
        printf("\n\t\t\t\t|[1] Lista dos Alunos                                                  |");
        printf("\n\t\t\t\t|[2] Lista de Disciplinas                                              |");
        printf("\n\t\t\t\t|[3] Lista de professores                                              |");
        printf("\n\t\t\t\t|[4] Lista das disciplinas de um Aluno                                 |");
        printf("\n\t\t\t\t|[5] Lista de disciplinas ministradas por um professor                 |");
        printf("\n\t\t\t\t|[6] Lista de Alunos em uma Disciplina                                 |");
        printf("\n\t\t\t\t|[7] Lista de Professores em uma disciplina                            |");
        printf("\n\t\t\t\t|[8] Voltar ao Menu Principal                                          |");
        printf("\n\t\t\t\t|                                                                      |\n");
        printf("\t\t\t\t ______________________________________________________________________\n:");
        gets(aux);
        fflush(stdin);
        n=strtol(aux, NULL, 10);
        Sleep(100);
        system("cls");

    }
    while(n<1||n>8);
    return n;
}
void imprime(int n, cadastro cad[])
{

    switch(n)
    {

    case 1:
        imprimirA(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 2:
        imprimirD(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 3:
        imprimirP(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 4:
        imprimirDisciplinaDeAluno(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 5:
        imprimirDisciplinaMinistradaProf(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 6:
        imprimirAlunosEmDisciplina(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;

    case 7:
        imprimirProfessorEmDisciplina(cad);
        printf("\n\n\n");
        system("pause");
        system("cls");
        break;
    case 8:
        break;
    default:

        printf("Comando invalido!");
        printf("\n\n\n");
        system("pause");
        system("cls");
    }
}
int main ()
{
    int i,j,k=0,n,ver=0;
    cadastro cad[tam];
    char busca[50];
    int auxbusca,auxbusca2;
    clear(cad);
    setlocale(LC_ALL, "Portuguese");
    for(int i=0; i<tam ; i++)
    {
        cad[i].a_verifica=false;
        cad[i].d_verifica=false;
        cad[i].p_verifica=false;
    }

    do
    {
        system("cls");
        k=menu(k);
        if (k==1)
        {
            for (i=0; i<tam; i++)
            {
                if(strcmp(cad[i].aluno_nome,"NULL")==0)
                {
                    printf(" Nome do aluno: ");
                    fflush(stdin);
                    gets(cad[i].aluno_nome);
                    cad[i].a_verifica=true;
                    do
                    {
                        printf(" RA: ");
                        gets(cad[i].aluno_ra);
                        ver=verificacao(cad,i,k);
                        if (ver == 1)
                        {
                            Sleep(200);
                            system("cls");
                            printf(" Esse RA já pertence a um Aluno!\n Redigite o RA do Aluno\n");
                            printf("\n\n Nome do aluno:");
                            puts(cad[i].aluno_nome);
                        }
                    }
                    while(ver!=0);
                    break;
                }
                else if(i==tam-1)
                {
                    printf("Você chegou ao numero maximos de aluno permitido no cadastro!");
                    Sleep(2000);
                    system("cls");
                }
            }
            system("cls");
        }
        else if (k==2)
        {
            for (i=0; i<tam; i++)
            {
                if(strcmp(cad[i].dis_nome,"NULL")==0)
                {
                    printf(" Nome da disciplina: ");
                    fflush(stdin);
                    gets(cad[i].dis_nome);
                    cad[i].a_verifica=true;

                    do
                    {
                        printf(" Codigo: ");
                        gets(cad[i].dis_codigo);
                        ver=verificacao(cad,i,k);///Função: Verifica se o RA já foi digitado.
                        if (ver==1)
                        {
                            Sleep(200);
                            system("cls");
                            printf(" Esse codigo já pertence a uma disciplina!\n Redigite o codigo da disciplina\n");
                            printf("\n\n Nome da disciplina:");
                            puts(cad[i].dis_nome);
                        }
                    }
                    while(ver!=0);
                    break;
                }
                else if(i==tam-1)
                {
                    printf("Você chegou ao numero maximos de disciplinas permitidas no cadastro!");
                    Sleep(2000);
                    system("cls");
                }

            }
            system("cls");
        }

        else if (k==3)
        {
            for (i=0; i<tam; i++)
            {
                if(strcmp(cad[i].prof_nome,"NULL")==0)
                {
                    printf(" Nome do professor: ");
                    fflush(stdin);
                    gets(cad[i].prof_nome);
                    cad[i].a_verifica=true;

                    do
                    {
                        printf(" Numero de identificação: ");
                        gets(cad[i].prof_codigo);
                        ver=verificacao(cad,i,k);///Função: Verifica se o RA já foi digitado.
                        if (ver == 1)
                        {
                            Sleep(200);
                            system("cls");
                            printf(" Esse numero de identificação já pertence a um professor!\n Redigite o umero de identificação do professor\n");
                            printf("\n\n Nome do Professor:");
                            puts(cad[i].prof_nome);
                        }
                    }
                    while(ver!=0);
                    break;
                }
                else if(i==tam-1)
                {
                    printf("Você chegou ao numero maximos de professores permitido no cadastro!");
                    Sleep(2000);
                    system("cls");
                }
            }
            system("cls");
        }


        else if (k==4)
        {
            auxbusca=0,auxbusca2=0;
            printf("Digite o codigo da disciplina que deseja cadastrar:");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                if(strcmp(busca,cad[i].dis_codigo)==0)
                {
                    auxbusca=i;
                }
            }
            printf("Digite o Ra do aluno que deseja cadastrar:");
            fflush(stdin);
            gets(busca);
            for( i=0 ; i<tam; i++)
            {
                if(strcmp(cad[i].aluno_ra,busca)==0)
                    auxbusca2=i;
            }



            for( j=0; j<tam; j++)
            {


                if(strcmp(busca,cad[auxbusca2].aluno_ra)==0&&strcmp(cad[auxbusca2].aluno_materias[j],"NULL")==0  )
                {
                    Sleep(2000);
                    strcpy(cad[auxbusca2].aluno_materias[j],cad[auxbusca].dis_nome);
                    puts(cad[auxbusca2].aluno_materias[j]);
                    Sleep(2000);

                    break;
                }

            }

        }


        else if(k==5)
        {
            auxbusca=0,auxbusca2=0;
            printf("Digite o codigo da disciplina que deseja cadastrar:");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                if(strcmp(busca,cad[i].dis_codigo)==0)
                {
                    auxbusca=i;
                }
            }
            printf("Digite o Número de indentificação do professor que deseja cadastrar:");
            fflush(stdin);
            gets(busca);
            for( i=0 ; i<tam; i++)
            {
                if(strcmp(cad[i].prof_codigo,busca)==0)
                    auxbusca2=i;
            }



            for(int j=0; j<tam; j++)
            {


                if(strcmp(busca,cad[auxbusca2].prof_codigo)==0&&strcmp(cad[auxbusca2].prof_materias[j],"NULL")==0  )
                {
                    Sleep(2000);
                    strcpy(cad[auxbusca2].prof_materias[j],cad[auxbusca].dis_nome);
                    puts(cad[auxbusca2].prof_materias[j]);
                    Sleep(2000);

                    break;
                }

            }
        }
        else if(k==6)
        {
            auxbusca=0;
            printf("Digite o codigo da disciplina que deseja remover o aluno:");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                if(strcmp(busca,cad[i].aluno_ra)==0)
                {
                    auxbusca=i;
                }
            }
            printf("Digite o Ra do aluno que deseja desmatricular");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                for(j=0 ; j<tam ; j++)
                {
                    if (strcmp(cad[i].aluno_materias[j],"NULL")==0)
                    {
                        Sleep(200);
                        break;
                    }
                    if(strcmp(busca,cad[i].aluno_ra)==0)
                    {
                        strcpy(cad[i].aluno_materias[j],"NULL");
                        puts(cad[i].aluno_materias[j]);
                        Sleep(500);
                        break;
                    }
                }
            }


        }
        else if(k==7)
        {
            auxbusca=0;
            printf("Digite o codigo da disciplina que deseja remover o professor:");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                if(strcmp(busca,cad[i].dis_codigo)==0)
                {
                    auxbusca=i;
                }
            }
            printf("Digite o numero de indentificação do professor que deseja remover:");
            fflush(stdin);
            gets(busca);
            for(i=0 ; i<tam ; i++)
            {
                for(j=0 ; j<tam ; j++)
                {
                    if (strcmp(cad[i].prof_materias[j],"NULL")==0)
                    {
                        printf("\tts=");
                        Sleep(200);
                        break;
                    }
                    if(strcmp(busca,cad[i].prof_codigo)==0)
                    {

                        strcpy(cad[i].prof_materias[j],"NULL");
                        puts(cad[i].prof_materias[j]);

                        break;


                    }
                }
            }
        }
        else if (k==9)
        {
            int n;
            n=SegundoMenu(n);
            imprime(n,cad);


        }
        else if (k==0)
        {

            n=2;
            system("Pause");
        }
    }
    while (n!=2);
    return 0;
}
