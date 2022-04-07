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
		// La méthode lire retourne le frame à lire 
		// et enlève l’élément de la structure de données pour faire
		// de la place
		Frame lire();
		bool estVide();
		bool estPlein();
	};
}

#endif


