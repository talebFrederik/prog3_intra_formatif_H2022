#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <algorithm>

namespace intra
{
	struct Frame
	{
		int frameId;
		char data;
	};


	class Buffer
	{
	private:
		int m_capacite;
		int m_size;
		Frame* m_frames;
		void heapify();
		int parent(int);
		int left(int);
		int right(int);
		void swap(Frame&, Frame&);
	public:
		Buffer(int capacite);
		void ajouter(Frame frame);
		// La m�thode lire retourne le frame � lire 
		// et enl�ve l��l�ment de la structure de donn�es pour faire
		// de la place
		Frame lire();
		bool estVide();
		bool estPlein();
	};
}

#endif


