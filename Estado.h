/*
 * Estado.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#ifndef ESTADO_H_
#define ESTADO_H_
#include <iostream>

using namespace std;

class Pregunta;

class Estado {
protected:
	Pregunta *pregunta_;
public:
	Estado();
	void set_Pregunta(Pregunta *pregunta);
	/*Funciones Virtuales*/
	virtual void EncargarseDe1()= 0;
	virtual void EncargarseDe2()= 0;
	virtual ~Estado();
};

#endif /* ESTADO_H_ */
