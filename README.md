### BOOTSTRAP
* `sudo apt-get install libcgal-dev cmake`
* `bootstrap.sh`

### BUILD
* `build.sh`

### RUN
```bash
$> cat input.txt
0 0 1 1
1 0 0 1
1.5 0.5
0.2 1.0
$> <input.txt build/intersector
Read completed: 4
0.5 0.5
0.777778 0.777778
```
* **stdin** - one segment per line (in format `X1 Y1 X2 Y2`)
* **stdout** - one intersection point per line (in format `X1 Y1`)
* **stderr** - `Read completed: <NUMBER_OF_SEGMENTS>`
