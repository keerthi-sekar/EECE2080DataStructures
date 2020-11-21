// tests.cpp
#include "Graphs.h"
#include <gtest/gtest.h>

	TEST(GraphTests,Constructor1)
	{
		Graphs graph;
		ASSERT_EQ(10, graph.getN());
		ASSERT_EQ(10, graph.getM());
	}

	TEST(GraphTests,Constructor2)
	{
		Graphs graph(10, 15);
		ASSERT_EQ(10, graph.getN());
		ASSERT_EQ(15, graph.getM());
	}

	TEST(GraphTests, addEdge1)
	{
		Graphs graph;
		graph.AddEdge(1,1);
		ASSERT_EQ(1, graph.m_values[1][1]);
	}

	TEST(GraphTests, addEdge2)
	{
		Graphs graph;
		bool test;
		test = graph.AddEdge(11, 11);
		ASSERT_FALSE(test);
	}

	TEST(GraphTests, removeEdge1)
	{
		Graphs graph;
		graph.AddEdge(1,1);
		graph.RemoveEdge(1,1);
		ASSERT_EQ(0, graph.m_values[1][1]);
	}

	TEST(GraphTests, removeEdge2)
	{
		Graphs graph;
		bool test;
		graph.AddEdge(1,1);
		test = graph.RemoveEdge(11, 11);
		ASSERT_FALSE(test);
	}

	TEST(GraphTests, hasEdge1)
	{
		Graphs graph;
		bool test;
		graph.AddEdge(1,1);
		test = graph.HasEdge(1,1);
		ASSERT_TRUE(test);
	}

	TEST(GraphTests, hasEdge2)
	{
		Graphs graph;
		bool test;
		test = graph.HasEdge(1,1);
		ASSERT_FALSE(test);
	}

	TEST(GraphTests, outEdges1)
	{
		Graphs graph;
		int size;
		graph.AddEdge(1,1);
		graph.AddEdge(1,3);
		graph.AddEdge(1,5);
		graph.AddEdge(1,7);
		size = graph.OutEdges(1).size();
		ASSERT_EQ(size, 4);
	
	}

	TEST(GraphTests, outEdges2)
	{
		Graphs graph;
		int size;
		size = graph.OutEdges(11).size();
		ASSERT_EQ(size, 0);
	}

	TEST(GraphTests, inEdges1)
	{
		Graphs graph;
		int size;
		graph.AddEdge(1,1);
		graph.AddEdge(3,1);
		graph.AddEdge(5,1);
		graph.AddEdge(7,1);
		size = graph.InEdges(1).size();
		ASSERT_EQ(size, 4);
	
	}

	TEST(GraphTests, inEdges2)
	{
		Graphs graph;
		int size;
		size = graph.InEdges(11).size();
		ASSERT_EQ(size, 0);
	}

	TEST(GraphTests, print1)
	{
		Graphs graph;
		bool test = graph.PrintOutAdjacencyMatrix();
		ASSERT_TRUE(test);
	}

	TEST(GraphTests, print2)
	{
		Graphs graph(0, 0);
		bool test = graph.PrintOutAdjacencyMatrix();
		ASSERT_FALSE(test);
	}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
