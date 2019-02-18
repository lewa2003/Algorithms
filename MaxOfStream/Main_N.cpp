#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


class TTopElements {
public:

    TTopElements(int topSize);
    void Add(const int & elem);
    void GetCurrentTop(std::vector<int> & top);

private:

	void MoveToFront(int l, int r, int k);
	vector<int> Hp;
	int TopSize;
};

TTopElements::TTopElements(int topSize) {
	TopSize = topSize;
	Hp.clear();
}

void TTopElements::Add(const int & elem) {
   	Hp.push_back(elem);
}

void TTopElements::GetCurrentTop(std::vector<int> & top) {
    MoveToFront(0, Hp.size() - 1, TopSize);

    top.resize(TopSize);
    for (int i = 0; i < TopSize; i++)
    	top[i] = Hp[i];
}

void TTopElements::MoveToFront(int l, int r, int k) {
	if (l >= r)
		return;
	int i = l;
	int j = r;
	int x = Hp[rand() % (r - l + 1) + l];
	while (i <= j) {
		while (Hp[i] > x) i++;
		while (Hp[j] < x) j--;
		if (i <= j)
			swap(Hp[i++], Hp[j--]);
	}
	if (j - l + 1 < k)
		MoveToFront(i, r, k - (j - l + 1));
	else
		MoveToFront(l, j, k);
}

int main() {

	int All_size, Top;
	std::cin >> All_size >> Top;
	TTopElements A(Top);
	for (int i = 0; i < All_size; i++) {
		int x;
		std::cin >> x;
		A.Add(x);
	}
	vector<int> ans;
	A.GetCurrentTop(ans);
	for (int i = 0; i < Top; i++)
		std::cout << ans[i] << ' ';
	std::cout << endl;

	return 0;
}
