//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
bool isNumberEntered = false;
int guessNumber;
int attemptsCounter = 0;
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	TitleLabel->Text = "Please enter the number: ";
	CounterLabel->Text = "0";
	HelperLabel->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConfirmButtonClick(TObject *Sender)
{
    if (!isNumberEntered) {
        guessNumber = NumberEdit->Text.ToInt();
        isNumberEntered = true;
        TitleLabel->Text = "Now you can guess the number: ";
        NumberEdit->Text = "";
    }
    else {
        int secondUsersNumber = NumberEdit->Text.ToInt();

        if (secondUsersNumber == guessNumber) {
            HelperLabel->Text = "You WON! Congratulations!";
            ConfirmButton->Enabled = false;
            return;
        }
        else if (secondUsersNumber > guessNumber) {
            HelperLabel->Text = "Number too big!";
        }
        else {
			HelperLabel->Text = "Number too low!";
        }
        CounterLabel->Text = ++attemptsCounter;
    }
}

//---------------------------------------------------------------------------
