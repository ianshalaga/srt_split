#include "iostream"
#include "string"
#include "djr_functions.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	string nombre_srt = "y_Sony AVC-MVC_Y_480";
	
	double paso = 61; // en segundos
	paso *= 1000; // paso a milisegundos
	
	srt_split(nombre_srt,paso);

	return 0;
}

