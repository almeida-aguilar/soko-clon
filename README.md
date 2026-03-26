# Soko-clon

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
# generar niveles infinitos con semilla aleatoria
skclon

# generar niveles cotados con semilla aleatoria
skclon <num_levels>
# ejemplo
skclon 10

# generar niveles infinitos con semilla personalizada
skclon 00 <seed>
# ejemplo
skclon 00 1024

# generar n niveles con s semilla
skclon <num_levels> <seed>
# ejemplo
skclon 20 1024
```

## TODO

- [X] Iniciar el proyecto.
- [ ] Implementar `CLI`
- [ ] `Enum` de las diferentes tipos de celdas.
