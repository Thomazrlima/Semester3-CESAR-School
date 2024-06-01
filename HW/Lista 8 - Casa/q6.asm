# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q5
# Infra de HW 2024.1
# Fibonacci

.data
prompt_n: .asciiz "Digite o valor: "
result: .asciiz "O n-esimo elemento da serie de Fibonacci: "
newline: .asciiz "\n"

.text
.globl main

# recursão
fibonacci:
    # if se n == 0, retorna 0
    beq $a0, $zero, fib_base_0
    # else if n == 1, retorna 1
    li $t0, 1
    beq $a0, $t0, fib_base_1

    addi $sp, $sp, -8       # separa espaço para a pilha
    sw $ra, 0($sp)          
    sw $a0, 4($sp)          # Salva n

    addi $a0, $a0, -1       
    jal fibonacci
    move $t1, $v0           # Salva o resultado

    lw $a0, 4($sp)          # volta o valor de n
    addi $a0, $a0, -2       
    jal fibonacci
    move $t2, $v0           # Salva a conta

    add $v0, $t1, $t2       

    lw $ra, 0($sp)          
    addi $sp, $sp, 8        # Libera a pilha
    jr $ra                  # Return

fib_base_0:
    li $v0, 0               # Return 0
    jr $ra

fib_base_1:
    li $v0, 1               # Return 1
    jr $ra

main:
    li $v0, 4
    la $a0, prompt_n
    syscall

    li $v0, 5
    syscall
    move $a0, $v0           

    jal fibonacci

    # print no resultado
    li $v0, 4
    la $a0, result
    syscall

    move $a0, $v0
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 10
    syscall
