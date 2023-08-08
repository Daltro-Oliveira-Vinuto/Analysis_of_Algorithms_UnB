#include <string>
#include <iostream>

class LogicGate {
public:
	LogicGate(std::string label) {
		this->label = label;
	}

	bool getOutput();
	virtual bool performGateLogic() {
		std::cout <<"Error! perfomGateLogic called in the base class Logic Gate" << std::endl;
		output = false;
		return output;
	};
	virtual void setNextInput(bool) {};
private:
	std::string label;
	bool output;

};

class Connector {
public:
	Connector(LogicGate* from, LogicGate* to) {
		this->from_gate = from;
		this->to_gate = to;
		to_gate->setNextInput((*from_gate).getOutput());
	}

	LogicGate* getFromGate() {
		return from_gate;
	}

	LogicGate* getToGate() {
		return to_gate;
	}

private:
	LogicGate *from_gate, *to_gate;
};

class UnaryGate: public LogicGate {
public:
	UnaryGate(std::string label): LogicGate(label) {
		pinTaken = false;
	}

	void setNextInput(bool);
	bool getPin();
private:
	bool pin;
	bool pinTaken;
};

class BinaryGate: public LogicGate {
public:
	BinaryGate(std::string label): LogicGate(label) {
		pinATaken = false;
		pinBTaken = false;
	}

	void setNextInput(bool);
	bool getPinA();
	bool getPinB();
private:
	bool pinA, pinB;
	bool pinATaken, pinBTaken;
};

class NotGate: public UnaryGate {
public:
	NotGate(std::string label): UnaryGate(label) {};
	bool performGateLogic();
};

class AndGate: public BinaryGate {
public:
	AndGate(std::string label): BinaryGate(label) {};
	bool performGateLogic();
};

class OrGate: public BinaryGate {
public:
	OrGate(std::string label): BinaryGate(label) {};
	bool performGateLogic();
};


bool NotGate::performGateLogic() {
	if (getPin()) {
		return false;
	} else {
		return true;
	}
}


bool AndGate::performGateLogic() {
	if (getPinA() && getPinB()) {
		return true;
	} else {
		return false;
	}
}


bool OrGate::performGateLogic() {
	if (getPinA() || getPinB()) {
		return true;
	} else {
		return false;
	}
}


void BinaryGate::setNextInput(bool source) {
	if (pinATaken == false) {
		pinA = source;
		pinATaken = true;
	} else if (pinBTaken == false) {
		pinB = source;
		pinBTaken = true;
	}
}

bool BinaryGate::getPinA() {
	if (pinATaken == true) {
		return pinA;
	} else {
		std::cout << "Type the value of the pin(0/1): ";
		std::cin >> pinA;
		pinATaken = true;
		return pinA;
	}
}

bool BinaryGate::getPinB() {
	if (pinBTaken == true) {
		return pinB;
	} else {
		std::cout << "Type the value of the pin(0/1): ";
		std::cin >> pinB;
		pinBTaken = true;
		return pinB;
	}
}


void UnaryGate::setNextInput(bool source) {
	if (pinTaken == false) {
		pin = source;
		pinTaken = true;
	}
}

bool UnaryGate::getPin() {
	if (pinTaken == true) {
		return pin;
	} else {
		std::cout << "Type the value of the pin(0/1): ";
		std::cin >> pin;
		pinTaken = true;
		return pin;
	}
}


bool LogicGate::getOutput() {
	output = performGateLogic();
	return output;
}





































