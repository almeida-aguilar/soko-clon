# Cambio en el CLI

## Cosas corregidas

Después de revisar la seguridad del código con un LLM noté que no necesito un
número, es más fácil y como dejar al usuario decidir cuando quiere terminar el
juego.

Dejé que la única funcionalidad del CLI es asignar el seed para iniciar los
niveles, ¿para qué serviría eso?, simple, si el usuario esta en un nivel y
simplemente quiere recrearlo después simplemente tiene que ver el seed que está
en pantalla a la hora de jugar y guardarlo para luego recrearlo o
compartirlo.

Es posible que el uso del CLI sea termporal, dado que sería mejor:

1. Que la asignación de la semilla sea en al inicio del juego con un simple
editor de texto.
2. Que la manera de guardar las semillas sea por un bóton que lo ponga en
el buffer del copy, o que lo guarde en un archivo temporal. Creo que la manera
más limpia sería la primera.

## Cosas aprendidas

### strtol

Como dije anteriormente revisé el código con LLM y me mencionó una vulnerabilidad
`atoi()`, al parecer, dado que `seed_t` era transitivamente un `long`, ahora es
explicitamente un `long` en vez de un `time_t`, `atoi()` estaba retornando un
`int` lo que al parecer no aprovechaba del todo el tamaño de `long` y además era
inseguro, dado que una transformación de `string` a  `number` puede fallar así
que era necesario una manera de catchear errores.
Una manera era con `strtol` (que no sé porque no existe un `strtoi`, cuanto les
cuesta), `strtol` me permite saber si el iterador llego a leer todo el `string`,
de lo contrario lanzo un error de incompatibilidad.

### KISS -- Keep It Simple, Stupid

Intentar hacer un CLI, aunque simple, con más opciones de las necesarias fue un
error, y como mencioné antes, el CLI solo se va a quedar para el testing y luego
será eliminado. Los usuarios no son todo programadores, y no tiene que saber como
funciona una terminal para poder jugar, debería ser capaz de declarar su semilla
en el mismo juego.
Por ahora voy a mantener el CLI más que todo porque siempre quise hacer uno y
ahora que sé como hacerlos los quiero poner en todas partes (jsjsjs).
