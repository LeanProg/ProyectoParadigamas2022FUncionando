/*
 * Respuesta.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#ifndef RESPUESTA_H_
#define RESPUESTA_H_
#include  <iostream>
#include "Fecha.h"
#include "Usuario.h"
using namespace std;

class Respuesta {
private:
	int idrespuesta;
	string descripcion;
	Fecha fechaRespuesta;
	bool aceptada;
	int contadorMegusta;
	Usuario usuarioR;
	static int autoincremental2;
public:
	Respuesta();
	Respuesta(string descrip,Fecha &fecha,Usuario &usu);
	int getIdRespuesta();
	void IncrementarContador();
	void ListarInformacion();
	void MarcarComoAceptada();
	int getCantidadMegusta();
	virtual ~Respuesta();

};

#endif /* RESPUESTA_H_ */
