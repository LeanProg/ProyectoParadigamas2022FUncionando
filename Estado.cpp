/*
 * Estado.cpp
 *
 *  Created on: Nov 20, 2022
 *      Author: Leandro
 */

#include "Estado.h"
Estado::Estado(Pregunta *pregunta):pregunta_(pregunta){
}

void Estado::set_Pregunta(Pregunta *pregunta){;
	this->pregunta_=pregunta;
}


Estado::~Estado() {

}

