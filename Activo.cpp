/*
 * Activo.cpp
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#include "Activo.h"
#include "Pregunta.h"
#include "Inactiva.h"

Activo::Activo() {
	// TODO Auto-generated constructor stub

}
void Activo::EncargarseDe1(){
	cout<<"Cambio el estado a Inactivo"<<endl;
	this->pregunta_->TransitionTo(new Inactiva);
	this->pregunta_->ListarInformacion();
}
void Activo::EncargarseDe2(){
	cout<<"No cambio de estado aqui"<<endl;
}
Activo::~Activo() {
	// TODO Auto-generated destructor stub
}

