int lire(char *chaine, int longueur);
long lireLong();
void viderBuffer();
double lireDouble();

int lire(char *chaine, int longueur){
  char *positionEntree = NULL; 

  if (fgets(chaine, longueur, stdin) != NULL){
      positionEntree = strchr(chaine, '\n');
      if (positionEntree != NULL) *positionEntree = '\0';
      else viderBuffer();
      return 1;
  }
  
  else{
      viderBuffer();
      return 0;
  }
}

long lireLong(){
  char nombreTexte[100] = {0}; // 100 cases devraient suffire
  if (lire(nombreTexte, 100)){
      // Si lecture du texte ok, convertir le nombre en long et le retourner
      return strtol(nombreTexte, NULL, 10);
  }
  else{
      // Si problème de lecture, renvoyer 0
      return 0;
  }
}

double lireDouble(){

  char nombreTexte[100] = {0}; // 100 cases devraient suffire

  if (lire(nombreTexte, 100)) return strtod(nombreTexte, NULL);
  else return 0;
  
}

void viderBuffer(){
  int c = 0;
  while (c != '\n' && c != EOF) c = getchar();
}

 
