#include <iostream>
#include "Complex_number.h"

template<class T1>
Form Complex<T1>::form = ALG_FORM;
uint8_t input_key = '0';
int key = 0;
int form = 0;
int part = 0;
float real = 0;
float imag = 0;
bool truevalue = true;
Complex<float>* x;
Complex<float>* y;
Complex<float>* z;
int main()
{
    Complex<float> ariff(0, 0);
    x = new Complex<float>(5, -6);
    y = new Complex<float>(10, 8);
    z = new Complex<float>[10];

    while (1)
    {
        if (input_key != '0')
        {
            cout << "Rebooting...\n";
        }
        else
        {
            cout << "Starting program!\n";
        }
        
        input_key = '0';
        form = 0;
        part = 0;
        real = 0;
        imag = 0;
        truevalue = true;

        while (truevalue)
        {

            do
            {
                print_menu();
                cin >> input_key;
                fflush(stdin);

                switch (input_key)
                {

                case '0':
                    cout << "GOOD BYE!\n";
                    break;

                case '1':
                    cout << "Choose form\n";
                    cout << "0-Alg form\n";
                    cout << "1-Trig form\n";
                    cout << "2-Exp form\n";
                    cin >> form;
                    switch (form)
                    {
                    case 0:
                        x->setForm(Form::ALG_FORM);
                        break;
                    case 1:
                        x->setForm(Form::TRIG_FORM);
                        break;
                    case 2:
                        x->setForm(Form::EXP_FORM);
                        break;
                    }
                    cout << "Form mode is switched!\n";
                    break;

                case '2':
                    cout << "Enter the number to modify\n";
                    cout << "1 - X\n";
                    cout << "2 - Y\n";
                    cout << "3 - Z[]\n";
                    cin >> input_key;
                    cout << "What part modify to?\n";
                    cout << "1 - Real\Module\n";
                    cout << "2 - Imag\Argument\n";
                    cout << "3 - Both parts\n";
                    cin >> part;
                    switch (part)
                    {
                    case 1:
                        cout << "Write real part\n";
                        cin >> real;
                        switch (input_key)
                        {
                        case '1':
                            x->setRealPart(real);
                            break;
                        case '2':
                            y->setRealPart(real);
                            break;
                        case '3':
                            cout << "write x Z[x]\n";
                            cin >> key;
                            z[key].setRealPart(real);
                            break;
                        default:
                            cout << "Incorrect input!\n";
                            truevalue = false;
                            break;
                        }
                        break;

                    case 2:
                        cout << "Write imag part\n";
                        cin >> imag;
                        switch (input_key)
                        {
                        case '1':
                            x->setImagPart(imag);
                            break;
                        case '2':
                            y->setImagPart(imag);
                            break;
                        case '3':
                            cout << "write x Z[x]\n";
                            cin >> key;
                            z[key].setImagPart(imag);
                            break;
                        default:
                            cout << "Incorrect input!\n";
                            truevalue = false;
                            break;
                        }
                        break;

                    case 3:
                        switch (form)
                        {
                        case ALG_FORM:
                            cout << "Write real part\n";
                            cin >> real;
                            cout << "Write imag part\n";
                            cin >> imag;
                            switch (input_key)
                            {
                            case '1':
                                x->setBothParts(real, imag);
                                break;
                            case '2':
                                y->setBothParts(real, imag);
                                break;
                            case '3':
                                cout << "write x Z[x]\n";
                                cin >> key;
                                z[key].setBothParts(real,imag);
                                break;
                            default:
                                cout << "Incorrect input!\n";
                                truevalue = false;
                                break;
                            }
                            break;
                        case TRIG_FORM:
                        case EXP_FORM:
                            cout << "Write module\n";
                            cin >> real;
                            cout << "Write angle\n";
                            cin >> imag;
                            switch (input_key)
                            {
                            case '1':
                                x->setBothtrigparts(real, imag);
                                break;
                            case '2':
                                y->setBothtrigparts(real, imag);
                                break;
                            case '3':
                                cout << "write x Z[x]\n";
                                cin >> key;
                                z[key].setBothtrigparts(real, imag);
                                break;
                            default:
                                cout << "Incorrect input!\n";
                                truevalue = false;
                                break;
                            }
                            break;
                        default:
                            cout << "Input key is incorrect\n";
                            truevalue = false;
                            break;
                        }
                        break;
                    default:
                        cout << "Input key is incorrect\n";
                        truevalue = false;
                        break;
                    }

                    break;

                case '3':
                    cout << "Choose number display to\n";
                    cout << "1 - X\n";
                    cout << "2 - Y\n";
                    cin >> input_key;
                    switch (input_key)
                    {
                    case '1':
                        x->print_complex_number();
                        break;
                    case '2':
                        y->print_complex_number();
                        break;
                    case '3':
                        cout << "write x Z[x]\n";
                        cin >> key;
                        z[key].print_complex_number();
                        break;
                    default:
                        cout << "Input key is incorrect\n";
                        truevalue = false;
                        break;
                    }
                    break;

                case '4':
                    cout << "Write X\n";
                    cin >> key;
                    cout << "X:"; 
                    z[key].print_complex_number();
                    cout << "\n";
                    cout << "Write Y\n";
                    cin >> part;
                    cout << "Y:";
                    z[part].print_complex_number();
                    cout << "\n";
                    if (z[key].getReal() && z[part].getReal())
                    {
                        ariff = z[key] + z[part];
                        cout << "Result(X + Y):";
                        ariff.print_complex_number();

                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '5':
                    cout << "Write X\n";
                    cin >> key;
                    cout << "X:";
                    z[key].print_complex_number();
                    cout << "\n";
                    cout << "Write Y\n";
                    cin >> part;
                    cout << "Y:";
                    z[part].print_complex_number();
                    cout << "\n";
                    if (z[key].getReal() && z[part].getReal())
                    {
                        ariff = z[key] + z[part];
                        cout << "Result(X - Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '6':
                    cout << "Write X\n";
                    cin >> key;
                    cout << "X:";
                    z[key].print_complex_number();
                    cout << "\n";
                    cout << "Write Y\n";
                    cin >> part;
                    cout << "Y:";
                    z[part].print_complex_number();
                    cout << "\n";
                    if (z[key].getReal() && z[part].getReal())
                    {
                        ariff = z[key] + z[part];
                        cout << "Result(X * Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '7':
                    cout << "Write X\n";
                    cin >> key;
                    cout << "X:";
                    z[key].print_complex_number();
                    cout << "\n";
                    cout << "Write Y\n";
                    cin >> part;
                    cout << "Y:";
                    z[part].print_complex_number();
                    cout << "\n";
                    if (z[key].getReal() && z[part].getReal())
                    {
                        ariff = z[key] + z[part];
                        cout << "Result(X / Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '8':
                    if (x->getReal() && y->getReal())
                    {
                        cout << "Choose the number\n";
                        cout << "1 - X\n";
                        cout << "2 - Y\n";
                        cin >> input_key;
                        cout << "Choose mode\n";
                        cout << "0 - Power\n";
                        cout << "1 - Root\n";
                        cin >> form;
                        cout << "Enter power\n";
                        cin >> real;
                        switch (input_key)
                        {
                        case '1':
                            x->raisetopower(real, form);
                            x->print_complex_number();
                            break;
                        case '2':
                            y->raisetopower(real, form);
                            y->print_complex_number();
                            break;
                        default:
                            cout << "Input key is incorrect\n";
                            truevalue = false;
                            break;
                        }
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;
                default:
                    cout << "Input key is incorrect\n";
                    truevalue = false;
                    break;
                }
            } 
            while (input_key != '0');
            cout << "Your sure want to exit?\n" << "Y - yes\n" << "N - no\n";
            cin >> input_key;
            if (input_key == 'Y')
            {
                return 0;
            }
            else
            {
                truevalue = false;
            }
        }
    }
}