/*
 * Estado.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include <iostream>
#include "Fecha.h"
#include "Usuario.h"

class Pregunta;

using namespace std;

class Estado {
protected:
	Pregunta *pregunta_;
public:
	Estado(Pregunta *pregunta);
	void set_Pregunta(Pregunta *pregunta);
	/*Funciones Virtuales*/
	virtual void EncargarseDe1()= 0;
	virtual void EncargarseDe2()= 0;
	virtual void AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1)= 0;

	virtual ~Estado();
};

#endif /* ESTADO_H_ */
