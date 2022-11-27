/*
 * Suspendido.cpp
 *
 *  Created on: Nov 23, 2022
 *      Author: Leandro
 */

#include "Suspendido.h"
#include "Pregunta.h"

Suspendido::Suspendido(Pregunta *pregunta):Estado(pregunta) {
	// TODO Auto-generated constructor stub

}

void Suspendido::EncargarseDe1(){
	cout<<"Estado Suspendido"<<endl;
}
void Suspendido::EncargarseDe2(){
	cout<<"Estado Suspendido Encargarse2"<<endl;
}
void Suspendido::AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1){
	cout<<"Estoy en estado Suspendido"<<endl;
	Respuesta *nuevaR= new Respuesta("No es necesario",f1,aux);
	auxPreg->InsertarRespuesta(nuevaR);
}
Suspendido::~Suspendido() {
	// TODO Auto-generated destructor stub
}

