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

using namespace std;

class Pregunta {
private :
		static int autoincremental3;
		int idpregunta;
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
	void AgregarRespuesta();
	void ListarInformacion();
	virtual ~Pregunta();
};

#endif /* PREGUNTA_H_ */