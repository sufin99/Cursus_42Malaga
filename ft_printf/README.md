# Parte obligatoria

# Nombre de programa
<h2>libftprintf.a</h2>

<b>Archivos a entregar</b>
- Makefile, *.h, */*.h, *.c, */*.c
- Makefile NAME, all, clean, fclean, re

<b>Funciones autorizadas</b>
-malloc, free, write,
-va_start, va_arg, va_copy, va_end

<b>Se permite usar</b>
libft
Yes
<b>Descripción</b>: Escribe una librería que contenga la función
ft_printf(), que imite el printf() original
Debes reprogramar la función printf() de la libc.

# El prototipo de ft_printf() es:
int ft_printf(char const *, ...);

<b>Aquí tienes los requisitos</b>:
• No implementes la gestión del buffer del printf() original.
• Deberás implementar las siguientes conversiones: cspdiuxX %
• Tu función se comparará con el printf() original.
• Tienes que usar el comando ar para crear tu librería. El uso de libtool está
prohibido.
• Tu archivo libftprintf.a deberá ser creado en la raiz de tu repositorio.

<b>Tienes que implementar las siguientes conversiones</b>:
• %c Imprime un solo carácter.
• %s Imprime una string (como se define por defecto en C).
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
• %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.