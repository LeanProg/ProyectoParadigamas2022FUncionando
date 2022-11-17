/*
 * Sistema.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */
#include <iostream>
#include "Sistema.h"
#include <vector>
using namespace std;

Sistema::Sistema() {

}
/*Metodo para crear Usuario 16-11-20222*/
bool Sistema::crearUsuario(string nombre,string apellido,string paisorigen,string email,string contrasenia){
	Usuario *nuevoUsu = new Usuario(nombre,apellido,paisorigen,email,contrasenia);
	contedorUsuarios.insert(contedorUsuarios.end(),nuevoUsu);
}
void Sistema::ListarUsuarios(){
	for (int var = 0; var<contedorUsuarios.size() ; ++var) {
		contedorUsuarios[var]->ListarInformacion();
	}
}
Usuario *Sistema::buscarUsuario(int id){

	for (int var = 0; var<contedorUsuarios.size() ; ++var) {
			if(id==contedorUsuarios[var]->getId()){
				return (contedorUsuarios[var]);

			}

		}

}
/*Metodo para crear Pregunta 16-11-20222*/
bool Sistema::crearPregunta(Fecha f1){
	this->ListarUsuarios();
	int idbuscado;
	cout<<"Cual usuario desea hacer la pregunta? marque su ID"<<endl;
	cin>>idbuscado;
	Usuario *nuevoU(buscarUsuario(idbuscado));
	Pregunta *np = new Pregunta("Por que tanto calor?","Dia caluroso",f1,*nuevoU);
	contenedorP.insert(contenedorP.end(),np);
}
/*Metodo para crear Respuesta 16-11-20222*/
bool Sistema::crearRespuesta(Fecha f1){

	ListarPreguntas();
}
void Sistema::ListarPreguntas(){
	for (int var = 0; var<contenedorP.size() ; ++var) {
			contenedorP[var]->ListarInformacion();
		}
}

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

