int cadastroAluno(int qtdaluno, Lista_aluno Aluno[], int mesAtual)//main do cadastro de alunos, qtdaluno e a struct vêm do main
{
    int x;
    int opcao;
    int status_matricula;
    
    //inicializando as matriculas como inativas
    status_aluno(Aluno);
    
    while(opcao!=4)
    {
        opcao=menu_opcoes();
        switch(opcao)
        {
            case 1:
            {
                printf("\n###CADASTRO DE ALUNO###\n");
                status_matricula = matricula_Aluno(qtdaluno, Aluno);
                if(status_matricula==1)
                {
                printf("\n### MATRICULA REALIZADA COM SUCESSO###\n");
                qtdaluno++;
                printf("\n");
                }
                else
                printf("\n###FALHA NA MATRICULA###\n");
                printf("\n");
                break;
            }
            case 2:
            {
                printf("###LISTA DE ALUNOS###\n");
                listar_aluno(Aluno);
                break;
            }
            case 3:
            {
                printf("###LISTA DE ALUNOS POR SEXO###\n");
                listar_aluno_sexo(Aluno);
                break;
            }
            case 4:
            {
                printf("###REMOVER ALUNOS###\n");
                qtdaluno=retirar_aluno(Aluno);
                break;
            }
            case 5:
            {
                printf("###ANIVERSARIANTES DO MES###\n");
                aniversariantesA(mesAtual, qtdaluno, Aluno);
                break;
            }
            case 6:
            {
                printf("\n###ALTERAR DADOS DE ALUNOS###\n");
                alterar_aluno(Aluno);
                break;
            }
            case 7:
            {
                printf("\n###SAINDO DO CADASTRO DE ALUNOS###\n");
                break;
            }
        
        }   
    }
    return qtdaluno;   
}
   
int matricula_Aluno(int qtd, Lista_aluno Alunos[])
{
    int v1,v2,v3,v4,v5;
    int ver;
    
    for(ver=0;ver<TAMANHO_LISTA;ver++)
    {
        if(Alunos[qtd].matricula!=-1)
            qtd++;
        else
            break;
    }
    
    
    
    printf("Informe a matricula do aluno\n");
    scanf("%d",&Alunos[qtd].matricula);
    getchar();
    
    printf("Informe o nome do Aluno\n");
    fgets(Alunos[qtd].nome,40,stdin);
    size_t ln= strlen(Alunos[qtd].nome)-1;
    if(Alunos[qtd].nome[ln]=='\n')
            Alunos[qtd].nome[ln]='\0';
    
    printf("Informe a dia do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.dia);
    
    printf("Informe a mes do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.mes);
    
    printf("Informe a ano do Nascimento\n");
    scanf("%d",&Alunos[qtd].dtnasc.ano);
    getchar();
        
    printf("Informe o CPF do Aluno\n");
    fgets(Alunos[qtd].CPF,15,stdin);
    ln= strlen(Alunos[qtd].CPF)-1;
    if(Alunos[qtd].CPF[ln]=='\n')
            Alunos[qtd].CPF[ln]='\0';
        
    printf("Infome o sexo do Aluno(F, M ou O)\n");
    scanf("%s",&Alunos[qtd].sexo);
    
    //Validação dos dados inseridos//
    v1=validarnome(Alunos[qtd].nome);
    v2=validardtnasc(Alunos[qtd].dtnasc.dia,Alunos[qtd].dtnasc.mes,Alunos[qtd].dtnasc.ano);
    v3=validarcpf(Alunos[qtd].CPF);
    v4=validarsexo(Alunos[qtd].sexo);
    v5=validarmatricula(Alunos[qtd].matricula);
    
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

int validarnome(char nm[])
{
    int tam;
    tam=strlen(nm);
    if(tam>20)
        return 1;
     else
        return 0;
}

int validardtnasc(int d,int m,int a)
{
    if( d<=31 &&  d>0)
    {
        if( m<=12 &&  m>0)
        {
            if(m==2)
        	{
        		if(a%4==0 && a%100!=0)
        		{
        			if (d>=30)
        				return 0;
				}
				else if (d>=29)
					return 0;
			}
            
            if( a > 0)
                return 1;
            else 
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
}

int validarcpf(char c[])
{
    int len;
    len = strlen(c);
    if(len==14 || len==11)
        return 1;
    else
        return 0;
}

int validarsexo(char s)
{
    if(s=='M' || s=='m' || s=='F' || s=='f' || s=='O'  || s=='o')
        return 1;
    else
        return 0;
}

int validarmatricula(int mat)
{
    if(mat>=-1)
        return 1;
    else
        return 0;
}

int menu_opcoes()
{
    int op;
    
    printf("###MENU ESCOLA###\n");
    printf("Informe a opcao\n");
    printf("\n");
    printf("1.Cadastro de Alunos\n");
    printf("2.Listar Alunos\n");
    printf("3.Listar Alunos por Sexo\n");
    printf("4.Remover Alunos\n");
    printf("5.Aniversariantes do Mes\n");
    printf("6.Alterar Cadastro\n");
    printf("7.Voltar ao Menu Principal\n");
    scanf("%d",&op);
    return op;
}

void listar_aluno(Lista_aluno Alunos[])
{
    int x, aux;
    
    for(x=0;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].matricula!=-1) 
        {
            printf("%d. Nome: %s\n",x+1,Alunos[x].nome);
            printf("Matricula: %d\n",Alunos[x].matricula);
            printf("Data de Nascimento : %d/%d/%d\n",Alunos[x].dtnasc.dia,Alunos[x].dtnasc.mes,Alunos[x].dtnasc.ano);
            printf("CPF : %s\n",Alunos[x].CPF);
            printf("Sexo : %c\n",Alunos[x].sexo);
            printf("\n");
        }
    }
}

void listar_aluno_sexo(Lista_aluno Alunos[])
{
    int x, aux;
    
    printf("\nSexo Feminino:\n");
    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='f' || Alunos[x].sexo=='F') 
        {
            printf("%d. Nome: %s\n",aux,Alunos[x].nome);
            printf("\n");
            aux++;
        }
    }
    printf("\nSexo Masculino:\n");

    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='m' || Alunos[x].sexo=='M') 
        {
            printf("%d. Nome: %s\n",aux+1,Alunos[x].nome);
            printf("\n");
            aux++;
        }
    }

    printf("\nSexo Outro:\n");
    for(x=0,aux=1;x<TAMANHO_LISTA;x++)
    {
        if(Alunos[x].sexo=='o' || Alunos[x].sexo=='O') 
        {
            printf("%d. Nome: %s\n",aux+1,Alunos[x].nome);
            printf("\n");
        }
    }
}

void status_aluno(Lista_aluno Alunos[])
{
    int x;
    
    for(x=0;x<TAMANHO_LISTA;x++)
        Alunos[x].matricula = -1;
}

void retirar_aluno(int qtd,Lista_aluno Alunos[])
{
    int del;
    int cont;
    printf("Informe o número do Aluno\n");
    listar_aluno(Alunos);
    scanf("%d",&del);
    del--;
    for(cont=del;Alunos[cont].matricula!=-1;cont++)
    {
        Alunos[cont].matricula=Alunos[cont+1].matricula;
        Alunos[cont].sexo=Alunos[cont+1].sexo;
        Alunos[cont].dtnasc.dia=Alunos[cont+1].dtnasc.dia;
        Alunos[cont].dtnasc.mes=Alunos[cont+1].dtnasc.mes;
        Alunos[cont].dtnasc.ano=Alunos[cont+1].dtnasc.ano;
        strcpy(Alunos[cont].nome,Alunos[cont+1].nome);
        strcpy(Alunos[cont].CPF,Alunos[cont+1].CPF);
    }
}
    
void aniversariantesA(int mesAtual,int qtdAlunos, Lista_aluno Aluno[])
{
    int x;
    
    printf("\n###ANIVERSARIANTES DO MES###\n")

    for(x=0;x<qtdAlunos;x++)
    {
        if(Aluno[x].dataNascimento.mes==mesAtual)
        {
            printf("%s\n",Aluno[x].nome);
        }
    }
    printf("\n");
}

void alterar_aluno(Lista_aluno Alunos[])
{
    int alt;
    int op;
    int ver;
    int altnum,altdia,altmes,altano;
    char altname[50];
    char altchar;
    
    printf("Informe o Aluno que quer alterar\n");
    listar_aluno(Alunos);
    scanf("%d",&alt);
    alt--;
    printf("Informe que dado alterar\n");
    printf("1.Matricula\n");
    printf("2.Nome\n");
    printf("3.Data de Nascimento\n");
    printf("4.CPF\n");
    printf("5.Sexo\n");
    scanf("%d",&op);
    getchar();
    
    switch(op)
    {
        case 1:
        {
            printf("Informe a nova matricula\n");
            scanf("%d",&altnum);
            ver=validarmatricula(altnum);
            if(ver==1)
            {
                Alunos[alt].matricula=altnum;
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
                strcpy(Alunos[alt].nome,altname);
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
                Alunos[alt].dtnasc.dia=altdia;
                Alunos[alt].dtnasc.mes=altmes;
                Alunos[alt].dtnasc.ano=altano;
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
                strcpy(Alunos[alt].CPF,altname);
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
                Alunos[alt].sexo=altchar;
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