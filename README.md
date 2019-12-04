# Router CNC

+ ## Descrição geral do sistema:

  + Um Router CNC é basicamente uma fresadora controlada eletronicamente por um
    sistema microprocessado e acionada por servomotores. A estrutura mecânica básica
    consiste em 3 eixos ortogonais, X, Y e Z, e um eixo rotativo, normalmente denominado eixo
    árvore ou spindle.<br>
    Está estrutra é comum a outros tipos de equipamentos industriais, apenas
    substituindo o eixo rotativo pela aplicação específica desejada. Por exemplo, um cabeçote
    extrusor, Figura 2, para uma impressora 3D ou um cabeçote Laser para uma cortadora a
    laser.

    + #### Diagrama de blocos do sistema:

      <p align="center">
        <img width="540" height="320" src="diagrams/system_block_diagram.PNG">
      </p>

    + #### Diagrama esquemático do sistema:
    
    <p align="center">
     <img width="540" height="320" src="diagrams/schematic_diagram.PNG">
     </p>
     
     
+ ## Placa de circuito impresso (PCB)

     + #### Preview
     
     <p align="center">
     <img width="1000" height="320" src="photos/pcb/pcb_preview.PNG">
     </p>
     
     + #### No Components View
     
     <p align="center">
     <img width="1000" height="320" src="photos/pcb/no_components_view.PNG">
     </p>

     + #### Top View
     
     <p align="center">
     <img width="1000" height="320" src="photos/pcb/top_view.PNG">
     </p>
     
     + #### Front View
     
     <p align="center">
     <img width="1000" height="320" src="photos/pcb/front_view.PNG">
     </p>
     
     + #### Back View
     
     <p align="center">
     <img width="1000" height="320" src="photos/pcb/back_view.PNG">
     </p>
     
     + #### Left View
     
     <p align="center">
     <img width="440" height="620" src="photos/pcb/left_view.PNG">
     </p>
     
     + #### Right View
     
     <p align="center">
     <img width="440" height="620" src="photos/pcb/right_view.PNG">
     </p>
       
     
+ ## Interface

  + O bloco de interface contém um display LCD 16x2 e 4 botões além da Interface Serial. A interface
    deverá apresentar a posição atual dos eixos e velocidade do spindle bem como possibilitar a
    modificação do estado da máquina, referência, manual ou automático.
  
   + O display apresenta 5 telas, sendo elas a tela inicial, de erro, de referenciamento, de posição e de fim de curso               positivo, as quais serão explicadas na seção **Funcionamento**. 

    + Os botões do teclado servem para:
      + P: Ativar/Desativar e Selecionar eixo para movimento manual.
      + +: Movimenta eixo no sentido positivo, horário (CW).
      + -: Movimenta eixo no sentido negativo, anti-horário (CCW)
      + S: Liga spindle em manual.
      
      
      <p align="center">
        <img width="280" height="95" src="photos/keyboard.PNG">
      </p>
      
    + Se o modo manual não estiver ativado, o controlador aceita comandos pela entrada
      serial, os comandos permitidos são listados abaixo:
      
      | Eixo    | Comando        | Descrição                                                                                                                                                                                                                            | Exemplo                                                                                                               |
      |---------|----------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
      | Spindle | S=             | Ajusta a velocidade (em RPM) de giro do eixo Spindle.<br>Limites:<br>Mínimo: 200 RPM<br>Máximo: 2000 RPM                                                                                                                             | S=1000<br>Ajusta a velocidade<br>em 1000RPM, mas<br>não liga o eixo.                                                  |
      |         | M3             | Liga o eixo spindle no sentido CW                                                                                                                                                                                                    |                                                                                                                       |
      |         | M4             | Liga eixo spindle no sentido CCW                                                                                                                                                                                                     |                                                                                                                       |
      | Eixos   | F=             | Modifica a velocidade de movimento dos eixos X, Y e Z.<br><br>Lento, Medio, Rapido                                                                                                                                                   | F=Medio<br>Ajusta a velocidade<br>de deslocamento<br>para a velocidade<br>média, mas não<br>movimenta nenhum<br>eixo. |
      |         | X=<br>Y=<br>Z= | Comanda o movimento para o eixo<br>especificado.<br>Caso mais de um eixo seja comandado na<br>mesma mensagem, os eixos deve ser<br>interpolados linearmente, válido somente<br>para os eixo X e Y.<br>*Respeitar os limites de curso | X=100<br>Move o eixo X para<br>a posição 100<br>X=10Y=5<br>Move ambos os<br>eixos com<br>interpolação linear.         |

    + As mensagens recebidas devem estar entre os caracteres delimitadores de início ($) e final (#) de mensagem.<br>
      + Exemplos de mensagem válida:<br>
          + Ex1.: Ajustar a velocidade do spindle para 1000 RPM, ativar o giro no sentido CW,
          ajustar a velocidade de movimento dos eixo em rápido e mover o eixo Z para a
          posição 10.
             <p align="center">
             <mark>$S=1000M3Z=10F=Rapido#</mark>
             </p>
          + Ex2.: Mover eixo X para a posição 10 e o eixo Y para a posição 5. Neste caso os
          eixo movem com a última velocidade ajustada (Lento, Medio, Rapido ).
            <p align="center">
            <mark>$X=10Y=5#</mark> 
            </p>

    + ## Funcionamento

      + Ao energizar o sistema a [tela inicial](photos/screens/initial_screen.jpg) é exibida, possiblitando retornar ao ponto de         referência quando pressionada a tecla S.
        Caso a entrada Cover Closed esteja aberta (chave aberta), e a tecla S for
        pressionada, o display informa o [erro](photos/screens/error_screen.jpg) durante 3 segundos e retorna à tela                     inicial.
        
      + Após satisfeita a condição da entrada Cover Closed, quando pressionada a tecla S,
        o sistema entra no modo de referência, nesse modo os motores dos eixo X, Y e Z se movem (em velocidade baixa) no sentido         horário até atingirem o sensores de referência, Home X, Home Y e Home Z. Durante este processo é mostrada a                     [tela de referenciamento](photos/screens/referencing_screen.jpg). Se em qualquer momento a entrada Cover Closed for             desacionada, a tela de [erro](photos/screens/error_screen.jpg) será mostrada por 3 segundos e retornar à [tela inicial]         (photos/screens/initial_screen.jpg) para reiniciar o processo.
       
      + Quando o processo de referenciamento estiver concluído e os sensores Home X, Home
        Y e Home Z estiverem ativados, será mostrada a [tela de posição](photos/screens/position_screen.jpg).
        
      + No processo de referência as variáveis de contagem de posição são zeradas e
        a variável eixos referenciados setada para um.
        
      + A partir da [tela de posição](photos/screens/position_screen.jpg) é possível mover 
        os eixo de forma manual (X, Y e Z), para tanto deverá ser pressionado a tecla P a fim de selecionar um dos eixos. O eixo
        selecionado é destacado com o caractere de sublinhado, indicando o movimento
        manual habilitado. Para sair do modo manual deve-se percorrer os eixos Z, X e Y,
        pressionando a tecla P, se a seleção atual for do eixo Y e a tecla P for pressionada
        novamente, o modo manual é desabilitado e a [tela de posição](photos/screens/position_screen.jpg) é mostrada novamente.
        
      + Em modo manual o eixo selecionado é movido através da teclas + e - . Quando
        pressionado a tecla + o eixo se move no sentido horário (CW), quando pressionada a tecla -
        em sentido anti-horário (CCW).
        
      + O movimento deve respeitar os limites físicos do curso mecânico de cada eixo,
          exposto abaixo:
          
          Curso de deslocamento dos Eixos:<br>
          ● Eixo X: 0... 200mm<br>
          ● Eixo Y: 0... 300mm<br>
          ● Eixo Z: 0... 150mm<br>
          
          Caso o eixo que está sendo movimentado atinja o final do curso, uma mensagem
          de [erro](photos/screens/overtravel_screen.jpg) deverá ser informada, indicando o eixo e o sentido em que ocorreu o             final do curso.
          
       + Durante o modo manual, o eixo spindle é ligado através da tecla S. Pressionando a
         tecla S uma vez o eixo Spindle liga em velocidade fixa de 500 RPM, Pressionando
         novamente S, o eixo Spindle desliga.

         Se o Spindle for ligado manualmente e o modo manual for desativado, o eixo é
         desligado automaticamente.
         
       + Se o modo manual não estiver ativado, o controlador aceita comandos pela entrada
         serial, como descrito acima.

+ ## Periféricos

  + **Chaves e Sensores:** São utilizadas chaves normalmente abertas para simular o comportamento dos sensores de referência (Home) e de proteção aberta (Cover Closed).
  + **MCU:** O microcontrolador é o ATMEGA328P (Arduino Mega 2560).
  + **Driver:** O driver utilizado é o circuito integrado L293D - Quadruple Half-H Drivers.
  + **Motor dos eixos** São utilizados motores de passo bipolares.
  + **Spindle** O motor do Spindle é simulado com um Motor DC unipolar e um encoder de 20PPR. A velocidade atual, não a programada, é mostrada no display da interface.
  + **Heart Beat:** Um LED foi utilizado para informar que o sistema está em execução. O LED permanece aceso caso o driver de saída esteja desabilitado.


+ ## Software
  
  + **IDE:** A IDE utilizada foi a [Sloeber](https://eclipse.baeyens.it/), IDE do Eclipse para Arduino.
  + **Bibliotecas utilizadas:** LiquidCrystal, [Bounce2](https://github.com/thomasfredericks/Bounce2) e as bibliotecas criadas contidas em [myLibs](https://github.com/jessenKS/Router-CNC/tree/master/myLibs).
  + **Arquivo .hex:** Ao compilar a aplicação, os arquivos .hex e .elf ficam localizados na pasta Release.
    

+ ## Autores

* **Felipe Tavares** - [felipe-tavares](https://github.com/felipe-tavares)
* **Jessen Krupinski Scariot** - [jessenKS](https://github.com/jessenKS)
