#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Graph
{
	string vertices[15], edges[200];
	int vCount, eCount;
public:
	Graph() :vCount(0), eCount(0){}
	string getString(string str, int start, int &end, char c)
	{
		char s[100];
		int i, count = 0;
		for (i = start; str[i] != c&&count < 99; i++)
			s[count++] = str[i];
		s[count] = '\0';
		end = i;
		return string(s);
	}
	void ReadVertices()
	{
		ifstream indata;
		indata.open("Vertices.txt");
		string data;
		while (getline(indata, data))
			vertices[vCount++] = data;
		indata.close();
	}
	void ReadEdges()
	{
		ifstream indata("EdgesUndirected.txt");
		string data;
		while (getline(indata, data))
			edges[eCount++] = data;
		indata.close();
	}
	int getVertexPos(string str)
	{
		for (int i = 0; i < vCount; i++)
		if (vertices[i] == str)
			return i;

	}
	void AdjacencyMatrix()
	{
		int **matrix = new int*[vCount];
		for (int i = 0; i < vCount; i++)
			matrix[i] = new int[vCount];
		for (int i = 0; i < vCount; i++)
		{
			for (int j = 0; j < vCount; j++)
				matrix[i][j] = 0;
		}
		for (int i = 0; i < eCount; i++)
		{
			int end;
			string str = edges[i], rStr = getString(str, 1, end = 0, ','), cStr = getString(str, end + 1, end, ')');
			int row = getVertexPos(rStr), col = getVertexPos(cStr);
			matrix[row][col] = 1;
			matrix[col][row] = 1;
		}
		cout << "   ";
		for (int i = 0; i < vCount; i++)
			cout << vertices[i] << "  ";
		cout << endl << endl;
		for (int i = 0; i < vCount; i++)
		{
			cout << vertices[i] << "  ";
			for (int j = 0; j < vCount; j++)
			{
				cout << matrix[i][j] << "  ";
			}
			cout << endl << endl;
		}
		for (int i = 0; i < vCount; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
};

int main()
{
	Graph graph;
	graph.ReadVertices();
	graph.ReadEdges();
	graph.AdjacencyMatrix();
	system("pause");
}