### BUILD
* `sudo apt-get install libcgal-dev cmake`
* `mkdir build -p && cd build && cmake .. && make -j8`

## RUN
* **stdin** - one segment per line (in format "X1 Y1 X2 Y2")
* **stdout** - one intersection point per line (in format "X1 Y1")
