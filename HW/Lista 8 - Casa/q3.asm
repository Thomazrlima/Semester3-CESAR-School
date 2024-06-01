# Thomaz Lima, Pedro Silva, Sofia Saraiva
# Q3
# Infra de HW 2024.1
#
# Lê N e printa a sequencia decrescente:

.data
prompt: .asciiz "Qual valor de N: "
newline: .asciiz "\n"
buffer: .space 4                # Armazena N

.text
.globl main

main:
    # Pegar N
    li $v0, 4                   # printa a str
    la $a0, prompt              # carrega o prompt
    syscall

    # Ler N
    li $v0, 5                   # Le N
    syscall
    move $t0, $v0               # armazena N

    # Loop para as sequências
    move $t1, $t0               

outer_loop:
    blez $t1, end_program       # if $t1 <= 0 end

    # Loop interno para imprimir de 1 a $t1
    li $t2, 1                   # inicializa $t2 = 1

inner_loop:
    bgt $t2, $t1, print_newline # if $t2 > $t1, print_newline

    # print $t2
    move $a0, $t2               # move valor de $t2 para $a0
    li $v0, 1                   # printa o valor
    syscall

    # printar , e espaco se não for o ultimo
    bge $t2, $t1, skip_comma    # if $t2 >= $t1, skip_comma
    li $v0, 4                   
    la $a0, comma_space         # carrega vírgula e espaço
    syscall

skip_comma:
    addi $t2, $t2, 1            # incrementa $t2
    j inner_loop                # loop

print_newline:
    # Imprimir nova linha
    li $v0, 4                   
    la $a0, newline             # carrega newline
    syscall

    # Decrementar $t1 para a próxima sequência
    addi $t1, $t1, -1           # decrementa $t1
    j outer_loop                # loop

end_program:
    li $v0, 10                  # finaliza o programa
    syscall

.data
comma_space: .asciiz ", "
newline: .asciiz "\n"
