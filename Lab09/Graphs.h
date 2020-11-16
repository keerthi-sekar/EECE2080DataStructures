#include <vector>

using namespace std;

class Graphs
{
	public:
		Graphs();
		Graphs(int size1, int size2);
		void AddEdge(int i, int j);
		void RemoveEdge(int i, int j);
		bool HasEdge(int i, int j);
		vector<int> OutEdges(int i);
		vector<int> InEdges(int i); 
		~Graphs();
	private:
		int N = 10;
		int M = 10;
		int m_values[10][10];
};










