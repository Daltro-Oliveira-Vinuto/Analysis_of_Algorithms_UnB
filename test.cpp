#include <bits/stdc++.h>
#include "logicGate.cpp"

using namespace std;

int main() {
	AndGate gAnd1("and1");
	AndGate gAnd2("and2");
	OrGate gOr("or");
	NotGate gNot("not");

	gAnd1.setNextInput(0);
	gAnd1.setNextInput(0);
	gAnd2.setNextInput(0);
	gAnd2.setNextInput(0);

	Connector connector1(&gAnd1, &gOr);
	Connector connector2(&gAnd2, &gOr);
	Connector connector3(&gOr, &gNot);


	cout << gNot.getOutput() << endl;


	return 0;
}