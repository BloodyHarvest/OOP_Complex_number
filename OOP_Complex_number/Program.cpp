#include <iostream>
#include "Complex_number.h"

using namespace std;
template<class T1>
Form Complex<T1>::form = ALG_FORM;
uint8_t input_key = '0';
int form = 0;
int part = 0;
float real = 0;
float imag = 0;
bool truevalue = true;
Complex<float>* z;

int main()
{
    Complex<float> ariff(0, 0);
    z = new Complex<float>[10]();

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
                        z[0].setForm(Form::ALG_FORM);
                        break;
                    case 1:
                        z[0].setForm(Form::TRIG_FORM);
                        break;
                    case 2:
                        z[0].setForm(Form::EXP_FORM);
                        break;
                    }
                    cout << "Form mode is switched!\n";
                    break;

                case '2':
                    cout << "Enter the number to modify\n";
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
                        z[input_key].setRealPart(real);
                        break;

                    case 2:
                        cout << "Write imag part\n";
                        cin >> imag;
                        z[input_key].setImagPart(imag);
                        break;

                    case 3:
                        switch (form)
                        {
                        case ALG_FORM:
                            cout << "Write real part\n";
                            cin >> real;
                            cout << "Write imag part\n";
                            cin >> imag;
                            z[input_key].print_complex_number();
                            z[input_key].setBothParts(real, imag);
                            break;

                        case TRIG_FORM:
                        case EXP_FORM:
                            cout << "Write module\n";
                            cin >> real;
                            cout << "Write angle\n";
                            cin >> imag;
                            z[input_key].setBothtrigparts(real, imag);
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
                    z[input_key].print_complex_number();


                case '4':
                    cout << "Write number X\n";
                    cin >> input_key;
                    cout << "Write number Y\n";
                    cin >> part;
                    if (z[input_key].getReal() && z[part].getReal())
                    {
                        ariff = z[input_key] + z[part];
                        cout << "X:"; z[input_key].print_complex_number();
                        cout << "\nY:"; z[part].print_complex_number();
                        cout << "Result(X + Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '5':
                    cout << "Write number X\n";
                    cin >> input_key;
                    cout << "Write number Y\n";
                    cin >> part;
                    if (z[input_key].getReal() && z[part].getReal())
                    {
                        ariff = z[input_key] - z[part];
                        cout << "X:"; z[input_key].print_complex_number();
                        cout << "\nY:"; z[part].print_complex_number();
                        cout << "Result(X - Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '6':
                    cout << "Write number X\n";
                    cin >> input_key;
                    cout << "Write number Y\n";
                    cin >> part;
                    if (z[input_key].getReal() && z[part].getReal())
                    {
                        ariff = z[input_key] * z[part];
                        cout << "X:"; z[input_key].print_complex_number();
                        cout << "\nY:"; z[part].print_complex_number();
                        cout << "Result(X * Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '7':
                    cout << "Write number X\n";
                    cin >> input_key;
                    cout << "Write number Y\n";
                    cin >> part;
                    if (z[input_key].getReal() && z[part].getReal())
                    {
                        ariff = z[input_key] / z[part];
                        cout << "X:"; z[input_key].print_complex_number();
                        cout << "\nY:"; z[part].print_complex_number();
                        cout << "Result(X / Y):";
                        ariff.print_complex_number();
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '8':
                    cout << "Enter the number\n";
                    cin >> input_key;
                    cout << "Choose mode\n";
                    cout << "0 - Power\n";
                    cout << "1 - Root\n";
                    cin >> form;
                    cout << "Enter power\n";
                    cin >> real;
                    if (z[input_key].getReal())
                    {
                        z[input_key].raisetopower(real, form);
                        z[input_key].print_complex_number();
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
            } while (input_key != '0');
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