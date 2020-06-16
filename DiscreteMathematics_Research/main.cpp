#include <iostream>
#include <string>
using namespace std;

void Display(int **Array_Relation, int num_of_pairs_R);
int **Complement(int **Array_Relation, int num_pf_pairs_R, int **Array_Original, int num_of_pairs_Original, string ch);
void Inverse(int **Array_Relation, int num_of_pairs_R, string ch);
int **Intersection(int **Array_R, int num_of_pairs_R, int **Array_S, int num_of_pairs_S, string ch1, string ch2);
void Union(int **Array_R, int num_of_pairs_R, int **Array_S, int num_of_pairs_S, int **Array_Original, int num_of_pairs_Original, string ch1, string ch2);
void Deallocating2dArray(int **Array_Relation);

//To manage the Union Function during its executing
int counts[4] = {0};
int counti=0;
bool uni = false;

int main()
{
	//Input the number of the Set A
	//Let A ={1,2,3,4}
	int num_of_pairs_Original;
	cout << "Enter the number of elements on Set A = ";
	cin >> num_of_pairs_Original;
	cout << "Enter the elements of the Set = ";

	//Implementing the Set A in an array
	int *Array_Set=new int[num_of_pairs_Original];
	for (int i = 0; i < num_of_pairs_Original; i++)
		cin >> Array_Set[i];
	
	//Implementing an array for the total possible number of relations
	int **Array_Original;
	Array_Original = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Original[i] = new int[num_of_pairs_Original*num_of_pairs_Original];

	//Setup the total possible number of relations
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0, t = 0, z = 0, counter = 0; j < num_of_pairs_Original * num_of_pairs_Original; j++, z = (z + 1) % num_of_pairs_Original)
		{
			if (i == 0)
			{
				Array_Original[i][j] = Array_Set[t];
				counter++;
				if (counter == num_of_pairs_Original)
				{
					t++;
					counter = 0;
				}
				continue;
			}
			Array_Original[i][j] = Array_Set[z];
		}
	}
	

	//Display the Ordered Pair of the Relation 1
	cout << "So the all Possible Relations = ";
	Display(Array_Original, num_of_pairs_Original*num_of_pairs_Original);

	/*===================
	Implementing Relation 1
	===================*/
	cout << "\n----------------\nEnter the Letter represented for the first Relation = ";
	string Relation1;
	cin >> Relation1;
	cout << "Enter how many the Ordered pairs in the Relation " << Relation1 << " = ";
	int num_of_pairs_R;
	cin >> num_of_pairs_R;

	int **Array_R;
	Array_R = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_R[i] = new int[num_of_pairs_R];

	cout << "Enter the Ordered Pair of Relation " << Relation1 << " :\n";

	//Input the Ordered Pair data in Relation 1
	for (int i = 0, j = 0; i < num_of_pairs_R; i++, j = 0)
		cin >> Array_R[j][i] >> Array_R[j+1][i];

	//Display the Ordered Pair of the Relation 1
	cout << "So the Relation " << Relation1 << " = ";
	Display(Array_R, num_of_pairs_R);
	//relation 1 ends


	/*===================
	Implementing Relation 2
	===================*/
	cout << "\n----------------\nEnter the Letter represented for the second  Relation = ";
	string Relation2;
	cin >> Relation2;
	cout << "Enter how many the Ordered pairs in the Relation " << Relation2 << " = ";
	int num_of_pairs_S;
	cin >> num_of_pairs_S;

	int **Array_S;
	Array_S = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_S[i] = new int[num_of_pairs_S];

	cout << "Enter the Ordered Pair of Relation " << Relation2 << ":\n";

	//Input the Ordered Pair data in Relation 2
	for (int i = 0, j = 0; i < num_of_pairs_S; i++, j = 0)
		cin >> Array_S[j][i] >> Array_S[j + 1][i];

	//Display the Ordered Pair of Relation 2
	cout << "So the Relation " << Relation2 << " = ";
	Display(Array_S, num_of_pairs_S);
	//relation 2 ends

	/*=============================
	Evaluate the following operations on the Two Relations R & S
	=============================*/

	Complement(Array_R, num_of_pairs_R, Array_Original, num_of_pairs_Original, Relation1);
	Inverse(Array_S, num_of_pairs_S, Relation2);
	Intersection(Array_R, num_of_pairs_R, Array_S, num_of_pairs_S, Relation1, Relation2);
	Union(Array_R, num_of_pairs_R, Array_S, num_of_pairs_S, Array_Original, num_of_pairs_Original, Relation1, Relation2);
	Intersection(Array_R, num_of_pairs_R, Array_S, num_of_pairs_S, Relation1, Relation2);
	Union(Array_R, num_of_pairs_R, Array_S, num_of_pairs_S, Array_Original, num_of_pairs_Original, Relation1, Relation2);

	/*=============================
	Deallocating all 2D Arrays in the program
	=============================*/

	Deallocating2dArray(Array_Original);
	Deallocating2dArray(Array_R);
	Deallocating2dArray(Array_S);

	delete Array_Set;

	return 0;
}//main end

/*======================================================================================
Display Function
=======================================================================================*/

void Display(int **Array_Relation, int num_of_pairs_R)
{
	//Display the Relation
	int i, j;
	cout << "{";
	for (i = 0, j = 0; i < num_of_pairs_R; i++, j = 0)
	{
		if (i == num_of_pairs_R - 1)
			break;
		cout << "(" << Array_Relation[j][i] << "," << Array_Relation[j + 1][i] << "),";
	}
	cout << "(" << Array_Relation[j][i] << "," << Array_Relation[j + 1][i] << ")}";
}

/*======================================================================================
Complement Function
=======================================================================================*/

int **Complement(int **Array_Relation, int num_pf_pairs_R, int **Array_Original, int num_of_pairs_Original, string ch)
{
	//Declaring a new 2D Array called Array_Temp
	int **Array_Temp;
	Array_Temp = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp[i] = new int[num_of_pairs_Original * num_of_pairs_Original];


	//Coping the data from Array_Original into Array_Temp
	for (int i = 0, j = 0; i < num_of_pairs_Original * num_of_pairs_Original; i++, j = 0)
	{
		Array_Temp[j][i] = Array_Original[j][i];
		Array_Temp[j+1][i] = Array_Original[j+1][i];
	}

	//Implementing the For loop to indicate the similar pair(s) between Array_Relation and Array_Temp
	for (int i = 0, j = 0; i < num_pf_pairs_R; i++, j = 0)
	{
		for (int k = 0, l = 0; k < num_of_pairs_Original*num_of_pairs_Original; k++, l = 0)
		{
			//Give the similar Pair(s) a value (-1) to facilitate the output display when executing
			if (Array_Relation[j][i] == Array_Original[l][k] && Array_Relation[j + 1][i] == Array_Original[l + 1][k])
			{
				Array_Temp[l][k] = -111111;
				break;
			}
		}
	}

	int num_of_pairs_Temp2 = (num_of_pairs_Original* num_of_pairs_Original) - num_pf_pairs_R;

	//Declaring another 2D Array called Array_Temp2 To make up a prepared array to be returned
	int **Array_Temp2;
	Array_Temp2 = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp2[i] = new int[num_of_pairs_Temp2];

	//Coping the Ordered pair(s) data from Array_Temp into Array_Temp2
	for (int i = 0, j = 0, k = 0; i < num_of_pairs_Temp2  && k < num_of_pairs_Original*num_of_pairs_Original; k++, j = 0)
	{
		if (Array_Temp[j][k] == -111111)
			continue;
		else
		{
			Array_Temp2[j][i] = Array_Temp[j][k];
			Array_Temp2[j+1][i] = Array_Temp[j+1][k];
			i++;
		}
	}

	//Insert in Counts[0] && Counts[1] to help Union Function when executing
	if (uni)
	{
		counts[counti] = num_of_pairs_Temp2;
		counti++;
	}

	if (!uni)
	{
		//Display the Complement of the relation R
		cout << "\n============================\nThe Complement of Relation "<< ch << " = ";
		Display(Array_Temp2, num_of_pairs_Temp2);
	}

	//Return 2D Array_Temp2
	return Array_Temp2;

	//Deallocating the Array_Temp
	Deallocating2dArray(Array_Temp);

	//Deallocating the Array_Temp2
	Deallocating2dArray(Array_Temp2);

}//complement end

/*======================================================================================
Inverse Function
=======================================================================================*/

void Inverse(int **Array_Relation, int num_of_pairs_R, string ch)
{
	//Declaring a new 2D Array called Array_Temp
	int **Array_Temp;
	Array_Temp = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp[i] = new int[num_of_pairs_R];

	//Coping the data from Array_Relation into Array_Temp
	for (int i = 0, j = 0; i < num_of_pairs_R; i++, j = 0)
	{
		Array_Temp[j][i] = Array_Relation[j][i];
		Array_Temp[j + 1][i] = Array_Relation[j + 1][i];
	}

	//Implementing the For loop to inverse each pair in Array_Temp
	//Change (a,b) into (b,a)
	for (int i = 0, j = 0; i < num_of_pairs_R; i++, j = 0)
	{
		Array_Temp[j + 1][i] = Array_Relation[j][i];
		Array_Temp[j][i] = Array_Relation[j+1][i];
	}

	//Display the Inverse of the relation S
	cout << "\n============================\nThe Inverse of Relation " << ch << " ( " << ch << "^(-1) ) = ";
	Display(Array_Temp, num_of_pairs_R);
	
	//Deallocating the Array_Temp
	Deallocating2dArray(Array_Temp);


}//inverse end

/*======================================================================================
Intersection Function
=======================================================================================*/

int **Intersection(int **Array_R, int num_of_pairs_R, int **Array_S, int num_of_pairs_S, string ch1, string ch2)
{
	//Declaring a new 2D Array called Array_Temp
	int **Array_Temp;
	Array_Temp = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp[i] = new int[num_of_pairs_R];

	int counter = 0;
	//Implementing a For Loop for Intersection Operation
	for (int i = 0, j = 0; i < num_of_pairs_R; i++, j = 0)
	{
		for (int k = 0, l = 0; k < num_of_pairs_S; k++, l = 0)
		{
			if (Array_R[j][i] == Array_S[l][k] && Array_R[j + 1][i] == Array_S[l + 1][k])
			{
				//Put this Pair in Array_Temp
				Array_Temp[j][counter] = Array_R[j][i];
				Array_Temp[j+1][counter] = Array_R[j+1][i];
				counter++;
				break;
			}
		}
	}

	if (uni)
	{
		//Insert in Counts[2] to help Union Function when executing
		counts[counti] = counter;
		counti++;
	}

	if (counter > 0)
	{
		//Declaring another 2D Array called Array_Temp2 To make up a prepared array to be returned
		int **Array_Temp2;
		Array_Temp2 = new int*[2];
		for (int i = 0; i < 2; i++)
			Array_Temp2[i] = new int[counter];

		//Coping the Ordered pair(s) data from Array_Temp into Array_Temp2
		for (int i = 0, j = 0; i < counter;i++, j=0)
		{
			Array_Temp2[j][i] = Array_Temp[j][i];
			Array_Temp2[j + 1][i] = Array_Temp[j + 1][i];
		}

		if (!uni)
		{
			//Display the Intersection between Relation R and S
			cout << "\n============================\nThe Intersection between Relation " << ch1 << " and " << ch2 << " = ";
			Display(Array_Temp2, counter);
		}


		//Return 2D Array_Temp2
		return Array_Temp2;

		//Deallocating the Array_Temp2
		Deallocating2dArray(Array_Temp2);
	}
	else
		cout << "\n============================\nThere is no Intersection between Relation " << ch1 << " and " << ch2 << ".";

	//Return 2D Array_Temp
	return Array_Temp;

	//Deallocating the Array_Temp
	Deallocating2dArray(Array_Temp);


}//intersection end

/*======================================================================================
Union Function
=======================================================================================*/

void Union(int **Array_R, int num_of_pairs_R, int **Array_S, int num_of_pairs_S, int **Array_Original, int num_of_pairs_Original, string ch1, string ch2)
{
	//Make a number of Columns that is suitable enough for the new array that will hold the 2D Array Data of the Intersection Operation
	//int sum_of_pairs = num_of_pairs_R + num_of_pairs_S;
	//Declaring a new 2D Array called Array_Temp
	int **Array_Temp;
	Array_Temp = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp[i] = new int[counts[2]];

	//Declaring a new 2D Array called Array_1 To make a Complement of it
	int **Array_1;
	Array_1 = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_1[i] = new int[num_of_pairs_R];

	//Declaring a new 2D Array called Array_2 To make a Complement of it
	int **Array_2;
	Array_2 = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_2[i] = new int[num_of_pairs_S];

	//Declaring another 2D Array called Array_Temp2 To make the resulted complement of The Intersection between Rc and Sc
	int **Array_Temp2;
	Array_Temp2 = new int*[2];
	for (int i = 0; i < 2; i++)
		Array_Temp2[i] = new int[counts[3]];

	//To disable the displaying of such Intersection and Complement Operations while Union Function is executing
	uni = true;
	counti = 0;

	string ch3 = ch1 + "c Intersection with " + ch2 + "c";
	
	//Complement of R
	Array_1 = Complement(Array_R, num_of_pairs_R, Array_Original, num_of_pairs_Original, ch1);
	
	//Complement of S
	Array_2 = Complement(Array_S, num_of_pairs_S, Array_Original, num_of_pairs_Original, ch2);

	//Intersection between Rc and Sc
	Array_Temp = Intersection(Array_1, counts[0], Array_2, counts[1], ch1+"c", ch2+"c");

	//Complement of (Rc Intersection with Sc)
	Array_Temp2 = Complement(Array_Temp, counts[2], Array_Original, num_of_pairs_Original, ch3);

	//Display the Union between Relation R and S
	cout << "\n============================\nThe Union between Relation " << ch1 << " and " << ch2 << " = ";
	Display(Array_Temp2, counts[3]);

	//redisable the uni to make any other operation safely afterwards
	uni = false;

	//Deallocating the Array_Temp
	Deallocating2dArray(Array_Temp);

	//Deallocating the Array_Temp2
	Deallocating2dArray(Array_Temp2);

	//Deallocating the Array_1
	Deallocating2dArray(Array_1);

	//Deallocating the Array_2
	Deallocating2dArray(Array_2);

}//union end

void Deallocating2dArray(int **Array_Relation)
{
	//Deallocating the Array_Relation
	for (int i = 0; i < 2; i++)
		delete Array_Relation[i];
	delete[] Array_Relation;
}