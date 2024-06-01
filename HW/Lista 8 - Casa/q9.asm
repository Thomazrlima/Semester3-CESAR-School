# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q9
# Infra de HW 2024.1
# Vê o tamanho da string

.data
prompt: .asciiz "Digite a string: "
length_msg: .asciiz "Tamanho da string: "
buffer: .space 256  

.text
.globl main

# Função principal
main:
    li $v0, 4                   # Printa string
    la $a0, prompt              # Carrega o prompt
    syscall

    # Leitura
    li $v0, 8                   # Lê a string
    la $a0, buffer              # Carrega o buffer
    li $a1, 256                 # Tamanho máximo
    syscall

    # Chamada da função
    la $a0, buffer              # Passa o endereço da string
    jal string_length           # Chama a função string_length

    li $v0, 4                   
    la $a0, length_msg          # Carrega a mensagem
    syscall

    # Printa o comprimento da string
    addi $t0, $t0, -1        # Remove o bit extra lido
    move $a0, $t0         # Move o comprimento da string para $a0
    move $t0, $v0               # Salva o valor de $v0 em $t0
                       
    li $v0, 1                   # Código de syscall para imprimir inteiro
    syscall

    # Terminar o programa
    li $v0, 10                  # Finaliza o programa
    syscall

# Função
string_length:
    # Inicializa o comprimento como 0
    li $t0, 0            

length_loop:
    lb $t1, 0($a0)              # Carrega o byte atual da string
    beq $t1, $zero, end_length  # If == 0, sai do loop
    addi $t0, $t0, 1            # Length++
    addi $a0, $a0, 1            # Move
    move $a1, $t0
    j length_loop               # Loopa

end_length:
    move $v0, $t0               
    jr $ra                      # Retorna