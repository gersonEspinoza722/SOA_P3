// Documentacion:
// floyd(); inicializa la matriz, no recibe parametros.
// floyd_path(); retorna una lista con la ruta de i a j.
// NOTAS:
// floyd hay que llamarlo anted de floyd path al menos una vez.
// floyd es idempotente, no importa si se llama varias veces
// HAY QUE HACER FREE DE LA LISTA RETORNADA POR FLOYD PATH!!!

#ifndef PROYECTO3_FLOYD_H
#define PROYECTO3_FLOYD_H

void floyd();
void generate_file();
int *floyd_path(int i, int j);

#endif //PROYECTO3_FLOYD_H