#include <string>
#include <iostream>
using namespace std;
bool binaryLoad(char *ag[]){
	string validUser[5] = {"--lb","--sb","--sv",".maze",".svg"};
	/* checks if --lb flag is set, then that the file being loaded is an actual binary file with the correct file type */ 
	if(validUser[0].compare(ag[1]) == 0)
	{
	/*--lb flag set check for file type found in arg2 */
		string file = ag[2];
		size_t i = file.rfind(validUser[3],file.length());
		if(i!=string::npos){	
			cout << "correct file type loading binary file" <<endl;
			
		}
		else{
			cout << "invalid file type found for 2nd argument" << endl;
			return false;
		}
	}

	return true;
}
bool svgFile(char* ag[]){
	/*this function will return true if it can save, the function will return false otherwise */
	string flagSave = "--sv";
	string saveExt = ".svg";
	if(flagSave.compare(ag[3]) == 0){
		cout << "saving file. " << endl;
			string fileName = ag[4];
			size_t i = fileName.rfind(saveExt,fileName.length());
				if(i!=string::npos){
					cout << "Saving to " << fileName << endl;
				}
				else{
					cout << "inccrrect file extension, expect .svg" << endl;
					return false;
				}
	}
	else{
		cout << "incorrect flag set for saving file, expects --sv" << endl;
	}

		return true;
}
