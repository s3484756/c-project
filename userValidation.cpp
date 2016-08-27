#include <string>
#include <iostream>
#include <regex> 
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
		return true;
	}

	return false;
}
bool saveSvg(char* ag[], int argIndex){
	/*this function will return true if it can save, the function will return false otherwise */
	string flagSave = "--sv";
	string saveExt = ".svg";
	if(flagSave.compare(ag[argIndex]) == 0){
		cout << "saving file. " << endl;
			string fileName = ag[argIndex++];
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
bool saveBinary(char* ag[], int argIndex){
	string flagSave = "--sb";
	string saveExt = ".maze";
	if(flagSave.compare(ag[argIndex])==0){
		cout << "saving binary" << endl;
		string fileName = ag[argIndex++];
		size_t i = fileName.rfind(saveExt,fileName.length());
			if(i!=string::npos){
				cout << "saving to " << fileName << endl;
			}
			else{
				cout << "incorrect file extension, expects .maze" << endl;
				return false;
			}
		return true;
	}	
	return false;
}
bool seedInput(char* ag[], int c){
	string flag = "--g";
	if(flag.compare(ag[1]) == 0){
		cout << "flag --g entered " << endl;
		regex r("[[:digit:]]+");
	if(c >= 4){
			if(regex_match(ag[2],r) && regex_match(ag[3],r)){
				cout << "maze has height off " << ag[2] << endl;
				cout << "maze has width off " << ag[3] << endl;
			return true;
			}
		
		}	
	}
	return false;
}



