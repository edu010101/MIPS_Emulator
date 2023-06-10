
cmake_minimum_required(VERSION 3.0)
project(EmuladorProgram)

set(CMAKE_CXX_STANDARD 11)

# Adicione os seus arquivos .cpp adicionais aqui, se necessário
set(SOURCES main.cpp)

add_executable(emulador ${SOURCES})

# Defina o nome dos arquivos binários de entrada
set(INPUT_TEXT_FILE "text.bin")
set(INPUT_DATA_FILE "data.bin")

# Defina o nome do arquivo de texto de saída
set(OUTPUT_FILE "saida.txt")

# Criação de um alvo customizado para executar o programa com os arquivos binários de entrada e redirecionar a saída para o arquivo de texto
add_custom_target(run
    COMMAND ./emulador ${INPUT_TEXT_FILE} ${INPUT_DATA_FILE} > ${OUTPUT_FILE}
    COMMENT "Executando o programa com ${INPUT_TEXT_FILE} e ${INPUT_DATA_FILE} e salvando a saída em ${OUTPUT_FILE}"
    DEPENDS emulador
)
