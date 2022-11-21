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
	Activo();
	void EncargarseDe1() override;
	void EncargarseDe2() override;
	virtual ~Activo();
};

#endif /* ACTIVO_H_ */
