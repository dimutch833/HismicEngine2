#include "Logger.h"

void Utils::Logger::PrintLog(const char* logString, int code) {
	
	switch (code) {
	case 1:
		std::cout << "[INFO]" << logString << std::endl;
		break;
	case 2 :
		std::cout << "[WARNING]" << logString << std::endl;
		break;
	case 3 :
		std::cout << "[FAIL]" << logString << std::endl;
		break;
	case 4:
		std::cout << "[FAIL][COMPILE VERTEX SHADER]: " << logString << std::endl;
		break;
	case 5:
		std::cout << "[FAIL][COMPILE FRAGMENT SHADER]: " << logString << std::endl;
		break;

	}
}