# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q7 - Termo PG
# Infra de HW 2024.1
# PG

.data
prompt_q: .asciiz "Digite a razao q da PG: "
prompt_n: .asciiz "Digite o termo n da PG: "
result: .asciiz "Soma da PG: "

.text
 # pede a razão q da PG
    li $v0, 4
    la $a0, prompt_q
    syscall

    # pega o q
    li $v0, 5
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
    jal somaPG
    move $a0, $t0          
    move $a1, $a0
    move $a1, $v0
    
    # print result
    li $v0, 4
    la $a0, result
    syscall
    # print soma
    move $a0, $t0
    li $v0, 1
    syscall

    # Finaliza
    li $v0, 10
    syscall

somaPG:
    # Prologue: Salvar o endereço de retorno e o registrador $ra
    addi $sp, $sp, -12
    sw $ra, 8($sp)
    sw $t1, 4($sp)
    sw $t0, 0($sp)

    # Corpo da função
    # Verificar se n é 0
    bgt $t0, $t2, lower
    addi $sp, $sp, 12
    jr $ra

lower:
addi $t0, $t0, -1
jal somaPG
lw $ra, 8($sp)
lw $t1, 4($sp)
lw $t0, 0($sp)

move $a0, $t0
subi $t1, $t1, 1
addi $sp, $sp, 12
mult $t0, $t1
mflo $a0
add  $t0, $zero, $a0
jr $ra

return_1:
    li $v0, 1    # Retornar 1 (caso n = 0)

return_func:
    # Epílogo: Restaurar o registrador $ra e retornar
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra