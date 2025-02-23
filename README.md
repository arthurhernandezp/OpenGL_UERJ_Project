# Instruções de Uso do Projeto Final - Computação Gráfica no OpenGL

## Introdução
Este projeto foi desenvolvido para a disciplina de Computação Gráfica e permite controlar um robô utilizando teclas específicas e o mouse.

## Imagens do Robô
Aqui estão algumas imagens ilustrando o funcionamento do robô:

![Robo](images/robo.png)
Diagrama de Classes

Abaixo está o diagrama de classes do projeto, gerado com Mermaid.js:

tclassDiagram
    class Robo {
        +Robo()
        +~Robo()
        +bool verificaAnguloBracos()
        +bool verificaTamanhoBraco()
        +bool verificaAnguloForearm()
        +bool verificaBracos()
        +void roboInicializa()
        +void roboHandleKeypress(unsigned char key, int x, int y)
        +void roboDrawScene()
        +float posicaoRobo
        -Cabeca *cabeca
        -Corpo *corpo
        -Garra *garraEsquerda
        -Garra *garraDireita
        -Perna *perna
    }

    class Cabeca {
        +void cabecaHandleKeypress(unsigned char key, int x, int y)
        +void cabecaDrawScene()
    }

    class Corpo {
        +void corpoHandleKeypress(unsigned char key, int x, int y)
        +void corpoDrawScene()
    }

    class Garra {
        +void garraHandleKeypress(unsigned char key, int x, int y)
        +void garraDrawScene()
    }

    class Perna {
        +void pernaHandleKeypress(unsigned char key, int x, int y)
        +void pernaDrawScene()
    }

    Robo --> Cabeca
    Robo --> Corpo
    Robo --> Garra : garraEsquerda
    Robo --> Garra : garraDireita
    Robo --> Perna

## Controles do Robô

### Movimentação da Cabeça
- **Girar para a esquerda:** `u`
- **Girar para a direita:** `i`
- **Levantar a cabeça:** `p`
- **Abaixar a cabeça:** `o`

### Movimentação do Corpo
- **Rotacionar somente o corpo do robô:** `z`

### Controles do Braço
- **Aumentar o tamanho do braço:** `1`
- **Diminuir o tamanho do braço:** `2`
- **Abrir o braço:** `4`
- **Fechar o braço:** `3`

### Controles da Garra
- **Abrir a garra:** `5`
- **Fechar a garra:** `6`

## Controles da Câmera

### Zoom
- **Tirar zoom:** Scroll do mouse para baixo
- **Dar zoom:** Scroll do mouse para cima

### Movimentação
- **Olhar para a direita:** `Seta Direita`
- **Olhar para a esquerda:** `Seta Esquerda`
- **Olhar para cima:** `Seta Cima`
- **Olhar para baixo:** `Seta Baixo`

### Rotação
- **Rotacionar para direita/esquerda:** Botão esquerdo do mouse + mover
- **Rotacionar para cima/baixo:** Botão direito do mouse + mover

## Movimentação do Robô
Para movimentar o robô, utilize a mecânica onde apenas o próprio robô consegue girar as rodas:
1. **Reduza o tamanho do braço ao mínimo:** pressione `2` repetidamente.
2. **Coloque o braço mais colado ao corpo:** pressione `3`.
3. **Mova o robô para frente:** pressione `w` (desde que esteja na angulação da roda).
4. **Mova o robô para trás:** pressione `s` (desde que esteja na angulação da roda).

## Tabela de Comandos

| Funcionalidade             | Ação                                 | Comando |
|----------------------------|--------------------------------------|---------|
| **Movimentação da Cabeça**   | Girar para a esquerda             | `u`     |
|                            | Girar para a direita              | `i`     |
|                            | Levantar a cabeça                | `p`     |
|                            | Abaixar a cabeça                 | `o`     |
| **Movimentação do Corpo**   | Rotacionar somente o corpo        | `z`     |
| **Controles do Braço**      | Aumentar o tamanho do braço       | `1`     |
|                            | Diminuir o tamanho do braço      | `2`     |
|                            | Abrir o braço                    | `4`     |
|                            | Fechar o braço                   | `3`     |
| **Controles da Garra**     | Abrir a garra                     | `5`     |
|                            | Fechar a garra                    | `6`     |
| **Controles da Câmera**    | Tirar zoom                        | Scroll para baixo |
|                            | Dar zoom                          | Scroll para cima  |
|                            | Olhar para a direita              | `Seta Direita`    |
|                            | Olhar para a esquerda             | `Seta Esquerda`   |
|                            | Olhar para cima                   | `Seta Cima`       |
|                            | Olhar para baixo                  | `Seta Baixo`      |
| **Rotação da Câmera**    | Rotacionar para direita/esquerda  | Botão esquerdo do mouse + mover |
|                            | Rotacionar para cima/baixo        | Botão direito do mouse + mover |
| **Movimentação do Robô**  | Reduzir o tamanho do braço ao mínimo | `2` (repetidamente) |
|                            | Colocar o braço mais colado ao corpo | `3` |
|                            | Mover o robô para frente         | `w`     |
|                            | Mover o robô para trás           | `s`     |

---
Este documento serve como um guia rápido para uso do software. Para mais informações, consulte a documentação completa no repositório.

