.data
 linejump: .asciiz "\n"


.text

li $s1, 0

li $v0,5
syscall

move $t0, $v0

beq $t0, $s1, finish
add $s2, $s2, $t0
j condicional
  
 
 condicional:

li $s1, 0

li $v0,5
syscall

move $t0, $v0

beq $t0, $s1, finish
add $s2, $s2, $t0
 j condicional
 
 finish:
 li $v0, 1
 move $a0, $s2
 syscall