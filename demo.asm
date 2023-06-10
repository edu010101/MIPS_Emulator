.data
	input: .word 8
	weight: .word 3
	bias: .word 1
	output: .word 0

.text
    lw $4, input
    lw $5, weight
    lw $6, bias
  
    # O código seguinte representa uma função afim, que pode parecer simples mas é a bse primordial das redes neurais, 
    #tendo isso, e muito poder computacional é possível criar redes neurais de qualquer escala   
    mult $4, $5
    mflo $4
    add $4, $4, $6
    sw $4, output

    # Impressão do output
    li $v0, 1
    lw $a0, output
    syscall

    # Encerrar o programa
    li $v0, 10
    syscall


