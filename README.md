```
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```

```
cmake --build build --parallel $(nproc)
```

```
cmake --build build --target play_snake_desktop --parallel $(nproc)
```

```
cmake --build build --target play_tetris_cli --parallel $(nproc)
```

```
cmake --build build --target play_tetris_desktop --parallel $(nproc)
```

```
cmake --build build --target play_snake_cli --parallel $(nproc)
```