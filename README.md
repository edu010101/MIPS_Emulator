<h1 align="center">Tutorial de uso MipsEmulator</h1>

Para usar o MipsEmulator, você precisa ter o cmake e o g++ instalados em sua máquina.

```bash
sudo apt install cmake
sudo apt install g++
```

<h2 align="center">Introdução</h2>
O MipsEmulator é como o nome diz um emulador da arquitetura mips, que pode ser executado em qualquer dispositov x86 que possua as biblotecas acima instaladas.
Seu potencial é grandíssimo dados que o playstaion 2 usa a arquitetura mips, e com isso é possível emular jogos de playstation 2 em um computador comum.
Mais do que isso, é possivel emular e jogar jogos em embarcados como carros, celulares, e até mesmo em um microondas.


<h2 align="center">Como usar</h2>
Basta você executar o arquivoMipsEmulator, que é um CMake, para isso é necessário executar o seguinte comando:

```bash
./emulador text.bin data.bin > saida.txt
```
Observação: O nome dos arquivos "text.bin" e "data.bin" devem ser modificados de acordo com o código que se deseja executar.
<\n> 
Por exemplo, para rodar a demo utiliza-se o seguinte comando:

```bash
./emulador demo_text.bin demo_data.bin > saida.txt 
```
