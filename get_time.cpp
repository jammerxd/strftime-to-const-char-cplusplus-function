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
	int i = strftime(buffer, 4096,"%a %b %d %R:%S %Y", &ltm);
	if (i != 0)
		timeStr = reinterpret_cast<const char*>(buffer);
	return timeStr;
}
int main()
{
	std::cout << "The current time is: " << currentTime() << std::endl;
	wait_on_enter();
	return 0;
}
