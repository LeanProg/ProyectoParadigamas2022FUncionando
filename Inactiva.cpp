/*
 * Inactiva.cpp
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */
#include <iostream>
#include "Inactiva.h"
#include "Activo.h"
#include "Pregunta.h"

using namespace std;

Inactiva::Inactiva(Pregunta * pregunta):Estado(pregunta) {
	// TODO Auto-generated constructor stub

}
void Inactiva::EncargarseDe1(){
	cout<<"El estado queda como esta"<<endl;
}
void Inactiva::EncargarseDe2(){
	cout<<"cambio el estado a Activo"<<endl;
	this->pregunta_->TransitionTo(new Activo(this->pregunta_));
}
void Inactiva::AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1){
	cout<<"Estoy en el estado Inactivo"<<endl;
	Respuesta *nuevaR = new Respuesta("Respuesta aleatoria Nueva para pasar a Activo",f1,aux);
	auxPreg->TransitionTo(new Activo(auxPreg));
	auxPreg->InsertarRespuesta(nuevaR);
	auxPreg->fechaUltimaRespuesta=f1;
}
Inactiva::~Inactiva() {
	// TODO Auto-generated destructor stub
}

