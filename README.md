# SpaceEvaders
Trabalho Final da disciplina de Fundamentos de Computação Gráfica.

## Contribuições de cada membro:

### Lucca Kroeff:
- Transformações geométricas controladas pelo usuário (rotate em z da espaçonave)
- Câmera livre e câmera look-at
- Três tipos de testes de intersecção
- Animações baseadas no tempo

### Sofia Braga:
- Instâncias de objetos
- Modelos de Iluminação Difusa e Blinn-Phong
- Modelos de Interpolação de Phong e Gouraud
-  Movimentação com curva Bézier cúbica

Fizemos em conjunto o mapeamento de texturas em todos os objetos, porém a colega Sofia teve maior foco nesta atividade.

## Chat GPT
Nosso uso do Chat GPT foi somente para casos onde não conseguimos encontrar erros em nosso código e o utilizamos, dessa forma, como forma de debugar nosso código, apesar de em muitos casos a ferramenta não ter conseguido encontrar os erros no código e tivemos que encontrar nós mesmos. Em alguns casos ele encontrava os erros de forma correta e isso nos auxiliava a focar mais nos requisitos necessários para o trabalho, e não em erros de nomeação de funções ou variáveis, por exemplo.

## Utilização da aplicação
Basta clicar nos botões ASWD para movimentação da espaçonave:
A- movimento para a esquerda
D- movimento para a direita 
S- movimento para baixo 
W- movimento para cima
Z - rotaciona espaçonave
F - muda a visão da câmera (de livre para look-at ou vice-versa)

Basta clicar no mouse para o poiscionamento da câmera

### Objetivos do jogo
Coletar as moedas dirigindo a espaçonave sem bater em nenhum obstáculo. Caso você colida com algum meteoro ou a lua, você volta para o início do jogo. O jogo não possui um fim, de modo que se você coletar todas as moedas ainda pode andar pelo mapa (pensamos que isso seria melhor para a visualização do jogo e requisitos que ele atingiu). Ademais, se você andar muito em alguma direção do mapa, também voltará ao início.

## Compilação e execução
Para compilar, como utilizamos Code::Blocks, somente é necessário clicar no botão de rodar o programa para o mesmo ser executado.

## Conceitos de Computação Gráfica listado nos requisitos
As malhas poligonais complexas foram utilizadas em todos os objetos da nossa aplicação, ou seja, na espaçonave, moedas, asteroides, lua e a esfera que compõe o plano de fundo. As transformações geométricas controladas pelo usuário são tanto a mudança da perspectiva da câmera (de look-at para free camera e vice-versa, feitos com a tecla V) quanto a tecla Z que faz uma rotação (ou "flip") da espaçonave. A câmera livre e câmera look-at são presentes na nossa aplicação ao clicarmos na tecla V. O jogo inicia com a câmera sendo look-at e, ao pressionarmos V, podemos mudar para uma câmera livre e, se quisermos voltar ao estado de look-at basta clicar de novo em V. As instâncias de objetos foram feitas ao baixarmos modelos 3-D para todos os objetos e, seguindo o Laboratório 4, baixando eles para visualização no nosso programa. Três tipos de testes de intersecção foram realizados no nosso programa, que foram: colisão da espaçonave com moedas (paralelepípedo com paralelepípedo), colisão da espaçonave com asteroides (paralelepípedo com paralelepípedo), colisão da espaçonave com a lua (paralelepípedo com ponto), e finalmente colisão da espaçonave ao nos movimentarmos por muito tempo em direção ao fim do mapa (paralelepípedo com plano, pois colocamos planos antes do fim do mapa para este teste de colisão). Modelos de Iluminação Difusa foram usadas em todos os objetos, exceto na esfera do plano de fundo, pois sua cor é dada somente pelo carregamento de sua textura, e Blinn-Phong, que foi utilizado para gerar a iluminação da Lua e dos asteroides. Todos os objetos tiveram sua cor renderizada no shader_fragment, a espaçonave também teve sua Interpolação utilizando Phong Shading, exceto a moeda, que utilizou a Interpolação de Gouraud Shading. Mapeamento de texturas em todos os objetos foi realizado e pode ser visto ao abrir a implementação, para isto utilizamos jpg ou png para a textura de cada objeto. O asteroide mais para o fundo da visão inicial da espaçonave utilizou para sua movimentação curva Bézier cúbica, com p1 e p4 mais para baixo do mapa e p2 e p3 mais para cima, para melhor simulação de uma curva. Finalmente, animações baseadas no tempo (delta t) foram utilizadas em todo o trabalho, exceto com curva de Beziér cúbica que teve sua animação baseada neste método, e com o "t" da fórmula variando entre 0 e 1 através de uma variável que diminuía do tempo atual do quadro o tempo de início da aplicação, e, depois de passados 10 segundos, atualizava o estado de início da curva de Beziér e contava novamente até aproximadamente 10.





