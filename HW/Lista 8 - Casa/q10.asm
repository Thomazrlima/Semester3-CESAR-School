# Thomaz Lima, Pedro Silva, Sofia Saraiva
# Q10
# Infra de HW 2024.1
# X com Y

.data
prompt_x: .asciiz "Digite o primeiro valor (x): "
prompt_y: .asciiz "Digite o segundo valor (y): "
greater_msg: .asciiz "x > y\n"
less_msg: .asciiz "x < y\n"
equal_msg: .asciiz "x = y\n"

.text
.globl main

main:
    #Entrada x
    li $v0, 4                   # print str
    la $a0, prompt_x            # carrega o prompt x
    syscall

    # Ler x
    li $v0, 6                   # lê o float
    syscall
    mov.s $f0, $f0              

    # Entrada y
    li $v0, 4                   # Mesma logica
    la $a0, prompt_y            
    syscall

    # Le float y
    li $v0, 6                   
    syscall
    mov.s $f1, $f0              

    # Compara x e y
    c.eq.s $f0, $f1             # if x = y, equal
    bc1t equal                  # if True
    c.lt.s $f0, $f1             # x < y, less
    bc1t less                   # if true

greater:
    li $v0, 4                   
    la $a0, greater_msg         # mensagem de x > y
    syscall
    j end_program               # Finaliza o programa

less:
    # x < y
    li $v0, 4                   
    la $a0, less_msg            # mensagem de x < y
    syscall
    j end_program               # Finaliza

equal:
    # x igual y
    li $v0, 4                   
    la $a0, equal_msg           # x = y
    syscall

end_program:
    li $v0, 10                  # fim
    syscall
