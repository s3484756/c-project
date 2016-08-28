/***********************************************************************
 * Author           : Luke Ellison - Joshua Theeuf
 * Student Number   : s3484756 -  s3234575
 ***********************************************************************/
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
int seedInput(char* ag[], int c){
	string flag = "--g";
	string loadbflag = "--lb";
	int count = 0;
	if(flag.compare(ag[1]) == 0 && c > 2){
		cout << "flag --g entered " << endl;
		regex r("[[:digit:]]+");
		// checks the input arguments and counts the number of digit input starting from argv[2]
		// stops when reaches end of argv or reads an input that isn't a digit
		for(int i = 2; i < c; i++){
			if(regex_match(ag[i],r))
				count++;
			else
				break;
		}
		// no seed, width or height specified
		if (count == 0){
			return 2;
		}
		// seed specified, no width or height
		if (count == 1){
			return 3;
		}
		//height and width specified, no seed
		if(count == 2){
			return 4;
		}
		// seed width and height specified
		if(count == 3){
			cout << "maze has height off " << ag[3] << endl;
			cout << "maze has width off " << ag[4] << endl;
			return 1;
		}
		//invalid number of digits		
		return 0;	
	}
	else if(loadbflag.compare(ag[1]) == 0){
		//send back that main should load binary file
		return 5;
	}
	return 0;
}

int outputOptions(char* ag[], int c, int startIndex){
	string svgFlag = "--sv";
	string binaryFlag = "--sb";
	string svgExt = ".svg";
	if(startIndex + 3 <= c){
		//save to svgFile and save to binary
		if (svgFlag.compare(ag[startIndex]) == 0 && binaryFlag.compare(ag[startIndex+2]) == 0){
			return 1;
		}
		//save to binary and save to svgFile
		else if(binaryFlag.compare(ag[startIndex]) && svgFlag.compare(ag[startIndex+2]) == 0){
			return 2;
		}
		//save to binary
		else if(binaryFlag.compare(ag[startIndex]) == 0){
			return 3;
		}
		//save to svgFile 
		else if(svgFlag.compare(ag[startIndex]) == 0){
					string fileName = ag[startIndex++];
		size_t i = fileName.rfind(svgExt,fileName.length());
			if(i!=string::npos){
				cout << "saving to " << fileName << endl;
			}
			else{
				cout << "incorrect file extension, expects .maze" << endl;
				return false;
			}
			return 4;
		}
	}
	return 0;
	
}



