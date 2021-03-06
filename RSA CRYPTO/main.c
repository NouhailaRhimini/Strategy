// Cryptocraphie avec RSA :
#include <stdio.h>
#include <stdlib.h>
#include<math.h> 
#include <time.h> 

unsigned long long int Secondaire(unsigned long long int t,unsigned long long int k,unsigned long long  int* q,unsigned long long int* p)//on utilise long long car les nbres peuvent etre très grands
{//on utilise des pointeurs pour pour agir sur la valeur de la variable on mémoire
	if (t == 1)
		*q = (*q * (*p)) % k;

	*p = (*p) * (*p) % k; 
}

unsigned long long int EXP_RAPIDE(unsigned long long int x,unsigned long long int y, unsigned long long int mod)
{
    unsigned long long int var,resultat = 1;//la variable resultat ou on stocke le calcul
    

	while (y > 0)//tant que l'expossant est strictement possitif on refait le calcul
	{
		var = y % 2;  //var est une variable locale temporaire
		Secondaire(var, mod, &resultat, &x);//Appel de la fct précedamant définie
		y = y / 2;
	}

	return resultat;
}
// une fonction qui retourne le nombre de bits d'un nombre 
unsigned countBits(unsigned long long  int number) 
{        
      return (unsigned int)log2(number)+1; 
}
// Dans ce code on utilise la fonction indicatrice carmichael au lieu de la fonction indicatrice d'euler , c'est pourquoi on va 
// utiliser une fonction qui calcule le PPCM de deux entiers :

unsigned long long int lcm(unsigned long long int n1,unsigned long long int n2){
    unsigned long long int min;
  min = (n1 > n2) ? n1 : n2;

    while (1) {
        if (min % n1 == 0 && min % n2 == 0) {
            break;
        }
        ++min;
    }
  return min;

}

//fonction qui detecte si un nbre est premier ou pas
  unsigned int premier (unsigned int n){
  	unsigned long long int count=1;
        int i;
        if(n<=1) count=0;
  	for(i=2;i<n;i++) {
        if(n%i==0)
        {
         count = 0;
         break;
         }}
         return count;
  }
  
  // fonction qui trouve  l'inverse modulaire d'un entier a pour la multiplication modulo m , dans ce code on va utiliser cette fonction 
  //pour e et phi qui sont premier entre eux d'où l'existence de x :
  unsigned long long int modInverse(unsigned int a,unsigned long long int m) 
{ 
    a = a%m; 
    unsigned long long int x;
    for (x=1; x<m; x++) { 
       if ((a*x) % m == 1) 
          return x; }
} 
  //fonction dui retourne le pgdc de deux nombres a et b :
  unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
      if(b == 0)
          return a;
      return gcd(b,a%b);
  
  }
    //imaginons que Alice et Bob voulaient communiquer de façon sécurisé un message secret(chiffré), Alice doit choisir 
  //une clé public pour chifrer son message et bob doit génerer une clé privé pour déchifrer se message
  int main(){
  unsigned long long int p,q,d, n,phi, x,msg, y;  //definition des variables
  unsigned int e,bitsn,bitsm;
  //Alice  doit choisir deux grand nombres premiers p et q
  printf("Entrer les valeurs choisis de p et q : "); 
  scanf("%llu,%llu",&p,&q);  
  
  //p et q doivent etre des nombres premiers , les deux nombres ne doivent pas depasser le nombre 34679 et ils peuvent pas etre égaux
  while(!premier(p)){		 
  printf("le nombre p doit etre un nombre premier , RESAISIR: \n");
  scanf("%llu",&p);
  }
  while(!premier(q)){		 
  printf("le nombre q doit etre un nombre premier , RESAISIR: \n");
  scanf("%llu",&q);
  }
  while (p==q ) {
      
  printf("les deux nombres be peuvent as etre égaux ,RESAISIR :\n "); 
  scanf("%llu,%llu",&p,&q);
  }
  while(p>34680){		 
  printf("le nombre p ne doit pas dépasser 34679 , RESAISIR: \n");
  scanf("%llu",&p);
  }
  while(q>34680){		 
  printf("le nombre q ne doit pas dépasser 34679 , RESAISIR: \n");
  scanf("%llu",&q);
  }
  //les valeurs que vous avez choisi
  printf("The value of p : %llu\n", p);  
  printf("The value of q : %llu\n\n", q);
  //la clé publique (n,e)
  n = p*q;
  bitsn=countBits(n);
  printf("nombres de bits de n  %u\n.", bitsn);
  phi=lcm((p-1),(q-1));
  e=2;
        while (e<phi)
          {
            if (gcd(e,phi)==1)
                break;
            else
                e++;
          
          }
  //la clé privé (n,d) d doit satisfaire d*e=1 mod phi :
  
  d = modInverse(e,phi);
  // Le nombres de bits du message a sésir de doint pas depasser le nombresde bits de n  
  do {printf("Entrer votre message (le message doit etre sous forme numérique)(le nombre de bits du message ne doit pas dépasser le nombres de bits de n  ) : "); 
  scanf("%llu",&msg);
  bitsm=countBits(msg);}
  while (bitsm >= bitsn);
  printf("nombres de bits de msg  %u  ", bitsm);
  //x peut donc se calculer par la fonction d'exponentiation et la clé publique
  x = EXP_RAPIDE(msg,(unsigned int) e, n); 
  printf("Le message crypté est: %llu\n", x);        
  // Bob peut décrypter son msg par sa clé privée
  y = EXP_RAPIDE(x,d, n); 
  printf("Le message décrypté est: %llu\n", y);   
  
  }
