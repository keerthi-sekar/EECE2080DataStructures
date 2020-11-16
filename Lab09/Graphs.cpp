#include "Graphs.h"
#include <iostream>
#include <vector>

using namespace std;

Graphs::Graphs()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            m_values[i][j] = 0;
        }
    }
}

Graphs::Graphs(int size1, int size2)
{
    for(int i = 0; i < size1; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            m_values[i][j] = 0;
        }
    }
}

void Graphs::AddEdge(int i, int j)
{
    if(i >= N || j >= M || i < 0 || j < 0)
    {
        cout << "AddEdges: Out of Bounds" << endl;
        return;
    }

    m_values[i][j] = 1;
    m_values[j][i] = 1;
}

void Graphs::RemoveEdge(int i, int j)
{
    if(i >= N || j >= M || i < 0 || j < 0)
    {
        cout << "RemoveEdge: Out of Bounds" << endl;
        return;
    }

    m_values[i][j] = 0;
    m_values[j][i] = 0;
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

Graphs::~Graphs()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; M; j++)
        {
            cout << "destructor activated" << endl;
            //delete m_values[i][j];
        }
    }
}