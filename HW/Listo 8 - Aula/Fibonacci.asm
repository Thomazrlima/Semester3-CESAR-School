.data
prompt: .asciiz "Enter n: "
result_msg: .asciiz "Fibonacci(n) = "

.text
.globl main

main:
    li $v0, 4
    la $a0, prompt
    syscall

    li $v0, 5
    syscall
    move $a0, $v0

    jal fibonacci

    li $v0, 4
    la $a0, result_msg
    syscall

    move $a0, $v0
    li $v0, 1
    syscall

    li $v0, 10
    syscall

fibonacci:
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)

    li $t0, 0
    beq $a0, $t0, base_case_0

    li $t0, 1
    beq $a0, $t0, base_case_1

    addi $a0, $a0, -1
    jal fibonacci
    move $t1, $v0

    lw $a0, 0($sp)
    addi $a0, $a0, -2
    jal fibonacci
    move $t2, $v0

    add $v0, $t1, $t2
    j end_fibonacci

base_case_0:
    li $v0, 0
    j end_fibonacci

base_case_1:
    li $v0, 1

end_fibonacci:
    lw $ra, 4($sp)
    lw $a0, 0($sp)
    addi $sp, $sp, 8
    jr $ra
