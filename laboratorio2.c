//laboratorio_2
//autores: cristian rincon y julian ballesteros
//asignatura: Alse grupo 2

//definicion de librerias
#include <stdio.h>
//definicion de estructuras
typedef struct punto{
	float x;
	float y;
}punto;

//definimos prototipos
void validar_menu(int *opcion_invalida);
int ingresar_puntos(punto *p1,punto *p2,float *pend,float *cruce_y);
void mostrar_pendiente(punto p1,punto p2,float dat5,int band);
void cruce_eje_y(punto p1,punto p2,float pend, float interseccion,int band);
void ecuacion_recta( punto p1,punto p2,float pend,float cruce,int band);

//programa principal
void main()
 { 
	int menu =0;
	int band =0;
	punto punto1,punto2;
	//float x1 =0, x2 =0, y1=0, y2 =0;
	float pendiente =0, cruce_y =0;
	printf("\n\fBienvenido\n");			//damos la bienvenida al usuario
	printf("\nEste programa le solicita dos puntos sobre el plano cartesiano y halla los resultados que se muestran a continuacion\n");

do
{	// imprimimos opciones del menu
	printf("\t\n menu:\n");
	printf("\n seleccione una opcion\n");
	printf("\n 1. ingresar numeros\n");
	printf("\n 2. mostrar pendiente \n");
	printf("\n 3. mostrar cruce con el eje Y \n");
	printf("\n 4. mostrar ecuacion de la recta\n");
	printf("\n 5. salir\n");
	
	scanf("%d",&menu);
		
		switch(menu)
	{// validamos la opcion seleccionada del menu 
		case 1:band=ingresar_puntos(&punto1,&punto2,&pendiente,&cruce_y);
		break;
		case 2:mostrar_pendiente(punto1,punto2,pendiente,band);
		break;
		case 3:cruce_eje_y(punto1,punto2,pendiente,cruce_y,band);
		break;
		case 4:ecuacion_recta(punto1,punto2,pendiente,cruce_y,band);
		break;
		case 5:printf("\nHasta luego..\n");
		break;	
		default: printf("\n\tla opcion ingresada es incorrecta,intente nuevamente\n");
	}
}
while (menu !=5);
		
}

int ingresar_puntos(punto *p1,punto *p2,float *pend,float *cruce_y)
{
	// se piden y guardan las coordenadas de los puntos a operar
	printf("\f\n Opcion 1.\n");
	printf("\n escriba el primer punto de la recta\n");
	printf("\n coordenada X\n");
	scanf("%f", &p1->x);
	printf("\n coordenada Y\n");
	scanf("%f",&p1->y);
	printf("\f\n escriba el segundo punto de la recta\n");
	printf("\n coordenada X\n");
	scanf("%f", &p2->x);
	printf("\n coordenada Y\n");
	scanf("%f",&p2->y);
	
	*pend=((p2->y)-(p1->y))/((p2->x)-(p1->x));		// hallamos el valor de la pendiente
	*cruce_y= (p1->y)-((*pend)*(p1->x));			//hallamos el valor del cruce con el eje Y
	return 1;
}

void mostrar_pendiente(punto p1,punto p2,float dat5,int band)
{
	if(band==0)		// validamos si se han ingresado o no los valores de los puntos
		printf("\f\n no hay valores ingresados, por favor primero ingrese los puntos\n");
	if(band==1)
	{// imprimimos la pendiente
	printf("\f\n la pendiente de la recta que pasa por los puntos P1(%.3f,%.3f) y P2(%.3f,%.3f) es: %.3f\n",p1.x,p1.y,p2.x,p2.y,dat5);
	}
}

void cruce_eje_y(punto p1,punto p2,float pend, float interseccion,int band)
{
	if(band==0)			// validamos si se han ingresado o no los valores de los puntos
		printf("\n\f no hay valores ingresados, por favor primero ingrese los puntos\n");
	if(band==1)
	{		
	printf("\f\n el punto de interseccion con el eje Y es: %.3f\n\n",interseccion);//imprimimos el cruce con el eje Y
	}
}

void ecuacion_recta( punto p1,punto p2,float pend,float cruce,int band)
{
	char signo= '+';
	if(cruce<0)			// asignamos el signo de la parte compleja segun corresponda
		signo=' ';
	if(cruce>=0)
		signo='+';
	
	if(band==0)				// validamos si se han ingresado o no los valores de los puntos
		printf("\n\f no hay valores ingresados, por favor primero ingrese los puntos\n");
	if(band==1)
		//imprimimos el valor de la ecuacion de la recta
	printf("\f\n la ecuacion de la recta que pasa por los puntos P1(%.3f,%.3f) y P2(%.3f,%.3f) es y(x)= %.3fx %c%.3f\n\n",p1.x,p1.y,p2.x,p2.y,pend,signo,cruce);
}




