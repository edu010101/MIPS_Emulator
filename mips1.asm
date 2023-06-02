.data
v: .word 10 15 2 -5 20 80 -9 4 45 21
s: .word 10
c: .word -1

.text
add $zero, $zero, $zero
la $t1, 0xabcd1234
addi $t1, $t2, 7
addi $t7, $t9, 7
addi $t5, $t3, 7


li  $v0, 10 
syscall 