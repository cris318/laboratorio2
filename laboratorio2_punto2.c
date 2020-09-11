//laboratorio 2 parte 2
//elaborado por:por cristian rincon y julian ballesteros
//asignatura: Alse grupo 2

#include <stdio.h>
#include <string.h>
#define MAXI 10
#define MINI 3 
// definimos prototipos
int pedir_palabras(int *lon1,int *lon2,int *lon3,char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI]);
void comparar(char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band );
void invertir(int lon1,int lon2, int lon3,char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band );
void longitudes(int lon1,int lon2,int lon3,char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band );
void concatenar(char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band );
void sumar(char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band );
void salir();
//menu principal
int main()
{
	char palabra1[MAXI],palabra2[MAXI],palabra3[MAXI];
	int lon1=0,lon2=0,lon3=0; 
	int opcion=0,bandera=0;
	printf("\t\nBienvenido\n");
	printf("\t\neste programa le solicita 3 palabras y realiza las operaciones listadas acontinuacion\n");
	
	do
	{//imprimimos el menu con las opciones
		printf("\nseleccione la opcion que desea realizar\n");
		printf("\n1.ingresar palabras\n");
		printf("\n2.comparar palabras\n");
		printf("\n3.invertir palabras\n");
		printf("\n4.concatenar palabras\n");
		printf("\n5.mostrar longitud de las palabras\n");
		printf("\n6.sumar palabras\n");
		printf("\n7.salir\n");
		
		scanf("%d",&opcion);
	switch(opcion)
	{// se valida la opcion recibida y lo envia a la funcion deseada
		case 1:bandera=pedir_palabras(&lon1,&lon2,&lon3,palabra1,palabra2,palabra3); 
		break;
		case 2:comparar(palabra1,palabra2,palabra3,bandera);
		break;
		case 3:invertir(lon1,lon2,lon3,palabra1,palabra2,palabra3,bandera);
		break;
		case 4:concatenar(palabra1,palabra2,palabra3,bandera);
		break;
		case 5:longitudes(lon1,lon2,lon3,palabra1,palabra2,palabra3,bandera);
		break;
		case 6:sumar (palabra1,palabra2,palabra3,bandera);
		break;
		case 7:printf("\nHasta luego\n");
		break;
		default:printf("\t\n no a ingresado un valor correcto, intente nuevamente\n");
	}
	}
	while(opcion!=7);
	
	
	return 0;
}
int pedir_palabras(int *lon1,int *lon2,int *lon3,char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI])
{
	printf("\nbienvenido por favor ingrese las palabras mas de 2 y menos de 11 caracteres\n");
	printf("\nEscribe la primera palabra:\n");  //pedimos las palabras
    scanf("%s", palabra1);
    printf("Escribe la segunda palabra:\n");
    scanf("%s", palabra2);
    printf("escribe la tercera palabra\n");
    scanf("%s", palabra3);
	*lon1 = strlen (palabra1); // obtenemos la longitud de la palabra
	*lon2 = strlen (palabra2);
	*lon3 = strlen (palabra3);
	if((*lon1>=MINI)&(*lon1<=MAXI)&(*lon2>=MINI)&(*lon2<=MAXI)&(*lon3>=MINI)&(*lon3<=MAXI))
	{
		
	}
	else 
	{ printf("\n\npor favor volver a poner las palabras con las respectivas condiciones\n\n");
	
	}
	
    return 1;
}
void comparar(char palabra1[MAXI],char palabra2[MAXI],char palabra3[MAXI],int band)
{
	int com1=0,com2=0,com3=0;
	com1=strcmp(palabra1,palabra2); // se usa una funcion de comparacion donde nos da resultado un numero 
	com2=strcmp(palabra2,palabra3);
	com3=strcmp(palabra1,palabra3);
	if(band ==0)
		printf("\t\n no hay palabras ingresadas,primero ingrese las palabras\n\n");
	if(band==1)
	{
	if (com1==0&com2==0&com3==0)
	{
		printf("\nlas palabras son todas iguales\n"); //con la funcion del if y el resulado de strcmp se hacen las condiciones
	}
	if ( com1==0&com2!=0&com3!=0)
	{
		printf ("\nlas primeras dos palabras son iguales pero la tercera es diferente\n");
	}
	if (com1!=0&com2==0&com3!=0)
	{
		printf("\nla primera palabra es diferente pero las demas son iguales \n");
	}
	if (com1!=0&com2!=0&com3==0)
	{
		printf("\nla primera y tercera palabra son iguales pero la segunda es diferente\n");
	}
	else 
	{
		printf("\nlas palabras son total mente diferentes \n");
	}
	
	}


}
void invertir(int lon1,int lon2,int lon3,char palabra1[MAXI], char palabra2[MAXI], char palabra3[MAXI],int band )
{
	if(band ==0)
		printf("\t\n no hay palabras ingresadas,primero ingrese las palabras\n");
	if(band==1)
	{
		int i; //con la funcion de un for se va corriendo letra por letra asta llegar al fina de la palabra
		printf("la primera palabra invertida es :");	
		for (i = 0; palabra1[i] != '\0'; i++)
		{
			printf("%c", palabra1[lon1-1-i]); //con ayuda de la longitud se calcula la pocicion de cada letra de la palabra 	
		}
		printf("\nla segunda palabra invertida es :");	
		for (i = 0; palabra2[i] != '\0'; i++)
		{
			printf("%c", palabra2[lon2-1-i]);	
		}
		printf("\nla segunda palabra invertida es :");	
		for (i = 0; palabra3[i] != '\0'; i++)
		{
			printf("%c", palabra3[lon3-1-i]);	
		}
		
	}
}
void longitudes(int lon1,int lon2,int lon3,char palabra1[MAXI], char palabra2[MAXI], char palabra3[MAXI],int band )
{
	
	if(band ==0)
		printf("\t\n no hay palabras ingresadas,primero ingrese las palabras\n");
	if(band==1)
	{
	printf("\nla longitud de la primera palabra es: %d\n",lon1); // imprimimos la longitud de la palabra
	printf("\nla longitud de la segunda palabra es: %d\n",lon2);
	printf("\nla longitud de la tercera palabra es: %d\n",lon3);
	}
}
void concatenar(char palabra1[MAXI], char palabra2[MAXI], char palabra3[MAXI],int band )
{
	if(band ==0)
		printf("\t\n no hay palabras ingresadas,primero ingrese las palabras\n");
	if(band==1)
	{
	char con[40];
	strcpy(con,palabra1 );  //para que en la salida la primera palabra sea lo primero que se escribe se copia a la nueva cadena de caracteres 
	strcat(con," ");       // enseguida usamos la funcion de unir  y agregamos un espacio para que las plabras no esten unidas
	strcat(con,palabra2 );
	strcat(con," ");
	strcat(con,palabra3 );
	printf("\nTus palabras son: %s\n ", con);  // Aquí mostraremos las palabras unidas 
    }
}
void sumar(char palabra1[MAXI], char palabra2[MAXI], char palabra3[MAXI],int band)
{
	if(band ==0)
		printf("\t\n no hay palabras ingresadas,primero ingrese las palabras\n");
	if(band==1)
	{
		int i; //variable que dara la pocicion del caracter
		int suma1=0,suma2=0,suma3=0; //resultado de la suma 
		printf("los valores ascii de cada letra de la primera palabra son:");	
		for (i = 0; palabra1[i] != '\0'; i++)      //con la funcion del for se hace un bucle para mostrar y sumar los valores de cada palabra
		{
			printf(" %d", palabra1[i]);
			suma1=suma1+palabra1[i];
		}
		printf("\ny la suma de los valores son: %d\n",suma1);
		printf("los valores ascii de cada letra de la segunda palabra son:");	
		for (i = 0; palabra2[i] != '\0'; i++)
		{
			printf(" %d", palabra2[i]);
			suma2=suma2+palabra1[i];
		}
		printf("\ny la suma de los valores son: %d\n",suma2);
		printf("los valores ascii de cada letra de la tercera palabra son:");	
		for (i = 0; palabra3[i] != '\0'; i++)
		{
			printf(" %d", palabra3[i]);
			suma3=suma3+palabra3[i];
		}
		printf("\ny la suma de los valores son: %d",suma3);
		putchar('\n');
			
	}

}
