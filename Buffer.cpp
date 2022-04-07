#include "Buffer.h"

void intra::Buffer::heapify()
{
	for (int i = (m_size / 2); i > 0; i--)
	{
		int idxParent{ i - 1 };
		Frame parent{ m_frames[idxParent] };
		bool heap{ false };
		while (!heap && right(idxParent) <= m_size)
		{
			int idxEnfant{ left(idxParent) };
			if (idxEnfant < m_size - 1)
			{
				if (m_frames[idxEnfant].frameId > m_frames[idxEnfant + 1].frameId)
				{
					idxEnfant++;
				}
			}
			if (parent.frameId <= m_frames[idxEnfant].frameId)
			{
				heap = true;
			}
			else
			{
				m_frames[idxParent] = m_frames[idxEnfant];
				idxParent = idxEnfant;
			}
		}
		m_frames[idxParent] = parent;
	}
}

int intra::Buffer::parent(int index)
{
	return (index -1) / 2;
}

int intra::Buffer::left(int index)
{
	return 2 * index + 1;
}

int intra::Buffer::right(int index)
{
	return 2 * index + 2;
}

void intra::Buffer::swap(Frame& f1, Frame& f2)
{
	Frame temp = f1;
	f1 = f2;
	f2 = temp;
}

intra::Buffer::Buffer(int capacite) : m_capacite{capacite}, m_size{0}
{
	m_frames = new Frame[m_capacite]{};
}

void intra::Buffer::ajouter(Frame frame)
{
	if (!estPlein())
	{
		int index{ m_size };
		m_frames[index] = frame;

		while (parent(index) >= 0 && m_frames[index].frameId < m_frames[parent(index)].frameId)
		{
			swap(m_frames[index], m_frames[parent(index)]);
			index = parent(index);
		}
		m_size++;
	}
}

intra::Frame intra::Buffer::lire()
{
	Frame frame{INT_MAX, ' '};
	if (!estVide())
	{
		frame = m_frames[0];
		swap(m_frames[0], m_frames[m_size - 1]);
		m_size--;
		heapify();
	}
	return frame;
}

bool intra::Buffer::estVide()
{
	return m_size == 0;
}

bool intra::Buffer::estPlein()
{
	return m_size == m_capacite;
}


