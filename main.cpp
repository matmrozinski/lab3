// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// S³ownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;

	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieœæ S³owian w losowej kolejnoœci w wektorze.
    srand(time(NULL));
	vectorOfSlavs.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int position = rand() % vectorOfSlavs.size();
		vectorOfSlavs.insert(vectorOfSlavs.begin() + position, i);
	}

	// Wykorzystuj¹c iterator i funkcjê description(), wyœwietl wszystkich S³owian w wektorze
vector <Slav *>::iterator i;
	for (i = vectorOfSlavs.begin(); i != vectorOfSlavs.end(); i++)
	{
		cout << (**i).description() << endl;
	}

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieœ wszystkich S³owian z wektoru do zbioru.
	for (int i=0;i<n;i++)
    {
		setOfSlavs.insert(vectorOfSlavs[i]);
	}

	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz s³ownik tworz¹cy pary S³owian, z tych znajduj¹cych siê w zbiorze, czyszcz¹c zbiór

    set<Slav*>::iterator it_set=setOfSlavs.begin();
	set<Slav*>::iterator it=setOfSlavs.end();
	it--;
	int k = 1;
	while(it_set != setOfSlavs.end()   ){

		mapOfSlavs[*it_set]= (*it );

		setOfSlavs.erase(*it_set);
		setOfSlavs.erase(*it);

		it_set = setOfSlavs.begin();
		it = setOfSlavs.begin();

		for(int i=0;i<(n-1-k-k);i++){it++;}

		j++;
		REPORT_CONTAINERS;
	}

	// Wykorzystuj¹c iterator, wyœwietl wszystkie pary S³owian
map <Slav *, Slav *>::iterator i = mapOfSlavs.begin();
	for(i; i != mapOfSlavs.end(); i++)
	{
		cout << *(i).first->desctription() << " " << *(i).second->description() << endl;
	}

	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieœæ S³owian w kolejce.

	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieœ S³owian z kolejki do stosu.

	REPORT_ADAPTERS;

	// Wyœwietl S³owian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
