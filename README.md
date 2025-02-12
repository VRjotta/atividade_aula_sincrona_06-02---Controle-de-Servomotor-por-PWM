<<<<<<< HEAD
### atividade_aula_sincrona_06-02 - Controle de Servomotor por PWM

## Descrição do Projeto
Este projeto tem como objetivo controlar um servomotor utilizando PWM com o Raspberry Pi Pico W, dentro da plataforma BitDogLab. A GPIO 22 foi configurada para gerar um sinal PWM de 50Hz para posicionar o servo em diferentes ângulos. Além disso, o LED RGB conectado à GPIO 12 foi utilizado para observar seu comportamento conforme a movimentação do servo.

## Pré-requisitos para abrir o projeto

Para configurar o ambiente de desenvolvimento, siga as instruções abaixo:

### 1. Instalar o Visual Studio Code
- Acesse o site oficial e faça o download: [Visual Studio Code](https://code.visualstudio.com/).
- Instale o programa e configure conforme necessário.
- Adicione a extensão [Wokwi](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode) e faça sua integração com o VS CODE para simular o hardware.

### 2. Instalar o CMake
- Baixe o instalador do CMake: [CMake](https://cmake.org/download/).
- Durante a instalação, marque a opção **"Add CMake to the system PATH"**.
- Conclua a instalação.

### 3. Instalar o GCC para ARM
- Baixe o compilador ARM GNU em: [GCC ARM Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm).
- Após a instalação, adicione o diretório do executável ao **PATH**:
  - Vá para **Configurações do Sistema > Variáveis de Ambiente**.
  - Edite a variável `Path` e adicione:
    ```
    C:\Program Files (x86)\Arm GNU Toolchain\<versão>\bin
    ```
  - Substitua `<versão>` pela versão instalada.

### 4. Instalar o Git
- Faça o download: [Git para Windows](https://git-scm.com/).
- Instale o programa e configure-o.
- Abra o terminal (Git Bash ou CMD) e configure seu nome e e-mail:
  ```bash
  git config --global user.name "Seu Nome"
  git config --global user.email "seu.email@exemplo.com"


## Implementação

1. Configurar a GPIO 22 com uma frequência de 50Hz (Período de 20ms).
2. Ajustar o ciclo de trabalho (Duty Cycle) para:
   - 180° (2.400µs) e aguardar 5 segundos.
   - 90° (1.470µs) e aguardar 5 segundos.
   - 0° (500µs) e aguardar 5 segundos.
3. Criar uma rotina de movimentação suave entre 0° e 180°, com incrementos de ±5µs a cada 10ms.
4. Observar o comportamento do LED RGB (GPIO 12) durante a movimentação do servo.

### Executar na BitDogLab
1. Conecte a BitDogLab ao PC e entre no modo BOOTSEL.
2. A placa aparecerá como uma unidade USB.
3. Arraste o arquivo `servo_pwm.uf2` para essa unidade.

## Observações sobre o LED RGB (GPIO 12)
- Quando o servo está em 0° (500µs): O LED acende (vermelho).
- Quando o servo está em 90° (1470µs): O LED apaga.
- Quando o servo está em 180° (2400µs): O LED acende novamente (azul).
- Durante o movimento suave: O LED pode piscar ligeiramente.

## Conclusão
Este projeto demonstrou como controlar um servomotor via PWM no Raspberry Pi Pico W e analisar o comportamento do LED RGB na plataforma BitDogLab. O servo foi posicionado corretamente nos ângulos de 0°, 90° e 180°, e a movimentação suave foi realizada com sucesso.

## Vídeo Ensaio
O vídeo ensaio com a apresentação da solução e os resultados obtidos pode ser acessado no seguinte link:
[Inserir Link do Vídeo Aqui]

## Autor
Jotta

=======
