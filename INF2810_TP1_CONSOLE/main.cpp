#include <iostream>
#include <string>
#include <fstream>
#include "Sommet.h";
#include "Graphe.h"
#include "Arc.h"
#define OUT;

int separerLigne(std::string& ligne, std::string delimiter=",", std::vector<int>& )
{
	size_t pos = ligne.find(',');
	int element = std::stoi(ligne.substr(0, pos));

}



void split3(const std::string& str, vector<string>& cont,
	char delim = ' ')
{
	std::size_t current, previous = 0;
	current = str.find(delim);
	while (current != std::string::npos) {
		cont.push_back(str.substr(previous, current - previous));
		previous = current + 1;
		current = str.find(delim, previous);
	}
	cont.push_back(str.substr(previous, current - previous));
}

int main(int* argc, char* argv[]) {
	std::ifstream fichier;
	Graphe* graphePrincipal = new Graphe();
	enum VehiculeTypePosition{NIOH,MIOH};
	enum VehiculeCategoriePosition { NIOH, MIOH };
	char nomFichier[80];

	do {
		std::cout << "entrer le nom du fichier svp:\n";
		std::cin >> nomFichier;
		fichier.open(nomFichier);
	} while (fichier.fail());
	
	std::string ligne = "";
	bool premierTraitement = true;

	do {
		std::getline(fichier, ligne);
		size_t pos = 0;
		if (!ligne.empty()) {
			if (premierTraitement) {
				Sommet* nouveauSommet = new Sommet();
				pos = ligne.find(',');
				nouveauSommet->setId(std::stoi(ligne.substr(0, pos)));
				nouveauSommet->setType(std::stoi(ligne.substr(pos+1)));
				graphePrincipal->ajouterSommet(nouveauSommet);
			}else
			{
				Arc* nouvelArc = new Arc();
				pos = ligne.find(',');
				nouvelArc->ajouterSommetId(std::stoi(ligne.substr(0, pos)));
				nouvelArc->setType(std::stoi(ligne.substr(pos)));
				
			}
		}else
		{
			premierTraitement = false;
		}
	} while (ligne != '');


	int pause = 0;
	std::cin >> pause;
	return 0;
}
