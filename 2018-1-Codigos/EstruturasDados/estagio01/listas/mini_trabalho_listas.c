#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 60

typedef struct disciplina { //lista encadeada
    char nome_disciplina[30];
    float nota_final;
    struct disciplina * prox_no;
} t_no_disciplina;

typedef struct aluno {
    char matricula[10];
    t_no_disciplina * lista_disciplinas; //armazena a cabe�a da lista das disciplinas
} t_elemento_aluno;

typedef struct alunos { //lista sequencial
    int ultimo_indice;
    t_elemento_aluno vetor_alunos[MAX_ALUNOS];
} t_alunos;

//----------------------------------- FUN��ES PARA LISTA SEQUENCIAL (ALUNOS)
t_alunos criarListaAluno() {
	t_alunos lista;

	lista.ultimo_indice = -1;

	return lista;
}

int isCheiaAlunos(t_alunos * lista) {
    return (lista->ultimo_indice == MAX_ALUNOS - 1);
}

int deslocaDireita(t_alunos * lista, int posicao) {
    int i = 0;

    for(i = lista->ultimo_indice + 1; i > posicao; i--)
        lista->vetor_alunos[i] = lista->vetor_alunos[i - 1];

    return 1;
}

int inserirDadosAluno(t_alunos * lista, int posicao, t_elemento_aluno dados_aluno) {
    if ( isCheiaAlunos(lista) || (posicao > lista->ultimo_indice + 1) || (posicao < 0) )
        return 0;

    deslocaDireita(lista, posicao);
    lista->vetor_alunos[posicao] = dados_aluno;
    (lista->ultimo_indice)++;
    return 1;
}

int comparaDadosAlunos(t_elemento_aluno dados_aluno1, t_elemento_aluno dados_aluno2) {
    return strcmp(dados_aluno1.matricula, dados_aluno2.matricula);
}

int getPosicaoAluno(t_alunos * lista, t_elemento_aluno dado_aluno) {
    int i;

    for (i = 0; i <= lista->ultimo_indice; i++)
        if (comparaDadosAlunos(lista->vetor_alunos[i], dado_aluno) == 0)
            return i;

    return -1;
}

int deslocaAlunosEsquerda(t_alunos * lista, int posicao) {
    int i;

    for (i = posicao; i < (lista->ultimo_indice); i++)
        lista->vetor_alunos[i] = lista->vetor_alunos[i + 1];

    return 1;
}

int removerDadosAluno(t_alunos * lista, int posicao) {
    if ( (posicao > lista->ultimo_indice) || (posicao < 0) )
        return 0;

    deslocaAlunosEsquerda(lista, posicao);

    (lista->ultimo_indice)--;

    return 1;
}

//----------------------------------- FUN��ES PARA LISTA ENCADEADA (DISCIPLINAS)
t_no_disciplina * criaNo() {
    t_no_disciplina * no = (t_no_disciplina *) malloc(sizeof(t_no_disciplina)); //no recebe uma �rea de mem�ria que � um ponteiro para t_n�

    if(no) //se n� for diferente de NULL ou 0:
        no->prox_no = NULL; //o elemento criado ser� o �ltimo da lista

    return no;
}

int isVaziaDisciplinas(t_no_disciplina * lista_disciplinas) {
    return (lista_disciplinas == NULL);
}

t_no_disciplina * getNoDisciplina(t_no_disciplina * lista_disciplinas, int posicao) {
    int index = 0;

    if(posicao < 0)
        return 0; //posi��o inv�lida

    while(lista_disciplinas != NULL) { //verifica a lista at� o �ltimo elemento
        if(index == posicao) //quando chegar na posi��o, retorna o n�
            return lista_disciplinas;

        lista_disciplinas = lista_disciplinas->prox_no;

        index++;
    }

    return 0; //posi��o inv�lida
}

int compara(t_no_disciplina disciplina01, t_no_disciplina disciplina02) {
    return strcmp(disciplina01.nome_disciplina, disciplina02.nome_disciplina);
}

int getPosicao(t_no_disciplina * lista_disciplinas, t_no_disciplina disciplina) { //verificar adequacao desta fun��o
    int posicao = 0;

    while(lista_disciplinas != NULL) {
        if(compara(*lista_disciplinas, disciplina) == 0)
            return posicao;

        lista_disciplinas = lista_disciplinas->prox_no;

        posicao++;
    }

    return -1;
}

int inserirDadosDisciplina(t_no_disciplina ** lista_disciplinas, int posicao, t_no_disciplina dados_disciplina) {
    t_no_disciplina * no_aux, * novo_no;

    if(posicao == 0) {  //criando o primeiro n�
        novo_no = criaNo();

        if(novo_no == NULL)
            return 0; //erro: mem�ria insuficiente

        strcpy(novo_no->nome_disciplina, dados_disciplina.nome_disciplina);
        novo_no->nota_final = dados_disciplina.nota_final;

        novo_no->prox_no = *lista_disciplinas; //o PROX_NO do novo n� recebe o endere�o guardado na lista_disciplinas

        *lista_disciplinas = novo_no; //lista_disciplinas recebe o endere�o do novo_no

        return 1;
    }
//inser��o ap�s a 1� posi��o, em lista n�o vazia
    no_aux = getNoDisciplina(*lista_disciplinas, posicao - 1); //pega o endere�o do n�  da posi��o anterior a que se quer inserir

    if(no_aux == NULL)
        return 0; //posi��o inv�lida

    novo_no = criaNo(); //cria o novo n�

    if(novo_no == NULL)
        return 0; //mem�ria insuficiente

    strcpy(novo_no->nome_disciplina, dados_disciplina.nome_disciplina);
    novo_no->nota_final = dados_disciplina.nota_final;

    novo_no->prox_no = no_aux->prox_no; //novo->prox recebe o endere�o do n� que vir� ap�s ele, que estava armazenado em p
    no_aux->prox_no = novo_no; //e p->prox receber� o enedere�o do novo n�

    return 1;
}

t_no_disciplina * getDisciplina(t_no_disciplina lista_disciplinas, int posicao) {
    t_no_disciplina * no = getNoDisciplina(&lista_disciplinas, posicao);

    if(no != NULL)
        return no;

    return NULL;
}

//------------------------------------ FUN��ES EXTRA
void fechaPrograma() {
    //free();
    system("cls");
    printf(">> Programa encerrado pelo usuario.\n");
}

void inserirDados(t_alunos * lista_alunos) {
    char matricula[10], disciplina[30];
    int contador_disciplinas = 1;
    t_elemento_aluno aluno;

    system("cls");

    printf("--- INSERIR DADOS ---\n\n");

    while(1) {
        printf("Digite os dados solicitaos ou 'parar' para sair \n");

        printf(">> MATRICULA: ");
        scanf("%s", matricula);

        if( ! strcmp(matricula, "parar"))
            break;

        strcpy(aluno.matricula, matricula);

        setbuf(stdin, NULL);

        while(1) {
            printf(">> NOME DA DISCIPLINA %d: ", contador_disciplinas);
            scanf("%[^\n]s", disciplina);

            if( ! strcmp(disciplina, "parar"))
                break;

            //strcpy(aluno.matricula, matricula);

            aluno.lista_disciplinas = criaNo();

            inserirDadosAluno(lista_alunos, 0, aluno);

            setbuf(stdin, NULL);

            contador_disciplinas++;
        }

        puts("");
    }


    system("pause");
    system("cls");
}

void exibirHistoricos(/*t_alunos * lista_alunos*/) {
    system("cls");
    printf("---- HISTORICO ----.\n");


    system("pause");
    system("cls");
}

void chamadasFuncoesMenu(int opcao, t_alunos * lista_alunos) {
    switch(opcao) {
        case 0:
            fechaPrograma();
            break;

        case 1:
            inserirDados(lista_alunos);
            break;

        case 2:
            exibirHistoricos();
            break;

        default:
            printf("\n>> Informe uma opcao valida.\n\n");
            system("pause");
            system("cls");
    }
}

int menu(t_alunos * lista_alunos) {
    int opcao = 0;

    while(1){
        printf("ALUNO: ALYSSON SILVA DE MORAIS\n");
        printf("DISCIPLINA: ESTRUTURA DE DADOS I\n");
        printf("PROFESSOR: WALACE BONFIM\n");

        printf("\n     HISTORICO ESCOLAR     \n\n");

        printf("1 - INSERIR MATRICULAS, DISCIPLINAS E NOTAS\n");
        printf("2 - EXIBIR HISTORICOS\n");
        printf("0 - SAIR\n");

        printf("\nDIGITE SUA OPCAO: ");
        scanf("%d", &opcao);

        chamadasFuncoesMenu(opcao, lista_alunos);

        if(opcao == 0)
            break;
    }
}

//---------------------------------------------------- MAIN
int main() {
    t_alunos lista_alunos01 = criarListaAluno();

    menu(&lista_alunos01);



/*    strcpy(lista_alunos_01.lista_alunos[0].matricula, "1520011423");
    lista_alunos_01.lista_alunos[0].lista_disciplinas = criaNo();


    printf("%s\n", lista_alunos_01.lista_alunos[0].matricula);
    printf("%s\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->nome_disciplina);
    printf("%.1f\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->nota_final);
    printf("%p\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->prox_no);

    strcpy(lista_alunos_01.lista_alunos[0].lista_disciplinas->nome_disciplina, "estrutura de dados I");
    lista_alunos_01.lista_alunos[0].lista_disciplinas->nota_final = 9.8;

    inserir(&lista_alunos_01.lista_alunos[0].lista_disciplinas, 0, *(lista_alunos_01.lista_alunos[0].lista_disciplinas));

    printf("%s\n", lista_alunos_01.lista_alunos[0].matricula);
    printf("%s\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->nome_disciplina);
    printf("%.1f\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->nota_final);
    printf("%p\n", lista_alunos_01.lista_alunos[0].lista_disciplinas->prox_no);
*/
    return 0;
}
