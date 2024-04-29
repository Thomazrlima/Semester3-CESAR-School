.data
prompt_celsius: .asciiz "Digite a temperatura em Celsius: "
fahrenheit_msg: .asciiz "A temperatura em Fahrenheit é: "

.text
main:
    li $v0, 4
    la $a0, prompt_celsius
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $t1, 9
    mul $t0, $t0, $t1
    addi $t0, $t0, 160
    sra $t0, $t0, 4
    
    li $v0, 4
    la $a0, fahrenheit_msg
    syscall
    
    li $v0, 1
    move $a0, $t0
    syscall
    
    li $v0, 10
    syscall
