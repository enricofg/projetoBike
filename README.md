# projetoBike
Sistema de gerenciamento de aluguer de bicicletas para o IPL para a cadeira de Prog. I

# Resumo:
Programa em C para gerir uso de bicicletas entre os campi do IPL.
Os campi referidos são: as Residências, os Campus 1, Campus 2 e Campus 5.
Quando um usuário quiser efetuar o empréstimo de uma bicicleta, o mesmo 
deverá indicar para qual campus tem intenção de ir e qual é seu campus atual.
SE houver bicicletas disponíveis no campus atual, o empréstimo será efetuado.
SE NÃO houver, o usuário entrará em uma fila de espera.
APÓS chegar ao campus destino, o usuário devolve a bicicleta.

# Elementos:

	->15 Bicicletas:
		.designação única (ID da bicicleta automático) -> função de geração automática de ID de Bicicleta
		.modelo
		.status, que pode ser 1-disponível, 2-emprestada ou 3-danificada
		.campus que se localiza(1,2,5,3)
		
	->Usuário(máximo 50):
		.código (ID do usuário automático) -> função de geração automática de ID de Usuário
		.nome
		.telefoness
		.tipo (estudante, docente, técnico administrativo ou convidado)
		
	->Empréstimo:
		.número de registro, criado automaticamente (ID do empréstimo automático) -> função de geração automática de ID de Empréstimo
		.código do usuário (ID do usuário)
		.código da bicicleta (ID da bicicleta)
		.data e hora do empréstimo (função para pegar hora/data do sistema) 
			|» ("https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program")
		.campus de origem
		.campus de destino
			->Após devolução (fazer outra estrutura dentro de Empréstimo):
				.data e hora da devolução (função para pegar hora/data do sistema)
				.distância percorrida
	
	->Lista de espera: vetor dinâmico que contém os pedidos de empréstimo em espera de uma bicicleta
	
	
# Algoritmo Geral:
	Apresentação de um menu onde pode-se (dividir em submenus):
		- Informações sobre: Usuários atuais			- Empréstimos registrados
		- Distância total já percorrida				- Empréstimos em espera
		
		
		*1)Submenu - bicicletas:
			1.1)Inserir bicicleta (verificar ID se já não existe ID);
			1.2)Consultar bicicleta, pesquisa por ID (Estatísticas individuais: também listar quantidades de empréstimos total por bicicleta,  
			avarias e reparações totais por bicicletas [relação entre ambas em %], distância total percorrida por bicicleta);
			1.3)Listar todas bicicletas;
			
			1.4)Estatísticas totais: Listar quantidade de empréstimos totais, quantidade de avarias e reparações totais já registradas (relação entre ambas em %) e distância total 
			percorrida de todas as bicicletas.
		--
		
		*2)Submenu - usuários:
			2.1)Inserir usuário (verificar ID se já não existe ID);
			2.2)Alterar usuário: nome, telefone ou tipo;
			2.3)Consultar usuário, pesquisa por ID (Estatísticas individuais: quantidade de empréstimos efetuados e distância total percorrida);
			2.4)Listar todos usuários;
			
			2.5)Estatísticas totais: Listar quantidade de empréstimos totais e distância total percorrida de todos os usuários.
		--
		
		*3)Submenu - empréstimos e devolução:
			3.1.a)Registrar um empréstimo, verifica-se ID do usuário: se OK e houver bicicleta -> automaticamente lhe atribui uma das bicicletas disponíveis 
																	se OK e não houver bicicleta -> deve entrar no vetor de fila de espera com todas as informações inseridas
			3.1.b)Consultar empréstimos já efetuados por ID, se não houver devolução registrada, exibir mensagem "Aguardando devolução"
			3.1.c)Listar todos os empréstimos e se aguarda devolução;
			3.1.d)Listar vetor lista de espera;
			
			3.2)Registrar devolução de bicicleta: inserir ID do empréstimo e confirmar devolução;
			
			3.3.a)Cancelar pedido de empréstimo: inserir ID do empréstimo e confirmação -> vai em lista de espera e elimina elemento do vetor
			3.3.b)Alterar pedido de empréstimo: inserir ID do empréstimo e novo campus de destino
		--
		
		*4)Submenu - avarias e reparações:
			4.1)Registrar avaria de bicicleta, deve ser ascrecentada num log, de ficheiro de texto: 
				-> Designação da bicicleta, distância total percorrida, data e hora da avaria e descrição da avaria;
			4.2)Registrar reparações de bicicleta;
		--
		
		*5)Decidir critério para lista de espera - atribuir um critério para decidir a ordem dos usuários escolhidos em lista de espera(automaticamente deve ser 1 no início do programa):
			"1":Ordem de entrada do pedido,
			ou "2": Tipo de usuário (estudante, docente, técnico administrativo ou convidado),
			ou "3": Distância a percorrer;
		--
		
		*6)Histórico:
			6.1)Pesquisar ID de um usuário e listar os dados da última bicicleta que foi utilizada por ele;
			6.2)Pesquisar ID de um usuário e listar todos os empréstimos já feito por ele;
			6.3)Consulta de empréstimos por datas: inserir duas datas e listar todos os dados de empréstimos entre as datas
			
		*7)Estatísticas:
			7.1.a)Distância média percorrida por cada bicicleta (distancia total de cada uma / por numero total de bicicletas)
			7.1.b)Percentagem de empréstimos efetuados por cada tipo de usuário (nºde empréstimos feito por estudante, docente, tecnico administrativo ou convidado / nº total de empréstimos)
			7.1.c)Listar empréstimos por campus de origem e campus de origem com maior quantidade de empréstimos
			7.1.d)Consultar quantidade usuários que usaram uma determinada bicicleta: consultar por ID de bike
			
			7.2)Listar todos os utentes por ordem de descrescente da quantidade de empréstimos efetuados;
		--
		
	*Funcionalidades
		.Armazenar e ler todas as informações em ficheiros binários
		
		
# Possíveis funcionalidades adicionais
	- Criação de senha (automaticamente gerada) para usuário, onde ele deve usá-la para identificar-se no momento de empréstimo
	
		
		
