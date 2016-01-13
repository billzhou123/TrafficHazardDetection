#include "ConsoleThread.h"
#include "THDUtil.h"


ConsoleThread::ConsoleThread()
{

}


void ConsoleThread::process()
{
	while (1)
	{
		if (globalStop)
			break;
		mutex_consoleMessage.lock();
		string msg = consoleMessage;
		mutex_consoleMessage.unlock();

		if (msg != ""){
			emit sendGlobalMessage();
		}
		Sleep(200);
	}
}
