typedef struct elementos {
	char nome[50];
} t_elemento;

typedef struct no {
	t_elemento dado;
	struct no * prox;
} t_no;

typedef t_no * t_lista;	

t_no * criaNo() {
	t_no * no = (t_no *) malloc(sizeof(t_no));
	
	if(no)
		no->prox = NULL;

	return no;		
}

int main() {
	
	t_lista m_No; //ponteiro para um t_no
	t_lista no_aux; //ponteiro para um t_no
	t_lista ultimo_no; //ponteiro para um t_no
	
	m_No = criaNo(); //aloca e retorna o endere�o alocado 1� n�
	ultimo_no = m_No; //como s� existe um �nico n�, ent�o ele tamb�m � o �ltimo
	
	while(1) {
		no_aux = criaNo(); //aloca uma mem�ria para o pr�ximo t_no, que �, temporariamente, chamado de auxiliar
		ultimo_no->prox = no_aux; //o �ltimo n� sempre recebe o endere�o alocado do n� criado
		ultimo_no = no_aux; //
	}
	 
	
	return 0;
}


