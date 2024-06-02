# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q5
# Infra de HW 2024.1
# Fibonacci

.data
prompt_n: .asciiz "Digite o valor: "
result: .asciiz "O n-esimo elemento da serie de Fibonacci: "
newline: .asciiz "\n"

.text
 li $v0, 4
    la $a0, prompt_n
    syscall

    li $v0, 5
    syscall
    move $a0, $v0           

    jal fibonacci
    sub $v0, $v0, $a0
    move $a1, $v0
    # print no resultado
    li $v0, 4
    la $a0, result
    syscall

    move $a0, $a1
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 10
    syscall

# recursão
fibonacci:
    # if se n == 0, retorna 0
    beq $a0, $zero, fib_base_0
    # else if n == 1, retorna 1
    li $t0, 1
    slti $t0, $a0, 1
    beq $a0, $t0, fib_base_1

    addi $sp, $sp, -8      # separa espaço para a pilha
    sw $ra, 0($sp)          # Salva o endereço de retorno
    sw $a0, 4($sp)          # Salva n


    bgt $a0, $t0, lower
    #add $a0, $a0, $t0
    addi $sp, $sp, 8
    

    jr $ra
    
    
    
lower:
addi $a0, $a0, -1
jal fibonacci
lw $ra, 0($sp)
lw $a0, 4($sp)

addi $sp, $sp, 8

add $v0, $v0, $a0
jr $ra

fib_base_0:
    li $v0, 0               # Return 0
    jr $ra

fib_base_1:
    li $v0, 1               # Return 1
    jr $ra