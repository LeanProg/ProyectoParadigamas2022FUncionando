/*
 * Respuesta.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#include "Respuesta.h"

int Respuesta::autoincremental2=0;

Respuesta::Respuesta() {


}
Respuesta::Respuesta(string descrip,Fecha &fecha,Usuario &usu):fechaRespuesta(fecha),usuarioR(usu){
		this->idrespuesta= Respuesta::autoincremental2++;
		this->descripcion=descrip;
		this->aceptada= false;
		this->contadorMegusta=0;
}
void Respuesta::ListarInformacion(){
	cout<<"Id respuesta: "<<this->idrespuesta<<endl;
	cout<<"Descripcion: "<<this->descripcion<<endl;
	cout<<"Datos del usuario: "<<endl;
	this->usuarioR.ListarInformacionDos();
}
Respuesta::~Respuesta() {
	// TODO Auto-generated destructor stub
}

