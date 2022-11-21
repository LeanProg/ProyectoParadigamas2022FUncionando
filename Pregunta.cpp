/*
 * Pregunta.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */
#include <vector>
#include <algorithm>
#include "Pregunta.h"
#include "Activo.h"
#include <typeinfo.h>

int Pregunta::autoincremental3=0;
Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}
Pregunta::Pregunta(string descripcion,string titulo,Fecha &Fp,Usuario &Usu):fechaPregunta(Fp),usuarioP(Usu),estado_(new Activo){
	this->idpregunta=Pregunta::autoincremental3++;
	this->titulo=titulo;
	this->descripcion=descripcion;
}
Pregunta::Pregunta(Pregunta &aux):fechaPregunta(aux.fechaPregunta),usuarioP(aux.usuarioP),estado_(aux.estado_){
	this->idpregunta=aux.idpregunta;
	this->titulo=aux.titulo;
	this->descripcion=aux.descripcion;

}
void Pregunta::ListarInformacion(){
	cout<<"///////////////*****//////////////////"<<endl;
	cout<<"---->ID pregunta: "<<this->idpregunta<<endl;
	cout<<"---->Fecha de la pregunta: "<<this->fechaPregunta<<endl;
	cout<<"---->Titulo: "<<this->titulo<<endl;
	cout<<"---->Descripcion: "<<this->descripcion<<endl;
	 std::cout << "Context: Transition to " << typeid(*estado_).name() << ".\n";
	cout<<"-----Usuario----"<<endl;
	this->usuarioP.ListarInformacionDos();

}

void Pregunta::DarMegustaRespuesta(int a){
	this->contenedorRespuesta[a]->IncrementarContador();
}

void Pregunta::ListarInformaciondos(){
	cout<<"///////////////******//////////////////"<<endl;
	cout<<"ID pregunta: "<<this->idpregunta<<endl;
	cout<<"Fecha de la pregunta: "<<this->fechaPregunta<<endl;
	cout<<"Titulo: "<<this->titulo<<endl;
	cout<<"Descripcion: "<<this->descripcion<<endl;
	 std::cout << "Context: Transition to " << typeid(*estado_).name() << ".\n";
	cout<<"-----Usuario que realizo la pregunta----";
	this->usuarioP.ListarInformacionDos();
	cout<<"<<<<Respuestas de esta pregunta>>>"<<endl;
	this->ListarRespuestas();

}

/*Obtener el id*/
int Pregunta::getid(){
	return this->idpregunta;
}
/*Metodo Agregar Respuesta*/
void Pregunta::AgregarRespuesta(Fecha f1,Usuario aux){
	Respuesta *nuevaR = new Respuesta("Si porque hace frio",f1,aux);
	contenedorRespuesta.insert(contenedorRespuesta.end(),nuevaR);
}

void Pregunta::ListarRespuestas(){
	for (int var = 0; var < contenedorRespuesta.size(); ++var) {
		cout<<"----->";contenedorRespuesta[var]->ListarInformacion();
	}
}
void Pregunta::OrdenarPorMegusta(){
	sort(contenedorRespuesta.begin(),contenedorRespuesta.end(),[] (Respuesta *x,Respuesta *y) {return x->getCantidadMegusta() >y->getCantidadMegusta();});
}
void Pregunta::TransitionTo(Estado *estado){
	if (this->estado_ != nullptr) {
		delete this->estado_;
		this->estado_ = estado;
		this->estado_->set_Pregunta(this);
	}

}
void Pregunta::Solicitud1(){
	cout<<"EnviarNotificacion y cambiar a Inactivo"<<endl;
	 std::cout << "Context: Transition to " << typeid(*estado_).name() << ".\n";
	this->estado_->EncargarseDe1();

}
void Pregunta::Solicitud2(){
	cout<<"Enviar Notificacion y cambiar a Activo"<<endl;
	std::cout << "Context: Transition to " << typeid(*estado_).name() << ".\n";
	this->estado_->EncargarseDe2();
}
Pregunta::~Pregunta() {
	delete estado_;
}

