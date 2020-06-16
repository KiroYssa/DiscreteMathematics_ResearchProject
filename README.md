# DiscreteMathematics_ResearchProject
Relation operations on Sets

Here, there is a program that runs the operations required in Point 2-b - as 𝑅̅, 𝑆−1, 𝑅∩𝑆,and 𝑅∪𝑆.
Implement a program which takes an input of Set A (as an example A={1,2,3,4} )
and it processes to create a new 2D Array called Array_Original that holds all possible relations ordered pairs for the set,
then inputing the Relation R and S according to these conditions (R = {(x,y); x + y < 4} and S = {(x,y); x = y} ),
then the program starts giving an output as the mentioned operations above in Line 4.
The code consists of 3 parts 
(first is for declaring the functions, second the main function that manages everything, and third the functions itself)
it is turned out that displaying the output of each operation requires a block of code 
so it is made to be a function by itself to be used anytime with fewer lines of code, 
and (Deallocating2Darray Function) achieves the same idea but with different functionality 
as it is deallocated 2D Arrays created within running the program.
Then, the first function is the Complement that takes a 2D Array and outputs the complement of it,
which would be the difference between the ordered pair(s) of the Original Array (that hold all possible relations) 
and the ordered pairs of the relation that is required to result in the complement of it.
Second, the inverse function which takes the relation and reverses (swaps) each ordered pair in that relation - x=y & y=x -.
The third function is Intersection, 
The intersection between two relations ( 𝑅∩𝑆 as mentioned ) by comparing each pair in R with each other element in S,
then if there are two same ordered pair this pair is put in another new Array (Array_Temp).
Forth function is Union, Union can be obtained by different rules,
a simple rule is used in implementing its function which is ( 𝑅∪𝑆 = ( 𝑅^𝑐 ∩ 𝑆^𝑐 )^𝑐 ). 
So, it’s obvious that we get first by our previous implemented functions the complement of both of R and S 
then put the result of the intersection between them in a 2D array (Array_Temp) then get the Complement of that result
which is the last answer (for the Union operation ) and put that answer in a new another 2D array called (Arrray_Temp2), 
then displaying the result(Union between R and S). 
Certainly, it is obvious that at the end of each function in the program (including the main function) 
all allocated arrays are deallocated (using Deallocating2Darray Function) to prevent memory leak after using the program.
