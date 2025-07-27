```
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```

```
cmake --build build --parallel $(nproc)
```

```
cmake --build build --target hello
```