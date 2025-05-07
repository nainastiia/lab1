#ifndef CLOTHING_H
#define CLOTHING_H
#include <string>
#include <iostream>
using namespace std;

class Wearable {
public:
	Wearable() {
		cout << "Wearable created.\n";
	}

	virtual ~Wearable() {
		cout << "Wearable destroyed.\n";
	}

	virtual void Display() {
		cout << "Wearable item.\n";
	}
};

class Colorable : virtual public Wearable {
protected:
	string color;
public:
	Colorable(const string& c) : color(c) {
		cout << "added color: " << color << "\n";
	}

	virtual ~Colorable() {
		cout << "removed color: " << color << "\n";
	}

	virtual void DisplayColor() {
		cout << "Color: " << color << "\n";
	}
};

class Sizable : virtual public Wearable {
protected:
	string size;
public:
	Sizable(const string& s) : size(s) {
		cout << "added size: " << size << "\n";
	}

	virtual ~Sizable() {
		cout << "removed size: " << size << "\n";
	}

	virtual void DisplaySize() {
		cout << "Size: " << size << "\n";
	}
};


class Clothing : public Colorable, public Sizable{
protected:
	int CreateClothingInternal();
public:
	Clothing(const string& c, const string& s)
		: Wearable(), Colorable(c), Sizable(s){
		CreateClothingInternal();
	}

	int SetColor(const string& c);
	int SetSize(const string& s);
	virtual void Describe();
	virtual ~Clothing() {
		cout << "Clothing destroyed.\n";
	}

	void Display() override {
		cout << "Clothing item.\n";
		DisplayColor();
		DisplaySize();
	}
};

class Shirt :  public Clothing {
public:
	Shirt(const string& c, const string& s);

	void Describe() override;
	virtual ~Shirt() {
		cout << "Shirt destroyed.\n";
	}
};

class Pants :  public Clothing {
public:
	Pants(const string& c, const string& s);

	void Describe() override;
	virtual ~Pants() {
		cout << "Pants destroyed.\n";
	}
};

class Jacket :  public Clothing {
public:
	Jacket(const string& c, const string& s);

	void Describe() override;
	virtual ~Jacket() {
		cout << "Jacket destroyed.\n";
	}
};

class DesignerShirt : public Shirt {
protected:
	string brand;
public:
	DesignerShirt(const string& c, const string& s, const string& b);

	void Describe() override;
	virtual ~DesignerShirt() {
		cout << "Designer shirt removed.\n";
	}
};

class CasualJacket : public Jacket {
protected:
	bool hasHood;
public:
	CasualJacket(const string& c, const string& s, bool hood);

	void Describe() override;
	virtual ~CasualJacket() {
		cout << "Casual jacket removed.\n";
	}
};

class MultiFeatureItem : public Shirt, public Pants, public Jacket {
protected:
	string feature;
public:
	MultiFeatureItem(const string& c, const string& s, const string& f);

	void Describe() override;

	virtual ~MultiFeatureItem() {
		cout << "MultiFeatureItem removed.\n";
	}
};

#endif
