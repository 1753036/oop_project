#include "Border.h"



Border::Border(std::string fileName, int x, int y)
	: _x(x)
	, _y(y)
{
	std::ifstream in(fileName);
	if (in.is_open() == false) {
		std::cout << "File not found: " << fileName << std::endl;
		return;
	}

	std::string buff;

	while (std::getline(in, buff)) {
		if (buff[0] == '#') continue;
		if (buff == "[Border]") {
			in >> _size;

			_dataX = new int[_size];
			_dataY = new int[_size];

			for (int i = 0; i < _size; ++i)
				in >> _dataX[i] >> _dataY[i];
		}
	}

	in.close();
}


Border::~Border()
{
	delete[] _dataX;
	delete[] _dataY;
}

bool Border::isImpact(Border& bor) {

	for (int i = 0; i < _size; ++i)
		for (int j = 0; j < bor._size; ++j)
			if (_dataX[i] + _x == bor._dataX[j] + bor._x && 
				_dataY[i] + _y == bor._dataY[j] + bor._y)
				return true;
	return false;
}