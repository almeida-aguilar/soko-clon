# Made  with C

## Blog

### [*2026-03-28* | Cambios en el CLI y mejoras en la seguridad](/docs/cambios-cli-seguridad.md)

## Idea

Hacer un clon de [Sokoban](https://en.wikipedia.org/wiki/Sokoban).

Para el renderizado se hará con la librería multimedia Raylib.
La primera implementación se hará en 2D.
Se planea una ultima implementación en 3D.

Los niveles tendrán un tamaño fijo de 10 * 10 celdas.
Los niveles tendrán un número fijo de 3 cajas.

Para la generación de niveles se reescribirá el codigo de [AlliBalliBaba](https://github.com/AlliBalliBaba/Sokoban-Level-Generator).
Se pasaran el código JS a C.

La ejecución se va a hacer vía CLI.
`concepto:`

```sh
# generar niveles con semilla aleatoria
skclon

# generar niveles con semilla perzonalizada
skclon <seed>
```

## TODO

- [X] Iniciar el proyecto.
- [X] Implementar `CLI`
- [ ] `Enum` de las diferentes tipos de celdas.
