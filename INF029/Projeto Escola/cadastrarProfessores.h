#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMANHO_LISTA 10
#include "cadastrarAlunos.h"

typedef struct cadProf
{
    char nome[50];
    struct dataNascimento dtnasc;
    char CPF[15];
    int matricula;
    char sexo;
} Lista_Prof;

//escopo de funções de cadastramento
int matricula_Professor(int qtd,Lista_Prof Professores[]);
void listar_Professor(Lista_Prof Professores[]);
void listar_professor_nome(int qtd,Lista_Prof Professores[]);
void listar_professor_sexo(int qtd,Lista_Prof Professores[]);
void listar_professor_data(int qtd,Lista_Prof Professores[]);
void status_Professor(Lista_Prof Professores[]);
void retirar_Professor(int qtd,Lista_Prof Professores[]);
void alterar_professor(int qtd,Lista_Prof Professores[]);
int menu_professor();
int menu_opcoesprofessores();
//Função de validar matricula particular para Professores
int validarmatriculaprof(int mat,Lista_Prof Professores[]);

int matricula_Professor(int qtd, Lista_Prof Professores[])
{
    int v1,v2,v3,v4,v5;
    int ver;
    
    for(ver=0;ver<TAMANHO_LISTA;ver++)
    {
        if(Professores[qtd].matricula!=-1)
            qtd++;
        else
            break;
    }
    
    
    
    printf("Informe a matricula do Professor\n");
    scanf("%d",&Professores[qtd].matricula);
    getchar();
    
    printf("Informe o nome e sobrenome do Professor\n");
    fgets(Professores[qtd].nome,40,stdin);
    size_t ln= strlen(Professores[qtd].nome)-1;
    if(Professores[qtd].nome[ln]=='\n')
            Professores[qtd].nome[ln]='\0';
    
    printf("Informe o dia de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.dia);
    
    printf("Informe o mes de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.mes);
    
    printf("Informe o ano de Nascimento\n");
    scanf("%d",&Professores[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Professor\n");
    fgets(Professores[qtd].CPF,16,stdin);
    ln= strlen(Professores[qtd].CPF)-1;
    if(Professores[qtd].CPF[ln]=='\n')
            Professores[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Professor(F, M ou O)\n");
    scanf("%c",&Professores[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Professores[qtd].nome);
    v2=validardtnasc(Professores[qtd].dtnasc.dia,Professores[qtd].dtnasc.mes,Professores[qtd].dtnasc.ano);
    v3=validarcpf(Professores[qtd].CPF);
    v4=validarsexo(Professores[qtd].sexo);
    v5=validarmatriculaprof(Professores[qtd].matricula,Professores);
    
    if(v1==1 && v2==1 && v3==1 && v4==1 && v5==1)
    {
        return 1;
    }
    if(v1==0)
        printf("\nERRO_NOME_INVALIDO\n");
    if(v2==0)
        printf("\nERRO_DATA_INVALIDA\n");
    if(v3==0)
        printf("\nERRO_CPF_INVALIDO\n");
    if(v4==0)
        printf("\nERR0_SEXO_INVALIDO\n");
    if(v5==0)
        printf("\nERRO_MATRICULA_INVALIDA\n");
    return 0;
    
}


void listar_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Professores[x].matricula!=-1)
        {
            printf("%d. Nome: %s\n",x+1,Professores[x].nome);
            printf("Matricula: %d\n",Professores[x].matricula);
            printf("Data de Nascimento : %d/%d/%d\n",Professores[x].dtnasc.dia,Professores[x].dtnasc.mes,Professores[x].dtnasc.ano);
            printf("CPF : %s\n",Professores[x].CPF);
            printf("Sexo : %c\n",Professores[x].sexo);
            printf("\n");
        }
    }
}

void status_Professor(Lista_Prof Professores[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Professores[x].matricula = -1;
}

void retirar_Professor(int qtd,Lista_Prof Professores[])
{
    int del;
    int cont;
    printf("Informe o número do Professor\n");
    listar_Professor(Professores);
    scanf("%d",&del);
    del--;
    for(cont=del;Professores[cont].matricula!=-1;cont++)
    {
        Professores[cont].matricula=Professores[cont+1].matricula;
        Professores[cont].sexo=Professores[cont+1].sexo;
        Professores[cont].dtnasc.dia=Professores[cont+1].dtnasc.dia;
        Professores[cont].dtnasc.mes=Professores[cont+1].dtnasc.mes;
        Professores[cont].dtnasc.ano=Professores[cont+1].dtnasc.ano;
        strcpy(Professores[cont].nome,Professores[cont+1].nome);
        strcpy(Professores[cont].CPF,Professores[cont+1].CPF);
    }
    
    listar_Professor(Professores);
    return ;
}
    
void alterar_professor(int qtd,Lista_Prof Professores[])
{
    int alt;
    int op;
    int ver;
    int altnum,altdia,altmes,altano;
    char altname[50];
    char altchar;
    if(qtd>0)
    {
        printf("Informe o Professor que quer alterar\n");
        printf("\n");
        listar_Professor(Professores);
        scanf("%d",&alt);
        alt--;
        printf("Informe que dado alterar\n");
        printf("\n");
        printf("1.Matricula\n");
        printf("2.Nome\n");
        printf("3.Data de Nascimento\n");
        printf("4.CPF\n");
        printf("5.Sexo\n");
        scanf("%d",&op);
        getchar();
    }
    else
    {
        printf("Nenhum Professor Cadastrado\n");
        return;
    }
    
    switch(op)
    {
        case 1:
        {
            printf("Informe a nova matricula\n");
            scanf("%d",&altnum);
            ver=validarmatriculaprof(altnum,Professores);
            if(ver==1)
            {
                Professores[alt].matricula=altnum;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_MATRICULA_INVALIDA###\n");
                break;
            }
        }
        case 2:
        {
            printf("Informe o novo nome\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarnome(altname);
            if(ver==1)
            {
                strcpy(Professores[alt].nome,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_NOME_INVALIDO###\n");
                break;
            }
        }
        case 3:
        {
            printf("Informe a nova Data de Nascimento\n");
            printf("Dia:\n");
            scanf("%d",&altdia);
            printf("Mes:\n");
            scanf("%d",&altmes);    
            printf("Ano:\n");
            scanf("%d",&altano);
            ver=validardtnasc(altdia,altmes,altano);
            if(ver==1)
            {
                Professores[alt].dtnasc.dia=altdia;
                Professores[alt].dtnasc.mes=altmes;
                Professores[alt].dtnasc.ano=altano;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_DATA_INVALIDA###\n");
                break;
            }
        }
        case 4:
        {
            printf("Informe o novo CPF\n");
            fgets(altname,50,stdin);
            size_t ln= strlen(altname)-1;
            if(altname[ln]=='\n')
                altname[ln]='\0';    
            ver=validarcpf(altname);
            if(ver==1)
            {
                strcpy(Professores[alt].CPF,altname);
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_CPF_INVALIDO###\n");
                break;
            }
        } 
        case 5:
        {
            printf("Informe o novo sexo\n");
            scanf("%c",&altchar);
            ver=validarsexo(altchar);
            if(ver==1)
            {
                Professores[alt].sexo=altchar;
                printf("\n###ALTERAÇÃO REALIZADA COM SUCESSO###\n");
                break;
            }
            else
            {
                printf("\n###ERRO_SEXO_INVALIDA###\n");
                break;
            }
        }
    }
       
    return;
}
int menu_professor(int qtdprof,Lista_Prof Professor[])
{
    
    int opcao;
    int status_matricula;
    
    
    while(opcao!=8)
    {
        opcao=menu_opcoesprofessores();
        switch(opcao)
        {
            case 1:
            {
                if(qtdprof<TAMANHO_LISTA)
                {   
                    printf("\n###CADASTRO DE PROFESSOR###\n");
                    status_matricula = matricula_Professor(qtdprof,Professor);
                    if(status_matricula==1)
                    {
                    printf("\n### MATRICULA REALIZADA COM SUCESSO###\n");
                    qtdprof++;
                    printf("\n");
                    }
                    else
                    printf("\n###FALHA NA MATRICULA###\n");
                    Professor[qtdprof].matricula=-1;
                    printf("\n");
                    break;
                } 
                else
                {
                    printf("\n###NUMERO_MAXIMO_ATINGIDO###\n");
                    break;
                }      
            
        }
            case 2:
            {
                printf("###LISTA DE PROFESSORES###\n");
                listar_Professor(Professor);
                break;
            }
            case 3:
            {
                printf("###REMOVER Professores###\n");
                if(qtdprof>0)
                {
                    retirar_Professor(qtdprof,Professor);
                    qtdprof--;
                }
                else
                    printf("\n###NENHUM_PROFESSOR_CADASTRADO###\n");
                break;
            }
            case 4:
            {
                printf("\n###ALTERAR DADOS DE PROFESSORES###\n");
                alterar_professor(qtdprof,Professor);
                break;
            }
            case 5:
            {
                printf("###LISTA DE PROFESSORES POR NOME###\n");
                listar_professor_nome(qtdprof,Professor);
                break;
            }
            case 6:
            {
                printf("###LISTA DE PROFESSORES POR SEXO###\n");
                listar_professor_sexo(qtdprof, Professor);
                break;
            }
            case 7:
            {
                printf("###LISTA DE PROFESSORES POR DATA DE NASCIMENTO###\n");
                listar_professor_data(qtdprof, Professor);
                break;
            }
            case 8:
            {
                printf("\n###SAINDO DO MENU DE Professores###\n");
                break;
            }
        }   
    }               
    
    return qtdprof;
}

int menu_opcoesprofessores()
{
    int op;
    
    printf("###MENU PROFESSORES###\n");
    printf("Informe a opcao\n");
    printf("\n");
    printf("1.Cadastro de Professores\n");
    printf("2.Listar Professores\n");
    printf("3.Remover Professores\n");
    printf("4.Alterar dados de Professores\n");
    printf("5.Listar Professores por Nome\n");
    printf("6.Listar Professores por Sexo\n");
    printf("7.Sair\n");
    scanf("%d",&op);
    return op;
}

int validarmatriculaprof(int mat, Lista_Prof Professores[])
{
    int icont=0;
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(mat==Professores[x].matricula)
            icont++;
    }
    if(mat>=-1 && icont<=1)
        return 1;
    else
        return 0;
}

void listar_professor_nome(int qtd,Lista_Prof Professores[])
{
    int i, j;
    Lista_Prof aux;

    for(i=1;i<qtd;i++)
    {
        aux=Professores[i];
        for(j=i;j>0 && (strcmp(aux.nome,Professores[j-1].nome)<0);j--)
            Professores[j]=Professores[j-1];
        Professores[j]=aux;
    }
    for(i=0,j=1;i<qtd;i++,j++)
        printf("\n%d.%s\n",j,Professores[i].nome);
}

void listar_professor_sexo(int qtd,Lista_Prof Professores[])
{
    int x, aux;
    
    printf("\nSexo Feminino:\n");
    for(x=0,aux=1;x<qtd;x++)
    {
        if(Professores[x].sexo=='f' || Professores[x].sexo=='F') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }
    printf("\nSexo Masculino:\n");

    for(x=0,aux=1;x<qtd;x++)
    {
        if(Professores[x].sexo=='m' || Professores[x].sexo=='M') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }

    printf("\nSexo Outro:\n");

    for(x=0,aux=1;x<qtd;x++)
    {
        if(Professores[x].sexo=='o' || Professores[x].sexo=='O') 
        {
            printf("%d.%s\n",aux,Professores[x].nome);
            printf("\n");
            aux++;
        }
    }
}

void listar_professor_data(int qtd,Lista_Prof Professores[]){

    int iCont, jCont;
    Lista_Prof aux;

    for(iCont = 1; iCont<qtd; iCont++){

        aux= Professores[iCont];
        
        for(jCont= iCont; (jCont>0) && (aux.dtnasc.ano< Professores[jCont - 1].dtnasc.ano); jCont--)
            Professores[jCont]=Professores[jCont-1];

        Professores[jCont] = aux;
    }
    for(iCont = 1; iCont<qtd; iCont++){

        aux= Professores[iCont];
        
        for(jCont= iCont; (jCont>0) && (aux.dtnasc.mes< Professores[jCont - 1].dtnasc.mes) && (aux.dtnasc.ano==Professores[jCont - 1].dtnasc.ano); jCont--)
            Professores[jCont]=Professores[jCont-1];

        Professores[jCont] = aux;
    }
    for(iCont = 1; iCont<qtd; iCont++){

        aux= Professores[iCont];

        for(jCont= iCont; (jCont>0) && (aux.dtnasc.dia< Professores[jCont - 1].dtnasc.dia) && (aux.dtnasc.ano==Professores[jCont - 1].dtnasc.ano) && (aux.dtnasc.mes==Professores[jCont - 1].dtnasc.mes); jCont--)
            Professores[jCont]=Professores[jCont-1];

        Professores[jCont] = aux;
    }
    for(iCont=0,jCont=1;iCont<qtd;iCont++,jCont++)
        printf("\n%d.%s\n%d/%d/%d\n",jCont,Professores[iCont].nome,Professores[iCont].dtnasc.dia,Professores[iCont].dtnasc.mes,Professores[iCont].dtnasc.ano);
}