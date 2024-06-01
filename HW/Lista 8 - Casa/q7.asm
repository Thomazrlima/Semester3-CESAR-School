# Thomaz Lima, Pedro Silva, Sofia Saraiva
# Q8
# Infra de HW 2024.1
# PG

.data
prompt_q: .asciiz "Digite a razao q da PG: "
prompt_n: .asciiz "Digite o termo n da PG: "
result: .asciiz "Termo a[n] da PG: "

.text
.globl main

termoPG:
    # if n == 0
    beq $a0, $zero, termoPG_end
    # else
    subi $a0, $a0, 1       # Decrementa n
    mul $v0, $a1, $v0     # Multiplica por q
    jr $ra

termoPG_end:
    li $v0, 1              # Retorna 1
    jr $ra

# main
main:
    li $v0, 4
    la $a0, prompt_q
    syscall

    # Recebe q
    li $v0, 5
    syscall
    move $t0, $v0          # Salva q em $t0

    li $v0, 4
    la $a0, prompt_n
    syscall

    li $v0, 5
    syscall
    move $t1, $v0          # Salva n em $t1

    # Calcula a[n] 
    move $a0, $t1          # n para termoPG
    move $a1, $t0          # q para termoPG
    jal termoPG

    # print result
    li $v0, 4
    la $a0, result
    syscall

    # print a[n]
    move $a0, $v0
    li $v0, 1
    syscall

    # Finaliza
    li $v0, 10
    syscall