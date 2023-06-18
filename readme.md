# Grayscaler for PNG images
This is a very simple CLI that turns .png files into grayscale images by adding each pixel RGB values together and calculating the average.

## Usage:
1. Use the executable:
````shell
./grayscaler <img.png>
````
2. Input: \
<img src="assets/ferrari.pnng.PNG" width=128>
3. Output: \
<img src="assets/gray-ferrari.pnng.PNG" width=128>

## Implementation
If you want to see the implementation just look into the `main.c`. We use the `stb_image` library but as you can see this are header only so you can just compile the project.

## Compilation
````shell
mkdir build
cd build
cmake ..
make
````

or short:
````shell
mkdir build && cd build && cmake .. && make
````