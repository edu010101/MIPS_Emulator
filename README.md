<h1 align="center">Tutorial de uso MipsEmulator</h1>

<h2 align="center"> Requirements </h2>

```bash
sudo apt install cmake
sudo apt install g++
```

<h2 align="center">Introdução</h2>


O MipsEmulator é como o nome diz um emulador da arquitetura MIPS, que pode ser executado em qualquer disposito x86 que possua as biblotecas acima instaladas.
A utilização de um emulador da arquitetura MIPS tem diversas aplicações, dado que no passado ela foi utilizada em inúmeros dispositivos famosos, incluindo o video game playstation 2, dado a idade da arquitetura e os componentes atuais é possível emular um video game inteiro em um sistema embarcado como um carro e um celular.  


<h2 align="center"> Organização do trabalho</h2>


No diretório deste repositório vocẽ irá encontrar diversos arquivos muito bem organizados, onde os arquivos .cpp represetam o código em si do emulador e das instruções, e junto a demo e seus binários já compilados. Além disso, existe uma pasta de tests que contém outros exemplos de códigos em MIPS32 que foram testados.
O relatório do trabalho se encontra no arquivo "Trabalho-Arq2(Alberto_Eduardo).pdf".


<h2 align="center">Como usar</h2>


Basta você executar o arquivo "emulador", que é um CMake, para isso é necessário inserir o seguinte comando no terminal:

```bash
./emulador caminho/do/seu/arquivo/de/text.bin caminho/do/seu/arquivo/de/data.bin > saida.txt
```
Observação: O nome dos arquivos "text.bin" e "data.bin" devem ser modificados de acordo com o código que se deseja executar.  

Por exemplo, para executar a demo utiliza-se o seguinte comando:

```bash
./emulador demo_text.bin demo_data.bin > saida.txt 
```
