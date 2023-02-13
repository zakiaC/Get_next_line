#include <stdio.h>

int main() {
  const char * filename = "file_dscriptor.txt";
  int x = 7;

  FILE * fd = fopen(filename, "w");
  if (fd) { // succès
    // utilisation du fichier
    fprintf(fd, "coucou %d\n", x);
    fclose(fd);
  } else { // échec
    fprintf(stderr, "Can't read %s\n", filename);
  }

  return 0;
}
