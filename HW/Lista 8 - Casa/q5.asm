# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q5
# Infra de HW 2024.1
# vetor

.data
prompt_n: .asciiz "Digite o comprimento: "
invalid_n: .asciiz "Invalido\n"
prompt_x: .asciiz "Digite o valor do elemento: "
result_x: .asciiz "Vetor de entrada x:\n"
result_y: .asciiz "Vetor de saída y:\n"
newline: .asciiz "\n"

.text
.globl main

main:
    li $v0, 4
    la $a0, prompt_n
    syscall

    # Recebe N
    li $v0, 5
    syscall
    move $t0, $v0            # Salva N

    # if N >= 6
    li $t1, 6
    blt $t0, $t1, invalid_input

    # Aloca memória
    sll $t2, $t0, 2          # Multiplica N por 4
    li $v0, 9                # sbrk
    move $a0, $t2
    syscall
    move $s0, $v0            # Salva o endereço base no array

    # Aloca array y (N-5)
    sub $t3, $t0, 5
    sll $t4, $t3, 2          # Multiplica N-5 por 4
    li $v0, 9                # Código para sbrk
    move $a0, $t4
    syscall
    move $s1, $v0            

    # Recebe os valores para x
    li $t5, 0
input_loop:
    beq $t5, $t0, calculate_y  # Se $t5 == N, sai do loop
    li $v0, 4
    la $a0, prompt_x
    syscall

    move $a0, $t5
    li $v0, 1
    syscall

    # Recebe o valor do elemento
    li $v0, 5
    syscall
    sll $t6, $t5, 2           # Calcula o offset do elemento
    add $t7, $s0, $t6
    sw $v0, 0($t7)

    addi $t5, $t5, 1          # Incrementa o índice
    j input_loop

# Calcula as componentes do array y
calculate_y:
    li $t5, 0
calc_loop:
    beq $t5, $t3, print_x     # Se $t5 == (N-5), sai do loop
    move $t8, $zero           # Inicializa a soma

    # Soma os 6 elementos consecutivos
    li $t9, 0
sum_loop:
    lw $t6, 0($t7)
    add $t8, $t8, $t6
    addi $t7, $t7, 4
    addi $t9, $t9, 1
    bne $t9, 6, sum_loop

    # média
    div $t8, 6
    mflo $t8

    # Salva a média
    sll $t6, $t5, 2
    add $t7, $s1, $t6
    sw $t8, 0($t7)

    addi $t5, $t5, 1          # Incrementa o índice
    j calc_loop

# Imprime
print_x:
    li $v0, 4
    la $a0, result_x
    syscall

    li $t5, 0
print_x_loop:
    beq $t5, $t0, print_y     # Se $t5 == N, sai do loop
    sll $t6, $t5, 2
    add $t7, $s0, $t6
    lw $a0, 0($t7)

    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    addi $t5, $t5, 1          # Incrementa o índice
    j print_x_loop

# Imprime y
print_y:
    li $v0, 4
    la $a0, result_y
    syscall

    li $t5, 0
print_y_loop:
    beq $t5, $t3, end         # Se $t5 == (N-5), termina
    sll $t6, $t5, 2
    add $t7, $s1, $t6
    lw $a0, 0($t7)

    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    addi $t5, $t5, 1          # Incrementa o índice
    j print_y_loop

# Tratamento de erro
invalid_input:
    li $v0, 4
    la $a0, invalid_n
    syscall
    j main

end:
    li $v0, 10
    syscall
