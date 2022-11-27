/*
 * Suspendido.h
 *
 *  Created on: Nov 23, 2022
 *      Author: Leandro
 */

#ifndef SUSPENDIDO_H_
#define SUSPENDIDO_H_
#include "Estado.h"

class Suspendido:public Estado {
public:
	Suspendido(Pregunta *pregunta);
	virtual void EncargarseDe1() override;
	virtual void EncargarseDe2() override;
	virtual void AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1) override;
	virtual ~Suspendido();
};

#endif /* SUSPENDIDO_H_ */
