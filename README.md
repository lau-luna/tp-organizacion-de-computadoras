⚙️ Compilación y Ejecución
El proceso de construcción se divide en dos pasos: ensamblar el código NASM y enlazarlo con el código C.

Abre tu terminal en el directorio del proyecto y ejecuta los siguientes comandos en orden:

1. Ensamblar el código x86 a formato objeto (ELF 32-bit).
2. 2. Compilar C y enlazar ambos archivos.
3. Ejecutar. 

Bash

nasm -f elf32 sumar_matriz.asm -o sumar_matriz.o;
gcc -m32 sumar.c sumar_matriz.o -o mi_programa;
./mi_programa
