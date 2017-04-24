//
//  main.c
//  3x5
//
//  Created by Diego Eduardo Rosas González on 02/02/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, n;
    float r;
    printf("Ingrese el número de iteraciones\n");
    scanf("%d",&n);
    while (i<n) {
        r += 1/((2*i+1)*(2*i+3));
    }
    printf("1/2 = %f",r);
    return 0;
}
