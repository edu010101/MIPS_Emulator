.data
    equal: .asciiz "Iguais"
    not_equal: .asciiz "Diferentes"

.text
    main:
        li $t0, 5   # Número a ser comparado
        li $t1, 5  # Valor de referência
        
        bne $t0, $t1, different  # Desvia para different se $t0 não for igual a $t1
        
        # Se os números forem iguais, imprime "Iguais" e termina o programa
        li $v0, 4
        la $a0, equal
        syscall
        
        j end  # Pula para o fim do programa
        
    different:
        # Se os números forem diferentes, imprime "Diferentes" e termina o programa
        li $v0, 4
        la $a0, not_equal
        syscall
        
    end:
        li $v0, 10
        syscall
        

