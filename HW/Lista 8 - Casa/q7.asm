# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q7
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
    move $a0, $t1          
    move $a1, $a0          
    jal somaPG
    move $a1, $v0
    
    # print result
    li $v0, 4
    la $a0, result
    syscall
    # print soma
    move $a0, $a1
    li $v0, 1
    syscall

    # Finaliza
    li $v0, 10
    syscall

somaPG:
    # Prologue: Salvar o endereço de retorno e o registrador $ra
    addi $sp, $sp, -8
    sw $ra, 4($sp)
    sw $a0, 0($sp)

    # Corpo da função
    # Verificar se n é 0
    beq $a1, $zero, return_1

    # Caso geral: q*somaPG(n-1)
    addi $a1, $a1, -1      # Decrementar n
    jal somaPG             # Chamar a função recursivamente
    lw $a0, 0($sp)         # Restaurar q
    lw $ra, 4($sp)       # Obter o resultado da sub-rotina
    mul $v0, $a0, $t0     # Calcular q*somaPG(n-1)
    add $v0, $v1, $v0
    j return_func

return_1:
    li $v0, 1              # Retornar 1 (caso n = 0)

return_func:
    # Epílogo: Restaurar o registrador $ra e retornar
    lw $ra, 4($sp)
    addi $sp, $sp, 8
    jr $ra