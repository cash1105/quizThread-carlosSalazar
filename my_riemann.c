#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include "function.h"

#define NUMWORKERS 5
#define MAXRECT 10000

double widthbase;
int rectxworker;

struct ij {
	double low;
	double high;
};
pthread_mutex_t mutex;
double total = 0;
double total2= 0;


/*double suma(int id) {
	int i;
	double base = (double)(rectxworker*id*widthbase); 
	double resultado = 0;
	printf("\t\tId: %d base: %lf\n",id,base);
	for (i = 0; i < rectxworker; i++)
		 resultado += function(base + i*widthbase) * widthbase;
	return resultado;
}*/


void* suma_para(void *_data) {
	struct ij *data = (struct ij *)_data;
	double i=0;
	double resultado = 0;
//	printf("valor low y high:%lf,%lf,\n",data->low,data->high);
	for (i=data->low; i<data->high;i++){
		//printf("valor de i:%lf\n",i);
		resultado +=function(widthbase*i)*(widthbase);//  suma de rieamann por la izquierda
		//printf("resultado: %lf\n",resultado);

	}
	pthread_mutex_lock(&mutex);
	
	total = total + resultado;
	
	pthread_mutex_unlock(&mutex);
	//printf("\t\tId: %d base: %lf\n",id,base);
	
	return NULL;
}

int main(int argc, char** argv) {
	clock_t t1,t2;
	int maxrect = MAXRECT;  // Maxima cantidad de rectangulos
	int low_gral = 0;  // Limite inferior de la suma de riemann
	int high_gral = 1; //  Limite superior
	int nw = NUMWORKERS; // numero de hilos
	int j;
	struct ij particion[nw];
	pthread_t tid[nw]; 

	widthbase = (double)(high_gral - low_gral)/(double)maxrect; // tamano de cada rectangulo (step)
	printf("Width of the base %lf\n\n",widthbase);
	printf("Number of workers %d\n",nw); // numero de hilos
	rectxworker = (int)(maxrect/nw); //rectangulos por hilo
	printf("\tRectangles per worker %d\n",rectxworker);
	
	t1=clock();
	// Paralelizacion

	for (j = 0; j < nw; j++) {// proceso por cada hilo 
		
		particion[j].low=j*rectxworker;
		particion[j].high=(j+1)*rectxworker;
		//printf("valor low y high:%lf,%lf,\n",particion[j].low,particion[j].high);
		pthread_create(&tid[j],NULL,suma_para,&particion[j]);
	}
	for (j = 0; j < nw; j++) {
		pthread_join(tid[j], NULL);
	}
			
/*	for (j = 0; j < nw; j++) {
			total2 += suma(j); // proceso a bloquear
	}
	
	printf("\tTotal Metodo Clasico: %lf\n\n", total2);
	*/
	printf("\tTotal Metodo Riemann: %lf\n\n", total);
	//t2=clock();
	//printf("Tiempo total %lf,%lf,%f ms\n",t1,t2,difftime(t1,t2));
	
}


