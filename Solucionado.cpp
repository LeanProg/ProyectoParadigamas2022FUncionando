/*
 * Solucionado.cpp
 *
 *  Created on: Nov 23, 2022
 *      Author: Leandro
 */

#include "Solucionado.h"

Solucionado::Solucionado(Pregunta *pregunta):Estado(pregunta) {
	// TODO Auto-generated constructor stub

}
void Solucionado::EncargarseDe1(){
	cout<<"Estoy en solucionado metodo Encargarsede1"<<endl;
}
void Solucionado::EncargarseDe2(){
	cout<<"Estoy en solucionado metodo Encargarsede2"<<endl;
}
void Solucionado::AgregarRespuesta(Pregunta *auxPreg,Usuario aux,Fecha f1){
	cout<<"No se puede agregar Respuesta La Pregunta Esta Solucionada"<<endl;
}
Solucionado::~Solucionado() {
	// TODO Auto-generated destructor stub
}

