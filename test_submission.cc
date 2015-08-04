
/**
 * Project 1
 * Name: [name]
 * Netid: [id number]
 * [class]
 * Section: [section]
 *
 * Any help items (you may omit mentions of the TAs, the professors,
 * or the recommended text):
 *
 *  Description: <This program will calculate your Framingham Risk Score and 
	estimate your 10-year cardiovascular risk.>
 *
 **/

//START

#include <iostream>
using namespace std;

int main()
{
    
    // Declare variables
    
	char smoker = ' ';
	int age = 0;
	int total_cholesterol = 0;
	int HDL_cholesterol = 0;
	int sbp = 0;
	int total_score = 0;
    
    //Declare constants
    
	const double HDL_CHOLESTEROL_RANGE_ONE_MIN = 60;
	const double HDL_CHOLESTEROL_RANGE_ONE_MAX = 100;
	const double HDL_CHOLESTEROL_RANGE_TWO_MIN = 50;
	const double HDL_CHOLESTEROL_RANGE_TWO_MAX = 59;
	const double HDL_CHOLESTEROL_RANGE_THREE_MIN = 40;
    const double HDL_CHOLESTEROL_RANGE_THREE_MAX = 49;
	const double HDL_CHOLESTEROL_RANGE_FOUR_MIN = 20;
	const double HDL_CHOLESTEROL_RANGE_FOUR_MAX = 39;
	const double HDL_CHOLESTEROL_RANGE_ONE_VALUE = -1;
	const double HDL_CHOLESTEROL_RANGE_TWO_VALUE = 0;
    const double HDL_CHOLESTEROL_RANGE_THREE_VALUE = 1;
    const double HDL_CHOLESTEROL_RANGE_FOUR_VALUE = 2;
    
	const double SBP_RANGE_ONE_MIN = 90;
	const double SBP_RANGE_ONE_MAX = 119;
	const double SBP_RANGE_TWO_MIN = 120;
	const double SBP_RANGE_TWO_MAX = 129;
	const double SBP_RANGE_THREE_MIN = 130;
    const double SBP_RANGE_THREE_MAX = 139;
	const double SBP_RANGE_FOUR_MIN = 140;
	const double SBP_RANGE_FOUR_MAX = 159;
	const double SBP_RANGE_FIVE_MIN = 160;
	const double SBP_RANGE_FIVE_MAX = 300;
	const double SBP_RANGE_ONE_VALUE = 0;
	const double SBP_RANGE_TWO_VALUE = 1;
	const double SBP_RANGE_THREE_VALUE = 2;
	const double SBP_RANGE_FOUR_VALUE = 3;
	const double SBP_RANGE_FIVE_VALUE = 4;
    
	const double AGE_RANGE_ONE_MIN = 20;
	const double AGE_RANGE_ONE_MAX = 34;
	const double AGE_RANGE_TWO_MIN = 35;
	const double AGE_RANGE_TWO_MAX = 39;
	const double AGE_RANGE_THREE_MIN = 40;
	const double AGE_RANGE_THREE_MAX = 44;
	const double AGE_RANGE_FOUR_MIN = 45;
	const double AGE_RANGE_FOUR_MAX = 49;
	const double AGE_RANGE_FIVE_MIN = 50;
	const double AGE_RANGE_FIVE_MAX = 54;
	const double AGE_RANGE_SIX_MIN = 55;
	const double AGE_RANGE_SIX_MAX = 59;
	const double AGE_RANGE_SEVEN_MIN = 60;
	const double AGE_RANGE_SEVEN_MAX = 64;
	const double AGE_RANGE_EIGHT_MIN = 65;
	const double AGE_RANGE_EIGHT_MAX = 69;
	const double AGE_RANGE_NINE_MIN = 70;
	const double AGE_RANGE_NINE_MAX = 74;
	const double AGE_RANGE_TEN_MIN = 75;
	const double AGE_RANGE_TEN_MAX = 79;
	const double AGE_RANGE_ONE_VALUE = -7;
	const double AGE_RANGE_TWO_VALUE = -3;
	const double AGE_RANGE_THREE_VALUE = 0;
	const double AGE_RANGE_FOUR_VALUE = 3;
	const double AGE_RANGE_FIVE_VALUE = 6;
	const double AGE_RANGE_SIX_VALUE = 8;
	const double AGE_RANGE_SEVEN_VALUE = 10;
	const double AGE_RANGE_EIGHT_VALUE = 12;
	const double AGE_RANGE_NINE_VALUE = 14;
	const double AGE_RANGE_TEN_VALUE = 16;
    
	const double TOTAL_CHOL_RANGE_ONE_MIN = 130;
	const double TOTAL_CHOL_RANGE_ONE_MAX = 159;
	const double TOTAL_CHOL_RANGE_TWO_MIN = 160;
	const double TOTAL_CHOL_RANGE_TWO_MAX = 199;
	const double TOTAL_CHOL_RANGE_THREE_MIN = 200;
	const double TOTAL_CHOL_RANGE_THREE_MAX = 239;
	const double TOTAL_CHOL_RANGE_FOUR_MIN = 240;
	const double TOTAL_CHOL_RANGE_FOUR_MAX = 279;
	const double TOTAL_CHOL_RANGE_FIVE_MIN = 280;
	const double TOTAL_CHOL_RANGE_FIVE_MAX = 320;
	const double TOTAL_CHOL_RANGE_ONE_ONE = 0;
	const double TOTAL_CHOL_RANGE_TWO_ONE = 4;
	const double TOTAL_CHOL_RANGE_THREE_ONE = 8;
	const double TOTAL_CHOL_RANGE_FOUR_ONE = 11;
	const double TOTAL_CHOL_RANGE_FIVE_ONE = 13;
	const double TOTAL_CHOL_RANGE_ONE_TWO = 0;
	const double TOTAL_CHOL_RANGE_TWO_TWO = 3;
	const double TOTAL_CHOL_RANGE_THREE_TWO = 6;
	const double TOTAL_CHOL_RANGE_FOUR_TWO = 8;
	const double TOTAL_CHOL_RANGE_FIVE_TWO = 10;
	const double TOTAL_CHOL_RANGE_ONE_THREE = 0;
	const double TOTAL_CHOL_RANGE_TWO_THREE = 2;
	const double TOTAL_CHOL_RANGE_THREE_THREE = 4;
	const double TOTAL_CHOL_RANGE_FOUR_THREE = 5;
	const double TOTAL_CHOL_RANGE_FIVE_THREE = 7;
	const double TOTAL_CHOL_RANGE_ONE_FOUR = 0;
	const double TOTAL_CHOL_RANGE_TWO_FOUR = 1;
	const double TOTAL_CHOL_RANGE_THREE_FOUR = 2;
	const double TOTAL_CHOL_RANGE_FOUR_FOUR = 3;
	const double TOTAL_CHOL_RANGE_FIVE_FOUR = 4;
	const double TOTAL_CHOL_RANGE_ONE_FIVE = 0;
	const double TOTAL_CHOL_RANGE_TWO_FIVE = 1;
	const double TOTAL_CHOL_RANGE_THREE_FIVE = 1;
	const double TOTAL_CHOL_RANGE_FOUR_FIVE = 2;
	const double TOTAL_CHOL_RANGE_FIVE_FIVE = 2;
    
	const double CIG_SMOKER_ONE = 9;
	const double CIG_SMOKER_TWO = 7;
	const double CIG_SMOKER_THREE = 4;
	const double CIG_SMOKER_FOUR = 2;
	const double CIG_SMOKER_FIVE = 1;
	const double NO_CIG = 0;
    
	const double TOTAL_SCORE_ONE_MIN = -8;
	const double TOTAL_SCORE_ONE_MAX = 8;
	const double TOTAL_SCORE_TWO_MIN = 9;
	const double TOTAL_SCORE_TWO_MAX = 12;
	const double TOTAL_SCORE_THREE_MIN = 13;
	const double TOTAL_SCORE_THREE_MAX = 14;
	const double TOTAL_SCORE_FOUR = 15;
	const double TOTAL_SCORE_FIVE = 16;
	const double TOTAL_SCORE_SIX = 17;
	const double TOTAL_SCORE_SEVEN = 18;
	const double TOTAL_SCORE_EIGHT = 19;
	const double TOTAL_SCORE_NINE = 20;
	const double TOTAL_SCORE_TEN = 21;
	const double TOTAL_SCORE_ELEVEN = 22;
	const double TOTAL_SCORE_TWELVE = 23;
	const double TOTAL_SCORE_THIRTEEN = 24;
	const double TOTAL_SCORE_FOURTEEN_MIN = 25;
    const double TOTAL_SCORE_FOURTEEN_MAX = 29;
    
    //Provide instructions for user
    
	cout << "Please have the following subject information at hand:" << endl;
	cout << "Age, Smoker status, Total Cholesterol, HDL Cholesterol," << endl;
	cout << "Systolic Blood Pressure" << endl;
    
    //Enter Age
    
	cout << "Please enter the patient's age" << endl;
	cin >> age;
    
	if ((age < AGE_RANGE_ONE_MIN) || (age > AGE_RANGE_TEN_MAX)){
		cout << "Input must be a number between 20 and 79" << endl;
		return 0;
	}
    
    //Enter smoker
    
	cout << "Is the patient a smoker (Y/N)?" << endl;
	cin >> smoker;
    
	if ((smoker != 'Y') && (smoker != 'y') &&
        (smoker != 'N') && (smoker != 'n')){
		cout << "Input must be either 'Y' (yes) or 'N' (no)" << endl;
		return 0;
	}
    
    //Enter total cholesterol
    
	cout << "Please enter total cholesterol level" << endl;
	cin >> total_cholesterol;
    
	if ((total_cholesterol < TOTAL_CHOL_RANGE_ONE_MIN) ||
        (total_cholesterol > TOTAL_CHOL_RANGE_FIVE_MAX)){
		cout << "Input must be a number between 130 and 320" << endl;
		return 0;
	}
    
    //Enter HDL cholesterol
    
	cout << "Please enter HDL cholesterol level" << endl;
	cin >> HDL_cholesterol;
    
	if ((HDL_cholesterol < HDL_CHOLESTEROL_RANGE_FOUR_MIN) ||
        (HDL_cholesterol > HDL_CHOLESTEROL_RANGE_ONE_MAX)){
		cout << "Input must be a number between 20 and 100" << endl;
		return 0;
	}
    
    //Enter systolic blood pressure
    
	cout << "Please enter systolic blood pressure" << endl;
	cin >> sbp;
    
	if ((sbp < SBP_RANGE_ONE_MIN) ||
        (sbp > SBP_RANGE_FIVE_MAX)){
		cout << "Input must be a number between 90 and 300" << endl;
		return 0;
	}
    
    //Add points to total score based on HDL Cholesterol input
    
	if (HDL_cholesterol >= HDL_CHOLESTEROL_RANGE_ONE_MIN &&
        HDL_cholesterol <= HDL_CHOLESTEROL_RANGE_ONE_MAX)
    {
		total_score = HDL_CHOLESTEROL_RANGE_ONE_VALUE + total_score;
    }
	else if (HDL_cholesterol >= HDL_CHOLESTEROL_RANGE_TWO_MIN &&
             HDL_cholesterol <= HDL_CHOLESTEROL_RANGE_TWO_MAX)
    {
		total_score = HDL_CHOLESTEROL_RANGE_TWO_VALUE + total_score;
    }
	else if (HDL_cholesterol >= HDL_CHOLESTEROL_RANGE_THREE_MIN &&
             HDL_cholesterol <= HDL_CHOLESTEROL_RANGE_THREE_MAX)
    {
		total_score = HDL_CHOLESTEROL_RANGE_THREE_VALUE + total_score;
    }
	else if (HDL_cholesterol >= HDL_CHOLESTEROL_RANGE_FOUR_MIN &&
             HDL_cholesterol <= HDL_CHOLESTEROL_RANGE_FOUR_MAX)
    {
		total_score = HDL_CHOLESTEROL_RANGE_FOUR_VALUE + total_score;
    }
    
    //Add points to total scored based on systolic blood pressure input
    
	if (sbp >= SBP_RANGE_ONE_MIN &&
        sbp <= SBP_RANGE_ONE_MAX)
    {
		total_score = SBP_RANGE_ONE_VALUE + total_score;
    }
	else if (sbp >= SBP_RANGE_TWO_MIN &&
             sbp <= SBP_RANGE_TWO_MAX)
    {
		total_score = SBP_RANGE_TWO_VALUE + total_score;
    }
	else if (sbp >= SBP_RANGE_THREE_MIN &&
             sbp <= SBP_RANGE_THREE_MAX)
    {
		total_score = SBP_RANGE_THREE_VALUE + total_score;
    }
	else if (sbp >= SBP_RANGE_FOUR_MIN &&
             sbp <= SBP_RANGE_FOUR_MAX)
    {
		total_score = SBP_RANGE_FOUR_VALUE + total_score;
    }
	else if (sbp >= SBP_RANGE_FIVE_MIN &&
             sbp <= SBP_RANGE_FIVE_MAX)
    {
		total_score = SBP_RANGE_FIVE_VALUE + total_score;
    }
    
    
    //Add points to total score based on age input, total cholesterol
    //and smoking/nonsmoking
    
    
	if (age >= AGE_RANGE_ONE_MIN && age <= AGE_RANGE_ONE_MAX)
	{
		total_score = AGE_RANGE_ONE_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_ONE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
            total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_ONE + total_score;
		}
	}
	else if (age >= AGE_RANGE_TWO_MIN && age <= AGE_RANGE_TWO_MAX)
	{
		total_score =  AGE_RANGE_TWO_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_ONE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_ONE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_ONE + total_score;
		}
	}
	else if (age >= AGE_RANGE_THREE_MIN && age <= AGE_RANGE_THREE_MAX)
	{
		total_score =  AGE_RANGE_THREE_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_TWO + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_TWO + total_score;
		}
	}
	else if (age >= AGE_RANGE_FOUR_MIN && age <= AGE_RANGE_FOUR_MAX)
	{
		total_score = AGE_RANGE_FOUR_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_TWO + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_TWO + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_TWO + total_score;
		}
	}
	else if (age >= AGE_RANGE_FIVE_MIN && age <= AGE_RANGE_FIVE_MAX)
	{
		total_score = AGE_RANGE_FIVE_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_THREE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_THREE +
			total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_THREE + total_score;
		}
	}
	else if (age >= AGE_RANGE_SIX_MIN && age <= AGE_RANGE_SIX_MAX)
	{
		total_score = AGE_RANGE_SIX_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_THREE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_THREE +
			total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_THREE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_THREE + total_score;
		}
	}
	else if (age >= AGE_RANGE_SEVEN_MIN && age <= AGE_RANGE_SEVEN_MAX)
	{
		total_score = AGE_RANGE_SEVEN_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_FOUR + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_FOUR + total_score;
		}
	}
	else if (age >= AGE_RANGE_EIGHT_MIN && age <= AGE_RANGE_EIGHT_MAX)
	{
		total_score= AGE_RANGE_EIGHT_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_FOUR + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_FOUR + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_FOUR + total_score;
		}
	}
	else if (age >= AGE_RANGE_NINE_MIN && age <= AGE_RANGE_NINE_MAX)
	{
		total_score = AGE_RANGE_NINE_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_FIVE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_FIVE + total_score;
		}
	}
	else if (age >= AGE_RANGE_TEN_MIN && age <= AGE_RANGE_TEN_MAX)
	{
		total_score = AGE_RANGE_TEN_VALUE + total_score;
		if ((smoker == 'Y') || (smoker == 'y'))
		{
			total_score = CIG_SMOKER_FIVE + total_score;
		}
		else
		{
			total_score = NO_CIG + total_score;
		}
		if (total_cholesterol >= TOTAL_CHOL_RANGE_ONE_MIN &&
			total_cholesterol <= TOTAL_CHOL_RANGE_ONE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_ONE_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_TWO_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_TWO_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_TWO_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_THREE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_THREE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_THREE_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FOUR_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FOUR_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FOUR_FIVE + total_score;
		}
		else if (total_cholesterol >= TOTAL_CHOL_RANGE_FIVE_MIN &&
                 total_cholesterol <= TOTAL_CHOL_RANGE_FIVE_MAX)
		{
			total_score = TOTAL_CHOL_RANGE_FIVE_FIVE + total_score;
		}
	}
    
    
    //OUTPUT total score
    
    cout << "Total Score: " << total_score << endl;
    
    
    // Output the risk level
    
    if (total_score >= TOTAL_SCORE_ONE_MIN &&
        total_score <= TOTAL_SCORE_ONE_MAX)
	{
        cout << "The patient has a <1% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score >= TOTAL_SCORE_TWO_MIN &&
             total_score <= TOTAL_SCORE_TWO_MAX)
    {
        cout << "The patient has a 1% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score >= TOTAL_SCORE_THREE_MIN &&
             total_score <= TOTAL_SCORE_THREE_MAX)
    {
        cout << "The patient has a 2% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_FOUR)
    {
        cout << "The patient has a 3% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    
    else if (total_score == TOTAL_SCORE_FIVE)
    {
        cout << "The patient has a 4% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_SIX)
    {
        cout << "The patient has a 5% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_SEVEN)
    {
        cout << "The patient has a 6% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_EIGHT)
    {
        cout << "The patient has a 8% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_NINE)
    {
        cout << "The patient has a 11% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_TEN)
    {
        cout << "The patient has a 14% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_ELEVEN)
    {
        cout << "The patient has a 17% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_TWELVE)
    {
        cout << "The patient has a 22% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score == TOTAL_SCORE_THIRTEEN)
    {
        cout << "The patient has a 27% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    else if (total_score >= TOTAL_SCORE_FOURTEEN_MIN &&
             total_score <= TOTAL_SCORE_FOURTEEN_MAX)
    {
        cout << "The patient has a >30% chance of developing" << endl;
        cout << "cardiovascular disease in the next ten years. " << endl;
    }
    
    //End program
    
	return 0;
}

