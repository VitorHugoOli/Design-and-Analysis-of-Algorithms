//
// Created by vho20 on 28/11/2018.
//

#ifndef SHIFAND_CASAMENTO_SHIF_H
#define SHIFAND_CASAMENTO_SHIF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

#define MAXTAMTEXTO 100000
#define MAXTAMPADRAO 10
#define MAxCHAR 256
#define NUMMAXERROS 10
typedef char TipoTexto[MAXTAMTEXTO];//n
typedef char TipoPadrao[MAXTAMPADRAO];//m

void lerarq(TipoTexto T);
void Busca(TipoPadrao P,TipoTexto T,int debug);
void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, int debug);
void Main(int debug);


#endif //SHIFAND_CASAMENTO_SHIF_H
