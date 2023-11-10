#include<iostream>
#include <math.h>
class shape {

protected:
	int numberOfSides;
	double * sideLenghts;
	
public:
	double getSidelengths(int i) {
	
		return *(sideLenghts + i); //dereferencing operator
	
	};
	shape() {
		numberOfSides = 0;
		sideLenghts = NULL;

	}
	shape(int numOfSides, double * sideLens) {


		numberOfSides = numOfSides;
		
		sideLenghts = new double(numberOfSides);

		for (int i = 0; i < numberOfSides; i++) {

			*(sideLenghts+i) = *(sideLens+i);

		}
		
		;


	}

	~shape() {

		 delete sideLenghts;

	}

	double perimeter() {

		double peri = 0;
		for (int i = 0; i < numberOfSides; i++) {

			peri += sideLenghts[i];
		}
		return peri;

	}

	double area() {

		if (numberOfSides == 3) {


		}
		else if (numberOfSides == 4) {



		}

	}
};

class triangle : shape {

public:
	triangle(double * sideLens) {
		numberOfSides = 3;

		sideLenghts = new double(3);

		for (int i = 0; i < 3; i++) {

			*(sideLenghts + i) = *(sideLens + i);

		}



	}
	double area() {

		double s = perimeter() / 2;
		return sqrt(s * (s - getSidelengths(0)) * (s - getSidelengths(1)) * (s - getSidelengths(2)));

	}


};

class rectangle : shape {

public :
	rectangle(double* sideLens) {

		numberOfSides = 4;

		sideLenghts = new double(4);

		for (int i = 0; i < 4; i++) {

			*(sideLenghts + i) = *(sideLens + i);

		}


	}
	double area() {

		return getSidelengths(0) * getSidelengths(1);

	}

};

int main() {

	double sides[4] = { 3.65, 2.50 , 2.1, 5.0 };

	//std::cout << sides[0]<<" " << *(sides+1) << " " << sides[2] << std::endl;

	shape myTriangle(4, sides);

	for (int i = 0; i < 4; i++) {

		std::cout << myTriangle.getSidelengths(i) << std::endl;

	}


	// *(sides+1) ======  sides[1]

}