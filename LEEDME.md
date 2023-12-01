<h1 align="center">
	📖 so_long
</h1>

<p align="center">
	<b><i>Primera experiencia con librerias externas en C</i></b><br>

<h3 align="center">
	<a href="#%EF%B8%8F-about">Sobre</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Uso</a>
	<span> · </span>
	<a href="#-testing">Pruebas</a>
</h3>

---

## 💡 Sobre el proyecto

> _Crea un simple videojuego usando minilibx._

El objetivo de este proyecto es crear un videojuego que consista en recoger todos los coleccionables de un mapa para desbloquear la puerta de salida y salir por ella.

Las reglas por las que se rige este videojuego son las siguientes:

### Reglas generales

- [x] Usar MiniLibX
- [x] Hacer un Makefile
- [x] Admitir como argumento un .ber

### Reglas del Juego
- [x] The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- [x] The W, A, S, and D keys must be used to move the main character.
- [x] The player should be able to move in these 4 directions: up, down, left, right.
- [x] The player should not be able to move into walls.
- [x] At every move, the current number of movements must be displayed in the shell.
- [x] You have to use a 2D view (top-down or profile).

### Reglas gestión gráficos
- [x] Your program has to display the image in a window.
- [x] The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- [x] Pressing ESC must close the window and quit the program in a clean way.
- [x] Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
- [x] The use of the images of the MiniLibX is mandatory.

### Reglas mapa
- [x] The map has to be constructed with 3 components: walls, collectibles, and free
space.
- [x] The map can be composed of only these 5 characters:
    - 0 for an empty space
    - 1 for a wall
    - C for a collectible
    - E for the map's exit
    - P for the player’s starting position
- [x]  The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
- [x] The map must be rectangular.
- [x] The map must be closed/surrounded by walls. If it’s not, the program must return an error.
- [x] You have to check if there’s a valid path in the map.
- [x] You must be able to parse any kind of map, as long as it respects the above rules.
- [x] If any misconfiguration of any kind is encountered in the file, the program must exit in a clean way, and return "Error\n" followed by an explicit error message of your choice.

## PATHFINDER
Para poder evaluar si el mapa es resoluble se ha desarrollado una función (ft_pathfinder) que funciona como un algoritmo fill floor. Se asume que la puerta de salida es como una pared más, por lo que en caso de que haya coleccionables no accesibles por paredes o la salida el mapa no será resoluble.
