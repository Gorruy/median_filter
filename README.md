# median_filter
### build
```bash
mkdir build && cd build && cmake .. && make
```
### tests
```bash
<<<<<<< Updated upstream
$ mkdir build && cd build && cmake -DBUILD_TESTS .. && make && ctest ctest -T Test -T Coverage
=======
mkdir build && cd build && cmake -DBUILD_TESTS=ON .. && make && ctest -T Test -T Coverage
>>>>>>> Stashed changes
```
### usage
```bash
./bin/median_filter (window_size)
```

### Example:
```bash
./bin/median_filter 10
1111111 1 1 1111111 1 11111111 1 1 11111 1 0 0 11111111 11111111 11111111 1 1 1010 11 101101
1 1 1 1 1 1 1 1 1 1 110 110 110 110 110 110 110 110 110 110 

```
