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

Inactiva::Inactiva() {
	// TODO Auto-generated constructor stub

}
void Inactiva::EncargarseDe1(){
	cout<<"El estado queda como esta"<<endl;
}
void Inactiva::EncargarseDe2(){
	cout<<"cambio el estado a Activo"<<endl;
	this->pregunta_->TransitionTo(new Activo);
}
Inactiva::~Inactiva() {
	// TODO Auto-generated destructor stub
}

