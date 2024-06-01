# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q2
# Infra de HW 2024.1
#
# Trocar C1 na string S por C2 e printar a nova string.

.data
prompt_str: .asciiz "Digite a string: "
prompt_c1: .asciiz "Digite o character a ser trocado: "
prompt_c2: .asciiz "Digite o novo Caractere: "
output_msg: .asciiz "Nova string: "
buffer: .space 100          # Armazena a string de entrada

.text
.globl main

main:
    # Leitura da string S
    li $v0, 4                # print str
    la $a0, prompt_str       # carrega o prompt_str
    syscall

    li $v0, 8                # lê a str
    la $a0, buffer           # carrega o endereço
    li $a1, 100              
    syscall

    # Leitura do caractere C1
    li $v0, 4                # print str
    la $a0, prompt_c1        # carrega o prompt_c1
    syscall

    li $v0, 12               # lê o caractere
    syscall
    move $t0, $v0            # armazena C1

    # Leitura do caractere C2
    li $v0, 4                # Mesma logica so que substitui por c2
    la $a0, prompt_c2        # carregar endereço do prompt_c2
    syscall

    li $v0, 12               
    syscall
    move $t1, $v0            

    # Substituir ocorrências de C1 por C2 na string S
    la $t2, buffer           # carrega endereço

replace_loop:
    lb $t3, 0($t2)           # carrega o caractere atual
    beqz $t3, print_result   # se for nulo, pula para o print_result
    beq $t3, $t0, replace    # se for igual a C1
    j skip_replace           # else vai para skip_replace

replace:
    sb $t1, 0($t2)           # troca o caractere atual por C2

skip_replace:
    addi $t2, $t2, 1         # vai para o próximo
    j replace_loop           # loop

print_result:
    li $v0, 4                # printa o str
    la $a0, output_msg       # carregar a mensagem
    syscall

    li $v0, 4                
    la $a0, buffer           # carrega a nova str
    syscall

    li $v0, 10               # finaliza o programa
    syscall
