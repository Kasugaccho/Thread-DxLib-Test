#include "DxLib.h"
#include <chrono>
#include <cstdint>
#include <thread>

struct coutDx {
	const coutDx& operator <<(const long long i) const {
		printfDx("%d", i);
		return *this;
	}
	const coutDx& operator <<(const uint64_t i) const {
		printfDx("%d", i);
		return *this;
	}
	const coutDx& operator <<(const int i) const {
		printfDx("%d", i);
		return *this;
	}
	const coutDx& operator <<(const unsigned int i) const {
		printfDx("%d", i);
		return *this;
	}
	const coutDx& operator <<(const char i) const {
		printfDx("%c", i);
		return *this;
	}
	const coutDx& operator <<(const char* const i) const {
		printfDx("%s", i);
		return *this;
	}
};

void lg(const char* const str_, int* const i) {
	*i = LoadGraph(str_, TRUE);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	const coutDx cout;

	//cout << std::thread::hardware_concurrency() << '\n';
	const auto start = std::chrono::system_clock::now();

	int a;
	int b;
	int c;
	int d;
	std::thread t1(lg, "a.png", &a);
	std::thread t2(lg, "a.png", &b);
	std::thread t3(lg, "a.png", &c);
	std::thread t4(lg, "a.png", &d);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	//int a=LoadGraph("a.png", TRUE);
	//int b= LoadGraph("a.png", TRUE);
	//int c = LoadGraph("a.png", TRUE);
	//int d = LoadGraph("a.png", TRUE);

	const auto end = std::chrono::system_clock::now() - start;

	DrawGraph(0, 0, a, TRUE);
	DrawGraph(100, 0, b, TRUE);
	DrawGraph(200, 0, c, TRUE);
	DrawGraph(300, 0, d, TRUE);

	cout << std::chrono::duration_cast<std::chrono::milliseconds>(end).count() << " ms\n";

	WaitKey();
	DxLib_End();
	return 0;
}