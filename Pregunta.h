/*
 * Pregunta.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#ifndef PREGUNTA_H_
#define PREGUNTA_H_
#include  <iostream>
#include "Fecha.h"
#include "Usuario.h"
#include "Respuesta.h"

#include <vector>

class Estado;

using namespace std;

class Pregunta {
private :
		static int autoincremental3;
		int idpregunta;
		Estado *estado_;
		string descripcion;
		string titulo;
		Usuario usuarioP;
		Fecha fechaPregunta;
		vector<Respuesta*> contenedorRespuesta;
		string tags[3];
public:
	Fecha fechaUltimaRespuesta;
	Pregunta();
	Pregunta(string descripcion,string titulo,Fecha &Fp,Usuario &Usu);
	Pregunta(Pregunta &aux);
	int getid();
	//void AgregarRespuesta(Fecha f1,Usuario);
	void InsertarRespuesta(Respuesta *);
	void ListarRespuestas();
	void ListarInformacion();
	void ListarInformaciondos();
	void OrdenarPorMegusta();
	void DarMegustaRespuesta(int);
	virtual ~Pregunta();

	/*Funcion para Cambiar de estados de la pregunta*/
	void TransitionTo(Estado *estado);
	/*Delego funciones al estado*/
	void Solicitud1();
	void Solicitud2();

	/*Void Agregar Respuesta */
	void AgregarRespuestaSegunEstado(Fecha f1,Usuario);
};

#endif /* PREGUNTA_H_ */
