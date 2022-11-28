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
#include "Solucionado.h"
#include <typeinfo.h>

int Pregunta::autoincremental3=0;
Pregunta::Pregunta() {
	// TODO Auto-generated constructor stub

}
Pregunta::Pregunta(string descripcion,string titulo,Fecha &Fp,Usuario &Usu):fechaPregunta(Fp),usuarioP(Usu),estado_(new Activo(this)){
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
	 std::cout << "Estado de la pregunta " << typeid(*estado_).name() << ".\n";
	cout<<"-----Usuario----"<<endl;
	this->usuarioP.ListarInformacionDos();

}
void Pregunta::MarcarComoAceptada(int idRes){
	this->contenedorRespuesta[idRes]->MarcarComoAceptada();
	this->TransitionTo(new Solucionado(this));
}
void Pregunta::DarMegustaRespuesta(int a){
	for (int var = 0; var < this->contenedorRespuesta.size(); ++ var) {
		if (this->contenedorRespuesta[var]->getIdRespuesta()==a){
			this->contenedorRespuesta[var]->IncrementarContador();
		}else{
			cout<<"No se encontre ese Id de respuesta en esta pregunta"<<endl;
		}
	}
}

void Pregunta::ListarInformaciondos(){
	cout<<"///////////////******//////////////////"<<endl;
	cout<<"ID pregunta: "<<this->idpregunta<<endl;
	cout<<"Fecha de la pregunta: "<<this->fechaPregunta<<endl;
	cout<<"Titulo: "<<this->titulo<<endl;
	cout<<"Descripcion: "<<this->descripcion<<endl;
	 std::cout << "Pregunta: Transition to " << typeid(*estado_).name() << ".\n";
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
/*void Pregunta::AgregarRespuesta(Fecha f1,Usuario aux){
	Respuesta *nuevaR = new Respuesta("Si porque hace frio",f1,aux);
	contenedorRespuesta.insert(contenedorRespuesta.end(),nuevaR);
}*/

/*Metodo para Ingresar Respuesta*/
void Pregunta::InsertarRespuesta(Respuesta *Raux){
	contenedorRespuesta.insert(contenedorRespuesta.end(),Raux);
}
void Pregunta::ListarRespuestas(){
	for (int var = 0; var < contenedorRespuesta.size(); ++var) {
		cout<<"----->";contenedorRespuesta[var]->ListarInformacion();
	}
}
void Pregunta::AgregarTag(string tag,int pos){
	this->tags[pos]=tag;
}
string Pregunta::DevolverTag(int Pos){
	 return this->tags[Pos];
}
int Pregunta::getIdUsuario(){
	return this->usuarioP.getId();
}
void Pregunta::OrdenarPorMegusta(){
	sort(contenedorRespuesta.begin(),contenedorRespuesta.end(),[] (Respuesta *x,Respuesta *y) {return x->getCantidadMegusta() >y->getCantidadMegusta();});
}
void Pregunta::TransitionTo(Estado *estado){
		std::cout << "Pregunta, estado antes de ser borrado " << typeid(*estado).name() << ".\n";
		delete this->estado_;
		this->estado_ = estado;
}
void Pregunta::AgregarRespuestaSegunEstado(Fecha f1,Usuario usu){
	cout<<"Metodo Agregar Respuesta"<<endl;
	this->estado_->AgregarRespuesta(this,usu,f1);
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

