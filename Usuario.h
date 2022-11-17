/*
 * Usuario.h
 *
 *  Created on: Nov 16, 2022
 *      Author: Leandro
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include  <iostream>
using namespace std;


class Usuario {
private:
		int id;
		string nombre;
		string apellido;
		string paisDeOrigen;
		string email;
		string contrasenia;
		int cantRespuestasAceptadas;
		static int autoincremental1;

public:
	Usuario();
	Usuario(string nombre,string apellido, string paisdeorigen,string email, string contrasenia);
	Usuario(Usuario & Aux);
	string getNombre();
	string getApellido();
	string getEmail();
	string getcontrasenia();
	string getPaisdeOrigen();
	int getId();
	int getCantidadRespAceptadas();
	void SetCantidadRespAceptadas();
	void ListarInformacion();
	void ListarInformacionDos();
	virtual ~Usuario();
};

#endif /* USUARIO_H_ */
