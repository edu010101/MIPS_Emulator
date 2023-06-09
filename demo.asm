.data
input: .word 8
weight: .word 3
bias: .word 1
output: .word 0

.text
.globl main

main:
    # Chamada da função hidden_layer
    lw $4, input
    lw $5, weight
    lw $6, bias
    jal hidden_layer
    sw $2, output

    # Impressão do output
    li $v0, 1
    lw $a0, output
    syscall

    # Quebra de linha
    li $v0, 4
    la $a0, endl
    syscall

    # Encerrar o programa
    li $v0, 10
    syscall

hidden_layer:
    # Cálculo do resultado
    lw $2, 0($4)
    lw $3, 0($5)
    lw $7, 0($6)
    mult $2, $3
    mflo $2
    add $2, $2, $7

    jr $ra
    nop

.data
endl: .asciiz "\n"
