//
//  main.c
//  Proyecto_1
//
//  Universidad de Guanajuato
//  Division de Ingenierias Campus Irapuato Salamanca
//  Diego Eduardo Rosas Gonzalez
//  Jonathan Joel Corona Ortega
//  Ivan Alejandro Rocha Ríos

#include <stdio.h>
#include <math.h>

/* Función: Calculadora que utiliza las series de taylor para calcular distintos valores y hacer operaciones trigonométricas
Factorial: Función recursiva que multiplica todos los valores que regresa desde n hasta n = 1
combinación: Función necesaria para las fórmulas trigonometricas de la tangente y cosecante.
Con esta se calculan los números de Bernoulli B2 en donde se utiliza el coeficiente binominal o combinatoria.
es igual a n! / k!(n-k)! (hay varios problemas en esta funcion)
ln(2): se hace un ciclo de sumatorias donde 1 siempre es el numerador y se divide entre n que incrementa de uno a uno.
En la fórmula los números se alternan entre positivo y negativo por eso se multiplica por -1 por cada iteracion.
pi/4: mismo caso que el anterior pero ahora el numerador se incrementa de dos en dos.
pi^2/6 y pi^2/8: Se hace una serie como la primera y la segunda pero en este caso todos los términos son positivos y el denominador se eleva al cuadrado.
1/2: 1 dividido entre la multiplicación de dos números. Notamos que ambos se incrementan dedos en dos. La única diferencia es que el primero inicia en 1 y el segundo en 3.
Se suma 2 a i y j en cada iteración. En la siguiente fórmula se aplica de la misma manera sólo que aquí aumenta de uno en uno.
e^x: 
 */

int factorial(int n){
    if (n == 1) {
        return 1;
    }else{
        return n *factorial(n-1);
    }
}
// Conbinacion
float comb(int k, int l){
    int f, a, fa=1, b, fb=1, c, fc=1, i = 0;
    
    a = k;
    b = l;
    c = k-1;
    for (i = 0; i < a; i++)
        fa *= (a-i);
    for (i = 0; i < a; i++)
        fb *= (b-i);
    for (i = 0; i < a; i++)
        fc *= (c-i);
    
    if (a == 0)
        fa = 1;
    if (b == 0)
        fb = 1;
    if (c == 0)
        fc = 1;
    
    f = (fa) /(fb*fc);
    return f;
}
//Ln(2)
float uno(int n){
    int i=0, signo = 1;
    float f = 0.0;
    do{
        f += ((float)signo)/((float)i+1);
        i++;
        signo*=(-1);
    }while(i<n);
    
    return f;
}
float unor(int n){
    static int signo = 1, i = 0;
    static float f = 0.0;

    if (n == 1)
        return f + ((float)signo)/((float)i+1);
    else {
        f += ((float)signo)/((float)i+1);
        i++;
        signo *= (-1);
        return unor(n-1);
    }
    return 0;
}
//pi/4
float dos(int n){
    int i=0, signo = 1, cont = 0;
    float f = 0.0;
    do{
        f += ((float)signo)/((float)i+1);
        i+=2;
        cont++;
        signo*=(-1);
    }while(cont<n);
    
    return f;
}
float dosr(int n){
    static int i = 0, signo = 1;
    static float f = 0.0;
    if (n == 1)
        return f + ((float)signo)/((float)i+1);
    else {
        f += ((float)signo)/((float)i+1);
        i+=2;
        signo*=(-1);
        return dosr(n-1);
    }
}
//pi^2/6
float tres(int n){
    int i=0;
    float f = 0.0;
    do{
        f += (1) / (((float)i+1) * ((float)i+1));
        i++;
    }while(i<n);
    
    return f;
}
float tresr(int n) {
    static int i = 0;
    static float f = 0.0;
    if (n == 1)
        return f + (1) / (((float)i+1) * ((float)i+1));
    else {
        f += (1) / (((float)i+1) * ((float)i+1));
        i++;
        return tresr(n-1);
    }
}

//pi^2 / 8
float cuatro(int n){
    float r = 0.0;
    int i=1;
    do{
        r+=((1.0)/((2*i-1)*(2*i-1)));
        i++;
    }while(i<=n);
    return r;
}
float cuatror(int n){
    static float r = 0.0;
    static int i = 1;
    if (n == 1)
        return r + ((1.0)/((2*i-1)*(2*i-1)));
    else {
        r+=((1.0)/((2*i-1)*(2*i-1)));
        i++;
        return cuatror(n-1);
    }
}
// 1/2
float cinco(int n){
    int i=1, j=3;
    float f = 0.0;
    do{
        f += ((1) / ((float)i*j));
        i+=2;
        j+=2;
    }while(i<n++||j<n+3);
    return f;
}
float cincor(int n){
    static int i = 1, j = 3;
    static float f = 0.0;
    if (n == 1)
        return f + ((1) / ((float)i*j));
    else {
        f += ((1) / ((float)i*j));
        i+=2;
        j+=2;
        return cincor(n-1);
    }
}
// 3/4
float seis(int n){
    int i=1, j=3;
    float f = 0.0;
    do{
        f += ((1) / ((float)i*j));
        i+=1;
        j+=1;
    }while(j<n+3);
    return f;
}
float seisr(int n){
    static int i = 1, j = 3;
    static float f = 0.0;
    if (n ==1)
        return f + ((1) / ((float)i*j));
    else {
        f += ((1) / ((float)i*j));
        i+=1;
        j+=1;
        return seisr(n-1);
    }
}
// e^x
float siete(float x, int n){
    float r=1;
    int i=1, fact=1;
    float num=1;
    do{
        num*=x;
        fact*=i;
        i++;
        r+=(num/(fact));
    }while(i<n);
    return r;
    
}
float sieter(float x, int n){
    static float r = 1, num = 1;
    static int i = 1, fact = 1;
    if (n == 1)
        return r ;
    else {
        num*=x;
        fact*=i;
        i++;
        r+=(num/(fact));
        return sieter(x, n-1);
    }
}
// ln (1 + x)
float ocho(float x, int n){
    float r = 0;
    int i=1,sig=1;
    float num=1;
    if(x>-1&&x<=1){
    do{
        num*=x;
        r+=((sig)*((num/i)));
        sig*= -1;
        i++;
    }while(i<=n);
    }else{
            
            printf("Datos incorretos (-1 < x <= 1)\n\n");
        }
     return r;
}
float ochor(float x, int n){
    static float r = 0.0;
    static int i = 1, sig = 1;
    static float num = 1;
    if(x>-1&&x<=1){
        if (n == 0)
            return r ;
        else {
            num *= x;
            r+=((sig)*((num/i)));
            sig*= -1;
            i++;
            return ochor(x, n-1);
        }
    }else{
        printf("Datos incorretos (-1 < x <= 1)\n\n");
    }
    return 0;
}
// 1/2 ln(1+x/1-x)
float nueve(float x, int n){
    float r=0;
    int i=0;
    float num=x;
    do{
        r+=((num)/(2*i+1));
        num*=x*x;
        i++;
        
    }while(i<n);
    return r;
    
}
float nuever(float x, int n){
    static float r = 0;
    static int i = 0;
    static float num;
    if (i == 0)
        num = x;
    if (n == 1)
        return r;
    else {
        r+=((num)/(2*i+1));
        num*=x*x;
        i++;
        return nuever(x, n-1);
    }
}
//Ln(x)
float diez(float x, int n){
    float r=0;
    int i=0;
    float ope=((x-1)/(x+1));
    float a = ope;
    do{
        r+=(a*(1/(2*(float)i+1)));
        a*=ope*ope;
        i++;
        printf("%f\n",r);
        
    }while(i<n);
    
    return 2*r;
    
}
float diezr(float x, int n) {
    static float r = 0;
    static int i = 0;
    float ope=((x-1)/(x+1));
    static float a;
    if (i == 0)
        a = ope;
    if (n == 0)
        return 2*r;
    else {
        r+=(a*(1/(2*(float)i+1)));
        a*=ope*ope;
        i++;
        return diezr(x, n-1);
    }
}
//Ln(x)
float once(int n, float x){
    int i = 0;
    float f,a, fx = 1;
    if (x >= (0.5)){
        a = ((x-1) / (x));
        do{
        i++;
        fx *= a;
        f += ((1/(float)i) * fx);
    }while(i < n);
    }else{
        printf("X debe ser mayor a 1/2\n");
    }
    return f;
}

float oncer(int n, float x){
    static int i = 0;
    float f, a, fx=1;
    a = ((x-1) / (x));
    if (x >= (0.5)){
        if (n == 1)
            return f;
        else{
            i++;
            fx *= a;
            f += ((1/(float)i) * fx);
            return oncer(n-1, x);
        }
    }else{
        printf("X debe ser mayor a 1/2\n");
    }
    return 0;
}
// a^x
float doce(int n, float x, float a){
    float f = 0.0, fx = 1.0;
    float b = (x*diez(n, a));
    int i = 0;
    
    if (x >= (1/2)){
        if (n == 1)
        f = 1;
        while (i<n){
            fx *= b/((float)i+1);
            f += fx;
            i++;
        }
        f += 1;
    }else{
        printf("X debe ser mayor a 1/2\n");
    }
    return f + 1;
}

//Bernoulli
long trece(int n, int x)
{
    long f = 1;
    if(n == 1|| n == 0 || n == x)
        return 	1;
    unsigned int d = n - x;
    
    while(n>1 || x>1 || d>1)
    {
        f *= n;
        f /= (x * (float)d);
        if(n>1)
            n--;
        if(x>1)
            x--;
        if(d>1)
            d--;
    } 
    return f;
}
//Ek
float catorce(int n,int k){
    int i = 0, sg = 1;
    float f, a;
    a = 2*k + 1;
    while (i < n) {
        f += (sg*1) / (powf((float)i+1, (float)a));
        sg *= (-1);
        i += 2;
    }
    return f*(pow(2, (2*k + 1)))*(factorial(2*k)) / powf(M_PI, a);
}

//sen(x)
float diezy6(int n, float x){
    float sx=0, f;
    int i, signo = 1;
    for (i = 0, f = x; i < n; i++){
        signo *= (-1);
        sx += (signo*f);
        f *= ((x / (2 * i + 2))*(x / (2 * i + 3)));
    }
    return sx;
}
float diezy6r(int n,float x){
    static float fc;
    static int i=1;
    float c;
    if(i==1)
        fc=x;
    fc*=((x/(2*i))*(x/(2*i+1)));
    i++;
    c=(2*(i%2)-1)*fc;
    if (i<(n+1))
        return diezy6r(n,x)+c;
    return x;
}
//cos(x)
float diezy7(float x,int n){
    float cx,fc;
    int i,sgn;
    for(i=0, cx=0, sgn=1, fc=1;i<n;i++, sgn*=(-1)){
        cx+=(sgn*fc);
        fc*=((x/(2*i+1))*(x/(2*i+2)));}
    return cx;
}
float diezy7r(float x,int n){
    static float fc=1;
    static int i=1;
    float c;
    fc*=((x/(2*n))*(x/(2*n-1)));
    c=(1-2*(i%2))*fc;
    i++;
    if(i<=(n+1))
        return diezy7r(x,n)+c;
    return 0;
}

float veinti1(float x,int n){   //Arcsin(x)
    float asx,fc;
    int i;
    float c;
    for(i=0, asx=0, fc=x;i<n;i++){
        asx+=fc;
        c=2.0*((float)i+1.0)+1.0;
        fc*=((((c+1)*x)/((i+1)*(i+2)))*(((c+2)*x)/((i+1)*(i+2)))*(1/(4*c)));}
    return asx;
}
float veinti1r(float x,int n){
    static float fc;
    static int i=1;
    float aux;
    if(i==1){
        fc=x;
        fc*=(pow(x,3)/6);}
    else{
        aux=2*i+1;
        fc*=(((aux-1)*x)/i*((aux-2)*x)/i*(1/(4*aux)));}
    i++;
    aux=fc;
    if(i<=(n+1))
        return veinti1r(x,n)+aux;
    return x;
}
//arccos
float veinti2(int n, float x){
    float f = 0.0, fx = x;
    int i = 0;
    if (sqrt(x*x) < 1) {
        while (i<n){
        f += fx;
        fx *= (x*x*(2*i-1)*(2*i)) / ((4)*i*i*(2*i+1));
        i++;
        }
    }else{
        printf("|x| tiene que ser menos a 1\n");
    }
    return M_PI_2 - f;
}
float veinti2r(int n,float x){	//Provisional
    return M_PI_2-veinti1r(x,n);
}

float veinti3(float x,int n){   //Arctg(x)
    float atx,fc,hpi=3.141592/2;
    int sgn,i;
    if((x<=-1)||(x>=1)){
        for(i=0, atx=0, fc=x, sgn=-1;i<n;i++, sgn*=(-1)){
            atx+=(sgn*fc);
            fc/=(x*x*(2*(i+1)+1));}
        if(x<=-1)
            return atx-hpi;
        else
            return hpi+atx;}
    else
        for(i=0, atx=0, fc=x, sgn=1;i<n;i++, sgn*=(-1)){
            atx+=(sgn*fc);
            fc*=((x/(2*(i+1)+1))*x);}
    return atx;
}
float veinti3r(float x,int n){
    static float fc;
    static int i=1;
    float c,hpi=3.141592/2;
    if(i==1)
        fc=x;
    if((x<=-1)||(x>=1)){
        fc/=(x*x*(2*i+1));
        c=(2*(i%2)-1)*fc;
        i++;
        if(x<=-1){
            if(i<=(n+1))
                return veinti3r(x,n)+c;
            return -hpi-(1/x);}
        else{
            if(i<=(n+1))
                return veinti3r(x,n)+c;
            return hpi-(1/x);}}
    else{
        fc*=((x/(2*i+1))*x);
        c=(1-2*(i%2))*fc;
        i++;
        if(i<=(n+1))
            return veinti3r(x,n)+c;
        return x;
    }
}
//senh(x)
float veinti4(int n, float x){
    float f = 0.0, fx = x;
    int i = 1;
    while (i<n) {
        f += fx;
        fx *= (x*x)/(2*i+1);
        i++;
    }
    return f;
}
float veinti4r(int n,float x){
    static float fc;
    static int i=1;
    float c;
    if(i==1)
        fc=x;
    fc*=((x/(2*i))*(x/(2*i+1)));
    i++;
    c=fc;
    if (i<(n+1))
        return veinti4r(n,x)+c;
    return x;
}

float veinti5(float x,int n){  //Cosh(x)
    float chx,fc;
    int i;
    for(i=0, chx=0, fc=1;i<n;i++){
        chx+=fc;
        fc*=((x/(2*i+1))*(x/(2*i+2)));}
    return chx;
}
float veinti5r(float x,int n){
    static float fc=1;
    static int i=1;
    float c;
    fc*=((x/(2*i))*(x/(2*i-1)));
    c=fc;
    i++;
    if(i<=(n+1))
        return veinti5r(x,n)+c;
    return 1;
}

float veinti7(float x,int n){ //Arcsinh(x)
    float ashx,fc;
    int c,i,j,sgn;
    for(i=0, ashx=0, fc=x, sgn=1;i<n;i++, sgn*=(-1)){
        ashx+=(fc*sgn);
        c=2*i+1;
        fc*=(((c*x)/((i+1)*(i+2)))*(((c+1)*x)/((i+1)*(i+2)))*(1/c));
        if(i==0)
            continue;
        for(j=0;j<i;j++)
            fc/=4;}
    return ashx;
}
float veinti7r(float x,int n){
    static float fc;
    static int i=1;
    float aux;
    if(i==1){
        fc=x;
        fc*=(pow(x,3)/6);}
    else{
        aux=2.0*(float)i+1.0;
        fc*=(((aux-1)*x)/i*((aux-2)*x)/i*(1/(4*aux)));}
    aux=(1-2*(i%2))*fc;
    i++;
    if(i<=(n+1))
        return veinti7r(x,n)+aux;
    return x;
}

float veinti8(int n, float x){
    int i = 0;
    float f, fx = x;
    
    while (i < n) {
    if (sqrt(x*x) < 1){
        f += fx / (2*i+1);
        fx *= (x*x);
        }else{
        printf("|x| tiene que ser menor a 1");
        }
    }
    return f;
    
}
float veinti8r(int n,float x){
    static float fc;
    static int i=1;
    float c;
    if(i==1)
        fc=x;
    fc*=(x*(x/(2*i+1)));
    i++;
    c=fc;
    if(i<=(n+1))
        return veinti8r(n,x)+c;
    return x;
}

float veinti9(float x,int n){ //ln(1+x)/1+x
    float lxdx,fc;
    int i,j,sgn;
    for(i=0, sgn=1, lxdx=0, fc=x;i<n;i++, sgn*=(-1)){
        lxdx+=(fc*sgn);
        for(j=0;j<=i;j++)
            fc+=(1/(j+1));
        fc*=x;}
    return lxdx;
}
float veinti9r(float x,int n){
    static float fc,aux=1.0;
    static int i=1;
    float c;
    if(i==1)
        fc=x;
    i++;
    aux+=(1.0/(float)i);
    fc*=x;
    c=(2*(i%2)-1)*fc*aux;
    if(i<=(n+1))
        return veinti9r(x,n)+c;
    return x;
}

int main(){
    char op;
    int i,n;
    int opc;
    float x = 0.0,a;
    
    do{
        
        n = 0;
        system("cls");
        op = '\0';
    do{
        printf("Introduzca numero de iteraciones: ");
        scanf("%d",&n);}
    while(n<1);
    do{
        printf("\nCalcular constantes (c) o variables (v)? ");
        fflush(stdin);
        op=getchar();}
    while((op!='c')&&(op!='v'));
    do{
        if((op=='C')||(op=='c')){
            system("cls");
            printf("\tIntroduzca opcion:\n");
            printf("\n1)ln(2)\n2)pi/4\n3)pi^2/6\n4)pi^2/8\n5)1/2\n6)3/4\n>>Su opcion: ");}
        else{
            printf("\nIntroduzca valor de x (recuerde ingresar valores correctos para las formulas; no se garantiza la certeza del resultado de otra forma): ");
            scanf("%f",&x);
            system("cls");
            printf("\tIntroduzca opcion:\n");
            printf("\n7)e^x\n8)ln(1+x)\n9)(1/2)ln((1+x)/(1-x))\n10)ln(x)\n11)ln(x) - Metodo alterno\n12)a^x\n13)Bk\n14)Ek\n15)E2k\n16)sen(x)");
            printf("\n17)cos(x)\n18)tan(x)\n19)sec(x)\n20)csc(x)\n21)arcsen(x)\n22)arccos(x)\n23)arctan(x)\n24)senh(x)\n25)cosh(x)\n26)tanh(x)");
            printf("\n27)arcsenh(x)\n28)arctanh(x)\n29)ln(1+x)/(1+x)\n30)e^sen(x)\n>>Su opcion: ");
        }
        scanf("%d",&i);}
    while((i<1)||(i>30));
    switch(i)
    {
        case 1:
            printf("\nln(2) = %f\n",uno(n));
            printf("ln(2) (recursiva) = %f\n",unor(n));
            break;
        case 2:
            printf("\npi/4 = %f\n",dos(n));
            printf("\npi/4 (recursiva) = %f\n",dosr(n));
            break;
        case 3:
            printf("\npi^2/6 = %f\n",tres(n));
            printf("\npi^2/6 (recursiva) = %f\n",tresr(n));
            break;
        case 4:
            printf("\npi^2/8 = %f\n",cuatro(n));
            printf("\npi^2/8 (recursiva) = %f\n",cuatror(n));
            break;
        case 5:
            printf("\n1/2 = %f\n",cinco(n));
            printf("\n1/2 (recursiva)= %f\n",cincor(n));
            break;
        case 6:
            printf("\n3/4 = %f\n",seis(n));
            printf("\n3/4 (recursiva)= %f\n",seisr(n));
            break;
        case 7:
            printf("\ne ^ %.2f = %f\n",x,siete(x,n));
            printf("\ne ^ %.2f(recursiva) = %f\n",x,sieter(x,n));
            break;
        case 8:
            printf("\nln(1+%.2f) = %f\n",x,ocho(x,n));
            printf("\nln(1+%.2f)(recursiva) = %f\n",x,ochor(x,n));
            break;
        case 9:
            printf("\nln(1+%.2f) = %f\n",x,nueve(x,n));
            printf("\nln(1+%.2f) (recursiva) = %f\n",x,nuever(x,n));
            break;
        case 10:
            printf("\nln(%.2f) = %f\n",x,diez(x,n));
            printf("ln(%.2f) = %f\n",x,diezr(x,n));
            break;
        case 11:
            printf("\nln(%.2f) = %f\n",x,once(n,x));
            printf("\nln(%.2f)(recursiva) = %f\n",x,once(n,x));
            break;
        case 12:
            printf("\nIntroduzca valor de a: ");
            scanf("%f",&a);
            printf("%.2f ^ %.2f = %f\n",a,x,doce(1,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(2,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(4,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(8,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(16,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(32,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(64,x,a));
            printf("%.2f ^ %.2f = %f\n",a,x,doce(128,x,a));
            break;
        case 13:
            printf("\nB(%.0f) = %li\n",x,trece(n,x));
            break;
        case 14:
            printf("\nE(%.0f) = %f\n",x,catorce(x,n));
            break;
        case 15:
            break;
        case 16:
            printf("\nsen(%.2f) = %f\n",x,diezy6(n,x));
            break;
        case 17:
            printf("\ncos(%.2f) = %f\nResultado recursividad: %f\n",x,diezy7(x,n),diezy7r(x,n));
            break;
        case 18:
            printf("Ingrese k\n");
            int k, l;
            scanf("%i",&k);
            printf("Ingrese l\n");
            scanf("%i",&l);
            printf("comb %f\n",comb(k, l));
            break;
        case 19:
            break;
        case 20:
            break;
        case 21:
            printf("\narcsen(%.2f) = %f\nResultado recursividad: %f\n",x,veinti1(x,n),veinti1r(x,n));
            break;
        case 22:
            break;
        case 23:
            printf("\narctan(%.2f) = %f\nResultado recursividad: %f\n",x,veinti3(x,n),veinti3r(x,n));
            break;
        case 24:
            printf("\nsenh(%.2f) = %f\n",x,veinti4(n,x));
            break;
        case 25:
            printf("\ncosh(%.2f) = %f\nResultado recursividad: %f\n",x,veinti5(x,n),veinti5r(x,n));
            break;
        case 26:
            break;
        case 27:
            printf("\narcsenh(%.2f) = %f\nResultado recursividad: %f\n",x,veinti7(x,n),veinti7r(x,n));
            break;
        case 28:
            printf("\narctanh(%.2f) = %f",x,veinti8(n,x));
            break;
        case 29:
            printf("\nln(1+%.2f)/(1+%.2f) = %f\nResultado recursividad: %f",x,x,veinti9(x,n),veinti9r(x,n));
            break;
        case 30:
            break;
        default:
            printf("\nNo se como llego a mostrar este mensaje, pero no le sirvio de mucho :v");
            break;
    }
        printf("\n¿DESEA REALIZAR OTRA OPERACION\n SI=1\nNO=0\n");
        scanf("%i",&opc);
        
}while(opc==1);
    return 0;
}
