/*
 * Activo.cpp
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#include "Activo.h"
#include "Inactiva.h"
#include "Pregunta.h"

Activo::Activo(Pregunta *pregunta):Estado(pregunta) {
	// TODO Auto-generated constructor stub

}
void Activo::EncargarseDe1(){
	cout<<"Cambio el estado a Inactivo"<<endl;
	cout<<"Aqui se detiene"<<endl;
	this->pregunta_->ListarInformacion();
	this->pregunta_->TransitionTo(new Inactiva(this->pregunta_));
}
void Activo::EncargarseDe2(){
	cout<<"No cambio de estado aqui"<<endl;
}
void Activo::AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1){
	cout<<"Estoy en el estado Activo"<<endl;
	Respuesta *nuevaR = new Respuesta("Respuesta aleatoria",f1,aux);
	auxPreg->InsertarRespuesta(nuevaR);
	auxPreg->fechaUltimaRespuesta=f1;
}
Activo::~Activo() {
	// TODO Auto-generated destructor stub
}

