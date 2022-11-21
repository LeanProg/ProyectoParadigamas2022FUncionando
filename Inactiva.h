/*
 * Inactiva.h
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#ifndef INACTIVA_H_
#define INACTIVA_H_
#include <iostream>
#include "Estado.h"
using namespace std;

class Inactiva : public Estado {
public:
	Inactiva();
	void EncargarseDe1() override;
	void EncargarseDe2() override;
	virtual ~Inactiva();
};

#endif /* INACTIVA_H_ */
