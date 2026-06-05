section .text
global sumar_matrices
global sumatoria_matriz

sumar_matrices:
    push ebp
    mov ebp, esp

    ; === GUARDAR REGISTROS PRESERVADOS DE C ===
    push esi
    push ebx
    ; ==========================================
    
    xor esi, esi;          i: indice filas
    
    .for:
        mov ecx, [ebp+20]; tam matriz
        imul ecx, 4;       porque son dd
        imul ecx, esi;     ecx = n * i * d
        
        xor ebx, ebx;      j: indice columna
        
        .for2:
            mov edx, [ebp + 8];     dir A
            add edx, ecx;           edx = M + n * i * d
            mov eax, [edx + 4*ebx]; eax = A[i][j]
            
            mov edx, [ebp + 12];    dir B
            add edx, ecx;           edx = M + n * i * d
            add eax, [edx + 4*ebx]; eax = A[i][j] + B[i][j]
            
            mov edx, [ebp + 16];    dir C
            add edx, ecx;           edx = M + n * i * d
            mov [edx + 4*ebx], eax
            
            inc ebx
            cmp ebx, [ebp+20]; tam matriz
            jl .for2
        
        inc esi
        cmp esi, [ebp+20]
        jl .for

    ; === RESTAURAR REGISTROS EN ORDEN INVERSO ===
    pop ebx
    pop esi
    ; ============================================    
    
    mov esp, ebp
    pop ebp
    ret 
    
    

; Metodo solo para testing
; va dejando cada elemento en eax de la matriz pasada como parametro (dir)
; toma en orden:
; direccion de matriz
; tamaño de matriz
;
; recorre desde M[0][0] hasta M[n][m]
sumatoria_matriz:
    push ebp
    mov ebp, esp

    ; === GUARDAR REGISTROS PRESERVADOS DE C ===
    push esi
    push ebx
    ; ==========================================
    
    xor esi, esi
    xor eax, eax
    
    .for:
        mov ecx, [ebp+12]; tam matriz
        imul ecx, 4;       porque son dd
        imul ecx, esi;     ecx = n * i * d
        
        xor ebx, ebx;      j: indice columna
        
        .for2:
            mov edx, [ebp + 8];     dir A
            add edx, ecx;           edx = M + n * i * d
            add eax, [edx + 4*ebx]; eax = A[i][j]
            
            inc ebx
            cmp ebx, [ebp+12]
            jl .for2
        
        inc esi
        cmp esi, [ebp+12]
        jl .for
    
    ; === RESTAURAR REGISTROS EN ORDEN INVERSO ===
    pop ebx
    pop esi
    ; ============================================

    mov esp, ebp
    pop ebp
    ret 