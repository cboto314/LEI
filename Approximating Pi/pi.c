#include <stdio.h>



int in_esfera(double x, double y, double z, double r_esfera){

	double dist = (x-r_esfera)*(x-r_esfera) + (y-r_esfera)*(y-r_esfera) + (z-r_esfera)*(z-r_esfera);

	return 	dist <= (r_esfera)*(r_esfera) ? 1 : 0;

}


double get_pi(double l_cubo){

	double r_esfera = l_cubo/2;

	double total = 0;
	double esfera = 0;

	double delta = 1E-1;

	
	for(double x = 0; x < l_cubo; x+=delta){
		for(double y = 0; y <l_cubo; y+=delta){
			for(double z = 0; z < l_cubo; z+=delta){
				total+=delta;
				if(in_esfera(x,y,z,r_esfera))
					esfera+=delta;
			}
		}
	}


// Explanation for this part https://stackoverflow.com/a/61146240/13280525

	esfera*=delta*delta;
	total*=delta*delta;

//

	return (esfera)/(total)*6;
}


void teste_pi(){
	
	double l_cubo = 4;

	double pi = get_pi(l_cubo);

	printf("%.8f\n",pi);


}


int main(){

	teste_pi();
}
