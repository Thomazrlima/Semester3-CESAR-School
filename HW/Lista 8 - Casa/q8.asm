# Thomaz Lima, Pedro Silva, Sofia Saraiva
# Q8
# Infra de HW 2024.1
# X com Y

.data
prompt_q: .asciiz "Digite a razao q da PG: "
prompt_n: .asciiz "Digite o termo n da PG: "
result: .asciiz "Soma da PG: "

.text
.globl main

    li $v0, 1

    beq $a0, $zero, termoPG_end

    # Caso contrário, calcula termoPG(n-1) * q
    subi $a0, $a0, 1
    lw $t0, 0($a1)        # Carrega q
    mul $v0, $v0, $t0     # Multiplica pelo anterior
    j termoPG_end

termoPG_end:
    jr $ra                 # Return

# recursiva:
    li $v0, 1

    # if true
    beq $a0, $zero, somaPG_end

    # else
    subi $a0, $a0, 1       # n--
    jal termoPG            # Chama o termo
    add $v0, $v0, $a1      # Adiciona o termo a soma
    j somaPG_end

somaPG_end:
    jr $ra                 # Return

# main
main:
    # pede a razão q da PG
    li $v0, 4
    la $a0, prompt_q
    syscall

    # pega o q
    li $v0, 7
    syscall
    move $t0, $v0          

    # pede o n da PG
    li $v0, 4
    la $a0, prompt_n
    syscall

    # Recebe n
    li $v0, 5
    syscall
    move $t1, $v0          

    # Calcula a soma s[n] da PG
    move $a0, $t1          
    move $a1, $t0          
    jal somaPG

    # print result
    li $v0, 4
    la $a0, result
    syscall

    # print soma
    move $a0, $v0
    li $v0, 1
    syscall

    # Finaliza
    li $v0, 10
    syscall
