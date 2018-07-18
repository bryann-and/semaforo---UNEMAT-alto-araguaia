# semaforo-UNEMAT-alto-araguaia
Projeto Semáforo Alto Araguaia

Bryan Duarte, Natanael Paião.

Projeto de implementação de um semáforo inteligente, para controlar o fluxo de veículos na avenida principal de Alto Araguaia, na intersecção com a MT-100.
O semáforo ficara alternando entre as duas vias principais, e os semáforos das vias adjacentes ficarão sempre fechados, até que um veículo solicite a abertura para que ele possa passar, esse solicitação ocorrera através de um sensor instalado abaixo do asfalto, que detectara quando um veículo está no local.
O semáforo também controlara o fluxo de pedestres, em cada esquina, haverá um painel com um botão para que um pedestre solicite a passagem, este painel também possui luzes de aviso (se o pedestre pode passar ou não) e possui um aviso sonoro quando a passagem para pedestres estiver prestes a fechar.
O sistema também possui um painel para controle manual dos semáforos, em caso de acidente, por exemplo, um guarda de transito pode manualmente controlar o fluxo das vias, possibilitando a limpeza da pista sem bloquear totalmente o fluxo de veículos.
Para prototipação foram usados: um arduino Mega, leds RGB para representar os semáforos, um buzzer para representar o aviso sonoro, botões como simuladores dos sensores abaixo do asfalto e botões para o controle manual.
Código

void verde (int, int);Recebe os dois pinos do semáforo, e faz ele ficar verde.

void vermelho(int, int);Recebe os dois pinos do semáforo, e faz ele ficar amarelo por 2 segundos, e depois fica vermelho.

void fecha_tudo();Torna todos os sinais vermelhos.

void abre_lado(int);Recebe qual sensor foi acionado, e abre aquele semáforo para passagem.

void pd_parar();Aciona o aviso sonoro, e logo após fecha a passagem de pedestres.

void pd_aberto();Possibilita a passagem do pedestre.

void controle_manual();Ativa o controle manual dos semáforos.

void inverte(int, int);Inverte o estado atual do semáforo, se estiver verde, ficara vermelho e vice-versa.
