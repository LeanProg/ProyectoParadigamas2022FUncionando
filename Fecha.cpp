/*
 * Fecha.cpp
 */

#include "Fecha.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

Fecha::Fecha() {
	setFechaActual();
}
Fecha::Fecha(short int d, short int m, short int a) {
	setFecha(d, m, a);
}
Fecha::Fecha(const Fecha &f) :
	dia(f.dia), mes(f.mes), anio(f.anio) {
}

void Fecha::setFechaActual(void) {
	struct tm *ptr;
	time_t sec;

	time(&sec);
	ptr = localtime(&sec);
	dia = (short) ptr->tm_mday;
	mes = (short) ptr->tm_mon + 1;
	anio = (short) ptr->tm_year + 1900;
}

void Fecha::setFecha(const short d, const short m, const short a) {
	dia = d;
	mes = m;
	anio = a;
	if(!esAnioValido() || !esMesValido() || !esDiaValido()){
		setFechaActual();
	}
}

bool Fecha::esAnioValido() const {
	return (anio > 0);
}
bool Fecha::esMesValido() const {
	return (mes >= 1 && mes <= 12);
}
bool Fecha::esDiaValido() const {
	return (dia >= 1 && dia <= diasEnMes(mes));
}

short Fecha::diasEnMes(const short m) const{
	short cantidadDias = 0;
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cantidadDias = 31;
			break;
		case 2:
			if (esAnioBisiesto()) {
				cantidadDias = 29;
			} else {
				cantidadDias = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			cantidadDias = 30;
			break;
	}
	return cantidadDias;
}


bool Fecha::esAnioBisiesto() const {
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}

short Fecha::getDia() const {
	return dia;
}
short Fecha::getMes() const {
	return mes;
}
short Fecha::getAnio() const {
	return anio;
}

long int Fecha::cantidadDiasDelAnio(){
	long int cantidadDias = 0;
	int febrero=28 + esAnioBisiesto();
		switch (mes) {
			case 1:cantidadDias=dia;break;
			case 2:cantidadDias=31+dia;break;
			case 3:cantidadDias=31+febrero+dia;break;
			case 4:cantidadDias=31+febrero+31+dia;break;
			case 5:cantidadDias=31+febrero+31+30+dia;break;
			case 6:cantidadDias=31+febrero+31+30+31+dia;break;
			case 7:cantidadDias=31+febrero+31+30+31+30+dia;break;
			case 8:cantidadDias=31+febrero+31+30+31+30+31+dia;break;
			case 9:cantidadDias=31+febrero+31+30+31+30+31+31+dia;break;
			case 10:cantidadDias=31+febrero+31+30+31+30+31+31+30+dia;break;
			case 11:cantidadDias=31+febrero+31+30+31+30+31+31+30+31+dia;break;
			case 12:cantidadDias=31+febrero+31+30+31+30+31+31+30+31+30+dia;break;
		}
		return cantidadDias;
}

bool esAnioBisiesto(int anio){
	return ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0);
}
long int cantidadDiasAniosCompletos(int anioBase, int anio){

	long int dias=0;
	if(anioBase<anio){
		for(int i=anioBase;i<anio;i++){
			if(esAnioBisiesto(i))
				dias+=366;
			else
				dias+=365;
		}
	}
	return dias;
}

bool operator>=(Fecha fecha1, Fecha fecha2){
	return ((fecha1.anio>fecha2.anio) || (fecha1.anio==fecha2.anio && (fecha1.mes>fecha2.mes || (fecha1.mes==fecha2.mes && fecha1.dia>=fecha2.dia))) );
}

long int operator-(Fecha &fecha1, Fecha &fecha2){
	long int dif=0;
	if(fecha1>=fecha2){
		long int diasAnios = cantidadDiasAniosCompletos(fecha2.getAnio(), fecha1.getAnio());
		long int dias2=fecha2.cantidadDiasDelAnio();
		long int dias1 =fecha1.cantidadDiasDelAnio() + diasAnios;
		dif=dias1-dias2;
	}
	return dif;
}

ostream& operator<<(ostream &salida,const Fecha &f) {
	salida.fill('0');
	salida << setw(2) << f.getDia() << "/" << setw(2) << f.getMes() << "/" << setw(4)
			<< f.getAnio();
	return salida;
}
