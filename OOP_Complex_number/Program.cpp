#include <iostream>
#include "Complex_number.h"

template<class T1>
Form Complex<T1>::form = ALG_FORM;
uint8_t input_key = '0';
int key = 0;
int key2 = 0;
int form = 0;
int part = 0;
float real = 0;
float imag = 0;
bool truevalue = true;
Complex<float>* x;
Complex<float>* y;
Complex<float>* z;
Complex<float>* ariff;


Complex<float> choose_operand(const char *message)
{
    Complex<float>* operand;
    operand = new Complex<float>[1];
    choose_number(message);
    switch (key)
    {
    case 1:
        operand[0] = x[0];
        break;
    case 2:
        operand[0] = y[0];
        break;
    case 3:
        cout << "write x Z[x]\n";
        cin >> key;
        operand[0] = z[key];
        break;
    }
    return operand[0];
}

int main()
{
    
    x = new Complex<float>;
    y = new Complex<float>;
    z = new Complex<float>[10];
    ariff = new Complex<float>[3];

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
                    key = choose_number("modify to");
                    if (key == 3)
                    {
                        cout << "write x Z[x]\n";
                        cin >> key2;
                    }
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
                        switch (key)
                        {
                        case 1:
                            x->setRealPart(real);
                            break;
                        case 2:
                            y->setRealPart(real);
                            break;
                        case 3:
                            z[key2].setRealPart(real);
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
                        switch (key)
                        {
                        case 1:
                            x->setImagPart(imag);
                            break;
                        case 2:
                            y->setImagPart(imag);
                            break;
                        case 3:
                            z[key2].setImagPart(imag);
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
                            switch (key)
                            {
                            case 1:
                                x->setBothParts(real, imag);
                                break;
                            case 2:
                                y->setBothParts(real, imag);
                                break;
                            case 3:
                                z[key2].setBothParts(real,imag);
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
                            switch (key)
                            {
                            case 1:
                                x->setBothtrigparts(real, imag);
                                break;
                            case 2:
                                y->setBothtrigparts(real, imag);
                                break;
                            case 3:
                                z[key2].setBothtrigparts(real, imag);
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
                    key = choose_number("display to");

                    switch (key)
                    {
                    case 1:
                        cout << x[0];
                        break;
                    case 2:
                        cout << y[0];
                        break;
                    case 3:
                        cout << "write x Z[x]\n";
                        cin >> key;
                        cout << z[key];
                        break;
                    default:
                        cout << "Input key is incorrect\n";
                        truevalue = false;
                        break;
                    }
                    break;

                case '4':
                    ariff[1] = choose_operand("first operand");
                    cout << ariff[1];
                    ariff[2] = choose_operand("second operand");
                    cout << ariff[2];

                    if (ariff[1].getReal() && ariff[2].getReal())
                    {
                        ariff[0] = ariff[1] + ariff[2];
                        cout << "Result(X + Y):";
                        cout << ariff[0];
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                
                case '5':
                    ariff[1] = choose_operand("first operand");
                    cout << ariff[1];
                    ariff[2] = choose_operand("second operand");
                    cout << ariff[2];

                    if (ariff[1].getReal() && ariff[2].getReal())
                    {
                        ariff[0] = ariff[1] - ariff[2];
                        cout << "Result(X - Y):";
                        cout << ariff[0];
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '6':
                    ariff[1] = choose_operand("first operand");
                    cout << ariff[1];
                    ariff[2] = choose_operand("second operand");
                    cout << ariff[2];

                    if (ariff[1].getReal() && ariff[2].getReal())
                    {
                        ariff[0] = ariff[1] * ariff[2];
                        cout << "Result(X * Y):";
                        cout << ariff[0];
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '7':
                    ariff[1] = choose_operand("first operand");
                    cout << ariff[1];
                    ariff[2] = choose_operand("second operand");
                    cout << ariff[2];

                    if (ariff[1].getReal() && ariff[2].getReal())
                    {
                        ariff[0] = ariff[1] / ariff[2];
                        cout << "Result(X / Y):";
                        cout << ariff[0];
                    }
                    else
                    {
                        cout << "Complex numbers is not created!\n";
                    }
                    break;

                case '8':
                        key = choose_number("to power/root");
                        if (key == 3)
                        {
                            cout << "write x Z[x]\n";
                            cin >> key2;
                        }
                        cout << "Choose mode\n";
                        cout << "0 - Power\n";
                        cout << "1 - Root\n";
                        cin >> form;
                        cout << "Enter power\n";
                        cin >> real;
                        switch (key)
                        {
                        case 1:
                            x->raisetopower(real, form);
                            cout << x[0];
                            break;
                        case 2:
                            y->raisetopower(real, form);
                            cout << y[0];
                            break;
                        case 3:
                            z[key2].raisetopower(real, form);
                            cout << z[key2];
                            break;
                        default:
                            cout << "Input key is incorrect\n";
                            truevalue = false;
                            break;
                        }
                    
                    break;

                case '9':
                    for (int i = 0; i < 2; i++)
                    {
                        cout << "Choose "<< i+1 << " number to compare\n";
                        cout << "1 - X\n";
                        cout << "2 - Y\n";
                        cout << "3 - Z[]\n";
                        cin >> key;
                        switch(key)
                        {
                        case 1:
                            ariff[i] = x[0];
                            break;
                        case 2:
                            ariff[i] = y[0];
                            break;
                        case 3:
                            cout << "write x Z[x]\n";
                            cin >> key2;
                            ariff[i] = z[key2];
                            break;
                        }
                    }
                    if (ariff[0] == ariff[1])
                    {
                        cout << "These numbers are equal!\n";
                    }
                    else
                    {
                        cout << "These numbers are not equal!\n";
                    }
                    break;

                case 'a':
                    ariff[0] = choose_operand("for [] operator");
                    cout << "Chosen number:" << ariff[0];
                    cout << "Write x [x]";
                    cin >> key;
                    try
                    {
                        real = ariff[0][key];
                        cout << real;
                    }
                    catch (const char* exnum)
                    {
                        cout << exnum;
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