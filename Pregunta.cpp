/*
 * Pregunta.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#include "Pregunta.h"
int Pregunta::autoincremental3=0;
Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}
Pregunta::Pregunta(string descripcion,string titulo,Fecha &Fp,Usuario &Usu):fechaPregunta(Fp),usuarioP(Usu){
	this->idpregunta=Pregunta::autoincremental3++;
	this->titulo=titulo;
	this->descripcion=descripcion;
}
Pregunta::Pregunta(Pregunta &aux):fechaPregunta(aux.fechaPregunta),usuarioP(aux.usuarioP){
	this->idpregunta=aux.idpregunta;
	this->titulo=aux.titulo;
	this->descripcion=aux.descripcion;
}
void Pregunta::ListarInformacion(){
	cout<<"ID pregunta: "<<this->idpregunta<<endl;
	cout<<"Titulo: "<<this->titulo<<endl;
	cout<<"Descripcion: "<<this->descripcion<<endl;
	cout<<"Usuario: "<<endl;
	this->usuarioP.ListarInformacion();
}
/*Metodo Agregar Respuesta*/
void Pregunta::AgregarRespuesta(){

}
Pregunta::~Pregunta() {
	// TODO Auto-generated destructor stub
}

