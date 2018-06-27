#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H

// Separa un archivo de subtitulos srt en varios dependiendo del paso
void srt_split(std::string archivo_srt,const double &paso);

// Conversion del tiempo en ms al formato hh:mm:ss,sss del .srt
std::string ms2hms(const double &tiempo_ms);

// Pasa el tiempo en formato hh:mm:ss,sss a milisegundos
double hms2ms(int horas,int minutos,int segundos,int milisegundos);

#endif
