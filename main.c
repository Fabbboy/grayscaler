#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_writer.h"
#include <stdint.h>

#define u8 uint8_t
#define CHANNEL_NUM 4
#define MAXLEN 1024

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("./grayscaler <img>\n");
        return -1;
    }
    int w;
    int h;
    int comp;
    unsigned char* file = stbi_load(argv[1], &w, &h, &comp, STBI_rgb_alpha);
    if (!file) {
        printf("Error loading file\n");
        return -1;
    }
    unsigned char* endFile = (unsigned char*)malloc(w * h * CHANNEL_NUM * sizeof(unsigned char));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int index = (i * w + j) * CHANNEL_NUM;
            u8 r = file[index];
            u8 g = file[index + 1];
            u8 b = file[index + 2];
            u8 a = file[index + 3];

            //cal grayscale value of RGB
            u8 endVal = (r + g + b) / 3;

            endFile[index] = endVal;
            endFile[index + 1] = endVal;
            endFile[index + 2] = endVal;
            endFile[index + 3] = a;
        }
    }
    char new_filename[MAXLEN];
    if(strlen(argv[1]) > MAXLEN){
        printf("filename to big \n");
        return -1;
    }
    sprintf(new_filename, "gray-%s", argv[1]);
    //writing the image data into a separate file
    stbi_write_png(new_filename, w, h, CHANNEL_NUM, endFile, w * CHANNEL_NUM);

    free(file);
    free(endFile);
    return 0;
}
