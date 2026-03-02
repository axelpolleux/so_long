_This project has been created as part of the 42 curriculum_

## Description

So_long is a graphic projet in C aiming to create a 2d top-down (or platform) game. Main player must collect all the items in the map, before leaving it by the exit door.

This project uses the MacroLibX, a graphic library made by 42 students. The window management has to be smoothly handled (close event, no memory leaks).

## Instructions

### Prerequisites

- MacroLibX must be installed on your computer
- So must be valgrind, to check probable memory leaks

### Compilation

```sh
make
```

### Execution

```sh
./so_long <path_map>
```

### Memory checks

```sh
valgrind --suppressions=includes/MacroLibX/valgrind.supp --leak-check=full ./so_long <path_map>
```

## Resources

- [Official MacroLibX doc](https://macrolibx.kbz8.me/)
- [Medium article](https://medium.com/@digitalpoolng/42-so-long-and-thanks-for-all-the-fish-building-your-first-2d-game-in-c-ccd24034bc8b)
- Use of AI:
  - Flood fill algorithm structure **(no direct code)**
  - Frees for memory leaks
  - Help on loading the images **(using the MacroLibX functions)**

## Additional
MacroLibX has been chosen because of its simplified images, events and window management functions. Its powerful errors management helped me to find my code issues faster.
