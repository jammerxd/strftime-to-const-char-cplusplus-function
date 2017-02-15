#include <iostream>
#include <ctime>

inline void wait_on_enter()
{
	std::string dummy;
	std::cout << "Enter to continue..." << std::endl;
	std::cin.get();
}
const char* currentTime()
{
	const char* timeStr = "";
	char buffer[4096];
	
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	strftime(buffer, 8192, "%a %b %d %R:%S %Y", &ltm);
	char *nBuffer = new char[strlen(reinterpret_cast<const char*>(buffer))+1];
	strncpy_s(nBuffer, strlen(reinterpret_cast<const char*>(buffer))+1, reinterpret_cast<const char*>(buffer), strlen(reinterpret_cast<const char*>(buffer))+1);
	return nBuffer;
}
int main()
{
	std::cout << "The current time is: " << currentTime() << std::endl;
	wait_on_enter();
	return 0;
}
