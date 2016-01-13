#include "TestThread.h"

TestThread::TestThread(){

}

void TestThread::process(){
	int i = 0;
	while (true){
		emit finished(i);
		Sleep(10);
		i++;
	}

}