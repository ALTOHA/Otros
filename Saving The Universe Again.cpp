#include <bits/stdc++.h>

using namespace std;

int main(){
	int casos, escudo, ataque, hackeos, i, dano, cont = 0, ata2;
	char control[100000];
	bool impo;
	scanf("%d", &casos);
	
	while(casos--){
		dano = 1, hackeos = ataque = 0;
		cont++;
		impo = false;
		
		scanf("%d %s", &escudo, control);
		
		for(i=0; i<strlen(control); i++){
			if(control[i] == 'C')
				dano*=2;
				
			else if(control[i] == 'S')
				ataque+=dano;	
		}
		ata2 = ataque;
		
		while(ataque > escudo){
			dano = 1;
			ataque = 0;
			
			for(i=strlen(control)-1; i>=0; i--){
				if(control[i] == 'S' && control[i-1] == 'C'){
					control[i-1] = 'S';
					control[i] = 'C';
					break;
				}
			}
			for(i=0; i<strlen(control); i++){
				if(control[i] == 'C')
					dano*=2;
					
				else if(control[i] == 'S')
					ataque+=dano;					
			}		
			
			if(ata2 != ataque)
				hackeos++;
				
			else{
				impo = true;
				break;
			}
			ata2 = ataque;
		}
		
		(impo == false) ? printf("Case #%d: %d\n", cont, hackeos) : printf("Case #%d: IMPOSSIBLE\n", cont);
	}
	
	
	return 0;
}
