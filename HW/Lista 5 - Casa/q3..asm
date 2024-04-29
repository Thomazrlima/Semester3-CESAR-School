.data
prompt_nota1: .asciiz "Digite a primeira nota: "
prompt_nota2: .asciiz "Digite a segunda nota: "
prompt_freq: .asciiz "Digite o percentual de frequência: "
media_msg: .asciiz "A média das notas é: "
aprovado_msg: .asciiz "Aluno aprovado!"
reprovado_msg: .asciiz "Aluno reprovado!"

.text
main:
    li $v0, 4
    la $a0, prompt_nota1
    syscall
    
    li $v0, 5
    syscall
    move $t0, $v0
    
    li $v0, 4
    la $a0, prompt_nota2
    syscall
    
    li $v0, 5
    syscall
    move $t1, $v0
    
    li $v0, 4
    la $a0, prompt_freq
    syscall
    
    li $v0, 5
    syscall
    move $t2, $v0
    
    add $t3, $t0, $t1
    div $t3, $t3, 2
    
    bge $t3, 7, aprova
    bge $t2, 75, aprova
    j reprovado
    
aprovado:
    li $v0, 4
    la $a0, aprovado_msg
    syscall
    j fim
    
reprovado:
    li $v0, 4
    la $a0, reprovado_msg
    syscall

fim:
    li $v0, 10
    syscall
