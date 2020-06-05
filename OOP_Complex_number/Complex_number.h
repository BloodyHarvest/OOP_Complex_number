#pragma once
#include <iostream>
#include <math.h>
#define PI 3.14159265

void print_menu(void);
int choose_number(const char *message);



//enum for edit form of complex number
enum Form
{
	ALG_FORM, TRIG_FORM, EXP_FORM
};

using namespace std;

template<class T1>
class Complex
{
private:
	T1* real; //field for real part of complex number
	T1* imag; //field for imagine part of complex number
	static Form form; //field for saving form of complex number
	bool* isReal; //field for check that memory is initialized
	void init_memory(void) //function for dynamic allocate memory
	{
		real = new T1; 
		imag = new T1;
		isReal = new bool;
	}

public:
	//setter
	void setRealPart(T1 re); //setting real part of complex number
	void setImagPart(T1 im); //setting imagine part of complex number
	void setBothParts(T1 re, T1 im); //setting both parts in algebraic form of complex number
	void setBothtrigparts(T1 r, float angle); //setting both parts in trigonometric form of complex number
	void setForm(Form f); //setting form for number

	//getter
	bool getReal(); 
	Form getform();
	T1 getRealPart();
	T1 getImgPart();
	T1* getAlgForm();
	T1* getExpForm();
	T1* getTrigForm();

	//Constructor
	Complex<T1>(T1 re, T1 im)
	{
		init_memory();
		setRealPart(re);
		setImagPart(im);
	}

	Complex<T1>()
	{
		init_memory();
		setRealPart(0);
		setImagPart(0);
	}

	//Destructor
	~Complex<T1>()
	{
		delete real;
		delete imag;
		delete isReal;
		cout << "Destructor!\n";
	}

	//Overloaded operators for arifmetical operations
	Complex<T1> operator + (const Complex<T1>& other);
	Complex<T1> operator - (const Complex<T1>& other);
	Complex<T1> operator * (const Complex<T1>& other);
	Complex<T1> operator / (const Complex<T1>& other);
	void raisetopower(T1 power, int mode);

	//Overloaded operators for comparing 
	bool operator == (const Complex<T1>& other);
	void operator = (const Complex<T1>& other);
	T1 operator[](int i);

	//Overloaded operator for print
	friend std::ostream& operator << (std::ostream& str, const Complex<T1>& his)
	{
		switch (form)
		{
		case ALG_FORM:
			str << "Alg form:";
			str << "z=" << *his.real << "+(" << *his.imag << "i)" << "\n";
			break;
		case TRIG_FORM:
			cout << "Trig form:";
			cout << "z=" << sqrt((*his.real * *his.real) + (*his.imag * *his.imag)) << "*(cos(" << atan2(*his.imag, *his.real) * 180 / PI << ")+sin(" << atan2(*his.imag, *his.real) * 180 / PI << ")j)" << "\n";
			break;
		case EXP_FORM:
			cout << "Exp form:";
			cout << "z=" << sqrt(*his.real * *his.real + *his.imag * *his.imag) << "*e^i*" << atan2(*his.imag, *his.real) << "pi" << "\n";
			break;
		}
		return str;
	}

	//Overloaded operator for write 
	friend std::ostream& operator >> (std::ostream& str, const Complex<T1>& his)
	{
		cout << "Write real part\n";
		cin >> *his.real;
		cout << "Write imag part\n";
		cin >> *his.imag;
		return str;
	}

	//Operators for dynamic alocating and free memory
	void* operator new(size_t size)
	{
		void* ptr;
		ptr = malloc(size);
		if (!ptr)
		{
			bad_alloc error;
			throw error;
		}
		return ptr;
	}

	void operator delete(void* ptr)
	{
		free(ptr);
	}

	void* operator new[](size_t size)
	{
		void* ptr;
		ptr = malloc(size);
		if (!ptr)
		{
			bad_alloc error;
			throw error;
		}
		return ptr;
	}

	void operator delete[](void* ptr)
	{
		free(ptr);
	}
};

//Returns bool variable, it display that private fields is not NULL.  
template<class T1>
bool Complex<T1>::getReal() 
{
	return *this->isReal;
}

//Method for setting or modify real field
template <class T1>
void Complex<T1>::setRealPart(T1 re)
{
	if (re != NULL)
	{
		*this->real = re;
	}
	else
	{
		*this->real = 0;
	}

	if (getImgPart() != NULL)
	{
		*this->isReal = true;
	}
	else
	{
		*this->isReal = false;
	}
}

//Method for setting or modify imagine field
template <class T1>
void Complex<T1>::setImagPart(T1 im)
{
	if (im != NULL)
	{
		*this->imag = im;
	}
	else
	{
		*this->imag = 0;
	}

	if (getRealPart() != NULL)
	{
		*this->isReal = true;
	}
	else
	{
		*this->isReal = false;
	}
}

//Method for setting or modify all fields
template <class T1>
void Complex<T1>::setBothParts(T1 re, T1 im)
{
	setRealPart(re);
	setImagPart(im);
}

//Method for setting or modify all fields in trigonometrical form
template <class T1>
void Complex<T1>::setBothtrigparts(T1 r, float angle)
{
	setRealPart(r * cos(angle * PI / 180.0));
	setImagPart(r * sin(angle * PI / 180.0));
}

//Method for setting the form for modify/display numbers
template <class T1>
void Complex<T1>::setForm(Form f)
{
	switch (f)
	{
	case 0:
		form = ALG_FORM;
		break;
	case 1:
		form = TRIG_FORM;
		break;
	case 2:
		form = EXP_FORM;
		break;
	default:
		form = ALG_FORM;
		break;
	}
}

//Method for getting current form
template <class T1>
Form Complex<T1>::getform()
{
	return form;
}

//Method for getting value of field real
template <class T1>
T1 Complex<T1>::getRealPart()
{
	return *this->real;
}

//Method for getting value of field imag
template <class T1>
T1 Complex<T1>::getImgPart()
{
	return *this->imag;
}

//Method for getting value of fields in algebraic form
template <class T1>
T1* Complex<T1>::getAlgForm()
{
	T1* alg = new T1[2];
	alg[0] = *this->real;
	alg[1] = *this->imag;
	return alg;
}

//Method for getting value of fields in exponental form
template  <class T1>
T1* Complex<T1>::getExpForm()
{
	T1* expa = new T1[2];
	expa[0] = sqrt(*this->real * *this->real + *this->imag * *this->imag);
	expa[1] = atan2(*this->imag, *this->real);
	return expa;
}

template  <class T1>
T1* Complex<T1>::getTrigForm()
{
	T1* trig = new T1[2];
	trig[0] = sqrt((*this->real * *this->real) + (*this->imag * *this->imag));
	trig[1] = atan2(*this->imag, *this->real) * 180 / PI;
	if (trig[1] < 0)
	{
		trig[1] = 360 + trig[1];
	}
	return trig;
}


template <class T1>
Complex<T1> Complex<T1>::operator + (const Complex<T1>& other)
{
	Complex<T1>* arif;
	arif = new Complex<T1>(0, 0);
	arif->setRealPart(*this->real + *other.real);
	arif->setImagPart(*this->imag + *other.imag);
	return *arif;
}

template <class T1>
Complex<T1> Complex<T1>::operator - (const Complex<T1>& other)
{
	Complex<T1>* arif;
	arif = new Complex<T1>(0, 0);
	arif->setRealPart(*this->real - *other.real);
	arif->setImagPart(*this->imag - *other.imag);
	return *arif;
}

template <class T1>
Complex<T1> Complex<T1>::operator * (const Complex<T1>& other)
{
	Complex<T1>* arif;
	arif = new Complex<T1>(0, 0);
	arif->setRealPart((*this->real * *other.real) - (*this->imag * *other.imag));
	arif->setImagPart((*this->imag * *other.real) + (*this->real * *other.imag));
	return *arif;
}

template <class T1>
Complex<T1> Complex<T1>::operator / (const Complex<T1>& other)
{
	Complex<T1>* arif;
	arif = new Complex<T1>(0, 0);
	arif->setRealPart(((*this->real * *other.real) + (*this->imag * *other.imag)) / ((*other.real * *other.real) + (*other.imag * *other.imag)));
	arif->setImagPart(((*this->imag * *other.real) - (*this->real * *other.imag)) / ((*other.real * *other.real) + (*other.imag * *other.imag)));
	return *arif;
}

//Method for copying values of fields within numbers
template <class T1>
void Complex<T1>::operator = (const Complex<T1>& other)
{
	this->setImagPart(*other.imag);
	this->setRealPart(*other.real);
}

template <class T1>
bool Complex<T1>::operator == (const Complex<T1>& other)
{
	bool isTrue = false;
	if (*this->real == *other.real && *this->imag == *other.imag)
	{
		isTrue = true;
	}
	return isTrue;
}

//Returns real field if var i is 0,imagine if 1,else throw the exception code
template <class T1>  
T1 Complex<T1>::operator[](int i)
{
	if (i == 0)
	{
		return *this->real;
	}
	else if (i == 1)
	{
		return *this->imag;
	}
	else
	{
		throw "Invalid number in [] case";
	}
}


template <class T1>
void Complex<T1>::raisetopower(T1 power, int mode)
{
	T1* trig = new T1[2];
	trig = getExpForm();

	T1 p = trig[0];
	T1 f = trig[1];

	if (mode == 0)
	{
		trig[0] = pow(trig[0], power);
		trig[1] = f * power;
	}
	else if (mode == 1)
	{
		float po = power * -1;
		trig[0] = pow(trig[0], 1 / power);
		trig[1] = f / po;
	}

	setBothParts(trig[0] * cos(trig[1]), trig[0] * sin(trig[1]));
}


