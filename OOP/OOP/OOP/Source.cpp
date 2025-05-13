#include <sstream> // stringstream
#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <istream>
#include "Matrix.h"
using namespace std;


//OOP - Task 1 


double* readTXT(char *fileName, int sizeR, int sizeC);
void WritePGM(char *filename, double *data, int sizeR, int sizeC, int Q);
Matrix logoRestore(BinaryImage& Shuffled, BinaryImage& Noise, int A, int B);


int main()
{
	int M = 512; int N = 512;
	double* shuffledLogo = 0;
	double* noisyLogo = 0; 


	char* inputFileNameShuffled = "logo_shuffled.txt";
	char* inputFileNameNoise = "logo_with_noise.txt"; 
	char* outputFileName = "logo_restored.pgm";

	cout << "-----------------------(TASK 1)-----------------------\n" << endl;
	cout << "This program will restore a shuffled picture of the University of Lincoln Logo" << endl; 
	cout << "Please allow a maximum of 30 seconds for this task to complete\n" << endl;


	//load shuffled logo
	cout << "Now lodaing shuffled logo... " << endl;
	shuffledLogo = readTXT(inputFileNameShuffled, M, N);
	cout << "Load successful\n" << endl; 

	//load noisy logo
	cout << "Now loading noisy logo... " << endl;
	noisyLogo = readTXT(inputFileNameNoise, M, N);
	cout << "Load successful\n" << endl; 

	//converts logos to matrices
	BinaryImage LogoToRestore(M, N, shuffledLogo, 150); 
	BinaryImage LogoComparison(M, N, noisyLogo, 150); 

	//starts the process
	cout << "Working...\n" << endl; 
	Matrix FixedLogo = logoRestore(LogoToRestore, LogoComparison, 32, 512); 
	cout << "Restoration complete\n" << endl;
	cout << "Saving..." << endl; 

	// writes data back to .pgm file stored in outputFileName
	WritePGM(outputFileName, FixedLogo.getDoubleData(), M, N, 1);
	cout << "Saved as: " << outputFileName << endl; 

	//delete[] input_data;
	system("PAUSE"); 

}



Matrix logoRestore(BinaryImage& Shuffled, BinaryImage& Noise, int sizeOfBlock, int sizeOfLogo)
{

	//stores the sum of squared differences 
	Matrix SoSD((sizeOfLogo / sizeOfBlock), (sizeOfLogo / sizeOfBlock), -1);
	BinaryImage matrixOutput(sizeOfLogo, sizeOfLogo, 1);



	for (int i = 0; i < (sizeOfLogo / sizeOfBlock); i++) //noisy columns
	{
		for (int j = 0; j < (sizeOfLogo / sizeOfBlock); j++) //noisy rows
		{
			for (int k = 0; k < (sizeOfLogo / sizeOfBlock); k++) //shuffled columns
			{
				for (int l = 0; l < (sizeOfLogo / sizeOfBlock); l++) //shuffled rows 
				{

					//stores the noisy and shuffled block into seperate matrices
					BinaryImage ShuffledBlockMatrix = Shuffled.getBlock((sizeOfBlock * l), ((sizeOfBlock * l) + sizeOfBlock), (sizeOfBlock * k), ((sizeOfBlock * k) + sizeOfBlock));
					BinaryImage NoisyBlockMatrix = Noise.getBlock((sizeOfBlock * i), ((sizeOfBlock * i) + sizeOfBlock), (sizeOfBlock * j), ((sizeOfBlock * j) + sizeOfBlock));

					BinaryImage SSD = ShuffledBlockMatrix - NoisyBlockMatrix;

					double SSDSum = SSD.sumValue();

					SoSD.setValue(l, k, SSDSum);

				} 
			}

			int minValue = SoSD.minValue(); 

			//convert the minimum value found into matrix coordinates 
			int lowPositionX = (minValue / (sizeOfLogo / sizeOfBlock));
			int lowPositionY = (minValue - (lowPositionX*(sizeOfLogo / sizeOfBlock)));

			//stores the correct block to be inserted
			Matrix InsertBlock = Shuffled.getBlock((sizeOfBlock * lowPositionX), ((sizeOfBlock*lowPositionX) + sizeOfBlock), (sizeOfBlock * lowPositionY), ((sizeOfBlock * lowPositionY) + sizeOfBlock));

			//inserts the 'correct' block that was just found
			matrixOutput.setBlock((i * sizeOfBlock), ((i * sizeOfBlock) + sizeOfBlock), (j * sizeOfBlock), ((j * sizeOfBlock) + sizeOfBlock), InsertBlock); 


		}
	}

	return matrixOutput; 
}
	


// Read .txt file with image of size RxC, and convert to an array of doubles
double* readTXT(char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{

		while (myfile.good())
		{
			if (i > sizeR*sizeC - 1) break;
			myfile >> *(data + i);
			//cout << *(data+i) << ' '; // This line display the converted data on the screen, you may comment it out. 
			i++;
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	//cout << i;

	return data;
}

// convert data from double to .pgm stored in filename
void WritePGM(char *filename, double *data, int sizeR, int sizeC, int Q)
{
	int i;
	unsigned char *image;
	ofstream myfile;

	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i < sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myfile.open(filename, ios::out | ios::binary | ios::trunc);

	if (!myfile) {
		cout << "Can't open file: " << filename << endl;
		exit(1);
	}

	myfile << "P5" << endl;
	myfile << sizeC << " " << sizeR << endl;
	myfile << Q << endl;

	myfile.write(reinterpret_cast<char *>(image), (sizeR*sizeC)*sizeof(unsigned char));

	if (myfile.fail()) {
		cout << "Can't write image " << filename << endl;
		exit(0);
	}

	myfile.close();
	delete[] image;

}