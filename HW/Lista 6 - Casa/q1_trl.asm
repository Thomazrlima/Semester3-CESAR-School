.data
 linejump: .asciiz "\n"


.text

li $s0, 0
li $s1, 10

BLe $s0, $s1, condicional
 
 
 condicional:

 li $v0,1
 move $a0, $s0
 addi  $s0, $s0, 1
 syscall
 
 la $a0, linejump
 li $v0, 4
 syscall
 
 Beq $s0, $s1, finish
 j condicional
 
 finish: