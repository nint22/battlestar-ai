#ifndef GENE_H
#define GENE_H

#include <cstdio>
#include <cstring>
#include "globals.h"
#include "harmonic.h"
#include "fourier.h"

#define MAX_OF_SCALED_SIN_PLUS_COS 1//0.235586 //computed earlier
#define MUTATION_RATE 0.5

class Gene
{
	double magnitude;
	Harmonic waves[WAVECOUNT];

public:
	Gene() //makes random gene
	{
		for(int i = 0; i < WAVECOUNT; i++)
			waves[i] = Harmonic(MAX_OF_SCALED_SIN_PLUS_COS);
	}

	Gene(double magnitude) //makes random gene
	{
		this->magnitude = magnitude;
		for(int i = 0; i < WAVECOUNT; i++)
			waves[i] = Harmonic(MAX_OF_SCALED_SIN_PLUS_COS);
	}

	Gene(Harmonic* waves) //gene with premade harmonics
	{
		memcpy(this->waves, waves, sizeof(Harmonic) * WAVECOUNT);
	}

	Gene(double magnitude, Harmonic* waves) //gene with premade harmonics
	{
		this->magnitude = magnitude;
		memcpy(this->waves, waves, sizeof(Harmonic) * WAVECOUNT);
	}

	double* getDist();
	double fitness(double* dist);
	char* toString();

	static Gene cross(Gene* father, Gene* mother, bool mutate);
}; 

#endif