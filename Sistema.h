/*
 * Sistema.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <iostream>
#include<vector>
#include "Usuario.h"
#include "Pregunta.h"
#include "Fecha.h"
using namespace std;


class Sistema {
private:
	vector<Usuario*> contedorUsuarios;
	vector<Pregunta*> contenedorP;
public:
	Sistema();
	bool crearUsuario(string,string,string,string,string);
	bool crearPregunta(Fecha f1);
	bool crearRespuesta(Fecha f1);
	void DarMegusta();
	void RankearRespuesta();
	//void CambiarEstado();
	//void CambiarEstadodos();
	bool controlFecha();
	void controlarEstado();
	void ListarUsuarios();
	void ListarPreguntas();
	void ListarPreguntasConRespuestas();
	void ListarRespuestas();
	void ListarPreguntasPorTag();
	Usuario *buscarUsuario(int id);
	void EliminarUsuario(int);
	void MarcarRespuestasComoAceptada();
	/*Metodos para probar los Estados*/
	//void AgregarRespuestaEstado(Fecha f1);
	virtual ~Sistema();
};

#endif /* SISTEMA_H_ */
