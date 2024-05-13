.data
str: .asciiz "Insira o valor a ser multiplicado"

.text
li $v0, 4
la $a0, str
syscall

li $v0, 5
syscall

move $a0, $v0
move $a1, $a0

jal Fatorial

Fatorial:
addi $sp, $sp -8
sw $ra, 0($sp)
slti $t0, $a0, 1


addi $a1, $a1, -1
ble $a1,0,Return
mul $a0, $a0, $a1
jr $ra


Return:
li $v0, 1
syscall