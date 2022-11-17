//============================================================================
// Name        : GestionDelConocimiento.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
/*
#include "Usuario.h"
#include "Pregunta.h"*/
#include "Respuesta.h"
#include "Sistema.h"
#include "Fecha.h"
using namespace std;

int main() {

	Fecha f;
	/*Usuario usuarionuevo("leandro","ortega","Argentina","email@email.com","12345f");
	Usuario usuarionuevodos("leandro2","ortega2","Argentina2","email@email2.com","12345f2");
	Pregunta P1("Por que tanto calor?","Dia caluroso",f,usuarionuevo);*/
	//Respuesta R1("Si porque hace calor",f,usuarionuevodos);
	Sistema SistemaPrincipal;
	//Mostrar

	SistemaPrincipal.crearUsuario("leandro","ortega","Argentina","email@email.com","12345f");
	SistemaPrincipal.crearUsuario("leandro2","ortega2","Argentina2","email@email2.com","12345f2");
	//SistemaPrincipal.ListarUsuarios();

	SistemaPrincipal.crearPregunta(f);
	SistemaPrincipal.crearPregunta(f);
	SistemaPrincipal.ListarPreguntas();
	SistemaPrincipal.crearRespuesta(f);
	//P1.ListarInformacion();
	cout<<"----------"<<endl;
	cout<<"----------"<<endl;
	SistemaPrincipal.ListarRespuestas();
	//R1.ListarInformacion();

	return 0;
}
