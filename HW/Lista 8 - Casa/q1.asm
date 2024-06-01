# Thomaz Lima, 
# Q1
# Infra de HW 2024.1
#
# if (A + D == 7 || B == 2 && C != 5)
# printf("TRUE");
# else
# printf("FALSE");

.data
prompt1: .asciiz "Insira o valor A: "
prompt2: .asciiz "Insira o valor B: "
prompt3: .asciiz "Insira o valor C: "
prompt4: .asciiz "Insira o valor D: "
true_msg: .asciiz "TRUE\n"
false_msg: .asciiz "FALSE\n"

.text
.globl main

main:
    # Valor A
    li $v0, 4                # printa a str
    la $a0, prompt1          # carrega o endereço do prompt
    syscall

    li $v0, 5                # le o inteiro
    syscall
    move $t0, $v0            # armazenar A

    # Valor B
    li $v0, 4                # mesma sequencia para, B,C, D
    la $a0, prompt2          
    syscall

    li $v0, 5                
    syscall
    move $t1, $v0            

    # Valor C
    li $v0, 4                
    la $a0, prompt3          
    syscall

    li $v0, 5                
    syscall
    move $t2, $v0           

    # Valor D
    li $v0, 4                
    la $a0, prompt4          
    syscall

    li $v0, 5                
    syscall
    move $t3, $v0            

    #if (A + D == 7 || B == 2 && C != 5)
    add $t4, $t0, $t3        # A + D
    li $t5, 7                # 7
    li $t6, 2                # 2
    li $t7, 5                # 5

    # (A + D == 7)
    beq $t4, $t5, print_true # Se A + D == 7, pula para print_true

    # (B == 2 && C != 5)
    beq $t1, $t6, check_c    # Se B == 2, pula para check_c
    j print_false            # else imprime FALSE

check_c:
    bne $t2, $t7, print_true # Mesma logica para != 5
    j print_false            

print_true:
    li $v0, 4                # printa a str
    la $a0, true_msg         # carrega TRUE
    syscall
    j end                    # pula para o fim

print_false:
    li $v0, 4                # printa a str
    la $a0, false_msg        # carrega FALSE
    syscall

end:
    li $v0, 10               # Finalizando o programa
    syscall
