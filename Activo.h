/*
 * Activo.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#ifndef ACTIVO_H_
#define ACTIVO_H_
#include <iostream>
#include "Estado.h"
using namespace std;

class Activo : public Estado {
public:
	Activo(Pregunta *pregunta);
	virtual void EncargarseDe1() override;
	virtual void EncargarseDe2() override;
	virtual void AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1) override;
	virtual ~Activo();
};

#endif /* ACTIVO_H_ */
