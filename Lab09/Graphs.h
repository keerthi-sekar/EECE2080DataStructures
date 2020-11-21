#include <vector>


using namespace std;

class Graphs
{
	public:
		Graphs();
		Graphs(int size1, int size2);
        bool PrintOutAdjacencyMatrix();
		bool AddEdge(int i, int j);
		bool RemoveEdge(int i, int j);
		bool HasEdge(int i, int j);
		vector<int> OutEdges(int i);
		vector<int> InEdges(int j); 
        int getN();
        int getM();
        vector<vector<int>> m_values;
		~Graphs();
	private:
		int N = 10;
		int M = 10;
		
};








