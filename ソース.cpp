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

namespace ID {
	enum Symbol{
		None=0,
		A,
		B,
		C,
	};
}

enum class Symbol: std::uint8_t {
	None=0,
	A,
	B,
	C,
};


typedef std::vector<IUnknown::spUnknown> Unknowns;
typedef std::map<std::uint16_t, Unknowns> M;
typedef std::map<ID::Symbol, Unknowns> WeekSymbolCollecter;
typedef std::map<Symbol, Unknowns> StrongSymbolCollecter;

int main() {
	{
		M M = { {1,{std::make_shared<IOne>()}} };

		M[2].push_back(std::make_shared<ITow>());

		M[1].push_back(std::make_shared<IThree>());

		M[1].push_back(std::make_shared<IFour>());

		for (auto& oo : M) {
			for (auto& o : oo.second) {
				o->Say();
			}
			std::cout << std::endl;
		}
	}
		
	std::cout <<"*------------*"<< std::endl;	
	
	{
		WeekSymbolCollecter M = { {ID::A,{std::make_shared<IOne>()}} };

		M[ID::B].push_back(std::make_shared<ITow>());

		M[ID::C].push_back(std::make_shared<IThree>());

		M[ID::A].push_back(std::make_shared<IFour>());

	//	M[16].push_back(std::make_shared<IThree>());
		for (auto& oo : M) {
			for (auto& o : oo.second) {
				o->Say();
			}
			std::cout << std::endl;
		}
	}
	std::cout <<"*------------*"<< std::endl;
	{
		StrongSymbolCollecter M = { {Symbol::A,{std::make_shared<IOne>()}} };
		
		M[Symbol::B].push_back(std::make_shared<ITow>());

		M[Symbol::C].push_back(std::make_shared<IThree>());

		M[Symbol::A].push_back(std::make_shared<IFour>());

		M[Symbol::B].push_back(std::make_shared<IThree>());
		for (auto& oo : M) {
			for (auto& o : oo.second) {
				o->Say();
			}
			std::cout << std::endl;
		}
	}

}