# Thomaz Lima, Pedro Silva, Sofia Saraiva, Andre Goes
# Q4
# Infra de HW 2024.1
#
# Transforma de Segundo para ano

.data
prompt: .asciiz "Digite o tempo em segundos: "
year_msg: .asciiz " anos, "
month_msg: .asciiz " meses, "
day_msg: .asciiz " dias, "
hour_msg: .asciiz " horas, "
minute_msg: .asciiz " minutos e "
second_msg: .asciiz " segundos\n"

.text
.globl main

main:
    li $v0, 4                   # print str
    la $a0, prompt              # carrega o prompt
    syscall

    # Ler int
    li $v0, 5                   # Lê os segundos
    syscall
    move $t0, $v0               # salva N em $t0

    # Constantes
    li $t1, 31536000            # ano = (12 * 30 * 24 * 60 * 60)
    li $t2, 2592000             # mês = (30 * 24 * 60 * 60)
    li $t3, 86400               # dia = (24 * 60 * 60)
    li $t4, 3600                # hora = (60 * 60)
    li $t5, 60                  # minuto só *60

    # anos
    div $t0, $t1                # N / 31536000
    mflo $s0                    # salva
    mfhi $t0                    # salva o resto

    # meses
    div $t0, $t2                # resto / 2592000
    mflo $s1                    # salva
    mfhi $t0                    # salva o resto

    # dias
    div $t0, $t3                # resto / 86400
    mflo $s2                    
    mfhi $t0                    

    # h
    div $t0, $t4                # resto / 3600
    mflo $s3                    
    mfhi $t0                    

    # min
    div $t0, $t5                # resto / 60
    mflo $s4                    # armazenar minutos em $s4
    mfhi $s5                    # armazenar segundos em $s5

    # print anos
    li $v0, 1                   # print num
    move $a0, $s0               # move anos para $a0
    syscall

    li $v0, 4                   # print
    la $a0, year_msg            # year_msg
    syscall

    # print meses
    li $v0, 1                   # mesma logica para os demais
    move $a0, $s1              
    syscall

    li $v0, 4                  
    la $a0, month_msg          
    syscall

    # print dias
    li $v0, 1                   
    move $a0, $s2              
    syscall

    li $v0, 4                   
    la $a0, day_msg             # day_msg
    syscall

    # print h
    li $v0, 1                   
    move $a0, $s3               
    syscall

    li $v0, 4                   # print
    la $a0, hour_msg            # carrega hour_msg
    syscall

    # print min
    li $v0, 1                   # print num
    move $a0, $s4               # move minutos para $a0
    syscall

    li $v0, 4                   # print str
    la $a0, minute_msg          # carrega minute_msg
    syscall

    # print seg
    li $v0, 1                   
    move $a0, $s5               # valor de seg para $a0
    syscall

    li $v0, 4                   # print str
    la $a0, second_msg          
    syscall

    # Finaliza
    li $v0, 10                  # Finaliza o programa
    syscall
