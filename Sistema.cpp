/*
 * Sistema.cpp
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */
#include <iostream>
#include "Sistema.h"
#include "Inactiva.h"
#include "Activo.h"
#include "Suspendido.h"
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

Sistema::Sistema() {

}
/*Metodo para crear Usuario 16-11-20222*/
bool Sistema::crearUsuario(string nombre,string apellido,string paisorigen,string email,string contrasenia){
	Usuario *nuevoUsu = new Usuario(nombre,apellido,paisorigen,email,contrasenia);
	contedorUsuarios.insert(contedorUsuarios.end(),nuevoUsu);
	return true;
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
	return true;
}
/*Metodo para crear Respuesta 16-11-20222*/
bool Sistema::crearRespuesta(Fecha f1){
	int idUsuario,idPregunta;
	cout<<"------------------------------------"<<endl;
	cout<<"-----------------------------o-------------"<<endl;
	cout<<"Que usuario Desea Realizar la Respuesta?"<<endl;
	cin>>idUsuario;
	Usuario *nuevoU(buscarUsuario(idUsuario));
	ListarPreguntas();
	cout<<"------------------------------------"<<endl;
	cout<<"Ingrese el id de la Pregunta a la que quiere agragar una respuesta"<<endl;
	cin>>idPregunta;
	for (int var = 0; var < contenedorP.size(); ++var) {
		if (contenedorP[var]->getid()==idPregunta) {
			contenedorP[var]->AgregarRespuestaSegunEstado(f1, *nuevoU);
		}
	}
return true;
}

void Sistema::ListarPreguntas(){
	for (int var = 0; var<contenedorP.size() ; ++var) {
			contenedorP[var]->ListarInformacion();
		}
}
void Sistema::ListarPreguntasConRespuestas(){
		for (int var = 0; var<contenedorP.size() ; ++var) {
				contenedorP[var]->ListarInformaciondos();
			}
}
void Sistema::ListarRespuestas(){
	for (int var = 0; var < contenedorP.size(); ++var) {
		cout<<"---//**//--Respuestas de la pregunta: "<<var<<endl;
		contenedorP[var]->ListarRespuestas();
	}
}

void Sistema::RankearRespuesta(){
	int idPregunta;
	this->ListarPreguntas();
	cout<<"De cual pregunta desea rankear las respuestas?"<<endl;
	cin>>idPregunta;
	cout<<"A continuacion se lista la respuesta con MasMegusta"<<endl;
	contenedorP[idPregunta]->OrdenarPorMegusta();
}

void Sistema::DarMegusta(){
	    int preguntaid,respuestaId;
		this->ListarPreguntas();
		cout<<"--Seleccione la pregunta la cual desea ver las Respuestas---"<<endl;
		cin>>preguntaid;
		contenedorP[preguntaid]->ListarRespuestas();
		cout<<"Cual Respuesta desea dar Me gusta"<<endl;
		cin>>respuestaId;
		contenedorP[preguntaid]->DarMegustaRespuesta(respuestaId);

}
void Sistema::controlarEstado(){
	for (int var = 0; var < contenedorP.size(); ++var) {
		contenedorP[var]->ListarInformacion();
	}
}
bool Sistema::controlFecha(){
	Fecha f;
	for (int var = 0; var < contenedorP.size(); ++var) {
			if ((f-contenedorP[var]->fechaUltimaRespuesta)>185) {
				cout<<"Cambio a inactiva"<<endl;
				contenedorP[var]->TransitionTo(new Inactiva(contenedorP[var]));
			}

	}
}
/*
void Sistema::CambiarEstado(){
	contenedorP[0]->Solicitud1();
}*/
/*
void Sistema::CambiarEstadodos(){
	contenedorP[0]->Solicitud2();
}
*/
/*Metodos para Estado*/
/*
void Sistema::AgregarRespuestaEstado(Fecha f1){
	contenedorP[0]->AgregarRespuestaSegunEstado(f1, *contedorUsuarios[0]);
}*/

void Sistema::ListarPreguntasPorTag(){
	string tag;
	cout<<"Ingrese el tag para mostrar las preguntas relacionadas"<<endl;
	cin>>tag;
	for (int var = 0; var < this->contenedorP.size(); ++var) {
		for (int var2 = 0; var2 < 3; ++var2) {
			if (contenedorP[var]->DevolverTag(var2).compare(tag)==0) {
						contenedorP[var]->ListarInformacion();
					}
		}

	}

}

void Sistema::MarcarRespuestasComoAceptada(){
	int idUsuario,idPregunta,idRespuesta;
		cout<<"------------------------------------"<<endl;
		cout<<"-----------------------------o-------------"<<endl;

		this->ListarUsuarios();
		cout<<"Que usuario desea Listar sus preguntas? "<<endl;
		cin>>idUsuario;
		for (int var2 = 0; var2 < contenedorP.size(); ++var2) {
			if(idUsuario == contenedorP[var2]->getIdUsuario()){
				contenedorP[var2]->ListarInformacion();
			}
		}

		cout<<"------------------------------------"<<endl;
		cout<<"Ingrese el id de la Pregunta a la que quiere Mostrar las respuestas"<<endl;
		cin>>idPregunta;
		contenedorP[idPregunta]->ListarRespuestas();

		cout<<"Que respuesta desea marcar como aceptada para esta Pregunta?"<<endl;
		cin>>idRespuesta;
		contenedorP[idPregunta]->MarcarComoAceptada(idRespuesta);

}

void Sistema::EliminarUsuario(int idUsuario){
	  vector<Usuario*>::iterator it;
	            for (it=contedorUsuarios.begin(); it!=contedorUsuarios.end(); ++it){
	                delete (*it); //Llama al detructor de controles y libera la memoria
	            }
	            contedorUsuarios.clear();
	    for(size_t i; i<contedorUsuarios.size();i++){

	    	if(idUsuario ==  contedorUsuarios[i]->getId()){
	    		for (int var2 = 0; var2 < contenedorP.size(); ++var2) {
	    			    if(idUsuario == contenedorP[var2]->getIdUsuario()){
	    			    	contenedorP[var2]->TransitionTo(new Suspendido(contenedorP[var2]));
	    			    	}
	    			   }
	    		 contedorUsuarios.erase(contedorUsuarios.begin()+i);
	    	}

	    }

}

Sistema::~Sistema() {
	vector<Usuario*>::iterator it;
	                for (it=contedorUsuarios.begin(); it!=contedorUsuarios.end(); ++it){
	                    delete (*it); //Llama al detructor de controles y libera la memoria
	                }
	                contedorUsuarios.clear();
   vector<Pregunta*>::iterator it2;
	            for (it2=contenedorP.begin(); it2!=contenedorP.end(); ++it2){
	                delete (*it2); //Llama al detructor de controles y libera la memoria
	                }
	            contenedorP.clear();
}

