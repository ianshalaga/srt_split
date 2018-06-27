#include "iostream"
#include "string"
#include "djr_functions.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	string nombre_srt = "snk_Sony AVC-MVC_SNK_1080";
	
	double paso = 61; // en segundos
	paso *= 1000; // paso a milisegundos
	
	srt_split(nombre_srt,paso);

	return 0;
}

