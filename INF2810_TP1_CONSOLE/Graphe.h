#pragma once
#include <vector>
#include "Sommet.h"
#include "Vehicule.h"

class Graphe
{
public:
	Graphe();
	~Graphe();

	void ajouterSommet(Sommet* sommet);
	void ajouterArc(Arc* arc);

	void Afficher();
	Sommet* GetSommetById(int sommetId);
	void setVehicule(Vehicule* vehicule);
	Vehicule* getVehicule() const;
	std::vector<Sommet*> GetSommets();

private:
	std::vector<Sommet*> sommets;
	std::vector<Arc*> arcs;
	Vehicule* vehicule;

};

