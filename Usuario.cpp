/*
 * Usuario.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */
#include  <iostream>
#include "Usuario.h"
using namespace std;

int Usuario::autoincremental1= 0;

Usuario::Usuario() {
	// TODO Auto-generated constructor stub
	this->nombre= "";
	this->apellido = "";
	this->paisDeOrigen= "";
	this->email = "";
	this->contrasenia = "";
	this->id= Usuario::autoincremental1++;
	this->cantRespuestasAceptadas=0;

}
Usuario::Usuario(string nombre,string apellido, string paisdeorigen,string email, string contrasenia) {
	// TODO Auto-generated constructor stub
	this->nombre= nombre;
	this->apellido = apellido;
	this->paisDeOrigen=paisdeorigen;
	this->email = email;
	this->contrasenia = contrasenia;
	this->id= Usuario::autoincremental1++;
	this->cantRespuestasAceptadas=0;
}
Usuario::Usuario(Usuario &Aux){
	this->nombre= Aux.nombre;
	this->apellido = Aux.apellido;
	this->paisDeOrigen=Aux.paisDeOrigen;
	this->email = Aux.email;
	this->contrasenia = Aux.contrasenia;
	this->id= Aux.id;
	this->cantRespuestasAceptadas=0;
}
void Usuario::ListarInformacion(){
	cout<<"----------"<<endl;;
	cout<<"idUsuario: "<<this->id<<endl;
	cout<<"Nombre del usuario: "<<this->getNombre()<<endl;
	cout<<"Apellido del usuario: "<<this->getApellido()<<endl;
	cout<<"pais de origen: "<<this->getPaisdeOrigen()<<endl;
	cout<<"email: "<<this->getEmail()<<endl;
	cout<<"contraseña: "<<this->getcontrasenia()<<endl;

}
void Usuario::ListarInformacionDos(){
	cout<<"----------"<<endl;;
		cout<<"idUsuario: "<<this->id<<endl;
		cout<<"Nombre del usuario: "<<this->getNombre()<<endl;
}
void Usuario::SetCantidadRespAceptadas(){
		this->cantRespuestasAceptadas=this->cantRespuestasAceptadas++;
}
int Usuario::getId(){
	return this->id;
}
string Usuario::getPaisdeOrigen(){
	return this->paisDeOrigen;
}
string Usuario::getApellido(){
	return this->apellido;
}
string Usuario::getNombre(){
	return this->nombre;
}
string Usuario::getEmail(){
	return this->email;
}
string Usuario::getcontrasenia(){
	return this->contrasenia;
}
int Usuario::getCantidadRespAceptadas(){
	return this->cantRespuestasAceptadas;
}
Usuario::~Usuario() {
	// TODO Auto-generated destructor stub
}

