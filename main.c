//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//   
// ██████╗██╗   ██╗ ██████╗██████╗ ██╗   ██╗███████╗██╗  ██╗//
//██╔════╝╚██╗ ██╔╝██╔════╝██╔══██╗██║   ██║██╔════╝██║  ██║//
//██║      ╚████╔╝ ██║     ██████╔╝██║   ██║███████╗███████║//
//██║       ╚██╔╝  ██║     ██╔══██╗██║   ██║╚════██║██╔══██║//
//╚██████╗   ██║   ╚██████╗██║  ██║╚██████╔╝███████║██║  ██║//
// ╚═════╝   ╚═╝    ╚═════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝//
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//
                                                    
#include "fonctions.h"

int main(){
	srand(time(NULL));
	Dimensions dim;
	dim.d1=9;
	dim.d2=6;
	dim.nb_s=4;
	int **plat;
	CYcrush(plat, dim);
	return 0;
}
