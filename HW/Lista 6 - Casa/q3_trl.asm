    mov esi, 0  ; soma = 0

do_while_loop:
    push x_fmt  ; Empilhe o formato "%d"
    call scanf  ; Chame a função scanf para ler x
    add esp, 4  ; Ajuste o ponteiro da pilha
    
    add esi, eax; soma += x
    
    cmp eax, 0  ; x != 0
    jne do_while_loop ; Se x != 0, volte para o início do loop
    
    push esi    ; Empilhe o valor de soma para printf
    push sum_fmt; Empilhe o formato "%d\n"
    call printf ; Chame a função printf para imprimir soma
    add esp, 8  ; Ajuste o ponteiro da pilha