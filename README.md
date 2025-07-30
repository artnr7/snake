```
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```

```
cmake --build build --parallel $(nproc)
```

```
cmake --build build --target play_snake_game --parallel $(nproc)
```