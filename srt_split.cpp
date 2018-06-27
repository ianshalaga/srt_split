#include "iostream"
#include "string"
#include "djr_functions.h"
#include <fstream>
#include <sstream>
#include "iomanip"

using namespace std;

void srt_split(string nombre_archivo,const double &paso) {
	
	stringstream s;
	s << nombre_archivo << ".srt";
	
	ifstream archivo_srt (s.str());
	
//	string id_inicio;
//	archivo_srt >> id_inicio;
	
	string id;
	int horas;
	int minutos;
	int segundos;
	int milisegundos;
	string flechita;
	char separador;
	char coma;
	int cont = 0;
	int cont_srt = 1;
	bool remanente = false;
	string tiempo_remanente;
	string texto_remanente;
	
	while (archivo_srt) {
	
		stringstream s;
		s << nombre_archivo << "[" << cont << "]" << ".srt";
		ofstream parte_srt(s.str());
	
		if (remanente) {
			parte_srt << 1 << '\n' << ms2hms(0) << " --> " << tiempo_remanente << '\n' << texto_remanente << '\n';
		}
		
		remanente = false;
		
		while (archivo_srt >> id) {
			
			archivo_srt >> horas >> separador >> minutos >> separador >> segundos >> coma >> milisegundos;
			double tms1 = hms2ms(horas,minutos,segundos,milisegundos);
			
			archivo_srt >> flechita;
			
			archivo_srt >> horas >> separador >> minutos >> separador >> segundos >> coma >> milisegundos;
			double tms2 = hms2ms(horas,minutos,segundos,milisegundos);
			
			archivo_srt.ignore();
			
			string linea,texto;
			while (getline(archivo_srt,linea)) {
				if (linea.empty())
					break;
				texto += linea + '\n' ;
			}
			
			if (tms1 < cont_srt*paso) {
				parte_srt << id << '\n';
				parte_srt << ms2hms(tms1-cont*paso) << " ";
				parte_srt << flechita << " ";
			} else {
				break;
			}
			
			if (tms2 < cont_srt*paso)
				parte_srt << ms2hms(tms2-cont*paso) << '\n';
			else {
				parte_srt << ms2hms(paso) << '\n';
				tiempo_remanente = ms2hms(tms2-cont_srt*paso);
				texto_remanente = texto;
				remanente = true;
				parte_srt << texto << '\n';
				break;
			}
			
			parte_srt << texto << '\n';
		}
		
		cont_srt++;
		cont++;
		
	}
}
