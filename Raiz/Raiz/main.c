//
//  main.c
//  Raiz
//
//  Created by Diego Eduardo Rosas González on 30/01/17.
//  Copyright © 2017 Diego Eduardo Rosas González. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, c, r2, xr1,xi1, xr2, xi2, cond;
    printf("Ingrese el coeficiente cuadrático\n");
    scanf("%f", &a);
    printf("Ingrese el coeficiente lineal\n");
    scanf("%f", &b);
    printf("Ingrese el coeficiente independiente\n");
    scanf("%f", &c);
    
    /*cond = (pow(b,2)<(4*a*c));
    r2 = cond? sqrt(4*a*c - pow(b, 2)): sqrt(pow(b,2)-4*a*c);
    xr1 = cond? -b / (2* a):(-b + r2)/(2*a);
    xr2 = cond? xr1:(-b - r2)/(2*a);
    xi1 = cond? r2 / (2 * a): 0;
    xi2 = -xi1;
    */
    // poner %+f pone el signo antes de imprimir
    if (pow(b,2)<(4*a*c)){
        r2 = sqrt(4*a*c - pow(b, 2));
        xr1 =  -b / (2* a);
        xr2 = xr1;
        xi1 = r2 / (2 * a);
        
    }else{
        r2 = sqrt(pow(b,2)-4*a*c);
        xr1 = (-b + r2)/(2*a);
        xr2 = (-b - r2)/(2*a);
        xi1 = 0;
    }
    
    printf("f(x)=%.2fx^2%+.2f%+.2f=0\n", a, b, c);
    printf("x1=%.2f%+.2fi\nx2=%f%+.2fi\n", xr1, xi1, xr2, xi2);
    getchar();
    getchar();
    return 0;
}
