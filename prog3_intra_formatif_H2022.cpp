#include "Buffer.h"

#include <iostream>

void afficher(intra::Buffer& buffer)
{
	while (!buffer.estVide())
	{
		std::cout << buffer.lire().data;
	}
}

int main()
{
	intra::Frame source[]{ {1, 'A'},{5, 'Y'},{15, ' '},{3, 'L'},{4, ' '},{2, 'L'},{6, 'O'},{25, 'G'},{8, 'R'},{9, ' '},{10, 'B'},{32, '!'},{11, 'A'},{13, 'E'},{14, 'S'},{7, 'U'},{16, 'A'},{30, 'U'},{17, 'R'},{18, 'E'},	{19, ' '},	{20, 'B'},	{24, 'N'},	{29, ' '},	{23, 'O'},{22, 'L'},	{21, 'E'},	{26, ' '},	{27, 'T'},	{28, 'O'},	{12, 'S'},	{31, 'S'},	{33, '\n'} };

	intra::Buffer buffer{ 33 };

	for (int i = 0; i < 33; ++i)
	{
		buffer.ajouter(source[i]);
	}

	afficher(buffer);
}

