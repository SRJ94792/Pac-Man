#pragma once
#include<iostream>
#include<fstream>
#include <dirent.h>
#include<stdio.h>
#include<vector>
#include<sstream>
using namespace std;

template<class T>
class node
{
	T data;
public:
	node<T>* next = NULL;

	T getData()
	{
		return data;
	}
	void setData(T x)
	{
		data = x;
	}
};
template<class T>
class Queue
{
	node<T>* front = NULL;
	node<T>* rare = NULL;
	node<T>* newn;
public:
	node<T>* getRear()
	{
		return rare;
	}
	void enqueue(T x)
	{
		if (front == NULL)
		{
			newn = new node<T>;
			newn->setData(x);
			front = newn;
			rare = newn;
		}
		else
		{
			newn = new node<T>;
			newn->setData(x);
			rare->next = newn;
			rare = newn;
		}

	}
	T Front()
	{
		return front->getData();
	}
	void dequeue()
	{
		if (front != NULL)
		{
			newn = front;
			front = front->next;
			delete newn;
		}
	}

	bool isEmpty()
	{
		if (front == NULL)
			return true;
		else
			return false;
	}


};

/*
These all classes along with their function definitions are for the sake of GTESTs that you are going to use to implement the assignment.
You can add more classes , member variables & member functions that supports your functionality.
*/
template <typename T>
struct Node
{
	vector<Node<T>*> child;
	Node<T>* parent;
	T Data;
	int NO = 0;
	Node()
	{

	}
	Node(T D)
	{
//		child = new Node<T>*[N];
		Data = D;
		parent = NULL;
	}
};

template<typename T>
struct AvlNode
{
    vector<Node<T>*> LIST;
  //  int NO;
    char Data;
    AvlNode<T>* left;
    AvlNode<T>* right;
    AvlNode(char value)
    {
    //    NO = 0;
        Data = value;
        left = NULL;
        right = NULL;
    }
};

template<typename T>
class AVLTree
{
public:
    AvlNode<T>* Treeroot=NULL;
	void Inser(AvlNode<T>*& R, char D)
	{
		if (R == NULL)
		{
			R = new AvlNode<T>(D);
		}
		else if (R->Data < D)
		{
			Inser(R->right, D);
		}
		else if (R->Data > D)
		{
			Inser(R->left, D);
		}
	//	cout << BF(R)<<",";
		if (BF(R) > 1)
		{
			if ((BF(R) / BF(R)) == (BF(R->left) / BF(R->left)))
				RL(R);
			else
			{
				LL(R->left);
				RL(R);
			}
		}
		if (BF(R) < -1)
		{
			if ((BF(R) / BF(R)) == (BF(R->right) / BF(R->right)))
				LL(R);
			else
			{
				RL(R->right);
				LL(R);
			}
		}
	}
	int Height(AvlNode<T>*& R)
	{
		if (R == NULL)
		{
			return -1;
		}
		else
		{
			int lh = 1;
			int rh = 1;
			lh = lh + Height(R->left);
			rh = rh + Height(R->right);
			if (lh > rh)
				return lh;
			else
				return rh;
		}
	}

	void LL(AvlNode<T>*& R)
	{
		AvlNode<T>* Tmp = R->right;
		R->right = Tmp->left;
		Tmp->left = R;
		R = Tmp;
	}

	void RL(AvlNode<T>*& R)
	{
		AvlNode<T>* Tmp = R->left;
		R->left = Tmp->right;
		Tmp->right = R;
		R = Tmp;
	}

	int BH(AvlNode<T>* R)
	{
		int H = Height(R->left) - Height(R->right);
		//cout << H;
		return H;
	}
	bool Bal(AvlNode<T>* R)
	{
		if (R == NULL)
			return true;
		if (BF(R) <= 1 && BF(R) >= -1)
		{
			return true;
		}
		else
		{ 
			bool a1, a2;
			if (!(Bal(Node<T>*R->left)))
				a1= false;
		    if (!(Bal(Node<T>*R->right)))
				a2 false;
			if (a1 == false || a2 == false)
				return false;
			else
				return true;
		}
	}
	void insert(Node<T>*& N,char D)
	{
		if (D >= 'a' && D <= 'z')
			D = D - 32;
		AvlNode<T>*& J = FIND(Treeroot, D);
		if(J==NULL)
		{
    		Inser(Treeroot, D);
			AvlNode<T>*& j = FIND(Treeroot, D);
			j->LIST.push_back(N);
		}
		else
			J->LIST.push_back(N);

		return;
	}
	int H(AvlNode<T>* R)
	{
		return Height(R);
	}
	int BF(AvlNode<T>* R)
	{
		return BH(R);
	}
	bool isBalanced()
	{
		bool chck = Bal(Treeroot);
		return chck;
	}
	void makedeletion(AvlNode<T>*& root)
	{
		AvlNode<T>* newn;
		if (root->right == NULL)
		{
			newn = root;
			root = root->left;
			delete newn;
		}
		else if (root->left == NULL)
		{
			newn = root;
			root = root->right;
			delete newn;
		}
		else
		{
			newn = root->right;
			while (newn->left != NULL)
			{
				newn = newn->left;
			}
			newn->left = root->left;
			newn = root;
			root = root->right;
			delete newn;
		}
	}
	void delet(AvlNode<T>*& root, char N)
	{
		if (root == NULL)
			return;
		else if (root->Data > N)
			delet(root->left, N);
		else if (root->Data < N)
			delet(root->right, N);
		else
			makedeletion(root);
	}

	AvlNode<T>*& FIND(AvlNode<T>*& Root, char D)
	{
		if (Root == NULL)
			return Root;
		else if (Root->Data == D)
			return Root;
		else if (D > Root->Data)
			return FIND(Root->right, D);
		else if (D < Root->Data)
			return FIND(Root->left, D);
	}
    //Search File in AVL. It will return an array containing paths of the given file. will return NULL if no such file exist
    //Check Test Case for better understanding of output
    T* searchFile(T Directory) 
	{
		string* List;
		List = new string[10];
		char D;
		D = Directory[0];
		if (D >= 'a' && D <= 'z')
			D = D - 32;
		int n = 0;
		AvlNode<T>*& Q = FIND(Treeroot, D);
		for (int i = 0; i < Q->LIST.size(); i++)
		{
			Node<T>* temp, * TM;
			temp = Q->LIST[i];
			if (temp->Data == Directory)
			{
				string Pth;
				TM = temp;
				while (TM)
				{
					string Z;
					Z = Z + '/';
					Z = Z + TM->Data;
					Z = Z + Pth;
					Pth = Z;
					TM = TM->parent;
				}

				string Path;
				Path = Path + '.';
				Path = Path + Pth;
				List[n] = Path;
				n++;
			}
		}
		if (n == 0)
			return NULL;
		else
		return List;


    }

    //This function returns string in format i.e. "J,D,O,A" after traversing AVL in levelOrder fashion
    //Check Test Case for better understanding of output
	string l(AvlNode<T>*& Root)
	{
		Queue<AvlNode<T>*> Q;
		Q.enqueue(Root);
		string Z;
		while (!Q.isEmpty())
		{
			AvlNode<T>* temp = Q.Front();
			//cout <<temp->Data;
			Q.dequeue();
			if (temp->left)
				Q.enqueue(temp->left);
			if (temp->right)
				Q.enqueue(temp->right);
			Z = Z + temp->Data;
			if (!Q.isEmpty())
				Z = Z + ',';
		}
		//	Z = Z - ',';
		return Z;
	}
	string levelOrderTraversal()
	{
		string Tree;
		Tree = l(Treeroot);
		return Tree;

	}

    //This function returns string in format i.e. "J,D,O,A" after traversing AVL in preOrder fashion
    //Check Test Case for better understanding of output
    string preorderTraversal() {

    }

    //This function returns string in format i.e. "J,D,O,A" after traversing AVL in postOrder fashion
    //Check Test Case for better understanding of output
    string postorderTraversal() {

    }

    //This function returns string in format i.e. "J,D,O,A" after traversing AVL in inOrder fashion
    //Check Test Case for better understanding of output
    string inorderTraversal() {

    }
};





//Remember :- You can add more classes that support your functionality

template <typename T>
class NaryTree {
public:
	Node<T>* Treeroot;
    AVLTree<T> avl;
    AVLTree<T> getAVL() {
        return avl;
    }

	void Insert(string Root,Node<T>* Parent)
	{
		string Pth;
		Node<T>* temp,*TM;
		temp = new Node<T>(Root);
		temp->parent = Parent;
		Parent->child.push_back(temp);
		char D;
		D = Root[0];
		bool K = false;
		int J = Root.length();
		if (Root.length() > 4)
		{
			int J = Root.length();
			string h;
			h = h + Root[J - 4];
			h = h + Root[J - 3];
			h = h + Root[J - 2];
			h = h + Root[J - 1];
			if (h == ".txt")
			{
				K= true;
			}
		}
		if (K == true)
		{
			avl.insert(temp, D);
		}
		TM = temp;
		while (TM)
		{
			string Z;
			Z = Z + '/';
			Z = Z + TM->Data;
			Z = Z + Pth;
			Pth = Z;
			TM = TM->parent;
		}

		string Path;
		Path = Path + '.';
		Path = Path + Pth;

		char* P = new char[Path.length() + 1];
		strcpy(P, Path.c_str());
		string* Directories;
		Directories = new string[25];
		int n = 0;
		DIR* direct;
		struct dirent* subdirect;
		direct = opendir(P);
		if (direct)
		{
			while ((subdirect = readdir(direct)) != NULL)
			{
				Directories[n] = subdirect->d_name;
				n++;
			}
		}
		closedir(direct);
		if(n!=0)
		{ 
			for (int i = 2; i < n; i++)
			{
			//	cout << "here";
				bool k = true;
				int j = Directories[i].length();
				if (Directories[i].length() > 4)
				{
					int j = Directories[i].length();
					string h;
					h = h + Directories[i][j - 4];
					h = h + Directories[i][j - 3];
					h = h + Directories[i][j - 2];
					h = h + Directories[i][j - 1];
					if (h == ".txt")
					{
						k = false;
					}
				}
				if (k == true)
					Insert(Directories[i], temp);
			//	temp->NO++;
			}

			for (int i = 2; i < n; i++)
			{
				bool k = false;
				int j = Directories[i].length();
				if (Directories[i].length() > 4)
				{
					int j = Directories[i].length();
					string h;
					h = h + Directories[i][j - 4];
					h = h + Directories[i][j - 3];
					h = h + Directories[i][j - 2];
					h = h + Directories[i][j - 1];
					if (h == ".txt")
					{
						k = true;
					}
				}
				if (k == true)
				{
					Insert(Directories[i], temp);
					//temp->NO++;
				}
			}

		}


	}
    //Create an N-ary tree and its corresponding AVl by taking path of root directory
    void CreateTree(T Path) 
    {
		char* P = new char[Path.length() + 1];
		strcpy(P, Path.c_str());
		string* Directories;
		Directories = new string[25];
		int n = 0;
		DIR* direct;
		struct dirent* subdirect;
		direct = opendir(P);
		while ((subdirect = readdir(direct)) != NULL)
		{
			Directories[n] = subdirect->d_name;
			n++;
		}
		closedir(direct);
		string Root;
		for (int i = 2; i < Path.length(); i++)
			Root = Root + Path[i];
		Treeroot = new Node<T>(Root);
		char D;
		D = Root[0];
		//avl.insert(Treeroot, D);

		if (n != 0)
		{

			for (int i = 2; i < n; i++)
			{
				//cout << "here";
				bool k = true;
				int j = Directories[i].length();
				if (Directories[i].length() > 4)
				{
					int j = Directories[i].length();
					string h;
					h = h + Directories[i][j - 4];
					h = h + Directories[i][j - 3];
					h = h + Directories[i][j - 2];
					h = h + Directories[i][j - 1];
					if (h == ".txt")
					{
						k = false;
					}
				}
				if (k == true)
				{
				//	cout << Directories[i];
					Insert(Directories[i], Treeroot);
					//Treeroot->NO++;
				}
			}

			for (int i = 2; i < n; i++)
			{
				bool k = false;
				int j = Directories[i].length();
				if (Directories[i].length() > 4)
				{
					int j = Directories[i].length();
					string h;
					h = h + Directories[i][j - 4];
					h = h + Directories[i][j - 3];
					h = h + Directories[i][j - 2];
					h = h + Directories[i][j - 1];
					if (h == ".txt")
					{
						k = true;
					}
				}
				if (k == true)
				{
					Insert(Directories[i], Treeroot);
					//Treeroot->NO++;
				}
			}

		}




    }

    //Add a file to N-ary tree at a give path and store its path in AVL and returns true if successfully added
    bool addFile(T P, T filename) 
	{
		string L;
		int l = 2;
		int X = 1, Y;
		Node<T>*& Q = Treeroot;
		while (l <= P.length())
		{
			if (P[l] == '/' || l == (P.length()))
			{
				X++;
				string B;
				for (int j = X; j < l; j++)
				{
					B = B + P[j];
					//  cout << P[j];
				}
				for (int i = 0; i < Q->child.size(); i++)
				{
					Node<T>* temp;
					temp = Q->child[i];
					if (temp->Data == B)
					{
						Q = Q->child[i];
					}
				}
				X = l;
			}
			l++;
		}

		Node<T>* temp;
		temp = new Node<T>(filename);
		temp->parent = Q;
		Q->child.push_back(temp);
		char D;
		D = filename[0];
		bool K = false;
		int J = filename.length();
		if (filename.length() > 4)
		{
			int J = filename.length();
			string h;
			h = h + filename[J - 4];
			h = h + filename[J - 3];
			h = h + filename[J - 2];
			h = h + filename[J - 1];
			if (h == ".txt")
			{
				K = true;
			}
		}
		if (K == true)
		{
			avl.insert(temp, D);
		}
		return true;

    }
	
    //Add a folder to N-ary tree at a give path and returns true if successfully added
    bool AddFolder(T folderpath, T foldername)
	{

    }
    //Delete a file from N-ary tree and its path from avl and returns true if successfully deleted
    //Check Test Case for better understanding of output
    bool deleteFile(T filename) 
	{
		char D;
		D = filename[0];
		if (D >= 'a' && D <= 'z')
			D = D - 32;
		AvlNode<T>*& DF=avl.FIND(avl.Treeroot, D);

		Node<T>* Temp,*TM;
		bool X = false;
		int i = 0,j=0;
		for (; i < DF->LIST.size(); i++)
		{
			Temp = DF->LIST[i];
			if (Temp->Data == filename)
			{
				X = true;
				break;
		    }
		}
		TM = Temp->parent;
		for (; j < TM->child.size(); j++)
		{
			Temp = TM->child[j];
			if (Temp->Data == filename)
			{
				X = true;
				break;
			}
		}
		if (X == true)
		{
			DF->LIST.erase(DF->LIST.begin() + i);
			TM->child.erase(TM->child.begin() + j);
			if (DF->LIST.size() == 0)
			{
				avl.delet(avl.Treeroot, DF->Data);
			}
			return X;
		}
    }

    //Delete a folder and all the files and folders from N-ary tree and path of files from avl and returns true if successfully deleted
    //Check Test Case for better understanding of output
	bool DF(Node<T>* Root)
	{
		Queue<Node<T>*> Q;
		Q.enqueue(Root);
		//string Z;
		while (!Q.isEmpty())
		{
			Node<T>* temp = Q.Front();
			cout <<temp->Data;
			Q.dequeue();
			if (!temp->child.size())
			{
				if (deleteFile(temp->Data))
				{
					continue;
				}
				else
				{
					Node<T>* Tem;
					Tem = temp->parent;
					int i;
					for (i = 0; Tem->child[i]->Data != temp->Data; i++);

					Tem->child.erase(Tem->child.begin() + i);
				}
            }
			else if (temp->child.size())
			{
				for (int i = 0; i < (temp->child.size()); i++)
				{
					if (temp->child[i])
						Q.enqueue(temp->child[i]);
				}
			}
		}
		return true;
		//return Z;

	}
    bool DeleteFolder(T P)
	{
//		string L;
		int l = 2;
		int X = 1, Y;
		Node<T>* Q = Treeroot;


		while (l <= P.length())
		{
			if (P[l] == '/' || l == (P.length()))
			{
				X++;
				string B;
				for (int j = X; j < l; j++)
				{
					B = B + P[j];
					//  cout << P[j];
				}
				for (int i = 0; i < Q->child.size(); i++)
				{
					Node<T>* temp;
					temp = Q->child[i];
					if (temp->Data == B)
					{
						Q = Q->child[i];
					}
				}
				X = l;
			}
			l++;
		}
		cout<<Q->Data;
		Y = DF(Q);
		Node<T>*& Temp =Q->parent;
		int i;
		for (i = 0;Temp->child[i]->Data != Q->Data; i++);

		Temp->child.erase(Temp->child.begin() + i);
		return true;
    }

    //Merge two folders by moving all the files and folders of 2nd folder to first folder and update the paths in avl  and returns true if folders successfully merged
    //Check Test Case for better understanding of output
    bool MergeFolder(T P1, T P2) 
	{
		int l = 2;
		int X = 1, Y;
		Node<T>* Q1 = Treeroot;
		Node<T>*  Q2= Treeroot;


		while (l <= P1.length())
		{
			if (P1[l] == '/' || l == (P1.length()))
			{
				X++;
				string B;
				for (int j = X; j < l; j++)
				{
					B = B + P1[j];
					//  cout << P[j];
				}
				for (int i = 0; i < Q1->child.size(); i++)
				{
					Node<T>* temp;
					temp = Q1->child[i];
					if (temp->Data == B)
					{
						Q1 = Q1->child[i];
					}
				}
				X = l;
			}
			l++;
		}
		l = 2;
		X = 1;
		while (l <= P2.length())
		{
			if (P2[l] == '/' || l == (P2.length()))
			{
				X++;
				string B;
				for (int j = X; j < l; j++)
				{
					B = B + P2[j];
					//  cout << P[j];
				}
				for (int i = 0; i < Q2->child.size(); i++)
				{
					Node<T>* temp;
					temp = Q2->child[i];
					if (temp->Data == B)
					{
						Q2 = Q2->child[i];
					}
				}
				X = l;
			}
			l++;
		}

		cout << Q1->Data<<endl;
		cout << Q2->Data << endl;

		Node<T>*& QQ= Q1->parent;
		for (int i = 0; i < QQ->child.size(); i++)
		{
			if (QQ->child[i]->Data == Q1->Data)
			{
				Node<T>*& AB = QQ->child[i];
				for (int j = 0; j < Q2->child.size(); j++)
				{
					Node<T>*& BA = Q2->child[j];
					BA->parent = AB;
					AB->child.push_back(BA);
				}
				Node<T>*& FG = Q2->parent;
				int K;
				for (K = 0; FG->child[K] != Q2; K++);
				FG->child.erase(FG->child.begin() + K);
			}
		}


		return true;

    }


    //Display N-ary tree in treeform
    void DisplayTreeForm() {

    }
	
    //This function returns string in format i.e. "logs,powerLogs,timeUsageLog,voltageLogs,systemlog.txt" after traversing AVL in inOrder fashion
    //Check Test Case for better understanding of output
	string I(Node<T>* Root)
	{
		if (Root->child.size() == 0)
		return Root->Data;
		else
		{
			//cout << Root->NO;
			string Z;
			for(int i=0;i<(Root->child.size())-1;i++)
			{
				Z = Z + I(Root->child[i]);
				Z = Z + ',';
			}
			Z = Z + Root->Data;
				Z = Z + ',';
			Z = Z + I(Root->child[(Root->child.size())-1]);
			return Z;
		}
	}
	string inorderTraversal() 
	{

		string Tree;
		Tree = I(Treeroot);
		return Tree;

    }

    //This function returns string in format i.e. "logs,powerLogs,timeUsageLog,voltageLogs,systemlog.txt" after traversing AVL in preOrder fashion
    //Check Test Case for better understanding of output
	string P(Node<T>* Root)
	{
		if (Root->child.size() == 0)
			return Root->Data;
		else
		{
			//cout << Root->NO;
			string Z;
			Z = Z + Root->Data;
			Z = Z + ',';
			for (int i = 0; i < (Root->child.size()); i++)
			{
				Z = Z + P(Root->child[i]);
				if (i != (Root->child.size() - 1))
					Z = Z + ',';
			}
			return Z;
		}
	}
	string preorderTraversal() {
		string Tree;
		Tree = P(Treeroot);
		return Tree;

    }

    //This function returns string in format i.e. "logs,powerLogs,timeUsageLog,voltageLogs,systemlog.txt" after traversing AVL in levelOrder fashion
    //Check Test Case for better understanding of output
	string l(Node<T>*& Root)
	{
		Queue<Node<T>*> Q;
		Q.enqueue(Root);
		string Z;
		while(!Q.isEmpty())
		{ 
			Node<T>* temp = Q.Front();
				//cout <<temp->Data;
			Q.dequeue();
			if(temp->child.size())
			{
				for (int i = 0; i < (temp->child.size()); i++)
				{
					if (temp->child[i])
						Q.enqueue(temp->child[i]);
				}
			}
			Z = Z + temp->Data;
			if(!Q.isEmpty())
			Z = Z + ',';
		}
	//	Z = Z - ',';
		return Z;
	}
	string levelOrderTraversal()
    {
		string Tree;
		Tree = l(Treeroot);
		return Tree;

    }

    //This function returns string in format i.e. "logs,powerLogs,timeUsageLog,voltageLogs,systemlog.txt" after traversing AVL in postOrder fashion
    //Check Test Case for better understanding of output
	string p(Node<T>* Root)
	{
		if (Root->child.size() == 0)
			return Root->Data;
		else
		{
			//cout << Root->NO;
			string Z;
			for (int i = 0; i < (Root->child.size()); i++)
			{
				Z = Z + p(Root->child[i]);
				Z = Z + ',';
			}
			Z = Z + Root->Data;
			return Z;
		}
	}
	string postorderTraversal() {
		string Tree;
		Tree = p(Treeroot);
		return Tree;
    }

    //Returns size of a file 
    //Check Test Case for better understanding of output
    int sizeFile(T F) 
	{
		string* L=avl.searchFile(F);
		ifstream file(L[0], ios::binary);
		file.seekg(0, ios::end);
		return file.tellg();
    }

    //Returns size of a folder 
    //Check Test Case for better understanding of output
	int SF(Node<T>* temp,string Trav)
	{
		if (temp->child.size() == 0)
		{
			//cout << temp->Data;
			string* L = avl.searchFile(temp->Data);
			int i;
			for (i = 0; L[i] != Trav; i++);
			ifstream file(L[i], ios::binary);
			file.seekg(0, ios::end);
			//cout << file.tellg();
			return file.tellg();
		}
		else
		{
			int X=0;
			for (int i = 0; i < temp->child.size(); i++)
			{
				string tr;
				tr = tr + Trav;
				tr = tr + '/';
				tr = tr + temp->child[i]->Data;
				X = X + SF(temp->child[i],tr);
				cout << X;
			}
			return X;
		}
	}
	int sizeFolder(T P) 
	{

		string L;
		int l=2;
		int X=1,Y;
		Node<T>* Q =Treeroot;


		while (l <= P.length())
		{
			if (P[l] == '/'||l==(P.length()))
			{
				X++;
				string B;
			    for (int  j= X; j < l; j++)
				{ 
				   B = B + P[j];
				 //  cout << P[j];
				}
				for (int i = 0; i < Q->child.size(); i++)
				{
					Node<T>* temp;
					temp = Q->child[i];
					if (temp->Data == B)
					{
						Q = Q->child[i];
					}
				}
				X = l;
			}
			l++;
		}
		Y = SF(Q,P);
		return Y;
    }

};

