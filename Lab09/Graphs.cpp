#include "Graphs.h"
#include <iostream>
#include <vector>

using namespace std;

Graphs::Graphs()
{
    for(int i = 0; i < N; i++)
    {
        vector<int> v;
        for(int j = 0; j < M; j++)
        {
            v.push_back(0);
        }
        m_values.push_back(v);
    }
}

Graphs::Graphs(int size1, int size2)
{
    for(int i = 0; i < size1; i++)
    {
        vector<int> v;
        for(int j = 0; j < size2; j++)
        {
            v.push_back(0);
        }
        m_values.push_back(v);
    }
    N = size1;
    M = size2;
}

bool Graphs::PrintOutAdjacencyMatrix()
{
    if(m_values.size() == 0)
    {
        return false;
    }
    for(int i = 0; i < m_values.size(); i++)
    {
        for(int j = 0; j < m_values[i].size(); j++)
        {
            cout << m_values[i][j];
        }
        cout << endl;
    }

    return true;
}

bool Graphs::AddEdge(int i, int j)
{
    if(i >= N || j >= M || i < 0 || j < 0)
    {
        cout << "AddEdges: Out of Bounds" << endl;
        return false;
    }

    m_values[i][j] = 1;
    m_values[j][i] = 1;
    return true;
}

bool Graphs::RemoveEdge(int i, int j)
{
    if(i >= N || j >= M || i < 0 || j < 0)
    {
        cout << "RemoveEdge: Out of Bounds" << endl;
        return false;
    }

    m_values[i][j] = 0;
    m_values[j][i] = 0;
    return true;
}

bool Graphs::HasEdge(int i, int j)
{
    if(i >= N || j >= M || i < 0 || j < 0)
    {
        cout << "HasEdge: Out of Bounds" << endl;
        return false;
    }

    if(m_values[i][j] || m_values[j][i])
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<int> Graphs::OutEdges(int i)
{
    vector<int> outEdgesList;
    if(i >= N || i < 0)
    {
        cout << "OutEdges: Out of Bounds" << endl;
        return outEdgesList;
    }

    for(int j = 0; j < M; j++)
    {
        if(m_values[i][j] == 1)
        {
            outEdgesList.push_back(j);
        }
    }

    return outEdgesList;
}

vector<int> Graphs::InEdges(int j)
{
    vector<int> inEdgesList;

    if(j >= M || j < 0)
    {
        cout << "InEdges: Out of Bounds" << endl;
    }

    for(int i = 0; i < N; i++)
    {
        if(m_values[i][j] == 1)
        {
            inEdgesList.push_back(i);
        }
    }

    return inEdgesList;
}

int Graphs::getN()
{
    return N;
}

int Graphs::getM()
{
    return M;
}

Graphs::~Graphs()
{

}