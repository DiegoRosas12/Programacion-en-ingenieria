//
//  main.c
//  Sen(x)
//
//  Created by Diego Eduardo Rosas González on 20/02/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>



float seno2(float x, int n) {
    static float fc;
    fc = x;
    static int i = 1;
    float c;
    fc *= ((x/(2*i))*(x/(2*i+i)));
    i++;
    c = (2 * (i % 2) - 1)*fc;
    if(i < (n+1))
        return seno2(x, n)+c;
    else
        return x;
}

/*float seno(float x, int n){
    float sx, fc;
    int i, sg;
    for (i = 0, sx = 0, sg = 1, fc = x; i<n; i++, sg*=(-1)) {
        sx += (sg*fc);
        fc *= ((x / (2 * i + 2))*(x / (2 * 1 + 3)));
    }
    return sx;
}
*/
int main() {
    float x, sx;
    int n;
    printf("Ingrese el valor de x\n");
    scanf("%f",&x);
    printf("Ingrese numero de iteraciones:\n");
    scanf("%d", &n);
    sx = seno2(x, n);
    printf("%f\n",sx);
    
    return 0;
}
