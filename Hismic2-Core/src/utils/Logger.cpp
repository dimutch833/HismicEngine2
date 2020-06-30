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
	}
}