#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <cstdint>

#define interface struct

interface IUnknown
{
public:
	virtual bool Say() = 0;
	typedef std::shared_ptr<IUnknown> spUnknown;
};

class IOne :public IUnknown {
public: bool Say() { std::cout << "One" << std::endl; return true; }
};
class ITow :public IUnknown {
public: bool Say() { std::cout << "Tow" << std::endl;  return true;}
};
class IThree :public IUnknown {
public: bool Say() { std::cout << "Three" << std::endl; return true; }
};
class IFour :public IUnknown {
public: bool Say() { std::cout << "Four" << std::endl;  return true;}
};

typedef std::vector<IUnknown::spUnknown> Unknowns;
typedef std::map<std::uint16_t, Unknowns> M;

int main() {
	M M = { {1,{std::make_shared<IOne>()}} };

	M[2].push_back(std::make_shared<ITow>());

	M[1].push_back(std::make_shared<IThree>());

	M[1].push_back(std::make_shared<IFour>());

	for (auto& oo: M) {
		for (auto& o: oo.second) {
			o->Say();
		}
		std::cout << std::endl;
	}

}