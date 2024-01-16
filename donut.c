#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
int main(){
    float a = 0, b = 0;
    float i, j;
    float z[1760];
    char buf[1760];
    printf("\x1b[2J");
    for(;;){
        memset(buf, 32, 1760);
        memset(z, 0, 7040);
        for(j = 0; j < 6.28; j += 0.07){
            for(i = 0; i < 6.28; i += 0.02){
                float c = sin(i);
                float d = cos(j);
                float e = sin(a);
                float f = sin(j);
                float g = cos(a);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(b);
                float n = sin(b);
                float t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]){
                    z[o] = D;
                    buf[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H");
        for(int k = 0; k < 1760; k++){
            putchar(k % 80 ? buf[k] : 10);
            a += 0.00004;
            b += 0.00002;
        }
        usleep(30000);
    }
    return 0;
}
