/*
 * Solucionado.h
 *
 *  Created on: Nov 23, 2022
 *      Author: Leandro
 */

#ifndef SOLUCIONADO_H_
#define SOLUCIONADO_H_
#include "Estado.h"


class Solucionado: public Estado{
public:
	Solucionado(Pregunta *pregunta);
	virtual void EncargarseDe1() override;
		virtual void EncargarseDe2() override;
		virtual void AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1) override;
	virtual ~Solucionado();
};

#endif /* SOLUCIONADO_H_ */
